// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Pipelined exact-quarter-unit to row-scaled FP32 conversion.
module score_scaler #(
    parameter int ACC_W = 15,
    parameter int INDEX_W = 4,
    parameter int LANES = 1
)(
    input logic clk, rst_n,
    input logic [LANES-1:0] launch_valid,
    input logic signed [LANES-1:0][ACC_W-1:0] acc_in,
    input logic [LANES-1:0][31:0] q_scale_in, k_scale_in,
    input logic [LANES-1:0][INDEX_W-1:0] index_in,
    output logic [LANES-1:0] result_valid,
    output logic [LANES-1:0][31:0] result,
    output logic [LANES-1:0][INDEX_W-1:0] result_index
);
    function automatic logic [31:0] quarter_to_fp32(
        input logic signed [ACC_W-1:0] value
    );
        logic [ACC_W-1:0] magnitude;
        logic [7:0] exponent;
        logic [22:0] fraction;
        int leading;
        magnitude = value[ACC_W-1] ? $unsigned(-value) : $unsigned(value);
        leading = 0;
        for (int bit_index = 0; bit_index < ACC_W; bit_index++)
            if (magnitude[bit_index]) leading = bit_index;
        exponent = 8'(leading + 125);
        fraction = 23'(magnitude) << (23-leading);
        quarter_to_fp32 = (value == 0) ? 32'h0 :
            {value[ACC_W-1], exponent, fraction};
    endfunction

    for (genvar lane = 0; lane < LANES; lane++) begin : g_lane
        logic [31:0] q_result;
        logic q_valid;
        logic [INDEX_W-1:0] index_pipe [0:5];
        logic [31:0] k_scale_pipe [0:2];

        fp32_mul u_scale_q (
            .clk, .rst_n, .a(quarter_to_fp32(acc_in[lane])),
            .b(q_scale_in[lane]), .valid_in(launch_valid[lane]),
            .result(q_result), .valid_out(q_valid)
        );
        fp32_mul u_scale_k (
            .clk, .rst_n, .a(q_result), .b(k_scale_pipe[2]),
            .valid_in(q_valid), .result(result[lane]),
            .valid_out(result_valid[lane])
        );

        always_ff @(posedge clk) begin
            if (!rst_n) begin
                for (int stage = 0; stage < 6; stage++) index_pipe[stage] <= '0;
                for (int stage = 0; stage < 3; stage++) k_scale_pipe[stage] <= '0;
            end else begin
                if (launch_valid[lane]) begin
                    index_pipe[0] <= index_in[lane];
                    k_scale_pipe[0] <= k_scale_in[lane];
                end
                for (int stage = 1; stage < 6; stage++)
                    index_pipe[stage] <= index_pipe[stage-1];
                k_scale_pipe[1] <= k_scale_pipe[0];
                k_scale_pipe[2] <= k_scale_pipe[1];
            end
        end
        assign result_index[lane] = index_pipe[5];
    end
endmodule
