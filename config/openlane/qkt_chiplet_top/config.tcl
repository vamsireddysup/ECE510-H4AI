# Complete active 4x4 QK^T top, default D_HEAD=64, T_MAX=16, K_REUSE=0.
set ::env(DESIGN_NAME) "qkt_chiplet_top"
set ::env(VERILOG_FILES) "
    /work/rtl/core/fp32_mul.sv
    /work/rtl/interfaces/axi4_lite_ctrl.sv
    /work/rtl/top/qkt_chiplet_top.sv
"
set ::env(CLOCK_PORT) "clk"
set ::env(CLOCK_PERIOD) "50.0"
set ::env(PDK) "sky130A"
set ::env(STD_CELL_LIBRARY) "sky130_fd_sc_hd"
set ::env(DIE_AREA) "0 0 1500 1500"
set ::env(FP_CORE_UTIL) 40
set ::env(PL_TARGET_DENSITY) 0.55
set ::env(RUN_MAGIC) 1
set ::env(RUN_LVS) 1
set ::env(MAX_FANOUT_CONSTRAINT) 30
