# 0004: use FP32 scales with 16-element reduction blocks

Accepted, September 2026. Supersedes
[ADR 0003](0003-fp32-scales-with-32-element-blocks.md).

## Decision

Use one FP32 scale per 16 FP4 values along the reduction axis in the next stream
contract. For `D_HEAD=64`, every row carries four scales. Keep block size
parameterized and keep the current 1x32 protocol available for compatibility.

Do not change protocol version 3 in place. Versions 5 and 6 identify the 1x16
K-reload and K-reuse contracts; versions 3 and 4 retain 1x32 compatibility.

## Evidence

ADR 0003 selected the cheapest block size that improved mean KL, mean total
variation, top-1, and top-5 overlap over 1x64 on the same harness. On the pinned
BERT activation capture, 1x32 FP32 improves three metrics but reduces top-1 from
87.11% to 86.91%. The 1x16 point improves all four: KL 0.01055, TV 0.05721,
top-1 89.26%, and top-5 88.95%, compared with 0.01371, 0.06540, 87.11%, and
88.13% at 1x64.

The initial result covered one layer and head. Follow-up captures cover both
heads of the deeper layer and one last-layer head from a larger BERT. Bs=16
improves all four softmax metrics over Bs=64 in all four captures. Bs=32 fails
that rule in two captures. This is evidence for the engineering default rather
than a universal accuracy guarantee. Capture hashes, model revisions, tools,
complete sweeps, and raw-score metrics are in the
[real-activation result](../results/real-activation-precision.md).

## Cost

At `D_HEAD=64`, block count rises from two to four. The exact accumulator count
and parallel block scaler count double, and cross-block FP32 additions rise from
one to three per score. Scale storage doubles from 0.125 to 0.25 bytes per Q or K
element.

The existing cycle model projects:

| Build | Bs=32 T=512 | Bs=16 T=512 | Binding stage |
| --- | ---: | ---: | --- |
| 4x4, one score lane | 1,049,666 | 1,050,696 | CALC |
| 8x8, two score lanes | 263,306 | 264,336 | CALC |
| 16x16, four score lanes | 132,362 | 133,392 | OUTPUT |

The 1,030-cycle increase is 1,024 additional scale-input beats plus pipeline fill
and drain. Scaling service rises from 26 to 32 cycles at 4x4, 42 to 48 at 8x8,
and 74 to 80 at 16x16, so it does not change the binding stage in these builds.
These Bs=16 values now match the large RTL suites exactly. The physical routes
in the current P0.7 sweep retain Bs=32, so the default still needs its own routed
PPA result.

## Alternatives considered

**Retain 1x32.** It is cheaper and its top-1 loss is only one of 512 rows. It
nevertheless fails the comparative acceptance rule that selected it, while
1x16 passes the same rule and delivers a larger eleven-row top-1 gain over
1x64.

**Use 1x8.** It improves the four metrics further but needs seven FP32 adds per
score and doubles scale storage again. The added hardware is not justified by
one capture.

**Use E8M0.** All three E8M0 rules remain worse than FP32 on the real capture.
At Bs=16, ceiling is clipping safe but has KL 0.01671 and top-1 83.79%, both
worse than the 1x64 FP32 baseline.

The later optimized route also removes the timing argument for revisiting E8M0
in P0. Its worst setup path is synchronous reset distribution rather than an
FP32 scale multiplier. Replacing scale multiplication with exponent adjustment
would therefore sacrifice the measured accuracy without shortening the current
routed critical path. A future format-agile P1 datapath may still measure that
tradeoff as a separate mode.

## Consequences

Stream versions 5 and 6 carry four Q scales and four K scales per row at
`D_HEAD=64`. The parameterized accumulators, scaler, and reducer pass the small
and T=64/128/512 large integration suites at Bs=16. The cycle model reproduces
the new measurements exactly; routed PPA remains open.

This decision increases pressure on the scale path that P0.7 already identifies
as critical. P1 must first repair the integer-to-FP32 conversion's width
assumption and then measure the four-block scaler and reducer physically.

## Related

- [Decision records](README.md)
- [Real-activation precision](../results/real-activation-precision.md)
- [ADR 0003](0003-fp32-scales-with-32-element-blocks.md)
- [Development plan](../roadmap.md)
