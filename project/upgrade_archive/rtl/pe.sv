/*
 * pe.sv -- FP4 x FP32 Processing Element for QK^T Systolic Array
 *
 * Inputs a_in and b_in are FP4 E2M1 (4-bit).
 * Uses fp4_mul.sv (1-cycle latency, LUT-based) for multiplication.
 * Uses fp32_add.sv (1-cycle latency) for FP32 accumulation.
 * Result is FP32 -- full precision accumulation of FP4 products.
 *
 * Operation:
 *   COLLECT phase:    receive D_HEAD FP4 input pairs, store FP32 products
 *                     in prod_buf as they arrive (1 cycle after each input)
 *   ACCUMULATE phase: add prod_buf entries one at a time into FP32 acc,
 *                     waiting 1 cycle between each addition for acc to update
 *   DONE:             assert result_valid, hold FP32 result on output
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Ports:
 *   clk          input  1-bit    system clock
 *   rst_n        input  1-bit    active-low synchronous reset
 *   a_in         input  4-bit    FP4 E2M1 input (Q element)
 *   b_in         input  4-bit    FP4 E2M1 input (K element)
 *   valid_in     input  1-bit    high when a_in and b_in are valid
 *   a_out        output 4-bit    registered pass-through to next PE column
 *   b_out        output 4-bit    registered pass-through to next PE row
 *   valid_out    output 1-bit    registered pass-through of valid_in
 *   result       output 32-bit   FP32 dot product result
 *   result_valid output 1-bit    high when result is valid
 *
 * Debug: compile with -DDEBUG_PE for $display traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module pe #(
    parameter int D_HEAD = 64   // dot product length
)(
    input  logic       clk,
    input  logic       rst_n,
    input  logic [3:0] a_in,      // FP4 E2M1 input
    input  logic [3:0] b_in,      // FP4 E2M1 input
    input  logic       valid_in,

    output logic [3:0] a_out,     // registered pass-through
    output logic [3:0] b_out,     // registered pass-through
    output logic       valid_out,
    output logic [31:0] result,   // FP32 accumulated result
    output logic        result_valid
);

    // -----------------------------------------------------------------------
    // Registered pass-throughs -- breaks combinational loops across PE grid
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_out     <= 4'h0;
            b_out     <= 4'h0;
            valid_out <= 1'b0;
        end else begin
            a_out     <= a_in;
            b_out     <= b_in;
            valid_out <= valid_in;
        end
    end

    // -----------------------------------------------------------------------
    // FP4 Multiply: a_in * b_in -> FP32 product (1-cycle latency)
    // -----------------------------------------------------------------------
    logic [31:0] product;
    logic        product_valid;

    fp4_mul u_mul (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (a_in),
        .b         (b_in),
        .valid_in  (valid_in),
        .result    (product),
        .valid_out (product_valid)
    );

    // -----------------------------------------------------------------------
    // Product buffer -- stores D_HEAD FP32 products as they arrive
    // fp4_mul has 1-cycle latency so products arrive 1 cycle after input
    // -----------------------------------------------------------------------
    logic [31:0] prod_buf [0:D_HEAD-1];
    logic [31:0] prod_count;
    logic        all_collected;

    assign all_collected = (prod_count == 32'(D_HEAD));

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            prod_count <= 32'h0;
            for (int i = 0; i < D_HEAD; i++)
                prod_buf[i] <= 32'h0;
        end else begin
            if (product_valid && !all_collected) begin
                prod_buf[prod_count[($clog2(D_HEAD)-1):0]] <= product;
                prod_count <= prod_count + 32'h1;

                `ifdef DEBUG_PE
                $display("[PE COLLECT] product[%0d]=0x%08h at t=%0t",
                         prod_count, product, $time);
                `endif
            end
        end
    end

    // -----------------------------------------------------------------------
    // FP32 Accumulator state machine
    // States: IDLE -> ACCUMULATE -> DONE
    //
    // fp32_add has 1-cycle latency:
    //   cycle N:   present prod_buf[i], assert acc_valid_in
    //   cycle N+1: add_valid fires, acc updates, move to prod_buf[i+1]
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        IDLE       = 2'b00,
        ACCUMULATE = 2'b01,
        DONE       = 2'b10
    } acc_state_t;

    acc_state_t  acc_state;
    logic [31:0] add_idx;
    logic [31:0] acc;
    logic        acc_valid_in;
    logic [31:0] add_result;
    logic        add_valid;
    logic        waiting;

    fp32_add u_add (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (acc),
        .b         (prod_buf[add_idx[($clog2(D_HEAD)-1):0]]),
        .valid_in  (acc_valid_in),
        .result    (add_result),
        .valid_out (add_valid)
    );

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            acc_state    <= IDLE;
            add_idx      <= 32'h0;
            acc          <= 32'h0;
            acc_valid_in <= 1'b0;
            result_valid <= 1'b0;
            waiting      <= 1'b0;
        end else begin
            acc_valid_in <= 1'b0;

            case (acc_state)

                IDLE: begin
                    if (all_collected) begin
                        acc_state    <= ACCUMULATE;
                        add_idx      <= 32'h0;
                        acc          <= 32'h0;
                        waiting      <= 1'b0;
                        acc_valid_in <= 1'b1;

                        `ifdef DEBUG_PE
                        $display("[PE ACC] Starting accumulation at t=%0t", $time);
                        `endif
                    end
                end

                ACCUMULATE: begin
                    if (!waiting)
                        waiting <= 1'b1;

                    if (add_valid) begin
                        acc     <= add_result;
                        waiting <= 1'b0;

                        `ifdef DEBUG_PE
                        $display("[PE ACC] add[%0d] done: acc=0x%08h at t=%0t",
                                 add_idx, add_result, $time);
                        `endif

                        if (add_idx == 32'(D_HEAD - 1)) begin
                            acc_state    <= DONE;
                            result_valid <= 1'b1;

                            `ifdef DEBUG_PE
                            $display("[PE ACC] DONE: result=0x%08h at t=%0t",
                                     add_result, $time);
                            `endif
                        end else begin
                            add_idx      <= add_idx + 32'h1;
                            acc_valid_in <= 1'b1;
                        end
                    end
                end

                DONE: begin
                    result_valid <= 1'b1;
                end

                default: acc_state <= IDLE;

            endcase
        end
    end

    assign result = acc;

    `ifdef DEBUG_PE
    always_ff @(posedge clk) begin
        if (result_valid && acc_state == DONE)
            $display("[PE RESULT] result=0x%08h at t=%0t", result, $time);
    end
    `endif

endmodule
