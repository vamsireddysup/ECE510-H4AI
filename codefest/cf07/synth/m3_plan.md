# M3 Synthesis Plan

## What was learned from CF07 fallback (Option B)

The CF07 synthesis used crossbar_mac.sv (4x4, binary weights) as the fallback target. The generic synthesis produced 4318 cells dominated by XOR and AND chains -- expected for signed multiply-accumulate logic. Technology mapping to sky130 HD failed because yowasp-yosys lacks the ABC binary. This confirmed that a proper yosys installation with ABC and pyosys support, or full OpenLane Docker, is required for M3.

## M3 plan

Target date for systolic array synthesis: May 22, 2026 (two days before M3 deadline).

For M3 the actual synthesis target is `systolic_array.sv` with SIZE=4, D_HEAD=4 for the first run. Expected differences from the CF07 fallback: the systolic array has 16 PEs each containing an FP4 multiplier (256-entry LUT) and FP32 accumulator, so cell count will be 50-100x larger than crossbar_mac. The critical path will likely be inside the FP32 accumulator chain rather than the binary weight adder tree.

The lesson from CF07: complete the OpenLane Docker setup before M3 rather than during it.
