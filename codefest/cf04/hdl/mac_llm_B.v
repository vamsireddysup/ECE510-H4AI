module mac (
    input  logic               clk,
    input  logic               rst,      // Active-high synchronous reset
    input  logic signed [7:0]  a,
    input  logic signed [7:0]  b,
    output logic signed [31:0] out
);

    // Internal product signal
    logic signed [15:0] product;

    // Combinational multiply
    assign product = a * b;

    // Sequential accumulator with synchronous reset
    always_ff @(posedge clk) begin
        if (rst) begin
            out <= 32'sd0;
        end else begin
            out <= out + {{16{product[15]}}, product}; // Sign-extend to 32 bits
        end
    end

endmodule
