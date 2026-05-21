# M3 -- FP4 QK^T Accelerator Chiplet Synthesis and Integration

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

**Dependencies:** Docker, efabless/openlane:latest image, sky130A PDK at ~/.volare

```bash
cd project/m3
docker run --rm \
    -v $(pwd):/work \
    -v ~/.volare:/root/.volare \
    -e PDK_ROOT=/root/.volare -e PDK=sky130A \
    efabless/openlane:latest \
    bash -c "/nix/store/xpc7xd67rslanlqh566s6jph53bn830w-openlane1-1.1.1/bin/flow.tcl \
    -design /work/openlane1 -tag full_run -overwrite"
```

**OpenLane version:** OpenLane 1.1.1 (commit in openlane1/runs/full_run/OPENLANE_COMMIT)
**Configuration:** project/m3/synth/config.json (OpenLane 2 format) and project/m3/openlane1/config.tcl (OpenLane 1 format)

## File catalog

### Top-level
| File | Description |
|---|---|
| README.md | This file -- M3 index and reproduction instructions |
| synthesis_notes.md | Narrative of what synthesized, what failed, scope status (807 words) |
| config.json | OpenLane 2 configuration (clock 4.0 ns, sky130A HD, SIZE=4) |

### rtl/
| File | Description |
|---|---|
| rtl/top.sv | Integrated top module: AXI4-Lite + AXI4-Stream + tile_controller + systolic_array + fp32_mul |

### tb/
| File | Description |
|---|---|
| tb/tb_top.cpp | End-to-end co-simulation testbench (Verilator C++, accepted by instructor) |

### sim/
| File | Description |
|---|---|
| sim/cosim_run.log | Co-simulation transcript showing 16/16 PASS |
| sim/cosim_waveform.png | Waveform showing AXI write, compute, AXI read (annotated) |

### synth/
| File | Description |
|---|---|
| synth/config.json | OpenLane 2 configuration file |
| synth/openlane_run.log | Full OpenLane 1.1.1 stdout/stderr from synthesis run |
| synth/timing_report.txt | STA summary: WNS=-2.30 ns, TNS=-1429.82 ns, hold MET |
| synth/area_report.txt | Area: 328,554 um2, cell count by type |
| synth/power_report.txt | Power: 60.2 mW total (95.5% sequential, 4.5% combinational) |
| synth/critical_path.md | Critical path identification and analysis |

### src/ (synthesis RTL)
| File | Description |
|---|---|
| src/fp4_mul_lut.sv | 256-entry FP4 E2M1 multiply lookup table |
| src/fp4_mul.sv | FP4 multiplier wrapper (1-cycle latency) |
| src/fp32_add.sv | 3-stage pipelined FP32 adder (Option B) |
| src/pe.sv | Processing element: FP4 mul + FP32 accumulate |
| src/systolic_array.sv | SIZE x SIZE systolic array (reference, unpacked ports) |
| src/systolic_array_flat.sv | Synthesis wrapper with flat ports for yosys compatibility |

### reports/ (synthesis results)
| File | Description |
|---|---|
| reports/metrics.csv | Summary: cells, area, timing, power |
| reports/synthesis.log | Full yosys synthesis log |
| reports/synth_out.v | Mapped netlist (sky130 HD cells) |
| reports/sta_report.txt | OpenSTA timing report (standalone yosys run) |
| reports/openlane_area.rpt | OpenLane area report |
| reports/openlane_timing_summary.rpt | OpenLane timing summary |
| reports/openlane_power.rpt | OpenLane power report |
| reports/openlane_sta_max.rpt | OpenLane setup timing report |
