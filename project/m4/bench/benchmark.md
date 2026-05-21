# M4 Benchmark -- FP4 QK^T Accelerator vs CPU Baseline

## Measurement methodology

All synthesis numbers come from OpenLane 1.1.1 running inside Docker
(efabless/openlane:latest) with sky130A HD library at tt_025C_1v80,
run from project/m4/. Source files: project/m4/synth/*.

Accelerator throughput is derived from:
1. Achievable frequency from post-synthesis STA: WNS=-2.54 ns at 4.0 ns
   clock period → max frequency = 1000/(4.0+2.54) = 152.6 MHz
2. Cycle count from Verilator co-simulation: CYCLE_COUNT=498 for
   TILE_SIZE=4, D_HEAD=4, T=4 (project/m4/sim/final_run.log)
3. QK^T latency extrapolated to full design: N=512, d_head=64, SIZE=16

CPU baseline from M1: Intel Core i5-1145G7, PyTorch float32,
single thread, 11.36 GFLOP/s measured.

All raw numbers traceable to source files in project/m4/bench/benchmark_data.csv.

## Synthesis results (SIZE=4, measured from M4 OpenLane run)

| Metric | Value | Source file |
|---|---|---|
| Total cells (OpenLane) | 31,560 | synth/area_report.txt |
| Chip area | 329,148 µm² | synth/area_report.txt |
| WNS (setup) | -2.54 ns | synth/timing_report.txt |
| TNS | -1,390.39 ns | synth/timing_report.txt |
| Hold WNS | +0.08 ns (MET) | synth/timing_report.txt |
| Power total | 60.2 mW | synth/power_report.txt |
| Power sequential | 57.5 mW (95.5%) | synth/power_report.txt |
| Power combinational | 2.71 mW (4.5%) | synth/power_report.txt |

## Accelerator operating points (SIZE=16, extrapolated)

Area extrapolation: 329,148 × (16/4)² = 5,266,368 µm² = 5.27 mm²
Power extrapolation: 60.2 × (16/4)² = 963 mW

### Option A -- Achievable frequency (152.6 MHz)

From WNS=-2.54 ns: max_freq = 1000/(4.0+2.54) = 152.6 MHz

| Metric | Value |
|---|---|
| Frequency | 152.6 MHz |
| Peak GOPS (SIZE=16) | 78.13 |
| Effective GOPS | 23.94 |
| QK^T latency (N=512, d=64) | 1.400 ms |
| Speedup vs CPU | **2.11×** |
| Power (SIZE=16, extrapolated) | 963 mW |
| Energy per QK^T | 1.348 mJ |
| Area efficiency | 4.55 GOPS/mm² |
| Power efficiency | 24.86 GOPS/W |

### Option B -- Projected (250 MHz, full timing closure)

Requires pipelining fp32_add into 3 stages and full CTS with reset buffering.

| Metric | Value |
|---|---|
| Frequency | 250 MHz (projected) |
| Peak GOPS | 128.00 |
| Effective GOPS | 39.20 |
| QK^T latency | 0.856 ms |
| Speedup vs CPU | **3.45×** |
| Power efficiency | 40.69 GOPS/W |

## CPU baseline (from M1)

| Metric | Value |
|---|---|
| Platform | Intel Core i5-1145G7 |
| Peak FP32 | 11.36 GFLOP/s |
| Memory bandwidth | 51.2 GB/s |
| Ridge point | 8.28 FLOP/byte |
| QK^T latency (N=512, d=64) | 2.954 ms |

## Arithmetic intensity

QK^T kernel: AI = 2×N²×D_HEAD / total_bytes = 15.06 FLOP/byte
Both CPU and chiplet are compute-bound (AI > ridge point 8.28 FLOP/byte).

## Energy comparison

CPU energy (TDP upper bound): 15 W × 2.954 ms = 44.3 mJ
Chiplet energy (Option A): 0.963 W × 1.400 ms = 1.348 mJ
Energy improvement: ~33× lower energy than CPU upper bound

## Co-simulation verification

From project/m4/sim/final_run.log:
- 16/16 elements correct
- ALL PASS -- End-to-end AXI co-simulation verified
- TILE_COUNT=1, CYCLE_COUNT=498 (TILE_SIZE=4, D_HEAD=4, T=4)
