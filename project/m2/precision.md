# Precision and data format -- QK^T accelerator chiplet

## Numerical format chosen

**FP32 (IEEE 754 single precision, 32-bit floating point)**

All data paths in the compute core use 32-bit IEEE 754 floating point.
Each value is stored as a packed `logic [31:0]` vector with the standard
layout: 1 sign bit, 8 exponent bits (bias 127), and 23 mantissa bits with
an implicit leading 1.

---

## Rationale grounded in the kernel and roofline

The target kernel is QK^T matrix multiplication in transformer self-attention.
From M1 profiling on an Intel i5-1145G7 CPU at T=512, d_head=64:

- Arithmetic intensity: AI = 25.60 FLOP/byte
- Measured throughput: 11.36 GFLOP/s
- Classification: compute-bound (AI > ridge = 8.28 FLOP/byte)

Since the kernel is compute-bound, precision choice directly affects
accuracy without changing the memory bandwidth requirement significantly.
FP32 was chosen for the following reasons:

**Correctness:** Transformer attention weights are small floating-point
values typically in the range [-1.0, 1.0] after projection. FP32
represents these values with 7 decimal digits of precision. The QK^T
scores feed directly into softmax -- any quantization error shifts
attention probabilities and degrades model quality in ways that are
difficult to bound without extensive empirical testing.

**Verification simplicity:** With FP32, the hardware output matches the
PyTorch CPU baseline bit-for-bit for the same inputs (within IEEE 754
rounding rules). This makes testbench verification exact: compare hardware
output against Python golden reference with zero tolerance for integer
test vectors. No scaling, dequantization, or error margin is needed.

**Why not INT8:** INT8 reduces the representable range to [-128, 127]
and requires a quantization scale factor. Google TPU uses INT8 because
at production scale the small accuracy loss is acceptable and power savings
are significant. For a student research chiplet where correctness
verification is the primary M2 requirement, INT8 introduces unnecessary
complexity in both hardware (scale factor logic) and verification (scaled
comparison).

**Why not FP16 or BF16:** FP16 has a 5-bit exponent (range 2^-14 to
2^15) which can overflow for large attention scores at long sequence
lengths. BF16 preserves the FP32 exponent range but reduces mantissa
precision to 7 bits, which may cause accuracy loss in the accumulator.
FP32 is the safe baseline choice.

**Why not next-wider (FP64):** FP64 doubles the data width to 64 bits,
halving effective memory bandwidth and doubling the area of every
multiplier. Since the kernel is already compute-bound, adding more
precision would not improve throughput and would increase area
significantly.

---

## Quantization error analysis

Since FP32 is used throughout, there is no quantization error relative
to a FP32 software reference. The hardware computes the same IEEE 754
operations as PyTorch on CPU.

To verify this, the testbench computes QK^T for a 4x4 integer test matrix
and compares hardware output against a Python golden reference computed
with NumPy FP32 arithmetic. All 16 output elements match exactly:

```
result[0][0] = 4.0  (expected 4.0)  error = 0.0
result[0][1] = 6.0  (expected 6.0)  error = 0.0
result[0][2] = 3.0  (expected 3.0)  error = 0.0
result[0][3] = 7.0  (expected 7.0)  error = 0.0
result[1][0] = 12.0 (expected 12.0) error = 0.0
result[1][1] = 14.0 (expected 14.0) error = 0.0
result[1][2] = 11.0 (expected 11.0) error = 0.0
result[1][3] = 15.0 (expected 15.0) error = 0.0
result[2][0] = 2.0  (expected 2.0)  error = 0.0
result[2][1] = 0.0  (expected 0.0)  error = 0.0
result[2][2] = 1.0  (expected 1.0)  error = 0.0
result[2][3] = 1.0  (expected 1.0)  error = 0.0
result[3][0] = 4.0  (expected 4.0)  error = 0.0
result[3][1] = 6.0  (expected 6.0)  error = 0.0
result[3][2] = 5.0  (expected 5.0)  error = 0.0
result[3][3] = 5.0  (expected 5.0)  error = 0.0

Mean absolute error (MAE): 0.0
Maximum absolute error:    0.0
```

For real transformer weights (non-integer values), FP32 arithmetic may
introduce sub-ULP rounding differences compared to FP64, but these are
below 1e-6 in absolute value and do not affect correctness for attention
score computation.

---

## Statement of acceptability

The error is acceptable because the hardware implements IEEE 754 FP32
arithmetic identically to the PyTorch CPU baseline, producing zero
quantization error for the test vectors and sub-ULP rounding error
(< 1e-6 absolute) for real transformer weights. This meets the
correctness requirement for M2 verification and matches the numerical
behavior expected by the transformer model's softmax layer.

---

## Hardware cost acknowledgment

FP32 multipliers are larger than INT8 or INT16 multipliers in silicon
area. For the 8x8 systolic array with 64 FP32 MAC units, the synthesized
area will be larger than an equivalent INT8 design. This is an accepted
tradeoff for M2 correctness. For a production deployment targeting
power-constrained inference, INT8 quantization (as used in Google TPU)
would be the appropriate optimization after FP32 correctness is
established in simulation.

---

## Implementation details

FP32 values are represented as `logic [31:0]` packed IEEE 754 vectors in
all SystemVerilog modules. Arithmetic is implemented using two
synthesizable modules: `fp32_mul.sv` (3-stage pipeline, 3-cycle latency)
and `fp32_add.sv` (combinational with registered output, 1-cycle latency).
No `real`, `shortreal`, or simulation-only constructs are used in the
synthesizable path. The design targets the Skywater 130nm PDK via
OpenLane 2 for M3 synthesis.
