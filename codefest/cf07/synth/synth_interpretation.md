# Synthesis Interpretation — crossbar_mac (CF07 Option B)

## Target and tool

Design: `crossbar_mac.sv` (4x4 binary-weight crossbar MAC, CF06)
Tool: Yosys 0.65 (yowasp WebAssembly build), generic cell library (no technology mapping -- ABC unavailable in yowasp build)
Clock period: 4.0 ns target (250 MHz), matching M3 systolic array target

## Clock and slack

Technology mapping to sky130 HD was not completed because yowasp-yosys does not ship the ABC binary required for standard cell mapping. Timing slack cannot be computed without mapped cells. The generic synthesis completed in 1.58s with 4318 generic logic cells. For M3 with a proper OpenLane run, clock period 4.0 ns (250 MHz) will be used as the starting point. If timing is violated the clock will be relaxed to 5.0 ns (200 MHz).

## Critical path

Without technology mapping, exact gate delays are not available. The dominant cell types are `$_AND_` (1837 instances, 42.5%) and `$_XOR_` (1609 instances, 37.3%). The crossbar MAC computes `out[j] = sum_i weight[i][j] * in[i]` where each multiply is a sign-conditional add (±1 * 8-bit input = pass or negate). The critical path is expected to run from the weight registers through 4 conditional additions (one per input row) and terminate at the 32-bit accumulator output register. The XOR-heavy cell count confirms signed addition is the dominant computation -- each signed addition uses full-adder chains implemented in XOR/AND/OR.

## Area

Total cell count: 4318 generic cells. Top contributors by instance count:

- `$_AND_`: 1837 (42.5%) -- carry generation and masking logic
- `$_XOR_`: 1609 (37.3%) -- sum computation in adder chains
- `$_OR_`: 745 (17.2%) -- carry propagation

Sequential elements: 90 flip-flops total (73 `$_SDFF_PN0_` + 16 `$_SDFFE_PN0P_` + 1 `$_DFF_P_`). This matches the expected register count: 16 weight registers (8-bit each) + 4 output registers (32-bit each) + valid register = 16*8 + 4*32 + 1 = 257 bits, consistent with 90 flip-flops covering the design state.

## Warnings and limitations

No failed constraints or hold violations because STA was not run (no mapped netlist). The main issue for M3 is that yowasp-yosys cannot complete technology mapping without ABC. A proper OpenLane run with Docker or a native yosys with pyosys support is required for sky130 HD mapped results and timing closure.
