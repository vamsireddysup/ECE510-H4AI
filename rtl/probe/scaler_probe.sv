// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Cost probe for the block-scale format, not part of the active design.
//
// One score lane's scaling path: convert an exact quarter-unit accumulator to
// FP32, then apply the Q and K block scales. SCALE_FORMAT selects how the
// scales are represented and therefore what arithmetic the lane needs:
//
//   0  FP32   32-bit scales, two full FP32 multiplies (the current design)
//   1  E4M3   8-bit scales, two 24x4 significand multiplies
//   2  E8M0   8-bit power-of-two scales, exponent adds only
//
// Every variant takes the same accumulator and produces an FP32 score, so the
// mapped areas are comparable. See docs/results/precision.md for the accuracy
// side of the same comparison.
module scaler_probe #(
    parameter int ACC_W = 13,
    parameter int SCALE_FORMAT = 0
)(
    input logic clk, rst_n,
    input logic valid_in,
    input logic signed [ACC_W-1:0] acc_in,
    input logic [31:0] q_scale_in, k_scale_in,
    output logic valid_out,
    output logic [31:0] result
);
    localparam int ACC_INDEX_W = (ACC_W <= 2) ? 1 : $clog2(ACC_W);
    localparam int ACC_PAD_W = 1 << $clog2(ACC_W);

    // Identical to score_scaler's conversion, so the probe differs from the
    // active lane only in the scale arithmetic.
    function automatic logic [31:0] quarter_to_fp32(
        input logic signed [ACC_W-1:0] value
    );
        logic [ACC_W-1:0] magnitude;
        logic [ACC_PAD_W-1:0] search_value;
        logic [7:0] exponent;
        logic [22:0] fraction;
        logic [ACC_INDEX_W-1:0] leading;
        logic [4:0] fraction_shift;
        magnitude = value[ACC_W-1] ? $unsigned(-value) : $unsigned(value);
        search_value = '0;
        search_value[ACC_W-1:0] = magnitude;
        leading = '0;
        for (int level = $clog2(ACC_PAD_W)-1; level >= 0; level--) begin
            if (|(search_value >> (1 << level))) begin
                leading[level] = 1'b1;
                search_value = search_value >> (1 << level);
            end
        end
        exponent = 8'(leading) + 8'd125;
        fraction_shift = 5'd23 - 5'(leading);
        fraction = 23'(magnitude) << fraction_shift;
        quarter_to_fp32 = (value == 0) ? 32'h0 :
            {value[ACC_W-1], exponent, fraction};
    endfunction

    logic [31:0] converted;
    assign converted = quarter_to_fp32(acc_in);

    if (SCALE_FORMAT == 0) begin : g_fp32
        logic [31:0] q_result;
        logic q_valid;
        fp32_mul u_scale_q (
            .clk, .rst_n, .a(converted), .b(q_scale_in),
            .valid_in(valid_in), .result(q_result), .valid_out(q_valid)
        );
        // The K scale must be delayed to meet its product, as in score_scaler.
        logic [31:0] k_pipe [0:2];
        always_ff @(posedge clk) begin
            if (!rst_n) for (int s = 0; s < 3; s++) k_pipe[s] <= '0;
            else begin
                k_pipe[0] <= k_scale_in;
                k_pipe[1] <= k_pipe[0];
                k_pipe[2] <= k_pipe[1];
            end
        end
        fp32_mul u_scale_k (
            .clk, .rst_n, .a(q_result), .b(k_pipe[2]),
            .valid_in(q_valid), .result(result), .valid_out(valid_out)
        );
    end else begin : g_narrow
        // Both narrow formats carry one 8-bit scale per block in the low bits.
        // E4M3 is sign-free here: block scales are positive by construction.
        logic [7:0] q_code, k_code;
        assign q_code = q_scale_in[7:0];
        assign k_code = k_scale_in[7:0];

        logic sign_1;
        logic [23:0] sig_1;
        logic signed [10:0] exp_sum_1;
        logic [7:0] q_sig_1, k_sig_1;
        logic valid_1, zero_1;

        always_ff @(posedge clk) begin
            if (!rst_n) begin
                valid_1 <= 1'b0; zero_1 <= 1'b0; sign_1 <= 1'b0;
                sig_1 <= '0; exp_sum_1 <= '0;
                q_sig_1 <= '0; k_sig_1 <= '0;
            end else begin
                valid_1 <= valid_in;
                zero_1 <= converted[30:23] == 8'h0;
                sign_1 <= converted[31];
                sig_1 <= {1'b1, converted[22:0]};
                if (SCALE_FORMAT == 1) begin
                    // E4M3: 4-bit exponent, bias 7, and a 3-bit mantissa.
                    exp_sum_1 <= 11'($signed({3'b0, converted[30:23]})) +
                                 11'($signed({7'b0, q_code[6:3]})) +
                                 11'($signed({7'b0, k_code[6:3]})) - 11'sd14;
                    q_sig_1 <= {4'b0, 1'b1, q_code[2:0]};
                    k_sig_1 <= {4'b0, 1'b1, k_code[2:0]};
                end else begin
                    // E8M0: the scale is a power of two, so it is an exponent
                    // bias only and there is no significand to multiply.
                    exp_sum_1 <= 11'($signed({3'b0, converted[30:23]})) +
                                 11'($signed({3'b0, q_code})) +
                                 11'($signed({3'b0, k_code})) - 11'sd254;
                    q_sig_1 <= 8'h80;
                    k_sig_1 <= 8'h80;
                end
            end
        end

        // Stage 2: the significand product, on one scaling for both formats.
        // sig_1 is in [2^23, 2^24) and each 4-bit significand is in [8, 16)
        // representing [1, 2), so the raw product is in [2^29, 2^32) and the
        // true significand is raw / 2^29, in [1, 8). E8M0 substitutes 8 for
        // both significands, which is a constant shift, so synthesis removes
        // the multiplier for that variant.
        logic [39:0] product_2;
        logic signed [10:0] exp_sum_2;
        logic sign_2, valid_2, zero_2;
        always_ff @(posedge clk) begin
            if (!rst_n) begin
                product_2 <= '0; exp_sum_2 <= '0;
                sign_2 <= 1'b0; valid_2 <= 1'b0; zero_2 <= 1'b0;
            end else begin
                product_2 <= (SCALE_FORMAT == 1) ?
                    40'(sig_1) * 40'(q_sig_1) * 40'(k_sig_1) : 40'(sig_1) << 6;
                exp_sum_2 <= exp_sum_1;
                sign_2 <= sign_1; valid_2 <= valid_1; zero_2 <= zero_1;
            end
        end

        // Stage 3: pick the octave and pack. Flushing a subnormal or overflow
        // result to zero matches the existing FP32 units' behavior.
        logic [7:0] exp_3;
        logic [22:0] fraction_3;
        logic signed [10:0] exp_adjust;
        always_comb begin
            if (product_2[31]) begin            // [4, 8)
                exp_adjust = exp_sum_2 + 11'sd2;
                fraction_3 = product_2[30:8];
            end else if (product_2[30]) begin   // [2, 4)
                exp_adjust = exp_sum_2 + 11'sd1;
                fraction_3 = product_2[29:7];
            end else begin                      // [1, 2)
                exp_adjust = exp_sum_2;
                fraction_3 = product_2[28:6];
            end
            exp_3 = 8'(exp_adjust);
        end
        always_ff @(posedge clk) begin
            if (!rst_n) begin
                result <= '0; valid_out <= 1'b0;
            end else begin
                valid_out <= valid_2;
                result <= (zero_2 || exp_adjust <= 0 || exp_adjust > 254) ?
                    32'h0 : {sign_2, exp_3, fraction_3};
            end
        end
    end
endmodule
