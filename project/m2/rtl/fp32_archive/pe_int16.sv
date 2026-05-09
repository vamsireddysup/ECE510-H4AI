/*
 * pe.sv -- Processing Element for QK^T Systolic Array
 *
 * Each PE computes one element of the output matrix QK^T.
 * It receives one element from Q (a_in, from left neighbor) and
 * one element from K^T (b_in, from top neighbor) every clock cycle,
 * multiplies them, and accumulates the result.
 *
 * Data passes through to neighbors unchanged so the wavefront
 * propagates across the full array.
 *
 * Precision: 16-bit fixed-point input, 32-bit accumulator.
 * Q16.0 format: 16-bit integer arithmetic.
 * Accumulator is 32-bit to avoid overflow during accumulation.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module pe (
    input  logic        clk,        // clock
    input  logic        rst_n,      // active-low synchronous reset
    input  logic signed [15:0] a_in,     // element from Q row (from left)
    input  logic signed [15:0] b_in,     // element from K^T col (from top)
    input  logic        valid_in,   // high when a_in and b_in carry valid data

    output logic signed [15:0] a_out,    // pass a_in to right neighbor
    output logic signed [15:0] b_out,   // pass b_in to bottom neighbor
    output logic        valid_out,  // delayed valid signal to neighbors
    output logic signed [31:0] result,   // accumulated dot product
    output logic        result_valid // high when result holds a complete value
);

    // -----------------------------------------------------------------------
    // Internal signals
    // -----------------------------------------------------------------------
    logic signed [31:0] product;    // one multiply result (16b x 16b = 32b)
    logic signed [31:0] acc;        // accumulator register

    // -----------------------------------------------------------------------
    // Multiply -- combinational, no register
    // Multiply a_in by b_in every cycle when valid
    // -----------------------------------------------------------------------
    assign product = {{16{a_in[15]}}, a_in} * {{16{b_in[15]}}, b_in};

    // -----------------------------------------------------------------------
    // Accumulator -- registered, updates every valid cycle
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            acc          <= 32'sd0;
            valid_out    <= 1'b0;
            result_valid <= 1'b0;
        end else begin
            valid_out <= valid_in;  // pass valid to neighbors one cycle later

            if (valid_in) begin
                acc          <= acc + product;  // accumulate
                result_valid <= 1'b1;           // result is being built
            end
        end
    end

   // -----------------------------------------------------------------------
    // Pass-through -- registered, one cycle latency
    // Registered pass-through breaks combinational loop across PE grid.
    // In real silicon, signals always register between pipeline stages.
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_out <= 16'sd0;
            b_out <= 16'sd0;
        end else begin
            a_out <= a_in;
            b_out <= b_in;
        end
    end

    assign result = acc;

endmodule
