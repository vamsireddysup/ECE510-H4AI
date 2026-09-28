# P0.7 complete-top physical design

This record holds the first complete-top Sky130 routes and the constraint and
floorplan attempts that led to them. These are **measured EDA outputs**, not
silicon measurements. P0.7 established a routable floorplan and moved the
setup-only limit from about 196 ns to 30.5 ns, but remains open because
multi-corner hold, antenna, slew, fanout, and power qualification do not close.

## Configuration and tools

The completed routes target `qkt_chiplet_top`, 4x4, `D_HEAD=64`, `T_MAX=16`,
Bs=32, one score lane, and protocol version 3. The optimized route contains RTL
revision `e579ad7`; its generated manifest records that source revision. It
used OpenLane 1.1.1 image digest
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
| 125 ns | 2200 um | Optimized RTL completed; fixed-route setup closes through 30.5 ns and misses at 30.4 ns; worst hold slack -1.2765 ns |

The machine-readable [sweep record](data/physical-constraint-sweep.csv) keeps these outcomes.
The optimized run took 2 hours 8 minutes, including 1 hour 4 minutes of routed
work, and peaked at 6,091 MB. Detailed routing took 43 minutes and signoff DRC
took another 34 minutes. The replicated-engine study therefore selected one
16x16 four-lane attempt as the second physical point instead of eight 4x4
engines; its outcome is recorded below.

## Latest completed route

| Item | Result |
| --- | ---: |
| Synthesized cells | 69,400 |
| Placed cells including physical cells | 542,488 |
| Placed standard-cell area | 860,627 um2 |
| Core area | 4,762,568 um2 |
| Die area | 4.84 mm2 |
| Final utilization | 18.07% |
| Routed wire length | 4,614,216 um |
| Vias | 571,200 |
| Detailed-route violations | 0 |
| Magic DRC violations | 0 |
| KLayout DRC violations | 0 |
| LVS errors | 0 |
| Antenna violations | 332 pins, 281 nets |

The route is DRC and LVS clean but not antenna clean.

## 16x16 four-lane attempt

The replicated-engine study recommended one 16x16 four-lane array over eight
4x4 engines on the available area evidence. I therefore started the same
125 ns, 2200 um flow at Bs=32 and revision `2c6a76f`. It did not reach a mapped
netlist. After 20 minutes 49 seconds in Yosys, `OPT_MEM_PRIORITY` was still
lowering the dynamically written accumulator arrays on one fully occupied CPU
core. Resident memory had grown to 2.49 GB and the synthesis log had not
advanced for 9 minutes 49 seconds, so I stopped the bounded attempt.

There is no 16x16 synthesized area, timing, placement, or routing result to
report. Follow-up inspection identifies `acc_bank`, not `k_cache`, `sq`, or `sk`,
as the first scaling failure. The dynamic accumulator writes create 31,654
process signals and thousands of memory ports. The run already used `T_MAX=16`,
so lowering cache capacity is not an available workaround.

A static-write experiment bypassed `OPT_MEM_PRIORITY` but expanded to 12.4 GB in
technology mapping. A second ten-minute experiment skipped the optional priority
optimization and reached `MEMORY_COLLECT` and `MEMORY_MAP`, but did not produce a
mapped netlist. Both were bounded and generated logs remain under ignored
`build/`. [ADR 0006](../adr/0006-use-replicated-4x4-engines.md) therefore selects
replicated 4x4 engines as the next physical prototype. No 16x16 frequency, area,
or latency measurement is claimed.

## Timing and critical path

At the routed 125 ns constraint, the worst maximum-RC setup slack across three
timing corners is **+75.6704 ns**. Re-evaluating that same routed netlist and
maximum-RC SPEF while preserving the project's 20% maximum I/O-delay rule gives:

| Period | Worst setup slack | Worst hold slack |
| ---: | ---: | ---: |
| 68 ns | +30.0704 ns | -1.2765 ns |
| 50 ns | +15.6703 ns | -1.2765 ns |
| 31 ns | +0.4703 ns | -1.2765 ns |
| 30.5 ns | +0.0703 ns | -1.2765 ns |
| 30.4 ns | -0.0097 ns | -1.2765 ns |

The setup-only crossover is about 30.41 ns, or 32.9 MHz. The worst extracted
hold slack is **-1.2765 ns** at the slow timing corner; the fastest corner is
-0.0765 ns and the typical corner is +0.0513 ns. This fixed-layout sweep is a
measured STA result, but a multi-corner signoff cannot discard either hold
failure. There is no timing-closed period or achieved frequency yet.

Applying 30.5 ns to the verified Bs=32 1,049,666-cycle T=512 command gives a
**projected 32.015 ms**. The 125 ns route constraint gives 131.208 ms. Neither
is a timing-closed latency because hold fails.

The worst setup path is now the synchronous `rst_n` distribution into
`_118562_`, rather than the accumulator-to-scaler path. The divider removal,
scale prefetch, and bounded integer conversion therefore survived placement and
routing and moved the physical bottleneck. The slow-corner hold path starts at
the `s_tlast` input and ends at `_118347_`. Placement timing repair remains
disabled after the earlier pass failed to finish on thousands of endpoints;
route-time repair used only its single analysis corner. That explains why a
typical-corner clean result still fails slow and fast signoff corners.

## Power limitation

The maximum-RC extraction reports 9,956 maximum-slew and 533 maximum-fanout
violations at the typical timing corner. The slow corner has 21,262 slew and
533 fanout violations. Dynamic power is therefore still rejected; the
structural timing fix did not qualify switching activity or electrical limits.

The slow-corner leakage result is 0.474 mW. Leakage does not depend on assumed
toggle activity, so P0.5 uses it only as a conservative area-scaled projection;
it does not turn this run into a valid total-power or energy measurement.

The complete generated tree remains under ignored `build/physical/`. The CSV
above is the reviewed result kept in Git.

## Critical-path experiment setup

Each row uses `qkt_chiplet_top` at 4x4, `D_HEAD=64`, `T_MAX=16`, Bs=32, one
score lane, and a 225 ns constraint. The command is:

```bash
./scripts/run_physical.sh RUN_NAME 225 4 1 synthesis
```

The flow uses OpenLane 1.1.1 image digest
`sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229`,
OpenROAD `b16bda7e82721d10566ff7e2b68f1ff0be9f9e38`, Yosys 0.38
`543faed9c8c`, the Sky130 HD library, and Sky130A PDK revision
`bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`. Generated logs remain under
ignored `build/physical/`; the [CSV](data/critical-path-attribution.csv) is the concise
machine-readable record.

## Critical-path attribution

| Step | Mapped data arrival | Setup slack at 225 ns | Mapped cells | Mapped cell area |
| --- | ---: | ---: | ---: | ---: |
| Baseline | 95.95 ns | +128.72 ns | 74,491 | 766,267 um² |
| Row/column launch counters | 58.58 ns | +166.09 ns | 68,972 | 729,666 um² |
| Registered scale prefetch | 58.49 ns | +166.18 ns | 69,164 | 732,895 um² |
| Tree-based integer conversion | 58.09 ns | +166.58 ns | 69,400 | 736,351 um² |

Removing variable 32-bit division and modulo produced the material gain: the
mapped path fell by 37.37 ns, or 38.9%, and mapped area fell by 4.8%. The worst
path then moved from the accumulator-to-scaler datapath to synchronous `rst_n`
logic. Scale prefetch and the conversion tree reduced the worst mapped path by a
further 0.49 ns in total because neither was on that new worst path.

The 58.09 ns mapped path is below the 68 ns break-even target. I therefore did
not add the optional accumulator-read pipeline register. The follow-up route
confirms the change: a fixed-layout multi-corner sweep closes setup at 30.5 ns
and misses at 30.4 ns. The routed worst path is synchronous reset distribution,
so the accumulator and conversion path no longer sets setup timing. Hold,
slew, fanout, and antenna still fail, so 32.9 MHz remains a setup-only bound
rather than an achieved frequency.

## Critical-path functional and cycle consequences

The coordinate and conversion changes do not alter a score bit. The prefetch
register adds one drain cycle. Bs=32 scaling is now
`ceil(B^2/L) + 7 + 3*(C-1)` cycles per tile, including one prefetch cycle and
six multiplier cycles. CALC still binds at 4x4, so T=512 increases by one command
drain cycle to 1,049,666. All 16 recorded cycle configurations match the updated
closed-form model exactly, and the T=512 RTL precision result remains
14.2346060% relative Frobenius error with every score bit equal to the model.

## Related

- [Project status](../project-status.md)
- [Architecture](../architecture.md)
- [Performance results](performance.md)
- [Results index](README.md)
