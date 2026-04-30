# Milestone 2 -- QK^T Accelerator Chiplet

## Overview

This milestone implements the RTL compute core and interface module for
a custom chiplet accelerating QK^T matrix multiplication in transformer
self-attention. All simulations use Verilator 5.041 on Ubuntu 24.04.

---

## Repository structure

```
project/m2/
├── rtl/
│   ├── systolic_array.sv  -- top-level compute core (QK^T systolic array)
│   ├── axi4_lite_ctrl.sv  -- AXI4-Lite control interface
│   ├── axi4_stream.sv     -- AXI4-Stream data interface
│   ├── pe.sv              -- FP32 processing element
│   ├── fp32_mul.sv        -- synthesizable FP32 multiplier (3-stage)
│   └── fp32_add.sv        -- synthesizable FP32 adder (1-cycle)
├── tb/
│   ├── Makefile
│   ├── tb_systolic_array.cpp -- compute core testbench (16/16 PASS)
│   ├── tb_axi4_lite_ctrl.cpp -- AXI4-Lite testbench (2/2 PASS)
│   ├── tb_axi4_stream.cpp    -- AXI4-Stream testbench (2/2 PASS)
│   └── tb_pe.cpp             -- FP32 PE testbench (2/2 PASS)
├── sim/
│   ├── compute_core_run.log  -- simulation transcript showing 16/16 PASS
│   ├── interface_run.log     -- simulation transcript showing 2/2 PASS
│   └── waveform.png          -- GTKWave waveform from systolic array run
├── golden/
│   ├── q_matrix.txt          -- 4x4 Q input matrix
│   ├── k_matrix.txt          -- 4x4 K input matrix
│   ├── qkt_expected.txt      -- expected QK^T output
│   └── gen_golden.py         -- Python script to regenerate golden reference
├── precision.md              -- FP32 precision choice and error analysis
└── README.md                 -- this file
```

---

## How to reproduce simulations

### Prerequisites

```
Verilator 5.041  (verilator --version)
g++ 12 or later  (g++ --version)
GTKWave 3.3.116  (gtkwave --version)
```

### Clone and setup

```bash
git clone https://github.com/vamsireddysup/ECE510-H4AI.git
cd ECE510-H4AI
```

### Run compute core testbench

```bash
cd project/m2/tb
make array
```

Expected output:
```
Results: 16/16 elements correct
ALL PASS -- QK^T output matches golden reference
```

### Run interface testbench

```bash
cd project/m2/tb
make axi
```

Expected output:
```
Results: 2/2 transactions passed
ALL PASS -- AXI4-Lite interface verified
```

### Run all testbenches

```bash
cd project/m2/tb
make pe && make array && make axi && make stream
```

### Debug traces

```bash
make pe_debug      # FP32 PE internal pipeline traces
make array_debug   # systolic array with PE traces
make axi_debug     # AXI4-Lite transaction traces
make stream_debug  # AXI4-Stream transaction traces
```

### View waveform

```bash
gtkwave project/m2/tb/systolic_wave.vcd
```

---

## Simulator and versions

- Simulator: Verilator 5.041 (devel rev v5.040-196-g63f5f5c32)
- Testbench driver: C++ (standard for Verilator, not .sv)
- OS: Ubuntu 24.04 LTS
- Python 3.12.3 + NumPy 1.26: golden reference generation

---

## Deviations from M1 plan

**Interface:** AXI4-Lite (control) + AXI4-Stream (data) -- both implemented as planned. No changes.

**Precision:** FP32 implemented using synthesizable fp32_mul.sv and fp32_add.sv. No changes.

**Array size:** Parameterized NxN array. M2 testbenches use SIZE=4 matching golden reference. Target 8x8 for 32 GFLOP/s is M3 synthesis target.

**Testbench format:** C++ testbenches for Verilator. Extension is .cpp not .sv. Makefile in project/m2/tb/ drives all simulations.

---

## Golden reference

```bash
cd project/m2/golden
python3 gen_golden.py
```
