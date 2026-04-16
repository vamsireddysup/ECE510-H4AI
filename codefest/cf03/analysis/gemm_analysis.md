# GEMM analysis -- naive vs tiled on NVIDIA Tesla T4

## Hardware
- GPU: NVIDIA Tesla T4
- Peak FP32 compute: 8,100 GFLOP/s
- Peak memory bandwidth: 300 GB/s
- Ridge point: 27 FLOP/byte

## Measured results

| Kernel | Time (ms) | GFLOP/s | AI (FLOP/byte) | DRAM reads |
|---|---|---|---|---|
| Naive | 5.43 | 395 | 0.25 | 208 MB |
| Tiled (T=8) | 5.13 | 418 | 170.67 | 168 MB |

## (a) Why the naive kernel is memory-bound

In the naive kernel each thread computes one output element C[i][j] by loading
an entire row of A and an entire column of B directly from global memory. There
is no data reuse between threads -- element B[k][j] is loaded independently by
every thread in the same column. This gives an arithmetic intensity of 0.25
FLOP/byte, far below the T4 ridge point of 27 FLOP/byte. Nsight confirmed 208 MB
of DRAM reads and 62% SM throughput, meaning the SMs spend most of their time
waiting for memory rather than doing arithmetic.

## (b) How tiling reduces DRAM traffic

Tiling loads a T x T block of A and a T x T block of B into shared memory once,
then all T^2 threads in the block compute their partial dot products using that
shared data without going back to DRAM. Each tile element is reused T times
before the next tile is fetched. This reduces DRAM traffic from 2 x N^3 bytes
(naive) to 2 x N^2 bytes (tiled), a factor of N = 1024 reduction theoretically.
Nsight confirmed DRAM reads dropped from 208 MB to 168 MB, and L1 bandwidth
dropped from 467 GB/s to 117 GB/s, showing the shared memory is absorbing most
data movement.

## (c) Whether tiling achieved the expected improvement

The tiled kernel achieved only a marginal speedup -- 418 GFLOP/s vs 395 GFLOP/s,
about 1.06x. The expected improvement from DRAM traffic analysis was 32x
(for N=32) but at N=1024 the T4's L2 cache already captures many of the naive
kernel's repeated B accesses, which reduces the practical advantage of tiling.
The remaining bottleneck is low GPU occupancy from the small tile size T=8,
which gives only 64 threads per block. This under-utilizes the T4's warp
schedulers and limits parallelism. A larger tile (T=16 or T=32) would improve
occupancy and push the kernel closer to the compute ceiling.
EOF
print("Written gemm_analysis.md")
