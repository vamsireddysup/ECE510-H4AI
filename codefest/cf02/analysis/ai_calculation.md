# Arithmetic intensity calculation — QK^T kernel

## Dominant kernel identification

From the cProfile run across 10 forward passes of `MultiHeadAttention.forward()` at T=512:

```
scale_dot_product_attention.forward   cumtime 0.113s   (11.3 ms per run)
torch._C._nn.linear                   cumtime 0.093s   ( 9.3 ms per run)
softmax                               cumtime 0.029s   ( 2.9 ms per run)
```

The dominant function is `ScaleDotProductAttention.forward()`, accounting for
53% of total attention computation time. The specific line that drives this cost is:

```python
score = (q @ k_t) / math.sqrt(d_tensor)   # QK^T matrix multiply
```

This is the QK^T matrix multiplication. Its cost scales as T^2, which means it
grows faster than every other operation in the attention layer as sequence length
increases. At T=512 it is already the largest single function by cumulative time.

---

## FLOPs calculation

**Formula (from professor appendix):**

```
QK^T FLOPs = 2 x B x h x T^2 x (d/h)
```

Where:
- B = batch size = 1
- h = number of attention heads = 8
- T = sequence length
- d/h = head dimension = 512/8 = 64

**Values substituted at each sequence length:**

```
T=128:  2 x 1 x 8 x 128^2 x 64  =  2 x 8 x 16,384 x 64  =    16,777,216 FLOPs
T=256:  2 x 1 x 8 x 256^2 x 64  =  2 x 8 x 65,536 x 64  =    67,108,864 FLOPs
T=512:  2 x 1 x 8 x 512^2 x 64  =  2 x 8 x 262,144 x 64 =   268,435,456 FLOPs
```

Each time T doubles, QK^T FLOPs multiply by 4 (because T^2). This is the
quadratic scaling that makes QK^T the target for hardware acceleration.

---

## Bytes transferred (no cache reuse, all from DRAM)

The QK^T operation reads Q, reads K, and writes the output score matrix.
Each number is FP32 = 4 bytes.

**At T=512:**

```
Q matrix  [B, h, T, d/h] = 1 x 8 x 512 x 64 x 4 bytes =  1,048,576 bytes
K matrix  [B, h, T, d/h] = 1 x 8 x 512 x 64 x 4 bytes =  1,048,576 bytes
Output    [B, h, T, T  ] = 1 x 8 x 512 x 512 x 4 bytes = 8,388,608 bytes

Total bytes = 1,048,576 + 1,048,576 + 8,388,608 = 10,485,760 bytes
```

**At T=256:**

```
Q matrix  = 1 x 8 x 256 x 64 x 4 =   524,288 bytes
K matrix  = 1 x 8 x 256 x 64 x 4 =   524,288 bytes
Output    = 1 x 8 x 256 x 256 x 4 = 2,097,152 bytes

Total bytes = 524,288 + 524,288 + 2,097,152 = 3,145,728 bytes
```

**At T=128:**

```
Q matrix  = 1 x 8 x 128 x 64 x 4 =   262,144 bytes
K matrix  = 1 x 8 x 128 x 64 x 4 =   262,144 bytes
Output    = 1 x 8 x 128 x 128 x 4 =   524,288 bytes

Total bytes = 262,144 + 262,144 + 524,288 = 1,048,576 bytes
```

Note: the output matrix grows as T^2 while Q and K grow as T. At T=512 the
output is already 80% of total bytes transferred. This is why arithmetic
intensity increases with T -- more math per byte as the output dominates.

---

## Arithmetic intensity

```
AI = FLOPs / bytes
```

| T   | FLOPs         | Bytes        | AI (FLOP/byte) |
|-----|---------------|--------------|----------------|
| 128 | 16,777,216    | 1,048,576    | 16.00          |
| 256 | 67,108,864    | 3,145,728    | 21.33          |
| 512 | 268,435,456   | 10,485,760   | 25.60          |

---

## Roofline classification

**CPU hardware (Intel i5-1145G7):**
- Peak compute: 563.2 GFLOP/s (AVX-512 FMA, 4 cores @ 4.4 GHz)
- Peak bandwidth: 68.0 GB/s (LPDDR4x-4267 dual channel)
- Ridge point: 563.2 / 68.0 = 8.28 FLOP/byte
- Source: Intel ARK ark.intel.com/content/www/us/en/ark/products/208660

All three sequence lengths produce AI well above the ridge point:

| T   | AI (FLOP/byte) | Ridge (FLOP/byte) | Classification |
|-----|----------------|-------------------|----------------|
| 128 | 16.00          | 8.28              | COMPUTE-BOUND  |
| 256 | 21.33          | 8.28              | COMPUTE-BOUND  |
| 512 | 25.60          | 8.28              | COMPUTE-BOUND  |

The QK^T kernel is compute-bound at all tested sequence lengths. The CPU
cannot do the math fast enough -- it is not waiting for memory. This is exactly
the regime where a custom hardware accelerator with dedicated multipliers helps.
Adding memory bandwidth to the CPU would not improve QK^T performance here.
