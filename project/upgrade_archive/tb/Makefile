# Makefile for upgrade/ FP4 design testbenches
# Usage:
#   make fp4_mul         -- compile and run FP4 multiplier testbench
#   make fp4_mul_debug   -- compile and run with DEBUG_FP4MUL traces
#   make clean           -- remove all generated files

RTL_DIR = ../rtl
TB_DIR  = .

all: fp4_mul

# -----------------------------------------------------------------------
# FP4 multiplier testbench
# -----------------------------------------------------------------------
fp4_mul: compile_fp4_mul run_fp4_mul

compile_fp4_mul:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          --exe $(TB_DIR)/tb_fp4_mul.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o tb_fp4_mul \
	          --Mdir obj_fp4_mul \
	          --top-module fp4_mul

run_fp4_mul:
	./obj_fp4_mul/tb_fp4_mul

fp4_mul_debug: compile_fp4_mul_debug run_fp4_mul

compile_fp4_mul_debug:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          --exe $(TB_DIR)/tb_fp4_mul.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -DDEBUG_FP4MUL \
	          -o tb_fp4_mul \
	          --Mdir obj_fp4_mul \
	          --top-module fp4_mul

clean:
	rm -rf obj_fp4_mul *.vcd

.PHONY: all fp4_mul fp4_mul_debug \
        compile_fp4_mul compile_fp4_mul_debug \
        run_fp4_mul clean

# -----------------------------------------------------------------------
# FP4 PE testbench
# -----------------------------------------------------------------------
pe: compile_pe run_pe

compile_pe:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GD_HEAD=4 \
	          -o tb_pe \
	          --Mdir obj_pe \
	          --top-module pe

run_pe:
	./obj_pe/tb_pe

pe_debug: compile_pe_debug run_pe

compile_pe_debug:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GD_HEAD=4 \
	          -DDEBUG_PE \
	          -o tb_pe \
	          --Mdir obj_pe \
	          --top-module pe

# -----------------------------------------------------------------------
# FP4 systolic array testbench (SIZE=4 for verification)
# -----------------------------------------------------------------------
array: compile_array run_array

compile_array:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=4 \
	          -GD_HEAD=4 \
	          -o tb_systolic_array \
	          --Mdir obj_array \
	          --top-module systolic_array

run_array:
	./obj_array/tb_systolic_array

array_debug: compile_array_debug run_array

compile_array_debug:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=4 \
	          -GD_HEAD=4 \
	          -DDEBUG_PE \
	          -o tb_systolic_array \
	          --Mdir obj_array \
	          --top-module systolic_array

# -----------------------------------------------------------------------
# FP4 systolic array golden reference testbench
# -----------------------------------------------------------------------
array_golden: compile_array_golden run_array_golden

compile_array_golden:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array_golden.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=4 \
	          -GD_HEAD=4 \
	          -o tb_systolic_array_golden \
	          --Mdir obj_array_golden \
	          --top-module systolic_array

run_array_golden:
	./obj_array_golden/tb_systolic_array_golden

# -----------------------------------------------------------------------
# Tile controller testbench
# -----------------------------------------------------------------------
ctrl: compile_ctrl run_ctrl

compile_ctrl:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          $(RTL_DIR)/scale_sram.sv \
	          $(RTL_DIR)/tile_buffer.sv \
	          $(RTL_DIR)/tile_controller.sv \
	          --exe $(TB_DIR)/tb_tile_controller.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GTILE_SIZE=4 \
	          -GD_HEAD=4 \
	          -GT_MAX=16 \
	          -o tb_tile_controller \
	          --Mdir obj_ctrl \
	          --top-module tile_controller

run_ctrl:
	./obj_ctrl/tb_tile_controller

ctrl_debug: compile_ctrl_debug run_ctrl

compile_ctrl_debug:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          $(RTL_DIR)/scale_sram.sv \
	          $(RTL_DIR)/tile_buffer.sv \
	          $(RTL_DIR)/tile_controller.sv \
	          --exe $(TB_DIR)/tb_tile_controller.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GTILE_SIZE=4 \
	          -GD_HEAD=4 \
	          -GT_MAX=16 \
	          -DDEBUG_CTRL \
	          -DDEBUG_SRAM \
	          -DDEBUG_TBUF \
	          -o tb_tile_controller \
	          --Mdir obj_ctrl \

# -----------------------------------------------------------------------
# FP4 PE extended random value testbench
# -----------------------------------------------------------------------
pe_random: compile_pe_random run_pe_random

compile_pe_random:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe_random.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GD_HEAD=4 \
	          -o tb_pe_random \
	          --Mdir obj_pe_random \
	          --top-module pe

run_pe_random:
	./obj_pe_random/tb_pe_random

# -----------------------------------------------------------------------
# FP4 systolic array SIZE=16 elaboration and basic test
# -----------------------------------------------------------------------
array16: compile_array16 run_array16

compile_array16:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          $(RTL_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array16.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=16 \
	          -GD_HEAD=4 \
	          -o tb_systolic_array16 \
	          --Mdir obj_array16 \
	          --top-module systolic_array

run_array16:
	./obj_array16/tb_systolic_array16

# -----------------------------------------------------------------------
# FP4 PE D_HEAD=64 test
# -----------------------------------------------------------------------
pe_dhead64: compile_pe_dhead64 run_pe_dhead64

compile_pe_dhead64:
	verilator --cc $(RTL_DIR)/fp4_mul_lut.sv \
	          $(RTL_DIR)/fp4_mul.sv \
	          $(RTL_DIR)/fp32_add.sv \
	          $(RTL_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe_dhead64.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GD_HEAD=64 \
	          -o tb_pe_dhead64 \
	          --Mdir obj_pe_dhead64 \
	          --top-module pe

run_pe_dhead64:
	./obj_pe_dhead64/tb_pe_dhead64
