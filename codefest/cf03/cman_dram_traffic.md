# CMAN -- DRAM traffic analysis: naive vs tiled matrix multiply

**Hardware:** N = 32, FP32 (4 bytes per element), DRAM bandwidth = 320 GB/s, peak compute = 10 TFLOPS

---

## Task 1: Naive triple loop

For each output element C[i][j], the full row i of A and full column j of B are loaded from DRAM. Each element of B is accessed N times -- once for every row of the output.

```
Total A accesses = N x N x N = 32 x 32 x 32 = 32,768 elements
Total B accesses = N x N x N = 32 x 32 x 32 = 32,768 elements
Total elements   = 2 x N^3
```

```
Total bytes = 2 x N^3 x 4 = 2 x 32,768 x 4 = 262,144 bytes
```

```
FLOPs = 2 x N^3 = 2 x 32,768 = 65,536
AI    = 65,536 / 262,144 = 0.25 FLOP/byte
```

---

## Task 2: Tiled loop (T = 8)

Each T x T tile of A and B is loaded into on-chip memory and reused for all dot products within that tile. Each element of A and B is loaded from DRAM exactly once.

```
A: N x N = 32 x 32 = 1,024 elements = 1,024 x 4 = 4,096 bytes
B: N x N = 32 x 32 = 1,024 elements = 1,024 x 4 = 4,096 bytes
```

```
Tiled traffic = 2 x N^2 x 4 = 2 x 1,024 x 4 = 8,192 bytes
```

```
FLOPs = 65,536  (unchanged)
AI    = 65,536 / 8,192 = 8.0 FLOP/byte
```

---

## Task 3: Traffic ratio

```
Ratio = Naive / Tiled = 262,144 / 8,192 = 32 = N
```

In the naive case each element of B is reloaded from DRAM N times (once per output row), so total traffic scales as N^3, while tiling ensures each element is loaded only once so traffic scales as N^2, and their ratio is N^3 / N^2 = N.

---

## Task 4: Execution times

```
Ridge point = 10,000 GFLOP/s / 320 GB/s = 31.25 FLOP/byte
```

**Naive:**

```
AI   = 0.25 FLOP/byte < 31.25  →  memory-bound
Time = 262,144 / (320 x 10^9) = 0.82 microseconds
Attainable performance = 0.25 x 320 = 80 GFLOP/s
```

**Tiled:**

```
AI   = 8.0 FLOP/byte < 31.25  →  memory-bound (closer to ridge)
Time = 8,192 / (320 x 10^9) = 0.026 microseconds
Attainable performance = 8.0 x 320 = 2,560 GFLOP/s
```

Both cases are memory-bound since AI < 31.25 FLOP/byte. Tiling reduces DRAM traffic by a factor of N = 32, giving a 32x improvement in execution time.
