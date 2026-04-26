/*
 * qkt_core.sv -- Top-level QK^T Accelerator Compute Core
 *
 * This module is the top-level wrapper for the QK^T matrix multiply
 * accelerator chiplet. It instantiates the systolic array and exposes
 * clean FP32 data ports for connection to the AXI4-Stream interface.
 *
 * The compute core receives Q and K matrix elements streamed in row by
 * row, computes QK^T using the systolic array, and outputs the score
 * matrix elements.
 *
 * Interface: AXI4-Lite (control) + AXI4-Stream (data)
 * Precision: FP32 (IEEE 754 32-bit floating point)
 * Target: 8x8 systolic array, 250 MHz, 32 GFLOP/s
 *
 * Parameters:
 *   SIZE    -- systolic array dimension (default 8x8)
 *   WIDTH   -- data width in bits (32 for FP32)
 *   ACC_W   -- accumulator width (32 for FP32)
 *   T       -- sequence length (default 512)
 *   D_HEAD  -- head dimension (default 64)
 *
 * Ports:
 *   clk         -- system clock (250 MHz target)
 *   rst_n       -- active-low synchronous reset
 *   start       -- pulse high to begin computation
 *   done        -- high when result is ready
 *   a_in        -- Q row elements (FP32, one per PE row)
 *   b_in        -- K^T col elements (FP32, one per PE col)
 *   valid_in    -- high when a_in and b_in are valid
 *   result      -- output score matrix elements
 *   result_valid-- high when result is valid
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module qkt_core #(
    parameter int SIZE   = 8,    // systolic array dimension
    parameter int WIDTH  = 32,   // FP32 data width
    parameter int ACC_W  = 32,   // accumulator width
    parameter int T      = 512,  // sequence length
    parameter int D_HEAD = 64    // head dimension
)(
    input  logic                    clk,
    input  logic                    rst_n,

    // Control interface (driven by AXI4-Lite controller)
    input  logic                    start,
    output logic                    done,

    // Data interface (driven by AXI4-Stream controller)
    input  logic signed [WIDTH-1:0] a_in  [SIZE],  // Q row elements
    input  logic signed [WIDTH-1:0] b_in  [SIZE],  // K^T col elements
    input  logic                    valid_in,

    // Output
    output logic signed [ACC_W-1:0] result [SIZE][SIZE],
    output logic                    result_valid
);

    // -----------------------------------------------------------------------
    // Internal state machine
    // States: IDLE -> COMPUTING -> DONE
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        IDLE      = 2'b00,
        COMPUTING = 2'b01,
        DONE_ST   = 2'b10
    } state_t;

    state_t state;

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            state <= IDLE;
            done  <= 1'b0;
        end else begin
            case (state)
                IDLE: begin
                    done <= 1'b0;
                    if (start)
                        state <= COMPUTING;
                end
                COMPUTING: begin
                    if (result_valid) begin
                        state <= DONE_ST;
                        done  <= 1'b1;
                    end
                end
                DONE_ST: begin
                    done  <= 1'b0;
                    state <= IDLE;
                end
                default: state <= IDLE;
            endcase
        end
    end

    // -----------------------------------------------------------------------
    // Systolic array instantiation
    // -----------------------------------------------------------------------
    systolic_array #(
        .SIZE  (SIZE),
        .WIDTH (WIDTH),
        .ACC_W (ACC_W)
    ) u_systolic (
        .clk          (clk),
        .rst_n        (rst_n),
        .a_in         (a_in),
        .b_in         (b_in),
        .valid_in     (valid_in & (state == COMPUTING)),
        .result       (result),
        .result_valid (result_valid)
    );

endmodule
