# 0003: use FP32 scales with 32-element reduction blocks

Superseded by [ADR 0004](0004-use-1x16-fp32-scales.md), September 2026.
The 1x32 format remains implemented as protocol version 3 at revision
`1311eb0`.

## Decision

Use one FP32 scale per 32 FP4 values along the reduction axis for both Q and K.
For `D_HEAD=64`, every row carries two scales. Compute one exact integer dot per
block, apply that block's Q and K scales, and use one FP32 add to combine the two
block scores.

Keep 1x64 behavior available in the software model for compatibility and
comparison. Do not put E8M0 into the P0 RTL interface. A future decision may add
a separately versioned E8M0 mode after a better power-of-two quantizer is measured.

## Acceptance criterion

Choose the cheapest block size that improves all four softmax metrics over the
1x64 FP32 compatibility baseline on the same fixed seed-510, T=512,
`D_HEAD=64` harness. This comparative rule matches the available evidence and
does not invent universal numeric thresholds from one synthetic workload.

The 1x32 FP32 format is the first smaller block and improves mean KL from 0.01129
to 0.01025, mean total variation from 0.05940 to 0.05665, top-1 agreement from
75.00% to 75.78%, and top-5 overlap from 81.56% to 82.27%. P0.8 must repeat the
comparison on pinned transformer activations; those results can supersede this
decision.

## Alternatives considered

**1x16 FP32.** It is the most accurate practical candidate measured: mean KL
0.00897, mean total variation 0.05301, top-1 78.12%, and top-5 overlap 83.59%.
Against 1x32 it buys 0.00127 lower KL and 2.34 percentage points of top-1
agreement. It also needs three FP32 adds per score instead of one and doubles
scale storage to 0.25 bytes per Q or K element. The synthetic gain is too small
to commit the RTL to that reduction cost before real-activation evidence exists.

**1x64 FP32.** It needs no cross-block FP32 add and stores 0.0625 scale bytes per
element. Its four softmax metrics define the comparison baseline. It remains the
model's compatibility mode.

**E8M0 floor, nearest, and ceiling.** Power-of-two scales would replace scale
multiplication with exponent adjustment and use one quarter of the FP32 scale
storage. Ceiling confirms the predicted clipping-safe behavior, but even 1x16
ceiling is worse than 1x64 FP32 on every reported accuracy metric: mean KL
0.01296, mean TV 0.06361, top-1 71.68%, top-5 overlap 79.53%, and Frobenius
15.97%. At 1x32, nearest has mean KL 0.01499 and floor has 0.04534.

The floor premise needed correction. The stored scale is a dequantization scale
`s=max(abs(block))/6`. Rounding `s` down increases `abs(x)/s`, so it clips 12.83%
of inputs at 1x32. Ceiling rounds `s` upward and clips 0.00%, but its loss of
resolution still rejects E8M0 for P0.

**1x8, 1x4, and 1x2 FP32.** Accuracy continues to improve as blocks shrink. Bs=2
reaches 6.71% Frobenius error and 89.84% top-1 agreement, but needs 31 FP32 adds
and 2 scale bytes per element. These points are accuracy bounds, not practical P0
implementations. Bs=1 is degenerate because each nonzero element normalizes to
exactly positive or negative six.

## Evidence

The fixed-seed sweep covers Bs 64, 32, 16, 8, 4, and 2 crossed with FP32,
E8M0-floor, E8M0-nearest, and E8M0-ceil at T 4, 16, 64, 128, and 512. The T=512 table, method, tool
versions, raw-score metrics, clipping, storage, and accumulator consequences are
in [the precision record](../results/precision.md). The 1x64 FP32 point reproduces
the prior 14.90% relative Frobenius result.

## Consequences

P0.4 versions the stream contract because each row now has two scales at
`D_HEAD=64`. The score path has two exact block accumulators, parallel
block-scale operations, and one FP32 cross-block add. This preserves P0.3's
overlap and keeps 4x4 compute-bound.

The implementation restores the archived three-stage custom FP32 adder and
repairs its magnitude ordering, normalization range, and finite-normal
round-to-nearest-even behavior. The multiplier now uses the same rounding rule.
This keeps three-cycle arithmetic latency and gives a bounded path for later
lane sweeps. It was lower risk than introducing a new third-party FPU during a
format change. Both units still flush underflow rather than implementing gradual
subnormals, and they do not implement every IEEE exception and signed-zero rule.
The pinned synthetic workload exercises finite normal scales and matches the
software model bit-exactly for all 262,144 scores.

Scale storage rises from 0.0625 to 0.125 bytes per Q or K element. FP4 codes
remain 0.5 bytes per element, so scales add 25% to code storage for each matrix.
The independent Gaussian workload probably biases this decision toward larger
blocks. After division by `sqrt(64)`, its logits have standard deviation about
one over 512 candidates, so softmax rows are nearly flat and top-1 agreement
measures extreme-value fragility as much as quantizer quality. Gaussian data also
lacks the structured, heavy-tailed outliers that block scaling mainly fixes.
P0.8 may therefore favor 1x16 on real activations.

The software model remains able to represent any positive block size and a
partial final block. P0.4 should keep the block size a parameter rather than
hard-coding 32, while its verified default implements this Bs=32 decision.

## Related

- [Decision records](README.md)
- [Precision sweep](../results/precision.md)
- [P0 dense FP4 problem](../problem-statements/p0-dense-fp4-matmul.md)
- [Development plan](../roadmap.md)
