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
| E4M3 | 1,360 | 10,695 um² | 4.89x smaller in isolation |
| E8M0 | 367 | 3,780 um² | 13.83x smaller |

Scale storage falls by four times as well, from 4,096 to 1,024 bits at
`T_MAX=16`, and that gap grows with `T_MAX`.

**Exactness.** There is a third argument, found while planning the RTL. An
E4M3 significand is four bits, one implicit and three stored. A block
accumulator of `ACC_W` bits carries at most `ACC_W - 1` significant bits, 12 at
the Bs=16 width of 13. The product of the converted accumulator and the two
block scales therefore needs at most `(ACC_W - 1) + 4 + 4` significant bits, 20
here, which fits inside FP32's 24-bit significand. **Applying E4M3 block scales
is exact: it rounds nothing.** Over 60,000 random accumulator and scale triples,
0 needed rounding with E4M3 scales and 59,990 needed it with FP32 scales, which
the current design rounds twice, once per multiplier.

The condition is `ACC_W <= 17`, and it holds for every supported block size:
13 bits at Bs=16, 14 at Bs=32, 15 at Bs=64. It would not hold for the 43-bit
accumulator P1 needs for FP8, so that stage has to revisit it.

The consequence is that the whole score path becomes exact given the quantized
inputs and scales: exact integer block dot, exact conversion to FP32, exact
scale application. The only numerical error left is input quantization. It also
removes rounding logic from the scaler and makes the software reference a plain
double-precision product rounded once to FP32.

E4M3 is therefore better on accuracy, cheaper in area, and exact where FP32
rounds twice, all at once. That
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

Scores change. The new path is exact where the old one rounded twice, so the
protocol version bump is also a numerical-result bump, and the software model
and testbench must adopt the same exact reference.

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

## Integrated cost, measured after the decision

The decision above used a standalone probe. Integrating the format and
synthesizing the complete top in the same wire-free flow gives a much smaller
area result, and the record should say so plainly:

| Scale format | Cells | Mapped area | T=512 cycles |
| --- | ---: | ---: | ---: |
| FP32 | 53,005 | 257,495.71 um² | 1,050,690 |
| E4M3 | 47,251 | 257,186.66 um² | 1,050,687 |

That is **10.9% fewer cells but only 0.12% less area**, against the probe's
4.89x. The probe's number does not transfer, for the same reason
[ADR 0009](0009-use-e2m1-shift-add-products.md) already recorded for the
multiplier: the cells removed are small combinational ones, while mapped area
here is dominated by flip-flops.

The missing piece is storage. `sq` and `sk` are still 32-bit arrays, so the
four-times scale-storage saving this ADR claims is **not yet realized**: at
`T_MAX=16` that is 3,072 flip-flops still carrying bits the format no longer
uses, and the gap grows with `T_MAX`. Narrowing the arrays and the scale packet
to one byte is the remaining work, and it is where the area should come from.

**The decision stands, on different grounds than it was made.** Accuracy, the
exactness property, and three fewer cycles per command are all confirmed in the
integrated design. The area argument is reduced to 0.12% until storage narrows,
so it should not be quoted as 4.89x for the complete design. The rows are in
[`data/e4m3-integrated-cost.csv`](../results/data/e4m3-integrated-cost.csv).

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
