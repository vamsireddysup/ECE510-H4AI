/*
 * tile_buffer.sv -- On-chip tile buffers for QK^T tiled computation
 *
 * Holds three buffers:
 *   Q tile:   TILE_SIZE x D_HEAD FP4 values (current Q tile being processed)
 *   K tile:   TILE_SIZE x D_HEAD FP4 values (current K tile being processed)
 *   Out tile: TILE_SIZE x TILE_SIZE FP32 values (accumulated output scores)
 *
 * The tiling controller writes Q and K tiles from AXI4-Stream input,
 * feeds them to the systolic array, and reads back FP32 results into
 * the output tile buffer before dequantization and streaming out.
 *
 * All buffers use synchronous write, asynchronous read for low latency.
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n)
 *
 * Ports:
 *   clk              input  1-bit   system clock
 *   rst_n            input  1-bit   active-low synchronous reset
 *
 *   -- Q tile write port (from AXI4-Stream input)
 *   q_wr_en          input  1-bit   write enable
 *   q_wr_row         input  log2(TILE_SIZE)-bit  row index
 *   q_wr_col         input  log2(D_HEAD)-bit      column index
 *   q_wr_data        input  4-bit   FP4 value
 *
 *   -- Q tile read port (streaming to systolic array left edge)
 *   q_rd_row         input  log2(TILE_SIZE)-bit
 *   q_rd_col         input  log2(D_HEAD)-bit
 *   q_rd_data        output 4-bit   FP4 value
 *
 *   -- K tile write port (from AXI4-Stream input)
 *   k_wr_en          input  1-bit
 *   k_wr_row         input  log2(TILE_SIZE)-bit
 *   k_wr_col         input  log2(D_HEAD)-bit
 *   k_wr_data        input  4-bit
 *
 *   -- K tile read port (streaming to systolic array top edge)
 *   k_rd_row         input  log2(TILE_SIZE)-bit
 *   k_rd_col         input  log2(D_HEAD)-bit
 *   k_rd_data        output 4-bit
 *
 *   -- Output tile write port (from systolic array result)
 *   out_wr_en        input  1-bit
 *   out_wr_row       input  log2(TILE_SIZE)-bit
 *   out_wr_col       input  log2(TILE_SIZE)-bit
 *   out_wr_data      input  32-bit  FP32 result
 *
 *   -- Output tile read port (to dequantization and AXI4-Stream output)
 *   out_rd_row       input  log2(TILE_SIZE)-bit
 *   out_rd_col       input  log2(TILE_SIZE)-bit
 *   out_rd_data      output 32-bit  FP32 result
 *
 * Debug: compile with -DDEBUG_TBUF for $display traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module tile_buffer #(
    parameter int TILE_SIZE = 16,   // systolic array dimension
    parameter int D_HEAD    = 64    // dot product length
)(
    input  logic clk,
    input  logic rst_n,

    // Q tile -- FP4
    input  logic                            q_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    q_wr_row,
    input  logic [$clog2(D_HEAD)-1:0]       q_wr_col,
    input  logic [3:0]                      q_wr_data,
    input  logic [$clog2(TILE_SIZE)-1:0]    q_rd_row,
    input  logic [$clog2(D_HEAD)-1:0]       q_rd_col,
    output logic [3:0]                      q_rd_data,

    // K tile -- FP4
    input  logic                            k_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    k_wr_row,
    input  logic [$clog2(D_HEAD)-1:0]       k_wr_col,
    input  logic [3:0]                      k_wr_data,
    input  logic [$clog2(TILE_SIZE)-1:0]    k_rd_row,
    input  logic [$clog2(D_HEAD)-1:0]       k_rd_col,
    output logic [3:0]                      k_rd_data,

    // Output tile -- FP32
    input  logic                            out_wr_en,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_wr_row,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_wr_col,
    input  logic [31:0]                     out_wr_data,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_rd_row,
    input  logic [$clog2(TILE_SIZE)-1:0]    out_rd_col,
    output logic [31:0]                     out_rd_data
);

    // -----------------------------------------------------------------------
    // Q tile buffer: TILE_SIZE x D_HEAD x 4 bits
    // -----------------------------------------------------------------------
    logic [3:0] q_buf [0:TILE_SIZE-1][0:D_HEAD-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < D_HEAD; c++)
                    q_buf[r][c] <= 4'h0;
        end else if (q_wr_en) begin
            q_buf[q_wr_row][q_wr_col] <= q_wr_data;

            `ifdef DEBUG_TBUF
            $display("[TBUF] Q[%0d][%0d] = 0x%01h at t=%0t",
                     q_wr_row, q_wr_col, q_wr_data, $time);
            `endif
        end
    end

    // Asynchronous read
    assign q_rd_data = q_buf[q_rd_row][q_rd_col];

    // -----------------------------------------------------------------------
    // K tile buffer: TILE_SIZE x D_HEAD x 4 bits
    // -----------------------------------------------------------------------
    logic [3:0] k_buf [0:TILE_SIZE-1][0:D_HEAD-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < D_HEAD; c++)
                    k_buf[r][c] <= 4'h0;
        end else if (k_wr_en) begin
            k_buf[k_wr_row][k_wr_col] <= k_wr_data;

            `ifdef DEBUG_TBUF
            $display("[TBUF] K[%0d][%0d] = 0x%01h at t=%0t",
                     k_wr_row, k_wr_col, k_wr_data, $time);
            `endif
        end
    end

    assign k_rd_data = k_buf[k_rd_row][k_rd_col];

    // -----------------------------------------------------------------------
    // Output tile buffer: TILE_SIZE x TILE_SIZE x 32 bits (FP32)
    // -----------------------------------------------------------------------
    logic [31:0] out_buf [0:TILE_SIZE-1][0:TILE_SIZE-1];

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int r = 0; r < TILE_SIZE; r++)
                for (int c = 0; c < TILE_SIZE; c++)
                    out_buf[r][c] <= 32'h0;
        end else if (out_wr_en) begin
            out_buf[out_wr_row][out_wr_col] <= out_wr_data;

            `ifdef DEBUG_TBUF
            $display("[TBUF] OUT[%0d][%0d] = 0x%08h at t=%0t",
                     out_wr_row, out_wr_col, out_wr_data, $time);
            `endif
        end
    end

    assign out_rd_data = out_buf[out_rd_row][out_rd_col];

endmodule
