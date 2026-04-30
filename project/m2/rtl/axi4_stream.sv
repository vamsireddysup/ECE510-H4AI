/*
 * axi4_stream.sv -- AXI4-Stream Data Interface for QK^T Chiplet
 *
 * Handles streaming of Q and K matrix data from host to chiplet (input)
 * and score matrix data from chiplet to host (output).
 *
 * Data packing (64-bit tdata):
 *   Input:  tdata[63:32] = Q row element (FP32)
 *           tdata[31:0]  = K col element (FP32)
 *   Output: tdata[63:32] = result[i][j] high word (FP32)
 *           tdata[31:0]  = result[i][j] low word (0 for 32-bit result)
 *
 * For a SIZE x SIZE matrix with D_HEAD dot product length:
 *   Input transfers:  SIZE x D_HEAD (one per PE row/col per clock)
 *   Output transfers: SIZE x SIZE   (one per output element)
 *
 * Backpressure: chiplet deasserts s_tready when busy processing
 *
 * Debug: compile with -DDEBUG_STREAM for transaction traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */
    /* verilator lint_off UNUSEDPARAM */
    /* verilator lint_off UNUSEDSIGNAL */
module axi4_stream #(
    parameter int SIZE   = 4,   // systolic array dimension
    parameter int D_HEAD = 4    // dot product length
)(

    input  logic        clk,
    input  logic        rst_n,

    // Input AXI4-Stream (host -> chiplet): Q and K data
    // tdata[63:32] = one Q row element, tdata[31:0] = one K col element
    input  logic        s_tvalid,
    output logic        s_tready,
    input  logic [63:0] s_tdata,
    input  logic        s_tlast,   // marks last element of stream

    // Output AXI4-Stream (chiplet -> host): score matrix
    output logic        m_tvalid,
    input  logic        m_tready,
    output logic [63:0] m_tdata,
    output logic        m_tlast,   // marks last element of output

    // Control signals
    input  logic        start,     // from AXI4-Lite ctrl: begin accepting data
    output logic        done       // to AXI4-Lite ctrl: computation complete

);

    // -----------------------------------------------------------------------
    // State machine
    // IDLE -> RECEIVING -> COMPUTING -> SENDING -> DONE_ST
    // -----------------------------------------------------------------------
    typedef enum logic [2:0] {
        IDLE      = 3'b000,
        RECEIVING = 3'b001,
        COMPUTING = 3'b010,
        SENDING   = 3'b011,
        DONE_ST   = 3'b100
    } state_t;

    state_t state;

    // -----------------------------------------------------------------------
    // Input data buffers
    // Store one Q row element per row and one K col element per col per cycle
    // For simplicity: buffer one complete set of SIZE pairs per d step
    // -----------------------------------------------------------------------
    logic [31:0] q_buf [SIZE];   // one Q element per row
    logic [31:0] k_buf [SIZE];   // one K element per col
    logic [31:0] recv_count;     // number of input transfers received

    // Compute core interface (simplified -- connects to systolic array)
    logic [31:0] a_out [SIZE];   // Q elements to systolic array left edge
    logic [31:0] b_out [SIZE];   // K elements to systolic array top edge
    logic        core_valid;     // valid to systolic array

    // Output buffer for score matrix
    logic [31:0] score_buf [SIZE*SIZE];
    logic [31:0] send_count;     // number of output transfers sent
    logic [31:0] total_out;      // total output transfers needed

    assign total_out = 32'(SIZE * SIZE);

    // -----------------------------------------------------------------------
    // Input stream control
    // s_tready: high when we can accept input data
    // -----------------------------------------------------------------------
    assign s_tready = (state == RECEIVING);

    // -----------------------------------------------------------------------
    // Output stream control
    // m_tvalid: high when we have data to send
    // -----------------------------------------------------------------------
    assign m_tvalid = (state == SENDING);
    assign m_tdata  = (state == SENDING) ?
                      {score_buf[send_count], 32'h0} : 64'h0;
    assign m_tlast  = (state == SENDING) &&
                      (send_count == total_out - 32'h1);

    // done signal to AXI4-Lite ctrl
    assign done = (state == DONE_ST);

    // -----------------------------------------------------------------------
    // State machine
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state       <= IDLE;
            recv_count  <= 32'h0;
            send_count  <= 32'h0;
            core_valid  <= 1'b0;
            for (int i = 0; i < SIZE; i++) begin
                q_buf[i] <= 32'h0;
                k_buf[i] <= 32'h0;
            end
            for (int i = 0; i < SIZE*SIZE; i++)
                score_buf[i] <= 32'h0;
        end else begin
            core_valid <= 1'b0;

            case (state)

                IDLE: begin
                    recv_count <= 32'h0;
                    send_count <= 32'h0;
                    if (start) begin
                        state <= RECEIVING;
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] START received, entering RECEIVING at t=%0t",
                                 $time);
                        `endif
                    end
                end

                RECEIVING: begin
                    if (s_tvalid && s_tready) begin
                        q_buf[recv_count[$clog2(SIZE)-1:0]] <= s_tdata[63:32];
                        k_buf[recv_count[$clog2(SIZE)-1:0]] <= s_tdata[31:0];

                        `ifdef DEBUG_STREAM
                        $display("[STREAM] RX transfer %0d: Q=0x%08h K=0x%08h at t=%0t",
                                 recv_count, s_tdata[63:32], s_tdata[31:0], $time);
                        `endif

                        if (recv_count == 32'(SIZE - 1) || s_tlast) begin
                            recv_count <= 32'h0;
                            state      <= COMPUTING;
                            core_valid <= 1'b1;
                            `ifdef DEBUG_STREAM
                            $display("[STREAM] All input received, entering COMPUTING at t=%0t",
                                     $time);
                            `endif
                        end else begin
                            recv_count <= recv_count + 32'h1;
                        end
                    end
                end

                COMPUTING: begin
                    // Simple placeholder: wait 5 cycles then move to SENDING
                    // In full integration this waits for systolic array result_valid
                    recv_count <= recv_count + 32'h1;

                    // Load dummy score values for verification
                    // In full integration these come from systolic array result
                    if (recv_count == 32'h5) begin
                        for (int i = 0; i < SIZE*SIZE; i++)
                            score_buf[i] <= 32'(i + 1);  // placeholder values
                        state      <= SENDING;
                        send_count <= 32'h0;
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] Entering SENDING at t=%0t", $time);
                        `endif
                    end
                end

                SENDING: begin
                    if (m_tvalid && m_tready) begin
                        `ifdef DEBUG_STREAM
                        $display("[STREAM] TX transfer %0d: data=0x%08h at t=%0t",
                                 send_count, score_buf[send_count], $time);
                        `endif

                        if (send_count == total_out - 32'h1) begin
                            state <= DONE_ST;
                        end else begin
                            send_count <= send_count + 32'h1;
                        end
                    end
                end

                DONE_ST: begin
                    // Hold done high until reset
                    `ifdef DEBUG_STREAM
                    $display("[STREAM] DONE state at t=%0t", $time);
                    `endif
                end

                default: state <= IDLE;

            endcase
        end
    end

    // Connect to systolic array inputs (simplified)
    generate
        for (genvar i = 0; i < SIZE; i++) begin : gen_core_out
            assign a_out[i] = q_buf[i];
            assign b_out[i] = k_buf[i];
        end
    endgenerate


endmodule

/* verilator lint_on UNUSEDPARAM */
/* verilator lint_on UNUSEDSIGNAL */
