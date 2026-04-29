/*
 * fp32_add.sv -- Single-cycle FP32 Adder for PE accumulator
 *
 * Computes result = a + b combinationally, registered on clock edge.
 * Latency: 1 cycle.
 *
 * All internal variables declared outside always_comb to avoid latch
 * inference. Default assignments at top of always_comb ensure every
 * path assigns every variable.
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

    // Field extraction
    logic        sign_a, sign_b;
    logic [7:0]  exp_a,  exp_b;
    logic [23:0] sig_a,  sig_b;

    assign sign_a = a[31];
    assign exp_a  = a[30:23];
    assign sig_a  = (exp_a == 8'h0) ? {1'b0, a[22:0]} : {1'b1, a[22:0]};
    assign sign_b = b[31];
    assign exp_b  = b[30:23];
    assign sig_b  = (exp_b == 8'h0) ? {1'b0, b[22:0]} : {1'b1, b[22:0]};

    // Special case flags
    logic nan_a, nan_b, inf_a, inf_b, zero_a, zero_b;
    assign nan_a  = (exp_a == 8'hFF) && (a[22:0] != 23'h0);
    assign nan_b  = (exp_b == 8'hFF) && (b[22:0] != 23'h0);
    assign inf_a  = (exp_a == 8'hFF) && (a[22:0] == 23'h0);
    assign inf_b  = (exp_b == 8'hFF) && (b[22:0] == 23'h0);
    assign zero_a = (exp_a == 8'h00) && (a[22:0] == 23'h0);
    assign zero_b = (exp_b == 8'h00) && (b[22:0] == 23'h0);

    // Internal combinational signals -- declared outside always_comb
    logic        sign_l, sign_s;
    logic [7:0]  exp_l;
    logic [7:0]  exp_diff;
    logic [24:0] sig_l_ext, sig_s_ext, sig_s_aligned;
    logic [24:0] sum;
    logic        result_sign;
    logic [7:0]  result_exp;
    logic [22:0] result_man;
    logic [4:0]  lz;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [24:0] norm_sig;
    /* verilator lint_on UNUSEDSIGNAL */
    logic [31:0] add_result_comb;

    always_comb begin
        // Default assignments -- prevents latch inference
        sign_l          = 1'b0;
        sign_s          = 1'b0;
        exp_l           = 8'h0;
        exp_diff        = 8'h0;
        sig_l_ext       = 25'h0;
        sig_s_ext       = 25'h0;
        sig_s_aligned   = 25'h0;
        sum             = 25'h0;
        result_sign     = 1'b0;
        result_exp      = 8'h0;
        result_man      = 23'h0;
        lz              = 5'h0;
        norm_sig        = 25'h0;
        add_result_comb = 32'h0;

        if (nan_a || nan_b || (inf_a && inf_b && (sign_a != sign_b))) begin
            add_result_comb = 32'h7FC00000; // NaN

        end else if (inf_a) begin
            add_result_comb = a;

        end else if (inf_b) begin
            add_result_comb = b;

        end else if (zero_a && zero_b) begin
            add_result_comb = 32'h0;

        end else if (zero_a) begin
            add_result_comb = b;

        end else if (zero_b) begin
            add_result_comb = a;

        end else begin
            // Determine larger exponent
            if (exp_a >= exp_b) begin
                sign_l    = sign_a;
                sign_s    = sign_b;
                exp_l     = exp_a;
                exp_diff  = exp_a - exp_b;
                sig_l_ext = {1'b0, sig_a};
                sig_s_ext = {1'b0, sig_b};
            end else begin
                sign_l    = sign_b;
                sign_s    = sign_a;
                exp_l     = exp_b;
                exp_diff  = exp_b - exp_a;
                sig_l_ext = {1'b0, sig_b};
                sig_s_ext = {1'b0, sig_a};
            end

            // Align smaller significand
            sig_s_aligned = (exp_diff >= 8'd25) ? 25'h0 :
                            (sig_s_ext >> exp_diff);

            // Add or subtract
            if (sign_l == sign_s) begin
                result_sign = sign_l;
                sum = sig_l_ext + sig_s_aligned;
            end else begin
                result_sign = sign_l;
                if (sig_l_ext >= sig_s_aligned)
                    sum = sig_l_ext - sig_s_aligned;
                else
                    sum = sig_s_aligned - sig_l_ext;
            end

            // Normalize and pack
            if (sum == 25'h0) begin
                add_result_comb = 32'h0;

            end else if (sum[24]) begin
                // Carry out: shift right 1
                result_exp      = exp_l + 8'h1;
                result_man      = sum[23:1];
                add_result_comb = {result_sign, result_exp, result_man};

            end else begin
                // Count leading zeros to normalize
                lz = 5'd0;
                if      (!sum[23]) lz = 5'd1;
                if      (lz == 5'd1 && !sum[22]) lz = 5'd2;
                if      (lz == 5'd2 && !sum[21]) lz = 5'd3;
                if      (lz == 5'd3 && !sum[20]) lz = 5'd4;
                if      (lz == 5'd4 && !sum[19]) lz = 5'd5;
                if      (lz == 5'd5 && !sum[18]) lz = 5'd6;
                if      (lz == 5'd6 && !sum[17]) lz = 5'd7;
                if      (lz == 5'd7 && !sum[16]) lz = 5'd8;

                norm_sig        = sum << lz;
                result_exp      = exp_l - {3'b0, lz};
                result_man      = norm_sig[22:0];
                add_result_comb = {result_sign, result_exp, result_man};
            end
        end
    end

    // Register output -- 1-cycle latency
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            result    <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            result    <= add_result_comb;
            valid_out <= valid_in;
        end
    end

endmodule
