# 0001: accumulate FP4 products exactly as integers

Accepted, September 2026. Implemented in
[`rtl/top/qkt_chiplet_top.sv`](../../rtl/top/qkt_chiplet_top.sv).

## Decision

Decode each FP4 E2M1 operand to a signed integer in half units, multiply, and
accumulate the products as exact integers in quarter units within each scale
block. Convert once per block, apply its two scales, then use FP32 only to combine
block scores. Do not use a floating-point adder inside an exact block reduction.

## Why it works for this format

The E2M1 magnitudes are 0, 0.5, 1, 1.5, 2, 3, 4, 6. Doubling them gives the
integers 0, 1, 2, 3, 4, 6, 8, 12, so a product of two operands is an exact integer
in quarter units with a maximum magnitude of `12 * 12 = 144`. At `D_HEAD=64` the
worst-case sum is `144 * 64 = 9216`, which needs `ceil(log2(9217)) = 14` bits plus
a sign, so 15 signed bits hold every possible result exactly.

The accumulation is therefore associative and order-independent, and the only
rounding in the dot product is the single conversion at the end.

## Alternatives considered

**Keep the superseded FP32 accumulator.** The replaced PE buffered all `D_HEAD`
products and added them serially through a three-stage FP32 adder. It is inexact,
order-dependent, and needs both an FP4 product ROM and an FP32 adder that the
integer path does not. It is retained in
[`archive/superseded-rtl/`](../../archive/superseded-rtl/README.md) for comparison.

**A wider fixed-point accumulator sized for a general format.** Deferred. It is
what P1 needs for FP8 E4M3, which requires 43 bits at `D_HEAD=64` against the
current 15. Sizing for that now would pay the cost before the benefit is measured.
See [P1](../problem-statements/p1-format-agile-sparsity.md).

## Evidence

Published work finds that fixed-point accumulators are both exact and more
area-efficient than floating-point accumulators for formats from INT8 through
FP8-E3, and only lose for wider exponent ranges. FP4 E2M1 is well inside that
range.

Every integration run checks each score against an exact integer-dot reference
computed independently in the testbench, and all configurations pass.

## Consequences

P0.4 adds FP32 only across independently scaled blocks; it does not change the
exact accumulation within a block. The floating-point arithmetic is a pair of
`fp32_mul` instances per block and `BLOCK_COUNT-1` cross-block adds. See
[architecture](../architecture.md).

The exactness argument does not generalize. It holds because E2M1 products are
tiny and `D_HEAD` is modest. Any claim from this record must be scoped to FP4
E2M1 and similar narrow formats.

## Related

- [Decision records](README.md)
- [Architecture](../architecture.md)
- [P1, which needs a wider accumulator](../problem-statements/p1-format-agile-sparsity.md)
