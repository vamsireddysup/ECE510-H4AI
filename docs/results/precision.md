# Attention precision results

This record compares reduction-block formats on both fixed-seed synthetic data
and pinned transformer activations. Read it for raw-score error and the
attention-specific softmax metrics that select the default scale block.

## Synthetic method

These are **measured software-model results** from commit `9b87e50`, regenerated
after the stable-top-k change with Python 3.12.3 and pinned record version NumPy
1.26.4. `scripts/eval_precision.py` used seed 510,
`D_HEAD=64`, and the same generator sequence and T values 4, 16, 64, 128, and 512
as the previous 14.90% result. The complete 120-point
[machine-readable result](data/synthetic-precision-sweep.json) is committed; the table below is
generated from it and reports T=512, where each metric covers 262,144 scores.

Each row is divided into reduction blocks of `Bs` elements. FP32 uses
`max(abs(block))/6`. E8M0 stores a one-byte biased exponent for a power-of-two
dequantization scale. `E8M0-floor` applies `floor(log2(scale))` and
`E8M0-nearest` applies `floor(log2(scale)+0.5)`, and `E8M0-ceil` applies
`ceil(log2(scale))`. Inputs are rounded to the nearest
E2M1 value after scaling. Each block forms an exact quarter-unit integer dot, and
block results are scaled and summed in FP32.

Softmax uses `scores/sqrt(64)`. Top-5 agreement is the mean fraction of the five
reference indices also present in the quantized top five, rather than requiring
an identical ordering. Both sets use NumPy's stable `argsort`. KL is `KL(P_ref || P_fp4)`, and total variation is half
the L1 distance.

## Synthetic T=512 results

| Bs | Scale | Mean KL | Mean TV | Top-1 | Top-5 overlap | Rel. Frobenius | Mean abs. error | Clipped inputs | Scale B/element | FP32 adds/score |
| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 64 | FP32 | 0.01129 | 0.05940 | 75.00% | 81.56% | 14.90% | 0.945 | 0.00% | 0.0625 | 0 |
| 64 | E8M0-floor | 0.04126 | 0.11047 | 58.79% | 68.48% | 28.58% | 1.769 | 11.30% | 0.015625 | 0 |
| 64 | E8M0-nearest | 0.01351 | 0.06492 | 71.68% | 78.83% | 16.33% | 1.035 | 1.29% | 0.015625 | 0 |
| 64 | E8M0-ceil | 0.01447 | 0.06689 | 71.68% | 78.87% | 16.85% | 1.064 | 0.00% | 0.015625 | 0 |
| 32 | FP32 | 0.01025 | 0.05665 | 75.78% | 82.27% | 14.23% | 0.904 | 0.00% | 0.125 | 1 |
| 32 | E8M0-floor | 0.04534 | 0.11651 | 58.98% | 67.85% | 30.06% | 1.872 | 12.83% | 0.03125 | 1 |
| 32 | E8M0-nearest | 0.01499 | 0.06835 | 70.90% | 78.67% | 17.24% | 1.092 | 3.66% | 0.03125 | 1 |
| 32 | E8M0-ceil | 0.01356 | 0.06499 | 73.05% | 79.41% | 16.34% | 1.034 | 0.00% | 0.03125 | 1 |
| 16 | FP32 | 0.00897 | 0.05301 | 78.12% | 83.59% | 13.29% | 0.843 | 0.00% | 0.25 | 3 |
| 16 | E8M0-floor | 0.05336 | 0.12729 | 55.47% | 66.99% | 32.66% | 2.046 | 17.03% | 0.0625 | 3 |
| 16 | E8M0-nearest | 0.01662 | 0.07193 | 71.29% | 79.22% | 18.22% | 1.152 | 6.25% | 0.0625 | 3 |
| 16 | E8M0-ceil | 0.01296 | 0.06361 | 71.68% | 79.53% | 15.97% | 1.012 | 0.00% | 0.0625 | 3 |
| 8 | FP32 | 0.00705 | 0.04695 | 80.08% | 85.47% | 11.83% | 0.751 | 0.00% | 0.5 | 7 |
| 8 | E8M0-floor | 0.06797 | 0.14471 | 53.71% | 64.45% | 36.93% | 2.332 | 25.42% | 0.125 | 7 |
| 8 | E8M0-nearest | 0.01858 | 0.07599 | 71.68% | 78.67% | 19.24% | 1.216 | 9.59% | 0.125 | 7 |
| 8 | E8M0-ceil | 0.01237 | 0.06215 | 71.68% | 79.38% | 15.61% | 0.989 | 0.00% | 0.125 | 7 |

The old 1x64 FP32 row reproduces 14.8983%, which rounds to the recorded 14.90%.
All storage figures are per Q element or per K element; total Q-plus-K scale
traffic is twice the listed rate. The FP32-add count is `ceil(64/Bs)-1` and is a
**projected RTL consequence**, not a measured hardware cost.

A review rerun under NumPy 2.4.6 produced the same score metrics but different
E8M0 top-5 overlap in nine cells. The committed NumPy 1.26.4 result and the
reported NumPy 2.4.6 result are both retained here:

| Bs | Rule | NumPy 1.26.4 | NumPy 2.4.6 |
| ---: | --- | ---: | ---: |
| 64 | floor | 68.48% | 68.36% |
| 64 | nearest | 78.83% | 78.83% |
| 64 | ceil | 78.87% | 78.98% |
| 32 | floor | 67.85% | 67.89% |
| 32 | nearest | 78.67% | 78.52% |
| 32 | ceil | 79.41% | 79.30% |
| 16 | floor | 66.99% | 67.15% |
| 16 | nearest | 79.22% | 79.14% |
| 16 | ceil | 79.53% | 79.45% |
| 8 | floor | 64.45% | 64.41% |
| 8 | nearest | 78.67% | 78.67% |
| 8 | ceil | 79.38% | 79.38% |

There are no exact ties at the fifth/sixth boundary. The difference is therefore
version-specific NumPy behavior elsewhere in the harness, not ambiguous top-k
membership. The committed JSON pins the reviewed table to NumPy 1.26.4, and the
regression regenerates every T=512 value before checking that table.

## Synthetic interpretation

The selected 1x32 FP32 format improves all four softmax metrics over 1x64 while
requiring one cross-block FP32 add. Moving to 1x16 improves mean KL by 0.00127,
mean TV by 0.00364, top-1 by 2.34 percentage points, and top-5 overlap by 1.33
points, but requires three adds and doubles scale storage from 0.125 to 0.25
bytes per element. That incremental synthetic improvement does not justify
building a three-add reduction before real activations are available.

No E8M0 rule is competitive in this quantizer. Ceiling is clipping safe as
predicted, but at 1x16 its mean KL 0.01296, mean TV 0.06361, top-1 71.68%, top-5
79.53%, and Frobenius error 15.97% are all worse than 1x64 FP32. At 1x32,
nearest raises mean KL 46.3% relative to FP32 and floor raises it 342.6%. Floor
is not clipping safe for a dequantization scale: rounding `max(abs(block))/6`
down makes normalized magnitudes larger, producing a 12.83% clip rate at 1x32.


## Smaller-block accuracy bound

The optional FP32-only extension shows that accuracy has not plateaued. At Bs=4,
mean KL is 0.00478, top-1 agreement is 83.40%, and relative Frobenius error is
9.71%, at a projected 15 FP32 adds and 1 scale byte per element. At Bs=2, those
metrics reach 0.00227, 89.84%, and 6.71%, at 31 adds and 2 scale bytes per
element. Bs=1 is omitted because it is degenerate: every nonzero element
normalizes exactly to positive or negative six and reports zero quantization
error while requiring one scale per code.

Reproduce from the repository root:

```bash
mkdir -p build
python3 scripts/eval_precision.py > build/data/synthetic-precision-sweep.json
```

## Transformer activation captures

The original committed [capture](data/bert-tiny-layer0-head0.npz) contains 512
by 64 Q and K arrays from layer 0, head 0 of Google's
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

Three additional captures cover both heads of layer 1 and the last layer of the
larger four-layer, 256-hidden-state
[`bert_uncased_L-4_H-256_A-4`](https://huggingface.co/google/bert_uncased_L-4_H-256_A-4/tree/387825ce42dbb39b87911cdf8e383ee3b25184f8).
The capture script now obtains each layer's real input with a forward pre-hook;
using the embedding output directly would only be correct for layer 0.

| Capture | Model revision | Layer/head | SHA-256 |
| --- | --- | ---: | --- |
| [`tiny-layer0-head0`](data/bert-tiny-layer0-head0.npz) | `30b0a37ccaaa32f332884b96992754e246e48c5f` | 0/0 | `bda32c19f874329b641947da8fc9e6ef2696bc1a6b657914a527b707d50caf22` |
| [`tiny-layer1-head0`](data/bert-tiny-layer1-head0.npz) | `30b0a37ccaaa32f332884b96992754e246e48c5f` | 1/0 | `97cb93439482be4d4c231ced3127282152f15029d21588cf62132ce01c570d55` |
| [`tiny-layer1-head1`](data/bert-tiny-layer1-head1.npz) | `30b0a37ccaaa32f332884b96992754e246e48c5f` | 1/1 | `710b50924f90017326266c00890d4d74772385ebffebc88684b4b4e23b3898f0` |
| [`small-layer3-head0`](data/bert-small-layer3-head0.npz) | `387825ce42dbb39b87911cdf8e383ee3b25184f8` | 3/0 | `a570bdcd67bd967c316bdf69b182028c066074446f6b96132d8618969a0b2b63` |

Capture tools were Python 3.12.3, PyTorch 2.8.0+cpu, and Transformers 4.56.2.
The sweep used NumPy 1.26.4 and the same quantizer and metrics as the synthetic
P0.2 record. The complete [machine-readable sweep](data/bert-tiny-layer0-head0-precision.json)
contains every Bs 64/32/16/8/4/2 and scale-type combination.

## First activation sweep

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

## Cross-capture FP32 evidence

The table below condenses the FP32 rows from the four complete machine-readable
sweeps. Top-1 and top-5 are percentages; Frobenius error is relative percent.

| Capture | Bs | Mean KL | Mean TV | Top-1 | Top-5 | Rel. Frobenius |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| tiny L0 H0 | 64 | 0.01371 | 0.06540 | 87.11% | 88.13% | 10.98% |
|  | 32 | 0.01259 | 0.06253 | 86.91% | 88.48% | 10.41% |
|  | 16 | 0.01055 | 0.05721 | 89.26% | 88.95% | 9.70% |
| tiny L1 H0 | 64 | 0.05086 | 0.11654 | 84.96% | 97.15% | 6.61% |
|  | 32 | 0.04727 | 0.11040 | 85.35% | 96.99% | 6.37% |
|  | 16 | 0.04011 | 0.10328 | 87.70% | 97.50% | 5.81% |
| tiny L1 H1 | 64 | 0.09360 | 0.16817 | 74.02% | 97.30% | 6.65% |
|  | 32 | 0.05698 | 0.12637 | 83.98% | 97.54% | 6.24% |
|  | 16 | 0.03944 | 0.10348 | 87.50% | 97.50% | 5.80% |
| small L3 H0 | 64 | 0.02617 | 0.07657 | 92.58% | 88.13% | 14.17% |
|  | 32 | 0.02256 | 0.07072 | 94.53% | 89.26% | 13.35% |
|  | 16 | 0.01944 | 0.06459 | 94.14% | 89.45% | 12.52% |

Complete results, including Bs=8/4/2 and every E8M0 rule, are in the original
[layer-0 JSON](data/bert-tiny-layer0-head0-precision.json), the two
[layer-1 head-0](data/bert-tiny-layer1-head0-precision.json) and
[head-1](data/bert-tiny-layer1-head1-precision.json) records, and the
[larger-model JSON](data/bert-small-layer3-head0-precision.json).

## Decision evidence

The 1x32 FP32 point improves KL, total variation, top-5 overlap, Frobenius error,
and mean absolute error over 1x64, but top-1 falls from 87.11% to 86.91%. That is
one row out of 512, so this capture alone does not establish a broad accuracy
threshold. It does mean 1x32 fails ADR 0003's stated rule that all four softmax
metrics improve on the same harness.

The 1x16 FP32 point improves all four: KL falls from 0.01371 to 0.01055, TV from
0.06540 to 0.05721, top-1 rises to 89.26%, and top-5 overlap rises to 88.95%.
ADR 0004 therefore selects 1x16 for the next protocol revision. The added
captures strengthen that decision: Bs=16 improves all four softmax metrics over
Bs=64 in every capture. Bs=32 fails that rule on top-1 for tiny layer 0 and on
top-5 for tiny layer 1 head 0. Bs=8 can improve further but doubles accumulator,
scale, and cross-block-adder cost again. These four heads are engineering
evidence for the default, not a general model-quality claim.

At Bs=16 the existing parameterized RTL would use four exact block accumulators,
four block scaler lanes per score lane, and three FP32 adds per score. The cycle
model projects scaling service of 31, 47, and 79 cycles per tile for 4x4 L1, 8x8
L2, and 16x16 L4. Their T=512 totals become 1,050,696, 264,336, and 133,392
cycles, each 1,030 cycles above Bs=32 while retaining the same binding stage.
Scale traffic rises by 1,024 beats, or 8,192 bytes, and scale storage doubles to
0.25 bytes per Q or K element.

Reproduce a capture in an isolated environment with the versions above, then
run the sweep. For example:

```bash
python3 scripts/capture_transformer_qk.py \
  docs/results/data/bert-tiny-layer1-head0.npz --layer 1 --head 0
python3 scripts/eval_precision.py \
  --npz docs/results/data/bert-tiny-layer1-head0.npz
```

## Block-scale format study

The scale format is a hardware choice as much as a numerical one. FP32 scales
cost four bytes per block and a 24x24 significand multiply per score; E4M3
costs one byte and a 4-bit significand multiply; E8M0 costs one byte and turns
the multiply into an exponent add. [ADR 0003](../adr/0003-fp32-scales-with-32-element-blocks.md)
rejected E8M0 on accuracy, but it only tested three rounding rules of the
scale, and it never priced the alternatives.

These are **measured software-model results** at Bs=16 across all four pinned
captures, produced by `scripts/eval_precision.py --scale-study`. The study
quantizer reproduces the committed FP32 path bit-for-bit, so these rows are
comparable with the tables above. Rules tested:

- **FP32**, the current default, `max(abs(block))/6`.
- **FP32-4over6** and **E4M3-4over6**, per block choosing whichever of
  `max/6` and `max/4` has lower reconstruction error, after
  [Four Over Six](https://arxiv.org/html/2512.02010v4).
- **E4M3**, NVFP4's arrangement: a per-tensor FP32 scale maps the largest block
  scale into the E4M3 range, and each block scale is E4M3 relative to it. The
  product of the two tensor scales is one constant per command, which the host
  can fold into the softmax temperature.
- **E4M3-search**, the same with a search over E4M3 code offsets from -2 to +6,
  after [ScaleSearch](https://arxiv.org/html/2605.12464v1).
- **E8M0-OCP**, the OCP MX rule `floor(log2(max)) - 2`; **E8M0-ceil**, the
  clipping-safe rule already in the sweeps above; and **E8M0-UOS**,
  `ceil(log2(max/7.25))` from [MXAttention](https://arxiv.org/html/2607.24377v1).

Mean across the four captures, against the FP32 default:

| Scale rule | Bytes/element | Scale operation | Mean KL | Top-1 | Rel. Frobenius |
| --- | ---: | --- | ---: | ---: | ---: |
| FP32 | 0.25 | 24x24 significand multiply | 0.02738 | 89.65% | 8.46% |
| FP32-4over6 | 0.25 | 24x24 significand multiply | 0.02469, -9.8% | 89.06%, -0.59 pt | 7.67%, -9.3% |
| E4M3 | 0.0625 | 4-bit significand multiply | 0.02779, +1.5% | 90.38%, +0.73 pt | 8.50%, +0.6% |
| E4M3-4over6 | 0.0625 | 4-bit significand multiply | 0.02497, -8.8% | 90.53%, +0.88 pt | 7.79%, -7.9% |
| **E4M3-search** | **0.0625** | **4-bit significand multiply** | **0.02114, -22.8%** | **90.82%, +1.17 pt** | **7.27%, -14.0%** |
| E8M0-OCP | 0.0625 | exponent add only | 0.05537, +102.2% | 87.06%, -2.59 pt | 11.58%, +36.9% |
| E8M0-ceil | 0.0625 | exponent add only | 0.04992, +82.3% | 87.74%, -1.90 pt | 10.26%, +21.4% |
| E8M0-UOS | 0.0625 | exponent add only | 0.04825, +76.2% | 87.30%, -2.34 pt | 10.17%, +20.3% |

Per-capture rows are in
[`data/scale-format-study.csv`](data/scale-format-study.csv).

**E4M3 with a scale search is better than FP32 on every metric while costing a
quarter of the scale storage and a far smaller multiplier.** It lowers mean KL
by 22.8%, raises top-1 agreement by 1.17 points, and cuts relative Frobenius
error by 14.0%, and it improves mean KL on all four captures individually. The
search is offline: it runs in the host's quantizer, and the hardware only
consumes the resulting one-byte scale. That the accuracy gain and the hardware
saving point the same way is the useful part; it is the opposite of the
accuracy-for-area trade ADR 0003 assumed.

E8M0 stays clearly worse. The UOS boundary does help, cutting the KL penalty
from 102.2% to 76.2% against OCP's rule, but an exponent-only scale still loses
2.34 points of top-1 agreement. On this evidence the exponent-add scaler is not
worth its accuracy.

### What each format costs in silicon

`rtl/probe/scaler_probe.sv` is one score lane's scaling path, the exact
quarter-unit conversion followed by the two block-scale applications, built
once per format so the three are comparable. It is a cost probe, not part of
the active design. The narrow variants were checked bit-exact against a
double-precision reference over 539 accumulator and scale combinations each
before their area was believed.

Mapped with Yosys 0.44 to the Sky130 HD typical library at `ACC_W=13`, the
Bs=16 accumulator width, flattened so submodules are counted:

| Scale format | Scale bits | Cells | Mapped area | Against FP32 | Scale arithmetic |
| --- | ---: | ---: | ---: | ---: | --- |
| FP32 | 32 | 6,761 | 52,280 um² | | two 24x24 significand multiplies |
| **E4M3** | **8** | **1,360** | **10,695 um²** | **4.89x smaller** | two 24x4 significand multiplies |
| E8M0 | 8 | 367 | 3,780 um² | 13.83x smaller | exponent adds only |

The rows are in [`data/scaler-format-cost.csv`](data/scaler-format-cost.csv).
Scale storage shrinks by the same four times: `sq` and `sk` together hold
`2 * T_MAX * ceil(D_HEAD/Bs)` scales, which is 4,096 bits at 32 bits and
1,024 at 8, and that grows with `T_MAX`.

### Reading the two halves together

E4M3 with a scale search is **more accurate than the FP32 default on every
softmax metric and 4.89 times smaller in the scaling path**, with a quarter of
the scale storage. There is no accuracy-for-area trade to make here, which is
what makes it worth acting on; [ADR 0003](../adr/0003-fp32-scales-with-32-element-blocks.md)
assumed a finer scale had to cost more hardware, and at 32-bit scales it did.

E8M0 is 13.83 times smaller still, and that is a real option if the scaling
path ever dominates area. It costs 2.34 points of top-1 agreement and 76% more
KL divergence, so it is not free, and on this evidence I am not taking it.

[ADR 0008](../adr/0008-e4m3-block-scales.md) records the decision. The numbers
above are mapped, without wires; the routed consequence is a milestone M2
result.

## Softmax-invariant preprocessing

M1 tested two transformations before quantization. K channel-mean centering
subtracts the mean K vector from every key, which subtracts one constant from
each query row of `QK^T`. A normalized Walsh-Hadamard transform applies the same
orthogonal rotation to Q and K. Both preserve attention probabilities in exact
arithmetic. Across the four captures, the largest measured probability change
from float32 evaluation of either transform or their combination is
`1.82e-6`; this is numerical rounding rather than a model change.

These are **measured software-model results** at Bs=16 with NumPy 1.26.4. Raw
score error is computed after removing each score row's mean, because an
arbitrary row constant is invisible to softmax. The aggregate values are
unweighted means of the four pinned captures.

| Scale | Preprocessing | Mean KL | Mean TV | Top-1 | Top-5 | Row-centered rel. Frobenius |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| FP32 | none | 0.02738 | 0.08214 | 89.65% | 93.35% | 10.03% |
| FP32 | K center | 0.03268 | 0.09162 | 88.53% | 94.02% | 9.06% |
| FP32 | Hadamard | 0.03071 | 0.08695 | 87.40% | 93.54% | 10.12% |
| FP32 | both | 0.04653 | 0.10511 | 83.35% | 93.87% | 9.13% |
| E4M3-search | none | **0.02114** | 0.07339 | **90.82%** | 94.28% | 8.63% |
| E4M3-search | K center | 0.02712 | 0.08128 | 89.16% | 94.82% | **7.85%** |
| E4M3-search | Hadamard | 0.02165 | **0.07338** | 90.53% | 94.61% | 8.70% |
| E4M3-search | both | 0.02849 | 0.08443 | 87.74% | **94.86%** | 7.86% |

The capture-level selected-format result shows why the aggregate is not enough:

| Capture | Preprocessing | Mean KL | Top-1 | Top-5 |
| --- | --- | ---: | ---: | ---: |
| tiny L0 H0 | none / K center / Hadamard / both | 0.00786 / 0.00744 / 0.00766 / 0.00746 | 91.02% / 89.84% / 90.82% / 88.67% | 89.84% / 90.20% / 91.09% / 91.17% |
| tiny L1 H0 | none / K center / Hadamard / both | 0.02741 / 0.04847 / 0.02807 / 0.04914 | 89.06% / 88.09% / 88.09% / 84.96% | 98.09% / 97.93% / 97.97% / 97.81% |
| tiny L1 H1 | none / K center / Hadamard / both | 0.03055 / 0.03816 / 0.03538 / 0.04037 | 89.84% / 84.57% / 88.48% / 82.81% | 98.36% / 98.67% / 97.89% / 98.36% |
| small L3 H0 | none / K center / Hadamard / both | 0.01876 / 0.01439 / 0.01549 / 0.01700 | 93.36% / 94.14% / 94.73% / 94.53% | 90.82% / 92.50% / 91.48% / 92.11% |

No preprocessing becomes the default. K centering lowers row-aligned raw error
and improves top-5 on average, but worsens mean KL, TV, and top-1. Hadamard
rotation leaves mean TV effectively unchanged under searched E4M3 while
worsening KL and top-1. The larger, deeper capture improves under both rules,
while the two tiny-model layer-1 heads regress. A layer-selective rule may still
be useful in P1, but these four captures do not support applying either rule to
every layer.

Reproduce the 32 rows with:

```bash
python3 scripts/eval_precision.py --preprocessing-study \
  --captures docs/results/data/bert-tiny-layer0-head0.npz \
  docs/results/data/bert-tiny-layer1-head0.npz \
  docs/results/data/bert-tiny-layer1-head1.npz \
  docs/results/data/bert-small-layer3-head0.npz
```

The raw generated record, including every capture SHA-256, is
[`data/preprocessing-study.json`](data/preprocessing-study.json). A model test
regenerates every row.

## Per-block FP4 or INT4

M1 next tested whether each Q and K block should use FP4 E2M1 or signed INT4.
The host quantizer searches E4M3 block scales for both formats and selects the
format with lower reconstruction mean-square error independently for every row
and 16-value block. This is a **measured software-model result** on the same four
pinned captures with NumPy 1.26.4.

| Element rule | Mean KL | Mean TV | Top-1 | Top-5 | Rel. Frobenius | INT4 blocks |
| --- | ---: | ---: | ---: | ---: | ---: | ---: |
| Fixed FP4 | 0.02114 | 0.07339 | **90.82%** | 94.28% | 7.27% | 0% |
| Fixed INT4 | 0.02164 | 0.07336 | 89.94% | 94.48% | 6.99% | 100% |
| **Adaptive** | **0.01875** | **0.06869** | 90.48% | **94.97%** | **6.42%** | 62.14% |

Adaptive selection improves mean KL by 11.3%, TV by 6.4%, top-5 by 0.69
points, and relative Frobenius error by 11.7% against fixed FP4. Mean top-1
falls by 0.34 points, so it does not pass the project's rule that a new default
must improve all softmax metrics.

The capture-level direction also changes. Adaptive KL improves on all three
tiny-BERT heads, from 0.00786/0.02741/0.03055 to
0.00623/0.02404/0.02271. On small-BERT layer 3 head 0 it worsens from 0.01876
to 0.02203, and top-1 falls from 93.36% to 91.80%. The result supports P1's
layer-selective premise but rejects a global adaptive default chosen only by
local reconstruction error.

The hardware cost is one format bit per Q/K block plus format-aware decode and
scale exponent adjustment. Native integer products are bounded by 144 for
FP4×FP4, 96 for FP4×INT4, and 64 for INT4×INT4. At Bs=16, the existing signed
13-bit accumulator covers all three. This is a model result; no mixed-format RTL
exists yet.

Reproduce with `--element-format-study` and the same four `--captures` listed
in the preprocessing command above. The 12 generated rows and capture hashes
are in [`data/element-format-study.json`](data/element-format-study.json), and
a model test regenerates every row.

## Cross-block accumulation order

M1 compared the current sequential FP32 reduction with a balanced tree over the
four Bs=16 block scores. This is a **measured software-model result** under both
FP32 and searched E4M3 block scales on all four captures.

Tree order changes 24.5% to 29.4% of score bit patterns, with a largest absolute
score change of `1.53e-5`. It changes no top-1 or top-5 result on any capture.
The largest KL change is below `1e-9`; TV and Frobenius changes are likewise
below the reported precision.

Sequential reduction remains the reference. M2 naturally produces block scores
in sequence, and keeping that order preserves the existing bit-exact contract.
A balanced tree would be acceptable for measured attention quality, but it
would change score bits without improving any observed metric and would require
a separately versioned numerical contract.

Reproduce with `--accumulation-study` and the four pinned `--captures`. The 16
generated rows and capture hashes are in
[`data/accumulation-order-study.json`](data/accumulation-order-study.json), and
a model test regenerates every row.

## Exponent-only score bound

M1 measured whether sign and exponent bits can safely identify attention scores
that are too far below their row maximum to matter. For each quantized operand,
the model replaces its magnitude by the enclosing powers of two. Same-sign
products use the upper endpoints; opposite-sign products use the lower
endpoints, because that is the least-negative product. Their sum is therefore a
conservative upper bound on the signed score without multiplying mantissas.

The threshold is `rowmax - tau` after division by `sqrt(D_HEAD)`. `rowmax` is
the unpruned searched-E4M3 FP4 row maximum, so this is a two-pass opportunity,
not yet a proposed streaming implementation. A score is safe to skip only when
its upper bound is below the threshold. A 4x4 output tile is safe only when all
16 scores pass. These are **measured software-model results** across the four
pinned captures with NumPy 1.26.4; aggregate values are unweighted capture
means.

| Tau | Oracle scores below threshold | Safely bounded scores | Bound recall | Safe 4x4 tiles | Removed probability, score skips | Removed probability, tile skips |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| 1 | 99.48% | 57.71% | 58.00% | 18.62% | 2.060% | 0.01561% |
| 2 | 98.60% | 46.78% | 47.32% | 14.81% | 0.770% | 0.00204% |
| 4 | 92.13% | 28.83% | 29.77% | 8.66% | 0.049% | 0.00011% |
| 6 | 79.09% | 17.56% | 18.47% | 4.19% | 0.00150% | 0.000009% |
| 8 | 65.91% | 10.25% | 11.39% | 1.45% | 0.000044% | 0.0000006% |

At tau=4, safe score coverage ranges from 5.83% on tiny layer 0 head 0 to
46.38% on tiny layer 1 head 1. Whole-tile coverage ranges from zero to 18.38%.
This variation rules out a fixed performance claim from these four heads.
Across every tau and capture, pruning preserves the unpruned FP4 top-1 and
top-5 sets. The mean reverse KL to the unpruned distribution is 0.000491 at
tau=4. Forward KL is intentionally not reported: hard pruning assigns zero
probability and makes `KL(P_unpruned || P_pruned)` infinite.

The result supports keeping exponent-first skipping as a later experiment, but
does not select hardware. It needs a row-maximum pass or predictor, and the
cost of producing these signed interval sums must be lower than the exact dot
products they avoid. Whole-tile skipping is directly compatible with the
current 4x4 engine and has negligible measured softmax cost at tau=4, but only
8.66% mean coverage.

Reproduce the 20 rows with `--exponent-bound-study` and the four pinned
`--captures`. The generated record and capture hashes are in
[`data/exponent-bound-study.json`](data/exponent-bound-study.json); the model
suite regenerates every row and asserts that the safe mask never includes a
score above its threshold.

## Output score format

The replicated engine is bound by the 64-bit output port, which carries two FP32
scores per cycle ([ADR 0007](../adr/0007-fix-eight-replicated-engines.md)). A
16-bit score would carry four per beat and halve the T=512 output floor from
131,072 to 65,536 cycles with no extra pins. Whether that is acceptable is a
softmax-quality question, so I measured it.

These are **measured software-model results**. Each row keeps the selected
Bs=16 FP32 scale format and quantizes the finished score after the FP32 scale
multiply and cross-block sum, which is exactly where the RTL would do it. FP16
uses NumPy's round-to-nearest-even cast; BF16 truncates the low 16 mantissa bits
with round-to-nearest, ties to even.

| Capture | Output | Mean KL | Mean TV | Top-1 | Top-5 | Rel. Frobenius |
| --- | --- | ---: | ---: | ---: | ---: | ---: |
| tiny L0 H0 | FP32 | 0.010546 | 0.057213 | 89.26% | 88.95% | 9.696% |
|  | FP16 | 0.010546 | 0.057213 | 89.26% | 88.98% | 9.696% |
|  | BF16 | 0.010579 | 0.057288 | 89.26% | 88.91% | 9.698% |
| tiny L1 H0 | FP32 | 0.040114 | 0.103282 | 87.70% | 97.50% | 5.807% |
|  | FP16 | 0.040103 | 0.103266 | 87.70% | 97.50% | 5.807% |
|  | BF16 | 0.040289 | 0.103635 | 87.89% | 97.46% | 5.810% |
| tiny L1 H1 | FP32 | 0.039442 | 0.103476 | 87.50% | 97.50% | 5.798% |
|  | FP16 | 0.039440 | 0.103463 | 87.50% | 97.50% | 5.798% |
|  | BF16 | 0.039374 | 0.103385 | 87.89% | 97.50% | 5.800% |
| small L3 H0 | FP32 | 0.019438 | 0.064586 | 94.14% | 89.45% | 12.521% |
|  | FP16 | 0.019435 | 0.064561 | 94.14% | 89.49% | 12.521% |
|  | BF16 | 0.019518 | 0.064774 | 93.75% | 89.30% | 12.523% |

FP16 output does not change top-1 agreement on any of the four captures. Its
largest KL change is 0.000011 and its largest top-5 change is 0.04 percentage
points, in both directions. Relative Frobenius error is unchanged to five
decimal places. BF16 costs more, as its eight mantissa bits predict: KL rises by
up to 0.3% relative, top-5 falls by up to 0.05 points, and top-1 moves by up to
0.39 points in both directions.

Range is not a concern on these captures. The largest absolute reference score
is 182.99, against 65,504 for the largest finite FP16 value, so there is about
358x of headroom. A longer sequence, a larger head dimension, or an unscaled
model could reduce that, so a real FP16 output mode would need its own range
check rather than inheriting this one.

This is a measurement, not a recommendation. It does not close the port-width
option and it does not by itself justify a protocol version. What it does
establish is that output-score width is **not** blocked by softmax quality at
FP16 on this evidence, so a future protocol revision has a measured basis to
consider it. Reproduce with:

```bash
python3 scripts/eval_precision.py \
  --npz docs/results/data/bert-tiny-layer0-head0.npz --output-formats
```

The reviewed rows are in
[`data/output-format-sweep.csv`](data/output-format-sweep.csv).

### What it would be worth

Halving the output floor would take the measured eight-engine T=512 command from
135,280 cycles toward roughly 69,744 cycles, keeping the same 4,208 cycles of
startup, fill, and drain. At the 30.5 ns setup-only bound that is about 2.13 ms
instead of 4.13 ms. Against the refreshed CPU baseline in the
[performance record](performance.md) that is still 7.3x slower than one OpenBLAS
thread at 0.2932 ms and 15.0x slower than four cores at 0.1422 ms. A narrower
score format is therefore worth having for traffic and for the port, but it does
not change the conclusion that this part does not win on wall clock.

## Related

- [ADR 0004: use 1x16 FP32 scales](../adr/0004-use-1x16-fp32-scales.md)
- [ADR 0007: fix eight replicated engines](../adr/0007-fix-eight-replicated-engines.md)
- [Reference model](../../model/README.md)
- [Results index](README.md)
