# Precision choice -- QK^T accelerator chiplet

## Choice: FP32 (IEEE 754 single precision)

The compute core uses 32-bit IEEE 754 floating point (FP32) for both
inputs and the accumulator. All data paths are `logic [31:0]` packed
vectors following the IEEE 754 format internally.

---

## Why FP32

Transformer self-attention weights are small floating-point values,
typically in the range -1.0 to 1.0 after projection. FP32 represents
these values exactly without any quantization step. The QK^T operation
produces a score matrix whose values feed directly into softmax -- any
quantization error here shifts attention probabilities and degrades
model quality.

Using FP32 means the hardware output matches the software baseline
(PyTorch CPU) bit-for-bit for the same inputs, which makes verification
straightforward: the testbench compares hardware output directly against
Python golden reference values with no scaling or dequantization needed.

---

## Why not INT8 or INT16

INT8 and INT16 require a quantization scale factor. The input values
must be multiplied by a scale before feeding into the hardware and
divided after reading the result. This introduces:

- Quantization error proportional to the scale factor resolution
- Additional pre/post processing in software
- More complex verification (scaled comparison instead of exact match)

For a student project where verification correctness is the primary
M2 requirement, FP32 eliminates this complexity entirely.

---

## Why not FP16 or BF16

FP16 has a narrower exponent range (5 bits vs 8 in FP32) which can
cause overflow or underflow for attention scores at longer sequence
lengths. BF16 has the same exponent range as FP32 but only 7 mantissa
bits, which reduces precision. FP32 is the safe choice for correctness.

---

## Quantization error analysis

Since FP32 is used throughout, there is no quantization error. The
hardware computes the same IEEE 754 operations as the software baseline.
The only source of numerical difference would be the order of floating
point additions in the accumulator, which can cause sub-ULP differences
due to floating point non-associativity. These differences are below
1e-5 in absolute value and do not affect correctness.

---

## Hardware cost acknowledgment

FP32 multipliers are larger than INT16 multipliers in silicon area. For
an 8x8 systolic array with 64 FP32 multiply-accumulate units, the area
will be significantly larger than an equivalent INT16 design. This is
an accepted tradeoff for M2 verification correctness. For a production
deployment, INT8 quantization (as used in Google TPU) would be the
appropriate optimization after FP32 correctness is established.

---

## Implementation approach

FP32 values are represented as `logic [31:0]` packed vectors in all
SystemVerilog modules. Floating point arithmetic is implemented using
synthesizable FP32 multiply and add modules (`fp32_mul.sv`,
`fp32_add.sv`) written in pure combinational/registered logic with no
use of `real` or `shortreal` types, which are simulation-only and not
synthesizable. This ensures the design can proceed through OpenLane 2
synthesis targeting the Sky130 130nm PDK in M3.
