SRC_DIR = ../src
TB_DIR  = .

all: pe

# -----------------------------------------------------------------------
# FP32 PE testbench
# -----------------------------------------------------------------------
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

run_pe:
	./obj_pe/tb_pe

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

# -----------------------------------------------------------------------
# FP32 Systolic array testbench
# -----------------------------------------------------------------------
array: compile_array run_array

compile_array:
	verilator --cc $(SRC_DIR)/fp32_mul.sv \
	          $(SRC_DIR)/fp32_add.sv \
	          $(SRC_DIR)/pe.sv \
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

array_debug: compile_array_debug run_array

# -----------------------------------------------------------------------
# AXI4-Lite control interface testbench
# -----------------------------------------------------------------------
axi: compile_axi run_axi

compile_axi:
	verilator --cc $(SRC_DIR)/axi4_lite_ctrl.sv \
	          --exe $(TB_DIR)/tb_axi4_lite_ctrl.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -o tb_axi4_lite_ctrl \
	          --Mdir obj_axi \
	          --top-module axi4_lite_ctrl

run_axi:
	./obj_axi/tb_axi4_lite_ctrl

axi_debug: compile_axi_debug run_axi

compile_axi_debug:
	verilator --cc $(SRC_DIR)/axi4_lite_ctrl.sv \
	          --exe $(TB_DIR)/tb_axi4_lite_ctrl.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -DDEBUG_AXI \
	          -o tb_axi4_lite_ctrl \
	          --Mdir obj_axi \
	          --top-module axi4_lite_ctrl

compile_array_debug:
	verilator --cc $(SRC_DIR)/fp32_mul.sv \
	          $(SRC_DIR)/fp32_add.sv \
	          $(SRC_DIR)/pe.sv \
	          $(SRC_DIR)/systolic_array.sv \
	          --exe $(TB_DIR)/tb_systolic_array.cpp \
	          --build \
	          -Wall \
	          --trace \
	          -GSIZE=4 \
	          -DDEBUG_PE \
	          -o tb_systolic_array \
	          --Mdir obj_array \
	          --top-module systolic_array

clean:
	rm -rf obj_pe obj_array

.PHONY: all pe pe_debug array array_debug \
        compile_pe compile_pe_debug run_pe \
        compile_array compile_array_debug run_array clean
