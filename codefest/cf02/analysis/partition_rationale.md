# HW/SW partition proposal

## (a) Which kernel to accelerate and why

I am accelerating the QK^T matrix multiply inside `ScaleDotProductAttention.forward()`.
At T=512 the arithmetic intensity is 25.60 FLOP/byte, well above my CPU ridge
point of 8.28 FLOP/byte -- so the kernel is compute-bound. A systolic array with
dedicated MAC units directly attacks that bottleneck. QK^T also scales as T^2
while every other operation scales linearly with T, meaning it becomes
increasingly dominant at longer sequences. The measured latency ratio of 5.36x
from T=128 to T=512 (above the 4x expected from linear scaling) confirms this
quadratic growth is already visible at my target operating point.

## (b) What stays in software

The linear projections (W_Q, W_K, W_V, W_O), softmax, AV multiply, and
feed-forward layers stay on the host CPU. Softmax requires exponentials and
row-wise normalization that are expensive in custom silicon. The AV multiply has
the same intensity as QK^T but the softmax in between breaks clean pipelining.
The projections are handled efficiently by PyTorch's BLAS routines.

## (c) Interface bandwidth requirement

At 32 GFLOP/s with QK^T costing 268,435,456 FLOPs at T=512, one forward pass
takes 8.39 ms. The chiplet receives Q and K (2 MB total) and returns the score
matrix (8 MB), requiring 10 MB / 8.39 ms = 1.19 GB/s sustained bandwidth.
AXI4-Stream at 64-bit / 250 MHz delivers 2 GB/s, which is above 1.19 GB/s.
The interface is not the bottleneck.

## (d) Bound classification

QK^T is compute-bound on the CPU at all three tested sizes (AI 16.00 to 25.60
vs ridge 8.28). The chiplet keeps it compute-bound -- its ridge point is
32 / 256 = 0.125 FLOP/byte, and QK^T AI of 25.60 sits well above that. The
256 GB/s on-chip SRAM bandwidth is high enough that the systolic array is never
starved for data. Performance is limited by the compute ceiling, which is exactly
what the design targets.
