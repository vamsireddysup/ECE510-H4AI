# CMAN — Workload Accounting

**Network:** [784 → 256 → 128 → 10] | Batch size: 1 | Precision: FP32 | No biases
<img width="1039" height="591" alt="Screenshot from 2026-04-02 05-23-15" src="https://github.com/user-attachments/assets/ea41f4bd-868a-4da7-95d7-3eb871c1ed4c" />

---

## (a) Per-layer MAC table

| Layer | Formula | MACs |
|-------|---------|------|
| Layer 1 (784 → 256) | 784 × 256 | 200,704 |
| Layer 2 (256 → 128) | 256 × 128 | 32,768 |
| Layer 3 (128 → 10) | 128 × 10 | 1,280 |

## (b) Total MACs

```
200,704 + 32,768 + 1,280 = 234,752 MACs
```

## (c) Total parameters

```
784 × 256 + 256 × 128 + 128 × 10 = 234,752 parameters
```

## (d) Weight memory

```
234,752 × 4 bytes = 939,008 bytes
```

## (e) Activation memory

```
Activations: 784 + 256 + 128 + 10 = 1,178 values
1,178 × 4 bytes = 4,712 bytes
```

## (f) Arithmetic intensity

```
FLOPs = 2 × 234,752 = 469,504
Memory = 939,008 + 4,712 = 943,720 bytes

Arithmetic Intensity = 469,504 / 943,720 = 0.497 FLOP/byte
```

This workload is memory-bound — less than 0.5 FLOPs are performed per byte loaded from memory.
