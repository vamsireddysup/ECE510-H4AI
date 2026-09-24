# Reduction-block FP4 precision sweep

This record compares scale formats for P0.2. It uses synthetic normal Q/K inputs
to select the scale contract before RTL implementation; it does not claim accuracy
on transformer activations.

## Method

These are **measured software-model results** from commit `93e7292`, regenerated
after the stable-top-k change with Python 3.12.3 and pinned record version NumPy
1.26.4. `scripts/eval_precision.py` used seed 510,
`D_HEAD=64`, and the same generator sequence and T values 4, 16, 64, 128, and 512
as the previous 14.90% result. The complete 120-point
[machine-readable result](p0-2-precision.json) is committed; the table below is
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

## T=512 results

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

## Interpretation

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
python3 scripts/eval_precision.py > build/p0-2-precision.json
```

## Related

- [ADR 0003, which selects 1x32 FP32](../adr/0003-fp32-scales-with-32-element-blocks.md)
- [P0 dense FP4 problem](../problem-statements/p0-dense-fp4-matmul.md)
- [Reference model](../../model/README.md)
- [Results index](README.md)
