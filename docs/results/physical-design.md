# P0.7 complete-top physical design

This record holds the first complete-top Sky130 routes and the constraint and
floorplan attempts that led to them. These are **measured EDA outputs**, not
silicon measurements. P0.7 established a routable floorplan and setup closure,
but remains open because multi-corner hold, antenna, slew, fanout, and power
qualification do not close.

## Configuration and tools

Both completed runs target `qkt_chiplet_top`, 4x4, `D_HEAD=64`, `T_MAX=16`,
Bs=32, one score lane, and protocol version 3. The latest run is revision
`028401d`. It used OpenLane 1.1.1 image digest
`sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229`,
OpenROAD `b16bda7e82721d10566ff7e2b68f1ff0be9f9e38`, Yosys 0.38
`543faed9c8c`, Magic 8.3.483, Netgen 1.5.270, and Sky130A PDK revision
`bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`.

The latest run uses a 2200 by 2200 um die, a 2188.68 by 2176.00 um core, and
0.25 placement density. Its project SDC assigns maximum input and output delay
as 20% of the period, minimum input delay as 3 ns, and minimum output delay as
0 ns. Placement timing repair is disabled because its post-CTS hold pass did
not complete after 36 minutes on 9,129 endpoints. Global-route timing repair
uses a 0.001 ns hold target; extracted multi-corner signoff remains the final
acceptance check.

## Constraint and floorplan sweep

| Constraint | Die | Outcome |
| ---: | ---: | --- |
| 50 ns | 1500 um | Post-CTS setup slack was -33.95 ns; setup repair did not finish after 12 minutes |
| 100 ns | 1500 um | Post-CTS WNS printed as 0.00 ns, but 166 setup endpoints remained and repair did not finish after 14 minutes |
| 125 ns | 1500 um | First detailed-route pass reached 54,335 violations; stopped as congestion limited |
| 125 ns | 2200 um | Diagnostic route completed; worst extracted setup slack -71.08 ns and hold slack -0.04 ns |
| 225 ns | 2200 um | Stock SDC hold repair stopped after 34 minutes on 8,948 endpoints |
| 225 ns | 2200 um | Project SDC and route-time repair completed; setup closes, worst extracted hold slack -1.0069 ns |

The machine-readable [sweep record](p0-7-physical.csv) keeps these outcomes.
The completed 225 ns run took 1 hour 36 minutes, including 40 minutes of routed
work, and peaked at 6,229 MB. This cost, together with the unresolved 4x4 hold
and power failures, is why P0.7 did not start an 8x8 route. The 8x8 two-lane
point remains the next physical candidate after the shared scale path and
signoff flow close on 4x4.

## Latest completed route

| Item | Result |
| --- | ---: |
| Synthesized cells | 74,491 |
| Placed cells including physical cells | 537,339 |
| Placed standard-cell area | 864,944 um2 |
| Core area | 4,762,568 um2 |
| Die area | 4.84 mm2 |
| Final utilization | 18.16% |
| Routed wire length | 4,249,637 um |
| Vias | 580,244 |
| Detailed-route violations | 0 |
| Magic DRC violations | 0 |
| KLayout DRC violations | 0 |
| LVS errors | 0 |
| Antenna violations | 256 pins, 224 nets |

The route is DRC and LVS clean but not antenna clean.

## Timing and critical path

At 225 ns, the worst extracted setup slack across the three RC extractions and
three timing corners is **+28.7995 ns**. The worst extracted hold slack is
**-1.0069 ns** at the slow timing corner. Typical-corner hold slack is positive,
but a multi-corner signoff cannot discard the slow-corner failure. There is no
timing-closed period or achieved frequency yet.

Applying the constraint to the verified 1,049,665-cycle T=512 command gives a
**projected 236.17 ms**. It is not a timing-closed latency because hold fails.

The setup path remains the path found in the 125 ns route: accumulator-bank
selection and dynamic accumulator read feed the `quarter_to_fp32` leading-bit
conversion and end at the scaler's first Q multiplier input register. The two
FP32 multipliers are separated by registers. P1 should optimize scale launch
selection and integer-to-FP32 conversion before the multiplier chain.

## Power limitation

The nominal extraction reports 476 maximum-slew and 483 maximum-fanout
violations at the typical timing corner. The slow corner has 9,168 slew
violations. OpenSTA consequently reports impossible typical values of 734 kW
internal and 1.35 MW switching power. Those dynamic values are rejected.

The slow-corner leakage result is 0.495 mW. Leakage does not depend on assumed
toggle activity, so P0.5 uses it only as a conservative area-scaled projection;
it does not turn this run into a valid total-power or energy measurement.

The complete generated tree remains under ignored `build/physical/`. The CSV
above is the reviewed result kept in Git.

## Related

- [Results index](README.md)
- [P0 problem statement](../problem-statements/p0-dense-fp4-matmul.md)
- [Development plan](../roadmap.md)
- [Latest verification](latest-verification.md)
