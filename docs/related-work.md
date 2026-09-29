# Related work and positioning

This records the prior work closest to each research track and what, if
anything, this project could add. Read it before describing any result as new.

**Status: full-text review done for the two nearest papers, 2026-09-29.** The
first version of this page was written from abstracts and summaries, and three
of its claims were wrong. Those corrections are recorded below rather than
quietly edited away, because they changed what this project can claim. The
remaining rows are still abstract-level and are marked as such.

Comparisons in this project are A/B inside one flow and one PDK. Any
cross-node comparison states its scaling assumptions.

## What is not new

**The block-scale structure.** My 1x16 FP4 block with a finer-than-power-of-two
scale, selected in [ADR 0004](adr/0004-use-1x16-fp32-scales.md) and refined to
E4M3 in [ADR 0008](adr/0008-e4m3-block-scales.md), arrives at the structure of
[NVFP4](https://developer.nvidia.com/blog/introducing-nvfp4-for-efficient-and-accurate-low-precision-inference/):
16-element E2M1 blocks, an E4M3 block scale, and a per-tensor FP32 scale. The
P0.2 and P0.8 conclusion that smaller blocks and finer scales win is a
confirmation, not a contribution.

**FP4 attention itself.** [SageAttention3](https://www.alphaxiv.org/overview/2505.11594v2)
runs NVFP4 `QK^T` and `PV` on GPUs with K mean-subtraction smoothing.

**Softmax-level evaluation of a quantized score path.** I had treated judging
FP4 by KL divergence and top-k agreement rather than raw error as part of what
distinguishes this work. It is not.
[Shift-Accumulate Attention](https://arxiv.org/pdf/2609.09208) reports relative
score error, mean attention-distribution KL divergence, and top-8 ranking
overlap per layer. Softmax-fidelity metrics are the established way to evaluate
this, and using them is table stakes.

**A per-block format flag carried in spare scale bits.** I had recorded this as
an opening for novelty track 2. [MixFP4](https://arxiv.org/pdf/2605.31035) does
exactly it: it selects per 16-value block between FP4 E2M1 and INT4, encodes the
choice with **zero extra metadata by repurposing the sign bit of the E4M3 block
scale**, and decodes both into one internal E2M2 representation so the datapath
is not duplicated. It also reports the hardware cost, 3.1% tensor-core area and
1.5% power, and it analyzes activation tensors specifically, noting their
crest factor varies far more than weights'. Track 2's mechanism, encoding, and
hardware accounting are therefore published.

## Corrections to the first version of this page

| Claim I made from abstracts | What the full text says |
| --- | --- |
| Shift-Accumulate is "integer and approximate" | Its product is **exact with respect to its quantized operands**: because keys are normalized before log2 quantization every shift is a non-negative left shift, so "no truncation is introduced, and the only error is the operand quantisation error". |
| Shift-Accumulate evaluates "perplexity, not softmax metrics" | It reports score error, attention-distribution KL, and top-8 overlap, as well as WikiText-103 perplexity. |
| MixFP4 is "weights only, no hardware" | It covers activation tensors and reports 3.1% tensor-core area and 1.5% power. Its selection criterion is a per-block crest factor with a 2.224 threshold. |

## Nearest work by track

Rows marked *abstract* have not had a full-text review yet.

| Track | Nearest work | What it covers | What is left |
| --- | --- | --- | --- |
| Multiplier-free MAC | [Shift-Accumulate Attention](https://arxiv.org/pdf/2609.09208) | Multiplier-free exact `QK^T`; INT8 queries and **signed power-of-two keys**; CUDA kernels plus a cost model for a hypothetical `DS4A` instruction | It **changes the key format** to power-of-two to enable shifts, and pays for it: PoT-M4 costs +0.15 perplexity against an INT8 key cache. There is **no ASIC**: no synthesis, no process node, no measured area or power. Our E2M1 products are shift-add *without changing the format*, because E2M1's mantissa set is already `{1, 1.5}`, and [ADR 0009](adr/0009-use-e2m1-shift-add-products.md) measures the result in Sky130. |
| Per-block FP4/INT4 | [MixFP4](https://arxiv.org/pdf/2605.31035) | Per-block FP4-or-INT4 by crest factor, flag in the E4M3 scale sign bit, unified E2M2 datapath, 3.1% tensor-core area | Little. Ours differs only in selection criterion (reconstruction error), in targeting an exact-integer-accumulator ASIC rather than a tensor core, and in being measured on attention Q and K in an open PDK. **This is no longer a strong novelty track**, which matches the M1 measurement: reconstruction-selected blocks lose 0.34 top-1 points and regress on the larger capture. |
| Scale-format co-design | [MXAttention](https://arxiv.org/html/2607.24377v1) *(abstract)* | Data-free E8M0 clipping boundary of 7.25 for attention | GPU kernels; no hardware cost for the scale format. Our ADR 0008 prices FP32, E4M3, and E8M0 scalers in Sky130 alongside their softmax fidelity. |
| | [Four Over Six](https://arxiv.org/html/2512.02010v4), [ScaleSearch](https://arxiv.org/html/2605.12464v1) *(abstract)* | Per-block scale-to-4-or-6; MSE search over scale offsets, applied to Q and K | Accuracy only, no hardware cost. |
| Softmax-invariant preprocessing | [SageAttention3](https://www.alphaxiv.org/overview/2505.11594v2), [QuaRot](https://arxiv.org/pdf/2404.00456) *(abstract)* | K mean-subtraction; Hadamard rotation leaves `QK^T` exact | Measured here and **not adopted**: neither improves all four softmax metrics across all four captures. |
| Exponent-first sparsity | [BitStopper](https://arxiv.org/html/2512.06457), [LAPA](https://arxiv.org/html/2512.07855) *(abstract)* | MSB-first and log-domain score prediction to skip weak scores, both 28 nm | Integer operands and a separate prediction stage. Our M1 study found a safe sign-and-exponent bound covers 28.83% of scores but **no whole 4x4 tile in either decoder head**, so it is not a general feature. |
| MX hardware generally | [Jack Unit](https://arxiv.org/pdf/2507.04772), [MX-SAFE](https://arxiv.org/html/2605.24391v2) *(abstract)* | Precision-scalable MX MAC at 16 nm; MX core at 65 nm | Proprietary nodes, not attention-specific. |

## What this project can honestly claim

Narrower than the first version of this page assumed, and worth stating
precisely.

1. **A fully open, reproducible Sky130 measurement of an attention-score
   engine, where each arithmetic choice is priced.** Every nearest work above
   either runs on GPUs and reports no silicon cost, or reports silicon in a
   proprietary node. ADR 0008 and ADR 0009 each pair a softmax-fidelity result
   with a mapped Sky130 area from the same flow. The artifacts, PDK, and tools
   are open, and the numbers regenerate from committed scripts.
2. **Bit-exactness as a maintained contract.** The RTL matches the software
   model bit-for-bit on the full pinned T=512 workload across every structural
   change, checked in CI, and the cycle model reproduces all 32 recorded
   configurations. That is a verification property, not a novel mechanism, but
   it is what makes the cost comparisons trustworthy.
3. **One concrete, previously unreported co-design finding.** At 32-bit block
   scales, finer scale resolution costs area; at 8-bit E4M3 scales it does not.
   Searched E4M3 is simultaneously more accurate on every softmax metric across
   six pinned heads and 4.89x smaller in the mapped scaling path than the FP32
   default. Published work chooses E4M3 for accuracy, or prices MX hardware
   generally; the measured statement that the accuracy-optimal scale format is
   also the cheaper one for this operator is ours.

**What it should not claim.** Not the block structure, not FP4 attention, not
softmax-metric evaluation, not per-block FP4/INT4 with a flag in the scale, and
not multiplier-free `QK^T`. A power or energy-per-score claim needs the
milestone M2 measurement, which does not exist yet.

## Before publishing anything

The rows marked *abstract* still need full texts read, in the order they matter:
MXAttention, then BitStopper and LAPA, then Jack Unit and MX-SAFE. Record each
correction in the table above rather than editing this page silently.

## Related

- [Project status and roadmap](project-status.md)
- [P1 problem statement](problem-statements/p1-format-agile-sparsity.md)
- [Attention precision results](results/precision.md)
- [ADR 0008: E4M3 block scales](adr/0008-e4m3-block-scales.md)
- [ADR 0009: E2M1 shift-add products](adr/0009-use-e2m1-shift-add-products.md)
- [Documentation index](README.md)
