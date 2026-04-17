/*
 * pe.sv -- FP32 Processing Element for QK^T Systolic Array
 *
 * Each PE computes one element of the output matrix QK^T.
 * Receives one FP32 element from Q (a_in, from left neighbor) and
 * one FP32 element from K^T (b_in, from top neighbor) every clock
 * cycle, multiplies them using fp32_mul, accumulates using fp32_add.
 *
 * Pipeline latency:
 *   fp32_mul: 3 cycles
 *   fp32_add: 4 cycles
 *   Total per MAC: 7 cycles
 *
 * Pass-throughs (a_out, b_out) are registered to break combinational
 * loops across the PE grid.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module pe (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a_in,
    input  logic [31:0] b_in,
    input  logic        valid_in,

    output logic [31:0] a_out,
    output logic [31:0] b_out,
    output logic        valid_out,
    output logic [31:0] result,
    output logic        result_valid
);

    // -----------------------------------------------------------------------
    // Registered pass-throughs -- breaks combinational loops across PE grid
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_out     <= 32'h0;
            b_out     <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            a_out     <= a_in;
            b_out     <= b_in;
            valid_out <= valid_in;
        end
    end

    // -----------------------------------------------------------------------
    // FP32 Multiply: a_in * b_in -> product (3-cycle latency)
    // -----------------------------------------------------------------------
    logic [31:0] product;
    logic        product_valid;

    fp32_mul u_mul (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (a_in),
        .b         (b_in),
        .valid_in  (valid_in),
        .result    (product),
        .valid_out (product_valid)
    );

    // -----------------------------------------------------------------------
    // FP32 Accumulator: acc + product -> acc (4-cycle latency)
    // When product is not valid, add 0.0 to acc (identity, no change)
    // -----------------------------------------------------------------------
    logic [31:0] acc;
    logic [31:0] add_result;
    logic        add_valid;

    // 0.0 in IEEE 754 FP32 = 32'h00000000
    logic [31:0] add_b;
    assign add_b = product_valid ? product : 32'h0;

    fp32_add u_add (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (acc),
        .b         (add_b),
        .valid_in  (product_valid | result_valid),
        .result    (add_result),
        .valid_out (add_valid)
    );

    // -----------------------------------------------------------------------
    // Accumulator register
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            acc          <= 32'h0;
            result_valid <= 1'b0;
        end else begin
            if (add_valid) begin
                acc          <= add_result;
                result_valid <= 1'b1;
            end
        end
    end

    assign result = acc;

endmodule
