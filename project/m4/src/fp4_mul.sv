/*
 * fp4_mul.sv -- FP4 E2M1 Multiplier with registered output
 *
 * Wraps fp4_mul_lut.sv (combinational 256-entry ROM) and adds a
 * registered output stage for pipeline timing.
 *
 * FP4 E2M1 format (4 bits):
 *   bit 3:   sign
 *   bit 2-1: exponent (2 bits, bias=1)
 *   bit 0:   mantissa (1 bit, implicit leading 1 for normal numbers)
 *
 * Representable values:
 *   Positive: 0.0, 0.5, 1.0, 1.5, 2.0, 3.0, 4.0, 6.0
 *   Negative: -0.0, -0.5, -1.0, -1.5, -2.0, -3.0, -4.0, -6.0
 *
 * Pipeline: 1 stage (registered output, 1-cycle latency)
 *   Cycle 0: present a, b, valid_in
 *   Cycle 1: result and valid_out are stable
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Ports:
 *   clk       input  1-bit   system clock
 *   rst_n     input  1-bit   active-low synchronous reset
 *   a         input  4-bit   FP4 E2M1 operand A
 *   b         input  4-bit   FP4 E2M1 operand B
 *   valid_in  input  1-bit   high when a and b are valid
 *   result    output 32-bit  FP32 IEEE 754 product a*b
 *   valid_out output 1-bit   high when result is valid (1 cycle after valid_in)
 *
 * Debug: compile with -DDEBUG_FP4MUL for $display traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module fp4_mul (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [3:0]  a,
    input  logic [3:0]  b,
    input  logic        valid_in,
    output logic [31:0] result,
    output logic        valid_out
);

    // -----------------------------------------------------------------------
    // Combinational LUT output
    // -----------------------------------------------------------------------
    logic [31:0] lut_result;

    fp4_mul_lut u_lut (
        .a      (a),
        .b      (b),
        .result (lut_result)
    );

    // -----------------------------------------------------------------------
    // Registered output -- 1-cycle latency
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result    <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            result    <= lut_result;
            valid_out <= valid_in;

            `ifdef DEBUG_FP4MUL
            if (valid_in)
                $display("[FP4MUL] a=0x%01h b=0x%01h lut_result=0x%08h at t=%0t",
                         a, b, lut_result, $time);
            `endif
        end
    end

endmodule
