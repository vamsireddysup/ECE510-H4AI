# Synthesis Interpretation — crossbar_mac (CF07 Option B)

## Target and tool

Design: `crossbar_mac.sv` (4×4 binary-weight crossbar MAC, CF06)
Tool: Yosys 0.65 (yowasp WebAssembly), generic cell library (no sky130 mapping)
Clock period target: 4.0 ns (250 MHz)

## Clock and slack

Technology mapping to sky130 HD was not completed because yowasp-yosys does
not ship the ABC binary. No liberty-based timing analysis was run. The yosys
`ltp` pass reports a longest topological path of 34 gate stages through the
carry-propagate chain of the 32-bit output accumulator. Without mapped cell
delays, exact slack cannot be computed.

## Critical path

The longest path (34 stages) runs from weight register `w10` through a chain
of full-adder stages (`fulladd$1018` through `fulladd$1117`) and a carry
lookahead unit (`synth$1118`) terminating at output register `out0[30]`.
This is the carry-propagate chain of the 32-bit signed accumulator summing
four 8-bit signed inputs. Dominant cell types: `$_AND_` 1837 (42.5%),
`$_XOR_` 1609 (37.3%), `$_OR_` 745 (17.2%) -- consistent with a ripple-carry
adder tree implementation.

## Area

Total cells: 4318 (generic, pre-mapping).
Top three contributors:

- `$_AND_`: 1837 (42.5%) -- carry generation
- `$_XOR_`: 1609 (37.3%) -- sum computation
- `$_OR_`: 745 (17.2%) -- carry propagation

Sequential elements: 90 flip-flops -- 16 weight registers (8-bit each) +
4 output registers (32-bit each) + 1 valid register = 257 bits, consistent
with 90 flops.

## Warnings

No failed timing constraints (STA not run -- no mapped netlist). The
`crossbar_mac_synth.v` netlist contains generic cells only and cannot be
used for place-and-route without re-mapping to a target library.
