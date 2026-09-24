// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Overlapped packed-stream QK^T engine. See docs/stream-protocol.md.
module qkt_chiplet_top #(
    parameter int TILE_SIZE = 4,
    parameter int D_HEAD = 64,
    parameter int T_MAX = 16,
    parameter int K_REUSE = 0,
    parameter int SCALE_BLOCK_SIZE = 32,
    parameter int SCORE_LANES = 1
)(
    input logic clk, rst_n,
    input logic awvalid, output logic awready, input logic [31:0] awaddr,
    input logic wvalid, output logic wready, input logic [31:0] wdata,
    input logic [3:0] wstrb, output logic bvalid, input logic bready,
    output logic [1:0] bresp,
    input logic arvalid, output logic arready, input logic [31:0] araddr,
    output logic rvalid, input logic rready, output logic [31:0] rdata,
    output logic [1:0] rresp,
    input logic s_tvalid, output logic s_tready, input logic [63:0] s_tdata,
    input logic s_tlast,
    output logic m_tvalid, input logic m_tready, output logic [63:0] m_tdata,
    output logic m_tlast
);
    localparam bit K_REUSE_EN = K_REUSE != 0;
    localparam int BLOCK_COUNT = (D_HEAD+SCALE_BLOCK_SIZE-1)/SCALE_BLOCK_SIZE;
    localparam int ACC_DEPTH = (SCALE_BLOCK_SIZE < D_HEAD) ? SCALE_BLOCK_SIZE : D_HEAD;
    localparam int ACC_W = $clog2(144*ACC_DEPTH+1)+1;
    localparam int INDEX_W = $clog2(TILE_SIZE*TILE_SIZE);
    localparam int TILE_BEATS = (TILE_SIZE*D_HEAD+15)/16;

    logic start, done, command_active;
    logic [31:0] matrix_size, tile_count, cycle_count, tile_cycles;
    logic [31:0] input_beats, output_beats, input_stalls, output_stalls;
    logic [31:0] compute_cycles, scale_cycles;
    logic [3:0] error_code;
    logic [31:0] protocol_version;
    assign protocol_version = K_REUSE_EN ? 32'd4 : 32'd3;
    axi4_lite_ctrl u_ctrl (
        .clk, .rst_n, .awvalid, .awready, .awaddr, .wvalid, .wready,
        .wdata, .wstrb, .bvalid, .bready, .bresp, .arvalid, .arready,
        .araddr, .rvalid, .rready, .rdata, .rresp, .start, .done,
        .matrix_size, .tile_count, .cycle_count, .tile_cycles,
        .error_code, .protocol_version, .input_beats, .output_beats, .input_stalls,
        .output_stalls, .compute_cycles, .scale_cycles
    );

    typedef enum logic [2:0] {
        FE_IDLE, FE_SCALES, FE_CACHE_K, FE_LOAD_Q, FE_LOAD_K, FE_DONE
    } frontend_t;
    frontend_t frontend;

    logic [31:0] sq [0:T_MAX-1][0:BLOCK_COUNT-1];
    logic [31:0] sk [0:T_MAX-1][0:BLOCK_COUNT-1];
    logic [3:0] q_bank [0:1][0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0] k_bank [0:1][0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0] k_cache [0:T_MAX-1][0:D_HEAD-1];
    logic signed [ACC_W-1:0] acc_bank
        [0:1][0:BLOCK_COUNT-1][0:TILE_SIZE-1][0:TILE_SIZE-1];
    logic [31:0] score_bank [0:1][0:TILE_SIZE*TILE_SIZE-1];

    logic [1:0] q_valid, k_valid, acc_valid, score_valid;
    logic load_q_bank, load_k_bank, calc_q_bank, calc_k_bank;
    logic calc_acc_bank, scale_acc_bank, scale_score_bank, output_score_bank;
    logic calc_busy, scale_busy;
    logic [31:0] load_beat, cache_tile, input_row, input_col;
    logic [31:0] calc_row, calc_col, calc_depth;
    logic [31:0] acc_row [0:1], acc_col [0:1];
    logic [31:0] acc_cols [0:1], acc_scores [0:1];
    logic [31:0] score_count [0:1];
    logic [31:0] scale_launch_index, scale_result_count, send_index;
    logic [31:0] tile_start;

    logic [31:0] calc_rows_here, calc_cols_here;
    logic calc_start;
    assign calc_rows_here = (calc_row + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - calc_row;
    assign calc_cols_here = (calc_col + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - calc_col;
    assign calc_start = command_active && !calc_busy &&
        !acc_valid[calc_acc_bank] && q_valid[calc_q_bank] &&
        (K_REUSE_EN || k_valid[calc_k_bank]);

    function automatic signed [4:0] decode(input logic [3:0] code);
        logic signed [4:0] magnitude;
        case (code[2:0])
            3'd0: magnitude = 5'sd0;
            3'd1: magnitude = 5'sd1;
            3'd2: magnitude = 5'sd2;
            3'd3: magnitude = 5'sd3;
            3'd4: magnitude = 5'sd4;
            3'd5: magnitude = 5'sd6;
            3'd6: magnitude = 5'sd8;
            default: magnitude = 5'sd12;
        endcase
        decode = code[3] ? -magnitude : magnitude;
    endfunction

    localparam int SCALER_LANES = BLOCK_COUNT*SCORE_LANES;
    logic scale_start, scale_launch;
    logic [31:0] scale_effective_index;
    logic [31:0] scale_launch_count, reduced_count;
    logic [SCALER_LANES-1:0] scaler_launch_valid, scaler_result_valid;
    logic signed [SCALER_LANES-1:0][ACC_W-1:0] scaler_acc;
    logic [SCALER_LANES-1:0][31:0] scaler_q_scale, scaler_k_scale, scaler_result;
    logic [SCALER_LANES-1:0][INDEX_W-1:0] scaler_index_in, scaler_result_index;
    logic [SCORE_LANES-1:0] reduced_valid;
    logic [SCORE_LANES-1:0][31:0] reduced_result;
    logic [SCORE_LANES-1:0][INDEX_W-1:0] reduced_index;
    assign scale_start = command_active && !scale_busy &&
        acc_valid[scale_acc_bank] && !score_valid[scale_score_bank];
    assign scale_effective_index = scale_start ? 0 : scale_launch_index;
    assign scale_launch = command_active && (scale_start ||
        (scale_busy && scale_launch_index < acc_scores[scale_acc_bank]));
    assign scale_launch_count = !scale_launch ? 0 :
        ((scale_effective_index+SCORE_LANES <= acc_scores[scale_acc_bank]) ?
         SCORE_LANES : acc_scores[scale_acc_bank]-scale_effective_index);
    always_comb begin
        reduced_count = 0;
        for (int lane = 0; lane < SCORE_LANES; lane++)
            reduced_count = reduced_count + 32'(reduced_valid[lane]);
    end
    for (genvar score_lane = 0; score_lane < SCORE_LANES; score_lane++) begin : g_score_lane
        localparam int LANE_BASE = score_lane*BLOCK_COUNT;
        logic [31:0] lane_index, lane_row, lane_col;
        assign lane_index = scale_effective_index + score_lane;
        assign lane_row = lane_index / acc_cols[scale_acc_bank];
        assign lane_col = lane_index % acc_cols[scale_acc_bank];
        for (genvar block = 0; block < BLOCK_COUNT; block++) begin : g_scale_block
            localparam int FLAT_LANE = LANE_BASE+block;
            assign scaler_launch_valid[FLAT_LANE] =
                scale_launch && score_lane < scale_launch_count;
            assign scaler_acc[FLAT_LANE] =
                acc_bank[scale_acc_bank][block][lane_row][lane_col];
            assign scaler_q_scale[FLAT_LANE] =
                sq[acc_row[scale_acc_bank]+lane_row][block];
            assign scaler_k_scale[FLAT_LANE] =
                sk[acc_col[scale_acc_bank]+lane_col][block];
            assign scaler_index_in[FLAT_LANE] = INDEX_W'(lane_index);
        end
        score_reducer #(.BLOCK_COUNT(BLOCK_COUNT), .INDEX_W(INDEX_W)) u_reducer (
            .clk, .rst_n,
            .block_valid(scaler_result_valid[LANE_BASE +: BLOCK_COUNT]),
            .block_result(scaler_result[LANE_BASE +: BLOCK_COUNT]),
            .block_index(scaler_result_index[LANE_BASE +: BLOCK_COUNT]),
            .result_valid(reduced_valid[score_lane]),
            .result(reduced_result[score_lane]),
            .result_index(reduced_index[score_lane])
        );
    end
    score_scaler #(.ACC_W(ACC_W), .INDEX_W(INDEX_W),
                   .LANES(SCALER_LANES)) u_scaler (
        .clk, .rst_n, .launch_valid(scaler_launch_valid),
        .acc_in(scaler_acc), .q_scale_in(scaler_q_scale),
        .k_scale_in(scaler_k_scale), .index_in(scaler_index_in),
        .result_valid(scaler_result_valid), .result(scaler_result),
        .result_index(scaler_result_index)
    );

    always_comb begin
        s_tready = 1'b0;
        if (command_active) begin
            case (frontend)
                FE_SCALES, FE_CACHE_K: s_tready = 1'b1;
                FE_LOAD_Q: s_tready = !q_valid[load_q_bank];
                FE_LOAD_K: s_tready = !k_valid[load_k_bank];
                default: s_tready = 1'b0;
            endcase
        end
    end

    assign m_tvalid = command_active && score_valid[output_score_bank];
    assign m_tdata = m_tvalid ?
        {((send_index+1 < score_count[output_score_bank]) ?
          score_bank[output_score_bank][send_index+1] : 32'h0),
         score_bank[output_score_bank][send_index]} : 64'h0;
    assign m_tlast = m_tvalid && send_index+2 >= score_count[output_score_bank];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            frontend <= FE_IDLE;
            command_active <= 1'b0;
            done <= 1'b0;
            error_code <= 0;
            tile_count <= 0; cycle_count <= 0; tile_cycles <= 0;
            input_beats <= 0; output_beats <= 0;
            input_stalls <= 0; output_stalls <= 0;
            compute_cycles <= 0; scale_cycles <= 0;
            q_valid <= 0; k_valid <= 0; acc_valid <= 0; score_valid <= 0;
            load_q_bank <= 0; load_k_bank <= 0;
            calc_q_bank <= 0; calc_k_bank <= 0; calc_acc_bank <= 0;
            scale_acc_bank <= 0; scale_score_bank <= 0; output_score_bank <= 0;
            calc_busy <= 0; scale_busy <= 0;
            load_beat <= 0; cache_tile <= 0; input_row <= 0; input_col <= 0;
            calc_row <= 0; calc_col <= 0; calc_depth <= 0;
            scale_launch_index <= 0; scale_result_count <= 0; send_index <= 0;
            tile_start <= 0;
            for (int bank = 0; bank < 2; bank++) begin
                acc_row[bank] <= 0; acc_col[bank] <= 0;
                acc_cols[bank] <= 0; acc_scores[bank] <= 0;
                score_count[bank] <= 0;
            end
        end else begin
            if (command_active) cycle_count <= cycle_count + 1;
            if (s_tready && !s_tvalid) input_stalls <= input_stalls + 1;
            if (m_tvalid && !m_tready) output_stalls <= output_stalls + 1;
            if (calc_busy || calc_start) compute_cycles <= compute_cycles + 1;
            if (scale_busy || scale_start) scale_cycles <= scale_cycles + 1;
            if (s_tvalid && s_tready) input_beats <= input_beats + 1;
            if (m_tvalid && m_tready) output_beats <= output_beats + 1;

            if (start) begin
                done <= 1'b0; error_code <= 0; command_active <= 1'b0;
                tile_count <= 0; cycle_count <= 0; tile_cycles <= 0;
                input_beats <= 0; output_beats <= 0;
                input_stalls <= 0; output_stalls <= 0;
                compute_cycles <= 0; scale_cycles <= 0;
                q_valid <= 0; k_valid <= 0; acc_valid <= 0; score_valid <= 0;
                load_q_bank <= 0; load_k_bank <= 0;
                calc_q_bank <= 0; calc_k_bank <= 0; calc_acc_bank <= 0;
                scale_acc_bank <= 0; scale_score_bank <= 0; output_score_bank <= 0;
                calc_busy <= 0; scale_busy <= 0;
                load_beat <= 0; cache_tile <= 0; input_row <= 0; input_col <= 0;
                calc_row <= 0; calc_col <= 0; calc_depth <= 0;
                scale_launch_index <= 0; scale_result_count <= 0; send_index <= 0;
                tile_start <= 0;
                if (matrix_size == 0 || matrix_size > T_MAX) begin
                    error_code <= 4'h1; done <= 1'b1; frontend <= FE_DONE;
                end else begin
                    command_active <= 1'b1; frontend <= FE_SCALES;
                end
            end else if (command_active) begin
                // Input sequencer: scales, optional K cache, then Q/K tile stream.
                if (s_tvalid && s_tready) begin
                    case (frontend)
                        FE_SCALES: begin
                            for (int lane = 0; lane < 2; lane++) begin
                                if (load_beat*2+lane < matrix_size*BLOCK_COUNT)
                                    sq[(load_beat*2+lane)/BLOCK_COUNT]
                                      [(load_beat*2+lane)%BLOCK_COUNT] <=
                                        s_tdata[32*lane +: 32];
                                else if (load_beat*2+lane < 2*matrix_size*BLOCK_COUNT)
                                    sk[(load_beat*2+lane-matrix_size*BLOCK_COUNT)/BLOCK_COUNT]
                                      [(load_beat*2+lane-matrix_size*BLOCK_COUNT)%BLOCK_COUNT] <=
                                        s_tdata[32*lane +: 32];
                            end
                            if (load_beat+1 == matrix_size*BLOCK_COUNT) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    frontend <= K_REUSE_EN ? FE_CACHE_K : FE_LOAD_Q;
                                    load_beat <= 0;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1;
                        end
                        FE_CACHE_K: begin
                            for (int lane = 0; lane < 16; lane++)
                                if (load_beat*16+lane < TILE_SIZE*D_HEAD &&
                                    cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD < T_MAX)
                                    k_cache[cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD]
                                           [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                            if (load_beat+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else if ((cache_tile+1)*TILE_SIZE >= matrix_size) begin
                                    frontend <= FE_LOAD_Q; load_beat <= 0; cache_tile <= 0;
                                end else begin
                                    cache_tile <= cache_tile + 1; load_beat <= 0;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1;
                        end
                        FE_LOAD_Q: begin
                            for (int lane = 0; lane < 16; lane++)
                                if (load_beat*16+lane < TILE_SIZE*D_HEAD)
                                    q_bank[load_q_bank][(load_beat*16+lane)/D_HEAD]
                                          [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                            if (load_beat+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    q_valid[load_q_bank] <= 1'b1;
                                    load_beat <= 0; input_col <= 0;
                                    if (K_REUSE_EN) begin
                                        if (input_row+TILE_SIZE >= matrix_size) begin
                                            frontend <= FE_DONE;
                                        end else begin
                                            input_row <= input_row + TILE_SIZE;
                                            load_q_bank <= ~load_q_bank;
                                        end
                                    end else frontend <= FE_LOAD_K;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1;
                        end
                        FE_LOAD_K: begin
                            for (int lane = 0; lane < 16; lane++)
                                if (load_beat*16+lane < TILE_SIZE*D_HEAD)
                                    k_bank[load_k_bank][(load_beat*16+lane)/D_HEAD]
                                          [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                            if (load_beat+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    k_valid[load_k_bank] <= 1'b1;
                                    load_k_bank <= ~load_k_bank; load_beat <= 0;
                                    if (input_col+TILE_SIZE < matrix_size)
                                        input_col <= input_col + TILE_SIZE;
                                    else if (input_row+TILE_SIZE < matrix_size) begin
                                        input_row <= input_row + TILE_SIZE;
                                        load_q_bank <= ~load_q_bank;
                                        frontend <= FE_LOAD_Q;
                                    end else begin
                                        frontend <= FE_DONE;
                                    end
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1;
                        end
                        default: ;
                    endcase
                end

                // Compute sequencer consumes tiles in command order.
                if (calc_start) begin
                    calc_busy <= 1'b1; calc_depth <= 1;
                    for (int block = 0; block < BLOCK_COUNT; block++)
                        for (int i = 0; i < TILE_SIZE; i++)
                            for (int j = 0; j < TILE_SIZE; j++)
                                acc_bank[calc_acc_bank][block][i][j] <= '0;
                    /* verilator lint_off BLKLOOPINIT */
                    for (int i = 0; i < TILE_SIZE; i++)
                        for (int j = 0; j < TILE_SIZE; j++)
                            acc_bank[calc_acc_bank][0][i][j] <=
                                ACC_W'(decode(q_bank[calc_q_bank][i][0]) *
                                decode(K_REUSE_EN ? k_cache[calc_col+j][0] :
                                       k_bank[calc_k_bank][j][0]));
                    /* verilator lint_on BLKLOOPINIT */
                end else if (calc_busy) begin
                    /* verilator lint_off BLKLOOPINIT */
                    for (int i = 0; i < TILE_SIZE; i++)
                        for (int j = 0; j < TILE_SIZE; j++)
                            acc_bank[calc_acc_bank][calc_depth/SCALE_BLOCK_SIZE][i][j] <=
                                acc_bank[calc_acc_bank]
                                        [calc_depth/SCALE_BLOCK_SIZE][i][j] +
                                ACC_W'(decode(q_bank[calc_q_bank][i][calc_depth]) *
                                decode(K_REUSE_EN ? k_cache[calc_col+j][calc_depth] :
                                       k_bank[calc_k_bank][j][calc_depth]));
                    /* verilator lint_on BLKLOOPINIT */
                    if (calc_depth == D_HEAD-1) begin
                        calc_busy <= 1'b0; acc_valid[calc_acc_bank] <= 1'b1;
                        acc_row[calc_acc_bank] <= calc_row;
                        acc_col[calc_acc_bank] <= calc_col;
                        acc_cols[calc_acc_bank] <= calc_cols_here;
                        acc_scores[calc_acc_bank] <= calc_rows_here * calc_cols_here;
                        calc_acc_bank <= ~calc_acc_bank;
                        if (!K_REUSE_EN) begin
                            k_valid[calc_k_bank] <= 1'b0;
                            calc_k_bank <= ~calc_k_bank;
                        end
                        if (calc_col+TILE_SIZE < matrix_size)
                            calc_col <= calc_col + TILE_SIZE;
                        else begin
                            q_valid[calc_q_bank] <= 1'b0;
                            calc_q_bank <= ~calc_q_bank; calc_col <= 0;
                            calc_row <= calc_row + TILE_SIZE;
                        end
                    end else calc_depth <= calc_depth + 1;
                end

                // Scaling sequencer drains completed accumulator banks in order.
                if (scale_start) begin
                    scale_busy <= 1'b1;
                    scale_launch_index <= scale_launch_count;
                    scale_result_count <= 0;
                end else if (scale_busy) begin
                    if (scale_launch)
                        scale_launch_index <= scale_launch_index + scale_launch_count;
                    for (int lane = 0; lane < SCORE_LANES; lane++)
                        if (reduced_valid[lane])
                            score_bank[scale_score_bank][reduced_index[lane]] <=
                                reduced_result[lane];
                    if (reduced_count != 0) begin
                        scale_result_count <= scale_result_count + reduced_count;
                        if (scale_result_count+reduced_count == acc_scores[scale_acc_bank]) begin
                            scale_busy <= 1'b0;
                            score_valid[scale_score_bank] <= 1'b1;
                            score_count[scale_score_bank] <= acc_scores[scale_acc_bank];
                            acc_valid[scale_acc_bank] <= 1'b0;
                            scale_acc_bank <= ~scale_acc_bank;
                            scale_score_bank <= ~scale_score_bank;
                        end
                    end
                end

                // Output sequencer preserves tile order and stable stalled data.
                if (m_tvalid && m_tready) begin
                    if (send_index+2 >= score_count[output_score_bank]) begin
                        score_valid[output_score_bank] <= 1'b0;
                        output_score_bank <= ~output_score_bank; send_index <= 0;
                        tile_count <= tile_count + 1;
                        tile_cycles <= cycle_count - tile_start + 1;
                        tile_start <= cycle_count;
                        if (tile_count+1 == ((matrix_size+TILE_SIZE-1)/TILE_SIZE) *
                                             ((matrix_size+TILE_SIZE-1)/TILE_SIZE)) begin
                            done <= 1'b1; command_active <= 1'b0;
                        end
                    end else send_index <= send_index + 2;
                end
            end
        end
    end
endmodule
