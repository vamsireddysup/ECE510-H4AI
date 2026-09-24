# 0003: use FP32 scales with 32-element reduction blocks

Accepted, September 2026. This decision sets the P0.4 scale contract; no RTL was
changed while making it.

## Decision

Use one FP32 scale per 32 FP4 values along the reduction axis for both Q and K.
For `D_HEAD=64`, every row carries two scales. Compute one exact integer dot per
block, apply that block's Q and K scales, and use one FP32 add to combine the two
block scores.

Keep 1x64 behavior available in the software model for compatibility and
comparison. Do not put E8M0 into the P0 RTL interface. A future decision may add
a separately versioned E8M0 mode after a better power-of-two quantizer is measured.

## Acceptance criterion

For the fixed seed-510, T=512, `D_HEAD=64` synthetic test, a candidate must have
mean KL at most 0.011, mean total variation at most 0.060, top-1 agreement at
least 75%, and top-5 index overlap at least 82%. This criterion is based on
softmax behavior and rejects the current 1x64 baseline on KL and top-5 overlap.
The selected 1x32 FP32 format passes all four at 0.01025, 0.05665, 75.78%, and
82.27%.

This is an engineering gate for a pinned synthetic workload, not a universal
accuracy threshold. P0.8 must repeat the measurements on pinned transformer
activations. A failure there supersedes this decision even if raw-score error is
low.

## Alternatives considered

**1x16 FP32.** It is the most accurate practical candidate measured: mean KL
0.00897, mean total variation 0.05301, top-1 78.12%, and top-5 overlap 83.59%.
Against 1x32 it buys 0.00127 lower KL and 2.34 percentage points of top-1
agreement. It also needs three FP32 adds per score instead of one and doubles
scale storage to 0.25 bytes per Q or K element. The synthetic gain is too small
to commit the RTL to that reduction cost before real-activation evidence exists.

**1x64 FP32.** It needs no cross-block FP32 add and stores 0.0625 scale bytes per
element, but misses the acceptance gate at mean KL 0.01129 and top-5 overlap
81.56%. It remains the model's compatibility mode.

**E8M0 floor and nearest.** Power-of-two scales would replace scale
multiplication with exponent adjustment and use one quarter of the FP32 scale
storage. Neither requested rounding rule retains accuracy. At 1x32, nearest has
mean KL 0.01499 and top-1 70.90%; floor has mean KL 0.04534 and top-1 58.98%.
Both fail all four softmax gates.

The floor premise also needs correction. The stored scale is a dequantization
scale `s=max(abs(block))/6`. Rounding `s` down increases `abs(x)/s`, so it clips
12.83% of inputs at 1x32 in this run. Rounding upward is clipping safe. Testing
that ceiling rule or a scale derived from quantization gain is reasonable future
work, but its result cannot rescue the two rules measured here.

**1x8 FP32.** It gives the best measured metrics, including mean KL 0.00705, but
needs seven FP32 adds and 0.5 scale bytes per element. It is useful as an accuracy
bound, not the P0 implementation point.

## Evidence

The fixed-seed sweep covers Bs 64, 32, 16, and 8 crossed with FP32, E8M0-floor,
and E8M0-nearest at T 4, 16, 64, 128, and 512. The T=512 table, method, tool
versions, raw-score metrics, clipping, storage, and accumulator consequences are
in [the precision record](../results/precision.md). The 1x64 FP32 point reproduces
the prior 14.90% relative Frobenius result.

## Consequences

P0.4 must version the stream contract because each row now has two scales at
`D_HEAD=64`. The score path needs two exact block accumulators, two block-scale
operations, and one FP32 cross-block add. P0.3 can still overlap phases without
waiting for that interface change.

Scale storage rises from 0.0625 to 0.125 bytes per Q or K element. FP4 codes
remain 0.5 bytes per element, so scales add 25% to code storage for each matrix.
The software model remains able to represent any positive block size and a
partial final block, but this ADR commits hardware only to Bs=32 for P0.

## Related

- [Decision records](README.md)
- [Precision sweep](../results/precision.md)
- [P0 dense FP4 problem](../problem-statements/p0-dense-fp4-matmul.md)
- [Development plan](../roadmap.md)
