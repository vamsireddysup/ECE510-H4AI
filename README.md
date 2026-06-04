# ECE 510 -- Hardware for AI/ML -- Spring 2026
# FP4 QK^T Accelerator Chiplet

**Student:** Vamsidhar Reddy Eraganeni
**Course:** ECE 510, Portland State University, Spring 2026

## Project

Custom co-processor chiplet accelerating the QK^T attention score computation
using FP4 E2M1 multiply and FP32 accumulate on a systolic array, implemented on
the Sky130 HD process. The chiplet uses AXI4-Lite for control and AXI4-Stream
for data streaming.

The synthesized and verified design is a **4x4 systolic array (SIZE=4)**. A
16x16 array (SIZE=16) is the longer-term design target; all SIZE=16 figures in
this repository are explicitly labeled as projected, not measured.

## M4 Final Submission

The complete M4 deliverable package is in **[project/m4/](project/m4/README.md)**.

Key results (final M4 OpenLane run, project/m4/synth/):
- 4x4 FP4 systolic array, AXI4-Lite + AXI4-Stream interfaces
- Co-simulation: 16/16 PASS end-to-end (project/m4/sim/final_run.log)
- Full 44-step OpenLane signoff: SUCCESS, DRC=0, LVS clean, XOR clean
- Synthesis area: 329,148 um^2 (SIZE=4), 31,560 cells
- Clock period closed at: 15.0 ns; suggested operating frequency ~62 MHz
- Speedup vs CPU: see project/m4/bench/benchmark.md (honest projected numbers)
- Design justification report: [project/m4/report/design_justification.pdf](project/m4/report/design_justification.pdf)

### Why 62 MHz, not the 250 MHz design target

The M1 proposal targeted 250 MHz. The synthesized design closes timing at a
longer clock period for two reasons, both documented in the design
justification report and benchmark:

1. The FP32 accumulate path (fp32_add) is the critical path at ~6.2 ns of logic
   plus clock-tree skew/uncertainty. At an aggressive 4.0 ns clock the post-route
   setup slack was negative (WNS down to -8.49 ns), so the period was relaxed
   until the flow closed cleanly.
2. Clock-tree skew on a single-clock flat netlist adds margin that pushes the
   required period above the raw logic delay.

Planned improvements to reach higher frequency (future work):
- Pipeline the FP32 adder mantissa path into additional stages to cut the ~6.2 ns
  critical path below 4 ns, enabling timing closure at a shorter period.
- Add an explicit reset buffer tree to reduce high-fanout reset distribution.
- Floorplan tuning (aspect ratio, macro placement) to reduce clock-tree skew.
- Explore retiming during synthesis to balance the accumulate pipeline.

## Milestone structure

| Milestone | Location | Status |
|---|---|---|
| M1 | project/m1/ | Done |
| M2 | project/m2/ | Done |
| M3 | project/m3/ | Done |
| M4 | project/m4/ | Done |

## Repository

GitHub: https://github.com/vamsireddysup/ECE510-H4AI
