# M3 Synthesis Plan

## What was learned from CF07 (Option B)

CF07 used crossbar_mac.sv as the fallback target. Key findings:

- Generic synthesis: 4318 cells, 34-stage critical path in the carry chain
- Technology mapping failed because yowasp-yosys lacks ABC
- No timing slack obtainable without sky130-mapped cells

This confirmed that a native yosys build with ABC is required for M3.

## M3 plan

Target: `systolic_array.sv` with SIZE=4, D_HEAD=4, sky130 HD at 250 MHz.

Expected differences from the CF07 fallback: the systolic array contains 16
PEs each with a 256-entry FP4 LUT multiplier and a 32-bit FP32 accumulator,
so cell count will be 50-100× larger than crossbar_mac. The critical path
will be inside the FP32 accumulator chain rather than the binary adder tree.

Target date for systolic array synthesis: before M3 deadline (May 24, 2026).
