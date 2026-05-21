# M4 -- FP4 QK^T Accelerator Chiplet -- Final Deliverable Package

## File catalog

### src/ -- Final RTL source (used for M4 synthesis)
| File | Description | Checklist |
|---|---|---|
| src/fp4_mul_lut.sv | 256-entry FP4 E2M1 multiply lookup table | Section 2 |
| src/fp4_mul.sv | FP4 multiplier wrapper, 1-cycle latency | Section 2 |
| src/fp32_add.sv | 3-stage pipelined FP32 adder | Section 2 |
| src/fp32_mul.sv | 3-stage pipelined FP32 multiplier (dequantization) | Section 2 |
| src/pe.sv | Processing element: FP4 mul + FP32 accumulate | Section 2 |
| src/systolic_array.sv | SIZE×SIZE systolic array (reference, unpacked ports) | Section 2 |
| src/systolic_array_flat.sv | Synthesis wrapper with flat ports (OpenLane target) | Section 2 |
| src/scale_sram.sv | FP32 microscaling factor SRAM | Section 2 |
| src/tile_buffer.sv | Q/K/output tile buffers with parallel read ports | Section 2 |
| src/tile_controller.sv | Tiling FSM: coordinates AXI, buffers, systolic array | Section 2 |
| src/axi4_lite_ctrl.sv | AXI4-Lite slave control register interface | Section 2 |
| src/qkt_chiplet_top.sv | Top-level integration of all modules | Section 2 |

### rtl/ -- Final integrated RTL (co-simulation target)
| File | Description | Checklist |
|---|---|---|
| rtl/top.sv | Top-level integration module (qkt_chiplet_top) | Section 2 |
| rtl/compute_core.sv | Systolic array compute core | Section 2 |
| rtl/interface.sv | AXI4-Lite control interface | Section 2 |

### tb/ -- Final testbench
| File | Description | Checklist |
|---|---|---|
| tb/tb_top.cpp | End-to-end co-simulation (Verilator C++, accepted by instructor) | Section 2 |

### sim/ -- Simulation outputs
| File | Description | Checklist |
|---|---|---|
| sim/final_run.log | Co-simulation log: 16/16 PASS, CYCLE_COUNT=498 | Section 2 |
| sim/final_waveform.png | Waveform: AXI write, streaming, compute, AXI read | Section 2 |

### synth/ -- Synthesis results (OpenLane 1.1.1 from project/m4/)
| File | Description | Checklist |
|---|---|---|
| synth/config.json | OpenLane config: clock 4.0 ns, sky130A HD, systolic_array_flat | Section 3 |
| synth/openlane_run.log | Full OpenLane 1.1.1 stdout/stderr | Section 3 |
| synth/timing_report.txt | WNS=-2.54 ns, TNS=-1390.39 ns, hold +0.08 ns MET | Section 3 |
| synth/area_report.txt | 31,560 cells, 329,148 µm² (SIZE=4 measured) | Section 3 |
| synth/power_report.txt | 60.2 mW total, 95.5% sequential, 4.5% combinational | Section 3 |

### openlane/ -- OpenLane configuration for M4
| File | Description | Checklist |
|---|---|---|
| openlane/config.tcl | OpenLane 1 Tcl config used for M4 synthesis run | Section 3 |

### bench/ -- Benchmark comparison
| File | Description | Checklist |
|---|---|---|
| bench/benchmark.md | Throughput, speedup, energy vs CPU baseline | Section 4 |
| bench/benchmark_data.csv | Raw numbers traced to source log files | Section 4 |
| bench/roofline_final.png | Final roofline plot with measured accelerator point | Section 4 |

### report/ -- Design justification
| File | Description | Checklist |
|---|---|---|
| report/design_justification.pdf | 9-section design justification report | Section 5 |
| report/figures/roofline_final.png | Roofline figure referenced in report | Section 5 |

## How to reproduce co-simulation

**Dependencies:** Verilator 5.041, g++ 13.3, Ubuntu 24.04

```bash
cd project/m2/tb
verilator --cc \
    ../rtl/fp4_mul_lut.sv ../rtl/fp4_mul.sv ../rtl/fp32_add.sv \
    ../rtl/fp32_mul.sv ../rtl/pe.sv ../rtl/systolic_array.sv \
    ../rtl/scale_sram.sv ../rtl/tile_buffer.sv \
    ../rtl/tile_controller.sv ../rtl/axi4_lite_ctrl.sv \
    ../rtl/qkt_chiplet_top.sv \
    --exe ./tb_chiplet_top.cpp --build -Wall --trace \
    -GTILE_SIZE=4 -GD_HEAD=4 -GT_MAX=16 \
    -o tb_chiplet_top --Mdir obj_chiplet \
    --top-module qkt_chiplet_top
./obj_chiplet/tb_chiplet_top
```

Expected output: `ALL PASS -- End-to-end AXI co-simulation verified`

## How to reproduce synthesis

**Dependencies:** Docker, efabless/openlane:latest, sky130A PDK at ~/.volare

```bash
cd project/m4
docker run --rm \
    -v $(pwd):/work \
    -v ~/.volare:/root/.volare \
    -e PDK_ROOT=/root/.volare \
    -e PDK=sky130A \
    efabless/openlane:latest \
    bash -c "/nix/store/xpc7xd67rslanlqh566s6jph53bn830w-openlane1-1.1.1/bin/flow.tcl \
    -design /work/openlane -tag full_run -overwrite"
```

**Tool versions:**
- OpenLane 1.1.1 (efabless/openlane:latest Docker image)
- Yosys 0.38 (inside Docker)
- OpenSTA 2.5.0 (inside Docker)
- Verilator 5.041 (host)

**Note:** OpenLane 2.3.10 was attempted but failed due to pyosys
compatibility with yosys 0.44. OpenLane 1.1.1 inside Docker was used
as the working alternative. Synthesis target is systolic_array_flat
(flat port wrapper). AXI interface modules verified separately in
co-simulation.
