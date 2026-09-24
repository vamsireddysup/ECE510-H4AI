/*
 * crossbar_mac.sv -- 4x4 Binary-Weight Crossbar MAC Unit
 *
 * Computes out[j] = sum_i weight[i][j] * in[i] each clock cycle.
 * Weights +1 or -1. Inputs 8-bit signed. Outputs 32-bit signed.
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module crossbar_mac (
    input  logic                clk,
    input  logic                rst_n,
    input  logic signed [7:0]   in0, in1, in2, in3,
    input  logic                wr_en,
    input  logic [1:0]          wr_row,
    input  logic [1:0]          wr_col,
    input  logic                wr_weight,
    output logic signed [31:0]  out0, out1, out2, out3,
    output logic                valid
);

    // Weights stored as signed 8-bit (+1 or -1)
    logic signed [7:0] w00, w01, w02, w03;
    logic signed [7:0] w10, w11, w12, w13;
    logic signed [7:0] w20, w21, w22, w23;
    logic signed [7:0] w30, w31, w32, w33;

    // Weight register write
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            w00<=8'sd1; w01<=8'sd1; w02<=8'sd1; w03<=8'sd1;
            w10<=8'sd1; w11<=8'sd1; w12<=8'sd1; w13<=8'sd1;
            w20<=8'sd1; w21<=8'sd1; w22<=8'sd1; w23<=8'sd1;
            w30<=8'sd1; w31<=8'sd1; w32<=8'sd1; w33<=8'sd1;
        end else if (wr_en) begin
            case ({wr_row, wr_col})
                4'b0000: w00 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0001: w01 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0010: w02 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0011: w03 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0100: w10 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0101: w11 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0110: w12 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b0111: w13 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1000: w20 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1001: w21 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1010: w22 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1011: w23 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1100: w30 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1101: w31 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1110: w32 <= wr_weight ? 8'sd1 : -8'sd1;
                4'b1111: w33 <= wr_weight ? 8'sd1 : -8'sd1;
            endcase
        end
    end

    // MAC: registered output
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            out0 <= 0; out1 <= 0; out2 <= 0; out3 <= 0;
            valid <= 0;
        end else begin
            out0 <= w00*in0 + w10*in1 + w20*in2 + w30*in3;
            out1 <= w01*in0 + w11*in1 + w21*in2 + w31*in3;
            out2 <= w02*in0 + w12*in1 + w22*in2 + w32*in3;
            out3 <= w03*in0 + w13*in1 + w23*in2 + w33*in3;
            valid <= 1;
        end
    end

endmodule
