# Project context

I use this document to keep the main project details in one place. I am keeping
the milestone directories as submission snapshots, and I separate results I
measured from features I still plan to build.

## Mission

My goal is to build a chiplet-style accelerator for the `Q * K^T` part of
transformer self-attention. The inputs use microscaled FP4 E2M1, dot products
accumulate in FP32, and each final score is multiplied by its Q-row and K-row
scale factors. I use AXI4-Lite for control and AXI4-Stream for matrix data. The
course version targets Sky130 HD.

I currently accelerate only `Q * K^T`. Attention scaling, masking, softmax, and
the multiplication by V remain on the host.

## Verified course baseline

- Canonical course snapshot: `project/m4/`
- Array actually simulated and synthesized: 4x4
- Simulation parameters: `TILE_SIZE=4`, `D_HEAD=4`, `T_MAX=16`
- End-to-end numerical result: 16/16 outputs pass for one 4x4 tile
- Recorded simulation cycle count: 498 cycles
- Physical-design flow: OpenLane 1.1.1, Sky130 HD
- Reported synthesis area: 324,753 um^2 and 30,689 cells
- Signoff run: 44 steps complete, DRC=0, LVS and XOR clean
- Configured clock period: 15 ns; project documentation recommends about
  62 MHz because of post-route margin
- Reported typical power: 28.1 mW
- A 16x16 implementation and its performance are projections, not measured
  results

I rebuilt the baseline with Verilator 5.041 on 2026-09-24 and reproduced the
16/16 numeric pass. The same run printed `STATUS=0x00000000 DONE=NO`, but the old
test does not fail on that result. I therefore do not count completion behavior
as verified yet.

## Current data path

1. The host programs matrix size and start through `axi4_lite_ctrl`.
2. `tile_controller` receives Q/K scale factors through the input stream and
   stores them in `scale_sram`.
3. It loads one Q tile and one K tile into `tile_buffer`.
4. It feeds one reduction dimension per cycle to `systolic_array`.
5. Every PE converts an FP4 product to FP32 through a 256-entry LUT, buffers all
   `D_HEAD` products, then serially accumulates them with `fp32_add`.
6. The controller copies the tile result, applies `S_Q[i]` and `S_K[j]` using
   two serial FP32 multiplies, and streams results to the host.

The PE is meant to be output-stationary, but it does not perform one MAC every
cycle. It collects the products first and then adds them in series. I need to
account for that behavior in all throughput and area estimates.

## Module map

| Module | Responsibility |
| --- | --- |
| `qkt_chiplet_top.sv` | AXI control, controller, memories, array, and dequantizer integration |
| `axi4_lite_ctrl.sv` | Register interface for start, status, dimensions, and counters |
| `tile_controller.sv` | Load/compute/dequantize/stream finite-state machine and tile traversal |
| `tile_buffer.sv` | Q, K, and output tile storage |
| `scale_sram.sv` | Q and K microscale storage |
| `systolic_array.sv` | Parameterized PE grid and input staggering |
| `systolic_array_flat.sv` | Flat-port synthesis wrapper for the older Yosys frontend |
| `pe.sv` | FP4 product collection and FP32 accumulation |
| `fp4_mul_lut.sv` | Complete FP4 E2M1 pair-to-FP32 product ROM |
| `fp4_mul.sv` | Registered one-cycle LUT wrapper |
| `fp32_add.sv` | Three-stage custom FP32 adder |
| `fp32_mul.sv` | Three-stage custom FP32 multiplier used for dequantization |

## Register and stream contract currently exercised

The testbench writes matrix size at `0x08`, writes start at `0x00`, and reads
status at `0x04`, tile count at `0x0c`, and cycle count at `0x10`.

The implementation and comments disagree about stream packing:

- Scales are described as two FP32 values per 64-bit beat, but only bits 31:0
  are consumed and the counter advances by one.
- Q and K are described as sixteen FP4 values per beat, but only bits 3:0 are
  consumed and the counter advances by one.
- Results are described as two FP32 values per beat, but one result is placed
  in bits 63:32 and the lower half is zero.

Until I redesign and test the protocol, host software has to follow the actual
one-value-per-beat behavior.

## Known correctness and scalability gaps

These are limits I found while reviewing the design. They do not change the M4
course result.

1. **PEs are one-shot after reset.** `prod_count` stays at `D_HEAD` and the
   accumulation FSM stays in `DONE`. There is no tile-level clear, so more than
   one output tile cannot be trusted.
2. **Completion is not asserted in the passing regression.** The baseline test
   prints `DONE=NO` but checks only numerical outputs.
3. **The end-to-end test covers exactly one tile.** It does not exercise K-tile
   iteration, Q-tile iteration, matrix-edge handling, backpressure, or a second
   command without reset.
4. **Parallel array input wiring is ambiguous.** The top level connects
   parallel buffer data to array inputs while `tile_controller` also declares
   and drives those array-input ports using legacy single-read signals. This
   should be reduced to one owner.
5. **Stream bandwidth is underused.** The implementation transfers one useful
   scalar per 64-bit beat despite the packing comments.
6. **Power-of-two assumptions are implicit.** Shift-based tile-count logic and
   `$clog2` address slicing do not define behavior for partial tiles or several
   parameter values, including dimensions of one.
7. **Floating-point arithmetic is limited.** The custom units omit full IEEE
   754 rounding and robust overflow/underflow/subnormal handling. Accuracy must
   be specified and tested rather than assumed.
8. **Synthesis is not full-chip synthesis.** The final physical-design target
   is the flat systolic-array wrapper; AXI, controller, buffers, scale storage,
   and dequantization are co-simulated but excluded from the reported layout.

## Repository topology

- `codefest/`: independent weekly course exercises and reports
- `project/m1/`: workload, interface, and architecture proposal
- `project/m2/`: initial RTL, golden data, and most reusable unit testbenches
- `project/m3/`: integration and early synthesis snapshot
- `project/m4/`: final course snapshot and the best current RTL copy
- `project/upgrade_archive/`: abandoned/experimental upgrade snapshot
- `smoke_test/`: small Verilator environment check

Most modules under `project/m2/rtl`, `project/m3/src`, and `project/m4/src` are
byte-identical. I will keep one active source tree and leave the milestone
snapshots unchanged.

## Working rules for future changes

- Preserve `project/m1` through `project/m4` as historical artifacts.
- Do new work in a canonical development tree after it is introduced.
- Never report projected 16x16 results as measured.
- Add a failing regression that demonstrates a bug before fixing it.
- Treat numerical correctness, protocol correctness, performance, and physical
  design as separate verification gates.
- Keep generated simulator and OpenLane run directories out of Git. Curated
  logs, metrics, plots, and final signoff artifacts may be retained deliberately.
- Re-run the 4x4 baseline after every architectural change.
