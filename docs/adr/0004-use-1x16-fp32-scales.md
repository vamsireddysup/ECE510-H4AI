# 0004: use FP32 scales with 16-element reduction blocks

Accepted, September 2026. Supersedes
[ADR 0003](0003-fp32-scales-with-32-element-blocks.md). Implementation as the
default stream contract is pending; protocol version 3 remains 1x32.

## Decision

Use one FP32 scale per 16 FP4 values along the reduction axis in the next stream
contract. For `D_HEAD=64`, every row carries four scales. Keep block size
parameterized and keep the current 1x32 protocol available for compatibility.

Do not change protocol version 3 in place. The additional scale words require a
new version before 1x16 becomes the RTL default.

## Evidence

ADR 0003 selected the cheapest block size that improved mean KL, mean total
variation, top-1, and top-5 overlap over 1x64 on the same harness. On the pinned
BERT activation capture, 1x32 FP32 improves three metrics but reduces top-1 from
87.11% to 86.91%. The 1x16 point improves all four: KL 0.01055, TV 0.05721,
top-1 89.26%, and top-5 88.95%, compared with 0.01371, 0.06540, 87.11%, and
88.13% at 1x64.

This is one layer and head, so it is evidence for the engineering default rather
than a universal accuracy guarantee. The capture, model revision, input hash,
tool versions, complete format sweep, and raw-score metrics are in the
[real-activation result](../results/real-activation-precision.md).

## Cost

At `D_HEAD=64`, block count rises from two to four. The exact accumulator count
and parallel block scaler count double, and cross-block FP32 additions rise from
one to three per score. Scale storage doubles from 0.125 to 0.25 bytes per Q or K
element.

The existing cycle model projects:

| Build | Bs=32 T=512 | Bs=16 T=512 | Binding stage |
| --- | ---: | ---: | --- |
| 4x4, one score lane | 1,049,665 | 1,050,695 | CALC |
| 8x8, two score lanes | 263,305 | 264,335 | CALC |
| 16x16, four score lanes | 132,361 | 133,391 | OUTPUT |

The 1,030-cycle increase is 1,024 additional scale-input beats plus pipeline fill
and drain. Scaling service rises from 25 to 31 cycles at 4x4, 41 to 47 at 8x8,
and 73 to 79 at 16x16, so it does not change the binding stage in these builds.
These are projections from the exact cycle model; the 1x16 default has not run
the large RTL suite or physical flow.

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

## Consequences

A new stream protocol must carry four Q scales and four K scales per row at
`D_HEAD=64`. The current parameterized accumulators, scaler, and reducer already
elaborate at Bs=16 and pass the small integration suite, but the default change
needs the full large regression, cycle provenance, synthesis, and physical
measurement.

This decision increases pressure on the scale path that P0.7 already identifies
as critical. P1 must first repair the integer-to-FP32 conversion's width
assumption and then measure the four-block scaler and reducer physically.

## Related

- [Decision records](README.md)
- [Real-activation precision](../results/real-activation-precision.md)
- [ADR 0003](0003-fp32-scales-with-32-element-blocks.md)
- [Development plan](../roadmap.md)
