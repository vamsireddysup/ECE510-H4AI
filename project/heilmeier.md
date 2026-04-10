# Heilmeier questions

## Q1: What are you trying to do?

Transformer models compute self-attention by multiplying a Query matrix (Q)
against a transposed Key matrix (K^T) for every layer and every attention head.
This QK^T operation is a dense matrix multiplication whose cost scales
quadratically with sequence length, making it increasingly dominant as sequences
get longer. The goal is to build a custom silicon chiplet that executes this
matrix multiplication in hardware, faster than a general-purpose CPU.

## Q2: How is it done today and what are the limits?

Today, transformer inference runs on general-purpose CPUs using PyTorch with
optimized BLAS libraries that exploit AVX-512 SIMD instructions and multi-core
parallelism. I benchmarked this on an Intel i5-1145G7 CPU.

The measured results at T=512 tell the story directly. The CPU achieves 11.36 GFLOP/s for QK^T against a theoretical peak of 563.2 GFLOP/s
-- that is about 2% utilization. The median latency for one MultiHeadAttention 
forward pass is 23.64 ms. cProfile shows `ScaleDotProductAttention.forward()` accounting for
53% of total attention computation time. The arithmetic intensity of QK^T is
25.60 FLOP/byte, well above the CPU ridge point of 8.28 FLOP/byte, confirming
the kernel is compute-bound. The CPU simply does not have enough dedicated
multiply units to use its memory bandwidth efficiently for this operation.

The latency scaling makes the problem clearer: going from T=128 to T=512 (4x
longer), latency grew 5.36x instead of the 4x expected from linear scaling.
QK^T's quadratic cost is already visible at T=512 and gets worse at longer
sequences.

## Q3: What is new in your approach and why will it succeed?

The chiplet replaces the general-purpose CPU pipeline with a dedicated systolic
array -- a grid of processing elements each doing one multiply-accumulate per
clock cycle -- wired so data flows between neighbors without returning to DRAM
between operations. This eliminates fetch-decode-execute overhead and puts nearly
all silicon area toward the one operation that matters.

The approach is grounded in the measured roofline analysis. QK^T has an
arithmetic intensity of 25.60 FLOP/byte at T=512, which is 3.1x above the CPU
ridge point of 8.28 FLOP/byte. The bottleneck is compute, not memory bandwidth,
so adding more multipliers directly helps. The chiplet targets 32 GFLOP/s with
256 GB/s on-chip SRAM bandwidth, giving a chiplet ridge point of 0.125 FLOP/byte.
Since QK^T AI of 25.60 is well above that, the chiplet is also compute-bound and
its 32 GFLOP/s compute ceiling is the performance limit -- a 2.75x improvement
over the measured CPU throughput of 11.63 GFLOP/s. The interface uses AXI4-Lite
for control and AXI4-Stream for data, which at 64-bit / 250 MHz delivers 2 GB/s,
comfortably above the required 1.19 GB/s so the interface is not the bottleneck.
