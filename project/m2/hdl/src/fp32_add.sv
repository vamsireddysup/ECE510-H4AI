/*
 * fp32_add.sv -- Synthesizable IEEE 754 FP32 Adder
 *
 * Computes result = a + b for two FP32 inputs.
 * All ports are logic [31:0] packed IEEE 754 bit vectors.
 * No use of real/shortreal -- fully synthesizable.
 *
 * Pipeline: 4 stages (4-cycle latency)
 *   Stage 1: Extract fields, compare exponents, swap if needed
 *   Stage 2: Align smaller significand (shift right by exponent diff)
 *   Stage 3: Add or subtract significands
 *   Stage 4: Normalize and pack result
 *
 * Special cases handled:
 *   - Zero input  -> return the other input
 *   - Infinity    -> infinity output
 *   - NaN         -> NaN output
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module fp32_add (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a,        // FP32 input A
    input  logic [31:0] b,        // FP32 input B
    input  logic        valid_in,
    output logic [31:0] result,
    output logic        valid_out
);

    // -----------------------------------------------------------------------
    // Field extraction
    // -----------------------------------------------------------------------
    logic        sign_a, sign_b;
    logic [7:0]  exp_a,  exp_b;
    logic [23:0] sig_a,  sig_b;   // 24-bit significand with hidden 1

    assign sign_a = a[31];
    assign exp_a  = a[30:23];
    assign sig_a  = (exp_a == 8'h0) ? {1'b0, a[22:0]} : {1'b1, a[22:0]};

    assign sign_b = b[31];
    assign exp_b  = b[30:23];
    assign sig_b  = (exp_b == 8'h0) ? {1'b0, b[22:0]} : {1'b1, b[22:0]};

    // Special cases
    logic nan_a, nan_b, inf_a, inf_b, zero_a, zero_b;
    assign nan_a  = (exp_a == 8'hFF) && (a[22:0] != 23'h0);
    assign nan_b  = (exp_b == 8'hFF) && (b[22:0] != 23'h0);
    assign inf_a  = (exp_a == 8'hFF) && (a[22:0] == 23'h0);
    assign inf_b  = (exp_b == 8'hFF) && (b[22:0] == 23'h0);
    assign zero_a = (exp_a == 8'h00) && (a[22:0] == 23'h0);
    assign zero_b = (exp_b == 8'h00) && (b[22:0] == 23'h0);

    // -----------------------------------------------------------------------
    // Stage 1: Compare exponents, swap so larger exponent is in s1_exp_l
    // -----------------------------------------------------------------------
    logic        s1_sign_l, s1_sign_s;   // sign of larger/smaller magnitude
    logic [7:0]  s1_exp_l;               // larger exponent
    logic [7:0]  s1_exp_diff;            // exponent difference for alignment
    logic [23:0] s1_sig_l, s1_sig_s;     // larger/smaller significand
    logic        s1_is_nan, s1_is_inf;
    logic        s1_inf_sign;
    logic        s1_is_zero;
    logic [31:0] s1_zero_result;
    logic        s1_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_sign_l     <= 1'b0;
            s1_sign_s     <= 1'b0;
            s1_exp_l      <= 8'h0;
            s1_exp_diff   <= 8'h0;
            s1_sig_l      <= 24'h0;
            s1_sig_s      <= 24'h0;
            s1_is_nan     <= 1'b0;
            s1_is_inf     <= 1'b0;
            s1_inf_sign   <= 1'b0;
            s1_is_zero    <= 1'b0;
            s1_zero_result<= 32'h0;
            s1_valid      <= 1'b0;
        end else begin
            s1_valid   <= valid_in;
            s1_is_nan  <= nan_a | nan_b;
            s1_is_inf  <= inf_a | inf_b;
            s1_inf_sign <= inf_a ? sign_a : sign_b;
            s1_is_zero <= zero_a | zero_b;
            s1_zero_result <= zero_a ? b : a;

            // Swap so larger exponent (or equal) is always in _l
            if (exp_a >= exp_b) begin
                s1_sign_l   <= sign_a;
                s1_sign_s   <= sign_b;
                s1_exp_l    <= exp_a;
                s1_exp_diff <= exp_a - exp_b;
                s1_sig_l    <= sig_a;
                s1_sig_s    <= sig_b;
            end else begin
                s1_sign_l   <= sign_b;
                s1_sign_s   <= sign_a;
                s1_exp_l    <= exp_b;
                s1_exp_diff <= exp_b - exp_a;
                s1_sig_l    <= sig_b;
                s1_sig_s    <= sig_a;
            end
        end
    end

    // -----------------------------------------------------------------------
    // Stage 2: Align smaller significand by shifting right
    // -----------------------------------------------------------------------
    logic        s2_sign_l, s2_sign_s;
    logic [7:0]  s2_exp_l;
    logic [24:0] s2_sig_l;     // 25 bits to hold carry from addition
    logic [24:0] s2_sig_s_aligned;
    logic        s2_is_nan, s2_is_inf, s2_inf_sign;
    logic        s2_is_zero;
    logic [31:0] s2_zero_result;
    logic        s2_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_sign_l        <= 1'b0;
            s2_sign_s        <= 1'b0;
            s2_exp_l         <= 8'h0;
            s2_sig_l         <= 25'h0;
            s2_sig_s_aligned <= 25'h0;
            s2_is_nan        <= 1'b0;
            s2_is_inf        <= 1'b0;
            s2_inf_sign      <= 1'b0;
            s2_is_zero       <= 1'b0;
            s2_zero_result   <= 32'h0;
            s2_valid         <= 1'b0;
        end else begin
            s2_valid       <= s1_valid;
            s2_sign_l      <= s1_sign_l;
            s2_sign_s      <= s1_sign_s;
            s2_exp_l       <= s1_exp_l;
            s2_sig_l       <= {1'b0, s1_sig_l};
            s2_is_nan      <= s1_is_nan;
            s2_is_inf      <= s1_is_inf;
            s2_inf_sign    <= s1_inf_sign;
            s2_is_zero     <= s1_is_zero;
            s2_zero_result <= s1_zero_result;

            // Shift smaller significand right to align decimal points
            // Cap shift at 24 to avoid undefined behavior
            if (s1_exp_diff >= 8'd24)
                s2_sig_s_aligned <= 25'h0;
            else
                s2_sig_s_aligned <= {1'b0, s1_sig_s} >> s1_exp_diff;
        end
    end

    // -----------------------------------------------------------------------
    // Stage 3: Add or subtract significands
    // -----------------------------------------------------------------------
    logic        s3_sign;
    logic [7:0]  s3_exp;
    logic [24:0] s3_sum;      // may carry into bit 24
    logic        s3_is_nan, s3_is_inf, s3_inf_sign;
    logic        s3_is_zero;
    logic [31:0] s3_zero_result;
    logic        s3_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s3_sign        <= 1'b0;
            s3_exp         <= 8'h0;
            s3_sum         <= 25'h0;
            s3_is_nan      <= 1'b0;
            s3_is_inf      <= 1'b0;
            s3_inf_sign    <= 1'b0;
            s3_is_zero     <= 1'b0;
            s3_zero_result <= 32'h0;
            s3_valid       <= 1'b0;
        end else begin
            s3_valid       <= s2_valid;
            s3_exp         <= s2_exp_l;
            s3_is_nan      <= s2_is_nan;
            s3_is_inf      <= s2_is_inf;
            s3_inf_sign    <= s2_inf_sign;
            s3_is_zero     <= s2_is_zero;
            s3_zero_result <= s2_zero_result;

            if (s2_sign_l == s2_sign_s) begin
                // Same sign: add magnitudes
                s3_sign <= s2_sign_l;
                s3_sum  <= s2_sig_l + s2_sig_s_aligned;
            end else begin
                // Different signs: subtract smaller from larger
                s3_sign <= s2_sign_l;
                if (s2_sig_l >= s2_sig_s_aligned)
                    s3_sum <= s2_sig_l - s2_sig_s_aligned;
                else
                    s3_sum <= s2_sig_s_aligned - s2_sig_l;
            end
        end
    end

    // -----------------------------------------------------------------------
    // Stage 4: Normalize and pack result
    // -----------------------------------------------------------------------
    logic [31:0] s4_result;
    logic        s4_valid;

    // Leading zero count for normalization (up to 24 bits)
    function automatic [4:0] count_leading_zeros;
        input [24:0] val;
        integer i;
        begin
            count_leading_zeros = 5'd25;
            for (i = 24; i >= 0; i = i - 1)
                if (val[i]) count_leading_zeros = 5'd24 - 5'(i);
        end
    endfunction

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s4_result <= 32'h0;
            s4_valid  <= 1'b0;
        end else begin
            s4_valid <= s3_valid;

            if (s3_is_nan) begin
                s4_result <= 32'h7FC00000;

            end else if (s3_is_inf) begin
                s4_result <= {s3_inf_sign, 8'hFF, 23'h0};

            end else if (s3_is_zero || s3_sum == 25'h0) begin
                s4_result <= s3_zero_result;

            end else if (s3_sum[24]) begin
                // Carry out: result is 1x.xxx, shift right 1, increment exp
                s4_result <= {s3_sign, s3_exp + 8'h1, s3_sum[23:1]};

            end else begin
                // Normalize: find leading 1, shift left accordingly
                automatic logic [4:0]  lz;
                automatic logic [7:0]  norm_exp;
                /* verilator lint_off UNUSEDSIGNAL */
                automatic logic [24:0] norm_sig;
                /* verilator lint_on UNUSEDSIGNAL */
                lz       = count_leading_zeros(s3_sum);
                norm_exp = s3_exp - {3'b0, lz};
                norm_sig = s3_sum << lz;
                s4_result <= {s3_sign, norm_exp, norm_sig[22:0]};
            end
        end
    end

    assign result    = s4_result;
    assign valid_out = s4_valid;

endmodule
