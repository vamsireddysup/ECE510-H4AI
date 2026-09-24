# Reference model

This is the Python reference for the FP4 numerics. It is authoritative for what a
score should be; the RTL is checked against it, not the other way round. Read it
before changing either the FP4 encoding or the scale rule.

The reference package has no third-party runtime dependency. The required test
extra includes pinned NumPy 1.26.4 because the precision provenance regression
imports it; `make test-model` must not silently skip that required gate.

## What it owns

`qkt_model/reference.py` defines the E2M1 magnitude set, decode and encode, the
FP32 bit pattern of an FP4 product, and the dequantized `QK^T` of two FP4 code
matrices. Scales can be flat vectors for the original one-block-per-row format,
or matrices with one scale per reduction-axis block. A partial final block uses
the same scale as the other elements in that block.

The magnitude set is 0, 0.5, 1, 1.5, 2, 3, 4, 6, and both zero codes decode to
zero. Encoding rounds to the nearest supported magnitude, ties toward the lower
index. Setting `block_size=D_HEAD` retains the original one-scale-per-row
behavior.

## What the tests check

`tests/test_reference.py` parses the 256-entry product ROM in
[`archive/superseded-rtl/fp4_mul_lut.sv`](../archive/superseded-rtl/fp4_mul_lut.sv)
and asserts the model agrees with it on all 256 input pairs. It also checks
round-tripping for every positive and negative code, the archived M4 numerical
case, row and block scale application, a partial final block, and rejection of
malformed shapes.

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
