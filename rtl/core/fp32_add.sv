// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Three-stage FP32 adder with round-to-nearest-even for finite normal values.
module fp32_add (
    input logic clk, rst_n,
    input logic [31:0] a, b,
    input logic valid_in,
    output logic [31:0] result,
    output logic valid_out
);
    logic sign_a, sign_b;
    logic [7:0] exp_a, exp_b;
    logic [23:0] sig_a, sig_b;
    logic nan_a, nan_b, inf_a, inf_b, zero_a, zero_b;
    assign sign_a = a[31];
    assign sign_b = b[31];
    assign exp_a = a[30:23];
    assign exp_b = b[30:23];
    assign sig_a = {exp_a != 0, a[22:0]};
    assign sig_b = {exp_b != 0, b[22:0]};
    assign nan_a = exp_a == 8'hff && a[22:0] != 0;
    assign nan_b = exp_b == 8'hff && b[22:0] != 0;
    assign inf_a = exp_a == 8'hff && a[22:0] == 0;
    assign inf_b = exp_b == 8'hff && b[22:0] == 0;
    assign zero_a = a[30:0] == 0;
    assign zero_b = b[30:0] == 0;

    logic s1_valid, s1_special, s1_sign_l, s1_sign_s;
    logic [31:0] s1_special_result;
    logic [7:0] s1_exp_l, s1_exp_diff;
    logic [26:0] s1_sig_l, s1_sig_s;
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_valid <= 0; s1_special <= 0; s1_special_result <= 0;
            s1_sign_l <= 0; s1_sign_s <= 0; s1_exp_l <= 0;
            s1_exp_diff <= 0; s1_sig_l <= 0; s1_sig_s <= 0;
        end else begin
            s1_valid <= valid_in;
            if (nan_a || nan_b || (inf_a && inf_b && sign_a != sign_b)) begin
                s1_special <= 1; s1_special_result <= 32'h7fc00000;
            end else if (inf_a) begin
                s1_special <= 1; s1_special_result <= a;
            end else if (inf_b) begin
                s1_special <= 1; s1_special_result <= b;
            end else if (zero_a) begin
                s1_special <= 1; s1_special_result <= zero_b ? 32'h0 : b;
            end else if (zero_b) begin
                s1_special <= 1; s1_special_result <= a;
            end else begin
                s1_special <= 0; s1_special_result <= 0;
            end
            if ({exp_a, sig_a} >= {exp_b, sig_b}) begin
                s1_sign_l <= sign_a; s1_sign_s <= sign_b;
                s1_exp_l <= exp_a; s1_exp_diff <= exp_a-exp_b;
                s1_sig_l <= {sig_a, 3'b0}; s1_sig_s <= {sig_b, 3'b0};
            end else begin
                s1_sign_l <= sign_b; s1_sign_s <= sign_a;
                s1_exp_l <= exp_b; s1_exp_diff <= exp_b-exp_a;
                s1_sig_l <= {sig_b, 3'b0}; s1_sig_s <= {sig_a, 3'b0};
            end
        end
    end

    function automatic logic [26:0] shift_with_sticky(
        input logic [26:0] value, input logic [7:0] distance
    );
        logic sticky;
        logic [26:0] shifted;
        sticky = 0;
        if (distance >= 27) begin
            shifted = 0;
            sticky = |value;
        end else begin
            shifted = value >> distance;
            for (int bit_index = 0; bit_index < 27; bit_index++)
                if (bit_index < distance) sticky |= value[bit_index];
        end
        shifted[0] |= sticky;
        shift_with_sticky = shifted;
    endfunction

    logic s2_valid, s2_special, s2_sign;
    logic [31:0] s2_special_result;
    logic [7:0] s2_exp;
    logic [27:0] s2_sum;
    logic [26:0] aligned_small;
    assign aligned_small = shift_with_sticky(s1_sig_s, s1_exp_diff);
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_valid <= 0; s2_special <= 0; s2_special_result <= 0;
            s2_sign <= 0; s2_exp <= 0; s2_sum <= 0;
        end else begin
            s2_valid <= s1_valid; s2_special <= s1_special;
            s2_special_result <= s1_special_result;
            s2_sign <= s1_sign_l; s2_exp <= s1_exp_l;
            if (s1_sign_l == s1_sign_s)
                s2_sum <= {1'b0,s1_sig_l}+{1'b0,aligned_small};
            else
                s2_sum <= {1'b0,s1_sig_l}-{1'b0,aligned_small};
        end
    end

    logic [26:0] normalized;
    logic [8:0] normalized_exp;
    logic [23:0] mantissa;
    logic [24:0] rounded;
    logic increment;
    int leading;
    always_comb begin
        normalized = s2_sum[26:0];
        normalized_exp = {1'b0,s2_exp};
        leading = 26;
        if (s2_sum[27]) begin
            normalized = s2_sum[27:1];
            normalized[0] |= s2_sum[0];
            normalized_exp = {1'b0,s2_exp}+9'd1;
        end else if (s2_sum[26:0] != 0 && !s2_special) begin
            for (int bit_index = 0; bit_index <= 26; bit_index++)
                if (s2_sum[bit_index]) leading = bit_index;
            normalized = s2_sum[26:0] << (26-leading);
            normalized_exp = {1'b0,s2_exp} - 9'(26-leading);
        end
        mantissa = normalized[26:3];
        increment = normalized[2] && ((|normalized[1:0]) || normalized[3]);
        rounded = {1'b0,mantissa}+25'(increment);
        if (rounded[24]) begin
            mantissa = rounded[24:1];
            normalized_exp = normalized_exp+9'd1;
        end else mantissa = rounded[23:0];
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result <= 0; valid_out <= 0;
        end else begin
            valid_out <= s2_valid;
            if (s2_special) result <= s2_special_result;
            else if (s2_sum == 0) result <= 0;
            else if (normalized_exp[8] || normalized_exp >= 9'd255)
                result <= {s2_sign,8'hff,23'h0};
            else if (normalized_exp == 0)
                result <= {s2_sign,31'h0};
            else result <= {s2_sign,normalized_exp[7:0],mantissa[22:0]};
        end
    end
endmodule
