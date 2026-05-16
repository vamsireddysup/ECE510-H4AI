# Project Scope Assessment — ECE 510 Spring 2026

**Updated:** May 2026 (post CF07 synthesis)

## Project: FP4 QK^T Accelerator Chiplet

### Original scope

16x16 systolic array computing QK^T attention scores using FP4 E2M1 multiply and FP32 accumulate. Target: Sky130 HD at 250 MHz. N=512, d_head=64, microscaling (S_Q per row, S_K per col).

### Current status

M2 complete and verified:
- FP4 multiplier: 256/256 LUT entries correct
- PE D_HEAD=64: 4/4 PASS including max value 2304.0
- Systolic array SIZE=16: 256/256 elements correct
- Microscaling dequantization: MAE=1.23e-07 vs Python golden reference
- All 11 RTL modules lint clean

### Scope adjustment based on CF07 synthesis

The CF07 synthesis of crossbar_mac (4x4, binary weights) produced 4318 generic cells. The systolic array for M3 (SIZE=4, D_HEAD=4) will be 10-20x larger due to FP4 LUT multipliers and FP32 accumulators. A SIZE=16 full array is likely too large for meaningful synthesis results within M3 timeline -- it would contain 256 PEs each with a 256-entry LUT, totaling approximately 50,000-100,000 cells.

### Adjusted scope for M3

Synthesize SIZE=4, D_HEAD=4 first. If timing closes at 250 MHz, attempt SIZE=8. Report area and timing for the SIZE=4 array and extrapolate to SIZE=16 using linear scaling (area scales as SIZE²).

The core architecture and verification are solid. The scope reduction is only in the synthesis target size, not in the design itself.
