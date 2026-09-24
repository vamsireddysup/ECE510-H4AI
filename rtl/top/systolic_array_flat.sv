// systolic_array_flat.sv -- synthesis-friendly version with flat ports
// Replaces unpacked array ports with flat bit vectors for yosys compatibility

module systolic_array_flat #(
    parameter SIZE  = 4,
    parameter D_HEAD = 4,
    parameter WIDTH = 4,
    parameter ACC_W = 32
)(
    input  logic clk,
    input  logic rst_n,
    input  logic [WIDTH*SIZE-1:0]        a_in_flat,
    input  logic [WIDTH*SIZE-1:0]        b_in_flat,
    input  logic                         valid_in,
    output logic [ACC_W*SIZE*SIZE-1:0]   result_flat,
    output logic                         result_valid
);

    // Unpack flat inputs to arrays
    wire [WIDTH-1:0] a_in [0:SIZE-1];
    wire [WIDTH-1:0] b_in [0:SIZE-1];
    wire [ACC_W-1:0] result [0:SIZE-1][0:SIZE-1];

    genvar gi;
    generate
        for (gi = 0; gi < SIZE; gi++) begin : unpack
            assign a_in[gi] = a_in_flat[gi*WIDTH +: WIDTH];
            assign b_in[gi] = b_in_flat[gi*WIDTH +: WIDTH];
        end
    endgenerate

    // Pack outputs
    genvar ri, rj;
    generate
        for (ri = 0; ri < SIZE; ri++) begin : pack_i
            for (rj = 0; rj < SIZE; rj++) begin : pack_j
                assign result_flat[(ri*SIZE+rj)*ACC_W +: ACC_W] = result[ri][rj];
            end
        end
    endgenerate

    // Internal wires -- same as systolic_array.sv
    wire [WIDTH-1:0] a_wire   [0:SIZE-1][0:SIZE];
    wire [WIDTH-1:0] b_wire   [0:SIZE][0:SIZE-1];
    wire             v_wire_a [0:SIZE-1][0:SIZE];

    // Stagger registers
    reg [WIDTH-1:0] a_stagger   [0:SIZE-1][0:SIZE-1];
    reg [WIDTH-1:0] b_stagger   [0:SIZE-1][0:SIZE-1];
    reg             v_stagger_a [0:SIZE-1][0:SIZE-1];

    integer i, d;
    always @(posedge clk) begin
        for (i = 0; i < SIZE; i = i+1) begin
            a_stagger[i][0]   <= a_in[i];
            v_stagger_a[i][0] <= valid_in;
            for (d = 1; d < SIZE; d = d+1) begin
                a_stagger[i][d]   <= a_stagger[i][d-1];
                v_stagger_a[i][d] <= v_stagger_a[i][d-1];
            end
        end
        for (i = 0; i < SIZE; i = i+1) begin
            b_stagger[i][0] <= b_in[i];
            for (d = 1; d < SIZE; d = d+1)
                b_stagger[i][d] <= b_stagger[i][d-1];
        end
    end

    genvar si;
    generate
        for (si = 0; si < SIZE; si++) begin : gen_a_edge
            assign a_wire[si][0]   = a_stagger[si][si];
            assign v_wire_a[si][0] = v_stagger_a[si][si];
        end
        for (si = 0; si < SIZE; si++) begin : gen_b_edge
            assign b_wire[0][si] = b_stagger[si][si];
        end
    endgenerate

    wire pe_result_valid [0:SIZE-1][0:SIZE-1];

    genvar pei, pej;
    generate
        for (pei = 0; pei < SIZE; pei++) begin : gen_row
            for (pej = 0; pej < SIZE; pej++) begin : gen_col
                pe #(.D_HEAD(D_HEAD)) u_pe (
                    .clk(clk), .rst_n(rst_n),
                    .a_in(a_wire[pei][pej]),
                    .b_in(b_wire[pei][pej]),
                    .valid_in(v_wire_a[pei][pej]),
                    .a_out(a_wire[pei][pej+1]),
                    .b_out(b_wire[pei+1][pej]),
                    .valid_out(v_wire_a[pei][pej+1]),
                    .result(result[pei][pej]),
                    .result_valid(pe_result_valid[pei][pej])
                );
            end
        end
    endgenerate

    assign result_valid = pe_result_valid[SIZE-1][SIZE-1];

endmodule
