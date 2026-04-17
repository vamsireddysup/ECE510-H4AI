/*
 * fp32_mul.sv -- Synthesizable IEEE 754 FP32 Multiplier
 *
 * Computes result = a * b for two FP32 inputs.
 * All ports are logic [31:0] packed IEEE 754 bit vectors.
 * No use of real/shortreal -- fully synthesizable.
 *
 * Pipeline: 3 stages (registered output, 3-cycle latency)
 *   Stage 1: Extract fields, compute sign and exponent
 *   Stage 2: Significand multiply (24x24 -> 48 bits)
 *   Stage 3: Normalize and pack result
 *
 * Special cases handled:
 *   - Zero input  -> zero output
 *   - Infinity    -> infinity output
 *   - NaN         -> NaN output
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module fp32_mul (
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a,        // FP32 input A
    input  logic [31:0] b,        // FP32 input B
    input  logic        valid_in, // high when a and b are valid
    output logic [31:0] result,   // FP32 result = a * b
    output logic        valid_out // high when result is valid (3 cycles later)
);

    // -----------------------------------------------------------------------
    // Field extraction
    // -----------------------------------------------------------------------
    logic        sign_a, sign_b;
    logic [7:0]  exp_a,  exp_b;
    logic [22:0] man_a,  man_b;

    assign sign_a = a[31];
    assign exp_a  = a[30:23];
    assign man_a  = a[22:0];

    assign sign_b = b[31];
    assign exp_b  = b[30:23];
    assign man_b  = b[22:0];

    // Special case detection
    logic zero_a, zero_b, inf_a, inf_b, nan_a, nan_b;
    assign zero_a = (exp_a == 8'h00) && (man_a == 23'h0);
    assign zero_b = (exp_b == 8'h00) && (man_b == 23'h0);
    assign inf_a  = (exp_a == 8'hFF) && (man_a == 23'h0);
    assign inf_b  = (exp_b == 8'hFF) && (man_b == 23'h0);
    assign nan_a  = (exp_a == 8'hFF) && (man_a != 23'h0);
    assign nan_b  = (exp_b == 8'hFF) && (man_b != 23'h0);

    // -----------------------------------------------------------------------
    // Stage 1: Sign, exponent, special case flags
    // -----------------------------------------------------------------------
    logic        s1_sign;
    logic [9:0]  s1_exp;       // 10 bits to detect overflow/underflow
    logic [23:0] s1_sig_a;     // significand with hidden 1
    logic [23:0] s1_sig_b;
    logic        s1_is_zero;
    logic        s1_is_inf;
    logic        s1_is_nan;
    logic        s1_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s1_sign    <= 1'b0;
            s1_exp     <= 10'h0;
            s1_sig_a   <= 24'h0;
            s1_sig_b   <= 24'h0;
            s1_is_zero <= 1'b0;
            s1_is_inf  <= 1'b0;
            s1_is_nan  <= 1'b0;
            s1_valid   <= 1'b0;
        end else begin
            s1_sign    <= sign_a ^ sign_b;
            // Exponent addition: subtract 127 once (bias counted twice)
            s1_exp     <= {2'b00, exp_a} + {2'b00, exp_b} - 10'd127;
            // Hidden 1 prepended to mantissa
            s1_sig_a   <= {1'b1, man_a};
            s1_sig_b   <= {1'b1, man_b};
            s1_is_zero <= zero_a | zero_b;
            s1_is_inf  <= (inf_a | inf_b) & ~nan_a & ~nan_b;
            s1_is_nan  <= nan_a | nan_b | (zero_a & inf_b) | (inf_a & zero_b);
            s1_valid   <= valid_in;
        end
    end

    // -----------------------------------------------------------------------
    // Stage 2: 24x24 significand multiply
    // -----------------------------------------------------------------------
    logic        s2_sign;
    /* verilator lint_off UNUSEDSIGNAL */
    logic [9:0]  s2_exp;
    //LINTON
    logic [47:0] s2_product;   // 24 x 24 = 48-bit product
    /* verilator lint_on UNUSEDSIGNAL */
    logic        s2_is_zero;
    logic        s2_is_inf;
    logic        s2_is_nan;
    logic        s2_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s2_sign    <= 1'b0;
            s2_exp     <= 10'h0;
            s2_product <= 48'h0;
            s2_is_zero <= 1'b0;
            s2_is_inf  <= 1'b0;
            s2_is_nan  <= 1'b0;
            s2_valid   <= 1'b0;
        end else begin
            s2_sign    <= s1_sign;
            s2_exp     <= s1_exp;
            s2_product <= s1_sig_a * s1_sig_b;
            s2_is_zero <= s1_is_zero;
            s2_is_inf  <= s1_is_inf;
            s2_is_nan  <= s1_is_nan;
            s2_valid   <= s1_valid;
        end
    end

    // -----------------------------------------------------------------------
    // Stage 3: Normalize, round, pack result
    // -----------------------------------------------------------------------
    // The 48-bit product has the result in bits [47:24] or [46:23]
    // If bit 47 is set: product = 1x.xxx -> shift right 1, increment exp
    // If bit 46 is set: product = 01.xxx -> no shift needed
    //
    // Take 23 mantissa bits starting after the leading 1

    logic [31:0] s3_result;
    logic        s3_valid;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            s3_result <= 32'h0;
            s3_valid  <= 1'b0;
        end else begin
            s3_valid <= s2_valid;

            if (s2_is_nan) begin
                // NaN: exponent all 1s, mantissa non-zero
                s3_result <= 32'h7FC00000;

            end else if (s2_is_inf) begin
                // Infinity: exponent all 1s, mantissa zero
                s3_result <= {s2_sign, 8'hFF, 23'h0};

            end else if (s2_is_zero) begin
                // Zero
                s3_result <= {s2_sign, 31'h0};

            end else if (s2_product[47]) begin
                // MSB set: result is 1x.xxx format, shift right
                // Exponent increments by 1
                s3_result <= {
                    s2_sign,
                    s2_exp[7:0] + 8'h1,
                    s2_product[46:24]
                };

            end else begin
                // Normal case: 01.xxx format, no shift
                s3_result <= {
                    s2_sign,
                    s2_exp[7:0],
                    s2_product[45:23]
                };
            end
        end
    end

    assign result    = s3_result;
    assign valid_out = s3_valid;

endmodule
