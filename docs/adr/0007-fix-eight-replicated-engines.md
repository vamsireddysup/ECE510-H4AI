# 0007: fix eight engines as the replication design point

Accepted, September 2026. This closes the engine-count question for the current
64-bit output contract so it is not re-explored.

## Decision

Build the replicated prototype with `ENGINES=8` and protocol version 6. Do not
evaluate 16, 32, 64, or 128 engines. Reopen only if the output contract changes,
which [problem statement P0](../problem-statements/p0-dense-fp4-matmul.md) does
not currently plan.

## The ceiling

The output port carries two FP32 scores per cycle. At T=512 the engine must
emit 262,144 scores, so no configuration can finish in fewer than
`262,144 / 2 = 131,072` cycles.

Per-engine CALC work at 4x4 and `D_HEAD=64` is `16,384 tiles * 64 / N`:

| Engines | CALC work | Output floor | Binding |
| ---: | ---: | ---: | --- |
| 4 | 262,144 | 131,072 | CALC |
| 8 | 131,072 | 131,072 | tie |
| 16 | 65,536 | 131,072 | output |
| 32 | 32,768 | 131,072 | output |
| 128 | 8,192 | 131,072 | output |

Eight engines is exactly where private arithmetic stops exceeding the shared
port. Every engine past the eighth adds arithmetic that idles waiting for the
port, plus its area and leakage, for zero cycles. That is zero return, not
diminishing return.

## Evidence

The measured `ENGINES=8` command is 135,280 cycles, which is 96.90% of the
131,072-cycle floor. The remaining 4,208 cycles are command startup, pipeline
fill, and the serialized retirement of the trailing tiles; they are latency, not
throughput.

`ENGINES=16` measures 135,280 cycles, identical to `ENGINES=8`. That is the
empirical confirmation, and no further sweep was run. The cycle model derives
the same crossover from first principles rather than assuming it, and now
reproduces both counts exactly.

## Version 5 cannot reach the floor

Version 5 reloads a K tile for every output tile, so a T=512 command accepts
266,240 input beats. That exceeds the 131,072-cycle output floor, so the shared
input port binds first at any engine count. Measured version 5 saturates at four
engines and 266,344 cycles, and 8 and 16 engines measure the same.

Command-level K reuse is therefore a prerequisite for useful replication, not an
optional variant. This is the throughput reopening condition that
[ADR 0005](0005-close-register-k-reuse.md) anticipated, and it is now measured
rather than projected. ADR 0005's energy conclusion against the register
scratchpad is unchanged; what changed is that replication gives K reuse a
latency case it did not have at one engine.

## Consequences

The replicated prototype is fixed at eight engines and version 6 for synthesis
and physical work. The 4,468,427 um² eight-engine area projection remains the
only area figure until checkpoint 2 measures the shared hierarchy.

Halving the output floor needs a wider port or a narrower score format, not more
engines. The [output-format measurement](../results/precision.md) records what a
16-bit score would cost in softmax agreement.

## Related

- [Decision records](README.md)
- [ADR 0006: replicated 4x4 engines](0006-use-replicated-4x4-engines.md)
- [ADR 0005: close register K reuse](0005-close-register-k-reuse.md)
- [Performance and replication results](../results/performance.md)
- [Project status](../project-status.md)
