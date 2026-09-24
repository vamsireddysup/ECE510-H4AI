/*
 * systolic_array.sv -- Parameterized FP4 Systolic Array for QK^T
 *
 * Instantiates a SIZE x SIZE grid of FP4 PE modules. Each PE computes
 * one element of the QK^T output score matrix using FP4 multiply and
 * FP32 accumulate. Data flows right (Q columns) and down (K^T columns).
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Input staggering:
 *   Column i of Q is delayed by i cycles before entering the left edge.
 *   Column j of K^T is delayed by j cycles before entering the top edge.
 *   This ensures matching elements meet at the correct PE at the correct cycle.
 *
 * Parameters:
 *   SIZE   (int) -- array dimension, default 16 (16x16 = 256 PEs)
 *   D_HEAD (int) -- dot product length (head dimension), default 64
 *   WIDTH  (int) -- FP4 input data width in bits, default 4
 *   ACC_W  (int) -- FP32 accumulator output width in bits, default 32
 *
 * Ports:
 *   clk          input  1-bit          system clock
 *   rst_n        input  1-bit          active-low synchronous reset
 *   a_in[SIZE]   input  WIDTH-bit      Q column elements, left edge, FP4
 *   b_in[SIZE]   input  WIDTH-bit      K^T column elements, top edge, FP4
 *   valid_in     input  1-bit          high when a_in and b_in are valid
 *   result[SIZE][SIZE] output ACC_W    FP32 output score matrix
 *   result_valid output 1-bit          high when PE[SIZE-1][SIZE-1] is done
 *
 * Debug: compile with -DDEBUG_PE for PE-level traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module systolic_array #(
    parameter int SIZE   = 16,   // array dimension (16x16)
    parameter int D_HEAD = 64,   // dot product length
    parameter int WIDTH  = 4,    // FP4 input width
    parameter int ACC_W  = 32    // FP32 accumulator output width
)(
    input  logic                    clk,
    input  logic                    rst_n,

    input  logic [WIDTH-1:0]        a_in [SIZE],   // Q column elements
    input  logic [WIDTH-1:0]        b_in [SIZE],   // K^T column elements
    input  logic                    valid_in,

    output logic [ACC_W-1:0]        result [SIZE][SIZE],
    output logic                    result_valid
);

    // -----------------------------------------------------------------------
    // Internal wire arrays
    // a_wire[i][j]: FP4 value between PE[i][j-1] and PE[i][j]
    // b_wire[i][j]: FP4 value between PE[i-1][j] and PE[i][j]
    // v_wire_a[i][j]: valid signal flowing right with a
    // v_wire_b[i][j]: valid signal flowing down with b
    // -----------------------------------------------------------------------
    logic [WIDTH-1:0] a_wire   [SIZE][SIZE+1];
    logic [WIDTH-1:0] b_wire   [SIZE+1][SIZE];
    logic             v_wire_a [SIZE][SIZE+1];

    // -----------------------------------------------------------------------
    // Stagger shift registers
    // a_stagger[i][d]: column i of Q delayed by d cycles
    // b_stagger[j][d]: column j of K^T delayed by d cycles
    // Row i of the array uses a_stagger[i][i] (delayed by i cycles)
    // Col j of the array uses b_stagger[j][j] (delayed by j cycles)
    // -----------------------------------------------------------------------
    logic [WIDTH-1:0] a_stagger   [SIZE][SIZE];
    logic [WIDTH-1:0] b_stagger   [SIZE][SIZE];
    logic             v_stagger_a [SIZE][SIZE];

    always_ff @(posedge clk) begin
        // A stagger: each row i is delayed by i cycles
        for (int i = 0; i < SIZE; i++) begin
            a_stagger[i][0]   <= a_in[i];
            v_stagger_a[i][0] <= valid_in;
            for (int d = 1; d < SIZE; d++) begin
                a_stagger[i][d]   <= a_stagger[i][d-1];
                v_stagger_a[i][d] <= v_stagger_a[i][d-1];
            end
        end

        // B stagger: each column j is delayed by j cycles
        for (int j = 0; j < SIZE; j++) begin
            b_stagger[j][0]   <= b_in[j];
            for (int d = 1; d < SIZE; d++) begin
                b_stagger[j][d]   <= b_stagger[j][d-1];
            end
        end
    end

    // -----------------------------------------------------------------------
    // Connect staggered inputs to left and top edges
    // -----------------------------------------------------------------------
    generate
        for (genvar i = 0; i < SIZE; i++) begin : gen_a_edge
            assign a_wire[i][0]   = a_stagger[i][i];
            assign v_wire_a[i][0] = v_stagger_a[i][i];
        end
        for (genvar j = 0; j < SIZE; j++) begin : gen_b_edge
            assign b_wire[0][j]   = b_stagger[j][j];
        end
    endgenerate

    // -----------------------------------------------------------------------
    // PE grid -- PE[i][j] at row i, column j
    // valid_in to each PE is AND of a valid and b valid
    // ensuring both inputs are properly staggered before compute starts
    // -----------------------------------------------------------------------
    logic pe_result_valid [SIZE][SIZE];

    generate
        for (genvar i = 0; i < SIZE; i++) begin : gen_row
            for (genvar j = 0; j < SIZE; j++) begin : gen_col
                pe #(
                    .D_HEAD (D_HEAD)
                ) u_pe (
                    .clk         (clk),
                    .rst_n       (rst_n),
                    .a_in        (a_wire[i][j]),
                    .b_in        (b_wire[i][j]),
                    .valid_in    (v_wire_a[i][j]),
                    .a_out       (a_wire[i][j+1]),
                    .b_out       (b_wire[i+1][j]),
                    .valid_out   (v_wire_a[i][j+1]),
                    .result      (result[i][j]),
                    .result_valid(pe_result_valid[i][j])
                );
            end
        end
    endgenerate

    // -----------------------------------------------------------------------
    // result_valid: PE[SIZE-1][SIZE-1] finishes last
    // -----------------------------------------------------------------------
    assign result_valid = pe_result_valid[SIZE-1][SIZE-1];

endmodule
