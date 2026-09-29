# Project status and development plan

This is the authoritative status of the active accelerator and the ordered plan
for completing it. Read this after the root README when you need implementation
detail, verified milestones, or the next acceptance gate.

## Current implementation

The active `qkt_chiplet_top` accepts packed 64-bit input packets and computes
dense attention score matrices from FP4 E2M1 Q and K inputs. The default uses
one FP32 scale per 16 reduction elements, exact block-local quarter-unit integer
accumulators, parallel FP32 scale multipliers, and an FP32 cross-block reduction.
Two banks for Q tiles, K tiles, block-local accumulators, and scores overlap
load, compute, scale, and output. Protocol version 5 reloads K per output tile; optional version
6 caches K for a whole command.

The active module list is `rtl/filelist.f`. The retained M4 package is the
reproducible course baseline, and [`archive/superseded-rtl/`](../archive/superseded-rtl/README.md)
contains comparison RTL used by one model test. The custom FP32 units round
finite normal results to nearest even but flush underflows and do not implement
every IEEE exception or signed-zero rule.

## Verified baseline

The default 4x4 top passes T=1/4/7/8/16 at `D_HEAD=4/64` and T=64/128/512 at
`D_HEAD=64`, including edge tiles, stalls, malformed packets, reset, and repeated
commands. At T=512 it produces 262,144 bit-exact scores in 1,050,690 simulated
core cycles. The optimized complete top routes with 30.5 ns setup timing, while
hold, antenna, slew, fanout, and valid dynamic power remain open. Detailed
measurements are in [performance results](results/performance.md) and
[physical design](results/physical-design.md).

## Completed and verified

- The active top uses [packed stream version 5](stream-protocol.md), with explicit
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
- A closed-form cycle model reproduces all 24 benchmarked configurations exactly,
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
  [the design-space record](results/performance.md).
- A fixed-input one-thread NumPy benchmark is the local software baseline. It is
  observed throughput, not a peak, so it is not a Roofline ceiling.
- P0.2 initially selected 1x32 FP32 block scales after a 120-point fixed-seed sweep. At
  T=512 it measures mean KL 0.01025, mean total variation 0.05665, top-1
  agreement 75.78%, and top-5 overlap 82.27%. See
  [ADR 0003](adr/0003-fp32-scales-with-32-element-blocks.md).
- P0.8 captured four pinned BERT heads across two model sizes. The real
  activation sweeps select 1x16 FP32 in
  [ADR 0004](adr/0004-use-1x16-fp32-scales.md). Protocol versions 5 and 6 make
  it the verified RTL default while retaining versions 3 and 4 for 1x32.
- P0.4 provides parameterized block accumulation and scaling. M2 now streams
  each completed block through the scale lanes and performs cross-block FP32
  additions sequentially. All 262,144 T=512 default RTL scores match the 1x16
  software model bit-exactly; RTL relative Frobenius error is 13.29%.
- P0.6 keeps the 64-bit output. Those pre-M2 lane results remain historical;
  block streaming changes the service requirement to one pass per block. The
  remeasured 8x8 L2 and 16x16 L4 points take 526,458 and 264,474 cycles, so
  scaling binds both until within-block lane counts increase.
- P0.5 closes register-based K reuse in
  [ADR 0005](adr/0005-close-register-k-reuse.md). Its projected slow-corner
  leakage alone reaches 0.686 mJ per T=512 command, while avoided DRAM energy
  is projected at 0.338 to 0.676 mJ. SRAM needs new routed power or host-link
  evidence before the question reopens.
- [ADR 0007](adr/0007-fix-eight-replicated-engines.md) fixes eight engines and
  protocol version 6 as the replication design point. The output port's
  131,072-cycle floor equals per-engine CALC work at exactly eight engines, the
  measured `ENGINES=16` command is identical to `ENGINES=8`, and version 5
  cannot reach the floor at any engine count.
- A measured output-format sweep shows FP16 scores change no capture's top-1
  agreement, so halving the output floor is not blocked by softmax quality. See
  [attention precision results](results/precision.md).
- The CPU baseline is refreshed with full host provenance. The system NumPy
  links reference Netlib BLAS at 9.0625 ms and 2.63% of the single-core peak;
  OpenBLAS runs the same problem in 0.2932 ms on one thread. Against an
  optimized BLAS the CPU wins on wall clock, so no speedup is claimed.
- The replicated-engine RTL is implemented and verified in simulation. Work
  splits by K tile column, so Q is broadcast and ordered retirement needs only a
  round-robin pointer rather than the reorder buffer ADR 0006 anticipated.
  Measured T=512 cycles fall from 1,050,696 to 266,344 at four engines under
  version 5, where the shared input port binds, and from 1,052,728 to 135,280
  at eight engines under version 6, where the output port binds. See the
  [measured replication result](results/performance.md).
- A replicated-engine study derives both shared-port ceilings. Version 3 stops
  improving at four 4x4 engines and 265,216 projected cycles; version 4 permits
  eight engines to reach 134,194 projected cycles. The conservative eight-engine
  mapped-area projection is 4,468,427 um² before physical cells, so the next
  second route remains the verified 16x16 L4 top. See the
  [replication result](results/performance.md).

## Roadmap: milestones M0 to M4

The live state, which milestone step is active and what runs next, is in the
root [`CODEX.md`](../CODEX.md), which both agents update after every verified
commit. This section is the plan; that file is the position within it.

This roadmap replaces the P0.7b stage list. It came from a literature review on
2026-09-29 recorded in [related work](related-work.md), which showed that my
1x16 FP4 block choice re-derives NVFP4 and so is not new by itself. Novelty has
to come from choosing formats and hardware together, judged by softmax fidelity
and by measured area, energy, and timing in an open PDK. Every step is one
commit sized for one agent session; each milestone ends with a results record,
an ADR where a decision is made, a handoff entry in the root `CODEX.md`, and my
review. The first session after a milestone re-runs its gate before new work.

**M0, housekeeping and toolchain. Complete.** The floorplan result is recorded,
the old run trees are deleted, LibreLane 3.0.14 is installed, and the flow is
ported. The gate run took a `D_HEAD=4` configuration from RTL to GDS with zero
DRC, LVS, and antenna violations; see
[the M0 gate result](results/physical-design.md).

Original scope: Record the P0.7b floorplan result, then
delete the old `build/physical` trees. Install LibreLane 3.x with its `ciel`
PDK manager, port the OpenLane configuration and SDC, and keep the pinned
OpenLane 1.1.1 image only to reproduce recorded results. Gate: LibreLane smoke
test, synthesis parity with the current netlist, and a small configuration from
RTL to clean GDS.

**M1, arithmetic decisions in software.** Extend `scripts/eval_precision.py`
with scale formats (FP32, E4M3 with a tensor scale, E8M0 with the 7.25 clipping
boundary, per-block four-or-six, and scale search), softmax-invariant
preprocessing (K mean-centering and Hadamard rotation), per-block FP4 or INT4,
sequential versus tree cross-block accumulation, and an exponent-only score
bound for skipping. Add at least two modern decoder heads with `D_HEAD=64`.
Probe scaler and multiplier cost with synthesis-only runs.
**Complete:** [ADR 0008](adr/0008-e4m3-block-scales.md) selects the scale format:
searched E4M3, which is more accurate than FP32 on every softmax metric and
4.89 times smaller in the scaling path. The element format and preprocessing
study is now measured: neither K centering nor Hadamard rotation improves all
softmax metrics across all four captures, so neither becomes the default.
Per-block FP4/INT4 selection lowers mean KL, TV, Frobenius error, and raises
top-5, but loses 0.34 top-1 points and regresses on the larger-model capture.
It remains a layer-selective P1 candidate rather than a global default.
Sequential versus tree cross-block addition is also settled: a tree changes up
to 29.4% of score bit patterns but moves no top-k result and changes scores by
at most `1.53e-5`. M2 keeps sequential order to preserve bit exactness.
The exponent-only bound is also measured. At a four-logit margin it safely
identifies 28.83% of scores and 8.66% of complete 4x4 tiles on average with no
top-k change, but it requires a row maximum and coverage varies from zero to
18.38% of tiles by capture. It remains a later experiment rather than M2 scope.
Two post-RoPE SmolLM2 decoder heads validate the arithmetic choices out of
sample. Searched E4M3 retains better aggregate softmax and raw-score metrics
than FP32 and E8M0. Preprocessing and adaptive FP4/INT4 remain layer-dependent.
The exponent bound covers no complete 4x4 decoder tile at tau=4, so fixed
exponent-bound skipping is rejected as a general P0 feature.
[ADR 0009](adr/0009-use-e2m1-shift-add-products.md) selects exact E2M1
shift/add products after formal equivalence and same-library mapping: 381.62
um2 against 872.09 um2 for the generic integer multiply in isolation. A
same-flow complete-top comparison saves 3,313 cells but only 0.046% mapped
area, so M2 routing rather than the standalone projection decides its value.
M1 is complete.

**M2, P0 closure: the first routed milestone.** The block-streaming accumulator
now hands each 16-deep block to the scaler as it completes, removing the
tile-wide accumulator and its dynamic read mux while preserving every score
bit. ADR 0009 shift/add products are active. Next implement the ADR 0008 scaler
and route in LibreLane
with placement timing repair on and signoff at three corners. Annotate switching
activity from gate-level simulation of the pinned workload to obtain the
project's first valid dynamic power and energy per score. Gate: setup and hold
non-negative at every corner; zero slew, fanout, DRC, and LVS violations;
antenna resolved or explicitly accepted.

**M3, P1 tracks against the M2 baseline, measured after routing.** 3a,
format-selectable multiplication including the wide shared and packed options.
3b, per-block FP4 or INT4 selected by a one-bit flag in a separately versioned
stream. 3c, a layer-selected sparsity policy; fixed exponent-bound skipping is
not carried forward because the decoder validation found no skippable 4x4 tile.

**M4, integration.** The prior-art review it required is already done; see
[related work](related-work.md). Remaining: Route the best combined configuration, including the
eight-engine design point from ADR 0007 if the area allows, finish the related
work review, and optionally compare `sky130_fd_sc_hs`.

## P0, active: dense FP4 matrix multiplication

Stages and their exit conditions are in
[the P0 page](problem-statements/p0-dense-fp4-matmul.md). In short:

1. **P0.1, repository and documentation hygiene.** Done when `make check-docs`
   passes the contract checks and no document references a path that does not
   exist.
2. **P0.2, decide the scale format in software.** Complete. The sweep covered
   Bs 64, 32, 16, 8, 4, and 2 with FP32 and three E8M0 rules.
   [ADR 0003](adr/0003-fp32-scales-with-32-element-blocks.md) initially selected 1x32 FP32:
   one cross-block FP32 add is a better P0 point than the three required by
   1x16, while all three measured E8M0 rules lose to the FP32 baseline.
3. **P0.3, overlap the phases.** Complete. Two-bank Q, K, accumulator, and score
   storage lets independent sequencers run concurrently. Measured 4x4 array
   activity is 99.945% and speedup is 1.736x at T=512. Scaling binds at 8x8 and
   16x16; [the architecture record](architecture.md) gives the exact model.
4. **P0.4, implement the chosen format in RTL.** Complete. The parameterized
   scaler supports both Bs=16 and Bs=32. The Bs=16 default matches the software
   model bit-exactly in the full T=512 suite.
5. **P0.6, decide the output width from measurement.** Complete. Keep 64 bits;
   widen score scaling first. Two lanes are sufficient at 8x8 and four reach
   the output limit at 16x16.
6. **P0.7, route the complete top.** Active. Checkpoint 1 of
   [ADR 0006](adr/0006-use-replicated-4x4-engines.md) is complete: the
   replicated-engine RTL exists, `ENGINES=1` is bit-identical and
   cycle-identical to the previous top, and `ENGINES=1/2/4/8/16` are bit-exact
   in simulation. Mapped area and a routed result remain open. The optimized 4x4 route is DRC/LVS
   clean and closes setup at 30.5 ns, but worst multi-corner hold slack is
   -1.2765 ns. It has antenna, slew, and fanout violations, and its dynamic
   power is rejected. The selected 16x16 L4 follow-up remains blocked by accumulator synthesis
   scaling after two bounded alternatives, so ADR 0006 selects replicated 4x4
   engines as the next prototype. See [the physical result](results/physical-design.md).
   P0.7b then reworked synthesis and control timing (mapped slow-corner minimum
   period 20.593 ns to 18.241 ns) but no floorplan routed: congestion is
   dominated by the accumulator banks. Closure moves to roadmap milestone M2.
7. **P0.5, decide K-reuse storage from routed energy evidence.** Complete for
   the current implementation. Close register K reuse; its full-capacity area
   does not fit the current die and the conservative slow-corner leakage
   projection exceeds the projected DRAM saving. Reopen for a measured SRAM
   implementation, a higher-energy host link, or a bandwidth-bound workload.
8. **P0.8, measure error on real transformer activations.** Complete for the P0
   decision. Four pinned heads across two BERT sizes select 1x16 FP32; broader
   architectures and tasks remain future validation rather than a blocker.

P0.7 moved ahead of P0.5 because phase overlap removed K reuse's original cycle
benefit. The routed slow-corner leakage and historical full-capacity area are
enough to reject the register implementation conservatively, even though
dynamic power remains invalid. ADR 0005 records the projection and its limits.

### A correction to an earlier assumption

The block-scale implementation makes one score lane cost
`ceil(B^2/L) + 10` cycles per tile at Bs=32: one scale-prefetch cycle, six
multiplier drain cycles, and three cross-block-add drain cycles. At 8x8, `L=2`
gives 42 scaling cycles, below
64-cycle CALC; output is only 32 cycles and cannot bind. At 16x16, `L=2` still
binds in scaling at 138 cycles, while `L=4` gives 74 scaling cycles and exposes
the 128-cycle output limit. The measured 132,362-cycle command confirms the
131,072-cycle steady output floor plus 1,290 fill and drain. The derivation and
per-stage table are in [architecture](architecture.md).

## P1, next: format-agile precision and sparsity

Starts after P0.7 signoff, because energy by format needs a routed, hold-clean
baseline with qualified power. Stages, the accumulator-width arithmetic, the
five-option multiplier study, and the sparsity question are in
[the P1 page](problem-statements/p1-format-agile-sparsity.md).

## P2, shelved

Recorded in [the P2 page](problem-statements/p2-programmable-accelerator.md).
Nothing starts without an explicit decision.

## Standing constraints

Keep protocol version 5 block-scaled FP4 and dense FP32 scores as the default.
The selected format is not OCP MXFP4, which
uses 32-value blocks and E8M0 scales. Softmax and V fusion stay outside this project's scope.

Use the original [Roofline model](https://www2.eecs.berkeley.edu/Pubs/TechRpts/2008/EECS-2008-134.html)
only with an explicit memory boundary and measured bandwidth, and never treat
measured CPU throughput as CPU peak performance.

Do not infer an active clock from the archived array-only 15 ns run, which has
negative nominal setup and hold slack.

## Related

- [Research questions](problem-statements/README.md)
- [Related work](related-work.md)
- [Handoff log archive](handoff-log.md)
- [Architecture](architecture.md)
- [Verification plan](verification-plan.md)
- [Decision records](adr/README.md)
- [Documentation index](README.md)
