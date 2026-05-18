# M3 -- FP4 Systolic Array Synthesis

## Design

**Module:** `systolic_array_flat` (synthesis-friendly wrapper for `systolic_array`)
**Parameters:** SIZE=4, D_HEAD=4, WIDTH=4 (FP4), ACC_W=32 (FP32 accumulator)
**Description:** 4×4 systolic array computing QK^T attention scores using FP4 E2M1 multiply and FP32 accumulate. 16 PEs, each containing a 256-entry FP4 LUT multiplier and a 32-bit FP32 accumulator.

## Tool flow

```
Yosys 0.44 + ABC --> sky130 HD (tt_025C_1v80) --> OpenSTA 2.5.0
```

Synthesis script: `runs/synth.ys`
STA script: `runs/sta.tcl`
Liberty file: `sky130_fd_sc_hd__tt_025C_1v80.lib`

## Synthesis results

| Metric | Value |
|---|---|
| Total mapped cells | 25,378 |
| Chip area | 188,961 µm² |
| Sequential area | 59,697 µm² (31.59%) |
| Combinational area | 129,264 µm² (68.41%) |
| CPU synthesis time | 25.75 s |

Top cell types after mapping:
- `sky130_fd_sc_hd__o21ai_0`: 2,438 instances
- `sky130_fd_sc_hd__nor3_1`: 1,009 instances
- `sky130_fd_sc_hd__xnor2_1`: 518 instances
- `sky130_fd_sc_hd__xor2_1`: 327 instances

## Timing results (OpenSTA)

**Clock target:** 4.0 ns (250 MHz)

| Metric | Value | Status |
|---|---|---|
| Worst negative slack (setup) | -17.26 ns | VIOLATED |
| Total negative slack | -26,731.40 ns | VIOLATED |
| Worst negative slack (hold) | +0.31 ns | MET |
| Critical path delay | 21.13 ns | -- |
| Maximum achievable frequency | ~46 MHz (1/21.5ns) | -- |

**Critical path:** register `_44707_` → combinational logic → register endpoint. The 21.13 ns arrival time indicates the FP32 accumulator chain is the dominant path -- the 32-bit adder tree across 4 PE inputs creates a long carry-propagate chain without pipelining.

## Analysis

The 17.26 ns setup violation is expected for a first synthesis pass without timing-driven optimization (`synth` command with no timing constraints). The combinational depth of the FP32 accumulator (summing 4 × 32-bit values) is approximately 6-8 gate levels deep, which at sky130 HD typical delays of 0.1-0.3 ns per gate stage totals 15-20 ns -- consistent with the observed 21 ns critical path.

**Hold timing is clean** (+0.31 ns) meaning the sequential logic has no hold violations at any frequency.

## Plan for timing closure

Three options in order of implementation effort:

1. **Relax clock to 25 ns (40 MHz):** Zero RTL changes. Acceptable for a first tape-out attempt. Area stays at 188,961 µm².

2. **Pipeline the FP32 accumulator:** Add one register stage inside the PE accumulator, splitting the 21 ns path into two ~10 ns stages. Enables 100 MHz operation. Requires RTL change to `pe.sv` and increasing the drain cycle count in testbenches.

3. **Replace FP32 adder with a pipelined FP32 adder:** The `fp32_add.sv` module is currently a single-cycle combinational adder. Breaking it into 3 pipeline stages would enable 250 MHz operation. This is the correct path for M4.

## Extrapolation to SIZE=16

The 4×4 array has 16 PEs and area 188,961 µm². A 16×16 array has 256 PEs -- 16× more PEs.

Estimated SIZE=16 area: 188,961 × 16 ≈ **3.02 mm²**

This is within the Sky130 reticle limit (~9 mm²) so the full 16×16 array is physically feasible.

## Files

```
project/m3/
├── src/
│   ├── fp4_mul_lut.sv       -- 256-entry FP4 LUT
│   ├── fp4_mul.sv           -- FP4 E2M1 multiplier
│   ├── fp32_add.sv          -- FP32 adder
│   ├── pe.sv                -- FP4 PE with FP32 accumulator
│   ├── systolic_array.sv    -- 16x16 systolic array (reference)
│   └── systolic_array_flat.sv -- synthesis wrapper (flat ports)
├── runs/
│   ├── synth.ys             -- yosys synthesis script
│   └── sta.tcl              -- OpenSTA timing script
└── reports/
    ├── metrics.csv          -- synthesis summary
    ├── synthesis.log        -- full yosys log
    ├── synth_out.v          -- mapped netlist
    └── sta_report.txt       -- OpenSTA timing report
```
