// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Throughput-one reduction of parallel block-scaled FP32 partial scores.
module score_reducer #(
    parameter int BLOCK_COUNT = 2,
    parameter int INDEX_W = 4
)(
    /* verilator lint_off UNUSEDSIGNAL */
    input logic clk, rst_n,
    /* verilator lint_on UNUSEDSIGNAL */
    input logic [BLOCK_COUNT-1:0] block_valid,
    input logic [BLOCK_COUNT-1:0][31:0] block_result,
    /* verilator lint_off UNUSEDSIGNAL */
    input logic [BLOCK_COUNT-1:0][INDEX_W-1:0] block_index,
    /* verilator lint_on UNUSEDSIGNAL */
    output logic result_valid,
    output logic [31:0] result,
    output logic [INDEX_W-1:0] result_index
);
    if (BLOCK_COUNT == 1) begin : g_passthrough
        assign result_valid = &block_valid;
        assign result = block_result[0];
        assign result_index = block_index[0];
    end else begin : g_reduce
        logic [BLOCK_COUNT-1:0] stage_valid;
        logic [31:0] stage_result [0:BLOCK_COUNT-1];
        logic [INDEX_W-1:0] stage_index [0:BLOCK_COUNT-1];
        assign stage_valid[0] = &block_valid;
        assign stage_result[0] = block_result[0];
        assign stage_index[0] = block_index[0];

        for (genvar stage = 1; stage < BLOCK_COUNT; stage++) begin : g_add
            localparam int DELAY = 3*(stage-1);
            logic [31:0] aligned_block;
            logic [INDEX_W-1:0] index_pipe [0:2];
            if (DELAY == 0) begin : g_no_delay
                assign aligned_block = block_result[stage];
            end else begin : g_delay
                logic [31:0] delay_pipe [0:DELAY-1];
                always_ff @(posedge clk) begin
                    if (!rst_n)
                        for (int slot = 0; slot < DELAY; slot++) delay_pipe[slot] <= '0;
                    else begin
                        delay_pipe[0] <= block_result[stage];
                        for (int slot = 1; slot < DELAY; slot++)
                            delay_pipe[slot] <= delay_pipe[slot-1];
                    end
                end
                assign aligned_block = delay_pipe[DELAY-1];
            end
            fp32_add u_add (
                .clk, .rst_n, .a(stage_result[stage-1]), .b(aligned_block),
                .valid_in(stage_valid[stage-1]), .result(stage_result[stage]),
                .valid_out(stage_valid[stage])
            );
            always_ff @(posedge clk) begin
                if (!rst_n) begin
                    index_pipe[0] <= '0; index_pipe[1] <= '0; index_pipe[2] <= '0;
                end else begin
                    index_pipe[0] <= stage_index[stage-1];
                    index_pipe[1] <= index_pipe[0];
                    index_pipe[2] <= index_pipe[1];
                end
            end
            assign stage_index[stage] = index_pipe[2];
        end
        assign result_valid = stage_valid[BLOCK_COUNT-1];
        assign result = stage_result[BLOCK_COUNT-1];
        assign result_index = stage_index[BLOCK_COUNT-1];
    end
endmodule
