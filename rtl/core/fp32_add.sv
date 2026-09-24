/*
 * fp32_add.sv -- 3-stage Pipelined FP32 Adder for PE accumulator
 *
 * Pipeline stages:
 *   Stage 1 (cycle 1): Field extraction, special case detection,
 *                      exponent comparison, larger operand selection
 *   Stage 2 (cycle 2): Significand alignment, addition/subtraction
 *   Stage 3 (cycle 3): Normalization, result packing
 *
 * Latency: 3 cycles (vs 1 cycle in single-stage version)
 * Interface identical to single-stage fp32_add.sv -- drop-in replacement.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module fp32_add (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a,
    input  logic [31:0] b,
    input  logic        valid_in,
    output logic [31:0] result,
    output logic        valid_out
);

    // -----------------------------------------------------------------------
    // Combinational field extraction (no registers -- feeds Stage 1)
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
    // Stage 1 registers
    // -----------------------------------------------------------------------
    logic        s1_valid;
    logic        s1_special;
    logic [31:0] s1_special_result;
    logic        s1_sign_l, s1_sign_s;
    logic [7:0]  s1_exp_l;
    logic [7:0]  s1_exp_diff;
    logic [24:0] s1_sig_l, s1_sig_s;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_valid          <= 1'b0;
            s1_special        <= 1'b0;
            s1_special_result <= 32'h0;
            s1_sign_l         <= 1'b0;
            s1_sign_s         <= 1'b0;
            s1_exp_l          <= 8'h0;
            s1_exp_diff       <= 8'h0;
            s1_sig_l          <= 25'h0;
            s1_sig_s          <= 25'h0;
        end else begin
            s1_valid <= valid_in;

            if (nan_a || nan_b || (inf_a && inf_b && (sign_a != sign_b))) begin
                s1_special        <= 1'b1;
                s1_special_result <= 32'h7FC00000;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else if (inf_a) begin
                s1_special <= 1'b1; s1_special_result <= a;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else if (inf_b) begin
                s1_special <= 1'b1; s1_special_result <= b;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else if (zero_a && zero_b) begin
                s1_special <= 1'b1; s1_special_result <= 32'h0;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else if (zero_a) begin
                s1_special <= 1'b1; s1_special_result <= b;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else if (zero_b) begin
                s1_special <= 1'b1; s1_special_result <= a;
                s1_sign_l <= 1'b0; s1_sign_s <= 1'b0;
                s1_exp_l  <= 8'h0; s1_exp_diff <= 8'h0;
                s1_sig_l  <= 25'h0; s1_sig_s <= 25'h0;
            end else begin
                s1_special        <= 1'b0;
                s1_special_result <= 32'h0;
                if (exp_a >= exp_b) begin
                    s1_sign_l   <= sign_a; s1_sign_s <= sign_b;
                    s1_exp_l    <= exp_a;  s1_exp_diff <= exp_a - exp_b;
                    s1_sig_l    <= {1'b0, sig_a};
                    s1_sig_s    <= {1'b0, sig_b};
                end else begin
                    s1_sign_l   <= sign_b; s1_sign_s <= sign_a;
                    s1_exp_l    <= exp_b;  s1_exp_diff <= exp_b - exp_a;
                    s1_sig_l    <= {1'b0, sig_b};
                    s1_sig_s    <= {1'b0, sig_a};
                end
            end
        end
    end

    // -----------------------------------------------------------------------
    // Stage 2 registers: alignment + add/subtract
    // -----------------------------------------------------------------------
    logic        s2_valid;
    logic        s2_special;
    logic [31:0] s2_special_result;
    logic        s2_result_sign;
    logic [7:0]  s2_exp_l;
    logic [24:0] s2_sum;

    logic [24:0] sig_s_aligned;
    assign sig_s_aligned = (s1_exp_diff >= 8'd25) ? 25'h0 :
                           (s1_sig_s >> s1_exp_diff);

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_valid          <= 1'b0;
            s2_special        <= 1'b0;
            s2_special_result <= 32'h0;
            s2_result_sign    <= 1'b0;
            s2_exp_l          <= 8'h0;
            s2_sum            <= 25'h0;
        end else begin
            s2_valid          <= s1_valid;
            s2_special        <= s1_special;
            s2_special_result <= s1_special_result;
            s2_exp_l          <= s1_exp_l;

            if (!s1_special) begin
                if (s1_sign_l == s1_sign_s) begin
                    s2_result_sign <= s1_sign_l;
                    s2_sum         <= s1_sig_l + sig_s_aligned;
                end else begin
                    s2_result_sign <= s1_sign_l;
                    if (s1_sig_l >= sig_s_aligned)
                        s2_sum <= s1_sig_l - sig_s_aligned;
                    else
                        s2_sum <= sig_s_aligned - s1_sig_l;
                end
            end else begin
                s2_result_sign <= 1'b0;
                s2_sum         <= 25'h0;
            end
        end
    end

    // -----------------------------------------------------------------------
    // Stage 3 registers: normalization + pack
    // -----------------------------------------------------------------------
    logic [4:0]  lz;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [24:0] norm_sig;
    /* verilator lint_on UNUSEDSIGNAL */

    always_comb begin
        lz = 5'd0;
        if      (!s2_sum[23])                   lz = 5'd1;
        if      (lz == 5'd1 && !s2_sum[22])    lz = 5'd2;
        if      (lz == 5'd2 && !s2_sum[21])    lz = 5'd3;
        if      (lz == 5'd3 && !s2_sum[20])    lz = 5'd4;
        if      (lz == 5'd4 && !s2_sum[19])    lz = 5'd5;
        if      (lz == 5'd5 && !s2_sum[18])    lz = 5'd6;
        if      (lz == 5'd6 && !s2_sum[17])    lz = 5'd7;
        if      (lz == 5'd7 && !s2_sum[16])    lz = 5'd8;
        norm_sig = s2_sum << lz;
    end

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result    <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            valid_out <= s2_valid;
            if (s2_special) begin
                result <= s2_special_result;
            end else if (s2_sum == 25'h0) begin
                result <= 32'h0;
            end else if (s2_sum[24]) begin
                result <= {s2_result_sign, s2_exp_l + 8'h1, s2_sum[23:1]};
            end else begin
                result <= {s2_result_sign, s2_exp_l - {3'b0,lz}, norm_sig[22:0]};
            end
        end
    end

endmodule
