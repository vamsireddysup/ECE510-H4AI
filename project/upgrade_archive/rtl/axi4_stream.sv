/*
 * axi4_stream.sv -- AXI4-Stream Data Interface for FP4 QK^T Chiplet
 *
 * Handles streaming of FP4 Q/K tiles and FP32 scale factors from host
 * to chiplet, and dequantized FP32 score matrix from chiplet to host.
 *
 * Input data packing (64-bit tdata):
 *   Scale factors: tdata[31:0] = FP32 scale factor (one per transfer)
 *   FP4 tile data: tdata[63:0] = 16 FP4 values packed (4 bits each)
 *                  tdata[3:0]   = element 0
 *                  tdata[7:4]   = element 1
 *                  ...
 *                  tdata[63:60] = element 15
 *
 * Output data packing (64-bit tdata):
 *   tdata[63:32] = FP32 score element (high word)
 *   tdata[31:0]  = FP32 score element (low word, second element)
 *   Two FP32 scores per 64-bit transfer
 *
 * Stream phases (in order):
 *   Phase 1: Scale factors -- 2 x T FP32 values (S_Q then S_K)
 *   Phase 2: Q tile -- TILE_SIZE x D_HEAD FP4 values
 *   Phase 3: K tile -- TILE_SIZE x D_HEAD FP4 values
 *   Phase 4: Output -- TILE_SIZE x TILE_SIZE FP32 dequantized scores
 *   Phases 2-4 repeat for each tile
 *
 * Backpressure: chiplet deasserts s_tready when busy
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Ports:
 *   clk          input  1-bit    system clock
 *   rst_n        input  1-bit    active-low synchronous reset
 *   s_tvalid     input  1-bit    input stream valid
 *   s_tready     output 1-bit    input stream ready (backpressure)
 *   s_tdata      input  64-bit   input stream data
 *   s_tlast      input  1-bit    input stream last transfer marker
 *   m_tvalid     output 1-bit    output stream valid
 *   m_tready     input  1-bit    output stream ready
 *   m_tdata      output 64-bit   output stream data (2x FP32)
 *   m_tlast      output 1-bit    output stream last transfer marker
 *   start        input  1-bit    from AXI4-Lite: begin accepting data
 *   done         output 1-bit    to AXI4-Lite: all tiles complete
 *   matrix_size  input  32-bit   configurable T from AXI4-Lite
 *
 * Debug: compile with -DDEBUG_STREAM for transaction traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

/* verilator lint_off UNUSEDPARAM */
/* verilator lint_off UNUSEDSIGNAL */

module axi4_stream #(
    parameter int TILE_SIZE = 16,   // systolic array dimension
    parameter int D_HEAD    = 64,   // dot product length
    parameter int T_MAX     = 512   // max sequence length
)(
    input  logic        clk,
    input  logic        rst_n,

    // Input AXI4-Stream: scale factors then FP4 tile data
    input  logic        s_tvalid,
    output logic        s_tready,
    input  logic [63:0] s_tdata,
    input  logic        s_tlast,

    // Output AXI4-Stream: dequantized FP32 scores
    output logic        m_tvalid,
    input  logic        m_tready,
    output logic [63:0] m_tdata,
    output logic        m_tlast,

    // Control
    input  logic        start,
    output logic        done,
    input  logic [31:0] matrix_size
);

    // -----------------------------------------------------------------------
    // State machine
    // IDLE -> LOAD_SCALES -> LOAD_Q -> LOAD_K -> COMPUTING -> SENDING -> NEXT_TILE -> DONE_ST
    // -----------------------------------------------------------------------
    typedef enum logic [2:0] {
        IDLE        = 3'b000,
        LOAD_SCALES = 3'b001,
        LOAD_Q      = 3'b010,
        LOAD_K      = 3'b011,
        COMPUTING   = 3'b100,
        SENDING     = 3'b101,
        NEXT_TILE   = 3'b110,
        DONE_ST     = 3'b111
    } state_t;

    state_t      state;

    // -----------------------------------------------------------------------
    // Internal counters and buffers
    // -----------------------------------------------------------------------
    logic [31:0] recv_count;     // elements received in current phase
    logic [31:0] send_count;     // elements sent in output phase
    logic [31:0] tile_row;       // current Q tile row index
    logic [31:0] tile_col;       // current K tile col index
    logic [31:0] n_tiles;        // number of tiles per dimension

    // Scale factor buffers (small -- one tile worth)
    logic [31:0] sq_buf [0:TILE_SIZE-1];  // S_Q for current Q tile rows
    logic [$clog2(TILE_SIZE)-1:0] sk_idx;
    logic [31:0] sk_buf [0:TILE_SIZE-1];  // S_K for current K tile cols

    // FP4 tile buffers
    logic [3:0]  q_tile [0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0]  k_tile [0:TILE_SIZE-1][0:D_HEAD-1];

    // FP32 output score buffer (one tile)
    logic [31:0] score_buf [0:TILE_SIZE*TILE_SIZE-1];

    logic [31:0] total_out;
    assign total_out = 32'(TILE_SIZE * TILE_SIZE);

    // -----------------------------------------------------------------------
    // Stream control
    // -----------------------------------------------------------------------
    assign s_tready = (state == LOAD_SCALES ||
                       state == LOAD_Q      ||
                       state == LOAD_K);

    assign m_tvalid = (state == SENDING);

    // Pack two FP32 values per 64-bit output transfer
    logic [31:0] out_elem_hi, out_elem_lo;
    assign out_elem_hi = (send_count < total_out) ?
                         score_buf[send_count] : 32'h0;
    assign out_elem_lo = (send_count + 1 < total_out) ?
                         score_buf[send_count + 1] : 32'h0;
    assign m_tdata = {out_elem_hi, out_elem_lo};
    assign m_tlast = (state == SENDING) &&
                     (send_count + 2 >= total_out);
    assign done    = (state == DONE_ST);

    // -----------------------------------------------------------------------
    // State machine
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state      <= IDLE;
            recv_count <= 32'h0;
            send_count <= 32'h0;
            tile_row   <= 32'h0;
            tile_col   <= 32'h0;
            n_tiles    <= 32'h0;
            for (int i = 0; i < TILE_SIZE; i++) begin
                sq_buf[i] <= 32'h3F800000;
                sk_buf[i] <= 32'h3F800000;
            end
            for (int i = 0; i < TILE_SIZE; i++)
                for (int j = 0; j < D_HEAD; j++) begin
                    q_tile[i][j] <= 4'h0;
                    k_tile[i][j] <= 4'h0;
                end
            for (int i = 0; i < TILE_SIZE*TILE_SIZE; i++)
                score_buf[i] <= 32'h0;
        end else begin

            case (state)

                IDLE: begin
                    recv_count <= 32'h0;
                    send_count <= 32'h0;
                    tile_row   <= 32'h0;
                    tile_col   <= 32'h0;
                    n_tiles    <= matrix_size >> $clog2(TILE_SIZE);
                    if (start) begin
                        state <= LOAD_SCALES;
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] START, matrix_size=%0d at t=%0t",
                                 matrix_size, $time);
                        `endif
                    end
                end

                // ------------------------------------------------------------
                // Load scale factors for current tile
                // First TILE_SIZE transfers: S_Q for current Q tile rows
                // Next  TILE_SIZE transfers: S_K for current K tile cols
                // ------------------------------------------------------------
                LOAD_SCALES: begin
                    if (s_tvalid && s_tready) begin
                        if (recv_count < TILE_SIZE) begin
                            sq_buf[recv_count[$clog2(TILE_SIZE)-1:0]] <=
                                s_tdata[31:0];
                            `ifdef DEBUG_STREAM
                            $display("[STREAM] S_Q[%0d]=0x%08h at t=%0t",
                                     recv_count, s_tdata[31:0], $time);
                            `endif
                        end else begin
                            sk_idx = recv_count[$clog2(TILE_SIZE)-1:0] -
                                     TILE_SIZE[$clog2(TILE_SIZE)-1:0];
                            sk_buf[sk_idx] <= s_tdata[31:0];
                            `ifdef DEBUG_STREAM
                            $display("[STREAM] S_K[%0d]=0x%08h at t=%0t",
                                     recv_count-TILE_SIZE, s_tdata[31:0], $time);
                            `endif
                        end

                        if (recv_count == 32'(2*TILE_SIZE - 1) || s_tlast) begin
                            state      <= LOAD_Q;
                            recv_count <= 32'h0;
                        end else begin
                            recv_count <= recv_count + 32'h1;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Load Q tile: TILE_SIZE x D_HEAD FP4 values
                // Each 64-bit transfer carries 16 FP4 values
                // ------------------------------------------------------------
                LOAD_Q: begin
                    if (s_tvalid && s_tready) begin
                        // Unpack 16 FP4 values from 64-bit word
                        for (int k = 0; k < 16; k++) begin
                            automatic int elem = recv_count * 16 + k;
                            automatic int row  = elem / D_HEAD;
                            automatic int col  = elem % D_HEAD;
                            if (row < TILE_SIZE && col < D_HEAD)
                                q_tile[row][col] <=
                                    s_tdata[k*4 +: 4];
                        end
                        recv_count <= recv_count + 32'h1;

                        `ifdef DEBUG_STREAM
                        $display("[STREAM] Q transfer %0d at t=%0t",
                                 recv_count, $time);
                        `endif

                        // Total transfers = TILE_SIZE*D_HEAD / 16
                        if (recv_count == 32'(TILE_SIZE*D_HEAD/16 - 1) ||
                            s_tlast) begin
                            state      <= LOAD_K;
                            recv_count <= 32'h0;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Load K tile: TILE_SIZE x D_HEAD FP4 values
                // ------------------------------------------------------------
                LOAD_K: begin
                    if (s_tvalid && s_tready) begin
                        for (int k = 0; k < 16; k++) begin
                            automatic int elem = recv_count * 16 + k;
                            automatic int row  = elem / D_HEAD;
                            automatic int col  = elem % D_HEAD;
                            if (row < TILE_SIZE && col < D_HEAD)
                                k_tile[row][col] <=
                                    s_tdata[k*4 +: 4];
                        end
                        recv_count <= recv_count + 32'h1;

                        `ifdef DEBUG_STREAM
                        $display("[STREAM] K transfer %0d at t=%0t",
                                 recv_count, $time);
                        `endif

                        if (recv_count == 32'(TILE_SIZE*D_HEAD/16 - 1) ||
                            s_tlast) begin
                            state      <= COMPUTING;
                            recv_count <= 32'h0;
                            // Placeholder: load dummy scores for verification
                            // In full integration: systolic array feeds here
                            for (int i = 0; i < TILE_SIZE*TILE_SIZE; i++)
                                score_buf[i] <= 32'(i + 1);
                        end
                    end
                end

                // ------------------------------------------------------------
                // Wait for systolic array and dequantization
                // Placeholder: move after 5 cycles
                // Full integration: wait for tile_controller done
                // ------------------------------------------------------------
                COMPUTING: begin
                    recv_count <= recv_count + 32'h1;
                    if (recv_count == 32'h5) begin
                        state      <= SENDING;
                        send_count <= 32'h0;
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] COMPUTING done at t=%0t", $time);
                        `endif
                    end
                end

                // ------------------------------------------------------------
                // Send dequantized FP32 scores -- 2 per 64-bit transfer
                // ------------------------------------------------------------
                SENDING: begin
                    if (m_tvalid && m_tready) begin
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] TX[%0d+%0d]=0x%08h,0x%08h at t=%0t",
                                 send_count, send_count+1,
                                 score_buf[send_count],
                                 score_buf[send_count+1], $time);
                        `endif

                        send_count <= send_count + 32'h2;

                        if (send_count + 2 >= total_out) begin
                            state <= NEXT_TILE;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Advance to next tile
                // ------------------------------------------------------------
                NEXT_TILE: begin
                    if (tile_col + 1 >= n_tiles) begin
                        tile_col <= 32'h0;
                        if (tile_row + 1 >= n_tiles) begin
                            state <= DONE_ST;
                        end else begin
                            tile_row   <= tile_row + 32'h1;
                            state      <= LOAD_SCALES;
                            recv_count <= 32'h0;
                        end
                    end else begin
                        tile_col   <= tile_col + 32'h1;
                        state      <= LOAD_SCALES;
                        recv_count <= 32'h0;
                    end
                end

                DONE_ST: begin
                    `ifdef DEBUG_STREAM
                    $display("[STREAM] ALL DONE at t=%0t", $time);
                    `endif
                end

                default: state <= IDLE;

            endcase
        end
    end

endmodule

/* verilator lint_on UNUSEDPARAM */
/* verilator lint_on UNUSEDSIGNAL */
