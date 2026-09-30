// SPDX-License-Identifier: Apache-2.0
// Copyright 2026 Vamsidhar Reddy Eraganeni
// Gate-level testbench whose only job is switching activity for power.
//
// It drives one complete protocol-version-5 command through the routed netlist
// and dumps a VCD that OpenSTA annotates with read_power_activities. Numerical
// correctness is proved by tb/integration/tb_qkt_chiplet.cpp, not here; this
// checks only that the command completes and the expected beats move, because a
// command that stalled would give a misleadingly low power figure.
`timescale 1ns / 1ps
`default_nettype none

module tb_gate_power;
    localparam real PERIOD = 40.0;

    reg clk = 1'b0;
    reg rst_n = 1'b0;
    always #(PERIOD / 2.0) clk = ~clk;

    reg awvalid = 1'b0, wvalid = 1'b0, bready = 1'b1;
    reg arvalid = 1'b0, rready = 1'b1;
    reg [31:0] awaddr = 32'h0, wdata = 32'h0, araddr = 32'h0;
    reg [3:0] wstrb = 4'hF;
    reg s_tvalid = 1'b0, s_tlast = 1'b0;
    reg [63:0] s_tdata = 64'h0;
    reg m_tready = 1'b1;
    wire awready, wready, bvalid, arready, rvalid, s_tready, m_tvalid, m_tlast;
    wire [1:0] bresp, rresp;
    wire [31:0] rdata;
    wire [63:0] m_tdata;

`include "stimulus.vh"

    qkt_chiplet_top dut (
        .clk(clk), .rst_n(rst_n),
        .awvalid(awvalid), .awready(awready), .awaddr(awaddr),
        .wvalid(wvalid), .wready(wready), .wdata(wdata), .wstrb(wstrb),
        .bvalid(bvalid), .bready(bready), .bresp(bresp),
        .arvalid(arvalid), .arready(arready), .araddr(araddr),
        .rvalid(rvalid), .rready(rready), .rdata(rdata), .rresp(rresp),
        .s_tvalid(s_tvalid), .s_tready(s_tready), .s_tdata(s_tdata),
        .s_tlast(s_tlast),
        .m_tvalid(m_tvalid), .m_tready(m_tready), .m_tdata(m_tdata),
        .m_tlast(m_tlast)
    );

    integer accepted_in = 0;
    integer accepted_out = 0;
    always @(posedge clk) begin
        if (s_tvalid && s_tready) accepted_in = accepted_in + 1;
        if (m_tvalid && m_tready) accepted_out = accepted_out + 1;
    end

    task axi_write(input [31:0] address, input [31:0] value);
        begin
            @(posedge clk);
            awaddr <= address; awvalid <= 1'b1;
            wdata <= value; wvalid <= 1'b1;
            wait (awready && wready);
            @(posedge clk);
            awvalid <= 1'b0; wvalid <= 1'b0;
            wait (bvalid);
            @(posedge clk);
        end
    endtask

    integer beat;
    integer guard;
    initial begin
        $dumpfile("power.vcd");
        // Depth 0 records every level, which is what activity annotation needs.
        $dumpvars(0, tb_gate_power);

        repeat (6) @(posedge clk);
        rst_n <= 1'b1;
        repeat (4) @(posedge clk);

        axi_write(32'h08, STIM_SEQ);   // MATRIX_SIZE
        axi_write(32'h00, 32'h1);      // START

        for (beat = 0; beat < STIM_BEATS; beat = beat + 1) begin
            @(posedge clk);
            s_tdata <= stim_data[beat];
            s_tlast <= stim_last[beat];
            s_tvalid <= 1'b1;
            @(posedge clk);
            while (!s_tready) @(posedge clk);
            s_tvalid <= 1'b0;
            s_tlast <= 1'b0;
        end
        s_tvalid <= 1'b0;

        guard = 0;
        while (accepted_out < STIM_OUTPUT_BEATS && guard < 2000000) begin
            @(posedge clk);
            guard = guard + 1;
        end

        if (accepted_in != STIM_BEATS) begin
            $display("FAIL: accepted %0d of %0d input beats",
                     accepted_in, STIM_BEATS);
            $fatal(1);
        end
        if (accepted_out != STIM_OUTPUT_BEATS) begin
            $display("FAIL: accepted %0d of %0d output beats",
                     accepted_out, STIM_OUTPUT_BEATS);
            $fatal(1);
        end
        $display("PASS: %0d input beats, %0d output beats",
                 accepted_in, accepted_out);
        repeat (20) @(posedge clk);
        $finish;
    end
endmodule

`default_nettype wire
