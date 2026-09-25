# Development plan

This is the order of work and the evidence each step has to produce. It follows
the numbered problem statements: P0 is active, P1 is next, P2 is shelved. See
[problem statements](problem-statements/README.md) for what each one has to prove.

CPU speedup is a result to measure, not a design assumption. The M1-M4 snapshots
stay unchanged in [`archive/`](../archive/README.md).

## Completed and verified

- The active top uses [packed stream version 3](stream-protocol.md), with explicit
  packet-length checks, a full-width matrix dimension, partial-tile masking, and
  output that stays stable under stalls.
- A `TILE_SIZE x TILE_SIZE` grid accumulates signed FP4 half-unit products in
  exact quarter-unit registers, converts once per score, then applies two
  pipelined FP32 scale multipliers. See
  [ADR 0001](adr/0001-exact-integer-accumulation.md).
- Integration tests cover `D_HEAD=4/64`, T=1/4/7/8/16, malformed packets, reset,
  repeated commands, stalls, AXI4-Lite handshake ordering, and the original M4
  numerical pattern. A no-stall run covers T=64/128/512 at `D_HEAD=64`. The full
  matrix is in the [verification plan](verification-plan.md).
- Counters expose accepted beats, stalls, dot cycles, scale cycles, completed
  tiles, and command cycles.
- A closed-form cycle model reproduces all 16 benchmarked configurations exactly,
  including both protocols and all three tile sizes. See
  [architecture](architecture.md) and `scripts/cycle_model.py`.
- P0.3 overlaps input, exact dot products, scaling, and output through two Q, K,
  accumulator, and score banks. The 4x4 T=512 run falls from 1,821,184 to
  1,049,150 cycles and reaches 99.945% array activity before the block-scale
  format change. The extracted scaler binds
  at 8x8 and 16x16.
- Optional stream version 4 loads K once per command, cutting host traffic 2.9x
  and input beats 57.4x. Its register scratchpad grows mapped area 4.18x at full
  capacity, so version 3 stays default. See
  [ADR 0002](adr/0002-k-reload-is-the-default.md).
- 8x8 and 16x16 builds pass simulation, and all three tile sizes map through
  full-top Sky130 cell synthesis. See
  [the design-space record](results/design-space.md).
- A fixed-input one-thread NumPy benchmark is the local software baseline. It is
  observed throughput, not a peak, so it is not a Roofline ceiling.
- P0.2 selected 1x32 FP32 block scales after a 120-point fixed-seed sweep. At
  T=512 it measures mean KL 0.01025, mean total variation 0.05665, top-1
  agreement 75.78%, and top-5 overlap 82.27%. See
  [ADR 0003](adr/0003-fp32-scales-with-32-element-blocks.md).
- P0.4 implements that decision as protocol versions 3 and 4. The default path
  keeps one exact accumulator per 32-element block, scales both blocks in
  parallel, and combines them with one FP32 add. All 262,144 T=512 RTL scores
  match the software model bit-exactly; RTL relative Frobenius error is 14.23%.
- P0.6 keeps the 64-bit output. At 8x8, two score lanes move the binding stage
  from scaling to CALC and complete T=512 in 263,305 cycles. At 16x16, four
  lanes move it to output and complete in 132,361 cycles, 1,289 cycles above
  the two-score-per-cycle steady floor.

## P0, active: dense FP4 matrix multiplication

Stages and their exit conditions are in
[the P0 page](problem-statements/p0-dense-fp4-matmul.md). In short:

1. **P0.1, repository and documentation hygiene.** Done when `make check-docs`
   passes the contract checks and no document references a path that does not
   exist.
2. **P0.2, decide the scale format in software.** Complete. The sweep covered
   Bs 64, 32, 16, 8, 4, and 2 with FP32 and three E8M0 rules.
   [ADR 0003](adr/0003-fp32-scales-with-32-element-blocks.md) selects 1x32 FP32:
   one cross-block FP32 add is a better P0 point than the three required by
   1x16, while all three measured E8M0 rules lose to the FP32 baseline.
3. **P0.3, overlap the phases.** Complete. Two-bank Q, K, accumulator, and score
   storage lets independent sequencers run concurrently. Measured 4x4 array
   activity is 99.945% and speedup is 1.736x at T=512. Scaling binds at 8x8 and
   16x16; [the architecture record](architecture.md) gives the exact model.
4. **P0.4, implement the chosen format in RTL.** Complete. The parameterized
   Bs=32 default matches the software model bit-exactly, and Bs=16 also passes
   the small integration suite.
5. **P0.6, decide the output width from measurement.** Complete. Keep 64 bits;
   widen score scaling first. Two lanes are sufficient at 8x8 and four reach
   the output limit at 16x16.
6. **P0.7, route the complete top.** This now precedes P0.5. Record PDK
   and tool revision, clock constraint, area, setup and hold slack, power, and
   congestion. This is the first routed result for this top.
7. **P0.5, decide K-reuse storage from routed energy evidence.** Version 4 is
   2,032 cycles slower, while version 3 uses only 396,288 stream beats over
   1,049,665 cycles, or 37.75% of one accepted beat per cycle. K reuse therefore
   has no measured latency case. After P0.7 supplies power, compare the projected
   energy of 2,080,768 avoided host bytes with the register or SRAM area and
   power cost. Implement the installed 2 KiB macros only if that comparison wins.
8. **P0.8, measure error on real transformer activations,** with the capture
   pinned by SHA-256.

P0.7 moves ahead of P0.5 because phase overlap removed K reuse's original cycle
benefit. Its remaining 2.91x traffic reduction may save off-chip energy, but that
projected saving cannot be weighed against 4.18x mapped register area without a
routed power baseline. P0.5 is now a decision made from that evidence rather
than a prescheduled SRAM implementation.

### A correction to an earlier assumption

The block-scale implementation makes one score lane cost
`ceil(B^2/L) + 9` cycles per tile at Bs=32: six multiplier drain cycles and
three cross-block-add drain cycles. At 8x8, `L=2` gives 41 scaling cycles, below
64-cycle CALC; output is only 32 cycles and cannot bind. At 16x16, `L=2` still
binds in scaling at 137 cycles, while `L=4` gives 73 scaling cycles and exposes
the 128-cycle output limit. The measured 132,361-cycle command confirms the
131,072-cycle steady output floor plus fill and drain. The derivation and
per-stage table are in [architecture](architecture.md).

## P1, next: format-agile precision and sparsity

Starts no earlier than P0.4, because measuring the cost of changing format needs a
settled baseline format and a settled accumulator. Stages, the accumulator-width
arithmetic, the five-option multiplier study, and the sparsity question are in
[the P1 page](problem-statements/p1-format-agile-sparsity.md).

Before P1.2 starts, the full text of the closest prior art has to be read, not
just its abstract. If the gap closes, P1 changes.

## P2, shelved

Recorded in [the P2 page](problem-statements/p2-programmable-accelerator.md).
Nothing starts without an explicit decision.

## Standing constraints

Keep protocol version 3 block-scaled FP4 and dense FP32 scores as the default.
The selected format is not OCP MXFP4, which
uses 32-value blocks and E8M0 scales. Softmax and V fusion stay outside this project's scope.

Use the original [Roofline model](https://www2.eecs.berkeley.edu/Pubs/TechRpts/2008/EECS-2008-134.html)
only with an explicit memory boundary and measured bandwidth, and never treat
measured CPU throughput as CPU peak performance.

Do not infer an active clock from the archived array-only 15 ns run, which has
negative nominal setup and hold slack.

## Related

- [Problem statements](problem-statements/README.md)
- [Architecture](architecture.md)
- [Verification plan](verification-plan.md)
- [Decision records](adr/README.md)
- [Documentation index](README.md)
