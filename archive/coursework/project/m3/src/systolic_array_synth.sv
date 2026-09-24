// Synthesis wrapper for systolic_array -- flattens unpacked array ports
// for yosys compatibility

module systolic_array_synth #(
    parameter int SIZE  = 4,
    parameter int D_HEAD = 4,
    parameter int WIDTH = 4,
    parameter int ACC_W = 32
)(
    input  logic clk,
    input  logic rst_n,
    input  logic [WIDTH*SIZE-1:0] a_in_flat,
    input  logic [WIDTH*SIZE-1:0] b_in_flat,
    input  logic valid_in,
    output logic [ACC_W*SIZE*SIZE-1:0] result_flat,
    output logic result_valid
);
    logic [WIDTH-1:0] a_in [SIZE];
    logic [WIDTH-1:0] b_in [SIZE];
    logic [ACC_W-1:0] result [SIZE][SIZE];

    genvar i, j;
    generate
        for (i = 0; i < SIZE; i++) begin : gen_unpack
            assign a_in[i] = a_in_flat[i*WIDTH +: WIDTH];
            assign b_in[i] = b_in_flat[i*WIDTH +: WIDTH];
        end
        for (i = 0; i < SIZE; i++) begin : gen_pack_i
            for (j = 0; j < SIZE; j++) begin : gen_pack_j
                assign result_flat[(i*SIZE+j)*ACC_W +: ACC_W] = result[i][j];
            end
        end
    endgenerate

    systolic_array #(
        .SIZE(SIZE), .D_HEAD(D_HEAD), .WIDTH(WIDTH), .ACC_W(ACC_W)
    ) u_array (
        .clk(clk), .rst_n(rst_n),
        .a_in(a_in), .b_in(b_in),
        .valid_in(valid_in),
        .result(result),
        .result_valid(result_valid)
    );
endmodule
