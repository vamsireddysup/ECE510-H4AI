# CMAN — Roofline construction and kernel classification

**Hardware:** Peak compute = 10 TFLOPS (FP32) = 10,000 GFLOP/s | Peak DRAM bandwidth = 320 GB/s

---

## Task 1: Roofline

Ridge point = Peak compute / Peak bandwidth = 10,000 / 320 = **31.25 FLOP/byte**

Any kernel above 31.25 FLOP/byte is compute-bound. Any kernel below is memory-bound.

<img width="1440" height="1036" alt="Roofline diagram showing compute ceiling at 10,000 GFLOP/s, bandwidth ceiling slope, ridge point at 31.25 FLOP/byte, GEMM kernel at 170.7 FLOP/byte on compute ceiling, and vector add at 0.083 FLOP/byte on bandwidth ceiling." src="https://github.com/user-attachments/assets/5f6e0059-d4ec-4219-b466-59ba896e9337" />

---

## Task 2: Kernel A — Dense GEMM 1024x1024

To get each output element C[i,j], I multiply a full row of A by a full column of B (1024 multiplications) and sum everything up (1024 additions). That is 2 x 1024 operations per output element, and there are 1024 x 1024 output elements total.

**FLOPs:**
```
FLOPs = 2 x N^3 = 2 x 1024^3 = 2,147,483,648
```

**Bytes transferred (no cache reuse, everything comes from DRAM):**

Each number is FP32 = 4 bytes.
```
Matrix A:  1024 x 1024 x 4 =  4,194,304 bytes
Matrix B:  1024 x 1024 x 4 =  4,194,304 bytes
Matrix C:  1024 x 1024 x 4 =  4,194,304 bytes

Total = 12,582,912 bytes
```

**Arithmetic intensity:**
```
AI = 2,147,483,648 / 12,582,912 = 170.7 FLOP/byte
```

**Analysis:**

| Property | Value |
|---|---|
| AI | 170.7 FLOP/byte |
| Ridge point | 31.25 FLOP/byte |
| Bound | Compute-bound (170.7 >> 31.25) |
| Attainable performance | 10,000 GFLOP/s (hits compute ceiling) |

**Recommendation:** Kernel A is compute-bound, so more FMA units or wider SIMD lanes would help. Increasing memory bandwidth would not change anything here because memory is not what is slowing it down.

---

## Task 3: Kernel B — Vector addition, length 4,194,304

This is the simplest possible kernel -- one addition per element. Load two numbers, add them, write the result.

**FLOPs:**
```
FLOPs = 4,194,304
```

**Bytes transferred (no cache reuse, everything from DRAM):**
```
Vector A:  4,194,304 x 4 = 16,777,216 bytes
Vector B:  4,194,304 x 4 = 16,777,216 bytes
Vector C:  4,194,304 x 4 = 16,777,216 bytes

Total = 50,331,648 bytes
```

**Arithmetic intensity:**
```
AI = 4,194,304 / 50,331,648 = 0.083 FLOP/byte
```

**Analysis:**

| Property | Value |
|---|---|
| AI | 0.083 FLOP/byte |
| Ridge point | 31.25 FLOP/byte |
| Bound | Memory-bound (0.083 << 31.25) |
| Attainable performance | 0.083 x 320 = 26.7 GFLOP/s (hits bandwidth ceiling) |

**Recommendation:** Kernel B is memory-bound, so the only way to improve it is higher memory bandwidth -- something like HBM instead of DRAM. Adding more compute units would not help because the compute units are already sitting idle waiting for data to arrive.

---

## Summary

| Kernel | FLOPs | Bytes | AI (FLOP/byte) | Bound | Attainable (GFLOP/s) |
|---|---|---|---|---|---|
| GEMM 1024x1024 | 2,147,483,648 | 12,582,912 | 170.7 | Compute | 10,000 |
| Vector add 4M | 4,194,304 | 50,331,648 | 0.083 | Memory | 26.7 |

Ridge point: **31.25 FLOP/byte** at **10,000 GFLOP/s**
