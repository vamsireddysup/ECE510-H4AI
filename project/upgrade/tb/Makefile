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
