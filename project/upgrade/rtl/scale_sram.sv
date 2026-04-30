/*
 * scale_sram.sv -- On-chip SRAM for FP4 microscaling factors
 *
 * Stores S_Q (per Q row) and S_K (per K column) FP32 scale factors
 * for FP4 E2M1 microscaling dequantization.
 *
 * Memory layout:
 *   Address 0         to T_MAX-1:   S_Q[0..T_MAX-1] -- Q row scale factors
 *   Address T_MAX     to 2*T_MAX-1: S_K[0..T_MAX-1] -- K col scale factors
 *
 * Write port: single write port (host loads scale factors before compute)
 * Read port:  two independent read ports (tiling controller reads S_Q and
 *             S_K simultaneously during dequantization)
 *
 * Clock domain: single clock (clk), rising-edge triggered
 * Reset: active-low synchronous (rst_n) -- clears all entries to 1.0
 *        (1.0 = 0x3F800000 means no scaling -- identity scale factor)
 *
 * Ports:
 *   clk         input  1-bit          system clock
 *   rst_n       input  1-bit          active-low synchronous reset
 *
 *   wr_en       input  1-bit          write enable
 *   wr_addr     input  ADDR_W-bit     write address (0 to 2*T_MAX-1)
 *   wr_data     input  32-bit         FP32 scale factor to write
 *
 *   rd_addr_q   input  ADDR_W-1-bit   read address for S_Q (0 to T_MAX-1)
 *   rd_data_q   output 32-bit         S_Q[rd_addr_q] -- Q row scale factor
 *
 *   rd_addr_k   input  ADDR_W-1-bit   read address for S_K (0 to T_MAX-1)
 *   rd_data_k   output 32-bit         S_K[rd_addr_k] -- K col scale factor
 *
 * Debug: compile with -DDEBUG_SRAM for $display traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module scale_sram #(
    parameter int T_MAX  = 512,             // max sequence length
    parameter int ADDR_W = $clog2(T_MAX)+1  // address width (extra bit for S_Q vs S_K)
)(
    input  logic              clk,
    input  logic              rst_n,

    // Write port -- host loads scale factors
    input  logic              wr_en,
    input  logic [ADDR_W-1:0] wr_addr,   // bit[ADDR_W-1]=0 -> S_Q, 1 -> S_K
    input  logic [31:0]       wr_data,   // FP32 scale factor

    // Read port A -- S_Q[row_i], read by tiling controller
    input  logic [ADDR_W-2:0] rd_addr_q,
    output logic [31:0]       rd_data_q,

    // Read port B -- S_K[col_j], read by tiling controller
    input  logic [ADDR_W-2:0] rd_addr_k,
    output logic [31:0]       rd_data_k
);

    // -----------------------------------------------------------------------
    // Two separate SRAM arrays -- S_Q and S_K
    // Reset to 1.0 (0x3F800000) = identity scale (no scaling)
    // -----------------------------------------------------------------------
    logic [31:0] sq_mem [0:T_MAX-1];  // S_Q scale factors
    logic [31:0] sk_mem [0:T_MAX-1];  // S_K scale factors

    // -----------------------------------------------------------------------
    // Write port -- decode address MSB to select S_Q or S_K array
    // addr[ADDR_W-1] = 0 -> write S_Q
    // addr[ADDR_W-1] = 1 -> write S_K
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            for (int i = 0; i < T_MAX; i++) begin
                sq_mem[i] <= 32'h3F800000;  // 1.0 in FP32
                sk_mem[i] <= 32'h3F800000;  // 1.0 in FP32
            end
        end else begin
            if (wr_en) begin
                if (!wr_addr[ADDR_W-1]) begin
                    // Write to S_Q
                    sq_mem[wr_addr[ADDR_W-2:0]] <= wr_data;

                    `ifdef DEBUG_SRAM
                    $display("[SRAM] S_Q[%0d] = 0x%08h (%f) at t=%0t",
                             wr_addr[ADDR_W-2:0], wr_data, $bitstoreal({32'h0,wr_data}),
                             $time);
                    `endif
                end else begin
                    // Write to S_K
                    sk_mem[wr_addr[ADDR_W-2:0]] <= wr_data;

                    `ifdef DEBUG_SRAM
                    $display("[SRAM] S_K[%0d] = 0x%08h at t=%0t",
                             wr_addr[ADDR_W-2:0], wr_data, $time);
                    `endif
                end
            end
        end
    end

    // -----------------------------------------------------------------------
    // Read port A -- S_Q (synchronous read, 1-cycle latency)
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n)
            rd_data_q <= 32'h3F800000;
        else
            rd_data_q <= sq_mem[rd_addr_q];
    end

    // -----------------------------------------------------------------------
    // Read port B -- S_K (synchronous read, 1-cycle latency)
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n)
            rd_data_k <= 32'h3F800000;
        else
            rd_data_k <= sk_mem[rd_addr_k];
    end

endmodule
