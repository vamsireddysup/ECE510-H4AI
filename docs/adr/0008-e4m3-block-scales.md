# 0008: use E4M3 block scales chosen by an offline scale search

Accepted, September 2026. Supersedes the scale-format half of
[ADR 0004](0004-use-1x16-fp32-scales.md); the 16-element block size it selected
is unchanged.

## Decision

Represent each block scale as one E4M3 byte relative to a per-tensor FP32
scale, and choose each block's scale by an offline search over E4M3 codes
rather than by `max(abs(block))/6`. Keep 1x16 blocks, FP4 E2M1 elements, exact
integer block accumulation, and FP32 output scores.

Do not adopt E8M0, and do not keep FP32 scales as the default.

## Evidence

Two measurements, both across all four pinned BERT captures at Bs=16, in
[attention precision results](../results/precision.md).

**Accuracy.** Mean over the captures, against the FP32 default:

| Scale rule | Mean KL | Top-1 | Rel. Frobenius |
| --- | ---: | ---: | ---: |
| FP32 | 0.02738 | 89.65% | 8.46% |
| E4M3, max-based | 0.02779, +1.5% | 90.38%, +0.73 pt | 8.50%, +0.6% |
| **E4M3, searched** | **0.02114, -22.8%** | **90.82%, +1.17 pt** | **7.27%, -14.0%** |
| E8M0, best rule | 0.04825, +76.2% | 87.30%, -2.34 pt | 10.17%, +20.3% |

The searched E4M3 rule improves mean KL on each of the four captures
individually, not only on the mean.

Two later out-of-sample SmolLM2 decoder captures retain the decision. Against
FP32, searched E4M3 lowers mean KL from 0.05416 to 0.04668, mean TV from 0.10688
to 0.10027, relative Frobenius error from 10.75% to 9.70%, and raises mean
top-1 from 79.30% to 82.32% and top-5 from 73.83% to 79.10%. The deeper head's
top-1 alone falls by 1.36 points, so the evidence does not support a universal
per-head improvement claim. E8M0-UOS remains worse on every decoder aggregate.

**Cost.** One score lane's scaling path, mapped to Sky130 HD with Yosys 0.44 at
`ACC_W=13` and flattened:

| Scale format | Cells | Mapped area | Against FP32 |
| --- | ---: | ---: | ---: |
| FP32 | 6,761 | 52,280 um² | |
| E4M3 | 1,360 | 10,695 um² | 4.89x smaller |
| E8M0 | 367 | 3,780 um² | 13.83x smaller |

Scale storage falls by four times as well, from 4,096 to 1,024 bits at
`T_MAX=16`, and that gap grows with `T_MAX`.

E4M3 is therefore better on accuracy and cheaper in area at the same time. That
is the whole reason to act: there is no trade to weigh. ADR 0003 assumed a
finer scale must cost more hardware, which was true when the alternative to
FP32 was a coarser format, and is false when the alternative is a narrower
floating-point scale.

## Why not E8M0

It is 13.83 times smaller than FP32 and turns the scale multiply into an
exponent add, which is the cheapest scaler this design could have. It costs
2.34 points of top-1 agreement and 76% more KL divergence, and the
[MXAttention](https://arxiv.org/html/2607.24377v1) clipping boundary of 7.25
narrows that gap without closing it: it improves on the OCP rule by cutting the
KL penalty from 102.2% to 76.2%. An attention-score engine whose stated purpose
is preserving softmax behavior should not give up that much to save area it has
not yet shown it needs. Reopen this if a routed result shows the scaling path
dominating area or energy.

## Consequences

The stream contract changes: block scales become one byte plus two per-tensor
FP32 scales per command, so this is protocol version 7, the next unused
identifier. Host traffic for scales falls by four times. The per-tensor scales
multiply into one constant per command, which the host can fold into its
softmax temperature, so the engine does not apply them.

The scale search is entirely offline, in the host's quantizer. The hardware
consumes a byte and does not know how it was chosen, so the search can improve
later without touching silicon.

`score_scaler` replaces two `fp32_mul` instances per lane with a single narrow
significand multiply and an exponent add. This lands with the milestone M2
accumulator rework, since both touch the same datapath, and it has to hold the
existing bit-exactness property against the updated software model.

The E4M3 probe flushes subnormal and overflowed results to zero, matching the
existing FP32 units. The quantizer never emits a zero or subnormal block scale.

## Alternatives considered

**Keep FP32 and take the accuracy from `4over6` alone.** It improves mean KL by
9.8% but lowers top-1 by 0.59 points and keeps the 24x24 multipliers. The
searched E4M3 rule beats it on every metric and is 4.89 times smaller.

**Adopt E8M0 for the area.** Covered above.

**Change nothing until a routed result exists.** The scaling path is already
implicated in the congestion that blocks routing, so carrying a 4.89 times
larger scaler into milestone M2 would make that harder, not easier.

## Related

- [Decision records](README.md)
- [Attention precision results](../results/precision.md)
- [Related work](../related-work.md)
- [ADR 0004: 1x16 blocks](0004-use-1x16-fp32-scales.md)
- [Project status and roadmap](../project-status.md)
