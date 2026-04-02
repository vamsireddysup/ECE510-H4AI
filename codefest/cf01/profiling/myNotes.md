# CLLM — ResNet-18 profiling: concepts and walkthrough

These are personal study notes explaining what was done in CLLM and why.

---

## What the task was

Profile ResNet-18 using torchinfo to identify the most compute-intensive layers, then compute arithmetic intensity for the heaviest layer — the same analysis we did by hand in CMAN but on a real model at scale.

---

## What torchinfo does

torchinfo inspects a PyTorch model's architecture without running a forward pass. For each layer it reports input shape, output shape, parameter count, and Mult-Adds. It answers the question: where does the compute actually go?

```python
from torchvision.models import resnet18
from torchinfo import summary

model = resnet18(weights=None)
result = summary(model, input_size=(1, 3, 224, 224),
                 col_names=["input_size", "output_size", "num_params", "mult_adds"])
```

The key columns:
- `Param #` — how many weights this layer has (memory cost)
- `Mult-Adds` — how many MAC operations this layer performs (compute cost)

---

## Why so many layers tie at 115,605,504 MACs

ResNet-18 doubles channels as spatial resolution halves:

| Stage | Channels | Feature map | MACs per conv |
|-------|----------|-------------|---------------|
| Layer 1 | 64 | 56×56 | 115,605,504 |
| Layer 2 | 128 | 28×28 | 115,605,504 |
| Layer 3 | 256 | 14×14 | 115,605,504 |
| Layer 4 | 512 | 7×7 | 115,605,504 |

This is deliberate — the architecture keeps compute balanced across stages. When MACs tie, rank by parameter count.

---

## Arithmetic intensity — Conv2d 3-42

Layer: 512 channels in → 512 channels out, 3×3 kernel, 7×7 spatial, no weight reuse.

```
FLOPs        = 2 × 115,605,504       = 231,211,008

Weight bytes = 2,359,296 × 4         = 9,437,184 bytes
Input bytes  = 512 × 7 × 7 × 4      = 100,352 bytes
Output bytes = 512 × 7 × 7 × 4      = 100,352 bytes
Total memory = 9,437,184 + 200,704   = 9,637,888 bytes

Arithmetic intensity = 231,211,008 / 9,637,888 = 24 FLOP/byte
```

---

## Key takeaway — CMAN vs CLLM compared

| Network | Arithmetic intensity | Bound |
|---------|---------------------|-------|
| FC [784→256→128→10] | 0.5 FLOP/byte | Memory-bound |
| ResNet-18 Conv2d | 24 FLOP/byte | Compute-bound |

Convolutional layers do 48× more useful work per byte loaded from memory. This is why conv layers and matrix multiplies are worth accelerating in custom hardware — they sit above the memory bandwidth ceiling on the roofline and can actually use the compute you build.

---

## Files produced

| File | Contents |
|------|----------|
| `profile_resnet18.py` | Script that runs torchinfo and saves output |
| `resnet18_profile.txt` | Full torchinfo layer-by-layer output |
| `resnet18_analysis.md` | Top-5 MAC table + arithmetic intensity calculation |
