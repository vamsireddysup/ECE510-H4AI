# P0.7 complete-top physical design

## M2 block-streaming checkpoint, stopped at CTS

Revision `bb85cde` was mapped in the same wire-free Yosys/Sky130 flow as the
pre-M2 shift/add checkpoint. Cell count falls from 82,388 to 53,137, while
mapped cell area changes from 257,530.74 to 257,922.37 um2 (+0.15%). The large
cell-count reduction confirms that the tile-wide accumulator and its read mux
were removed; the retained FP32 adder keeps total mapped area essentially flat.

A LibreLane 3.0.14 global-route checkpoint was then started at 30 ns with an
8 ns synthesis target and the 1,800 um square floorplan. The owner requested a
handoff before the run could finish, so it was stopped during CTS. Synthesis,
global placement, design repair, and detailed placement completed. Pre-CTS STA
reported a 45.41 ns minimum period (22.02 MHz). Detailed placement contained
113,610 standard cells, 840,606 um2 of instances at 26.46% core utilization,
and 3,296,870 um estimated wire length. These are intermediate values: there is
no global-route congestion, setup/hold signoff, DRC, LVS, antenna, or power
result from this stopped run.

The resumable evidence is under ignored
`build/librelane/m2-block-stream-grt-30ns/`. Re-run
`SYNTH_CLOCK_PERIOD=8 ./scripts/run_librelane.sh m2-block-stream-grt-30ns 30 global-route`
to replace it cleanly. Reviewed checkpoint values are in
[`data/m2-block-stream-checkpoint.csv`](data/m2-block-stream-checkpoint.csv).

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

## P0.7b: the frequency this design actually closes at

The recorded 30.5 ns is a re-STA of a netlist synthesized for 125 ns with the
OpenLane default `SYNTH_STRATEGY` of `AREA 0`, placed without placement timing
repair. Nobody asked the tools for speed. P0.7b asks, in six stages: F0 makes a
run possible, F1 ranks the paths, F2 sweeps synthesis, F3 applies only the RTL
fixes F1 justifies, F4 sweeps the floorplan, and F5 is one full signoff run
whose deliverable is the project's first valid dynamic power number. F6 runs
only if F5 closes.

No wall-clock speedup is claimed at any frequency. At the measured 135,280-cycle
eight-engine T=512 command, parity with one OpenBLAS thread needs 461 MHz and
parity with the four-core, eight-thread OpenBLAS run needs 951 MHz. The claim
this work can support is energy and area per score.

Every run below uses `qkt_chiplet_top` at 4x4, `D_HEAD=64`, `T_MAX=16`, Bs=16,
one score lane, protocol version 5, and `ENGINES=1` unless its row says
otherwise, with OpenLane 1.1.1 image
`sha256:26719ced90c315b8b4ad7b9dc3e9a176991cea4c3f3282660d8d60d0f0cae229`,
Yosys 0.38, OpenSTA 2.5.0, and Sky130A `bdc9412b3e468c102d01b7cf6337be06ec6e9c9a`.
Synthesis-only numbers are **measured** on the mapped netlist with ideal clocks
and no wire parasitics, so they are lower bounds on routed delay.

### F0: making a run possible

The physical configuration could not elaborate the current RTL.
`VERILOG_FILES` omitted `rtl/core/qkt_engine.sv`, which `rtl/filelist.f` lists,
and the base `SYNTH_PARAMETERS` had no `ENGINES` and still named the retired
Bs=32 default. Both are fixed, and `scripts/run_physical.sh` now refuses to run
if the OpenLane file list and `rtl/filelist.f` differ. `SYNTH_STRATEGY`,
`SYNTH_SIZING`, `SYNTH_BUFFERING`, `STD_CELL_LIBRARY`, `ENGINES`, and
`MAX_TRANSITION_CONSTRAINT` are environment overrides in the same style as
`DIE_AREA`, and the manifest records each one plus the count of uncommitted RTL,
configuration, and script paths.

`MAX_TRANSITION_CONSTRAINT` is now set explicitly to 0.75 ns, but that changes
no number. Every recorded run already inherited 0.75 ns from the PDK's
`sky130_fd_sc_hd/config.tcl`, and the resolved configuration of the optimized
route shows it, so the SDC's `set_max_transition` guard was true. The slew
violations have a different cause. In that route's nominal-extraction signoff
log, **16,212 of 26,861 slew violator lines, 60%, are `INSDIODE1` pins**: antenna
diodes that global-route antenna repair inserts after the resizer's slew repair
has already run. F5 has to address that ordering rather than the constraint.

The first proof run then failed at parse. OpenLane's Yosys 0.38 rejects
`automatic` variable declarations inside procedural blocks, which Verilator
accepts, so the replicated-engine RTL had never been synthesizable. Revision
`7048905` replaces both with module-level signals; every score and the T=512
cycle counts at `ENGINES=1` and `8` for both protocols are unchanged.

The proof run at `7048905`, 10 ns, and the untouched defaults (`AREA 0`,
sizing off, buffering on) completes synthesis and STA:

| Run | Strategy | Typical WNS | Typical TNS | Cells | Mapped area |
| --- | --- | ---: | ---: | ---: | ---: |
| `f0-default-area0-10ns` | AREA 0, sizing 0, buffering 1 | -2.80 ns | -3,331.03 ns | 97,703 | 1,045,707 um² |

That alone supports the reason for reopening P0.7. The previous 58.09 ns mapped
path belongs to a 225 ns request; asking for 10 ns with the same strategy maps
the same design to a 12.8 ns typical-corner path.

### F1: the path distribution at 10 ns

Run `f2-p10-delay0` at `7048905` uses `DELAY 0`, `SYNTH_SIZING 1`, and
`SYNTH_BUFFERING 1` at 10 ns. It maps to 109,182 cells and 1,198,994 um², with
typical WNS -2.03 ns. `scripts/sta/endpoint_paths.tcl` loads the run's resolved
configuration, one corner's Liberty file, the netlist, and the project SDC,
then names the RTL register behind every anonymized Yosys instance by its Q net.
`scripts/rank_endpoints.py` groups the result by owning block.

The requested top 50 endpoints are uninformative on their own: one register
class fills them. `acc_bank` alone is 2 banks x 4 blocks x 16 scores x 13 bits,
1,664 endpoints.

| Corner | Top 50 endpoints | Worst slack | Arrival |
| --- | --- | ---: | ---: |
| `tt_025C_1v80` | 50 x `rst_n -> acc_bank` | -2.028 ns | 11.700 ns |
| `ss_100C_1v60` | 49 x `matrix_size -> acc_bank`, 1 x scaler | -12.204 ns | 21.703 ns |

So I also ranked every block pair by its own worst endpoint across 14,937
endpoints. The slow corner sets multi-corner setup signoff:

| Rank | Start block -> end block | Worst slack | Arrival | Endpoints |
| ---: | --- | ---: | ---: | ---: |
| 1 | `matrix_size` register -> accumulator banks | -12.204 ns | 21.70 ns | 1,017 |
| 2 | scaler -> scaler (`scaler_acc_col -> s1_exp_sum`) | -11.817 ns | 21.44 ns | 628 |
| 3 | compute sequencer (`calc_row -> acc_scores`) | -11.524 ns | 21.02 ns | 275 |
| 4 | output sequencer (`tiles_per_row`) -> AXI `done` | -10.960 ns | 20.46 ns | 65 |
| 5 | score banks -> scaling sequencer | -10.927 ns | 20.44 ns | 45 |
| 6 | reducer -> reducer (`s2_sum -> result`) | -10.539 ns | 20.05 ns | 464 |
| 7 | compute sequencer -> Q storage (`calc_depth -> q_row`) | -10.314 ns | 19.94 ns | 19 |
| 8 | compute sequencer -> accumulator banks (`calc_depth -> acc_bank`) | -10.044 ns | 19.55 ns | 648 |

At the typical corner the order changes: `rst_n -> acc_bank` is first at
-2.028 ns, then the scaler at -1.154 ns and `calc_row -> acc_scores` at
-0.950 ns. The complete table for both corners is in
[`data/endpoint-ranking-10ns.csv`](data/endpoint-ranking-10ns.csv).

What the top paths are:

- **Rank 1** leaves the `matrix_size` register, passes the two 32-bit compares
  in `calc_start` (`calc_row < matrix_size`, `calc_col < matrix_size`) by 6.1 ns,
  and fans out through a buffer tree by 8.1 ns. `calc_start` then selects the K
  operand index, `k_bank[...][0]` against `k_bank[...][calc_depth]`, so it sits
  in front of the 64:1 operand mux, decode, multiply, and 13-bit accumulate.
- **`rst_n`** spends the 2.00 ns maximum input delay, then 6.4 ns in a `buf_1`
  tree driving fanouts of 27 and 28 at 1.47 and 1.58 ns per stage, and joins
  the accumulate cone at the same node as rank 1. Its slow-corner worst path is
  21.01 ns, -11.51 ns slack, only 0.69 ns behind rank 1, so `endpoint_count 1`
  hides it there. Reset is worst at typical because its 2 ns input delay does
  not scale with the corner while logic depth does.
- **Rank 3** is `acc_scores <= calc_rows_here * calc_cols_here`, a 32-bit by
  32-bit multiply of two values no larger than `TILE_SIZE`. Rank 4 is the same
  shape: `tile_count+1 == tiles_per_row*tiles_per_row` in the done test.
- **Rank 2** is the accumulator read mux, `quarter_to_fp32`'s leading-one and
  shift, and the multiplier's exponent add in one stage.
- **Rank 8** is the multiply-accumulate itself from `calc_depth`: 64:1 K operand
  mux, decode, multiply, add. It arrives at 19.55 ns at the slow corner with no
  control in front of it.

`start` is a registered AXI output, so the flush fanout does not start at a pin
and the 20% input delay does not apply to it. That delay does apply to `rst_n`.

Two consequences for F3. Reset is justified as the first fix by the typical
corner and by being 0.69 ns from the slow-corner worst path, but it cannot move
the slow-corner worst path alone, because `calc_start` enters the same node. And
rank 8 means that removing every control path still leaves a 19.55 ns
slow-corner datapath, so reaching 10 ns at signoff would require restructuring
the operand path, not just cleaning up control.

### F2: synthesis strategy and period sweep

`scripts/sweep_synthesis.sh` ran the requested grid, periods 20, 15, 12, 10, and
8 ns crossed with `AREA 0`, `DELAY 0`, and `DELAY 2`, with `SYNTH_SIZING 1` and
`SYNTH_BUFFERING 1`, four runs at a time. RTL and configuration are identical at
the two recorded revisions, `432cc19` and `e173101`; each manifest's one dirty
path is the new, untracked sweep or collection script. `scripts/collect_synthesis.py`
reads cells and area from the Yosys report and reruns the F1 STA script for the
worst path at the typical and slow corners.

Two properties of OpenLane 1.1.1's `synth.tcl` shape how the grid reads:

- **`SYNTH_SIZING` has no effect when `SYNTH_BUFFERING` is 1.** The ABC fine-tune
  step is `buffer; upsize; dnsize` when buffering is on and only falls back to
  `upsize; dnsize` for sizing when it is off. The data agrees: F0 with sizing 0
  and the 10 ns `AREA 0` point here both map to 1,045,707 um².
- **The period saturates at both ends.** At `AREA 0`, the 8 ns and 10 ns runs
  produced byte-identical netlists, and 15 ns and 20 ns are identical at the slow
  corner in every strategy. The period only steers ABC between roughly 10 and
  15 ns.

Arrival alone misleads here. Typical-corner arrival at 15 and 20 ns differs by
exactly 1.0 ns in every strategy, which is `0.20 x 5 ns` of input delay on a
port-started path. I therefore compare the period-independent minimum period,
`period - worst slack`, which agrees at 15 and 20 ns wherever the netlist does.

| Strategy | Target | Cells | Mapped area | Area vs `AREA 0`, 10 ns | Typical min. period | Slow min. period | Slow vs `AREA 0`, 10 ns |
| --- | ---: | ---: | ---: | ---: | ---: | ---: | ---: |
| `AREA 0` | 20 ns | 97,703 | 1,044,647 um² | -0.10% | 17.069 ns | 32.140 ns | +20.54% |
| `AREA 0` | 15 ns | 97,703 | 1,044,649 um² | -0.10% | 16.069 ns | 32.140 ns | +20.54% |
| `AREA 0` | 12 ns | 97,703 | 1,045,210 um² | -0.05% | 13.467 ns | 27.305 ns | +2.40% |
| `AREA 0` | 10 ns | 97,703 | 1,045,707 um² | 0.00% | 12.804 ns | 26.664 ns | 0.00% |
| `AREA 0` | 8 ns | 97,703 | 1,045,707 um² | 0.00% | 12.804 ns | 26.664 ns | 0.00% |
| `DELAY 0` | 20 ns | 109,182 | 1,198,105 um² | +14.57% | 17.044 ns | 30.514 ns | +14.44% |
| `DELAY 0` | 15 ns | 109,182 | 1,198,105 um² | +14.57% | 16.044 ns | 30.514 ns | +14.44% |
| `DELAY 0` | 12 ns | 109,182 | 1,198,237 um² | +14.59% | 13.535 ns | 25.842 ns | -3.08% |
| `DELAY 0` | 10 ns | 109,182 | 1,198,994 um² | +14.66% | 12.028 ns | 22.204 ns | -16.73% |
| `DELAY 0` | 8 ns | 109,182 | 1,200,354 um² | +14.79% | 10.955 ns | 20.593 ns | -22.77% |
| `DELAY 2` | 20 ns | 109,816 | 1,180,462 um² | +12.89% | 16.614 ns | 28.871 ns | +8.28% |
| `DELAY 2` | 15 ns | 109,816 | 1,180,462 um² | +12.89% | 15.614 ns | 28.871 ns | +8.28% |
| `DELAY 2` | 12 ns | 109,816 | 1,180,522 um² | +12.89% | 13.887 ns | 25.891 ns | -2.90% |
| `DELAY 2` | 10 ns | 109,816 | 1,181,043 um² | +12.94% | 12.102 ns | 23.228 ns | -12.89% |
| `DELAY 2` | 8 ns | 109,816 | 1,182,870 um² | +13.12% | 11.117 ns | 21.621 ns | -18.91% |

The machine-readable record is [`data/synthesis-sweep.csv`](data/synthesis-sweep.csv).

**Choice.** The slow corner sets multi-corner setup signoff, and along its
frontier the knee is not reached inside this grid. From the best `AREA 0`
point, `DELAY 2` at 8 ns buys 18.91% of period for 13.12% of area, and `DELAY 0`
at 8 ns buys 22.77% for 14.79%. The last step, `DELAY 0` from 10 ns to 8 ns,
costs 0.11% of area for 7.26% of period. At the typical corner the same move from
`AREA 0` to `DELAY 0` is almost exactly one to one, 14.4% of period for 14.8% of
area, so that corner puts the knee at the strategy change itself. I select
**`DELAY 0` with an 8 ns synthesis target**. A tighter target might still help
at the slow corner; I did not widen the grid to find out.

Two limits on what this establishes. These are mapped netlists with ideal clocks
and no wires, so routed paths will be longer. And the synthesis target is not
the placement-and-route constraint: asking the resizer to repair a netlist that
maps at 20.6 ns slow against an 8 ns constraint would recreate the earlier
nonconvergent repair on thousands of endpoints. The F4 and F5 constraint will be
set from the post-F3 slow-corner result and recorded with its derivation.

### F3: RTL fixes the ranking justifies

Each change is its own commit, synthesized at the F2 point, `DELAY 0` with an
8 ns target, and re-ranked with the F1 scripts before choosing the next. Every
change is cycle-neutral. After the last one, `scripts/check_cycle_model.py`
re-simulated all 32 recorded cycle-model configurations on revision `34d9df5`,
including the Bs=32 protocol 3 and 4 points and every 8x8 and 16x16 lane
variant, and all 32 reproduce their recorded cycle and input-beat counts
exactly. Every score stayed bit-identical, including the T=512 precision run.
The cycle model needed no change.

| Step | Revision | Change | Slow min. period | Change | Typical min. period | Change | Area change |
| --- | --- | --- | ---: | ---: | ---: | ---: | ---: |
| F2 point | `e173101` | none | 20.593 ns | | 10.955 ns | | |
| F3.1 | `117ce31` | Reset synchronizer and per-engine registered reset | 19.973 ns | -0.620 ns | 9.975 ns | -0.980 ns | -0.92% |
| F3.2 | `9f43560` | Registered tile-position compares | 19.799 ns | -0.174 ns | 9.928 ns | -0.047 ns | +2.05% |
| F3.3 | `e350fbb` | Accumulator read in the scale prefetch cycle | 18.956 ns | -0.843 ns | 9.320 ns | -0.608 ns | -0.12% |
| F3.4 | `3b4b3ac` | Narrowed compute depth counter | 19.411 ns | **+0.455 ns** | 9.180 ns | -0.140 ns | +0.22% |
| F3.5 | `34d9df5` | `T_MAX`-sized command arithmetic | **18.241 ns** | -1.170 ns | **8.998 ns** | -0.182 ns | -10.04% |

In total F3 moves the mapped slow-corner minimum period from 20.593 ns to
18.241 ns, 11.4%, and the typical corner from 10.955 ns to 8.998 ns, 17.9%,
while cutting mapped area by 8.95% to 1,092,889 um². These are mapped-netlist
results without wires. The rows are in
[`data/frequency-attribution.csv`](data/frequency-attribution.csv).

What each step found:

- **F3.1.** `rst_n` now drives only a two-flop synchronizer, and each engine
  takes its own registered copy, so no reset tree starts at a pin. The change
  exposed a real protocol fault: `awready`, `wready`, and `arready` were all
  asserted while the AXI block was held in reset. It was invisible while reset
  released in one cycle, and it dropped a transaction once the synchronizer
  delayed release. The ready outputs now stay low in reset. Reset leaves the
  ranking at both corners.
- **No registered flush.** Across 14,937 F1 endpoints at both corners `flush`
  was never the worst startpoint of any endpoint, so F1 did not justify it. It
  did surface after F3.2 as the next input into the accumulator write cone. The
  reason is structural: the unreset storage arrays are written inside the
  `if (!rst_n || flush) ... else` block, so reset and flush gate every storage
  write enable. A registered flush would not remove that, and after F3.5 it is
  no longer in the slow-corner top of the ranking.
- **F3.2.** `calc_start` and `row_skip` compared 32-bit `calc_row` and
  `calc_col` against `matrix_size` in front of the `calc_start` fanout. The
  compares are now flags registered from the next position, and an assertion
  checks them against the original compares on every active cycle. I confirmed
  the assertions are live by inverting one and watching it fire.
- **F3.3.** The first scaling multiplier stage began with the 32-to-1
  accumulator read mux. The accumulator is now read in the prefetch cycle, which
  already existed, and registered with the scales.
- **F3.4** removed the 32-bit increment and compare from the Q prefetch
  address, and that path fell from first to rank 116 at the typical corner. The
  slow-corner result still regressed by 0.455 ns because ABC restructured the
  untouched frontend logic worse. I kept the change, which strictly removes
  logic, and record its measured delta as a regression. **Single synthesis runs
  of this design move by about half a nanosecond at the slow corner for reasons
  unrelated to the edit**, so smaller deltas above are not individually
  significant.
- **F3.5.** Every quantity derived from `matrix_size` was 32 bits wide although
  a running command has `matrix_size <= T_MAX`. The done test was
  `tile_count+1 == tiles_per_row*tiles_per_row`, a 32-bit square, and the score
  count was `calc_rows_here * calc_cols_here`, another 32-bit multiply of two
  values no larger than `TILE_SIZE`. The frontend now uses a `T_MAX`-sized
  registered copy of the size, done is a narrow down-counter, and each engine
  registers its tile extents. It was the largest gain and removed 10% of the
  mapped area.

**Why F3 stops here.** After F3.5 the slow-corner top of the ranking contains
no control path. It is the arithmetic datapath, all within 0.73 ns:

| Rank | Path | Slow slack at 8 ns |
| ---: | --- | ---: |
| 1 | Scaler: `quarter_to_fp32` and the first multiplier stage | -10.241 ns |
| 2 | Multiply-accumulate through the K bank select | -10.088 ns |
| 3 | Multiply-accumulate accumulator select | -10.082 ns |
| 4 | Multiply-accumulate from the Q bank select | -10.021 ns |
| 5 | Reducer: FP32 add normalize stage | -9.819 ns |
| 6 | Scaler: second multiplier 24x24 stage into the reducer | -9.508 ns |

The zero-cycle retimings left, a K operand prefetch matching the Q one and
moving the conversion into the prefetch cycle, can gain at most about 0.4 ns
before the reducer binds, and that is inside the sensitivity F3.4 measured.
Beyond that, several units need a pipeline stage each: the scaler conversion
(scaling latency 7 to 8 cycles), the reducer normalize (add latency 3 to 4,
three more cycles per Bs=16 score), and the multiply-accumulate (a second CALC
stage). Each costs cycles and changes the cycle model, so it is a design
decision, not a timing fix. I have not made it.

### F4: floorplan sweep, stopped without a routable point

F4 ran the requested grid, die 1300, 1500, 1800, and 2200 um crossed with
target density 0.45, 0.55, and 0.65, at RTL revision `4f3fcd5` (the 1800 um,
0.55 pilot at `e6b68e5`, identical RTL). A new `global-route` mode synthesizes
at an 8 ns target with `DELAY 0`, confirmed by a netlist byte-identical to the
F3.5 run, then places and routes against a **20 ns** constraint with timing
repair off. The 20 ns constraint is a stated choice: the 18.241 ns F3.5
slow-corner mapped minimum period plus about 10% for wires and clock tree.
These are **measured** OpenLane 1.1.1 outcomes. The sweep was stopped externally
before its last three points finished.

Congestion is reported twice. The design-repair step runs its own global route
first; the flow's final global route with antenna repair runs after it.

| Die | Density | Outcome | Placed area | Utilization | Repair-route overflow | Final-route overflow |
| ---: | ---: | --- | ---: | ---: | ---: | ---: |
| 1300 | 0.45, 0.55, 0.65 | GPL-0302, cannot place; minimum density 0.68 | | | | |
| 1500 | 0.45 | GPL-0302; minimum density 0.51 | | | | |
| 1500 | 0.55 | GRT-0119 congestion | 1,132,098 um² | 51% | 4,921 gcells | |
| 1500 | 0.65 | GRT-0119 congestion | 1,132,098 um² | 51% | 8,314 gcells | |
| 1800 | 0.45 | Final route done; GRT-0232 in antenna repair | 1,149,437 um² | 36% | 0 | 24 gcells |
| 1800 | 0.55 | GRT-0119 congestion | 1,149,437 um² | 36% | 1,046 gcells | |
| 1800 | 0.65 | GRT-0119 congestion | 1,149,437 um² | 36% | 4,997 gcells | |
| 2200 | 0.45 | Reached antenna repair, then stopped externally | 1,177,682 um² | 25% | 0 | 14 gcells |
| 2200 | 0.55, 0.65 | Not run | | | | |

The machine-readable record, including the `acc_bank` share of every
congestion report, is [`data/floorplan-sweep.csv`](data/floorplan-sweep.csv).

**Exit condition not met: no floorplan in the grid routed.** Two things block
it, and neither is die size:

- **The accumulator banks cause the congestion.** In every failing report,
  `acc_bank` nets account for nearly all overflow entries: 4,657 references
  against 4,921 overflowing gcells at 1500 um and 0.55, and 1,092 against 1,046
  at 1800 um and 0.55. The banks hold 1,664 flops per engine and feed both the
  accumulate path and the scaler's 32-to-1 read mux.
- **Higher density routes worse, not better.** At 1800 um the repair-route
  overflow goes from 0 to 1,046 to 4,997 gcells as density rises from 0.45 to
  0.55 to 0.65. Only the two 0.45 points cleared the design-repair route, and
  both still had final-route overflow, 24 and 14 gcells.

The premise that a smaller die would cut wire length assumed the old
Bs=32 `AREA 0` netlist of 860,627 um². The current Bs=16 `DELAY 0` netlist
places at 1.13 to 1.18 million um², so 1300 um cannot place at all. The
structural fix, a block-streaming accumulator that stops holding every block's
partial sums, is roadmap milestone M2, and the floorplan sweep moves there with
densities down to 0.25. F5 and F6 did not start.

## M0 gate: the LibreLane toolchain, RTL to GDS

The roadmap's M0 gate asks only whether the new toolchain works end to end, so
it uses a deliberately small configuration. This is a **measured** LibreLane
result at revision `4a740f6`: `qkt_chiplet_top` at 4x4, **`D_HEAD=4`**,
`T_MAX=16`, Bs=16, one score lane, `ENGINES=1`, on a 900 um die at 45% target
density, synthesized at 8 ns with `DELAY 0` and placed and routed at 20 ns.
Tools are LibreLane 3.0.14, image
`ghcr.io/librelane/librelane:3.0.14`, ciel 2.6.1, and Sky130
`8afc8346a57fe1ab7934ba5a6056ea8b43078e71`.

**`D_HEAD=4` is a toy depth.** It exists to exercise the flow, not to describe
the design, whose workload depth is 64. Nothing here transfers to the real
configuration except the toolchain's behavior.

| Item | Result |
| --- | ---: |
| Instances | 155,927 |
| Die area | 0.81 mm² |
| Final utilization | 53.13% |
| Routed wire length | 1,438,721 um |
| Detailed-route violations | 0 |
| Magic DRC | 0 |
| KLayout DRC | 0 |
| LVS errors | 0 |
| **Antenna violations** | **0** |
| Max-slew violations | 5,061 |
| Max-capacitance violations | 145 |
| Max-fanout violations | 0 |
| Worst setup slack, slow corner | -2.0313 ns |
| Worst hold slack, slow corner | -0.0605 ns |

The flow reached GDS and wrote every signoff view. It then stopped at the hold
checker, which is the correct behavior: the design does not meet timing at
20 ns at the slow corner.

**What this settles.** The toolchain works, and the antenna problem is gone.
Every OpenLane 1.1.1 route on record carried antenna violations, 332 pins and
281 nets on the best one, and 60% of that run's slew violators were the antenna
diodes inserted to fix them. LibreLane repairs antennas during detailed routing
and reports **zero antenna violations** here, with DRC and LVS clean. The F4
blocker was congestion, not antennas, but the antenna and slew interaction that
made the old dynamic power unusable is no longer in the way.

**What this does not settle.** Setup misses by 2.03 ns and hold by 0.06 ns at
the slow corner, with timing repair at its defaults and no margins set; 5,061
slew and 145 capacitance violations remain. The run also reports a total power
of 18.6 mW, and **that number is not usable**: nothing annotated switching
activity, so it rests on the tool's default toggle assumption. The project's
first valid power number still requires the gate-level simulation planned for
milestone M2, at `D_HEAD=64`.

The reviewed metrics are in
[`data/m0-gate-librelane-metrics.csv`](data/m0-gate-librelane-metrics.csv).

## Related

- [Project status](../project-status.md)
- [Architecture](../architecture.md)
- [Performance results](performance.md)
- [Results index](README.md)
