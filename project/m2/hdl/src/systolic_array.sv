/*
 * systolic_array.sv -- 8x8 Systolic Array for QK^T Matrix Multiply
 *
 * Instantiates an 8x8 grid of PE modules. Each PE computes one element
 * of the output matrix. Data flows right (Q rows) and down (K^T columns).
 *
 * Input staggering: row i of Q is delayed by i cycles before entering
 * the left edge. Column j of K^T is delayed by j cycles before entering
 * the top edge. This ensures matching elements meet at the correct PE.
 *
 * Parameters:
 *   SIZE    -- array dimension (8x8)
 *   D_HEAD  -- dot product length (head dimension, default 64)
 *   WIDTH   -- data width in bits (16-bit fixed point)
 *   ACC_W   -- accumulator width (32-bit to avoid overflow)
 *
 * Ports:
 *   clk, rst_n       -- clock and active-low reset
 *   a_in[SIZE]       -- Q row elements entering left edge (one per row)
 *   b_in[SIZE]       -- K^T col elements entering top edge (one per col)
 *   valid_in         -- high when input data is valid this cycle
 *   result[SIZE][SIZE]  -- output matrix elements (one per PE)
 *   result_valid     -- high when all PEs have completed accumulation
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module systolic_array #(
    parameter int SIZE   = 8,    // array dimension
    //parameter int D_HEAD = 64,   // dot product length
    parameter int WIDTH  = 16,   // input data width
    parameter int ACC_W  = 32    // accumulator width
)(
    input  logic                          clk,
    input  logic                          rst_n,

    // Input edges
    input  logic signed [WIDTH-1:0]       a_in  [SIZE],  // Q row elements
    input  logic signed [WIDTH-1:0]       b_in  [SIZE],  // K^T col elements
    input  logic                          valid_in,

    // Output matrix
    output logic signed [ACC_W-1:0]       result [SIZE][SIZE],
    output logic                          result_valid
);

    // -----------------------------------------------------------------------
    // Internal wire arrays connecting PEs to their neighbors
    // a_wire[i][j] carries the a value between PE[i][j-1] and PE[i][j]
    // b_wire[i][j] carries the b value between PE[i-1][j] and PE[i][j]
    // -----------------------------------------------------------------------
    logic signed [WIDTH-1:0]  a_wire [SIZE][SIZE+1]; // +1 for left edge
    logic signed [WIDTH-1:0]  b_wire [SIZE+1][SIZE]; // +1 for top edge
    logic                     v_wire [SIZE][SIZE+1];
    //logic                     v_wire_b [SIZE+1][SIZE];

    // -----------------------------------------------------------------------
    // Staggered input shift registers
    // Row i of Q is delayed by i cycles
    // Col j of K^T is delayed by j cycles
    // -----------------------------------------------------------------------
    logic signed [WIDTH-1:0]  a_stagger [SIZE][SIZE]; // a_stagger[i][d]
    logic signed [WIDTH-1:0]  b_stagger [SIZE][SIZE]; // b_stagger[j][d]
    logic                     v_stagger_a [SIZE][SIZE];
    logic                     v_stagger_b [SIZE][SIZE];

    // Stage 0 of stagger is the raw input
    // Stage d is delayed by d cycles from the raw input

    always_ff @(posedge clk) begin
        for (int i = 0; i < SIZE; i++) begin
            // First stage: load from input
            if (i == 0) begin
                a_stagger[i][0] <= a_in[i];
                v_stagger_a[i][0] <= valid_in;
            end else begin
                a_stagger[i][0] <= a_in[i];
                v_stagger_a[i][0] <= valid_in;
            end

            // Subsequent stages: shift register delay
            for (int d = 1; d < SIZE; d++) begin
                a_stagger[i][d] <= a_stagger[i][d-1];
                v_stagger_a[i][d] <= v_stagger_a[i][d-1];
            end
        end

        for (int j = 0; j < SIZE; j++) begin
            b_stagger[j][0] <= b_in[j];
            v_stagger_b[j][0] <= valid_in;

            for (int d = 1; d < SIZE; d++) begin
                b_stagger[j][d] <= b_stagger[j][d-1];
                v_stagger_b[j][d] <= v_stagger_b[j][d-1];
            end
        end
    end

    // -----------------------------------------------------------------------
    // Connect staggered inputs to left and top edges of the array
    // Row i uses delay stage i (delayed by i cycles)
    // Col j uses delay stage j (delayed by j cycles)
    // -----------------------------------------------------------------------
    generate
        for (genvar i = 0; i < SIZE; i++) begin : gen_a_edge
            assign a_wire[i][0]   = a_stagger[i][i];
            assign v_wire[i][0]   = v_stagger_a[i][i];
        end
        for (genvar j = 0; j < SIZE; j++) begin : gen_b_edge
            assign b_wire[0][j]   = b_stagger[j][j];
            //assign v_wire_b[0][j] = v_stagger_b[j][j];
        end
    endgenerate

    // -----------------------------------------------------------------------
    // PE grid instantiation
    // PE[i][j] is at row i, column j
    // -----------------------------------------------------------------------
    logic pe_result_valid [SIZE][SIZE];

    generate
        for (genvar i = 0; i < SIZE; i++) begin : gen_row
            for (genvar j = 0; j < SIZE; j++) begin : gen_col
                pe u_pe (
                    .clk         (clk),
                    .rst_n       (rst_n),
                    .a_in        (a_wire[i][j]),
                    .b_in        (b_wire[i][j]),
                    .valid_in    (v_wire[i][j]),
                    .a_out       (a_wire[i][j+1]),
                    .b_out       (b_wire[i+1][j]),
                    .valid_out   (v_wire[i][j+1]),
                    .result      (result[i][j]),
                    .result_valid(pe_result_valid[i][j])
                );
            end
        end
    endgenerate

    // -----------------------------------------------------------------------
    // result_valid: high when all PEs have valid results
    // Use the last PE[SIZE-1][SIZE-1] as the indicator --
    // it is the last PE to finish
    // -----------------------------------------------------------------------
    assign result_valid = pe_result_valid[SIZE-1][SIZE-1];

endmodule
