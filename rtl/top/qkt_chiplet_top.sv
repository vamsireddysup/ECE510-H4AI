// Version 1 packed-stream QK^T engine. See docs/STREAM_PROTOCOL.md.
module qkt_chiplet_top #(
    parameter int TILE_SIZE = 4,
    parameter int D_HEAD = 64,
    parameter int T_MAX = 16,
    parameter bit K_REUSE = 0
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
    localparam int ACC_W = $clog2(144*D_HEAD+1)+1;
    localparam int INDEX_W = $clog2(TILE_SIZE*TILE_SIZE);
    logic start, done;
    logic [31:0] matrix_size, tile_count, cycle_count, tile_cycles;
    logic [31:0] input_beats, output_beats, input_stalls, output_stalls;
    logic [31:0] compute_cycles, scale_cycles;
    logic [3:0] error_code;
    logic [31:0] protocol_version;
    assign protocol_version = K_REUSE ? 32'd2 : 32'd1;
    axi4_lite_ctrl u_ctrl (
        .clk, .rst_n, .awvalid, .awready, .awaddr, .wvalid, .wready,
        .wdata, .wstrb, .bvalid, .bready, .bresp, .arvalid, .arready,
        .araddr, .rvalid, .rready, .rdata, .rresp, .start, .done,
        .matrix_size, .tile_count, .cycle_count, .tile_cycles,
        .error_code, .protocol_version, .input_beats, .output_beats, .input_stalls,
        .output_stalls, .compute_cycles, .scale_cycles
    );

    typedef enum logic [3:0] {
        IDLE, SCALES, LOAD_Q, LOAD_K, CACHE_K, CALC, SCALING,
        OUTPUT, ADVANCE, FINISHED
    } state_t;
    state_t state;
    logic [31:0] sq [0:T_MAX-1], sk [0:T_MAX-1];
    logic [3:0] q [0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0] k [0:TILE_SIZE-1][0:D_HEAD-1];
    logic [3:0] k_cache [0:T_MAX-1][0:D_HEAD-1];
    logic signed [ACC_W-1:0] acc [0:TILE_SIZE-1][0:TILE_SIZE-1];
    logic [31:0] scores [0:TILE_SIZE*TILE_SIZE-1];
    logic [31:0] tile_row, tile_col, load_beat, depth, score_index, scaled_count, send_index;
    logic [31:0] cache_tile;
    logic [31:0] launch_row, launch_col;
    logic [31:0] rows_here, cols_here, scores_here, tile_start;
    logic [31:0] scale_a_result, scale_b_result;
    logic scale_a_valid, scale_b_valid;
    logic [INDEX_W-1:0] a_index_0, a_index_1, a_index_2;
    logic [INDEX_W-1:0] b_index_0, b_index_1, b_index_2;
    logic [$clog2(TILE_SIZE)-1:0] a_col_0, a_col_1, a_col_2;
    logic launch_valid;
    assign launch_valid = state == SCALING && score_index < scores_here;
    fp32_mul u_scale_q (.clk, .rst_n,
        .a(quarter_to_fp32(acc[launch_row][launch_col])),
        .b(sq[tile_row+launch_row]), .valid_in(launch_valid),
        .result(scale_a_result), .valid_out(scale_a_valid));
    fp32_mul u_scale_k (.clk, .rst_n, .a(scale_a_result),
        .b(sk[tile_col+32'(a_col_2)]), .valid_in(scale_a_valid),
        .result(scale_b_result), .valid_out(scale_b_valid));
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_index_0 <= 0; a_index_1 <= 0; a_index_2 <= 0;
            a_col_0 <= 0; a_col_1 <= 0; a_col_2 <= 0;
            b_index_0 <= 0; b_index_1 <= 0; b_index_2 <= 0;
        end else begin
            if (launch_valid) begin
                a_index_0 <= INDEX_W'(score_index);
                a_col_0 <= $clog2(TILE_SIZE)'(launch_col);
            end
            a_index_1 <= a_index_0;
            a_index_2 <= a_index_1;
            a_col_1 <= a_col_0;
            a_col_2 <= a_col_1;
            if (scale_a_valid) b_index_0 <= a_index_2;
            b_index_1 <= b_index_0;
            b_index_2 <= b_index_1;
        end
    end

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

    // The accumulator is exact in units of 0.25. Its maximum magnitude at
    // D_HEAD=64 is 9216, so a signed 15-bit register suffices.
    function automatic logic [31:0] quarter_to_fp32(input logic signed [ACC_W-1:0] value);
        logic [ACC_W-1:0] mag;
        logic [7:0] exponent;
        logic [22:0] fraction;
        int leading;
        mag = value[ACC_W-1] ? $unsigned(-value) : $unsigned(value);
        leading = 0;
        for (int bit_index = 0; bit_index < ACC_W; bit_index++)
            if (mag[bit_index]) leading = bit_index;
        exponent = 8'(leading + 125);
        fraction = 23'(mag) << (23-leading);
        quarter_to_fp32 = (value == 0) ? 32'h0 :
            {value[ACC_W-1], exponent, fraction};
    endfunction

    assign rows_here = (tile_row + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - tile_row;
    assign cols_here = (tile_col + TILE_SIZE <= matrix_size) ?
        TILE_SIZE : matrix_size - tile_col;
    assign scores_here = rows_here * cols_here;
    assign s_tready = (state == SCALES || state == LOAD_Q ||
                       state == LOAD_K || state == CACHE_K);
    assign m_tvalid = (state == OUTPUT);
    assign m_tdata = (state == OUTPUT) ?
        {((send_index+1 < scores_here) ? scores[send_index+1] : 32'h0),
          scores[send_index]} : 64'h0;
    assign m_tlast = (state == OUTPUT && send_index+2 >= scores_here);

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state <= IDLE;
            done <= 1'b0;
            error_code <= 4'h0;
            tile_count <= 0;
            cycle_count <= 0;
            tile_cycles <= 0;
            input_beats <= 0;
            output_beats <= 0;
            input_stalls <= 0;
            output_stalls <= 0;
            compute_cycles <= 0;
            scale_cycles <= 0;
            tile_row <= 0;
            tile_col <= 0;
            cache_tile <= 0;
            load_beat <= 0;
            depth <= 0;
            score_index <= 0;
            launch_row <= 0;
            launch_col <= 0;
            scaled_count <= 0;
            send_index <= 0;
            tile_start <= 0;
        end else begin
            if (state != IDLE && state != FINISHED) cycle_count <= cycle_count + 1;
            if (s_tready && !s_tvalid) input_stalls <= input_stalls + 1;
            if (m_tvalid && !m_tready) output_stalls <= output_stalls + 1;
            if (state == CALC) compute_cycles <= compute_cycles + 1;
            if (state == SCALING) scale_cycles <= scale_cycles + 1;
            if (s_tvalid && s_tready) input_beats <= input_beats + 1;
            if (m_tvalid && m_tready) output_beats <= output_beats + 1;
            case (state)
                IDLE, FINISHED: if (start) begin
                    done <= 1'b0;
                    error_code <= 0;
                    tile_count <= 0;
                    cycle_count <= 0;
                    tile_cycles <= 0;
                    input_beats <= 0;
                    output_beats <= 0;
                    input_stalls <= 0;
                    output_stalls <= 0;
                    compute_cycles <= 0;
                    scale_cycles <= 0;
                    tile_row <= 0;
                    tile_col <= 0;
                    cache_tile <= 0;
                    load_beat <= 0;
                    tile_start <= 0;
                    if (matrix_size == 0 || matrix_size > T_MAX) begin
                        error_code <= 4'h1;
                        done <= 1'b1;
                        state <= FINISHED;
                    end else state <= SCALES;
                end
                SCALES: if (s_tvalid && s_tready) begin
                    for (int lane = 0; lane < 2; lane++) begin
                        if (load_beat*2+lane < matrix_size)
                            sq[load_beat*2+lane] <= s_tdata[32*lane +: 32];
                        else if (load_beat*2+lane < 2*matrix_size)
                            sk[load_beat*2+lane-matrix_size] <= s_tdata[32*lane +: 32];
                    end
                    if (load_beat+1 == (2*matrix_size+1)/2) begin
                        if (!s_tlast) begin error_code <= 4'h3; done <= 1; state <= FINISHED; end
                        else begin
                            state <= K_REUSE ? CACHE_K : LOAD_Q;
                            load_beat <= 0;
                        end
                    end else if (s_tlast) begin error_code <= 4'h2; done <= 1; state <= FINISHED; end
                    else load_beat <= load_beat + 1;
                end
                LOAD_Q: if (s_tvalid && s_tready) begin
                    for (int lane = 0; lane < 16; lane++)
                        if (load_beat*16+lane < TILE_SIZE*D_HEAD)
                            q[(load_beat*16+lane)/D_HEAD][(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                    if (load_beat+1 == (TILE_SIZE*D_HEAD+15)/16) begin
                        if (!s_tlast) begin error_code <= 4'h3; done <= 1; state <= FINISHED; end
                        else begin
                            if (K_REUSE) begin
                                state <= CALC;
                                depth <= 0;
                                for (int i = 0; i < TILE_SIZE; i++)
                                    for (int j = 0; j < TILE_SIZE; j++) acc[i][j] <= '0;
                            end else state <= LOAD_K;
                            load_beat <= 0;
                        end
                    end else if (s_tlast) begin error_code <= 4'h2; done <= 1; state <= FINISHED; end
                    else load_beat <= load_beat + 1;
                end
                LOAD_K: if (s_tvalid && s_tready) begin
                    for (int lane = 0; lane < 16; lane++)
                        if (load_beat*16+lane < TILE_SIZE*D_HEAD)
                            k[(load_beat*16+lane)/D_HEAD][(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                    if (load_beat+1 == (TILE_SIZE*D_HEAD+15)/16) begin
                        if (!s_tlast) begin error_code <= 4'h3; done <= 1; state <= FINISHED; end
                        else begin
                            state <= CALC;
                            load_beat <= 0;
                            depth <= 0;
                            for (int i = 0; i < TILE_SIZE; i++)
                                for (int j = 0; j < TILE_SIZE; j++) acc[i][j] <= '0;
                        end
                    end else if (s_tlast) begin error_code <= 4'h2; done <= 1; state <= FINISHED; end
                    else load_beat <= load_beat + 1;
                end
                CACHE_K: if (s_tvalid && s_tready) begin
                    for (int lane = 0; lane < 16; lane++)
                        if (load_beat*16+lane < TILE_SIZE*D_HEAD &&
                            cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD < T_MAX)
                            k_cache[cache_tile*TILE_SIZE+(load_beat*16+lane)/D_HEAD]
                                   [(load_beat*16+lane)%D_HEAD] <= s_tdata[4*lane +: 4];
                    if (load_beat+1 == (TILE_SIZE*D_HEAD+15)/16) begin
                        if (!s_tlast) begin error_code <= 4'h3; done <= 1; state <= FINISHED; end
                        else if ((cache_tile+1)*TILE_SIZE >= matrix_size) begin
                            state <= LOAD_Q;
                            load_beat <= 0;
                            cache_tile <= 0;
                        end else begin
                            cache_tile <= cache_tile + 1;
                            load_beat <= 0;
                        end
                    end else if (s_tlast) begin error_code <= 4'h2; done <= 1; state <= FINISHED; end
                    else load_beat <= load_beat + 1;
                end
                CALC: begin
                    for (int i = 0; i < TILE_SIZE; i++)
                        for (int j = 0; j < TILE_SIZE; j++)
                            acc[i][j] <= acc[i][j] + ACC_W'(decode(q[i][depth]) *
                                decode(K_REUSE ? k_cache[tile_col+j][depth] : k[j][depth]));
                    if (depth == D_HEAD-1) begin
                        state <= SCALING;
                        score_index <= 0;
                        launch_row <= 0;
                        launch_col <= 0;
                        scaled_count <= 0;
                    end else depth <= depth + 1;
                end
                SCALING: begin
                    if (launch_valid) begin
                        score_index <= score_index + 1;
                        if (launch_col+1 == cols_here) begin
                            launch_col <= 0;
                            launch_row <= launch_row + 1;
                        end else launch_col <= launch_col + 1;
                    end
                    if (scale_b_valid) begin
                        scores[b_index_2] <= scale_b_result;
                        scaled_count <= scaled_count + 1;
                    end
                    if (scale_b_valid && scaled_count+1 == scores_here) begin
                        send_index <= 0;
                        state <= OUTPUT;
                    end
                end
                OUTPUT: if (m_tready) begin
                    if (send_index+2 >= scores_here) begin
                        tile_count <= tile_count + 1;
                        tile_cycles <= cycle_count - tile_start + 1;
                        state <= ADVANCE;
                    end else send_index <= send_index + 2;
                end
                ADVANCE: begin
                    tile_start <= cycle_count;
                    if (tile_col+TILE_SIZE < matrix_size) begin
                        tile_col <= tile_col + TILE_SIZE;
                        if (K_REUSE) begin
                            depth <= 0;
                            for (int i = 0; i < TILE_SIZE; i++)
                                for (int j = 0; j < TILE_SIZE; j++) acc[i][j] <= '0;
                            state <= CALC;
                        end else state <= LOAD_K;
                    end else if (tile_row+TILE_SIZE < matrix_size) begin
                        tile_row <= tile_row + TILE_SIZE;
                        tile_col <= 0;
                        state <= LOAD_Q;
                    end else begin
                        done <= 1'b1;
                        state <= FINISHED;
                    end
                end
                default: state <= IDLE;
            endcase
        end
    end
endmodule
