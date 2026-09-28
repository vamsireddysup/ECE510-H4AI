# Verification plan

This says what each check proves, what it does not prove, and which command runs
it. Read it to find out whether a claim you want to make is actually covered.

Every command runs from the repository root. `make test` is the required
pre-commit set: `check-docs`, `lint`, `test-model`, `test-integration`.

## The checks

| Check | Command | Proves | Does not prove |
| --- | --- | --- | --- |
| Documentation structure | `make check-docs` | One H1 per active document, every relative link resolves, every document has a `## Related` block and is reachable from `README.md` | That the prose is accurate |
| RTL lint | `make lint` | Eleven parameter sets elaborate clean under `-Wall`, including both protocols, Bs=16, widened 8x8/16x16 scalers, and `ENGINES=2/4/8` | Functional correctness |
| Reference model | `make test-model` | The Python FP4 decode, encode, and `QK^T` model agrees with the 256-entry RTL product ROM on all 256 input pairs, and rejects malformed shapes | That the RTL matches the model; the integration test does that |
| Cycle model | `python3 scripts/cycle_model.py` | The closed-form model reproduces all 32 measured configurations exactly, single-engine and replicated, and every input-beat count | Anything about a configuration not in its table |
| Recorded cycle counts | `python3 scripts/check_cycle_model.py` | Every configuration in the cycle model's measured table still simulates to its recorded cycle and input-beat count on the current RTL | Configurations not in that table |
| Replicated engines | `ENGINES=N make test-integration ...` | Bit-exact scores and counters at `ENGINES=1/2/4/8/16` for both protocols, including partial engine groups at T=1 and T=7 | Mapped area or routed timing at any engine count |
| Small integration | `make test-integration` | Everything in the table below, at `D_HEAD=4` and `64`, with host stalls injected on both streams | Large-`T` behavior; sustained throughput |
| Large integration | `make test-integration-large` | Scores and counters at T=64/128/512, `D_HEAD=64`, continuously ready host | Behavior under stalls |
| K reuse | `make test-integration-reuse`, `make test-integration-reuse-large` | Protocol version 6 at the same sequence lengths | That its register scratchpad is affordable; see [ADR 0002](adr/0002-k-reload-is-the-default.md) |
| Larger arrays | `make test-array8`, `make test-array16`, and their `-large` forms | 8x8 and 16x16 produce correct scores and counters | Routed timing or power at those sizes |
| Simulation summary | `make report-sim` | Cycles, array utilization, useful and wire bytes, and arithmetic intensity, derived from accepted-beat logs | Anything not in a `build/integration/*/run.log` |
| Archived baseline | `make baseline`, `make baseline-strict` | The untouched M4 sources still reproduce their recorded numeric result | Anything about the active top |
| Synthetic precision | `python3 scripts/eval_precision.py` and `make test-model` | The 120-point block-scale sweep, committed JSON, and rendered T=512 table reproduce at the pinned NumPy version | Error on real transformer activations; see [precision](results/precision.md) |
| Real-activation precision | `python3 scripts/eval_precision.py --npz CAPTURE` and `make test-model` | Four pinned BERT heads across two models and every recorded scale row reproduce from committed inputs | Accuracy across architectures and downstream tasks |
| RTL precision | `make test-precision-rtl` | Every score at pinned seed-510 T=512 is bit-exact with the software 1x16 FP32 path, and its raw-score error matches | IEEE behavior outside the finite-normal values in that capture |
| CPU baseline | `python3 scripts/bench_cpu.py [--all-cores]` | Observed NumPy throughput on fixed inputs, with host, BLAS, thread-pool, and warm-cache provenance, and the measured fraction of a stated theoretical peak | A CPU peak, and therefore not a Roofline ceiling; the peak it prints is a ceiling, never the baseline |
| Output score format | `python3 scripts/eval_precision.py --npz CAPTURE --output-formats` | FP32, FP16, and BF16 softmax agreement on the pinned captures | Anything about FP16 range outside these four captures; no RTL implements a 16-bit score |
| Mapped area | `./scripts/run_synthesis.sh TILE DEPTH TMAX [REUSE]` | Sky130 HD standard-cell area for the complete top at the typical corner | Timing, routing, congestion, or power |
| Physical run | `./scripts/run_physical.sh` | Complete-top route, extracted timing, DRC, LVS, antenna, and qualified power status | Timing closure until every setup, hold, slew, and fanout gate passes |

## What the integration test covers

One testbench, `tb/integration/tb_qkt_chiplet.cpp`, drives the complete top
through both interfaces and checks each score against an exact integer-dot
reference it computes itself.

Numerical: every score at `D_HEAD=4` and `64`; sequence lengths 1, 4, 7, 8, 16 in
the small suite and 64, 128, 512 in the large suite; partial edge tiles at T=7;
random FP4 code patterns across three seeds; worst-case integer sums; varied
block scales; Bs=16 as the default and Bs=32 compatibility; and the original M4 numerical
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

Simulation assertions cover stalled-output stability, ping-pong bank ownership,
output-bank ordering, legal output indices, and frontend transitions. They are
simulation checks rather than a formal proof.

There is no formal verification. `sby` is listed as optional in `make doctor` and
has not been used.

Four pinned BERT heads across two model sizes have real-activation precision
evidence. They support the 1x16 engineering default but do not establish
accuracy across model architectures or downstream tasks.

The physical check has routed named configurations, but frequency and power are
claimable only when its setup, hold, slew, fanout, antenna, DRC, and LVS gates
all pass.

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
