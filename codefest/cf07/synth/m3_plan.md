# M3 Synthesis Plan

## What was learned from CF07 fallback (Option B)

CF07 synthesis used crossbar_mac.sv as the fallback. The generic synthesis
produced 4318 cells dominated by XOR and AND chains. Technology mapping to
sky130 HD was not completed in CF07 because yowasp-yosys lacks ABC.

## M3 outcome

M3 synthesis was completed successfully using Yosys 0.44 + ABC with sky130 HD
(tt_025C_1v80). The actual systolic array (SIZE=4, D_HEAD=4) produced:

- Mapped cells: 25,378
- Chip area: 188,961 µm²
- WNS (setup): -17.26 ns at 250 MHz target
- Hold: MET (+0.31 ns)
- Critical path: 21.13 ns -- FP32 accumulator chain dominates

The 17.26 ns setup violation means timing closure at 250 MHz requires
pipelining the FP32 accumulator. The maximum achievable frequency with
current RTL is approximately 46 MHz (1/21.5 ns). For M4 the plan is to
pipeline `fp32_add.sv` into 3 stages, which should enable 250 MHz operation.
The hold timing is clean at all frequencies so no hold fixing is needed.
