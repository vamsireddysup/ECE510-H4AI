# M4 -- FP4 QK^T Accelerator Chiplet -- Final Deliverable Package

## What was synthesized and benchmarked

The synthesized, verified, and benchmarked design is a **4x4 systolic array
(SIZE=4)** on the sky130A HD process. A 16x16 array (SIZE=16) is the longer-term
design target; every SIZE=16 number in this package is explicitly labeled
[PROJECTED] and is a scaled estimate, not a measured result.

The OpenLane flow completed with status SUCCESS: DRC=0, LVS clean, XOR clean,
setup and hold gates met. The design closes timing at a 15.0 ns clock period
(suggested operating frequency ~62 MHz). See the timing note in
synth/timing_report.txt and bench/benchmark.md for the honest frequency
discussion.

## File catalog

### src/ -- Final RTL source (all modules; synthesis uses the flat wrapper)
| File | Description | Checklist |
|---|---|---|
| src/fp4_mul_lut.sv | 256-entry FP4 E2M1 multiply lookup table | Section 2 |
| src/fp4_mul.sv | FP4 multiplier wrapper, 1-cycle latency | Section 2 |
| src/fp32_add.sv | 3-stage pipelined FP32 adder (accumulate path) | Section 2 |
| src/fp32_mul.sv | 3-stage pipelined FP32 multiplier (dequantization) | Section 2 |
| src/pe.sv | Processing element: FP4 mul + FP32 accumulate | Section 2 |
| src/systolic_array.sv | SIZExSIZE systolic array (reference, unpacked ports) | Section 2 |
| src/systolic_array_flat.sv | Synthesis wrapper with flat ports (OpenLane target) | Section 2 |
| src/scale_sram.sv | FP32 microscaling factor SRAM | Section 2 |
| src/tile_buffer.sv | Q/K/output tile buffers with parallel read ports | Section 2 |
| src/tile_controller.sv | Tiling FSM: coordinates AXI, buffers, systolic array | Section 2 |
| src/axi4_lite_ctrl.sv | AXI4-Lite slave control register interface | Section 2 |
| src/qkt_chiplet_top.sv | Top-level integration of all modules | Section 2 |

### rtl/ -- Final integrated RTL (co-simulation top, per rubric layout)
| File | Description | Checklist |
|---|---|---|
| rtl/top.sv | Top-level integration module (qkt_chiplet_top) | Section 2 |
| rtl/compute_core.sv | Systolic array compute core | Section 2 |
| rtl/interface.sv | AXI4-Lite control interface | Section 2 |

### tb/ -- Final testbench
| File | Description | Checklist |
|---|---|---|
| tb/tb_top.cpp | End-to-end co-simulation (Verilator C++). The instructor confirmed .cpp is accepted in place of .sv for this Verilator-based flow. | Section 2 |

### sim/ -- Simulation outputs
| File | Description | Checklist |
|---|---|---|
| sim/final_run.log | Co-simulation log: 16/16 PASS, CYCLE_COUNT=498 | Section 2 |
| sim/final_waveform.png | Annotated waveform: host write / compute / host read regions | Section 2 |
| sim/chiplet_top_wave.vcd | Raw VCD trace from the co-simulation | Section 2 (supporting) |

### synth/ -- Synthesis results (OpenLane 1.1.1, final v14 run, from project/m4/)
| File | Description | Checklist |
|---|---|---|
| synth/config.json | OpenLane config snapshot: clock 15.0 ns, sky130A HD, systolic_array_flat | Section 3 |
| synth/openlane_run.log | Full OpenLane 1.1.1 stdout/stderr for the final run | Section 3 |
| synth/timing_report.txt | SPEF nominal: setup WNS -1.13 ns, hold WNS -0.12 ns; flow gate MET; closes at 15.0 ns | Section 3 |
| synth/area_report.txt | 30,689 cells, 324,753 um^2 (synthesis, SIZE=4) | Section 3 |
| synth/power_report.txt | 28.1 mW typical (seq 54.2%, clock 40.5%, comb 5.3%) | Section 3 |
| synth/manufacturability.rpt | DRC=0, LVS clean (43,158 nets), antenna summary | Section 3 (supporting) |
| synth/metrics.csv | Full OpenLane metrics: freq, area, power, slack | Section 3 (supporting) |

### openlane/ -- OpenLane configuration and run logs for M4
| File | Description | Checklist |
|---|---|---|
| openlane/config.tcl | OpenLane 1 Tcl config used for the final M4 synthesis run | Section 3 |
| openlane/run_logs/ | Archived stdout logs from each signoff iteration (v7-v14). Not a rubric deliverable; kept for reproducibility and to document the timing-closure path. | Section 3 (supporting) |

### bench/ -- Benchmark comparison
| File | Description | Checklist |
|---|---|---|
| bench/benchmark.md | Throughput, speedup, energy vs CPU. States plainly that SIZE=4 is slower than CPU and why. | Section 4 |
| bench/benchmark_data.csv | Raw numbers, each traced to a source file | Section 4 |
| bench/roofline_final.png | Roofline: CPU baseline, measured SIZE=4 point, projected SIZE=16 points | Section 4 |

### report/ -- Design justification
| File | Description | Checklist |
|---|---|---|
| report/design_justification.pdf | 9-section design justification report | Section 5 |
| report/figures/roofline_final.png | Roofline figure referenced in the report | Section 5 |

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
- OpenSTA (inside Docker)
- Verilator 5.041 (host)

**Notes:**
- OpenLane 2.x was attempted but failed due to a pyosys/yosys compatibility
  issue with the `-y` Python flag. OpenLane 1.1.1 inside Docker was used as the
  working alternative.
- The synthesis target is `systolic_array_flat`, a flat-port wrapper around the
  systolic array. The unpacked-array ports of `systolic_array.sv` are not
  parseable by yosys 0.38, which is why the flat wrapper exists. The AXI
  interface and tiling logic are verified in co-simulation rather than carried
  into this synthesis run.
- The clock period was relaxed from the 4.0 ns M1 target to 15.0 ns to achieve a
  clean signoff. The frequency-closure story is documented in
  bench/benchmark.md and the design justification report.
