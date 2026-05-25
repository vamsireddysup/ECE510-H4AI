set ::env(DESIGN_NAME) "systolic_array_flat"

set ::env(VERILOG_FILES) "
    /work/src/fp4_mul_lut.sv
    /work/src/fp4_mul.sv
    /work/src/fp32_add.sv
    /work/src/pe.sv
    /work/src/systolic_array_flat.sv
"

set ::env(CLOCK_PORT) "clk"
set ::env(CLOCK_PERIOD) "4.0"
set ::env(PDK) "sky130A"
set ::env(STD_CELL_LIBRARY) "sky130_fd_sc_hd"
set ::env(DIE_AREA) "0 0 2500 2500"
set ::env(FP_CORE_UTIL) 55
set ::env(PL_TARGET_DENSITY) 0.60
set ::env(RUN_MAGIC) 1
set ::env(RUN_LVS) 1

# Fix hold violations
set ::env(PL_RESIZER_HOLD_SLACK_MARGIN) 0.5
set ::env(GLB_RESIZER_HOLD_SLACK_MARGIN) 0.5
set ::env(GLB_RESIZER_HOLD_MAX_BUFFER_PERCENT) 70

# Fix fanout -- use synthesis max fanout
set ::env(MAX_FANOUT_CONSTRAINT) 10
set ::env(SYNTH_MAX_FANOUT) 10

# Enable hold buffer insertion during CTS resizer
set ::env(PL_RESIZER_HOLD_BUFFER_PERCENT) 50
set ::env(GLB_RESIZER_TIMING_OPTIMIZATIONS) 1
