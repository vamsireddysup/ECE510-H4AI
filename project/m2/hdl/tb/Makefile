# Makefile for HDL testbenches
# Usage:
#   make           -- compile and run both testbenches
#   make pe        -- compile and run PE testbench only
#   make array     -- compile and run systolic array testbench only
#   make clean     -- remove all generated files

SRC_DIR = ../src
TB_DIR  = .

all: pe array

# -----------------------------------------------------------------------
# PE testbench
# -----------------------------------------------------------------------
pe: compile_pe run_pe

compile_pe:
	verilator --cc $(SRC_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o tb_pe \
	          --Mdir obj_pe

run_pe:
	./obj_pe/tb_pe

# -----------------------------------------------------------------------
# Systolic array testbench
# Overrides SIZE=4 and D_HEAD=4 to match the golden reference matrices
# -----------------------------------------------------------------------
array: compile_array run_array

compile_array:
	verilator --cc $(SRC_DIR)/pe.sv \
	          $(SRC_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=4 \
	          -o tb_systolic_array \
	          --Mdir obj_array \
	          --top-module systolic_array

run_array:
	./obj_array/tb_systolic_array

clean:
	rm -rf obj_pe obj_array

.PHONY: all pe array compile_pe run_pe compile_array run_array clean
