# QK^T accelerator development plan

I am developing a dense FP4 E2M1 QK^T accelerator for Sky130 with FP32 output
scores and per-row FP32 Q/K scales. The goal is correct larger workloads and a
measured improvement over the course RTL. CPU speedup is a result to measure,
not a design assumption. The M1-M4 snapshots remain unchanged in `archive/`.

## Completed and verified

- The active top uses [packed stream version 1](stream-protocol.md), explicit
  packet-length checks, a full-width matrix dimension, partial-tile masking,
  and stable output under stalls.
- A 4x4 grid accumulates signed FP4 half-unit products in exact quarter-unit
  registers. It converts once per score, then uses two pipelined FP32 scale
  multipliers. The old serial FP32 PE and controller remain as reference RTL.
- Integration tests cover `D_HEAD=4/64`, T=1/4/7/8/16, malformed packets,
  reset, repeated commands, stalls, and the original numerical pattern.
  A separate no-stall run checks T=64/128/512 at `D_HEAD=64`.
- Counters expose accepted beats, stalls, dot cycles, scale cycles, completed
  tiles, and command cycles. The [reviewed results](results/packed-engine.md)
  state the host-stream byte boundary and synthesis scope.
- A fixed-input, one-thread NumPy benchmark replaces the archived CPU timing
  as the local software baseline. It is observed throughput, not a peak
  ceiling for a Roofline model.
- A fixed-seed synthetic precision evaluation measures row-scaled FP4 score
  error against FP32 QK^T. At T=512 its relative Frobenius error is 14.90%
  under the stated quantizer. It is not a real-activation result; see
  [the precision record](results/precision.md).
- Optional stream version 2 loads K once into an RTL scratchpad. I verified
  it at T=512 and measured its byte and cycle savings. Full-capacity
  standard-cell mapping grows to 6.67 mm², so it remains an experiment. I
  also verified 8x8 and 16x16 versions of the default stream and mapped all
  three tile sizes
  through full-top Sky130 cell synthesis. The [design-space record](results/design-space.md)
  keeps this evidence separate from timing closure.

## Next: memory reuse and overlap

1. Implement physical K scratchpad banking or choose register storage after
   comparing full-capacity area, read latency, bank conflicts, and routed
   timing. Version 2 proves the command-level traffic benefit; the installed
   2 KiB Sky130 macro has a large footprint and a clocked read port.
2. Double-buffer Q and output tiles to overlap input, compute, scale, and
   output. Measure sustained scores per cycle, including host stalls. The
   64-bit output cap is two FP32 scores per cycle, so test whether it becomes
   the limiting stage before widening the interface.
3. Compare the current exact integer array with the retained serial FP32 PE
   using identical complete workloads and integrated-top synthesis. Report
   numerical difference, cell area, timing, and estimated energy separately.

## Next: physical design and array size

1. Close timing and route the complete top at 4x4 with `D_HEAD=64`; record
   PDK/tool revision, clock constraint, area, setup/hold slack, power, and
   congestion. Current Yosys Sky130 cell area is synthesis only.
2. Route the already simulated 8x8 and 16x16 variants with identical workloads,
   then sweep buffering, K bank count, scale depth, and clock constraint.
   Select the fastest verified design that closes full-chip Sky130 checks;
   retain smaller Pareto alternatives.
3. Benchmark T=4/16/64/128/512 with actual tile counts, useful and transferred
   bytes, simulated cycles, timing-closed frequency, and full-chip PPA. Do not
   infer the active clock from the archived array-only 15 ns run, which has
   negative nominal setup and hold slack.

## Later precision experiments

Keep version 1 row-scale FP4 and dense FP32 scores as the default. Measure
score error on synthetic vectors and pinned transformer activations against
FP32 QK^T. A block-scaled format, narrower output, or structured sparsity
needs a separate version and end-to-end traffic and accuracy evidence. Current
row scaling is not OCP MXFP4; compliant MXFP4 uses 32-value blocks and E8M0
scales. Softmax and V fusion remain outside this project scope.

I use the original [Roofline model](https://www2.eecs.berkeley.edu/Pubs/TechRpts/2008/EECS-2008-134.html)
only with an explicit memory boundary and measured bandwidth. I will not use
measured CPU throughput as CPU peak performance.
