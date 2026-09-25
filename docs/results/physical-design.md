# P0.7 complete-top physical design

This record holds the first complete-top Sky130 route and the constraint and
floorplan attempts that led to it. It is **measured EDA output**, not silicon
measurement. The routed design is functionally verified RTL, but P0.7 remains
open because this route is not timing clean and its power report is outside the
library's valid slew range.

## Configuration and tools

The completed run is `qkt_chiplet_top`, 4x4, `D_HEAD=64`, `T_MAX=16`, Bs=32,
one score lane, protocol version 3, at revision `98e5623`. It used OpenLane
1.1.1 image digest
`sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229`,
OpenROAD `b16bda7e82721d10566ff7e2b68f1ff0be9f9e38`, Yosys 0.38
`543faed9c8c`, Magic 8.3.483, Netgen 1.5.270, and Sky130A PDK revision
`bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`.

The final attempt constrained the clock to 125 ns, used a 2200 by 2200 um die,
a 2188.68 by 2176.00 um core, and 0.25 placement density. Placement and global
routing timing repair were disabled after the 50 ns and 100 ns repair steps
failed to converge. All other flow steps, including CTS, detailed routing,
parasitic extraction, GDS generation, DRC, and LVS, ran.

## Constraint and floorplan sweep

| Constraint | Die | Outcome |
| ---: | ---: | --- |
| 50 ns | 1500 um | Post-CTS setup slack was -33.95 ns; setup repair did not finish after 12 minutes |
| 100 ns | 1500 um | Post-CTS WNS printed as 0.00 ns, but OpenROAD still found 166 sub-precision setup violations and repair did not finish after 14 minutes |
| 125 ns | 1500 um | First detailed-route pass reached 54,335 violations; stopped as congestion limited |
| 125 ns | 2200 um | Detailed routing converged to zero violations after seven repair iterations; complete signoff flow finished |

The machine-readable [sweep record](p0-7-physical.csv) keeps these outcomes.
The larger floorplan's final global-routing usage was 28.23% on met1, 27.68%
on met2, 3.14% on met3, 5.61% on met4, and 0.03% on met5, with zero global
overflow.

## Completed route result

| Item | Result |
| --- | ---: |
| Synthesized cells | 74,491 |
| Placed cells including physical cells | 536,627 |
| Placed standard-cell area | 862,344 um2 |
| Core area | 4,762,568 um2 |
| Die area | 4.84 mm2 |
| Final utilization | 18.11% |
| Routed wire length | 4,247,746 um |
| Vias | 578,518 |
| Detailed-route violations | 0 |
| Magic DRC violations | 0 |
| KLayout DRC violations | 0 |
| LVS errors | 0 |
| Antenna violations | 262 pins, 225 nets |

The route is DRC and LVS clean but still has antenna violations, so it is not a
tapeout-clean result.

## Timing and critical path

At the extracted worst corner, setup WNS is **-71.08 ns** and TNS is
**-10,325.71 ns** against 125 ns. Worst hold slack is **-0.04 ns**. The inferred
minimum setup period is 196.08 ns, or 5.10 MHz, before adding margin, but the
hold failure means this is not a timing-closed clock. Applying 1,049,665 T=512
cycles to that inferred period gives a **projected 205.82 ms**; it is not a
timing-closed latency.

The worst path starts at the scale accumulator-bank selector, passes through
the variable accumulator-bank read and `quarter_to_fp32` leading-bit conversion,
and ends at `u_scaler.g_lane[1].u_scale_q.s1_exp_sum[8]`. The two FP32
multipliers are separated by registers. The measured path therefore points to
scale launch selection and integer-to-FP32 conversion, rather than a
multiply-multiply-add combinational chain, as the first P1 timing target.

## Power limitation

The extracted design has 13,148 maximum-slew violations and 471 maximum-fanout
violations. OpenSTA consequently extrapolates invalid typical-corner values of
1.32 MW internal power and 2.43 MW switching power while reporting only
0.678 uW leakage. These values are physically inconsistent and are rejected as
a power result. P0.5 cannot use them to decide K reuse. A timing and slew-clean
route must supply the power baseline.

The complete generated tree remains under ignored `build/physical/`. The CSV
above is the reviewed result kept in Git.

## Related

- [Results index](README.md)
- [P0 problem statement](../problem-statements/p0-dense-fp4-matmul.md)
- [Development plan](../roadmap.md)
- [Latest verification](latest-verification.md)
