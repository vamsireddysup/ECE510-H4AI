/*
 * pe.sv -- FP4 x FP32 Processing Element for QK^T Systolic Array
 *
 * Updated for 3-stage pipelined fp32_add:
 *   ACCUMULATE state waits 3 cycles (not 1) for fp32_add result.
 *   wait_count counts 0->2 before accepting add_valid.
 *
 * All other behavior identical to 1-stage version.
 *
 * Timing with D_HEAD=4:
 *   result_valid at drain cycle 18 (was 10 with 1-stage fp32_add)
 *
 * Timing with D_HEAD=64:
 *   result_valid at drain cycle 258 (was 130)
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module pe #(
    parameter int D_HEAD = 64
)(
    input  logic       clk,
    input  logic       rst_n,
    input  logic [3:0] a_in,
    input  logic [3:0] b_in,
    input  logic       valid_in,
    output logic [3:0] a_out,
    output logic [3:0] b_out,
    output logic       valid_out,
    output logic [31:0] result,
    output logic        result_valid
);

    // Registered pass-throughs
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

    // FP4 multiplier (1-cycle latency)
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

    // Product buffer
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
            end
        end
    end

    // FP32 adder (3-cycle latency -- pipelined)
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
    logic [1:0]  wait_count;   // counts 0->2 for 3-cycle fp32_add latency

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
            wait_count   <= 2'h0;
        end else begin
            acc_valid_in <= 1'b0;

            case (acc_state)

                IDLE: begin
                    if (all_collected) begin
                        acc_state    <= ACCUMULATE;
                        add_idx      <= 32'h0;
                        acc          <= 32'h0;
                        wait_count   <= 2'h0;
                        acc_valid_in <= 1'b1;
                    end
                end

                ACCUMULATE: begin
                    // Count up to 2 (3 cycles total) before accepting result
                    if (wait_count < 2'h2) begin
                        wait_count <= wait_count + 2'h1;
                    end

                    if (add_valid && wait_count == 2'h2) begin
                        acc        <= add_result;
                        wait_count <= 2'h0;

                        if (add_idx == 32'(D_HEAD - 1)) begin
                            acc_state    <= DONE;
                            result_valid <= 1'b1;
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

endmodule
