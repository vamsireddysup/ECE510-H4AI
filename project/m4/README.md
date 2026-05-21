# M4 -- FP4 QK^T Accelerator Chiplet -- Final Deliverable Package

## File catalog

### rtl/ -- Final source code
| File | Description | Checklist |
|---|---|---|
| rtl/top.sv | Top-level integration: AXI4-Lite + AXI4-Stream + tile_controller + systolic_array + fp32_mul | Section 2 |
| rtl/compute_core.sv | Systolic array: SIZE×SIZE FP4 multiply + FP32 accumulate PEs | Section 2 |
| rtl/interface.sv | AXI4-Lite control register interface | Section 2 |

### tb/ -- Final testbench
| File | Description | Checklist |
|---|---|---|
| tb/tb_top.cpp | End-to-end co-simulation (Verilator C++, accepted by instructor) | Section 2 |

### sim/ -- Simulation outputs
| File | Description | Checklist |
|---|---|---|
| sim/final_run.log | Co-simulation log showing 16/16 PASS | Section 2 |
| sim/final_waveform.png | Annotated waveform: AXI write, streaming, compute, output | Section 2 |

### synth/ -- Synthesis results
| File | Description | Checklist |
|---|---|---|
| synth/config.json | OpenLane configuration (clock 4.0ns, sky130A HD, SIZE=4) | Section 3 |
| synth/openlane_run.log | Full OpenLane 1.1.1 stdout/stderr | Section 3 |
| synth/timing_report.txt | WNS=-2.30ns, TNS=-1429.82ns, hold +0.08ns MET | Section 3 |
| synth/area_report.txt | 31,502 cells, 328,554 µm² (SIZE=4) | Section 3 |
| synth/power_report.txt | 60.2 mW total, 95.5% sequential (SIZE=4) | Section 3 |

### bench/ -- Benchmark comparison
| File | Description | Checklist |
|---|---|---|
| bench/benchmark.md | Throughput, speedup, energy vs CPU baseline | Section 4 |
| bench/benchmark_data.csv | Raw numbers with source file references | Section 4 |
| bench/roofline_final.png | Final roofline plot with measured accelerator point | Section 4 |

### report/ -- Design justification
| File | Description | Checklist |
|---|---|---|
| report/design_justification.pdf | 9-section report (2000-5000 words) | Section 5 |
| report/figures/roofline_final.png | Roofline figure referenced in report | Section 5 |

## How to reproduce co-simulation

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

Expected: `ALL PASS -- End-to-end AXI co-simulation verified`

## How to reproduce synthesis

```bash
cd project/m3
docker run --rm \
    -v $(pwd):/work -v ~/.volare:/root/.volare \
    -e PDK_ROOT=/root/.volare -e PDK=sky130A \
    efabless/openlane:latest \
    bash -c "/nix/store/xpc7xd67rslanlqh566s6jph53bn830w-openlane1-1.1.1/bin/flow.tcl \
    -design /work/openlane1 -tag full_run -overwrite"
```

Tool: OpenLane 1.1.1, Verilator 5.041, yosys 0.44, OpenSTA 2.5.0
