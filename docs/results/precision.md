# Synthetic FP4 score error

I used `scripts/eval_precision.py` with seed 510, `D_HEAD=64`, and independent
normal FP32 Q/K matrices. Each row scale is its maximum absolute input divided
by six (or one for a zero row). Values are rounded to the nearest E2M1
magnitude. The FP4 path forms an exact quarter-unit integer dot product, then
applies the two row scales in FP32. The reference is NumPy FP32 QK^T.

| T | Mean absolute score error | Relative Frobenius error |
| ---: | ---: | ---: |
| 4 | 1.198 | 20.61% |
| 16 | 0.827 | 14.10% |
| 64 | 0.964 | 15.00% |
| 128 | 0.913 | 14.57% |
| 512 | 0.945 | 14.90% |

These are synthetic quantization errors under one explicit row-scale rule. The
script models ideal FP32 scale multiplication after the integer dot; it does
not establish bitwise equivalence for the RTL multiplier on arbitrary scales.
It accepts a pinned `.npz` capture with `q` and `k` arrays and records its
SHA-256. I have not yet supplied a pretrained transformer Q/K capture, so no
real-activation error claim is made. The 14.90% synthetic result is a reason
to test block scaling and alternative quantizers before changing the interface.

Reproduce the synthetic run from the repository root:

```bash
python3 scripts/eval_precision.py > build/synthetic-precision.json
```
