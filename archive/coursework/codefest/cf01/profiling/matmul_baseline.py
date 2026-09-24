import torch
import time

# Fixed size matching a single attention head: seq_len=64, d_k=64
seq_len = 64
d_k = 64
runs = 1000

Q = torch.randn(seq_len, d_k)
K = torch.randn(seq_len, d_k)

# Warmup
for _ in range(10):
    _ = torch.matmul(Q, K.transpose(0, 1))

# Benchmark
start = time.perf_counter()
for _ in range(runs):
    out = torch.matmul(Q, K.transpose(0, 1))
end = time.perf_counter()

avg_us = (end - start) / runs * 1e6
flops = 2 * seq_len * seq_len * d_k
intensity = flops / ((seq_len * d_k * 2 + seq_len * seq_len) * 4)

print(f"Matrix size:          {seq_len}x{d_k} @ {d_k}x{seq_len}")
print(f"Avg latency:          {avg_us:.2f} us")
print(f"FLOPs per call:       {flops:,}")
print(f"Throughput:           {flops / (avg_us * 1e-6) / 1e9:.2f} GFLOP/s")
print(f"Arithmetic intensity: {intensity:.2f} FLOP/byte")
