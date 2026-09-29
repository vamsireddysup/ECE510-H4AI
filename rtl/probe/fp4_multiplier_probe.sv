// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Standalone cost probe; this module is not part of rtl/filelist.f.
module fp4_multiplier_probe #(
    parameter int IMPLEMENTATION = 0
)(
    input  logic [3:0] a,
    input  logic [3:0] b,
    output logic [31:0] result
);
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

    function automatic logic [7:0] shift_add_magnitude(
        input logic [2:0] a_code,
        input logic [2:0] b_code
    );
        logic a_zero, b_zero, a_three, b_three;
        logic [1:0] a_shift, b_shift;
        logic [2:0] total_shift;
        logic [7:0] coefficient;
        a_zero = a_code == 0;
        b_zero = b_code == 0;
        a_three = a_code == 3'd3 || a_code == 3'd5 || a_code == 3'd7;
        b_three = b_code == 3'd3 || b_code == 3'd5 || b_code == 3'd7;
        case (a_code)
            3'd2, 3'd5: a_shift = 1;
            3'd4, 3'd7: a_shift = 2;
            3'd6:       a_shift = 3;
            default:    a_shift = 0;
        endcase
        case (b_code)
            3'd2, 3'd5: b_shift = 1;
            3'd4, 3'd7: b_shift = 2;
            3'd6:       b_shift = 3;
            default:    b_shift = 0;
        endcase
        total_shift = a_shift + b_shift;
        case ({a_three, b_three})
            2'b00: coefficient = 8'd1;
            2'b11: coefficient = 8'd9;
            default: coefficient = 8'd3;
        endcase
        shift_add_magnitude = (a_zero || b_zero) ? 0 :
            coefficient << total_shift;
    endfunction

    if (IMPLEMENTATION == 0) begin : g_current
        logic signed [9:0] product;
        always_comb begin
            product = decode(a) * decode(b);
            result = {{22{product[9]}}, product};
        end
    end else if (IMPLEMENTATION == 1) begin : g_shift_add
        logic signed [9:0] product;
        logic signed [9:0] signed_magnitude;
        logic [7:0] magnitude;
        always_comb begin
            magnitude = shift_add_magnitude(a[2:0], b[2:0]);
            signed_magnitude = {2'b00, magnitude};
            product = (a[3] ^ b[3]) ? -signed_magnitude : signed_magnitude;
            result = {{22{product[9]}}, product};
        end
    end else begin : g_product_rom
        fp4_mul_lut u_lut (.a, .b, .result);
    end
endmodule

module fp4_multiplier_equiv(
    input logic [3:0] a,
    input logic [3:0] b,
    output logic equal
);
    logic [31:0] current_result, shift_add_result;
    fp4_multiplier_probe #(.IMPLEMENTATION(0)) u_current (
        .a, .b, .result(current_result)
    );
    fp4_multiplier_probe #(.IMPLEMENTATION(1)) u_shift_add (
        .a, .b, .result(shift_add_result)
    );
    assign equal = current_result == shift_add_result;
endmodule
