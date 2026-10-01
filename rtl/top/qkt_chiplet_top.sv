// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Overlapped packed-stream QK^T engine. See docs/stream-protocol.md.
// ENGINES replicated compute engines share the input frontend, Q tile banks,
// K cache, block-scale storage, and the ordered output port.
module qkt_chiplet_top #(
    parameter int TILE_SIZE = 4,
    parameter int D_HEAD = 64,
    parameter int T_MAX = 16,
    parameter int K_REUSE = 0,
    parameter int SCALE_BLOCK_SIZE = 16,
    parameter int SCORE_LANES = 1,
    parameter int ENGINES = 1,
    // 0 selects FP32 block scales, 1 selects packed ADR 0008 E4M3 scales.
    parameter int SCALE_FORMAT = 0
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

    // The external reset drives only this synchronizer. Each engine then takes
    // its own registered copy, so no reset tree starts at a pin and none spans
    // more than one engine.
    logic rst_meta_n, rst_sync_n;
    logic [ENGINES-1:0] eng_rst_n;
    always_ff @(posedge clk) begin
        rst_meta_n <= rst_n;
        rst_sync_n <= rst_meta_n;
        eng_rst_n <= {ENGINES{rst_sync_n}};
    end

    localparam int BLOCK_COUNT = (D_HEAD+SCALE_BLOCK_SIZE-1)/SCALE_BLOCK_SIZE;
    localparam int SCALE_W = (SCALE_FORMAT == 0) ? 32 : 8;
    localparam int SCALES_PER_BEAT = 64/SCALE_W;
    localparam int TILE_BEATS = (TILE_SIZE*D_HEAD+15)/16;
    localparam int FILL_DEPTHS = (16/TILE_SIZE > 0) ? 16/TILE_SIZE : 1;
    localparam int ENGINE_W = (ENGINES <= 1) ? 1 : $clog2(ENGINES);
    // A running command has 1 <= matrix_size <= T_MAX, so every quantity
    // derived from it is sized by T_MAX rather than by the 32-bit register.
    localparam int SIZE_W = $clog2(T_MAX+1);
    localparam int POS_W = $clog2(T_MAX+TILE_SIZE+1);
    localparam int TILE_ROWS_MAX = (T_MAX+TILE_SIZE-1)/TILE_SIZE;
    localparam int TILE_ROW_W = $clog2(TILE_ROWS_MAX+1);
    localparam int TILE_TOTAL_W = $clog2(TILE_ROWS_MAX*TILE_ROWS_MAX+1);
    localparam int SCALE_VALUES_MAX = 2*T_MAX*BLOCK_COUNT;
    localparam int SCALE_BEATS_MAX =
        (SCALE_VALUES_MAX+SCALES_PER_BEAT-1)/SCALES_PER_BEAT;
    localparam int BEAT_W = $clog2(((SCALE_BEATS_MAX > TILE_BEATS) ?
        SCALE_BEATS_MAX : TILE_BEATS) + 1);

    logic start, done, command_active;
    logic [31:0] matrix_size, tile_count, cycle_count, tile_cycles;
    logic [31:0] input_beats, output_beats, input_stalls, output_stalls;
    logic [31:0] compute_cycles, scale_cycles;
    logic [3:0] error_code;
    logic [31:0] protocol_version;
    assign protocol_version = (SCALE_FORMAT != 0) ?
        (K_REUSE_EN ? 32'd8 : 32'd7) :
        ((SCALE_BLOCK_SIZE == 16) ?
            (K_REUSE_EN ? 32'd6 : 32'd5) :
            (K_REUSE_EN ? 32'd4 : 32'd3));
    axi4_lite_ctrl u_ctrl (
        .clk, .rst_n(rst_sync_n), .awvalid, .awready, .awaddr, .wvalid, .wready,
        .wdata, .wstrb, .arvalid, .arready,
        .araddr, .rvalid, .rready, .rdata, .rresp, .bvalid, .bready, .bresp,
        .start, .done,
        .matrix_size, .tile_count, .cycle_count, .tile_cycles,
        .error_code, .protocol_version, .input_beats, .output_beats, .input_stalls,
        .output_stalls, .compute_cycles, .scale_cycles
    );

    typedef enum logic [2:0] {
        FE_IDLE, FE_SCALES, FE_CACHE_K, FE_LOAD_Q, FE_LOAD_K, FE_DONE
    } frontend_t;
    frontend_t frontend;

    logic [SCALE_W-1:0] sq [0:T_MAX-1][0:BLOCK_COUNT-1];
    logic [SCALE_W-1:0] sk [0:T_MAX-1][0:BLOCK_COUNT-1];
    logic [3:0] q_bank [0:1][0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0] k_cache [0:T_MAX-1][0:D_HEAD-1];

    logic [1:0] q_valid;
    logic load_q_bank;
    logic [SIZE_W-1:0] cmd_size;
    logic [BEAT_W-1:0] load_beat;
    logic [POS_W-1:0] cache_tile, input_row, input_col;
    logic [31:0] send_index, tile_start;
    logic [TILE_ROW_W-1:0] tiles_per_row, retire_col;
    logic [TILE_TOTAL_W-1:0] tiles_left;
    logic [ENGINE_W-1:0] retire_engine, dispatch_engine;
    logic k_cache_ready;

    // Per-engine shared-resource ports.
    logic [ENGINES-1:0] eng_q_rd_bank;
    logic [ENGINES*32-1:0] eng_q_rd_depth;
    logic [ENGINES*TILE_SIZE*4-1:0] eng_q_rd_data;
    logic [ENGINES*2-1:0] eng_q_release;
    logic [ENGINES-1:0] eng_k_ready, eng_k_wr_valid;
    logic [ENGINES*32-1:0] eng_kc_col, eng_kc_beat;
    logic [ENGINES*TILE_SIZE*FILL_DEPTHS*4-1:0] eng_kc_data;
    logic [ENGINES*SCORE_LANES*32-1:0] eng_sq_index, eng_sk_index;
    logic [ENGINES*SCORE_LANES*BLOCK_COUNT*32-1:0] eng_sq_data, eng_sk_data;
    logic [ENGINES-1:0] eng_score_ready, eng_tile_retire;
    logic [ENGINES*32-1:0] eng_score_count;
    logic [ENGINES*64-1:0] eng_rd_data;
    logic [ENGINES-1:0] eng_calc_active, eng_scale_active;
    logic [1:0] q_release_seen [0:ENGINES-1];

    for (genvar e = 0; e < ENGINES; e++) begin : g_engine
        // Shared Q tile read: every engine works on the same Q row.
        for (genvar row = 0; row < TILE_SIZE; row++) begin : g_q_read
            assign eng_q_rd_data[(e*TILE_SIZE+row)*4 +: 4] =
                q_bank[eng_q_rd_bank[e]][row][eng_q_rd_depth[e*32 +: 32]];
        end
        // Shared K cache burst read for the K-reuse builds.
        for (genvar row = 0; row < TILE_SIZE; row++) begin : g_kc_row
            for (genvar d = 0; d < FILL_DEPTHS; d++) begin : g_kc_depth
                logic [31:0] kc_row_index, kc_depth_index;
                assign kc_row_index = eng_kc_col[e*32 +: 32] + row;
                assign kc_depth_index =
                    eng_kc_beat[e*32 +: 32]*FILL_DEPTHS + d;
                assign eng_kc_data[
                    ((e*TILE_SIZE+row)*FILL_DEPTHS+d)*4 +: 4] =
                    (kc_row_index < T_MAX && kc_depth_index < D_HEAD) ?
                        k_cache[kc_row_index][kc_depth_index] : 4'h0;
            end
        end
        // Shared block-scale reads. sq is common to all engines in a row;
        // only the sk index differs, because engines own different columns.
        for (genvar lane = 0; lane < SCORE_LANES; lane++) begin : g_scale_lane
            for (genvar block = 0; block < BLOCK_COUNT; block++) begin : g_scale_block
                localparam int FLAT = (e*SCORE_LANES+lane)*BLOCK_COUNT+block;
                logic [31:0] sq_row, sk_row;
                assign sq_row = eng_sq_index[(e*SCORE_LANES+lane)*32 +: 32];
                assign sk_row = eng_sk_index[(e*SCORE_LANES+lane)*32 +: 32];
                assign eng_sq_data[FLAT*32 +: 32] = (sq_row < T_MAX) ?
                    {{(32-SCALE_W){1'b0}}, sq[sq_row][block]} : 32'h0;
                assign eng_sk_data[FLAT*32 +: 32] = (sk_row < T_MAX) ?
                    {{(32-SCALE_W){1'b0}}, sk[sk_row][block]} : 32'h0;
            end
        end
        assign eng_k_wr_valid[e] = !K_REUSE_EN && s_tvalid && s_tready &&
            frontend == FE_LOAD_K && dispatch_engine == ENGINE_W'(e);
        assign eng_tile_retire[e] = m_tvalid && m_tready && m_tlast &&
            retire_engine == ENGINE_W'(e);

        qkt_engine #(
            .TILE_SIZE(TILE_SIZE), .D_HEAD(D_HEAD), .K_REUSE(K_REUSE), .SCALE_BLOCK_SIZE(SCALE_BLOCK_SIZE),
            .SCORE_LANES(SCORE_LANES), .ENGINES(ENGINES), .ENGINE_ID(e),
            .SCALE_FORMAT(SCALE_FORMAT)
        ) u_engine (
            .clk, .rst_n(eng_rst_n[e]), .command_active, .flush(start), .matrix_size,
            .q_valid_in(q_valid),
            .q_wr_valid(s_tvalid && s_tready && frontend == FE_LOAD_Q),
            .q_wr_bank(load_q_bank), .q_wr_beat(32'(load_beat)), .q_wr_data(s_tdata),
            .q_rd_bank(eng_q_rd_bank[e]),
            .q_rd_depth(eng_q_rd_depth[e*32 +: 32]),
            .q_rd_data(eng_q_rd_data[e*TILE_SIZE*4 +: TILE_SIZE*4]),
            .q_release(eng_q_release[e*2 +: 2]),
            .k_ready(eng_k_ready[e]),
            .k_wr_valid(eng_k_wr_valid[e]),
            .k_wr_last(32'(load_beat)+1 == TILE_BEATS),
            .k_wr_beat(32'(load_beat)), .k_wr_data(s_tdata),
            .k_cache_ready(k_cache_ready),
            .kc_col(eng_kc_col[e*32 +: 32]), .kc_beat(eng_kc_beat[e*32 +: 32]),
            .kc_data(eng_kc_data[
                e*TILE_SIZE*FILL_DEPTHS*4 +: TILE_SIZE*FILL_DEPTHS*4]),
            .sq_index(eng_sq_index[e*SCORE_LANES*32 +: SCORE_LANES*32]),
            .sk_index(eng_sk_index[e*SCORE_LANES*32 +: SCORE_LANES*32]),
            .sq_data(eng_sq_data[
                e*SCORE_LANES*BLOCK_COUNT*32 +: SCORE_LANES*BLOCK_COUNT*32]),
            .sk_data(eng_sk_data[
                e*SCORE_LANES*BLOCK_COUNT*32 +: SCORE_LANES*BLOCK_COUNT*32]),
            .score_ready(eng_score_ready[e]),
            .score_count_out(eng_score_count[e*32 +: 32]),
            .rd_index(send_index), .rd_data(eng_rd_data[e*64 +: 64]),
            .tile_retire(eng_tile_retire[e]),
            .calc_active(eng_calc_active[e]),
            .scale_active(eng_scale_active[e])
        );
    end

    assign dispatch_engine = ENGINE_W'((32'(input_col)/TILE_SIZE) % ENGINES);

    always_comb begin
        s_tready = 1'b0;
        if (command_active) begin
            case (frontend)
                FE_SCALES, FE_CACHE_K: s_tready = 1'b1;
                FE_LOAD_Q: s_tready = !q_valid[load_q_bank];
                FE_LOAD_K: s_tready = eng_k_ready[dispatch_engine];
                default: s_tready = 1'b0;
            endcase
        end
    end

    assign m_tvalid = command_active && eng_score_ready[retire_engine];
    assign m_tdata = m_tvalid ? eng_rd_data[retire_engine*64 +: 64] : 64'h0;
    assign m_tlast = m_tvalid &&
        send_index+2 >= eng_score_count[retire_engine*32 +: 32];

    logic [1:0] q_all_released;
    always_comb begin
        for (int bank = 0; bank < 2; bank++) begin
            q_all_released[bank] = 1'b1;
            for (int e = 0; e < ENGINES; e++)
                if (!(q_release_seen[e][bank] || eng_q_release[e*2+bank]))
                    q_all_released[bank] = 1'b0;
        end
    end

    logic [31:0] active_calc, active_scale;
    always_comb begin
        active_calc = 0;
        active_scale = 0;
        for (int e = 0; e < ENGINES; e++) begin
            active_calc = active_calc + 32'(eng_calc_active[e]);
            active_scale = active_scale + 32'(eng_scale_active[e]);
        end
    end

    always_ff @(posedge clk) begin
        if (!rst_sync_n) begin
            frontend <= FE_IDLE;
            command_active <= 1'b0;
            done <= 1'b0;
            error_code <= 0;
            tile_count <= 0; cycle_count <= 0; tile_cycles <= 0;
            input_beats <= 0; output_beats <= 0;
            input_stalls <= 0; output_stalls <= 0;
            compute_cycles <= 0; scale_cycles <= 0;
            q_valid <= 0; load_q_bank <= 0; k_cache_ready <= 1'b0;
            load_beat <= 0; cache_tile <= 0; input_row <= 0; input_col <= 0;
            send_index <= 0; tile_start <= 0;
            tiles_per_row <= 0; retire_col <= 0; retire_engine <= 0;
            tiles_left <= 0; cmd_size <= 0;
            for (int e = 0; e < ENGINES; e++) q_release_seen[e] <= 2'b00;
        end else begin
            if (command_active) cycle_count <= cycle_count + 1;
            if (s_tready && !s_tvalid) input_stalls <= input_stalls + 1;
            if (m_tvalid && !m_tready) output_stalls <= output_stalls + 1;
            compute_cycles <= compute_cycles + active_calc;
            scale_cycles <= scale_cycles + active_scale;
            if (s_tvalid && s_tready) input_beats <= input_beats + 1;
            if (m_tvalid && m_tready) output_beats <= output_beats + 1;

            for (int e = 0; e < ENGINES; e++)
                q_release_seen[e] <= q_release_seen[e] | eng_q_release[e*2 +: 2];

            if (start) begin
                done <= 1'b0; error_code <= 0; command_active <= 1'b0;
                tile_count <= 0; cycle_count <= 0; tile_cycles <= 0;
                input_beats <= 0; output_beats <= 0;
                input_stalls <= 0; output_stalls <= 0;
                compute_cycles <= 0; scale_cycles <= 0;
                q_valid <= 0; load_q_bank <= 0; k_cache_ready <= 1'b0;
                load_beat <= 0; cache_tile <= 0; input_row <= 0; input_col <= 0;
                send_index <= 0; tile_start <= 0;
                retire_col <= 0; retire_engine <= 0;
                for (int e = 0; e < ENGINES; e++) q_release_seen[e] <= 2'b00;
                // Only a valid size starts a command, so these narrow copies
                // are exact whenever command_active is set.
                cmd_size <= SIZE_W'(matrix_size);
                tiles_per_row <= TILE_ROW_W'((matrix_size+TILE_SIZE-1)/TILE_SIZE);
                tiles_left <= TILE_TOTAL_W'(TILE_ROW_W'((matrix_size+TILE_SIZE-1)/TILE_SIZE) *
                    TILE_ROW_W'((matrix_size+TILE_SIZE-1)/TILE_SIZE));
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
                            for (int lane = 0; lane < SCALES_PER_BEAT; lane++) begin
                                if (load_beat*SCALES_PER_BEAT+lane <
                                    32'(cmd_size)*BLOCK_COUNT)
                                    sq[(load_beat*SCALES_PER_BEAT+lane)/BLOCK_COUNT]
                                      [(load_beat*SCALES_PER_BEAT+lane)%BLOCK_COUNT] <=
                                        s_tdata[SCALE_W*lane +: SCALE_W];
                                else if (load_beat*SCALES_PER_BEAT+lane <
                                         2*32'(cmd_size)*BLOCK_COUNT)
                                    sk[(load_beat*SCALES_PER_BEAT+lane-
                                        32'(cmd_size)*BLOCK_COUNT)/BLOCK_COUNT]
                                      [(load_beat*SCALES_PER_BEAT+lane-
                                        32'(cmd_size)*BLOCK_COUNT)%BLOCK_COUNT] <=
                                        s_tdata[SCALE_W*lane +: SCALE_W];
                            end
                            if ((32'(load_beat)+1)*SCALES_PER_BEAT >=
                                2*32'(cmd_size)*BLOCK_COUNT) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    frontend <= K_REUSE_EN ? FE_CACHE_K : FE_LOAD_Q;
                                    load_beat <= 0;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1'b1;
                        end
                        FE_CACHE_K: begin
                            for (int lane = 0; lane < 16; lane++)
                                if (load_beat*16+lane < TILE_SIZE*D_HEAD &&
                                    cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD < T_MAX)
                                    k_cache[cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD]
                                           [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                            if (32'(load_beat)+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else if ((32'(cache_tile)+1)*TILE_SIZE >= 32'(cmd_size)) begin
                                    frontend <= FE_LOAD_Q; load_beat <= 0; cache_tile <= 0;
                                    k_cache_ready <= 1'b1;
                                end else begin
                                    cache_tile <= cache_tile + 1'b1; load_beat <= 0;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1'b1;
                        end
                        FE_LOAD_Q: begin
                            for (int lane = 0; lane < 16; lane++)
                                if (load_beat*16+lane < TILE_SIZE*D_HEAD)
                                    q_bank[load_q_bank][(load_beat*16+lane)/D_HEAD]
                                          [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                            if (32'(load_beat)+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    q_valid[load_q_bank] <= 1'b1;
                                    load_beat <= 0; input_col <= 0;
                                    if (K_REUSE_EN) begin
                                        if (32'(input_row)+TILE_SIZE >= 32'(cmd_size)) begin
                                            frontend <= FE_DONE;
                                        end else begin
                                            input_row <= input_row + POS_W'(TILE_SIZE);
                                            load_q_bank <= ~load_q_bank;
                                        end
                                    end else frontend <= FE_LOAD_K;
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1'b1;
                        end
                        FE_LOAD_K: begin
                            if (32'(load_beat)+1 == TILE_BEATS) begin
                                if (!s_tlast) begin
                                    error_code <= 4'h3; done <= 1; command_active <= 0;
                                end else begin
                                    load_beat <= 0;
                                    if (32'(input_col)+TILE_SIZE < 32'(cmd_size))
                                        input_col <= input_col + POS_W'(TILE_SIZE);
                                    else if (32'(input_row)+TILE_SIZE < 32'(cmd_size)) begin
                                        input_row <= input_row + POS_W'(TILE_SIZE);
                                        load_q_bank <= ~load_q_bank;
                                        frontend <= FE_LOAD_Q;
                                    end else begin
                                        frontend <= FE_DONE;
                                    end
                                end
                            end else if (s_tlast) begin
                                error_code <= 4'h2; done <= 1; command_active <= 0;
                            end else load_beat <= load_beat + 1'b1;
                        end
                        default: ;
                    endcase
                end

                // A Q bank is reusable only after every engine has released it.
                for (int bank = 0; bank < 2; bank++) begin
                    if (q_all_released[bank] && q_valid[bank]) begin
                        q_valid[bank] <= 1'b0;
                        for (int e = 0; e < ENGINES; e++)
                            q_release_seen[e][bank] <= 1'b0;
                    end
                end

                // Output sequencer retires tiles in q-row-major, k-column order.
                if (m_tvalid && m_tready) begin
                    if (send_index+2 >= eng_score_count[retire_engine*32 +: 32]) begin
                        send_index <= 0;
                        tile_count <= tile_count + 1;
                        tile_cycles <= cycle_count - tile_start + 1;
                        tile_start <= cycle_count;
                        if (retire_col+1'b1 == tiles_per_row) begin
                            retire_col <= 0; retire_engine <= '0;
                        end else begin
                            retire_col <= retire_col + 1'b1;
                            retire_engine <= (32'(retire_engine)+1 == ENGINES) ?
                                '0 : retire_engine + 1'b1;
                        end
                        tiles_left <= tiles_left - 1'b1;
                        if (tiles_left == TILE_TOTAL_W'(1)) begin
                            done <= 1'b1; command_active <= 1'b0;
                        end
                    end else send_index <= send_index + 2;
                end
            end
        end
    end

`ifndef SYNTHESIS
    // Protocol and ownership invariants for the concurrent tile sequencers.
    property p_output_stable_while_stalled;
        @(posedge clk) disable iff (!rst_sync_n)
        m_tvalid && !m_tready |=>
            m_tvalid && $stable(m_tdata) && $stable(m_tlast);
    endproperty
    assert property (p_output_stable_while_stalled);

    property p_q_bank_ownership;
        @(posedge clk) disable iff (!rst_sync_n)
        s_tvalid && s_tready && frontend == FE_LOAD_Q |-> !q_valid[load_q_bank];
    endproperty
    assert property (p_q_bank_ownership);

    property p_output_index_legal;
        @(posedge clk) disable iff (!rst_sync_n)
        m_tvalid |-> send_index < eng_score_count[retire_engine*32 +: 32];
    endproperty
    assert property (p_output_index_legal);

    // Ordered retirement: the retire pointer only ever advances by one engine
    // within a Q row, and restarts at engine 0 on each new Q row.
    property p_retire_order;
        @(posedge clk) disable iff (!rst_sync_n)
        $changed(retire_engine) && $past(rst_sync_n) && !$past(start) |->
            retire_engine == '0 ||
            32'(retire_engine) == 32'($past(retire_engine))+1;
    endproperty
    assert property (p_retire_order);

    property p_retire_advances_on_tlast;
        @(posedge clk) disable iff (!rst_sync_n)
        $changed(retire_col) && $past(rst_sync_n) && !$past(start) |->
            $past(m_tvalid && m_tready && m_tlast);
    endproperty
    assert property (p_retire_advances_on_tlast);

    property p_legal_frontend_transition;
        @(posedge clk) disable iff (!rst_sync_n)
        $changed(frontend) |->
            frontend == FE_SCALES || frontend == FE_DONE ||
            ($past(frontend) == FE_SCALES &&
                (frontend == FE_CACHE_K || frontend == FE_LOAD_Q)) ||
            ($past(frontend) == FE_CACHE_K && frontend == FE_LOAD_Q) ||
            ($past(frontend) == FE_LOAD_Q && frontend == FE_LOAD_K) ||
            ($past(frontend) == FE_LOAD_K && frontend == FE_LOAD_Q);
    endproperty
    assert property (p_legal_frontend_transition);
`endif
endmodule
