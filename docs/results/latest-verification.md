# Latest verification

## September 29 LibreLane M0 gate

LibreLane 3.0.14 completed the 4x4, `D_HEAD=4`, `T_MAX=16`, Bs=16,
one-engine top through final GDS on a 900 um die. Detailed-route, Magic, and
KLayout DRC are zero; LVS matches uniquely; final antenna violations are zero.
This passes the M0 toolchain gate.

The 20 ns physical run is not timing closed. Worst slow-corner setup slack is
-2.0313 ns over 202 endpoints, and hold slack is -0.0605 ns on one endpoint.
The final metrics also report 5,061 maximum-slew and 145 maximum-capacitance
violations. The vectorless 18.6 mW estimate is rejected as an energy result.
Full provenance and limits are in the
[physical-design record](physical-design.md).

## September 28 baseline, model, and output-format run

I refreshed the CPU baseline with host provenance, closed the cycle model,
registered the shared Q read, and measured narrower output scores.

The one-thread benchmark path is unchanged, so its re-run isolates the machine:
9.0625 ms against the recorded 9.016 ms. The previously unverified thread claim
is resolved. System NumPy 1.26.4 links reference Netlib BLAS 3.12.0, which has
no thread pool to detect and does not thread at all; the new `--all-cores` run
measures 9.0722 ms, confirming it. An isolated NumPy 2.5.3 with OpenBLAS
0.3.34.106.0 runs the same problem in 0.2932 ms on one thread, 81.29% of the
single-core AVX-512 peak, and 0.1422 ms across four cores.

The cycle model now reproduces all 32 measured configurations exactly and fails
on any mismatch again. Two derived terms were added: an engine-saturation
crossover and a trailing-retirement stagger, plus an input-bound load tail.

Registering the shared Q read changed no score and no cycle count at any engine
count or tile size; `make test`, every large suite at `ENGINES=1/2/4/8/16`, the
8x8 and 16x16 large suites, the Bs=32 suite, and `make test-precision-rtl` at
`ENGINES=1` and `ENGINES=8` all reproduce their recorded values.

The output-format sweep quantizes finished scores to FP16 and BF16 across all
four pinned captures. FP16 changes no capture's top-1 agreement. This is a
software measurement; no RTL implements a 16-bit score.

## September 28 replicated-engine checkpoint 1

I extracted the per-engine compute pipeline into `rtl/core/qkt_engine.sv` and
added an `ENGINES` parameter that defaults to 1. At `ENGINES=1` the design is
bit-identical and cycle-identical to revision `212161f`: every small, large,
K-reuse, 8x8, 16x16, and Bs=32 suite reproduces its previous cycle count, and
`make test-precision-rtl` still reports 1,050,696 cycles with 13.2942637%
relative Frobenius error and 0.842930886 mean absolute error.

`ENGINES=1/2/4/8/16` all produce bit-exact scores for both protocols. The
`ENGINES=8` precision run matches the `ENGINES=1` result exactly on the pinned
T=512 capture. Measured T=512 cycles are 1,050,696 / 526,424 / 266,344 /
266,344 / 266,344 for version 5 and 1,052,728 / 528,448 / 266,320 / 135,280 /
135,280 for version 6. Version 5 becomes input-bound at four engines and
version 6 reaches the output floor at eight, as projected. `make lint` now
covers eleven parameter sets including `ENGINES=2/4/8`, and `make test` passes.

The cycle model reproduces all 32 measured configurations exactly, including
every replicated run, after adding a derived engine-saturation crossover and a
trailing-retirement term; see the [performance record](performance.md). There is no synthesis, area, or physical
result at any engine count, so nothing here is a frequency, latency, or energy
claim.

## September 28 16x16 synthesis diagnosis

The original 16x16 Bs=16 L4 attempt already used `T_MAX=16`. Its log identifies
`acc_bank` as the source of the `OPT_MEM_PRIORITY` expansion. A static-write
hierarchy reached 12.4 GB during technology mapping before the kernel killed it.
A custom flow that skipped `opt_mem_priority` reached `MEMORY_COLLECT` and
`MEMORY_MAP` within a ten-minute bound but produced no netlist. These are failed
EDA experiments, not physical results. The working tree was restored after each
attempt, and the verified score-producing RTL did not change.

## September 28 repository and documentation verification

The pre-cleanup tree is preserved by annotated tag
`pre-cleanup-2026-09-28`. The archive cleanup retains the M4 source/test baseline
and superseded LUT used by the model tests. `make baseline` still produces 16/16
correct scores with the known historical `DONE=NO` limitation, and all 29 model
tests pass.

The documentation reorganization moves all 16 small data artifacts under
`docs/results/data/`, and the precision provenance test regenerates the selected
records from their new paths. Active Markdown count falls from 34 to 32 while
adding a glossary and protocol history. `make check-docs` passes 33 checked files,
including two retained archive READMEs, with every active page at most two links
from the root README.

## September 27 Bs=16 default

The default stream contract is now version 5 with one FP32 scale per 16
reduction elements; `K_REUSE=1` selects version 6. Versions 3 and 4 remain
tested Bs=32 compatibility points. With Verilator 5.041, every default score
remains bit identical to the software model. The T=512 measurements are
1,050,696 cycles for 4x4 L1, 264,336 for 8x8 L2, and 133,392 for 16x16 L4.
Version 6 takes 1,052,728 cycles at 4x4. The cycle model reproduces all 24
recorded configurations exactly.

`make test`, every large 4x4/8x8/16x16 and K-reuse suite, the explicit Bs=32
compatibility suite, and `make test-precision-rtl` pass. The precision run
compares all 262,144 scores bit-for-bit and measures 13.2942637% relative
Frobenius error and 0.842930886 mean absolute error against the pinned FP32
reference. The reviewed rows are in
[`data/bs16-default-simulation.csv`](data/bs16-default-simulation.csv).

## September 27 optimized route

The 4x4, Bs=32, one-lane route containing RTL revision `e579ad7` completed on a
2200 um die with zero detailed-route, Magic DRC, KLayout DRC, or LVS errors.
The route has 69,400 synthesized cells, 860,627 um2 placed standard-cell area,
and 18.07% final utilization. A fixed-route maximum-RC sweep closes setup at
30.5 ns with +0.0703 ns slow-corner slack and misses at 30.4 ns by 0.0097 ns.
The worst setup path is now synchronous reset distribution.

This is still not timing closed. Maximum-RC hold slack is -1.2765 ns at the
slow corner and -0.0765 ns at the fast corner. The route also has 332 pin and
281 net antenna violations, up to 21,262 slew violations, and 533 fanout
violations. Dynamic power and energy per score remain rejected. Full tool,
constraint, timing, area, runtime, and signoff provenance is in the
[physical-design record](physical-design.md).

The recommended 16x16 four-lane second point was attempted at Bs=32 and 125 ns.
It did not produce a mapped netlist: Yosys remained in `OPT_MEM_PRIORITY` after
20 minutes 49 seconds while resident memory grew to 2.49 GB. The bounded run
was stopped and no 16x16 physical result is claimed.

## September 27 critical-path update

At revision `782619d`, `make test`, every large 4x4/8x8/16x16 and K-reuse
integration suite, the Bs=16 large suite, and `make test-precision-rtl` pass.
Every score remains bit identical to its reference. The updated cycle model
reproduces all 16 recorded configurations exactly. Current Bs=32 T=512 counts
are 1,049,666 cycles for 4x4 L1, 263,306 for 8x8 L2, and 132,362 for 16x16 L4.

Mapped, prelayout Sky130 timing at a common 225 ns constraint attributes the
path change as follows: 95.95 ns before the work, 58.58 ns after replacing
variable divide/modulo with coordinate counters, 58.49 ns after registering
scale reads, and 58.09 ns after replacing the linear leading-bit scan. The
worst mapped path is now synchronous reset logic. The optional accumulator-read
pipeline stage was not added because the first three steps crossed the 68 ns
mapped target. These values do not establish routed timing; full provenance is
in the [critical-path record](physical-design.md).

The local tools are Verilator 5.041 development revision
v5.040-196-g63f5f5c32, Python 3.12.3, pytest 7.4.4, OpenLane 1.1.1,
OpenROAD `b16bda7e82721d10566ff7e2b68f1ff0be9f9e38`, Yosys 0.38
`543faed9c8c`, and Sky130A
`bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`. Generated transcripts remain
under ignored `build/`.

The replication extension keeps every N=1 model row exact. At T=512 it projects
version 3 4x4 engines at 1,049,666, 525,378, 265,216, and 265,216 cycles for
N=1, 2, 4, and 8; the shared input port binds at N=4. Version 4 reaches 134,194
cycles at N=8. A same-revision hierarchical Yosys 0.44 mapping measures the
complete 4x4 L1 hierarchy at 565,736 um². The 16x16 L4 comparison did not finish
memory-priority lowering in 20 minutes and 2.3 GiB, so no area was claimed for
it. See the [replicated-engine study](performance.md).

## September 24 P0.4 and P0.6 record

I ran the complete P0.4 and P0.6 verification matrix on September 24, 2026, on
`master` at revision `1311eb0`. The target was the complete
`qkt_chiplet_top` with `D_HEAD=64`, FP32 scales, default
`SCALE_BLOCK_SIZE=32`, and protocol version 3 unless a row says otherwise.
These are RTL simulation results; no clock constraint or PDK applies.

## Commands and results

| Command | Result |
| --- | --- |
| `make test` | Documentation checks, eight lint configurations, 28 model tests, and the 4x4 small integration suite pass |
| `make test-integration-large` | Version 3 passes T=64/128/512; T=512 is 1,049,665 cycles |
| `make test-integration-reuse`, `make test-integration-reuse-large` | Version 4 passes D=4/64 and T through 512 |
| `make test-array8`, `make test-array16`, and both `-large` forms | Both arrays pass edge, stall, packet, and T=64/128/512 checks |
| `SCALE_BLOCK_SIZE=16 make test-integration` | The nondefault four-block configuration passes D=4/64 and all small cases |
| `make test-precision-rtl` | All 262,144 T=512 scores match the software 1x32 FP32 model bit-exactly |
| `SCORE_LANES=2/4 make test-array8-large` | T=512 takes 263,305/263,289 cycles |
| `SCORE_LANES=2/4 make test-array16-large` | T=512 takes 141,632/132,361 cycles |
| `python3 scripts/cycle_model.py` | All 16 measured cycle and input-beat configurations reproduce exactly |
| `make report-sim` | Regenerates `build/integration/summary.csv` from accepted-beat logs |
| Isolated `uv run` with NumPy 2.4.6 and pytest 8.4.2 | All 28 tests pass, including precision provenance at `rel=1e-6` |
| GitHub Actions at `f9ab75d` | Passes on Ubuntu 24.04 with its packaged Verilator 5.020 after reproducing and fixing the older lint limitation |

This historical run used an explicit regression ceiling of 1,049,665 core cycles.
The scale-prefetch stage raised the current ceiling to 1,049,666.
The machine-readable reviewed subset is
[`data/block-scale-lane-sweep.csv`](data/block-scale-lane-sweep.csv).

## Default block-scale measurements

Continuously ready streams at `D_HEAD=64`, Bs=32, and one score lane:

| Configuration | Core cycles | Input beats | Output beats | Array active | Binding stage |
| --- | ---: | ---: | ---: | ---: | --- |
| 4x4 v3, T=64 | 16,577 | 4,480 | 2,048 | 98.84% | CALC |
| 4x4 v3, T=128 | 65,857 | 17,152 | 8,192 | 99.51% | CALC |
| 4x4 v3, T=512 | 1,049,665 | 265,216 | 131,072 | 99.896% | CALC |
| 4x4 v4, T=512 | 1,051,697 | 5,120 | 131,072 | 99.70% | CALC |
| 8x8 v3, T=512 | 300,192 | 134,144 | 131,072 | 87.33% | SCALING |
| 16x16 v3, T=512 | 272,704 | 68,608 | 131,072 | 24.03% | SCALING |

The extra block scales add 512 input beats over P0.3 at T=512. Parallel block
scaling keeps 4x4 compute-bound; the three-cycle cross-block add appears only in
pipeline drain. Relative Frobenius error against the pinned FP32 QK^T reference
is **14.2346060%**, and mean absolute score error is **0.903700367**. These match
the software model's 1x32 FP32 path.

## P0.6 score-lane sweep

| Tile | Score lanes | Scaling cycles/tile | Binding stage | T=512 cycles | Array active |
| ---: | ---: | ---: | --- | ---: | ---: |
| 8x8 | 1 | 73 | SCALING, 73 | 300,192 | 87.33% |
| 8x8 | 2 | 41 | CALC, 64 | 263,305 | 99.56% |
| 8x8 | 4 | 25 | CALC, 64 | 263,289 | 99.57% |
| 16x16 | 1 | 265 | SCALING, 265 | 272,704 | 24.03% |
| 16x16 | 2 | 137 | SCALING, 137 | 141,632 | 46.27% |
| 16x16 | 4 | 73 | OUTPUT, 128 | 132,361 | 49.51% |

The 8x8 crossover is two lanes and moves to CALC, because its 32-cycle output
stage is always shorter than the 64-cycle dot product. The 16x16 crossover is
four lanes and moves to the 64-bit output. Its 132,361 measured cycles equal the
131,072-cycle two-score-per-cycle steady floor plus 1,289 fill and drain cycles.
Widening the output before scaling would buy no cycles, so P0.6 keeps 64 bits.

## Tools

| Tool | Version |
| --- | --- |
| Verilator | 5.041 development revision v5.040-196-g63f5f5c32 locally; 5.020 in passing GitHub CI |
| GCC/G++ | 13.3.0 |
| GNU Make | 4.3 |
| Python | 3.12.3 |
| pytest | 7.4.4 |
| NumPy | 1.26.4 generated the committed precision record; the extras accept 1.26.4 through 2.x |

Yosys was not available, so P0.4 and the lane variants have no synthesis or
physical evidence. The mapped Sky130 areas in the older result records belong
to their named revisions. This run proves functional correctness, protocol
behavior, the cycle model, and synthetic precision for finite normal scales. It
does not prove subnormal IEEE behavior, routed timing, power, frequency,
latency in seconds, or accuracy on real transformer activations.

Generated logs remain under ignored `build/`; the concise CSV above is the
committed result.

## P0.7 and P0.5 closeout gate

On September 25, 2026, `make test` passed at revision `ae707be`: documentation
checks, eight lint configurations, 29 model tests, and the D=4 and D=64 small
integration suites all passed. The physical-flow changes affect constraints and
orchestration only; no score-producing RTL changed in P0.7 or P0.5.

## P0.7 physical update

On September 25, 2026, revision `028401d` completed the 4x4,
`D_HEAD=64`, `T_MAX=16`, Bs=32, one-lane flow at 225 ns with the project SDC.
The 2200 um die has zero detailed-route, Magic DRC, KLayout DRC, and LVS errors.
Worst extracted setup slack is +28.7995 ns, while worst multi-corner hold slack
is -1.0069 ns. It has 256 pin and 224 net antenna violations, plus 476 typical
slew and 483 typical fanout violations. The dynamic-power report is physically
invalid and rejected. The run took 1 hour 36 minutes and peaked at 6,229 MB.
Full provenance and the constraint sweep are in
[the physical-design record](physical-design.md).

## P0.5 K-reuse update

[ADR 0005](../adr/0005-close-register-k-reuse.md) closes the register-based
experiment. Horowitz's 45 nm DRAM range projects 0.338 to 0.676 mJ saved per
T=512 command. Area-scaling the routed 0.495 mW slow-corner leakage over the
historical full-capacity register increment projects 0.686 mJ before dynamic
energy, while the added mapped area alone exceeds the routed die. Protocol
version 4 remains verified evidence; SRAM requires new routed power, a measured
higher-energy link, or a bandwidth-bound workload to reopen the decision.

## P0.8 real-activation update

The pinned BERT layer 0, head 0 capture has SHA-256
`bda32c19f874329b641947da8fc9e6ef2696bc1a6b657914a527b707d50caf22`.
Two capture runs produced identical bytes. NumPy 1.26.4 measured all 24 scale
combinations, and the 29-test model suite regenerates the six FP32 rows from the
committed capture and JSON. Bs=16 is the cheapest FP32 point that improves all
four softmax metrics over Bs=64 on this harness, so
[ADR 0004](../adr/0004-use-1x16-fp32-scales.md) supersedes ADR 0003. The RTL
default and stream protocol had not changed at that measurement revision; the
current version 5 implementation is recorded at the top of this page.

## Related

- [Results index](README.md)
- [Architecture and cycle model](../architecture.md)
- [Stream protocol](../stream-protocol.md)
- [Verification plan](../verification-plan.md)
