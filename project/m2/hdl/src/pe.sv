/*
 * pe.sv -- FP32 PE behavioral model using integer dot product
 *
 * For M2 simulation: uses integer arithmetic to verify the
 * systolic array control logic and data flow. The test vectors
 * use small integers so integer arithmetic gives exact results.
 *
 * The FP32 encoding of integer N is computed directly:
 *   N=0: 0x00000000
 *   N>0: sign=0, exp=floor(log2(N))+127, mantissa=(N/2^exp - 1)*2^23
 *
 * M3 replaces this with synthesizable fp32_mul + fp32_add modules.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */
/* verilator lint_off WIDTHEXPAND */
/* verilator lint_off BLKSEQ */
/* verilator lint_off UNUSEDSIGNAL */
module pe #(
    parameter int D_HEAD = 4
)(
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
    // Registered pass-throughs
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
    // FP32 decode: extract integer value from IEEE 754 FP32
    // Valid for small positive integers (test vectors only)
    // -----------------------------------------------------------------------
    function automatic integer fp32_to_int(input logic [31:0] fp);
        integer exp;
        integer mant;
        begin
            if (fp == 32'h0) begin
                fp32_to_int = 0;
            end else begin
                exp  = fp[30:23] - 127;
                mant = (1 << 23) | fp[22:0];
                if (exp >= 23)
                    fp32_to_int = mant << (exp - 23);
                else
                    fp32_to_int = mant >> (23 - exp);
                if (fp[31]) fp32_to_int = -fp32_to_int;
            end
        end
    endfunction

    // -----------------------------------------------------------------------
    // FP32 encode: convert integer to IEEE 754 FP32
    // Valid for small integers in test vector range
    // -----------------------------------------------------------------------
    function automatic logic [31:0] int_to_fp32(input integer n);
        integer abs_n;
        integer exp;
        integer mant;
        begin
            if (n == 0) begin
                int_to_fp32 = 32'h0;
            end else begin
                abs_n = (n < 0) ? -n : n;
                exp   = 0;
                while ((1 << (exp+1)) <= abs_n) exp = exp + 1;
                mant  = (abs_n - (1 << exp)) << (23 - exp);
                int_to_fp32 = {(n < 0) ? 1'b1 : 1'b0,
                               8'(exp + 127),
                               23'(mant)};
            end
        end
    endfunction

    // -----------------------------------------------------------------------
    // Pipeline: register inputs, compute product, accumulate
    // -----------------------------------------------------------------------
    logic [31:0] a_reg, b_reg;
    logic        valid_reg;

    // Stage 1: register inputs
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_reg     <= 32'h0;
            b_reg     <= 32'h0;
            valid_reg <= 1'b0;
        end else begin
            a_reg     <= a_in;
            b_reg     <= b_in;
            valid_reg <= valid_in;
        end
    end

    // Stage 2: multiply
    logic [31:0] product;
    logic        product_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            product       <= 32'h0;
            product_valid <= 1'b0;
        end else begin
            product_valid <= valid_reg;
            if (valid_reg)
                product <= int_to_fp32(fp32_to_int(a_reg) *
                                       fp32_to_int(b_reg));
        end
    end

    // Stage 3: accumulate
    integer      acc_int;
    logic [31:0] count;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            acc_int      = 0;
            count        <= 32'h0;
            result_valid <= 1'b0;
        end else begin
            if (product_valid) begin
                acc_int = acc_int + fp32_to_int(product);
                count   <= count + 32'h1;
                if (count == 32'(D_HEAD - 1))
                    result_valid <= 1'b1;
            end
        end
    end

    assign result = int_to_fp32(acc_int);

endmodule

/* verilator lint_on WIDTHEXPAND */
/* verilator lint_on BLKSEQ */
/* verilator lint_on UNUSEDSIGNAL */
