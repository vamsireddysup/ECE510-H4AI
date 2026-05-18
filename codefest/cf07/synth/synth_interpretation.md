# Synthesis Interpretation — crossbar_mac (CF07 Option B)

## Target and tool

Design: `crossbar_mac.sv` (4x4 binary-weight crossbar MAC, CF06)
Tool: Yosys 0.65 (yowasp WebAssembly build), generic cell library
Clock period: 4.0 ns target (250 MHz)

Note: CF07 used the crossbar_mac fallback (Option B) because the systolic array
synthesis toolchain was not yet resolved. M3 subsequently completed full sky130 HD
synthesis on the actual systolic array -- see `project/m3/reports/`.

## Clock and slack

Generic synthesis only -- no technology mapping to sky130 HD was completed for
this design. ABC was unavailable in the yowasp build. No timing slack is reported.
For actual timing numbers see the M3 synthesis results: WNS = -17.26 ns,
TNS = -26,731 ns at 250 MHz target on the systolic array.

## Critical path

Without technology mapping, exact gate delays are not available. The dominant
generic cell types are `$_AND_` (1837, 42.5%) and `$_XOR_` (1609, 37.3%).
The crossbar MAC computes `out[j] = sum_i weight[i][j] * in[i]` where each
multiply is sign-conditional (±1 × 8-bit input). The critical path runs from
weight registers through 4 conditional additions terminating at the 32-bit
output register. The XOR-heavy count confirms signed addition dominates --
full-adder chains implemented in XOR/AND/OR.

## Area

Total generic cells: 4318. Top three contributors by instance count:
`$_AND_` 1837 (42.5%), `$_XOR_` 1609 (37.3%), `$_OR_` 745 (17.2%).
Sequential elements: 90 flip-flops -- 16 weight registers (8-bit) +
4 output registers (32-bit) + 1 valid register = 257 bits total, consistent
with 90 flip-flops.

## Warnings and limitations

No failed constraints because STA was not run (no mapped netlist). The
crossbar_mac is a much simpler design than the FP4 systolic array -- binary
weights eliminate the FP4 multiplier LUT entirely. For M3 comparison: the
systolic array (SIZE=4, D_HEAD=4) mapped to 25,378 sky130 HD cells at
188,961 µm², roughly 6× the cell count of this crossbar design.
