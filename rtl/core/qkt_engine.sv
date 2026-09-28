// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// One private QK^T compute engine: K tile storage, exact integer accumulators,
// score scaling, and one score bank pair. Engine ENGINE_ID of ENGINES owns the
// output tile columns congruent to ENGINE_ID modulo ENGINES, so every engine
// works on the same Q tile row. See docs/architecture.md.
module qkt_engine #(
    parameter int TILE_SIZE = 4,
    parameter int D_HEAD = 64,
    parameter int K_REUSE = 0,
    parameter int SCALE_BLOCK_SIZE = 16,
    parameter int SCORE_LANES = 1,
    parameter int ENGINES = 1,
    parameter int ENGINE_ID = 0
)(
    input logic clk, rst_n,
    input logic command_active, flush,
    input logic [31:0] matrix_size,

    // Shared Q tile banks.
    input logic [1:0] q_valid_in,
    input logic q_wr_valid, q_wr_bank,
    input logic [31:0] q_wr_beat,
    input logic [63:0] q_wr_data,
    output logic q_rd_bank,
    output logic [31:0] q_rd_depth,
    input logic [TILE_SIZE*4-1:0] q_rd_data,
    output logic [1:0] q_release,

    // K reload write port, driven by the shared input dispatcher.
    output logic k_ready,
    input logic k_wr_valid, k_wr_last,
    input logic [31:0] k_wr_beat,
    input logic [63:0] k_wr_data,

    // K reuse burst-fill read port into the shared K cache.
    input logic k_cache_ready,
    output logic [31:0] kc_col, kc_beat,
    input logic [TILE_SIZE*((16/TILE_SIZE > 0) ? 16/TILE_SIZE : 1)*4-1:0] kc_data,

    // Shared block-scale storage.
    output logic [SCORE_LANES*32-1:0] sq_index, sk_index,
    input logic [SCORE_LANES*((D_HEAD+SCALE_BLOCK_SIZE-1)/SCALE_BLOCK_SIZE)*32-1:0]
        sq_data, sk_data,

    // Ordered retirement port.
    output logic score_ready,
    output logic [31:0] score_count_out,
    input logic [31:0] rd_index,
    output logic [63:0] rd_data,
    input logic tile_retire,

    output logic calc_active, scale_active
);
    localparam bit K_REUSE_EN = K_REUSE != 0;
    localparam int BLOCK_COUNT = (D_HEAD+SCALE_BLOCK_SIZE-1)/SCALE_BLOCK_SIZE;
    localparam int ACC_DEPTH = (SCALE_BLOCK_SIZE < D_HEAD) ? SCALE_BLOCK_SIZE : D_HEAD;
    localparam int ACC_W = $clog2(144*ACC_DEPTH+1)+1;
    localparam int INDEX_W = $clog2(TILE_SIZE*TILE_SIZE);
    localparam int TILE_INDEX_W = (TILE_SIZE <= 1) ? 1 : $clog2(TILE_SIZE);
    localparam int TILE_COUNT_W = $clog2(TILE_SIZE+1);
    localparam int SCALER_LANES = BLOCK_COUNT*SCORE_LANES;
    localparam int FILL_DEPTHS = (16/TILE_SIZE > 0) ? 16/TILE_SIZE : 1;
    localparam int FILL_BEATS = (D_HEAD+FILL_DEPTHS-1)/FILL_DEPTHS;
    localparam int COL_STRIDE = ENGINES*TILE_SIZE;
    localparam int COL_BASE = ENGINE_ID*TILE_SIZE;

    logic [3:0] k_bank [0:1][0:TILE_SIZE-1][0:D_HEAD-1];
    logic signed [ACC_W-1:0] acc_bank
        [0:1][0:BLOCK_COUNT-1][0:TILE_SIZE-1][0:TILE_SIZE-1];
    logic [31:0] score_bank [0:1][0:TILE_SIZE*TILE_SIZE-1];

    logic [1:0] k_valid, acc_valid, score_valid;
    logic load_k_bank, calc_q_bank, calc_k_bank;
    logic calc_acc_bank, scale_acc_bank, scale_score_bank, output_score_bank;
    logic calc_busy, scale_busy, fill_busy;
    // calc_depth never exceeds D_HEAD, so it is only as wide as that needs.
    localparam int DEPTH_W = $clog2(D_HEAD+1);
    localparam int DEPTH_INDEX_W = (D_HEAD <= 1) ? 1 : $clog2(D_HEAD);
    logic [31:0] calc_row, calc_col;
    logic [DEPTH_W-1:0] calc_depth;
    logic [31:0] fill_row, fill_col, fill_beat;
    logic [31:0] acc_row [0:1], acc_col [0:1];
    logic [TILE_COUNT_W-1:0] acc_cols [0:1];
    logic [31:0] acc_scores [0:1];
    logic [31:0] score_count [0:1];
    logic [31:0] scale_launch_index, scale_result_count;

    logic calc_start, row_skip, fill_start;
    // Tile-position tests against matrix_size are registered alongside
    // calc_row and calc_col, from their next values, so no 32-bit compare sits
    // in front of calc_start's fanout. matrix_size is fixed for a command.
    logic calc_row_in, calc_col_in, calc_col_more;
    // The valid rows and columns of the current tile are registered the same
    // way, so the score count is a TILE_SIZE-wide multiply of two registers.
    logic [TILE_COUNT_W-1:0] calc_rows_q, calc_cols_q;
    function automatic logic [TILE_COUNT_W-1:0] tile_extent(
        input logic [31:0] start, input logic [31:0] size
    );
        tile_extent = (start + TILE_SIZE <= size) ?
            TILE_COUNT_W'(TILE_SIZE) : TILE_COUNT_W'(size - start);
    endfunction
    assign calc_start = command_active && !calc_busy && calc_row_in &&
        calc_col_in && !acc_valid[calc_acc_bank] &&
        q_valid_in[calc_q_bank] && k_valid[calc_k_bank];
    // The burst fill writes its first beat in the cycle it starts, so a
    // K-reuse tile becomes ready on the same cycle a reloaded tile would.
    assign fill_start = K_REUSE_EN && command_active && !fill_busy &&
        k_cache_ready && !k_valid[load_k_bank] &&
        fill_row < matrix_size && fill_col < matrix_size;
    // An engine with no tile in this Q row still hands its Q bank back.
    assign row_skip = command_active && !calc_busy && calc_row_in &&
        !calc_col_in && q_valid_in[calc_q_bank];

    // The shared Q banks are read one cycle ahead into a private register, so
    // the engine-crossing array read is register to register and never shares a
    // path with decode, multiply, and accumulate.
    logic [TILE_SIZE*4-1:0] q_row;
    logic q_row_last, q_row_next_bank;
    assign q_row_last = calc_busy && calc_depth == DEPTH_W'(D_HEAD-1);
    assign q_row_next_bank = q_row_last && !calc_col_more;
    assign q_rd_bank = (q_row_next_bank || row_skip) ? ~calc_q_bank : calc_q_bank;
    // While busy, calc_depth is 1 through D_HEAD-1, so "calc_depth+1 < D_HEAD"
    // is exactly "not the last depth".
    assign q_rd_depth = (calc_start && D_HEAD > 1) ? 32'd1 :
        (calc_busy && !q_row_last) ? 32'(calc_depth + 1'b1) : 32'd0;
    assign k_ready = command_active && !k_valid[load_k_bank];
    assign kc_col = fill_col;
    assign kc_beat = fill_start ? 32'd0 : fill_beat;
    assign calc_active = calc_busy || calc_start;

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

    logic scale_start, scale_launch;
    logic [31:0] scale_effective_index;
    logic [TILE_INDEX_W-1:0] scale_launch_row, scale_launch_col;
    logic [TILE_INDEX_W-1:0] scale_effective_row, scale_effective_col;
    logic [TILE_INDEX_W-1:0] scale_next_row, scale_next_col;
    logic [31:0] scale_launch_count, reduced_count;
    logic [SCALER_LANES-1:0] scaler_prefetch_valid;
    logic [SCALER_LANES-1:0] scaler_launch_valid, scaler_result_valid;
    logic [SCALER_LANES*32-1:0] scaler_prefetch_q_scale;
    logic [SCALER_LANES*32-1:0] scaler_prefetch_k_scale;
    logic [SCALER_LANES*INDEX_W-1:0] scaler_prefetch_index;
    // The accumulator is read in the prefetch cycle and registered with the
    // scales, so the first multiplier stage starts from a register rather than
    // from the accumulator read mux.
    logic signed [SCALER_LANES*ACC_W-1:0] scaler_prefetch_acc, scaler_acc;
    logic [SCALER_LANES*32-1:0] scaler_q_scale, scaler_k_scale, scaler_result;
    logic [SCALER_LANES*INDEX_W-1:0] scaler_index_in, scaler_result_index;
    logic [SCORE_LANES-1:0] reduced_valid;
    logic [SCORE_LANES*32-1:0] reduced_result;
    logic [SCORE_LANES*INDEX_W-1:0] reduced_index;
    assign scale_start = command_active && !scale_busy &&
        acc_valid[scale_acc_bank] && !score_valid[scale_score_bank];
    assign scale_active = scale_busy || scale_start;
    assign scale_effective_index = scale_start ? 0 : scale_launch_index;
    assign scale_effective_row = scale_start ? '0 : scale_launch_row;
    assign scale_effective_col = scale_start ? '0 : scale_launch_col;
    assign scale_launch = command_active && (scale_start ||
        (scale_busy && scale_launch_index < acc_scores[scale_acc_bank]));
    assign scale_launch_count = !scale_launch ? 0 :
        ((scale_effective_index+SCORE_LANES <= acc_scores[scale_acc_bank]) ?
         SCORE_LANES : acc_scores[scale_acc_bank]-scale_effective_index);
    always_comb begin
        scale_next_row = scale_effective_row;
        scale_next_col = scale_effective_col;
        for (int advance = 0; advance < SCORE_LANES; advance++) begin
            if (advance < scale_launch_count) begin
                if (TILE_COUNT_W'(scale_next_col)+1 >= acc_cols[scale_acc_bank]) begin
                    scale_next_col = '0;
                    scale_next_row = scale_next_row + 1'b1;
                end else scale_next_col = scale_next_col + 1'b1;
            end
        end
    end
    always_comb begin
        reduced_count = 0;
        for (int lane = 0; lane < SCORE_LANES; lane++)
            reduced_count = reduced_count + 32'(reduced_valid[lane]);
    end
    for (genvar score_lane = 0; score_lane < SCORE_LANES; score_lane++) begin : g_score_lane
        localparam int LANE_BASE = score_lane*BLOCK_COUNT;
        logic [INDEX_W-1:0] lane_index;
        logic [TILE_INDEX_W-1:0] lane_row, lane_col;
        assign lane_index = INDEX_W'(scale_effective_index) + INDEX_W'(score_lane);
        always_comb begin
            lane_row = scale_effective_row;
            lane_col = scale_effective_col;
            for (int advance = 0; advance < score_lane; advance++) begin
                if (TILE_COUNT_W'(lane_col)+1 >= acc_cols[scale_acc_bank]) begin
                    lane_col = '0;
                    lane_row = lane_row + 1'b1;
                end else lane_col = lane_col + 1'b1;
            end
        end
        assign sq_index[score_lane*32 +: 32] =
            acc_row[scale_acc_bank] + 32'(lane_row);
        assign sk_index[score_lane*32 +: 32] =
            acc_col[scale_acc_bank] + 32'(lane_col);
        for (genvar block = 0; block < BLOCK_COUNT; block++) begin : g_scale_block
            localparam int FLAT_LANE = LANE_BASE+block;
            assign scaler_prefetch_valid[FLAT_LANE] =
                scale_launch && score_lane < scale_launch_count;
            assign scaler_prefetch_acc[FLAT_LANE*ACC_W +: ACC_W] =
                acc_bank[scale_acc_bank][block][lane_row][lane_col];
            assign scaler_prefetch_q_scale[FLAT_LANE*32 +: 32] =
                sq_data[FLAT_LANE*32 +: 32];
            assign scaler_prefetch_k_scale[FLAT_LANE*32 +: 32] =
                sk_data[FLAT_LANE*32 +: 32];
            assign scaler_prefetch_index[FLAT_LANE*INDEX_W +: INDEX_W] =
                lane_index;
        end
        score_reducer #(.BLOCK_COUNT(BLOCK_COUNT), .INDEX_W(INDEX_W)) u_reducer (
            .clk, .rst_n,
            .block_valid(scaler_result_valid[LANE_BASE +: BLOCK_COUNT]),
            .block_result(scaler_result[LANE_BASE*32 +: BLOCK_COUNT*32]),
            .block_index(scaler_result_index[
                LANE_BASE*INDEX_W +: BLOCK_COUNT*INDEX_W]),
            .result_valid(reduced_valid[score_lane]),
            .result(reduced_result[score_lane*32 +: 32]),
            .result_index(reduced_index[score_lane*INDEX_W +: INDEX_W])
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

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            scaler_launch_valid <= '0;
            scaler_q_scale <= '0;
            scaler_k_scale <= '0;
            scaler_index_in <= '0;
            scaler_acc <= '0;
        end else begin
            scaler_launch_valid <= scaler_prefetch_valid;
            scaler_q_scale <= scaler_prefetch_q_scale;
            scaler_k_scale <= scaler_prefetch_k_scale;
            scaler_index_in <= scaler_prefetch_index;
            scaler_acc <= scaler_prefetch_acc;
        end
    end

    assign score_ready = score_valid[output_score_bank];
    assign score_count_out = score_count[output_score_bank];
    assign rd_data = score_ready ?
        {((rd_index+1 < score_count[output_score_bank]) ?
          score_bank[output_score_bank][rd_index+1] : 32'h0),
         score_bank[output_score_bank][rd_index]} : 64'h0;

    // Depth 0 of a row can be written in the same cycle q_valid is set, which a
    // plain array read would miss, so that one nibble per row is snooped off the
    // write beat instead. Both the beat and the lane are compile-time constants.
    always_ff @(posedge clk) begin
        if (!rst_n) q_row <= '0;
        else begin
            for (int row = 0; row < TILE_SIZE; row++) begin
                if (q_rd_depth == 0 && q_wr_valid && q_wr_bank == q_rd_bank &&
                    q_wr_beat == (row*D_HEAD)/16)
                    q_row[4*row +: 4] <= q_wr_data[4*((row*D_HEAD)%16) +: 4];
                else
                    q_row[4*row +: 4] <= q_rd_data[4*row +: 4];
            end
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_n || flush) begin
            k_valid <= 0; acc_valid <= 0; score_valid <= 0;
            load_k_bank <= 0; calc_q_bank <= 0; calc_k_bank <= 0;
            calc_acc_bank <= 0; scale_acc_bank <= 0;
            scale_score_bank <= 0; output_score_bank <= 0;
            calc_busy <= 0; scale_busy <= 0; fill_busy <= 0;
            calc_row <= 0; calc_col <= COL_BASE; calc_depth <= 0;
            calc_row_in <= matrix_size != 0;
            calc_col_in <= COL_BASE < matrix_size;
            calc_col_more <= COL_BASE+COL_STRIDE < matrix_size;
            calc_rows_q <= tile_extent(0, matrix_size);
            calc_cols_q <= tile_extent(COL_BASE, matrix_size);
            fill_row <= 0; fill_col <= COL_BASE; fill_beat <= 0;
            scale_launch_index <= 0; scale_result_count <= 0;
            scale_launch_row <= 0; scale_launch_col <= 0;
            q_release <= 0;
            for (int bank = 0; bank < 2; bank++) begin
                acc_row[bank] <= 0; acc_col[bank] <= 0;
                acc_cols[bank] <= 0; acc_scores[bank] <= 0;
                score_count[bank] <= 0;
            end
        end else begin
            q_release <= 2'b00;
            if (command_active) begin
                // K reload: the shared dispatcher writes this engine's tile.
                if (!K_REUSE_EN && k_wr_valid) begin
                    for (int lane = 0; lane < 16; lane++)
                        if (k_wr_beat*16+lane < TILE_SIZE*D_HEAD)
                            k_bank[load_k_bank][(k_wr_beat*16+lane)/D_HEAD]
                                  [(k_wr_beat*16+lane)%D_HEAD] <=
                                      k_wr_data[4*lane +: 4];
                    if (k_wr_last) begin
                        k_valid[load_k_bank] <= 1'b1;
                        load_k_bank <= ~load_k_bank;
                    end
                end

                // K reuse: burst-fill the private tile from the shared cache.
                if (fill_start || fill_busy) begin
                    // kc_beat is the fill beat in progress, including beat 0 on
                    // the cycle the fill starts.
                    for (int j = 0; j < TILE_SIZE; j++)
                        for (int d = 0; d < FILL_DEPTHS; d++)
                            if (kc_beat*FILL_DEPTHS+d < D_HEAD)
                                k_bank[load_k_bank][j][kc_beat*FILL_DEPTHS+d] <=
                                    kc_data[(j*FILL_DEPTHS+d)*4 +: 4];
                    if (kc_beat+1 == FILL_BEATS) begin
                        fill_busy <= 1'b0; fill_beat <= 0;
                        k_valid[load_k_bank] <= 1'b1;
                        load_k_bank <= ~load_k_bank;
                        if (fill_col+COL_STRIDE < matrix_size)
                            fill_col <= fill_col + COL_STRIDE;
                        else begin
                            fill_col <= COL_BASE;
                            fill_row <= fill_row + TILE_SIZE;
                        end
                    end else begin
                        fill_busy <= 1'b1; fill_beat <= kc_beat + 1;
                    end
                end

                // Compute sequencer walks this engine's tile columns in order.
                if (row_skip) begin
                    q_release[calc_q_bank] <= 1'b1;
                    calc_q_bank <= ~calc_q_bank;
                    calc_row <= calc_row + TILE_SIZE;
                    calc_row_in <= calc_row + TILE_SIZE < matrix_size;
                    calc_rows_q <= tile_extent(calc_row + TILE_SIZE, matrix_size);
                end else if (calc_start) begin
                    calc_busy <= 1'b1; calc_depth <= 1;
                    for (int block = 0; block < BLOCK_COUNT; block++)
                        for (int i = 0; i < TILE_SIZE; i++)
                            for (int j = 0; j < TILE_SIZE; j++)
                                acc_bank[calc_acc_bank][block][i][j] <= '0;
                    /* verilator lint_off BLKLOOPINIT */
                    for (int i = 0; i < TILE_SIZE; i++)
                        for (int j = 0; j < TILE_SIZE; j++)
                            acc_bank[calc_acc_bank][0][i][j] <=
                                ACC_W'(decode(q_row[4*i +: 4]) *
                                       decode(k_bank[calc_k_bank][j][0]));
                    /* verilator lint_on BLKLOOPINIT */
                end else if (calc_busy) begin
                    /* verilator lint_off BLKLOOPINIT */
                    for (int i = 0; i < TILE_SIZE; i++)
                        for (int j = 0; j < TILE_SIZE; j++)
                            acc_bank[calc_acc_bank][32'(calc_depth)/SCALE_BLOCK_SIZE][i][j] <=
                                acc_bank[calc_acc_bank]
                                        [32'(calc_depth)/SCALE_BLOCK_SIZE][i][j] +
                                ACC_W'(decode(q_row[4*i +: 4]) *
                                       decode(k_bank[calc_k_bank][j]
                                           [calc_depth[DEPTH_INDEX_W-1:0]]));
                    /* verilator lint_on BLKLOOPINIT */
                    if (q_row_last) begin
                        calc_busy <= 1'b0; acc_valid[calc_acc_bank] <= 1'b1;
                        acc_row[calc_acc_bank] <= calc_row;
                        acc_col[calc_acc_bank] <= calc_col;
                        acc_cols[calc_acc_bank] <= calc_cols_q;
                        acc_scores[calc_acc_bank] <= 32'(calc_rows_q * calc_cols_q);
                        calc_acc_bank <= ~calc_acc_bank;
                        k_valid[calc_k_bank] <= 1'b0;
                        calc_k_bank <= ~calc_k_bank;
                        if (calc_col_more) begin
                            calc_col <= calc_col + COL_STRIDE;
                            calc_col_more <= calc_col + 2*COL_STRIDE < matrix_size;
                            calc_cols_q <= tile_extent(calc_col + COL_STRIDE, matrix_size);
                        end else begin
                            q_release[calc_q_bank] <= 1'b1;
                            calc_q_bank <= ~calc_q_bank; calc_col <= COL_BASE;
                            calc_row <= calc_row + TILE_SIZE;
                            calc_row_in <= calc_row + TILE_SIZE < matrix_size;
                            calc_col_in <= COL_BASE < matrix_size;
                            calc_col_more <= COL_BASE+COL_STRIDE < matrix_size;
                            calc_rows_q <= tile_extent(calc_row + TILE_SIZE, matrix_size);
                            calc_cols_q <= tile_extent(COL_BASE, matrix_size);
                        end
                    end else calc_depth <= calc_depth + 1'b1;
                end

                // Scaling sequencer drains completed accumulator banks in order.
                if (scale_start) begin
                    scale_busy <= 1'b1;
                    scale_launch_index <= scale_launch_count;
                    scale_launch_row <= scale_next_row;
                    scale_launch_col <= scale_next_col;
                    scale_result_count <= 0;
                end else if (scale_busy) begin
                    if (scale_launch) begin
                        scale_launch_index <= scale_launch_index + scale_launch_count;
                        scale_launch_row <= scale_next_row;
                        scale_launch_col <= scale_next_col;
                    end
                    for (int lane = 0; lane < SCORE_LANES; lane++)
                        if (reduced_valid[lane])
                            score_bank[scale_score_bank]
                                [reduced_index[lane*INDEX_W +: INDEX_W]] <=
                                reduced_result[lane*32 +: 32];
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

                // Ordered retirement releases one score bank per completed tile.
                if (tile_retire) begin
                    score_valid[output_score_bank] <= 1'b0;
                    output_score_bank <= ~output_score_bank;
                end
            end
        end
    end

`ifndef SYNTHESIS
    // The combinational tile extents the registered copies must equal.
    logic [31:0] calc_rows_here, calc_cols_here;
    assign calc_rows_here = (calc_row + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - calc_row;
    assign calc_cols_here = (calc_col + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - calc_col;

    property p_k_bank_ownership;
        @(posedge clk) disable iff (!rst_n)
        calc_busy && k_wr_valid |-> load_k_bank != calc_k_bank;
    endproperty
    assert property (p_k_bank_ownership);

    property p_fill_bank_ownership;
        @(posedge clk) disable iff (!rst_n)
        calc_busy && (fill_busy || fill_start) |-> load_k_bank != calc_k_bank;
    endproperty
    assert property (p_fill_bank_ownership);

    property p_acc_bank_ownership;
        @(posedge clk) disable iff (!rst_n)
        calc_busy && scale_busy |-> calc_acc_bank != scale_acc_bank;
    endproperty
    assert property (p_acc_bank_ownership);

    property p_score_bank_ownership;
        @(posedge clk) disable iff (!rst_n)
        scale_busy && score_ready |-> scale_score_bank != output_score_bank;
    endproperty
    assert property (p_score_bank_ownership);

    // The registered tile-position flags must equal the compares they replace.
    property p_tile_position_flags;
        @(posedge clk) disable iff (!rst_n)
        command_active |->
            calc_row_in == (calc_row < matrix_size) &&
            calc_col_in == (calc_col < matrix_size) &&
            calc_col_more == (calc_col + COL_STRIDE < matrix_size) &&
            (!calc_row_in || 32'(calc_rows_q) == calc_rows_here) &&
            (!calc_col_in || 32'(calc_cols_q) == calc_cols_here);
    endproperty
    assert property (p_tile_position_flags);

    property p_engine_column_ownership;
        @(posedge clk) disable iff (!rst_n)
        command_active && calc_busy |->
            (calc_col % COL_STRIDE) == COL_BASE;
    endproperty
    assert property (p_engine_column_ownership);
`endif
endmodule
