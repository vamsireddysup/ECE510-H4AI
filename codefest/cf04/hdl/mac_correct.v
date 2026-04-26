/*
 * mac_correct.v -- Corrected MAC module
 *
 * Multiply-accumulate unit with synchronous active-high reset.
 * Inputs a and b are 8-bit signed. Output out is 32-bit signed accumulator.
 *
 * Fix over mac_llm_A.v:
 *   The sign extension {{16{a[7]}},a} * {{16{b[7]}},b} produces a 64-bit
 *   product that gets silently truncated to 32 bits, giving wrong results
 *   for negative inputs (e.g. a=-5, b=2 gave 33554422 instead of -10).
 *   Correct fix: declare a 16-bit signed product wire, assign combinationally,
 *   then sign-extend explicitly to 32 bits before accumulating.
 *
 * Fix over mac_llm_B.v:
 *   mac_llm_B uses a continuous assign for product which runs every cycle.
 *   This implementation is functionally equivalent but documents the intent
 *   more clearly with explicit sign extension.
 */

module mac (
    input  wire               clk,
    input  wire               rst,
    input  wire signed [7:0]  a,
    input  wire signed [7:0]  b,
    output reg  signed [31:0] out
);

    // Combinational 16-bit product -- correct width for 8x8 signed multiply
    wire signed [15:0] product;
    assign product = a * b;

    always @(posedge clk) begin
        if (rst)
            out <= 32'sd0;
        else
            out <= out + {{16{product[15]}}, product};
    end

endmodule
