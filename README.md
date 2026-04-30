# ECE 510 -- Hardware for Artificial Intelligence and Machine Learning

**Portland State University | Spring 2026 | Prof. Christof Teuscher**

Student: Vamsidhar Reddy Eraganeni

**Project:** QK^T matrix multiplication accelerator chiplet for transformer self-attention

---

## Repository structure

```
ECE510-H4AI/
├── README.md
├── project/
│   ├── heilmeier.md
│   ├── m1/                        -- M1: profiling, roofline, interface selection
│   └── m2/
│       ├── rtl/                   -- synthesizable SystemVerilog HDL
│       │   ├── systolic_array.sv  -- top-level compute core (NxN FP32 systolic array)
│       │   ├── axi4_lite_ctrl.sv  -- AXI4-Lite control interface
│       │   ├── axi4_stream.sv     -- AXI4-Stream data interface
│       │   ├── pe.sv              -- FP32 processing element
│       │   ├── fp32_mul.sv        -- synthesizable FP32 multiplier (3-stage)
│       │   └── fp32_add.sv        -- synthesizable FP32 adder (1-cycle)
│       ├── tb/                    -- Verilator C++ testbenches
│       │   ├── Makefile
│       │   ├── tb_systolic_array.cpp
│       │   ├── tb_axi4_lite_ctrl.cpp
│       │   ├── tb_axi4_stream.cpp
│       │   └── tb_pe.cpp
│       ├── sim/                   -- simulation logs and waveform
│       │   ├── compute_core_run.log
│       │   ├── interface_run.log
│       │   └── waveform.png
│       ├── golden/                -- reference matrices for verification
│       ├── precision.md           -- FP32 precision choice and error analysis
│       └── README.md              -- M2 simulation instructions
└── codefest/
    ├── cf01/ -- cf05/             -- weekly codefest deliverables
```

---

## Project overview

This project designs and verifies a custom chiplet accelerating the QK^T
matrix multiplication kernel in transformer self-attention. The chiplet
uses a weight-stationary systolic array of FP32 processing elements.

**Target:** 8x8 systolic array at 250 MHz = 32 GFLOP/s (2.75x over CPU baseline)

**Interface:** AXI4-Lite for control (start/done registers) + AXI4-Stream
for data (Q and K matrices in, score matrix out)

**Precision:** FP32 (IEEE 754 32-bit), synthesizable throughout

---

## M1 key numbers

From profiling on Intel i5-1145G7 at T=512, d_head=64:

- Software baseline: 23.64 ms, 11.36 GFLOP/s
- Arithmetic intensity: 25.60 FLOP/byte (compute-bound, AI > ridge=8.28)
- Chiplet target: 32 GFLOP/s, 2.75x speedup
- Required bandwidth: 1.19 GB/s
- AXI4-Stream at 64-bit/250MHz: 2 GB/s (1.68x headroom)

---

## M2 simulation results

| Testbench | Result |
|---|---|
| FP32 PE dot product | 2/2 PASS |
| Systolic array QK^T | 16/16 PASS -- matches golden reference |
| AXI4-Lite control | 2/2 PASS -- write START, read DONE |
| AXI4-Stream data | 2/2 PASS -- 4 in + 16 out transfers |

To reproduce:

```bash
cd project/m2/tb
make pe && make array && make axi && make stream
```

---

## References

- Vaswani et al., "Attention Is All You Need," NeurIPS 2017.
  https://arxiv.org/pdf/1706.03762
- Hyunwoong Ko, "Transformer PyTorch Implementation,"
  GitHub 2019. https://github.com/hyunwoongko/transformer
  (Used for understanding QK^T kernel structure and profiling)
