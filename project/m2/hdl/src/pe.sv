/*
 * pe.sv -- Synthesizable FP32 Processing Element for QK^T Systolic Array
 *
 * Uses fp32_mul.sv (3-cycle latency) and fp32_add.sv (1-cycle latency).
 *
 * Operation:
 *   COLLECT phase:    receive D_HEAD input pairs, store fp32_mul products
 *                     in prod_buf as they arrive (3 cycles after each input)
 *   ACCUMULATE phase: add prod_buf entries one at a time into acc,
 *                     waiting 1 cycle between each addition for acc to update
 *   DONE:             assert result_valid, hold result on output
 *
 * Debug: compile with +define+DEBUG_PE to enable $display traces
 *   verilator ... -DDEBUG_PE
 *
 * Author: Vamsidhar Reddy Eraganeni
 * Course: ECE 510 Spring 2026, Portland State University
 */

module pe #(
    parameter int D_HEAD = 4   // dot product length
)(
    input  logic        clk,
    input  logic        rst_n,
    input  logic [31:0] a_in,
    input  logic [31:0] b_in,
    input  logic        valid_in,

    output logic [31:0] a_out,
    output logic [31:0] b_out,
    output logic        valid_out,
    output logic [31:0] result,
    output logic        result_valid
);

    // -----------------------------------------------------------------------
    // Registered pass-throughs -- breaks combinational loops across PE grid
    // -----------------------------------------------------------------------
    always_ff @(posedge clk) begin
        if (!rst_n) begin
            a_out     <= 32'h0;
            b_out     <= 32'h0;
            valid_out <= 1'b0;
        end else begin
            a_out     <= a_in;
            b_out     <= b_in;
            valid_out <= valid_in;
        end
    end

    // -----------------------------------------------------------------------
    // FP32 Multiply: a_in * b_in -> product (3-cycle latency)
    // -----------------------------------------------------------------------
    logic [31:0] product;
    logic        product_valid;

    fp32_mul u_mul (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (a_in),
        .b         (b_in),
        .valid_in  (valid_in),
        .result    (product),
        .valid_out (product_valid)
    );

    // -----------------------------------------------------------------------
    // Product buffer -- stores D_HEAD products as they arrive from fp32_mul
    // -----------------------------------------------------------------------
    logic [31:0] prod_buf [0:D_HEAD-1];
    logic [31:0] prod_count;   // how many products collected so far
    logic        all_collected; // all D_HEAD products in prod_buf

    assign all_collected = (prod_count == 32'(D_HEAD));

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            prod_count <= 32'h0;
            for (int i = 0; i < D_HEAD; i++)
                prod_buf[i] <= 32'h0;
        end else begin
            if (product_valid && !all_collected) begin
                prod_buf[prod_count[($clog2(D_HEAD)-1):0]] <= product;
                prod_count <= prod_count + 32'h1;

                `ifdef DEBUG_PE
                $display("[PE COLLECT] cycle=%0t product[%0d]=0x%08h",
                         $time, prod_count, product);
                `endif
            end
        end
    end

    // -----------------------------------------------------------------------
    // FP32 Accumulator state machine
    // States: IDLE -> ACCUMULATE -> DONE
    //
    // In ACCUMULATE: feed one product per cycle into fp32_add,
    // wait for add_valid before feeding the next one.
    // fp32_add has 1-cycle latency so each addition takes exactly 2 cycles:
    //   cycle N:   present prod_buf[i] to adder, assert acc_valid_in
    //   cycle N+1: add_valid fires, acc updates, move to prod_buf[i+1]
    // -----------------------------------------------------------------------
    typedef enum logic [1:0] {
        IDLE        = 2'b00,
        ACCUMULATE  = 2'b01,
        DONE        = 2'b10
    } acc_state_t;

    acc_state_t  acc_state;
    logic [31:0] add_idx;       // index into prod_buf during accumulation
    logic [31:0] acc;           // running sum
    logic        acc_valid_in;  // strobe to fp32_add
    logic [31:0] add_result;    // fp32_add output
    logic        add_valid;     // fp32_add valid_out
    logic        waiting;       // waiting for add_valid to return

    // fp32_add instance
    fp32_add u_add (
        .clk       (clk),
        .rst_n     (rst_n),
        .a         (acc),
        .b         (prod_buf[add_idx[($clog2(D_HEAD)-1):0]]),
        .valid_in  (acc_valid_in),
        .result    (add_result),
        .valid_out (add_valid)
    );

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            acc_state    <= IDLE;
            add_idx      <= 32'h0;
            acc          <= 32'h0;
            acc_valid_in <= 1'b0;
            result_valid <= 1'b0;
            waiting      <= 1'b0;
        end else begin
            // Default -- deassert strobe each cycle unless set below
            acc_valid_in <= 1'b0;

            case (acc_state)

                IDLE: begin
                    // Wait until all products are collected
                    if (all_collected) begin
                        acc_state    <= ACCUMULATE;
                        add_idx      <= 32'h0;
                        acc          <= 32'h0;
                        waiting      <= 1'b0;
                        acc_valid_in <= 1'b1;  // start first addition

                        `ifdef DEBUG_PE
                        $display("[PE ACC] Starting accumulation at t=%0t", $time);
                        `endif
                    end
                end

                ACCUMULATE: begin
                    if (!waiting) begin
                        // Strobe already sent -- now wait for add_valid
                        waiting <= 1'b1;
                    end

                    if (add_valid) begin
                        // Addition complete -- update acc
                        acc     <= add_result;
                        waiting <= 1'b0;

                        `ifdef DEBUG_PE
                        $display("[PE ACC] add[%0d] done: acc=0x%08h at t=%0t",
                                 add_idx, add_result, $time);
                        `endif

                        if (add_idx == 32'(D_HEAD - 1)) begin
                            // All products accumulated
                            acc_state    <= DONE;
                            result_valid <= 1'b1;

                            `ifdef DEBUG_PE
                            $display("[PE ACC] DONE: result=0x%08h at t=%0t",
                                     add_result, $time);
                            `endif
                        end else begin
                            // Move to next product
                            add_idx      <= add_idx + 32'h1;
                            acc_valid_in <= 1'b1;  // strobe next addition
                        end
                    end
                end

                DONE: begin
                    // Hold result_valid until reset
                    result_valid <= 1'b1;
                end

                default: acc_state <= IDLE;

            endcase
        end
    end

    assign result = acc;

    // -----------------------------------------------------------------------
    // Debug: print final result when result_valid fires
    // -----------------------------------------------------------------------
    `ifdef DEBUG_PE
    always_ff @(posedge clk) begin
        if (result_valid && acc_state == DONE)
            $display("[PE RESULT] result=0x%08h (%0d) at t=%0t",
                     result, result, $time);
    end
    `endif

endmodule
