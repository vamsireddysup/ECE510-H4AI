/*
 * axi4_lite_ctrl.sv -- AXI4-Lite Control Interface for FP4 QK^T Chiplet
 *
 * Register map:
 *   0x00 CTRL         -- bit 0 = START (write 1 to begin computation)
 *   0x04 STATUS       -- bit 0 = DONE  (read 1 when computation complete)
 *   0x08 MATRIX_SIZE  -- configurable sequence length T (read/write)
 *   0x0C TILE_COUNT   -- number of tiles completed (read only)
 *   0x10 CYCLE_COUNT  -- total cycles since START (read only)
 *   0x14 TILE_CYCLES  -- cycles taken for last tile (read only)
 *   0x18 SCALE_FACTOR -- global scale factor override (read/write, future use)
 *
 * AXI4-Lite slave -- host is master, chiplet is slave.
 * Single clock domain (clk), active-low synchronous reset (rst_n).
 *
 * Write transaction (5-channel handshake):
 *   1. Host: awvalid=1, awaddr
 *   2. Slave: awready=1
 *   3. Host: wvalid=1, wdata, wstrb
 *   4. Slave: wready=1, writes register
 *   5. Slave: bvalid=1, bresp=OKAY
 *   6. Host: bready=1
 *
 * Read transaction:
 *   1. Host: arvalid=1, araddr
 *   2. Slave: arready=1
 *   3. Slave: rvalid=1, rdata, rresp=OKAY
 *   4. Host: rready=1
 *
 * Ports:
 *   clk          input  1-bit   system clock
 *   rst_n        input  1-bit   active-low synchronous reset
 *   awvalid      input  1-bit   write address valid
 *   awready      output 1-bit   write address ready
 *   awaddr       input  32-bit  write address
 *   wvalid       input  1-bit   write data valid
 *   wready       output 1-bit   write data ready
 *   wdata        input  32-bit  write data
 *   wstrb        input  4-bit   write byte strobes (unused, all bytes written)
 *   bvalid       output 1-bit   write response valid
 *   bready       input  1-bit   write response ready
 *   bresp        output 2-bit   write response (00=OKAY)
 *   arvalid      input  1-bit   read address valid
 *   arready      output 1-bit   read address ready
 *   araddr       input  32-bit  read address
 *   rvalid       output 1-bit   read data valid
 *   rready       input  1-bit   read data ready
 *   rdata        output 32-bit  read data
 *   rresp        output 2-bit   read response (00=OKAY)
 *   start        output 1-bit   pulse to tiling controller: begin computation
 *   done         input  1-bit   from tiling controller: computation complete
 *   matrix_size  output 32-bit  configurable T to tiling controller
 *   tile_count   input  32-bit  profiling: tiles completed
 *   cycle_count  input  32-bit  profiling: total cycles
 *   tile_cycles  input  32-bit  profiling: last tile cycles
 *
 * Debug: compile with -DDEBUG_AXI for transaction traces
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module axi4_lite_ctrl (
    input  logic        clk,
    input  logic        rst_n,

    // AXI4-Lite Write Address Channel
    input  logic        awvalid,
    output logic        awready,
    input  logic [31:0] awaddr,

    // AXI4-Lite Write Data Channel
    input  logic        wvalid,
    output logic        wready,
    input  logic [31:0] wdata,
    /* verilator lint_off UNUSEDSIGNAL */
    input  logic [3:0]  wstrb,
    /* verilator lint_on UNUSEDSIGNAL */

    // AXI4-Lite Write Response Channel
    output logic        bvalid,
    input  logic        bready,
    output logic [1:0]  bresp,

    // AXI4-Lite Read Address Channel
    input  logic        arvalid,
    output logic        arready,
    input  logic [31:0] araddr,

    // AXI4-Lite Read Data Channel
    output logic        rvalid,
    input  logic        rready,
    output logic [31:0] rdata,
    output logic [1:0]  rresp,

    // Control signals to tiling controller
    output logic        start,
    input  logic        done,
    output logic [31:0] matrix_size,

    // Profiling inputs from tiling controller
    input  logic [31:0] tile_count,
    input  logic [31:0] cycle_count,
    input  logic [31:0] tile_cycles
);

    // -----------------------------------------------------------------------
    // Internal registers
    // -----------------------------------------------------------------------
    logic [31:0] ctrl_reg;         // 0x00 -- bit 0 = START
    logic [31:0] status_reg;       // 0x04 -- bit 0 = DONE (read only)
    logic [31:0] matrix_size_reg;  // 0x08 -- configurable T
    logic [31:0] scale_factor_reg; // 0x18 -- future microscaling

    assign status_reg  = {31'h0, done};
    assign start       = ctrl_reg[0];
    assign matrix_size = matrix_size_reg;

    // -----------------------------------------------------------------------
    // Write state machine -- identical to M2, extended register map
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        W_IDLE = 2'b00,
        W_ADDR = 2'b01,
        W_DATA = 2'b10,
        W_RESP = 2'b11
    } wstate_t;

    wstate_t     wstate;
    logic [31:0] waddr_lat;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            wstate          <= W_IDLE;
            awready         <= 1'b0;
            wready          <= 1'b0;
            bvalid          <= 1'b0;
            bresp           <= 2'b00;
            waddr_lat       <= 32'h0;
            ctrl_reg        <= 32'h0;
            matrix_size_reg <= 32'd512;    // default T=512
            scale_factor_reg<= 32'h3F800000; // default 1.0
        end else begin
            awready <= 1'b0;
            wready  <= 1'b0;

            // Clear START after one cycle
            if (ctrl_reg[0])
                ctrl_reg[0] <= 1'b0;

            case (wstate)

                W_IDLE: begin
                    bvalid <= 1'b0;
                    if (awvalid) begin
                        waddr_lat <= awaddr;
                        awready   <= 1'b1;
                        wstate    <= W_DATA;
                        `ifdef DEBUG_AXI
                        $display("[AXI-W] ADDR: 0x%08h at t=%0t", awaddr, $time);
                        `endif
                    end
                end

                W_DATA: begin
                    awready <= 1'b0;
                    if (wvalid) begin
                        wready <= 1'b1;
                        case (waddr_lat)
                            32'h00: begin
                                ctrl_reg <= wdata;
                                `ifdef DEBUG_AXI
                                $display("[AXI-W] CTRL=0x%08h at t=%0t",
                                         wdata, $time);
                                `endif
                            end
                            32'h08: begin
                                matrix_size_reg <= wdata;
                                `ifdef DEBUG_AXI
                                $display("[AXI-W] MATRIX_SIZE=%0d at t=%0t",
                                         wdata, $time);
                                `endif
                            end
                            32'h18: begin
                                scale_factor_reg <= wdata;
                                `ifdef DEBUG_AXI
                                $display("[AXI-W] SCALE_FACTOR=0x%08h at t=%0t",
                                         wdata, $time);
                                `endif
                            end
                            default: begin
                                `ifdef DEBUG_AXI
                                $display("[AXI-W] Unknown addr 0x%08h at t=%0t",
                                         waddr_lat, $time);
                                `endif
                            end
                        endcase
                        wstate <= W_RESP;
                    end
                end

                W_RESP: begin
                    wready <= 1'b0;
                    bvalid <= 1'b1;
                    bresp  <= 2'b00;
                    if (bready) begin
                        bvalid <= 1'b0;
                        wstate <= W_IDLE;
                        `ifdef DEBUG_AXI
                        $display("[AXI-W] Response accepted at t=%0t", $time);
                        `endif
                    end
                end

                default: wstate <= W_IDLE;
            endcase
        end
    end

    // -----------------------------------------------------------------------
    // Read state machine -- extended register map
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        R_IDLE = 2'b00,
        R_ADDR = 2'b01,
        R_DATA = 2'b10
    } rstate_t;

    rstate_t     rstate;
    logic [31:0] raddr_lat;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            rstate    <= R_IDLE;
            arready   <= 1'b0;
            rvalid    <= 1'b0;
            rdata     <= 32'h0;
            rresp     <= 2'b00;
            raddr_lat <= 32'h0;
        end else begin
            arready <= 1'b0;

            case (rstate)

                R_IDLE: begin
                    rvalid <= 1'b0;
                    if (arvalid) begin
                        raddr_lat <= araddr;
                        arready   <= 1'b1;
                        rstate    <= R_DATA;
                        `ifdef DEBUG_AXI
                        $display("[AXI-R] ADDR: 0x%08h at t=%0t", araddr, $time);
                        `endif
                    end
                end

                R_DATA: begin
                    arready <= 1'b0;
                    rvalid  <= 1'b1;
                    rresp   <= 2'b00;
                    case (raddr_lat)
                        32'h00: rdata <= ctrl_reg;
                        32'h04: rdata <= status_reg;
                        32'h08: rdata <= matrix_size_reg;
                        32'h0C: rdata <= tile_count;
                        32'h10: rdata <= cycle_count;
                        32'h14: rdata <= tile_cycles;
                        32'h18: rdata <= scale_factor_reg;
                        default: rdata <= 32'hDEADBEEF;
                    endcase
                    `ifdef DEBUG_AXI
                    $display("[AXI-R] DATA=0x%08h addr=0x%08h at t=%0t",
                             rdata, raddr_lat, $time);
                    `endif
                    if (rready) begin
                        rvalid <= 1'b0;
                        rstate <= R_IDLE;
                        `ifdef DEBUG_AXI
                        $display("[AXI-R] Response accepted at t=%0t", $time);
                        `endif
                    end
                end

                default: rstate <= R_IDLE;
            endcase
        end
    end

endmodule
