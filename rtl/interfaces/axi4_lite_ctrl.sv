// AXI4-Lite register slave for the packed QK^T engine.
module axi4_lite_ctrl (
    input logic clk, rst_n,
    input logic awvalid, output logic awready, input logic [31:0] awaddr,
    input logic wvalid, output logic wready, input logic [31:0] wdata,
    input logic [3:0] wstrb,
    output logic bvalid, input logic bready, output logic [1:0] bresp,
    input logic arvalid, output logic arready, input logic [31:0] araddr,
    output logic rvalid, input logic rready, output logic [31:0] rdata,
    output logic [1:0] rresp,
    output logic start, input logic done, output logic [31:0] matrix_size,
    input logic [31:0] tile_count, cycle_count, tile_cycles,
    input logic [3:0] error_code,
    input logic [31:0] protocol_version,
    input logic [31:0] input_beats, output_beats,
    input logic [31:0] input_stalls, output_stalls,
    input logic [31:0] compute_cycles, scale_cycles
);
    logic aw_pending, w_pending;
    logic [31:0] aw_hold, w_hold;
    logic [3:0] strb_hold;
    logic [31:0] scale_factor_reg;
    logic aw_fire, w_fire, write_commit;
    logic [31:0] write_addr, write_data;
    logic [3:0] write_strb;

    assign awready = !aw_pending && !bvalid;
    assign wready = !w_pending && !bvalid;
    assign aw_fire = awvalid && awready;
    assign w_fire = wvalid && wready;
    assign write_commit = !bvalid && (aw_pending || aw_fire) &&
                          (w_pending || w_fire);
    assign write_addr = aw_fire ? awaddr : aw_hold;
    assign write_data = w_fire ? wdata : w_hold;
    assign write_strb = w_fire ? wstrb : strb_hold;
    assign bresp = 2'b00;
    assign arready = !rvalid;
    assign rresp = 2'b00;

    function automatic logic [31:0] merge_bytes(
        input logic [31:0] old_value, new_value, input logic [3:0] strobes
    );
        logic [31:0] merged;
        merged = old_value;
        for (int byte_index = 0; byte_index < 4; byte_index++)
            if (strobes[byte_index])
                merged[byte_index*8 +: 8] = new_value[byte_index*8 +: 8];
        return merged;
    endfunction

    always_ff @(posedge clk) begin
        if (!rst_n) begin
            aw_pending <= 0;
            w_pending <= 0;
            aw_hold <= 0;
            w_hold <= 0;
            strb_hold <= 0;
            bvalid <= 0;
            start <= 0;
            matrix_size <= 32'd512;
            scale_factor_reg <= 32'h3F800000;
            rvalid <= 0;
            rdata <= 0;
        end else begin
            start <= 0;
            if (bvalid && bready) bvalid <= 0;
            if (aw_fire) begin
                aw_hold <= awaddr;
                aw_pending <= 1;
            end
            if (w_fire) begin
                w_hold <= wdata;
                strb_hold <= wstrb;
                w_pending <= 1;
            end
            if (write_commit) begin
                aw_pending <= 0;
                w_pending <= 0;
                bvalid <= 1;
                case (write_addr)
                    32'h00: if (write_strb[0] && write_data[0]) start <= 1;
                    32'h08: matrix_size <= merge_bytes(matrix_size, write_data, write_strb);
                    32'h18: scale_factor_reg <= merge_bytes(scale_factor_reg, write_data, write_strb);
                    default: ;
                endcase
            end
            if (rvalid && rready) rvalid <= 0;
            if (arvalid && arready) begin
                rvalid <= 1;
                case (araddr)
                    32'h00: rdata <= 0;
                    32'h04: rdata <= {24'h0, error_code, 3'h0, done};
                    32'h08: rdata <= matrix_size;
                    32'h0C: rdata <= tile_count;
                    32'h10: rdata <= cycle_count;
                    32'h14: rdata <= tile_cycles;
                    32'h18: rdata <= scale_factor_reg;
                    32'h1C: rdata <= protocol_version;
                    32'h20: rdata <= input_beats;
                    32'h24: rdata <= output_beats;
                    32'h28: rdata <= input_stalls;
                    32'h2C: rdata <= output_stalls;
                    32'h30: rdata <= compute_cycles;
                    32'h34: rdata <= scale_cycles;
                    default: rdata <= 32'hDEADBEEF;
                endcase
            end
        end
    end
endmodule
