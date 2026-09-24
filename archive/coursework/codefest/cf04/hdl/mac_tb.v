/*
 * mac_tb.v -- Testbench for MAC module
 *
 * Test sequence:
 *   Cycles 1-3: a=3, b=4  -> out should be 12, 24, 36
 *   Assert rst             -> out should be 0
 *   Cycles 5-6: a=-5, b=2 -> out should be -10, -20
 */

`timescale 1ns/1ps

module mac_tb;

    logic        clk;
    logic        rst;
    logic signed [7:0]  a;
    logic signed [7:0]  b;
    logic signed [31:0] out;

    // Instantiate DUT
    mac dut (
        .clk (clk),
        .rst (rst),
        .a   (a),
        .b   (b),
        .out (out)
    );

    // Clock: 10ns period
    initial clk = 0;
    always #5 clk = ~clk;

    // Task to check output
    task check;
        input signed [31:0] expected;
        input [63:0] cycle;
        begin
            if (out === expected)
                $display("PASS cycle %0d: out = %0d", cycle, out);
            else
                $display("FAIL cycle %0d: out = %0d, expected = %0d",
                         cycle, out, expected);
        end
    endtask

    integer cycle_num;

    initial begin
        // Initialize
        rst = 1;
        a   = 0;
        b   = 0;
        cycle_num = 0;

        // Hold reset for 2 cycles
        @(posedge clk); #1;
        @(posedge clk); #1;
        rst = 0;

        // Cycles 1-3: a=3, b=4, expect 12, 24, 36
        a = 8'sd3;
        b = 8'sd4;

        @(posedge clk); #1; check(32'sd12,  1);
        @(posedge clk); #1; check(32'sd24,  2);
        @(posedge clk); #1; check(32'sd36,  3);

        // Assert reset -- out should go to 0
        rst = 1;
        @(posedge clk); #1; check(32'sd0, 4);
        rst = 0;

        // Cycles 5-6: a=-5, b=2, expect -10, -20
        a = -8'sd5;
        b =  8'sd2;

        @(posedge clk); #1; check(-32'sd10, 5);
        @(posedge clk); #1; check(-32'sd20, 6);

        $display("Testbench complete.");
        $finish;
    end

endmodule
