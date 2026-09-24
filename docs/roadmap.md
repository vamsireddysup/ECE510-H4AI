# Development plan

This is the order of work and the evidence each step has to produce. It follows
the numbered problem statements: P0 is active, P1 is next, P2 is shelved. See
[problem statements](problem-statements/README.md) for what each one has to prove.

CPU speedup is a result to measure, not a design assumption. The M1-M4 snapshots
stay unchanged in [`archive/`](../archive/README.md).

## Completed and verified

- The active top uses [packed stream version 1](stream-protocol.md), with explicit
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
- A closed-form cycle model reproduces all six benchmarked configurations exactly,
  including both protocols and all three tile sizes. See
  [architecture](architecture.md) and `scripts/cycle_model.py`.
- Optional stream version 2 loads K once per command, cutting host traffic 2.9x
  and input beats 57.4x. Its register scratchpad grows mapped area 4.18x at full
  capacity, so version 1 stays default. See
  [ADR 0002](adr/0002-k-reload-is-the-default.md).
- 8x8 and 16x16 builds pass simulation, and all three tile sizes map through
  full-top Sky130 cell synthesis. See
  [the design-space record](results/design-space.md).
- A fixed-input one-thread NumPy benchmark is the local software baseline. It is
  observed throughput, not a peak, so it is not a Roofline ceiling.
- P0.2 selected 1x32 FP32 block scales after a 60-point fixed-seed sweep. At
  T=512 it measures mean KL 0.01025, mean total variation 0.05665, top-1
  agreement 75.78%, and top-5 overlap 82.27%. See
  [ADR 0003](adr/0003-fp32-scales-with-32-element-blocks.md).

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
3. **P0.3, overlap the phases.** Double-buffer Q, K, and output so load, compute,
   scale, and output run concurrently. Format-independent, so it does not wait on
   P0.2. Worth 1.74x at 4x4 by the cycle model. Done when measured array-active
   exceeds 90% at 4x4, or a record names the stage that now binds.
4. **P0.4, implement the chosen format in RTL.** Done when RTL error matches the
   model and integration passes at every tested T and `D_HEAD`.
5. **P0.5, give the K scratchpad banked storage.** The installed 2 KiB Sky130
   macro gives 16 KiB in 2,276,308 um² before routing, against 6,672,971 um² for
   the register array, but its read is clocked and needs address scheduling the
   combinational array does not have.
6. **P0.6, decide the output width from measurement**, not from assumption. See
   the correction below.
7. **P0.7, route the complete top** at the selected configuration and record PDK
   and tool revision, clock constraint, area, setup and hold slack, power, and
   congestion. This is the first routed result for this top.
8. **P0.8, measure error on real transformer activations,** with the capture
   pinned by SHA-256.

### A correction to an earlier assumption

An earlier version of this plan expected the 64-bit output cap of two FP32 scores
per cycle to become the limiting stage once the phases overlap. It does not.
`SCALING` launches one score per cycle, so it costs `B^2 + 6` cycles per tile
against the output path's `ceil(B^2/2)`, roughly twice as long at any tile size.
Under perfect overlap the binding stage is `CALC` at 4x4, and `SCALING` at both
8x8 and 16x16. The output port only binds after the scale pipeline is widened:
16x16 at T=512 would then take `1024 * 128 = 131,072` cycles, which is exactly
`262,144 / 2`, the output-port floor. The derivation and the per-stage table are
in [architecture](architecture.md).

That makes the scale pipeline the first thing to widen, and widening it is cheap
if the scales become powers of two, because a power-of-two scale is an exponent
addition rather than a multiplication. P0.2 and P0.3 therefore reinforce each
other.

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

Keep version 1 row-scale FP4 and dense FP32 scores as the default until P0.4
implements the 1x32 FP32 decision. The selected format is not OCP MXFP4, which
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
