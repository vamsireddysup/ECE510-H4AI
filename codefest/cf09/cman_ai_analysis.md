# CF09 -- CMAN: Arithmetic Intensity and Roofline Analysis

## Task 1: Dominant kernel

**Kernel:** QK^T matrix multiplication (attention score computation)

**Dimensions:**
- Q matrix: (N, d_head) = (512, 64), FP4 E2M1 input
- K matrix: (N, d_head) = (512, 64), FP4 E2M1 input
- Output: (N, N) = (512, 512), FP32

**Hardware implementation:** 4×4 systolic array, output-stationary dataflow, tiled across the full 512×512 output space. Each PE computes FP4 multiply + FP32 accumulate.

---

## Task 2: Total FLOPs for one invocation

Each output element C[i][j] = sum over d of Q[i][d] × K[j][d] requires d_head multiply-accumulate operations. Each MAC = 2 FLOPs.

```
FLOPs = 2 × N × N × d_head
      = 2 × 512 × 512 × 64
      = 33,554,432 FLOPs
      ≈ 33.55 MFLOP
```

---

## Task 3: Bytes transferred -- two bounds

### Lower bound (no data reuse)

Every output element loads its required Q row and K row fresh from off-chip memory. No on-chip caching.

```
Bytes_Q = N × N × d_head × 0.5     (FP4 = 0.5 bytes/element, Q row loaded N times)
        = 512 × 512 × 64 × 0.5
        = 8,388,608 bytes = 8.0 MB

Bytes_K = N × N × d_head × 0.5     (K row loaded N times)
        = 512 × 512 × 64 × 0.5
        = 8,388,608 bytes = 8.0 MB

Bytes_out = N × N × 4              (FP32 output, written once)
          = 512 × 512 × 4
          = 1,048,576 bytes = 1.0 MB

Total (no reuse) = 8.0 + 8.0 + 1.0 = 17.0 MB = 17,825,792 bytes
```

### Upper bound (perfect on-chip reuse)

Output-stationary dataflow: each row of Q and each row of K is loaded exactly once. The systolic array tiles keep data on-chip and reuse it across all accumulations.

```
Bytes_Q = N × d_head × 0.5         (each row loaded once)
        = 512 × 64 × 0.5
        = 16,384 bytes = 16 KB

Bytes_K = N × d_head × 0.5         (each row loaded once)
        = 512 × 64 × 0.5
        = 16,384 bytes = 16 KB

Bytes_out = N × N × 4              (FP32 output, written once)
          = 1,048,576 bytes = 1.0 MB

Total (full reuse) = 16,384 + 16,384 + 1,048,576 = 1,081,344 bytes ≈ 1.03 MB
```

**Note:** FP4 encoding reduces input traffic from 16 MB (FP32 equivalent) to 32 KB. Output traffic (1 MB FP32) dominates at full reuse, which is why the upper bound AI is relatively high.

---

## Task 4: Arithmetic intensity for both bounds

**Formula:** AI = FLOPs / Bytes

```
AI (lower bound, no reuse)   = 33,554,432 / 17,825,792 = 1.88 FLOP/byte

AI (upper bound, full reuse) = 33,554,432 / 1,081,344  = 31.03 FLOP/byte
```

**Platform specs for roofline:**

| Platform | Peak compute | Memory BW | Ridge point |
|---|---|---|---|
| CPU i5-1145G7 | 11.36 GFLOP/s | 51.2 GB/s | 0.22 FLOP/byte |
| Chiplet sky130 SIZE=4 | 10.25 GOPS | 5.12 GB/s | 2.0 FLOP/byte |

**Kernel region analysis:**

At AI lower bound (1.88 FLOP/byte):
- CPU: compute-bound (1.88 > 0.22 ridge)
- Chiplet: memory-bound (1.88 < 2.0 ridge) -- AXI4-Stream bandwidth is the bottleneck

At AI upper bound (31.03 FLOP/byte):
- CPU: compute-bound (31.03 >> 0.22 ridge)
- Chiplet: compute-bound (31.03 >> 2.0 ridge) -- systolic array utilization is the bottleneck

The roofline sketch is saved as `codefest/cf09/cman_roofline_sketch.png`.

---

## Task 5: Bottleneck identification

**Current bottleneck:** Compute units (not memory bandwidth).

The systolic array achieves near full-reuse (AI ≈ 31.03), placing the design well into the compute-bound region. Post-route STA shows the critical path is 5.05 ns, giving a suggested frequency of 80.06 MHz. The compute ceiling at this frequency is 10.25 GOPS for SIZE=4, but the measured effective throughput is only 1.07 GOPS because SIZE=4 covers only (4/512)² = 0.006% of the full 512×512 output space per tile -- the dominant overhead is tiling control cycles, not memory bandwidth.

**Single highest-leverage change:** Increase SIZE from 4 to 16. This gives 16× more PEs (256 vs 16), increases peak GOPS from 10.25 to 163.8 at the same 80 MHz, and reduces tiling overhead by 16×. The critical path does not change with SIZE scaling because the PE pipeline depth is fixed. Area scales as SIZE² (from 0.33 mm² to 5.26 mm²) which fits within the sky130 reticle limit.
