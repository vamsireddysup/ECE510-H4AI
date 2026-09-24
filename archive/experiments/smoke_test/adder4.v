module adder4 (
    input  [3:0] a,
    input  [3:0] b,
    input        cin,
    output [3:0] sum,
    output       cout
);
    /* verilator lint_off WIDTHEXPAND */
    assign {cout, sum} = a + b + cin;
    /* verilator lint_on WIDTHEXPAND */
endmodule
