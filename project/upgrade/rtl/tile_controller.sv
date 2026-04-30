/*
 * tile_controller.sv -- Tiling FSM for FP4 QK^T Accelerator
 *
 * Controls the complete computation pipeline for tiled QK^T:
 *   1. LOAD_SCALES:  receive S_Q and S_K from AXI4-Stream -> scale_sram
 *   2. LOAD_Q:       receive FP4 Q tile from AXI4-Stream -> q_tile_buffer
 *   3. LOAD_K:       receive FP4 K tile from AXI4-Stream -> k_tile_buffer
 *   4. FEED_ARRAY:   feed D_HEAD columns to systolic array
 *   5. WAIT_RESULT:  wait for systolic array result_valid
 *   6. CAPTURE:      read FP32 results into out_tile_buffer
 *   7. DEQUANTIZE:   multiply result[i][j] x S_Q[i] x S_K[j]
 *   8. STREAM_OUT:   send dequantized FP32 scores via AXI4-Stream
 *   9. NEXT_TILE:    advance tile indices, loop until all tiles done
 *  10. DONE:         assert done to AXI4-Lite ctrl
 *
 * Profiling registers (exported to AXI4-Lite):
 *   tile_count:   number of tiles completed
 *   cycle_count:  total cycles since START
 *   tile_cycles:  cycles for last tile
 *
 * Parameters:
 *   TILE_SIZE (int) -- systolic array dimension (default 16)
 *   D_HEAD    (int) -- dot product length (default 64)
 *   T_MAX     (int) -- max sequence length (default 512)
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Debug: compile with -DDEBUG_CTRL for $display traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module tile_controller #(
    parameter int TILE_SIZE = 16,
    parameter int D_HEAD    = 64,
    parameter int T_MAX     = 512
)(
    input  logic clk,
    input  logic rst_n,

    // Control from AXI4-Lite
    input  logic                        start,
    input  logic [$clog2(T_MAX)-1:0]    matrix_size,  // configurable T
    output logic                        done,

    // Profiling outputs to AXI4-Lite registers
    output logic [31:0]                 tile_count,
    output logic [31:0]                 cycle_count,
    output logic [31:0]                 tile_cycles,

    // AXI4-Stream input (Q tiles, K tiles, scale factors)
    input  logic                        s_tvalid,
    output logic                        s_tready,
    input  logic [63:0]                 s_tdata,   // 16 FP4 values packed
    input  logic                        s_tlast,

    // AXI4-Stream output (dequantized FP32 scores)
    output logic                        m_tvalid,
    input  logic                        m_tready,
    output logic [63:0]                 m_tdata,   // 2 FP32 values packed
    output logic                        m_tlast,

    // Scale SRAM write port
    output logic                        sq_wr_en,
    output logic [$clog2(T_MAX):0]      sq_wr_addr,
    output logic [31:0]                 sq_wr_data,

    // Scale SRAM read ports
    output logic [$clog2(T_MAX)-1:0]    sq_rd_addr,
    input  logic [31:0]                 sq_rd_data,
    output logic [$clog2(T_MAX)-1:0]    sk_rd_addr,
    input  logic [31:0]                 sk_rd_data,

    // Tile buffer Q write port
    output logic                        q_wr_en,
    output logic [$clog2(TILE_SIZE)-1:0] q_wr_row,
    output logic [$clog2(D_HEAD)-1:0]   q_wr_col,
    output logic [3:0]                  q_wr_data,

    // Tile buffer Q read port (to systolic array)
    output logic [$clog2(TILE_SIZE)-1:0] q_rd_row,
    output logic [$clog2(D_HEAD)-1:0]   q_rd_col,
    input  logic [3:0]                  q_rd_data,

    // Tile buffer K write port
    output logic                        k_wr_en,
    output logic [$clog2(TILE_SIZE)-1:0] k_wr_row,
    output logic [$clog2(D_HEAD)-1:0]   k_wr_col,
    output logic [3:0]                  k_wr_data,

    // Tile buffer K read port (to systolic array)
    output logic [$clog2(TILE_SIZE)-1:0] k_rd_row,
    output logic [$clog2(D_HEAD)-1:0]   k_rd_col,
    input  logic [3:0]                  k_rd_data,

    // Tile buffer output write port (from systolic array)
    output logic                        out_wr_en,
    output logic [$clog2(TILE_SIZE)-1:0] out_wr_row,
    output logic [$clog2(TILE_SIZE)-1:0] out_wr_col,
    output logic [31:0]                 out_wr_data,

    // Tile buffer output read port (for dequantization)
    output logic [$clog2(TILE_SIZE)-1:0] out_rd_row,
    output logic [$clog2(TILE_SIZE)-1:0] out_rd_col,
    input  logic [31:0]                 out_rd_data,

    // Systolic array interface
    output logic [3:0]                  arr_a_in  [TILE_SIZE],
    output logic [3:0]                  arr_b_in  [TILE_SIZE],
    output logic                        arr_valid_in,
    input  logic [31:0]                 arr_result [TILE_SIZE][TILE_SIZE],
    input  logic                        arr_result_valid,

    // Dequantization FP32 multiplier interface
    // Two multipliers: one for x S_Q, one for x S_K
    // We reuse fp32_add module concept but need fp32_mul here
    // Result = raw_score x S_Q[i] x S_K[j]
    // Done in two sequential multiply steps
    output logic [31:0]                 deq_a,      // raw score or intermediate
    output logic [31:0]                 deq_b,      // scale factor
    output logic                        deq_valid,
    input  logic [31:0]                 deq_result,
    input  logic                        deq_result_valid
);

    // -----------------------------------------------------------------------
    // State machine
    // -----------------------------------------------------------------------
    typedef enum logic [3:0] {
        IDLE         = 4'h0,
        LOAD_SCALES  = 4'h1,
        LOAD_Q       = 4'h2,
        LOAD_K       = 4'h3,
        FEED_ARRAY   = 4'h4,
        WAIT_RESULT  = 4'h5,
        CAPTURE      = 4'h6,
        DEQUANTIZE   = 4'h7,
        STREAM_OUT   = 4'h8,
        NEXT_TILE    = 4'h9,
        DONE_ST      = 4'hA
    } state_t;

    state_t state;

    // -----------------------------------------------------------------------
    // Tile indices
    // tile_row: which row-tile of Q we are computing (0 to T/TILE_SIZE - 1)
    // tile_col: which col-tile of K we are computing (0 to T/TILE_SIZE - 1)
    // -----------------------------------------------------------------------
    logic [$clog2(T_MAX)-1:0] tile_row;
    logic [$clog2(T_MAX)-1:0] tile_col;
    logic [$clog2(T_MAX)-1:0] n_tiles;     // T / TILE_SIZE

    // -----------------------------------------------------------------------
    // Internal counters
    // -----------------------------------------------------------------------
    logic [31:0] d_counter;    // D_HEAD feed counter
    logic [31:0] load_count;   // elements loaded so far
    logic [31:0] cap_row;      // capture row index
    logic [31:0] cap_col;      // capture col index
    logic [31:0] deq_row;      // dequantize row
    logic [31:0] deq_col;      // dequantize col
    logic [31:0] send_count;   // output elements sent
    logic [31:0] tile_start_cycle; // cycle when current tile started
    logic        deq_phase;    // 0 = multiply by S_Q, 1 = multiply by S_K
    logic [31:0] deq_intermediate; // result after S_Q multiply

    // -----------------------------------------------------------------------
    // Profiling counters
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            cycle_count <= 32'h0;
        end else if (state != IDLE && state != DONE_ST) begin
            cycle_count <= cycle_count + 32'h1;
        end
    end

    // -----------------------------------------------------------------------
    // Default output assignments
    // -----------------------------------------------------------------------
    assign sq_rd_addr  = deq_row[$clog2(T_MAX)-1:0] +
                         tile_row[$clog2(T_MAX)-1:0] * TILE_SIZE[$clog2(T_MAX)-1:0];
    assign sk_rd_addr  = deq_col[$clog2(T_MAX)-1:0] +
                         tile_col[$clog2(T_MAX)-1:0] * TILE_SIZE[$clog2(T_MAX)-1:0];
    assign out_rd_row  = deq_row[$clog2(TILE_SIZE)-1:0];
    assign out_rd_col  = deq_col[$clog2(TILE_SIZE)-1:0];

    // Q and K read for feeding array
    always_comb begin
        for (int i = 0; i < TILE_SIZE; i++) begin
            arr_a_in[i] = 4'h0;
            arr_b_in[i] = 4'h0;
        end
        if (state == FEED_ARRAY) begin
            for (int i = 0; i < TILE_SIZE; i++) begin
                arr_a_in[i] = q_rd_data; // driven by q_rd_row/col below
                arr_b_in[i] = k_rd_data;
            end
        end
    end

    // -----------------------------------------------------------------------
    // Main state machine
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state           <= IDLE;
            done            <= 1'b0;
            tile_row        <= '0;
            tile_col        <= '0;
            n_tiles         <= '0;
            d_counter       <= 32'h0;
            load_count      <= 32'h0;
            cap_row         <= 32'h0;
            cap_col         <= 32'h0;
            deq_row         <= 32'h0;
            deq_col         <= 32'h0;
            send_count      <= 32'h0;
            tile_count      <= 32'h0;
            tile_cycles     <= 32'h0;
            tile_start_cycle <= 32'h0;
            deq_phase       <= 1'b0;
            deq_intermediate <= 32'h0;
            arr_valid_in    <= 1'b0;
            s_tready        <= 1'b0;
            m_tvalid        <= 1'b0;
            m_tdata         <= 64'h0;
            m_tlast         <= 1'b0;
            sq_wr_en        <= 1'b0;
            sq_wr_addr      <= '0;
            sq_wr_data      <= 32'h3F800000;
            q_wr_en         <= 1'b0;
            q_wr_row        <= '0;
            q_wr_col        <= '0;
            q_wr_data       <= 4'h0;
            k_wr_en         <= 1'b0;
            k_wr_row        <= '0;
            k_wr_col        <= '0;
            k_wr_data       <= 4'h0;
            out_wr_en       <= 1'b0;
            out_wr_row      <= '0;
            out_wr_col      <= '0;
            out_wr_data     <= 32'h0;
            q_rd_row        <= '0;
            q_rd_col        <= '0;
            k_rd_row        <= '0;
            k_rd_col        <= '0;
            deq_valid       <= 1'b0;
            deq_a           <= 32'h0;
            deq_b           <= 32'h0;
        end else begin
            // Default deasserts
            arr_valid_in <= 1'b0;
            s_tready     <= 1'b0;
            sq_wr_en     <= 1'b0;
            q_wr_en      <= 1'b0;
            k_wr_en      <= 1'b0;
            out_wr_en    <= 1'b0;
            deq_valid    <= 1'b0;
            m_tvalid     <= 1'b0;
            m_tlast      <= 1'b0;

            case (state)

                // ------------------------------------------------------------
                IDLE: begin
                    done      <= 1'b0;
                    tile_row  <= '0;
                    tile_col  <= '0;
                    n_tiles   <= matrix_size[$clog2(T_MAX)-1:0] >>
                                 $clog2(TILE_SIZE);
                    if (start) begin
                        state      <= LOAD_SCALES;
                        load_count <= 32'h0;
                        `ifdef DEBUG_CTRL
                        $display("[CTRL] START received, matrix_size=%0d at t=%0t",
                                 matrix_size, $time);
                        `endif
                    end
                end

                // ------------------------------------------------------------
                // Load 2*T scale factors: first T are S_Q, next T are S_K
                // Host sends FP32 values packed two per 64-bit transfer
                // ------------------------------------------------------------
                LOAD_SCALES: begin
                    s_tready <= 1'b1;
                    if (s_tvalid && s_tready) begin
                        // Unpack two FP32 scale factors per transfer
                        sq_wr_en   <= 1'b1;
                        sq_wr_addr <= load_count[$clog2(T_MAX):0];
                        sq_wr_data <= s_tdata[31:0];
                        load_count <= load_count + 32'h1;

                        `ifdef DEBUG_CTRL
                        $display("[CTRL] Scale[%0d]=0x%08h at t=%0t",
                                 load_count, s_tdata[31:0], $time);
                        `endif

                        // Total scales = 2 x matrix_size (S_Q + S_K)
                        if (load_count == {1'b0, matrix_size} * 2 - 1) begin
                            state      <= LOAD_Q;
                            load_count <= 32'h0;
                            tile_start_cycle <= cycle_count;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Load Q tile: TILE_SIZE x D_HEAD FP4 values
                // Host sends 16 FP4 values packed per 64-bit transfer
                // ------------------------------------------------------------
                LOAD_Q: begin
                    s_tready <= 1'b1;
                    if (s_tvalid && s_tready) begin
                        // Unpack 16 FP4 values from 64-bit word
                        // Write one at a time using load_count
                        q_wr_en   <= 1'b1;
                        q_wr_row  <= load_count[$clog2(TILE_SIZE)+$clog2(D_HEAD)-1:
                                                $clog2(D_HEAD)];
                        q_wr_col  <= load_count[$clog2(D_HEAD)-1:0];
                        q_wr_data <= s_tdata[3:0]; // simplified: one per cycle
                        load_count <= load_count + 32'h1;

                        if (load_count == TILE_SIZE * D_HEAD - 1) begin
                            state      <= LOAD_K;
                            load_count <= 32'h0;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Load K tile: TILE_SIZE x D_HEAD FP4 values
                // ------------------------------------------------------------
                LOAD_K: begin
                    s_tready <= 1'b1;
                    if (s_tvalid && s_tready) begin
                        k_wr_en   <= 1'b1;
                        k_wr_row  <= load_count[$clog2(TILE_SIZE)+$clog2(D_HEAD)-1:
                                                $clog2(D_HEAD)];
                        k_wr_col  <= load_count[$clog2(D_HEAD)-1:0];
                        k_wr_data <= s_tdata[3:0];
                        load_count <= load_count + 32'h1;

                        if (load_count == TILE_SIZE * D_HEAD - 1) begin
                            state     <= FEED_ARRAY;
                            d_counter <= 32'h0;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Feed D_HEAD columns to systolic array
                // Each cycle: a_in[i] = Q_tile[i][d], b_in[j] = K_tile[j][d]
                // ------------------------------------------------------------
                FEED_ARRAY: begin
                    arr_valid_in <= 1'b1;
                    d_counter    <= d_counter + 32'h1;

                    // Drive read addresses for current d column
                    for (int i = 0; i < TILE_SIZE; i++) begin
                        q_rd_row <= i[$clog2(TILE_SIZE)-1:0];
                        k_rd_row <= i[$clog2(TILE_SIZE)-1:0];
                    end
                    q_rd_col <= d_counter[$clog2(D_HEAD)-1:0];
                    k_rd_col <= d_counter[$clog2(D_HEAD)-1:0];

                    `ifdef DEBUG_CTRL
                    $display("[CTRL] FEED d=%0d at t=%0t", d_counter, $time);
                    `endif

                    if (d_counter == 32'(D_HEAD - 1)) begin
                        state <= WAIT_RESULT;
                    end
                end

                // ------------------------------------------------------------
                // Wait for systolic array to finish
                // ------------------------------------------------------------
                WAIT_RESULT: begin
                    if (arr_result_valid) begin
                        state   <= CAPTURE;
                        cap_row <= 32'h0;
                        cap_col <= 32'h0;

                        `ifdef DEBUG_CTRL
                        $display("[CTRL] Array done at t=%0t", $time);
                        `endif
                    end
                end

                // ------------------------------------------------------------
                // Capture: read all TILE_SIZE x TILE_SIZE results into out_buf
                // ------------------------------------------------------------
                CAPTURE: begin
                    out_wr_en   <= 1'b1;
                    out_wr_row  <= cap_row[$clog2(TILE_SIZE)-1:0];
                    out_wr_col  <= cap_col[$clog2(TILE_SIZE)-1:0];
                    out_wr_data <= arr_result[cap_row[$clog2(TILE_SIZE)-1:0]]
                                             [cap_col[$clog2(TILE_SIZE)-1:0]];

                    if (cap_col == 32'(TILE_SIZE - 1)) begin
                        cap_col <= 32'h0;
                        if (cap_row == 32'(TILE_SIZE - 1)) begin
                            state   <= DEQUANTIZE;
                            deq_row <= 32'h0;
                            deq_col <= 32'h0;
                            deq_phase <= 1'b0;
                        end else begin
                            cap_row <= cap_row + 32'h1;
                        end
                    end else begin
                        cap_col <= cap_col + 32'h1;
                    end
                end

                // ------------------------------------------------------------
                // Dequantize: result[i][j] x S_Q[tile_row*TILE+i] x S_K[tile_col*TILE+j]
                // Two sequential FP32 multiplies per element
                // Phase 0: raw_result x S_Q[i] -> deq_intermediate
                // Phase 1: deq_intermediate x S_K[j] -> final result -> out_buf
                // ------------------------------------------------------------
                DEQUANTIZE: begin
                    if (!deq_phase) begin
                        // Phase 0: multiply by S_Q
                        deq_a     <= out_rd_data;  // raw FP32 from out_buf
                        deq_b     <= sq_rd_data;   // S_Q[tile_row*TILE+i]
                        deq_valid <= 1'b1;

                        if (deq_result_valid) begin
                            deq_intermediate <= deq_result;
                            deq_phase        <= 1'b1;
                        end
                    end else begin
                        // Phase 1: multiply by S_K
                        deq_a     <= deq_intermediate;
                        deq_b     <= sk_rd_data;   // S_K[tile_col*TILE+j]
                        deq_valid <= 1'b1;

                        if (deq_result_valid) begin
                            // Write dequantized result back to out_buf
                            out_wr_en   <= 1'b1;
                            out_wr_row  <= deq_row[$clog2(TILE_SIZE)-1:0];
                            out_wr_col  <= deq_col[$clog2(TILE_SIZE)-1:0];
                            out_wr_data <= deq_result;
                            deq_phase   <= 1'b0;

                            `ifdef DEBUG_CTRL
                            $display("[CTRL] DEQZ[%0d][%0d]=0x%08h at t=%0t",
                                     deq_row, deq_col, deq_result, $time);
                            `endif

                            // Advance to next element
                            if (deq_col == 32'(TILE_SIZE - 1)) begin
                                deq_col <= 32'h0;
                                if (deq_row == 32'(TILE_SIZE - 1)) begin
                                    // Update profiling
                                    tile_count  <= tile_count + 32'h1;
                                    tile_cycles <= cycle_count - tile_start_cycle;
                                    state       <= STREAM_OUT;
                                    send_count  <= 32'h0;
                                end else begin
                                    deq_row <= deq_row + 32'h1;
                                end
                            end else begin
                                deq_col <= deq_col + 32'h1;
                            end
                        end
                    end
                end

                // ------------------------------------------------------------
                // Stream out: send TILE_SIZE x TILE_SIZE FP32 results
                // Pack two FP32 values per 64-bit AXI4-Stream transfer
                // ------------------------------------------------------------
                STREAM_OUT: begin
                    m_tvalid <= 1'b1;
                    m_tdata  <= {out_rd_data,
                                 32'h0};  // simplified: one FP32 per transfer
                    m_tlast  <= (send_count == 32'(TILE_SIZE * TILE_SIZE - 1));

                    if (m_tvalid && m_tready) begin
                        send_count <= send_count + 32'h1;

                        `ifdef DEBUG_CTRL
                        $display("[CTRL] STREAM[%0d]=0x%08h at t=%0t",
                                 send_count, out_rd_data, $time);
                        `endif

                        if (send_count == 32'(TILE_SIZE * TILE_SIZE - 1)) begin
                            state <= NEXT_TILE;
                        end
                    end
                end

                // ------------------------------------------------------------
                // Next tile: advance tile_col, then tile_row
                // ------------------------------------------------------------
                NEXT_TILE: begin
                    tile_start_cycle <= cycle_count;

                    if (tile_col == n_tiles - 1) begin
                        tile_col <= '0;
                        if (tile_row == n_tiles - 1) begin
                            state <= DONE_ST;
                        end else begin
                            tile_row   <= tile_row + 1'b1;
                            state      <= LOAD_Q;
                            load_count <= 32'h0;
                        end
                    end else begin
                        tile_col   <= tile_col + 1'b1;
                        state      <= LOAD_K;
                        load_count <= 32'h0;
                    end
                end

                // ------------------------------------------------------------
                DONE_ST: begin
                    done <= 1'b1;
                    `ifdef DEBUG_CTRL
                    $display("[CTRL] ALL DONE. tiles=%0d cycles=%0d at t=%0t",
                             tile_count, cycle_count, $time);
                    `endif
                end

                default: state <= IDLE;

            endcase
        end
    end

endmodule
