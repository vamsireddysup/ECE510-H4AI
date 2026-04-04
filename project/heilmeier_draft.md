# Heilmeier catechism -- project draft

## Q1: What are you trying to do?

Transformer models compute self-attention by multiplying a Query matrix (Q) against a transposed Key matrix (K^T) for every layer and every attention head. This QK^T operation is a dense matrix multiplication whose cost scales quadratically with sequence length (O(N^2 * d)), making it the dominant cost in transformer inference. The goal is to build a custom silicon chiplet that executes this matrix multiplication in hardware, faster and more efficiently than a general-purpose CPU running the same operation in software.

## Q2: How is it done today and what are the limits?

Today, transformer inference runs on general-purpose CPUs using optimized BLAS libraries (OpenBLAS, MKL) that exploit SIMD instructions (AVX-512 on Intel) and multi-core parallelism. The limits are:

- A CPU is a generalist. Its pipeline, branch predictor, and out-of-order execution hardware handle arbitrary workloads, not repeated matrix multiplications. This hardware costs area and power without contributing to matmul throughput.
- On the i5-1145G7 used as the baseline platform, peak FP32 throughput is approximately 563 GFLOPS/s theoretical, but sustained matmul throughput is typically 30-50% of that due to memory hierarchy effects and scheduling overhead.
- There are no dedicated matrix multiply units on this CPU. Every multiply-accumulate goes through the general AVX-512 FMA pipeline.
- At longer sequence lengths (N > 512), the QK^T output matrix (N x N) grows large and stresses the 8 MB L3 cache, increasing DRAM traffic.

## Q3: What is new in your approach and why will it succeed?

The chiplet replaces the general-purpose pipeline with a dedicated systolic array -- a grid of processing elements each containing a multiplier and an accumulator -- wired so that data flows between neighbors without returning to main memory between operations. This eliminates fetch-decode-execute overhead and maximizes the fraction of silicon devoted to multiply-accumulate computation.

The approach is grounded in roofline analysis of QK^T: at sequence length N=512 and head dimension d=64, arithmetic intensity exceeds 128 FLOP/byte, placing the kernel well to the right of the CPU ridge point (~8.3 FLOP/byte). The bottleneck is compute, not memory bandwidth. A design with more parallel multipliers directly attacks the measured bottleneck. The interface uses AXI4-Lite for control and AXI4-Stream for data, chosen to sustain the required data rates without becoming the bottleneck itself.
