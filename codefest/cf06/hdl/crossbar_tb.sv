/*
 * crossbar_tb.sv -- Testbench for 4x4 binary-weight crossbar MAC
 *
 * Weights: [[1,-1,1,-1],[1,1,-1,-1],[-1,1,1,-1],[-1,-1,-1,1]]
 * Input:   [10, 20, 30, 40]
 *
 * Hand-calculated expected:
 *   out[0] = 1*10 + 1*20 + (-1)*30 + (-1)*40 = -40
 *   out[1] = (-1)*10 + 1*20 + 1*30 + (-1)*40 = 0
 *   out[2] = 1*10 + (-1)*20 + 1*30 + (-1)*40 = -20
 *   out[3] = (-1)*10 + (-1)*20 + (-1)*30 + 1*40 = -20
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

`timescale 1ns/1ps

module crossbar_tb;

    logic                clk, rst_n;
    logic signed [7:0]   in0, in1, in2, in3;
    logic                wr_en;
    logic [1:0]          wr_row, wr_col;
    logic                wr_weight;
    logic signed [31:0]  out0, out1, out2, out3;
    logic                valid;

    crossbar_mac dut (
        .clk(clk), .rst_n(rst_n),
        .in0(in0), .in1(in1), .in2(in2), .in3(in3),
        .wr_en(wr_en), .wr_row(wr_row), .wr_col(wr_col),
        .wr_weight(wr_weight),
        .out0(out0), .out1(out1), .out2(out2), .out3(out3),
        .valid(valid)
    );

    initial clk = 0;
    always #5 clk = ~clk;

    // Task to write one weight
    task write_weight(input [1:0] row, input [1:0] col, input w);
        @(negedge clk);
        wr_en=1; wr_row=row; wr_col=col; wr_weight=w;
    endtask

    integer pass_count, fail_count;

    initial begin
        rst_n=0; wr_en=0; wr_row=0; wr_col=0; wr_weight=0;
        in0=0; in1=0; in2=0; in3=0;
        pass_count=0; fail_count=0;

        repeat(4) @(posedge clk); #1;
        rst_n=1;
        @(posedge clk);

        // ------------------------------------------------------------
        // Load weights row by row
        // Row 0: [+1,-1,+1,-1] -> cols 0,1,2,3
        // Row 1: [+1,+1,-1,-1]
        // Row 2: [-1,+1,+1,-1]
        // Row 3: [-1,-1,-1,+1]
        // ------------------------------------------------------------
        $display("Loading weight matrix...");
        write_weight(0,0,1); @(posedge clk);
        write_weight(0,1,0); @(posedge clk);
        write_weight(0,2,1); @(posedge clk);
        write_weight(0,3,0); @(posedge clk);
        write_weight(1,0,1); @(posedge clk);
        write_weight(1,1,1); @(posedge clk);
        write_weight(1,2,0); @(posedge clk);
        write_weight(1,3,0); @(posedge clk);
        write_weight(2,0,0); @(posedge clk);
        write_weight(2,1,1); @(posedge clk);
        write_weight(2,2,1); @(posedge clk);
        write_weight(2,3,0); @(posedge clk);
        write_weight(3,0,0); @(posedge clk);
        write_weight(3,1,0); @(posedge clk);
        write_weight(3,2,0); @(posedge clk);
        write_weight(3,3,1); @(posedge clk);

        @(negedge clk); wr_en=0;

        // Apply input [10,20,30,40]
        @(negedge clk);
        $display("Applying input [10, 20, 30, 40]...");
        in0=8'sd10; in1=8'sd20; in2=8'sd30; in3=8'sd40;

        // Wait 2 cycles for MAC output
        repeat(2) @(posedge clk); #1;

        // Verify
        $display("");
        $display("--- Output verification ---");
        $display("Hand-calculated: out=[-40, 0, -20, -20]");
        $display("");

        if (out0 === -32'sd40) begin
            $display("out[0] = %0d (expected -40) PASS", out0);
            pass_count = pass_count + 1;
        end else begin
            $display("out[0] = %0d (expected -40) FAIL", out0);
            fail_count = fail_count + 1;
        end

        if (out1 === 32'sd0) begin
            $display("out[1] = %0d (expected 0) PASS", out1);
            pass_count = pass_count + 1;
        end else begin
            $display("out[1] = %0d (expected 0) FAIL", out1);
            fail_count = fail_count + 1;
        end

        if (out2 === -32'sd20) begin
            $display("out[2] = %0d (expected -20) PASS", out2);
            pass_count = pass_count + 1;
        end else begin
            $display("out[2] = %0d (expected -20) FAIL", out2);
            fail_count = fail_count + 1;
        end

        if (out3 === -32'sd20) begin
            $display("out[3] = %0d (expected -20) PASS", out3);
            pass_count = pass_count + 1;
        end else begin
            $display("out[3] = %0d (expected -20) FAIL", out3);
            fail_count = fail_count + 1;
        end

        $display("");
        $display("Results: %0d/4 outputs correct", pass_count);
        if (fail_count == 0)
            $display("ALL PASS -- crossbar MAC verified");
        else
            $display("FAIL -- %0d outputs incorrect", fail_count);

        $finish;
    end

    initial begin #100000; $display("TIMEOUT"); $finish; end

endmodule
