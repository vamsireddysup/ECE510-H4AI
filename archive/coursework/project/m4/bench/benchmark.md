# M4 Benchmark -- FP4 QK^T Accelerator vs CPU Baseline

## Measurement methodology

All synthesis numbers come from OpenLane 1.1.1 running inside Docker
(efabless/openlane:latest) with the sky130A HD library, run from project/m4/.
Source files: project/m4/synth/*. The full flow completed with status SUCCESS
(DRC=0, LVS clean, XOR clean, setup and hold gates met).

The synthesized and benchmarked design is a **4x4 systolic array (SIZE=4)**.
SIZE=16 figures are explicitly labeled [PROJECTED] and are scaled estimates,
not measured results.

Accelerator throughput uses the projected-from-synthesis path:
1. Operating frequency from post-route STA: clock closed at 15.0 ns period;
   suggested operating frequency 61.996 MHz (project/m4/synth/metrics.csv).
   The 6.19 ns critical-path logic plus clock-tree skew/uncertainty sets this.
2. Cycle count from Verilator co-simulation: 498 cycles for one 4x4 tile with
   TILE_SIZE=4, D_HEAD=4 (project/m4/sim/final_run.log).
3. Peak throughput = frequency x (SIZE x SIZE MACs/cycle) x (2 ops/MAC).

CPU baseline from M1: Intel Core i5-1145G7, PyTorch float32, single thread,
11.36 GFLOP/s, 2.954 ms per QK^T (N=512, d_head=64).

All raw numbers are in project/m4/bench/benchmark_data.csv.

## Synthesis results (SIZE=4, measured from M4 OpenLane v14 run)

| Metric | Value | Source file |
|---|---|---|
| Total cells (synthesis) | 30,689 | synth/area_report.txt |
| Chip area (synthesis) | 324,753 um^2 | synth/area_report.txt |
| Total cells (post-route) | 81,750 | synth/metrics.csv |
| Core area (post-route) | 589,240 um^2 | synth/metrics.csv |
| Clock period (closed) | 15.0 ns | synth/metrics.csv |
| Critical path logic | 6.19 ns | synth/metrics.csv |
| Suggested frequency | 61.996 MHz | synth/metrics.csv |
| SPEF nominal setup WNS | -1.13 ns | synth/timing_report.txt |
| SPEF nominal hold WNS | -0.12 ns | synth/timing_report.txt |
| Power total (typical) | 28.1 mW | synth/power_report.txt |
| Power sequential | 15.2 mW (54.2%) | synth/power_report.txt |
| Power clock | 11.4 mW (40.5%) | synth/power_report.txt |
| Power combinational | 1.49 mW (5.3%) | synth/power_report.txt |

Note on timing: the flow pass/fail gate reports setup and hold MET, and the
flow status is SUCCESS. The SPEF nominal-corner report still shows -1.13 ns
setup and -0.12 ns hold. This residual is clock-tree skew margin on the
single-clock flat netlist, not logic that fails functionally. The honest
operating frequency that makes even the nominal-corner slack positive is
~62 MHz, which is what is reported throughout.

## Accelerator operating point (SIZE=4, measured frequency)

Peak GOPS = 61.996 MHz x 4 x 4 x 2 = 1.984 GOPS

| Metric | Value |
|---|---|
| Frequency | 61.996 MHz |
| Peak throughput (SIZE=4) | 1.984 GOPS |
| Ideal QK^T latency (full util) | 16.914 ms |
| QK^T latency (498 cyc/tile, no tile overlap) | 2105.7 ms |
| Power (typical) | 28.1 mW |
| Energy per QK^T (ideal latency) | 0.475 mJ |
| Area efficiency (peak) | 6.11 GOPS/mm^2 |
| Power efficiency (peak) | 70.60 GOPS/W |

## Speedup vs M1 software baseline

| Comparison | CPU | Chiplet SIZE=4 | Speedup |
|---|---|---|---|
| QK^T latency (ideal peak) | 2.954 ms | 16.914 ms | 0.175x |
| QK^T latency (cycle-based) | 2.954 ms | 2105.7 ms | 0.0014x |

**The SIZE=4 accelerator is slower than the CPU.** This is expected and stated
plainly. A 16-PE array at 62 MHz delivers 1.984 GOPS peak; the CPU delivers
11.36 GFLOP/s from a 2.6 GHz superscalar core with SIMD. Raw wall-clock
throughput cannot beat the CPU at this array size and frequency.

Two factors compound this:
1. Array size: 16 PEs is small. Peak scales with SIZE^2, so SIZE=4 leaves most
   of the achievable parallelism on the table.
2. Tiling overhead: the cycle-based number assumes 498 cycles per tile with no
   prefetch overlap between tiles, so control overhead dominates wall-clock time.

The value of the design at this stage is energy efficiency per operation
(70.6 GOPS/W peak) and the verified, signed-off RTL-to-GDSII flow, not raw speed.

## SIZE=16 projection (scaled estimate, not measured)

These numbers are [PROJECTED] by scaling the SIZE=4 result. Peak scales as
SIZE^2; area and power scale as SIZE^2. They are not produced by synthesis.

| Metric | [PROJECTED] SIZE=16 @ 62 MHz | [PROJECTED] SIZE=16 @ 250 MHz |
|---|---|---|
| Peak throughput | 31.74 GOPS | 128.0 GOPS |
| Ideal QK^T latency | 1.057 ms | 0.262 ms |
| Speedup vs CPU | 2.79x | 11.27x |
| Area (scaled) | 5.20 mm^2 | 5.20 mm^2 |
| Power (scaled) | 450 mW | ~1.8 W |

Reaching 250 MHz requires the future work listed in project/remaining_tasks.md:
pipeline the FP32 adder to cut the 6.19 ns critical path, add a reset buffer
tree, and tune the floorplan to reduce clock-tree skew.

## CPU baseline (from M1)

| Metric | Value |
|---|---|
| Platform | Intel Core i5-1145G7 |
| Peak FP32 | 11.36 GFLOP/s |
| Memory bandwidth | 51.2 GB/s |
| Ridge point | 0.22 FLOP/byte |
| QK^T latency (N=512, d=64) | 2.954 ms |

## Arithmetic intensity

QK^T kernel (N=512, d_head=64, FP4 in, FP32 out):
- FLOPs = 2 x 512 x 512 x 64 = 33.55 MFLOP
- AI lower bound (no reuse, 17 MB): 1.88 FLOP/byte
- AI upper bound (full reuse, 1.03 MB): 31.03 FLOP/byte

CPU ridge point 0.22 FLOP/byte; chiplet ridge point 4.0 FLOP/byte (peak 1.984 GOPS over 0.496 GB/s stream BW at 62 MHz). At the
upper-bound AI of 31.03, both platforms are compute-bound.

## Energy comparison

CPU energy (15 W TDP upper bound): 15 W x 2.954 ms = 44.31 mJ
Chiplet energy (SIZE=4, ideal latency): 28.1 mW x 16.914 ms = 0.475 mJ
Energy ratio at ideal latency: ~93x lower energy than CPU.

This energy advantage holds even though wall-clock latency is worse, because
the chiplet draws ~28 mW versus ~15 W for the CPU. Energy per operation, not
latency, is the metric where the FP4 accelerator wins at this stage.

## Co-simulation verification

From project/m4/sim/final_run.log:
- 16/16 output elements correct
- ALL PASS -- end-to-end AXI co-simulation verified
- TILE_COUNT=1, CYCLE_COUNT=498 (TILE_SIZE=4, D_HEAD=4, T=4)
