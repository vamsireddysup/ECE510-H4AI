# Software baseline benchmark

## Platform

| Item | Value |
|---|---|
| CPU | Intel Core i5-1145G7 @ 2.60GHz (Tiger Lake, 4 cores, 8 threads) |
| Max turbo | 4.40 GHz |
| SIMD | AVX-512 with FMA |
| Memory | LPDDR4x-4267 dual channel |
| OS | Ubuntu 24.04 LTS |
| Python | 3.12.3 |
| PyTorch | 2.11.0+cu130 |
| Device | CPU (no GPU) |
| Batch size | 1 (single sequence inference) |

Reference implementation: hyunwoongko/transformer (Apache 2.0)
https://github.com/hyunwoongko/transformer

## What was benchmarked

`MultiHeadAttention.forward()` with self-attention (Q=K=V=input), using:
- d_model = 512, n_heads = 8, head dimension = 64
- Sequence lengths T = 128, 256, 512
- 3 warmup runs followed by 10 timed runs, median reported

The target kernel inside this is `ScaleDotProductAttention.forward()`,
specifically `score = (q @ k_t) / math.sqrt(d_tensor)` -- the QK^T matmul.

## Execution time (median over 10 runs)

| T | Median latency | Ratio vs T=128 |
|---|---|---|
| 128 | ~4-7 ms  | 1.00x (varies with system load) |
| 256 | ~8-10 ms | ~2x |
| 512 | 23.64 ms | ~5x |

Latency grows faster than 2x per doubling of T, consistent with QK^T T^2 scaling.

## Throughput

| T | QK^T GFLOP/s | % of CPU peak (563.2) |
|---|---|---|
| 128 | ~2.4-3.9 | ~0.7% |
| 256 | ~6.5-8.0 | ~1.4% |
| 512 | 11.36    | 2.0%  |

The CPU achieves roughly 2% of theoretical peak for this operation. The low
utilization is expected -- the CPU has no dedicated matrix multiply units and
routes every MAC through the general AVX-512 FMA pipeline.

## Memory usage

| T | Total tensor memory |
|---|---|
| 128 | 2.88 MB |
| 256 | 6.82 MB |
| 512 | 17.83 MB |

Largest tensor: score matrix [B, h, T, T] = 8.39 MB at T=512. This is the
T^2 term -- it grows 4x each time T doubles while all other tensors grow 2x.

## Dominant kernel identification

cProfile over 10 runs at T=512:

```
scale_dot_product_attention.forward   cumtime 0.113s  (11.3 ms/run, 53%)
torch._C._nn.linear                   cumtime 0.093s  ( 9.3 ms/run, 44%)
softmax                               cumtime 0.029s  ( 2.9 ms/run, 14%)
```

`ScaleDotProductAttention.forward()` is the largest single function by
cumulative time at T=512. At T>=2048 it analytically dominates all other
operations due to T^2 scaling vs linear T scaling of projections.

## M4 comparison point

The M4 speedup will be measured against the T=512 baseline:
- Latency: 23.64 ms per forward pass
- QK^T throughput: 11.36 GFLOP/s
- Platform: Intel i5-1145G7, Ubuntu 24.04, PyTorch 2.11.0, batch=1
- Note: T=128 timing varies across runs (4-7 ms range) due to OS scheduling 
overhead dominating at short execution times. T=512 is the stable reference point.
