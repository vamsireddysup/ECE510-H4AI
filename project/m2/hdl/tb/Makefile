# Makefile for PE testbench
# Usage:
#   make        -- compile and run
#   make compile -- compile only
#   make run     -- run only
#   make clean   -- remove generated files

SRC_DIR  = ../src
TB_DIR   = .
OBJ_DIR  = obj_dir

DUT      = pe
TB       = tb_pe

all: compile run

compile:
	verilator --cc $(SRC_DIR)/$(DUT).sv \
	          --exe $(TB_DIR)/$(TB).cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o $(TB) \
	          --Mdir $(OBJ_DIR)

run:
	./$(OBJ_DIR)/$(TB)

clean:
	rm -rf $(OBJ_DIR)

.PHONY: all compile run clean
