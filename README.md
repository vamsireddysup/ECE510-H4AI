# ECE 510 -- Hardware for AI/ML -- Spring 2026
# FP4 QK^T Accelerator Chiplet

**Student:** Vamsidhar Reddy Eraganeni
**Course:** ECE 510, Portland State University, Spring 2026

## Project

Custom co-processor chiplet accelerating the QK^T attention score computation
using FP4 E2M1 multiply and FP32 accumulate on a systolic array, targeting
Sky130 HD at 250 MHz.

## M4 Final Submission

The complete M4 deliverable package is in **[project/m4/](project/m4/README.md)**.

Key results:
- 16×16 FP4 systolic array, AXI4-Lite + AXI4-Stream interfaces
- Co-simulation: 16/16 PASS end-to-end
- Synthesis: 328,554 µm² (SIZE=4), 60.2 mW, WNS=-2.30 ns
- Speedup vs CPU: **2.19× at 158 MHz** (achievable), 3.45× projected at 250 MHz
- Design justification report: [project/m4/report/design_justification.pdf](project/m4/report/design_justification.pdf)

## Milestone structure

| Milestone | Location | Status |
|---|---|---|
| M1 | project/m1/ | Done |
| M2 | project/m2/ | Done |
| M3 | project/m3/ | Done |
| M4 | project/m4/ | Done |

## Repository

GitHub: https://github.com/vamsireddysup/ECE510-H4AI
