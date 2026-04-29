SRC_DIR = ../src
TB_DIR  = .

all: pe

pe: compile_pe run_pe

compile_pe:
	verilator --cc $(SRC_DIR)/pe.sv \
	          --exe $(TB_DIR)/tb_pe.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o tb_pe \
	          --Mdir obj_pe \
	          --top-module pe

run_pe:
	./obj_pe/tb_pe

clean:
	rm -rf obj_pe obj_array

.PHONY: all pe compile_pe run_pe clean
