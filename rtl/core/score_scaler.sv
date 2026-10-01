// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Pipelined exact-quarter-unit to block-scaled FP32 conversion.
//
// SCALE_FORMAT selects how a block scale is carried in the low bits of each
// 32-bit scale port:
//   0  FP32  the full 32-bit value, applied by two chained FP32 multipliers
//   1  E4M3  an 8-bit scale, applied by one narrow significand multiply
//
// The E4M3 path is exact. A block accumulator of ACC_W bits carries at most
// ACC_W-1 significant bits and each E4M3 significand adds four, so the product
// needs at most ACC_W+7 bits and fits FP32's 24-bit significand whenever
// ACC_W <= 17. Every supported block size satisfies that; see ADR 0008. The
// FP32 path rounds twice, once per multiplier.
//
// Scale latency is 6 cycles for FP32 and 3 for E4M3, which the cycle model's
// SCALE_PIPELINE_LATENCY mirrors. SCALE_FORMAT 0 is the default and is
// bit-identical and cycle-identical to the two-multiplier design it replaces.
module score_scaler #(
    parameter int ACC_W = 15,
    parameter int INDEX_W = 4,
    parameter int LANES = 1,
    parameter int SCALE_FORMAT = 0
)(
    input logic clk, rst_n,
    input logic [LANES-1:0] launch_valid,
    input logic signed [LANES*ACC_W-1:0] acc_in,
    input logic [LANES*32-1:0] q_scale_in, k_scale_in,
    input logic [LANES*INDEX_W-1:0] index_in,
    output logic [LANES-1:0] result_valid,
    output logic [LANES*32-1:0] result,
    output logic [LANES*INDEX_W-1:0] result_index
);
    localparam int ACC_INDEX_W = (ACC_W <= 2) ? 1 : $clog2(ACC_W);
    localparam int ACC_PAD_W = 1 << $clog2(ACC_W);
    localparam int SCALE_LATENCY = (SCALE_FORMAT == 0) ? 6 : 3;

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

    for (genvar lane = 0; lane < LANES; lane++) begin : g_lane
        logic [INDEX_W-1:0] index_pipe [0:SCALE_LATENCY-1];
        logic [31:0] converted;
        assign converted = quarter_to_fp32($signed(acc_in[lane*ACC_W +: ACC_W]));

        if (SCALE_FORMAT == 0) begin : g_fp32
            logic [31:0] q_result;
            logic q_valid;
            logic [31:0] k_scale_pipe [0:2];

            fp32_mul u_scale_q (
                .clk, .rst_n, .a(converted),
                .b(q_scale_in[lane*32 +: 32]), .valid_in(launch_valid[lane]),
                .result(q_result), .valid_out(q_valid)
            );
            fp32_mul u_scale_k (
                .clk, .rst_n, .a(q_result), .b(k_scale_pipe[2]),
                .valid_in(q_valid), .result(result[lane*32 +: 32]),
                .valid_out(result_valid[lane])
            );
            always_ff @(posedge clk) begin
                if (!rst_n) begin
                    for (int stage = 0; stage < 3; stage++) k_scale_pipe[stage] <= '0;
                end else begin
                    if (launch_valid[lane])
                        k_scale_pipe[0] <= k_scale_in[lane*32 +: 32];
                    k_scale_pipe[1] <= k_scale_pipe[0];
                    k_scale_pipe[2] <= k_scale_pipe[1];
                end
            end
        end else begin : g_e4m3
            // E4M3 block scales are positive by construction, and the host
            // quantizer never emits a zero or subnormal scale, so no sign bit
            // is carried and the exponent field is always nonzero.
            logic sign_1, valid_1, zero_1;
            logic [23:0] sig_1;
            logic signed [10:0] exp_sum_1;
            logic [3:0] q_sig_1, k_sig_1;
            logic [7:0] q_code, k_code;
            assign q_code = q_scale_in[lane*32 +: 8];
            assign k_code = k_scale_in[lane*32 +: 8];

            always_ff @(posedge clk) begin
                if (!rst_n) begin
                    valid_1 <= 1'b0; zero_1 <= 1'b0; sign_1 <= 1'b0;
                    sig_1 <= '0; exp_sum_1 <= '0;
                    q_sig_1 <= '0; k_sig_1 <= '0;
                end else begin
                    valid_1 <= launch_valid[lane];
                    zero_1 <= converted[30:23] == 8'h0;
                    sign_1 <= converted[31];
                    sig_1 <= {1'b1, converted[22:0]};
                    // E4M3 has a 4-bit exponent with bias 7 and a 3-bit mantissa.
                    exp_sum_1 <= 11'($signed({3'b0, converted[30:23]})) +
                                 11'($signed({7'b0, q_code[6:3]})) +
                                 11'($signed({7'b0, k_code[6:3]})) - 11'sd14;
                    q_sig_1 <= {1'b1, q_code[2:0]};
                    k_sig_1 <= {1'b1, k_code[2:0]};
                end
            end

            // The raw product lies in [2^29, 2^32) and the true significand is
            // raw / 2^29, in [1, 8), so normalization is at most two octaves.
            logic [39:0] product_2;
            logic signed [10:0] exp_sum_2;
            logic sign_2, valid_2, zero_2;
            always_ff @(posedge clk) begin
                if (!rst_n) begin
                    product_2 <= '0; exp_sum_2 <= '0;
                    sign_2 <= 1'b0; valid_2 <= 1'b0; zero_2 <= 1'b0;
                end else begin
                    product_2 <= 40'(sig_1) * 40'({4'b0, q_sig_1})
                                            * 40'({4'b0, k_sig_1});
                    exp_sum_2 <= exp_sum_1;
                    sign_2 <= sign_1; valid_2 <= valid_1; zero_2 <= zero_1;
                end
            end

            logic [22:0] fraction_3;
            logic signed [10:0] exp_adjust;
            always_comb begin
                if (product_2[31]) begin            // significand in [4, 8)
                    exp_adjust = exp_sum_2 + 11'sd2;
                    fraction_3 = product_2[30:8];
                end else if (product_2[30]) begin   // significand in [2, 4)
                    exp_adjust = exp_sum_2 + 11'sd1;
                    fraction_3 = product_2[29:7];
                end else begin                      // significand in [1, 2)
                    exp_adjust = exp_sum_2;
                    fraction_3 = product_2[28:6];
                end
            end
            always_ff @(posedge clk) begin
                if (!rst_n) begin
                    result[lane*32 +: 32] <= '0; result_valid[lane] <= 1'b0;
                end else begin
                    result_valid[lane] <= valid_2;
                    // Flushing subnormal and overflowed results to zero matches
                    // the FP32 units this path replaces.
                    result[lane*32 +: 32] <=
                        (zero_2 || exp_adjust <= 0 || exp_adjust > 254) ?
                        32'h0 : {sign_2, 8'(exp_adjust), fraction_3};
                end
            end
        end

        always_ff @(posedge clk) begin
            if (!rst_n) begin
                for (int stage = 0; stage < SCALE_LATENCY; stage++)
                    index_pipe[stage] <= '0;
            end else begin
                if (launch_valid[lane])
                    index_pipe[0] <= index_in[lane*INDEX_W +: INDEX_W];
                for (int stage = 1; stage < SCALE_LATENCY; stage++)
                    index_pipe[stage] <= index_pipe[stage-1];
            end
        end
        assign result_index[lane*INDEX_W +: INDEX_W] = index_pipe[SCALE_LATENCY-1];
    end
endmodule
