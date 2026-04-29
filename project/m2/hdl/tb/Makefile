SRC_DIR = ../src
TB_DIR  = .

all: pe

pe: compile_pe run_pe

compile_pe:
	verilator --cc $(SRC_DIR)/fp32_mul.sv \
	          $(SRC_DIR)/fp32_add.sv \
	          $(SRC_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o tb_pe \
	          --Mdir obj_pe \
	          --top-module pe

pe_debug: compile_pe_debug run_pe

compile_pe_debug:
	verilator --cc $(SRC_DIR)/fp32_mul.sv \
	          $(SRC_DIR)/fp32_add.sv \
	          $(SRC_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -DDEBUG_PE \
	          -o tb_pe \
	          --Mdir obj_pe \
	          --top-module pe

run_pe:
	./obj_pe/tb_pe

clean:
	rm -rf obj_pe obj_array

.PHONY: all pe pe_debug compile_pe compile_pe_debug run_pe clean
