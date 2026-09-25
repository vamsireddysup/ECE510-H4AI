# Verification plan

This says what each check proves, what it does not prove, and which command runs
it. Read it to find out whether a claim you want to make is actually covered.

Every command runs from the repository root. `make test` is the required
pre-commit set: `check-docs`, `lint`, `test-model`, `test-integration`.

## The checks

| Check | Command | Proves | Does not prove |
| --- | --- | --- | --- |
| Documentation structure | `make check-docs` | One H1 per active document, every relative link resolves, every document has a `## Related` block and is reachable from `README.md` | That the prose is accurate |
| RTL lint | `make lint` | Eight parameter sets elaborate clean under `-Wall`, including both protocols, Bs=16, and widened 8x8/16x16 scalers | Functional correctness |
| Reference model | `make test-model` | The Python FP4 decode, encode, and `QK^T` model agrees with the 256-entry RTL product ROM on all 256 input pairs, and rejects malformed shapes | That the RTL matches the model; the integration test does that |
| Cycle model | `python3 scripts/cycle_model.py` | The closed-form model in [architecture](architecture.md) reproduces all 16 measured configurations | Anything about a configuration not in its table |
| Small integration | `make test-integration` | Everything in the table below, at `D_HEAD=4` and `64`, with host stalls injected on both streams | Large-`T` behavior; sustained throughput |
| Large integration | `make test-integration-large` | Scores and counters at T=64/128/512, `D_HEAD=64`, continuously ready host | Behavior under stalls |
| K reuse | `make test-integration-reuse`, `make test-integration-reuse-large` | Protocol version 4 at the same sequence lengths | That its register scratchpad is affordable; see [ADR 0002](adr/0002-k-reload-is-the-default.md) |
| Larger arrays | `make test-array8`, `make test-array16`, and their `-large` forms | 8x8 and 16x16 produce correct scores and counters | Routed timing or power at those sizes |
| Simulation summary | `make report-sim` | Cycles, array utilization, useful and wire bytes, and arithmetic intensity, derived from accepted-beat logs | Anything not in a `build/integration/*/run.log` |
| Archived baseline | `make baseline`, `make baseline-strict` | The untouched M4 sources still reproduce their recorded numeric result | Anything about the active top |
| Synthetic precision | `python3 scripts/eval_precision.py` and `make test-model` | The 120-point block-scale sweep, committed JSON, and rendered T=512 table reproduce at the pinned NumPy version | Error on real transformer activations; see [precision](results/precision.md) |
| Real-activation precision | `python3 scripts/eval_precision.py --npz docs/results/p0-8-bert-tiny-layer0-head0.npz` and `make test-model` | The pinned BERT capture and six FP32 block-size rows reproduce from committed inputs | Accuracy across other layers, heads, models, and tasks |
| RTL precision | `make test-precision-rtl` | Every score at pinned seed-510 T=512 is bit-exact with the software 1x32 FP32 path, and its raw-score error matches | IEEE behavior outside the finite-normal values in that capture |
| CPU baseline | `python3 scripts/bench_cpu.py` | Observed one-thread NumPy throughput on fixed inputs | A CPU peak, and therefore not a Roofline ceiling |
| Mapped area | `./scripts/run_synthesis.sh TILE DEPTH TMAX [REUSE]` | Sky130 HD standard-cell area for the complete top at the typical corner | Timing, routing, congestion, or power |
| Physical run | `./scripts/run_physical.sh` | Complete-top route, extracted timing, DRC, LVS, antenna, and qualified power status | Timing closure until every setup, hold, slew, and fanout gate passes |

## What the integration test covers

One testbench, `tb/integration/tb_qkt_chiplet.cpp`, drives the complete top
through both interfaces and checks each score against an exact integer-dot
reference it computes itself.

Numerical: every score at `D_HEAD=4` and `64`; sequence lengths 1, 4, 7, 8, 16 in
the small suite and 64, 128, 512 in the large suite; partial edge tiles at T=7;
random FP4 code patterns across three seeds; worst-case integer sums; varied
block scales; Bs=16 as a nondefault parameter; and the original M4 numerical
pattern, so the historical 16/16 case stays
covered.

Protocol: concurrent input and output traffic, per-packet `TLAST` position,
output payload and `TLAST` stability while `TREADY` is low, zero padding in the upper half of an odd final beat, accepted
input and output beat counts against a closed-form expression, completed tile
counts, and dot-product and scale cycle counts.

Error and control: the three error codes for invalid `T`, early `TLAST`, and
missing `TLAST`; reset part-way through a command; a second command without an
intervening reset; AXI4-Lite write-data-before-address and same-cycle writes; byte
strobes; and stable read data held under backpressure.

## Gaps, stated plainly

There are no unit tests. `tb/unit/` does not exist, so arithmetic blocks are only
covered through the full top.

There are no SystemVerilog assertions. Protocol invariants are checked from the
testbench side, not inside the design.

There is no formal verification. `sby` is listed as optional in `make doctor` and
has not been used.

One pinned BERT layer and head now has real-activation precision evidence. It is
enough to select 1x16 for the next contract, but it does not establish accuracy
across layers, heads, models, or tasks.

Nothing is routed. No check in this plan produces a frequency, a latency in
seconds, or an energy number.

## Recording a result

Per [`CODEX.md`](../CODEX.md), every published number records the commit, the RTL
target and included modules, the parameter values, the tool and PDK versions, the
clock constraint, and whether it is measured or projected. Reviewed results go in
[`docs/results/`](results/README.md).

## Related

- [Architecture and the cycle model](architecture.md)
- [Latest verification run](results/latest-verification.md)
- [Testbench notes](../tb/README.md)
- [Documentation index](README.md)
