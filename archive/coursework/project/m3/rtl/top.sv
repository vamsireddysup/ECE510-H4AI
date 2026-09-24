/*
 * qkt_chiplet_top.sv -- Top-level integration for FP4 QK^T Accelerator
 *
 * Instantiates: axi4_lite_ctrl, tile_controller, scale_sram, tile_buffer,
 *               systolic_array, fp32_mul. Connects them via internal signals.
 *
 * External port list:
 *   clk          input   1      System clock (rising edge triggered)
 *   rst_n        input   1      Active-low synchronous reset
 *
 *   -- AXI4-Lite slave (control plane)
 *   awvalid      input   1      Write address valid
 *   awready      output  1      Write address ready
 *   awaddr       input   32     Write address (byte addressed)
 *   wvalid       input   1      Write data valid
 *   wready       output  1      Write data ready
 *   wdata        input   32     Write data
 *   wstrb        input   4      Write byte strobes
 *   bvalid       output  1      Write response valid
 *   bready       input   1      Write response ready
 *   bresp        output  2      Write response (00=OKAY)
 *   arvalid      input   1      Read address valid
 *   arready      output  1      Read address ready
 *   araddr       input   32     Read address
 *   rvalid       output  1      Read data valid
 *   rready       input   1      Read data ready
 *   rdata        output  32     Read data
 *   rresp        output  2      Read response (00=OKAY)
 *
 *   -- AXI4-Stream slave (input: scale factors + FP4 Q/K tiles)
 *   s_tvalid     input   1      Input stream valid
 *   s_tready     output  1      Input stream ready (backpressure)
 *   s_tdata      input   64     Input stream data (packed FP4 or FP32)
 *   s_tlast      input   1      Input stream last beat marker
 *
 *   -- AXI4-Stream master (output: dequantized FP32 scores)
 *   m_tvalid     output  1      Output stream valid
 *   m_tready     input   1      Output stream ready
 *   m_tdata      output  64     Output stream data (FP32 score, upper 32 bits)
 *   m_tlast      output  1      Output stream last beat marker
 *
 * Glue logic: generate block connects tile_buffer parallel read ports
 *   (q_rd_data_par, k_rd_data_par) to systolic array arr_a_in/arr_b_in.
 *   No clock domain crossings. Single clock domain throughout.
 *
 * Parameters:
 *   TILE_SIZE    int    Systolic array dimension (default 4)
 *   D_HEAD       int    Dot product length (default 4)
 *   T_MAX        int    Max sequence length (default 16)
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

/* verilator lint_off UNUSEDSIGNAL */
/* verilator lint_off UNUSEDPARAM */

module qkt_chiplet_top #(
    parameter int TILE_SIZE = 4,
    parameter int D_HEAD    = 4,
    parameter int T_MAX     = 16
)(
    input  logic clk,
    input  logic rst_n,

    // AXI4-Lite slave
    input  logic        awvalid,
    output logic        awready,
    input  logic [31:0] awaddr,
    input  logic        wvalid,
    output logic        wready,
    input  logic [31:0] wdata,
    input  logic [3:0]  wstrb,
    output logic        bvalid,
    input  logic        bready,
    output logic [1:0]  bresp,
    input  logic        arvalid,
    output logic        arready,
    input  logic [31:0] araddr,
    output logic        rvalid,
    input  logic        rready,
    output logic [31:0] rdata,
    output logic [1:0]  rresp,

    // AXI4-Stream slave (input)
    input  logic        s_tvalid,
    output logic        s_tready,
    input  logic [63:0] s_tdata,
    input  logic        s_tlast,

    // AXI4-Stream master (output)
    output logic        m_tvalid,
    input  logic        m_tready,
    output logic [63:0] m_tdata,
    output logic        m_tlast
);

    // AXI4-Lite <-> tile_controller
    logic        ctrl_start;
    logic        ctrl_done;
    logic [31:0] ctrl_matrix_size;
    logic [31:0] ctrl_tile_count;
    logic [31:0] ctrl_cycle_count;
    logic [31:0] ctrl_tile_cycles;

    // tile_controller <-> scale_sram
    logic                        sq_wr_en;
    logic [$clog2(T_MAX):0]      sq_wr_addr;
    logic [31:0]                 sq_wr_data;
    logic [$clog2(T_MAX)-1:0]    sq_rd_addr;
    logic [31:0]                 sq_rd_data;
    logic [$clog2(T_MAX)-1:0]    sk_rd_addr;
    logic [31:0]                 sk_rd_data;

    // tile_controller <-> tile_buffer (Q write + single read)
    logic                            q_wr_en;
    logic [$clog2(TILE_SIZE)-1:0]    q_wr_row;
    logic [$clog2(D_HEAD)-1:0]       q_wr_col;
    logic [3:0]                      q_wr_data;
    logic [$clog2(TILE_SIZE)-1:0]    q_rd_row;
    logic [$clog2(D_HEAD)-1:0]       q_rd_col;
    logic [3:0]                      q_rd_data_single;

    // tile_controller <-> tile_buffer (K write + single read)
    logic                            k_wr_en;
    logic [$clog2(TILE_SIZE)-1:0]    k_wr_row;
    logic [$clog2(D_HEAD)-1:0]       k_wr_col;
    logic [3:0]                      k_wr_data;
    logic [$clog2(TILE_SIZE)-1:0]    k_rd_row;
    logic [$clog2(D_HEAD)-1:0]       k_rd_col;
    logic [3:0]                      k_rd_data_single;

    // tile_buffer parallel read ports -> systolic array
    logic [3:0]  q_rd_data_par [0:TILE_SIZE-1];
    logic [3:0]  k_rd_data_par [0:TILE_SIZE-1];

    // tile_controller <-> tile_buffer (output)
    logic                            out_wr_en;
    logic [$clog2(TILE_SIZE)-1:0]    out_wr_row;
    logic [$clog2(TILE_SIZE)-1:0]    out_wr_col;
    logic [31:0]                     out_wr_data;
    logic [$clog2(TILE_SIZE)-1:0]    out_rd_row;
    logic [$clog2(TILE_SIZE)-1:0]    out_rd_col;
    logic [31:0]                     out_rd_data;

    // tile_controller <-> systolic_array
    logic [3:0]  arr_a_in  [TILE_SIZE];
    logic [3:0]  arr_b_in  [TILE_SIZE];
    logic        arr_valid_in;
    logic [31:0] arr_result [TILE_SIZE][TILE_SIZE];
    logic        arr_result_valid;

    // tile_controller <-> fp32_mul
    logic [31:0] deq_a;
    logic [31:0] deq_b;
    logic        deq_valid;
    logic [31:0] deq_result;
    logic        deq_result_valid;

    // Connect parallel read ports to systolic array inputs
    // q_rd_col and k_rd_col are shared column addresses driven by tile_controller
    genvar gi;
    generate
        for (gi = 0; gi < TILE_SIZE; gi++) begin : gen_arr_in
            assign arr_a_in[gi] = q_rd_data_par[gi];
            assign arr_b_in[gi] = k_rd_data_par[gi];
        end
    endgenerate

    // AXI4-Lite control
    axi4_lite_ctrl u_ctrl (
        .clk(clk), .rst_n(rst_n),
        .awvalid(awvalid), .awready(awready), .awaddr(awaddr),
        .wvalid(wvalid),   .wready(wready),   .wdata(wdata), .wstrb(wstrb),
        .bvalid(bvalid),   .bready(bready),   .bresp(bresp),
        .arvalid(arvalid), .arready(arready), .araddr(araddr),
        .rvalid(rvalid),   .rready(rready),   .rdata(rdata), .rresp(rresp),
        .start(ctrl_start), .done(ctrl_done),
        .matrix_size(ctrl_matrix_size),
        .tile_count(ctrl_tile_count),
        .cycle_count(ctrl_cycle_count),
        .tile_cycles(ctrl_tile_cycles)
    );

    // Tile controller
    tile_controller #(
        .TILE_SIZE(TILE_SIZE), .D_HEAD(D_HEAD), .T_MAX(T_MAX)
    ) u_ctrl_tile (
        .clk(clk), .rst_n(rst_n),
        .start(ctrl_start),
        .matrix_size(ctrl_matrix_size[$clog2(T_MAX)-1:0]),
        .done(ctrl_done),
        .tile_count(ctrl_tile_count),
        .cycle_count(ctrl_cycle_count),
        .tile_cycles(ctrl_tile_cycles),
        .s_tvalid(s_tvalid), .s_tready(s_tready),
        .s_tdata(s_tdata),   .s_tlast(s_tlast),
        .m_tvalid(m_tvalid), .m_tready(m_tready),
        .m_tdata(m_tdata),   .m_tlast(m_tlast),
        .sq_wr_en(sq_wr_en), .sq_wr_addr(sq_wr_addr), .sq_wr_data(sq_wr_data),
        .sq_rd_addr(sq_rd_addr), .sq_rd_data(sq_rd_data),
        .sk_rd_addr(sk_rd_addr), .sk_rd_data(sk_rd_data),
        .q_wr_en(q_wr_en), .q_wr_row(q_wr_row),
        .q_wr_col(q_wr_col), .q_wr_data(q_wr_data),
        .q_rd_row(q_rd_row), .q_rd_col(q_rd_col),
        .q_rd_data(q_rd_data_single),
        .k_wr_en(k_wr_en), .k_wr_row(k_wr_row),
        .k_wr_col(k_wr_col), .k_wr_data(k_wr_data),
        .k_rd_row(k_rd_row), .k_rd_col(k_rd_col),
        .k_rd_data(k_rd_data_single),
        .out_wr_en(out_wr_en), .out_wr_row(out_wr_row),
        .out_wr_col(out_wr_col), .out_wr_data(out_wr_data),
        .out_rd_row(out_rd_row), .out_rd_col(out_rd_col),
        .out_rd_data(out_rd_data),
        .arr_a_in(arr_a_in), .arr_b_in(arr_b_in),
        .arr_valid_in(arr_valid_in),
        .arr_result(arr_result), .arr_result_valid(arr_result_valid),
        .deq_a(deq_a), .deq_b(deq_b), .deq_valid(deq_valid),
        .deq_result(deq_result), .deq_result_valid(deq_result_valid)
    );

    // Scale SRAM
    scale_sram #(.T_MAX(T_MAX)) u_scale_sram (
        .clk(clk), .rst_n(rst_n),
        .wr_en(sq_wr_en), .wr_addr(sq_wr_addr), .wr_data(sq_wr_data),
        .rd_addr_q(sq_rd_addr), .rd_data_q(sq_rd_data),
        .rd_addr_k(sk_rd_addr), .rd_data_k(sk_rd_data)
    );

    // Tile buffer with parallel read ports
    tile_buffer #(.TILE_SIZE(TILE_SIZE), .D_HEAD(D_HEAD)) u_tile_buf (
        .clk(clk), .rst_n(rst_n),
        .q_wr_en(q_wr_en), .q_wr_row(q_wr_row),
        .q_wr_col(q_wr_col), .q_wr_data(q_wr_data),
        .q_rd_col(q_rd_col),
        .q_rd_data(q_rd_data_par),
        .q_rd_row(q_rd_row), .q_rd_data_single(q_rd_data_single),
        .k_wr_en(k_wr_en), .k_wr_row(k_wr_row),
        .k_wr_col(k_wr_col), .k_wr_data(k_wr_data),
        .k_rd_col(k_rd_col),
        .k_rd_data(k_rd_data_par),
        .k_rd_row(k_rd_row), .k_rd_data_single(k_rd_data_single),
        .out_wr_en(out_wr_en), .out_wr_row(out_wr_row),
        .out_wr_col(out_wr_col), .out_wr_data(out_wr_data),
        .out_rd_row(out_rd_row), .out_rd_col(out_rd_col),
        .out_rd_data(out_rd_data)
    );

    // Systolic array
    systolic_array #(
        .SIZE(TILE_SIZE), .D_HEAD(D_HEAD), .WIDTH(4), .ACC_W(32)
    ) u_array (
        .clk(clk), .rst_n(rst_n),
        .a_in(arr_a_in), .b_in(arr_b_in),
        .valid_in(arr_valid_in),
        .result(arr_result), .result_valid(arr_result_valid)
    );

    // FP32 multiplier for dequantization
    fp32_mul u_deq_mul (
        .clk(clk), .rst_n(rst_n),
        .a(deq_a), .b(deq_b),
        .valid_in(deq_valid),
        .result(deq_result), .valid_out(deq_result_valid)
    );

endmodule

/* verilator lint_on UNUSEDSIGNAL */
/* verilator lint_on UNUSEDPARAM */
