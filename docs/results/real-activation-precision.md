# Real transformer activation precision

This record evaluates the P0 scale formats on Q and K from a pretrained
transformer. These are **measured software-model results**, not RTL or silicon
measurements.

## Capture

The committed [capture](p0-8-bert-tiny-layer0-head0.npz) contains 512 by 64 Q
and K arrays from layer 0, head 0 of Google's
[`bert_uncased_L-2_H-128_A-2`](https://huggingface.co/google/bert_uncased_L-2_H-128_A-2/tree/30b0a37ccaaa32f332884b96992754e246e48c5f),
revision `30b0a37ccaaa32f332884b96992754e246e48c5f`. That model has two attention
heads across a 128-element hidden state, so each head has the accelerator's
`D_HEAD=64`. The input is the first 512 WordPiece tokens, including special
tokens, from the committed Chapter I excerpt of the public-domain
[Project Gutenberg Alice's Adventures in Wonderland](https://www.gutenberg.org/ebooks/11).

The capture SHA-256 is
`bda32c19f874329b641947da8fc9e6ef2696bc1a6b657914a527b707d50caf22`.
The text fixture SHA-256 is
`2895f266c42239d3efa61e71dee55313b0c79d03f6e82812bda706b87620b431`.
`scripts/capture_transformer_qk.py` writes deterministic NPZ bytes; two clean
runs produced the same hash.

Capture tools were Python 3.12.3, PyTorch 2.8.0+cpu, and Transformers 4.56.2.
The sweep used NumPy 1.26.4 and the same quantizer and metrics as the synthetic
P0.2 record. The complete [machine-readable sweep](p0-8-real-activation-precision.json)
contains every Bs 64/32/16/8/4/2 and scale-type combination.

## T=512 sweep

| Bs | Scale | Mean KL | Mean TV | Top-1 | Top-5 overlap | Rel. Frobenius | Mean abs. error | Clipped inputs | Scale B/element | FP32 adds/score |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 64 | FP32 | 0.01371 | 0.06540 | 87.11% | 88.13% | 10.98% | 1.108 | 0.00% | 0.0625 | 0 |
| 64 | E8M0-floor | 0.09729 | 0.16692 | 72.85% | 77.19% | 24.76% | 2.421 | 11.33% | 0.015625 | 0 |
| 64 | E8M0-nearest | 0.01747 | 0.07363 | 83.79% | 86.99% | 12.00% | 1.213 | 1.17% | 0.015625 | 0 |
| 64 | E8M0-ceil | 0.01898 | 0.07702 | 83.98% | 85.62% | 12.67% | 1.274 | 0.00% | 0.015625 | 0 |
| 32 | FP32 | 0.01259 | 0.06253 | 86.91% | 88.48% | 10.41% | 1.053 | 0.00% | 0.125 | 1 |
| 32 | E8M0-floor | 0.10978 | 0.18123 | 73.05% | 78.48% | 27.14% | 2.699 | 13.91% | 0.03125 | 1 |
| 32 | E8M0-nearest | 0.02013 | 0.07904 | 84.77% | 86.45% | 12.61% | 1.276 | 2.88% | 0.03125 | 1 |
| 32 | E8M0-ceil | 0.01745 | 0.07382 | 83.59% | 85.74% | 12.07% | 1.218 | 0.00% | 0.03125 | 1 |
| 16 | FP32 | 0.01055 | 0.05721 | 89.26% | 88.95% | 9.70% | 0.980 | 0.00% | 0.25 | 3 |
| 16 | E8M0-floor | 0.13456 | 0.20132 | 74.61% | 77.58% | 29.99% | 3.013 | 17.56% | 0.0625 | 3 |
| 16 | E8M0-nearest | 0.02426 | 0.08682 | 84.57% | 85.74% | 13.67% | 1.381 | 5.70% | 0.0625 | 3 |
| 16 | E8M0-ceil | 0.01671 | 0.07232 | 83.79% | 85.98% | 11.74% | 1.186 | 0.00% | 0.0625 | 3 |
| 8 | FP32 | 0.00853 | 0.05155 | 90.23% | 89.84% | 8.68% | 0.877 | 0.00% | 0.5 | 7 |
| 8 | E8M0-floor | 0.17420 | 0.22866 | 73.24% | 77.19% | 34.19% | 3.472 | 25.35% | 0.125 | 7 |
| 8 | E8M0-nearest | 0.02988 | 0.09632 | 84.18% | 84.57% | 15.06% | 1.522 | 9.55% | 0.125 | 7 |
| 8 | E8M0-ceil | 0.01615 | 0.07097 | 82.62% | 86.95% | 11.44% | 1.156 | 0.00% | 0.125 | 7 |

## Decision evidence

The 1x32 FP32 point improves KL, total variation, top-5 overlap, Frobenius error,
and mean absolute error over 1x64, but top-1 falls from 87.11% to 86.91%. That is
one row out of 512, so this capture alone does not establish a broad accuracy
threshold. It does mean 1x32 fails ADR 0003's stated rule that all four softmax
metrics improve on the same harness.

The 1x16 FP32 point improves all four: KL falls from 0.01371 to 0.01055, TV from
0.06540 to 0.05721, top-1 rises to 89.26%, and top-5 overlap rises to 88.95%.
ADR 0004 therefore selects 1x16 for the next protocol revision. More heads,
layers, models, and task data are still required before making a general model
quality claim.

At Bs=16 the existing parameterized RTL would use four exact block accumulators,
four block scaler lanes per score lane, and three FP32 adds per score. The cycle
model projects scaling service of 31, 47, and 79 cycles per tile for 4x4 L1, 8x8
L2, and 16x16 L4. Their T=512 totals become 1,050,695, 264,335, and 133,391
cycles, each 1,030 cycles above Bs=32 while retaining the same binding stage.
Scale traffic rises by 1,024 beats, or 8,192 bytes, and scale storage doubles to
0.25 bytes per Q or K element.

Reproduce the capture in an isolated environment with the versions above, then
run:

```bash
python3 scripts/eval_precision.py \
  --npz docs/results/p0-8-bert-tiny-layer0-head0.npz
```

## Related

- [ADR 0004](../adr/0004-use-1x16-fp32-scales.md)
- [Synthetic precision](precision.md)
- [P0 problem statement](../problem-statements/p0-dense-fp4-matmul.md)
- [Results index](README.md)
