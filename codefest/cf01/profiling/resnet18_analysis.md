# ResNet-18 Profiling Analysis

**Model:** ResNet-18 | **Input:** 3×224×224 | **Batch size:** 1 | **Precision:** FP32

---

## Top 5 MAC-intensive layers

| Rank | Layer | Input Shape | Output Shape | Params | Mult-Adds |
|------|-------|-------------|--------------|--------|-----------|
| 1 | Conv2d 3-42 | [1, 512, 7, 7] | [1, 512, 7, 7] | 2,359,296 | 115,605,504 |
| 2 | Conv2d 3-46 | [1, 512, 7, 7] | [1, 512, 7, 7] | 2,359,296 | 115,605,504 |
| 3 | Conv2d 3-49 | [1, 512, 7, 7] | [1, 512, 7, 7] | 2,359,296 | 115,605,504 |
| 4 | Conv2d 3-29 | [1, 256, 14, 14] | [1, 256, 14, 14] | 589,824 | 115,605,504 |
| 5 | Conv2d 3-33 | [1, 256, 14, 14] | [1, 256, 14, 14] | 589,824 | 115,605,504 |

All five layers share the same Mult-Adds count. Ranking within the tie is by parameter count (descending).

---

## Arithmetic intensity — Conv2d 3-42

Most MAC-intensive layer: Conv2d 3-42, 3×3 kernel, 512 input channels → 512 output channels, spatial 7×7.

**FLOPs:**
```
2 × 115,605,504 = 231,211,008 FLOPs
```

**Weight memory (no reuse, all from DRAM):**
```
2,359,296 params × 4 bytes = 9,437,184 bytes
```

**Activation memory:**
```
Input:  1 × 512 × 7 × 7 = 25,088 values → 25,088 × 4 = 100,352 bytes
Output: 1 × 512 × 7 × 7 = 25,088 values → 25,088 × 4 = 100,352 bytes
Total activation bytes = 200,704 bytes
```

**Total memory traffic:**
```
9,437,184 + 200,704 = 9,637,888 bytes
```

**Arithmetic intensity:**
```
231,211,008 / 9,637,888 = 23.99 FLOP/byte ≈ 24 FLOP/byte
```

This is significantly higher than the fully connected network in CMAN (0.497 FLOP/byte), confirming that convolutional layers are far more compute-bound and better candidates for hardware acceleration.
