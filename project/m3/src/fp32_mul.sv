/*
 * fp32_mul.sv -- 3-stage Pipelined FP32 Multiplier
 *
 * Computes result = a * b using IEEE 754 single-precision arithmetic.
 *
 * Pipeline stages:
 *   Stage 1 (cycle 1): Field extraction, special case detection,
 *                      exponent addition, sign computation
 *   Stage 2 (cycle 2): 24x24-bit significand multiplication
 *   Stage 3 (cycle 3): Normalization, rounding, result packing
 *
 * Latency: 3 cycles
 * Interface matches fp32_add.sv -- drop-in for dequantization multiplier.
 *
 * Special cases handled:
 *   NaN inputs    -> NaN output
 *   Inf * 0       -> NaN
 *   Inf * nonzero -> Inf (correct sign)
 *   0 * anything  -> 0
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module fp32_mul (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a,
    input  logic [31:0] b,
    input  logic        valid_in,
    output logic [31:0] result,
    output logic        valid_out
);

    // -----------------------------------------------------------------------
    // Combinational field extraction
    // -----------------------------------------------------------------------
    logic        sign_a, sign_b;
    logic [7:0]  exp_a,  exp_b;
    logic [23:0] sig_a,  sig_b;
    logic        nan_a, nan_b, inf_a, inf_b, zero_a, zero_b;

    assign sign_a = a[31];
    assign exp_a  = a[30:23];
    assign sig_a  = (exp_a == 8'h0) ? {1'b0, a[22:0]} : {1'b1, a[22:0]};
    assign sign_b = b[31];
    assign exp_b  = b[30:23];
    assign sig_b  = (exp_b == 8'h0) ? {1'b0, b[22:0]} : {1'b1, b[22:0]};

    assign nan_a  = (exp_a == 8'hFF) && (a[22:0] != 23'h0);
    assign nan_b  = (exp_b == 8'hFF) && (b[22:0] != 23'h0);
    assign inf_a  = (exp_a == 8'hFF) && (a[22:0] == 23'h0);
    assign inf_b  = (exp_b == 8'hFF) && (b[22:0] == 23'h0);
    assign zero_a = (exp_a == 8'h00) && (a[22:0] == 23'h0);
    assign zero_b = (exp_b == 8'h00) && (b[22:0] == 23'h0);

    // -----------------------------------------------------------------------
    // Stage 1: exponent add, sign, special case
    // -----------------------------------------------------------------------
    logic        s1_valid;
    logic        s1_special;
    logic [31:0] s1_special_result;
    logic        s1_result_sign;
    logic [8:0]  s1_exp_sum;    // 9 bits to detect overflow
    logic [23:0] s1_sig_a;
    logic [23:0] s1_sig_b;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_valid          <= 1'b0;
            s1_special        <= 1'b0;
            s1_special_result <= 32'h0;
            s1_result_sign    <= 1'b0;
            s1_exp_sum        <= 9'h0;
            s1_sig_a          <= 24'h0;
            s1_sig_b          <= 24'h0;
        end else begin
            s1_valid       <= valid_in;
            s1_result_sign <= sign_a ^ sign_b;
            s1_exp_sum     <= {1'b0, exp_a} + {1'b0, exp_b} - 9'd127;
            s1_sig_a       <= sig_a;
            s1_sig_b       <= sig_b;

            if (nan_a || nan_b || (inf_a && zero_b) || (zero_a && inf_b)) begin
                s1_special        <= 1'b1;
                s1_special_result <= 32'h7FC00000; // NaN
            end else if (inf_a || inf_b) begin
                s1_special        <= 1'b1;
                s1_special_result <= {(sign_a ^ sign_b), 8'hFF, 23'h0}; // Inf
            end else if (zero_a || zero_b) begin
                s1_special        <= 1'b1;
                s1_special_result <= 32'h0; // zero
            end else begin
                s1_special        <= 1'b0;
                s1_special_result <= 32'h0;
            end
        end
    end

    // -----------------------------------------------------------------------
    // Stage 2: 24x24 significand multiply (48-bit result)
    // -----------------------------------------------------------------------
    logic        s2_valid;
    logic        s2_special;
    logic [31:0] s2_special_result;
    logic        s2_result_sign;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [8:0]  s2_exp_sum;
    logic [47:0] s2_product;
    /* verilator lint_on UNUSEDSIGNAL */

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_valid          <= 1'b0;
            s2_special        <= 1'b0;
            s2_special_result <= 32'h0;
            s2_result_sign    <= 1'b0;
            s2_exp_sum        <= 9'h0;
            s2_product        <= 48'h0;
        end else begin
            s2_valid          <= s1_valid;
            s2_special        <= s1_special;
            s2_special_result <= s1_special_result;
            s2_result_sign    <= s1_result_sign;
            s2_exp_sum        <= s1_exp_sum;
            s2_product        <= s1_sig_a * s1_sig_b;
        end
    end

    // -----------------------------------------------------------------------
    // Stage 3: normalize and pack
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result    <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            valid_out <= s2_valid;

            if (s2_special) begin
                result <= s2_special_result;
            end else begin
                // Product is 48 bits: sig_a(24) x sig_b(24)
                // Both normalized: bit 47 or 46 is the leading 1
                if (s2_product[47]) begin
                    // Leading 1 at bit 47 -- shift right 1, exp+1
                    // Result mantissa = product[46:24]
                    result <= {s2_result_sign,
                               s2_exp_sum[7:0] + 8'h1,
                               s2_product[46:24]};
                end else begin
                    // Leading 1 at bit 46 -- no shift needed
                    // Result mantissa = product[45:23]
                    result <= {s2_result_sign,
                               s2_exp_sum[7:0],
                               s2_product[45:23]};
                end
            end
        end
    end

endmodule
