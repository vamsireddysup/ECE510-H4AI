# CMAN — Roofline construction and kernel classification

**Hardware specification:** Peak compute = 10 TFLOPS (FP32) = 10,000 GFLOP/s | Peak DRAM bandwidth = 320 GB/s

---

## Task 1: Roofline construction

**Ridge point calculation:**

Ridge point = Peak compute / Peak bandwidth = 10,000 GFLOP/s / 320 GB/s = **31.25 FLOP/byte**

This is the arithmetic intensity at which a kernel transitions from memory-bound to compute-bound. Any kernel with AI > 31.25 FLOP/byte is compute-bound and hits the compute ceiling. Any kernel with AI < 31.25 FLOP/byte is memory-bound and hits the bandwidth ceiling.

**Roofline construction rules:**
- X axis: arithmetic intensity (FLOP/byte), log scale, range 0.01 to 1000
- Y axis: attainable performance (GFLOP/s), log scale, range 1 to 100,000
- Bandwidth ceiling (diagonal): Performance = AI x 320 GB/s, slope = 1 on log-log axes
- Compute ceiling (flat): Performance = 10,000 GFLOP/s
- Ridge point: (31.25 FLOP/byte, 10,000 GFLOP/s)

See roofline diagram: `codefest/cf02/profiling/roofline_project.png`

---

## Task 2: Kernel A — Dense GEMM 1024x1024

**Problem:** Multiply two FP32 matrices A and B, each of size 1024x1024, to produce output matrix C.

### (a) FLOPs calculation

Each output element C[i,j] requires multiplying a row of A by a column of B (1024 multiplications) and summing the results (1024 additions). Each element therefore costs 2 x 1024 operations.

Total output elements = 1024 x 1024 = 1,048,576

```
FLOPs = 2 x N^3  where N = 1024
FLOPs = 2 x 1024 x 1024 x 1024
FLOPs = 2,147,483,648  (~2.1 GFLOP)
```

### (b) Bytes transferred (no cache reuse, all from DRAM)

Each matrix element is FP32 = 4 bytes.

```
Matrix A:  1024 x 1024 x 4 bytes =  4,194,304 bytes
Matrix B:  1024 x 1024 x 4 bytes =  4,194,304 bytes
Matrix C:  1024 x 1024 x 4 bytes =  4,194,304 bytes  (written back to DRAM)

Total bytes = 3 x 4,194,304 = 12,582,912 bytes (~12 MB)
```

### (c) Arithmetic intensity

```
AI = FLOPs / bytes = 2,147,483,648 / 12,582,912 = 170.7 FLOP/byte
```

### (d) Analysis

| Property | Value |
|---|---|
| Arithmetic intensity | 170.7 FLOP/byte |
| Ridge point | 31.25 FLOP/byte |
| Bound | Compute-bound (170.7 >> 31.25) |
| Attainable performance | 10,000 GFLOP/s (hits compute ceiling) |

**Architectural recommendation:** Since the bottleneck is compute, the most effective improvement is adding more FMA (Fused Multiply-Add) units or wider SIMD execution lanes. Increasing memory bandwidth would have no effect because the processor cannot consume data fast enough to make bandwidth the bottleneck.

---

## Task 3: Kernel B — Vector addition, length 4,194,304

**Problem:** Add two FP32 vectors A and B element-wise to produce output vector C. Each element: C[i] = A[i] + B[i].

### (a) FLOPs calculation

One addition per element.

```
FLOPs = 4,194,304  (~4.2 MFLOP)
```

### (b) Bytes transferred (no cache reuse, all from DRAM)

```
Vector A:  4,194,304 x 4 bytes = 16,777,216 bytes
Vector B:  4,194,304 x 4 bytes = 16,777,216 bytes
Vector C:  4,194,304 x 4 bytes = 16,777,216 bytes  (written back to DRAM)

Total bytes = 3 x 16,777,216 = 50,331,648 bytes (~50 MB)
```

### (c) Arithmetic intensity

```
AI = FLOPs / bytes = 4,194,304 / 50,331,648 = 0.083 FLOP/byte
```

### (d) Analysis

| Property | Value |
|---|---|
| Arithmetic intensity | 0.083 FLOP/byte |
| Ridge point | 31.25 FLOP/byte |
| Bound | Memory-bound (0.083 << 31.25) |
| Attainable performance | AI x Bpeak = 0.083 x 320 = 26.7 GFLOP/s |

**Architectural recommendation:** Since the bottleneck is memory bandwidth, the most effective improvement is higher-bandwidth memory such as HBM (High Bandwidth Memory) in place of standard DRAM. HBM can provide 1-2 TB/s bandwidth, which would proportionally increase attainable performance. Adding more compute units would have no effect because the compute units are already idle most of the time waiting for data to arrive.

---

## Summary table

| Kernel | FLOPs | Bytes | AI (FLOP/byte) | Bound | Attainable (GFLOP/s) |
|---|---|---|---|---|---|
| Dense GEMM 1024x1024 | 2,147,483,648 | 12,582,912 | 170.7 | Compute | 10,000 |
| Vector addition 4M | 4,194,304 | 50,331,648 | 0.083 | Memory | 26.7 |

Ridge point: **31.25 FLOP/byte** at **10,000 GFLOP/s**
