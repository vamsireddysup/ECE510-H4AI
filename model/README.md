# Reference model

This is the Python reference for the FP4 numerics. It is authoritative for what a
score should be; the RTL is checked against it, not the other way round. Read it
before changing either the FP4 encoding or the scale rule.

It has no third-party dependencies. `scripts/eval_precision.py` and
`scripts/bench_cpu.py` need NumPy, but the model itself does not.

## What it owns

`qkt_model/reference.py` defines the E2M1 magnitude set, decode and encode, the
FP32 bit pattern of an FP4 product, and the dequantized `QK^T` of two FP4 code
matrices with optional per-row scales.

The magnitude set is 0, 0.5, 1, 1.5, 2, 3, 4, 6, and both zero codes decode to
zero. Encoding rounds to the nearest supported magnitude, ties toward the lower
index.

## What the tests check

`tests/test_reference.py` parses the 256-entry product ROM in
[`archive/superseded-rtl/fp4_mul_lut.sv`](../archive/superseded-rtl/fp4_mul_lut.sv)
and asserts the model agrees with it on all 256 input pairs. It also checks
round-tripping for every positive and negative code, the archived M4 numerical
case, that scales apply by output row and column, and that malformed shapes are
rejected.

The ROM is no longer instantiated by any RTL, but it remains the checked-in
ground truth for FP4 products, so the test still reads it.

## Running it

From the repository root:

```bash
make test-model
```

## Related

- [Verification plan](../docs/verification-plan.md)
- [Architecture](../docs/architecture.md)
- [Synthetic precision result](../docs/results/precision.md)
- [Superseded RTL](../archive/superseded-rtl/README.md)
