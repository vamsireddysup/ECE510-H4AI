/*
 * tile_buffer.sv -- On-chip tile buffers for QK^T tiled computation
 *
 * Updated: Q and K buffers now expose TILE_SIZE parallel read ports
 * (one per row) so the systolic array can be fed all rows simultaneously
 * each clock cycle. Output buffer retains single read port.
 *
 * Q read ports: q_rd_data[i] = q_buf[i][q_rd_col]  for i=0..TILE_SIZE-1
 * K read ports: k_rd_data[i] = k_buf[i][k_rd_col]  for i=0..TILE_SIZE-1
 *
 * Write ports unchanged (single port, one element per cycle).
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module tile_buffer #(
    parameter int TILE_SIZE = 16,
    parameter int D_HEAD    = 64
)(
    input  logic clk,
    input  logic rst_n,

    // Q tile write port
    input  logic                            q_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    q_wr_row,
    input  logic [$clog2(D_HEAD)-1:0]       q_wr_col,
    input  logic [3:0]                      q_wr_data,

    // Q tile parallel read ports (TILE_SIZE rows, one col address shared)
    input  logic [$clog2(D_HEAD)-1:0]       q_rd_col,
    output logic [3:0]                      q_rd_data [0:TILE_SIZE-1],

    // Legacy single read port (kept for tile_controller compatibility)
    input  logic [$clog2(TILE_SIZE)-1:0]    q_rd_row,
    output logic [3:0]                      q_rd_data_single,

    // K tile write port
    input  logic                            k_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    k_wr_row,
    input  logic [$clog2(D_HEAD)-1:0]       k_wr_col,
    input  logic [3:0]                      k_wr_data,

    // K tile parallel read ports
    input  logic [$clog2(D_HEAD)-1:0]       k_rd_col,
    output logic [3:0]                      k_rd_data [0:TILE_SIZE-1],

    // Legacy single read port
    input  logic [$clog2(TILE_SIZE)-1:0]    k_rd_row,
    output logic [3:0]                      k_rd_data_single,

    // Output tile write port
    input  logic                            out_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_wr_row,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_wr_col,
    input  logic [31:0]                     out_wr_data,

    // Output tile read port
    input  logic [$clog2(TILE_SIZE)-1:0]    out_rd_row,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_rd_col,
    output logic [31:0]                     out_rd_data
);

    // Q tile buffer
    logic [3:0] q_buf [0:TILE_SIZE-1][0:D_HEAD-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < D_HEAD; c++)
                    q_buf[r][c] <= 4'h0;
        end else if (q_wr_en) begin
            q_buf[q_wr_row][q_wr_col] <= q_wr_data;
        end
    end

    // Parallel read: all rows, shared column
    genvar qi;
    generate
        for (qi = 0; qi < TILE_SIZE; qi++) begin : q_rd_gen
            assign q_rd_data[qi] = q_buf[qi][q_rd_col];
        end
    endgenerate

    // Single read port (for tile_controller sequential access)
    assign q_rd_data_single = q_buf[q_rd_row][q_rd_col];

    // K tile buffer
    logic [3:0] k_buf [0:TILE_SIZE-1][0:D_HEAD-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < D_HEAD; c++)
                    k_buf[r][c] <= 4'h0;
        end else if (k_wr_en) begin
            k_buf[k_wr_row][k_wr_col] <= k_wr_data;
        end
    end

    genvar ki;
    generate
        for (ki = 0; ki < TILE_SIZE; ki++) begin : k_rd_gen
            assign k_rd_data[ki] = k_buf[ki][k_rd_col];
        end
    endgenerate

    assign k_rd_data_single = k_buf[k_rd_row][k_rd_col];

    // Output tile buffer
    logic [31:0] out_buf [0:TILE_SIZE-1][0:TILE_SIZE-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < TILE_SIZE; c++)
                    out_buf[r][c] <= 32'h0;
        end else if (out_wr_en) begin
            out_buf[out_wr_row][out_wr_col] <= out_wr_data;
        end
    end

    assign out_rd_data = out_buf[out_rd_row][out_rd_col];

endmodule
