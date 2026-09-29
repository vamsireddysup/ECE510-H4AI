# Related work and positioning

This records the prior work closest to each research track and what, if
anything, this project could add. Read it before describing any result as new.

**Status: initial survey.** The entries below come from abstracts and summaries
gathered on 2026-09-29. Before any document calls a result novel, the full text
of the nearest papers must be read and this page updated with what each one
actually does and does not cover. Comparisons in this project are A/B inside one
flow and one PDK; any cross-node comparison states its scaling assumptions.

## What is not new

My 1x16 FP4 block with a finer-than-power-of-two scale, selected in
[ADR 0004](adr/0004-use-1x16-fp32-scales.md), independently arrives at the
structure of [NVFP4](https://developer.nvidia.com/blog/introducing-nvfp4-for-efficient-and-accurate-low-precision-inference/):
16-element E2M1 blocks with an E4M3 scale and a per-tensor FP32 scale, which
NVIDIA reports beats MXFP4's 32-element E8M0 blocks. The P0.2 and P0.8 finding
that smaller blocks and finer scales win is therefore a confirmation, not a
contribution. FP4 attention on GPUs is also established:
[SageAttention3](https://www.alphaxiv.org/overview/2505.11594v2) runs NVFP4
`QK^T` and `PV` with K mean-subtraction smoothing.

## Nearest work by track

| Track | Nearest work | What it covers | Apparent gap |
| --- | --- | --- | --- |
| Scale-format co-design | [MXAttention](https://arxiv.org/html/2607.24377v1) | Data-free E8M0 clipping boundary of 7.25 for attention | GPU kernels; no hardware cost of the scale format |
| | [Four Over Six](https://arxiv.org/html/2512.02010v4) | Per-block choice of scaling to 4 or 6 in NVFP4 | Accuracy only |
| | [ScaleSearch](https://arxiv.org/html/2605.12464v1) | MSE search over scale offsets, applied to Q and K | Accuracy only |
| Softmax-invariant preprocessing | [SageAttention3](https://www.alphaxiv.org/overview/2505.11594v2), [QuaRot](https://arxiv.org/pdf/2404.00456) | K mean-subtraction; Hadamard rotation keeps `QK^T` exact | Software; no hardware stage cost |
| Per-block FP4/INT4 | [MixFP4](https://arxiv.org/pdf/2605.31035) | Per-block FP4 or INT4 flagged in a spare scale bit | Weights only; no MAC hardware reported |
| Multiplier-free MAC | [Shift-Accumulate Attention](https://arxiv.org/pdf/2609.09208) | Multiplier-free query-key products | Integer and approximate; E2M1 products are exact as {1,3} x 2^e |
| | [Jack Unit](https://arxiv.org/pdf/2507.04772) | Precision-scalable MX MAC, 1.2x to 2.0x area and power reduction | 16 nm; general MX MAC |
| Exponent-first sparsity | [BitStopper](https://arxiv.org/html/2512.06457), [LAPA](https://arxiv.org/html/2512.07855) | MSB-first and log-domain score prediction to skip weak scores, 28 nm | Integer operands; FP4's two exponent bits are an untested first pass |
| MX hardware generally | [MX-SAFE](https://arxiv.org/html/2605.24391v2) | MX core at 65 nm and 500 MHz | Proprietary node; not attention-specific |

## Candidate contribution

To be confirmed by the full-text review above, not yet claimed: an open-PDK,
bit-exact FP4 attention-score engine whose element format, block-scale format,
and multiplier structure are chosen jointly by softmax fidelity on real
attention activations and by measured Sky130 signoff area, energy, and timing,
with exponent-first skipping of softmax-negligible scores. Each piece has close
neighbors; the claim would rest on the joint co-design and on a reproducible,
fully open measurement.

## Related

- [Project status and roadmap](project-status.md)
- [P1 problem statement](problem-statements/p1-format-agile-sparsity.md)
- [Attention precision results](results/precision.md)
- [Documentation index](README.md)
