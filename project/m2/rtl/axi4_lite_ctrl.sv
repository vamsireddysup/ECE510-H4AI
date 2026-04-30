/*
 * axi4_lite_ctrl.sv -- AXI4-Lite Control Interface for QK^T Chiplet
 *
 * Register map:
 *   0x00 CTRL   -- bit 0 = START (write 1 to begin computation)
 *   0x04 STATUS -- bit 0 = DONE  (read 1 when computation complete)
 *
 * AXI4-Lite slave -- host is master, chiplet is slave.
 *
 * Write transaction sequence:
 *   1. Host asserts awvalid + awaddr
 *   2. Slave asserts awready (accepts address)
 *   3. Host asserts wvalid + wdata + wstrb
 *   4. Slave asserts wready (accepts data), writes register
 *   5. Slave asserts bvalid + bresp=0 (OK)
 *   6. Host asserts bready (acknowledges response)
 *
 * Read transaction sequence:
 *   1. Host asserts arvalid + araddr
 *   2. Slave asserts arready (accepts address)
 *   3. Slave asserts rvalid + rdata + rresp=0
 *   4. Host asserts rready (acknowledges data)
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

    // Control signals to compute core
    output logic        start,   // pulse high for one cycle to start computation
    input  logic        done     // high when computation is complete
);

    // -----------------------------------------------------------------------
    // Internal registers
    // -----------------------------------------------------------------------
    logic [31:0] ctrl_reg;    // address 0x00 -- bit 0 = START
    logic [31:0] status_reg;  // address 0x04 -- bit 0 = DONE

    // DONE comes from compute core
    always_comb status_reg = {31'h0, done};

    // START is bit 0 of ctrl_reg -- pulse for one cycle then clear
    assign start = ctrl_reg[0];

    // -----------------------------------------------------------------------
    // Write state machine
    // States: W_IDLE -> W_ADDR -> W_DATA -> W_RESP
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        W_IDLE = 2'b00,
        W_ADDR = 2'b01,
        W_DATA = 2'b10,
        W_RESP = 2'b11
    } wstate_t;

    wstate_t     wstate;
    logic [31:0] waddr_lat;  // latched write address

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            wstate   <= W_IDLE;
            awready  <= 1'b0;
            wready   <= 1'b0;
            bvalid   <= 1'b0;
            bresp    <= 2'b00;
            waddr_lat<= 32'h0;
            ctrl_reg <= 32'h0;
        end else begin
            // Default deassert
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
                        $display("[AXI-W] ADDR accepted: 0x%08h at t=%0t",
                                 awaddr, $time);
                        `endif
                    end
                end

                W_DATA: begin
                    awready <= 1'b0;
                    if (wvalid) begin
                        wready <= 1'b1;

                        // Write to register based on address
                        case (waddr_lat)
                            32'h00: begin
                                ctrl_reg <= wdata;
                                `ifdef DEBUG_AXI
                                $display("[AXI-W] CTRL write: 0x%08h at t=%0t",
                                         wdata, $time);
                                `endif
                            end
                            default: begin
                                // Ignore writes to unknown addresses
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
                    bresp  <= 2'b00;  // OKAY response

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
    // Read state machine
    // States: R_IDLE -> R_ADDR -> R_DATA
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        R_IDLE = 2'b00,
        R_ADDR = 2'b01,
        R_DATA = 2'b10
    } rstate_t;

    rstate_t     rstate;
    logic [31:0] raddr_lat;  // latched read address

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            rstate   <= R_IDLE;
            arready  <= 1'b0;
            rvalid   <= 1'b0;
            rdata    <= 32'h0;
            rresp    <= 2'b00;
            raddr_lat<= 32'h0;
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
                        $display("[AXI-R] ADDR accepted: 0x%08h at t=%0t",
                                 araddr, $time);
                        `endif
                    end
                end

                R_DATA: begin
                    arready <= 1'b0;
                    rvalid  <= 1'b1;
                    rresp   <= 2'b00;

                    // Read from register based on address
                    case (raddr_lat)
                        32'h00: rdata <= ctrl_reg;
                        32'h04: rdata <= status_reg;
                        default: rdata <= 32'hDEADBEEF;
                    endcase

                    `ifdef DEBUG_AXI
                    $display("[AXI-R] DATA sent: 0x%08h from addr 0x%08h at t=%0t",
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
