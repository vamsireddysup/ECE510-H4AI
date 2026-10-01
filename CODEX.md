# Project handoff and agent entry point

This is the single entry point for every coding agent on this repository,
Claude Code and Codex alike. It holds the live project state and the handoff
log. The working rules live in [docs/agent-rules.md](docs/agent-rules.md); read
them before changing anything. There is deliberately no `CLAUDE.md`, and
`AGENTS.md` only points here, so both agents work from one set of rules and one
record of what happened.

Keep this file under about 24 KB. Codex truncates project instructions at
32 KiB by default, so older handoff entries move to
[docs/handoff-log.md](docs/handoff-log.md). **The size budget outranks the
eight-entry rule below.** Entries have grown long enough that eight of them put
this file at 31 KB, a few hundred bytes from silent truncation; six bring it to
27 KB. Rotate entries out until there is clear headroom, and if six still
breaches 24 KB, the next thing to shorten is "Current state", whose M0 and M1
bullets duplicate [docs/project-status.md](docs/project-status.md) and the ADRs.
Nothing is lost by rotating: the archive keeps entries in full.

## Session protocol

**Start of every session.**

1. Read this file and [docs/agent-rules.md](docs/agent-rules.md).
2. Check the lock below. If another agent is marked active, stop and ask the
   owner before touching anything.
3. Run `git status` and `git fetch`, fast-forward `master` if it is behind, and
   read `git log --oneline <commit in the newest handoff entry>..HEAD` to see
   anything done since the last entry.
4. If the previous session finished a milestone, re-run that milestone's gate
   commands before starting new work. A second agent verifying the first is
   what keeps the two from drifting apart.
5. Set the lock to your agent name and the date.

Before committing, re-read the lock and run `git status --short --branch` plus
`git log -1 --oneline`. If `HEAD` moved or another agent owns the lock, stop and
reconcile instead of committing over the other session. An agent that hands off
a live external run also hands off responsibility for recording its result; it
must not resume later and commit after the receiver has claimed the lock.

**During the session.** After every verified commit, update "Current state"
and add a handoff entry. Include the handoff in the work commit, or commit it
separately as `handoff: <what>`. Push it. The handoff is never more than one
step behind the code.

**Stopping.** Neither agent can read its own credit or billing percentage, so
an "at 80% usage" rule cannot be triggered from inside the session. The rule is
therefore continuous: a handoff after every commit, so an abrupt stop loses at
most the step in flight. Stop deliberately, finishing the current atomic step,
committing, writing the entry, pushing, and clearing the lock, when any of
these happens:

- the owner says "handoff" or "stop";
- a context-window, rate-limit, or usage warning appears;
- the session has been long or the next step will not fit in what remains.

Never leave uncommitted work without describing it in the handoff entry. If a
long tool run is still going when you must stop, record its command, run
directory, and how to check its result.

## Lock

Active agent: none. Last owner: Claude (Opus 5), 2026-10-01.

## Current state

Updated 2026-10-01 by Codex.

- **Branch and commit.** `master`, pushed to
  `vamsireddysup/FP4-transformer-attention-accelerator`. CI and `make test`
  pass.
- **Last integrated synthesis.** Same-flow Sky130 mapping of the 4x4 top gives
  40,892 cells and 140,592.34 um2 with packed E4M3 scales against 52,764 cells
  and 257,346.82 um2 with FP32: 22.50% fewer cells and 45.37% less wire-free
  mapped area. The E4M3 point is not routed yet.
- **Active plan.** The research-backed roadmap, milestones M0 to M4, is in
  [docs/project-status.md](docs/project-status.md#roadmap-milestones-m0-to-m4).
  M0 and M1 are complete. The next milestone is **M2, P0 physical closure**.
- **Where the design is.** 4x4 FP4 QK^T engine with 1x16 block scales, exact
  integer block accumulation, and `ENGINES` replication (1 to 16). FP32 v5/v6
  remains the default; selectable E4M3 v7/v8 stores bytes and packs eight per
  beat. All 44 recorded cycle configurations re-simulate exactly.
- **Best timing evidence.** Mapped netlist, `DELAY 0` at an 8 ns target, no
  wires: 18.241 ns slow-corner and 8.998 ns typical-corner minimum period at
  `34d9df5`. This is not a routed or closing frequency.
- **Full M2 signoff now runs to completion. Hold is diagnosed and fixed in
  constraint; antenna, slew, and capacitance remain open.** At 40 ns,
  nine-corner setup passes with +9.4961 ns worst slack, detailed-route, Magic,
  and KLayout DRC are zero, and LVS passes. Six antenna nets, seven antenna
  pins, 15,977 slew, and 989 capacitance violations remain. See
  `docs/results/physical-design.md`.
- **The 1,838 hold failures were an under-specified input delay, not a design
  defect.** All of them start at an input port; none is register to register.
  The SDC gave inputs a 3.0 ns minimum delay against a clock tree with 4.90 to
  5.98 ns of slow-corner insertion delay, so a host clocked from the same pin
  was told it need not hold data as long as the design actually requires. Hold
  closes at every one of the nine corners at and above 4.898 ns, and at 6.0 ns
  the worst hold slack equals the register-to-register figure, so input paths
  stop being the critical class. Setup is unchanged at every value. The
  LibreLane SDC default is now 6.0 ns; the OpenLane 1.1.1 SDC keeps 3.0 ns for
  reproducibility. This is why larger placement hold margins made hold worse.
- **Most of the slew and capacitance violations are margin, not electrical.**
  `MAX_TRANSITION_CONSTRAINT` is 0.75 ns against Sky130's 1.5 ns library limit,
  and `MAX_CAPACITANCE_CONSTRAINT` is 0.2 pF, a LibreLane default the project
  never set, against for example 0.353 pF on `buf_4`. Checked against the
  library's per-pin limits instead, the worst corner has **272 slew and 23
  capacitance** violations, not 15,977 and 989, and the typical and fast corners
  are clean. The remaining electrical item is 272 pins, confined to slow
  corners: 33 on repair-inserted `ANTENNA_*` diodes, 12 on fanout buffers, and
  the **clock input port itself** at 2.033 ns, because the SDC falls back to an
  `inv_2` for the clock input when `SYNTH_CLK_DRIVING_CELL` is unset. Keep the
  tighter project limit as a deliberate margin, but report against both.
- **Fixed-netlist STA re-check exists.** `./scripts/run_routed_sta.sh RUN
  MIN_DELAY [PERIOD]` re-runs setup and hold on an already routed netlist with
  extracted parasitics under a chosen input minimum delay, over three Liberty
  corners crossed with three SPEF corners. It reproduces `m2-signoff-hold`
  exactly at 3.0 ns, which is what makes it usable as evidence, and it turns a
  constraint question from a 3 h 39 min run into minutes. It also classifies
  each violating path as input-port or register sourced.
- **Extracted-parasitic power is measured.** The final-netlist T=8 run annotates
  284,357 pin activities and reports 23.3 to 33.7 mW, or 5.15 to 7.46 nJ per
  score. It uses nominal SPEF and a 40 ns point that still fails hold, antenna,
  slew, and capacitance checks; it is evidence, not a signoff energy claim.
- **Toolchain.** LibreLane 3.0.14 is installed by
  `scripts/install_librelane.sh` (venv `~/.local/share/fp4-accel/librelane-venv`,
  ciel 2.6.1, Sky130 `8afc8346a57fe1ab7934ba5a6056ea8b43078e71` in `~/.ciel`,
  image `ghcr.io/librelane/librelane:3.0.14`). Its smoke test passes. The old
  OpenLane 1.1.1 image stays for reproducing recorded results.
- **Uncommitted.** Nothing after the M1 closeout commit.
- **M1 scale-format decision is made.** [ADR 0008](docs/adr/0008-e4m3-block-scales.md)
  selects searched E4M3 block scales: better than FP32 on every softmax metric
  across all four captures **and** 4.89x smaller in the mapped scaling path,
  with a quarter of the scale storage. E8M0 is 13.83x smaller but costs 2.34
  points of top-1, so it is rejected and the reopening condition is recorded.
  The RTL change lands with the M2 accumulator rework, as protocol version 7.
- **M1 preprocessing is measured.** K channel-mean centering and normalized
  Hadamard rotation have mixed capture-level effects. Neither improves KL, TV,
  top-1, and top-5 together across all four captures, so neither becomes the
  default. The 32-row record is machine-checked.
- **M1 element-format selection is measured.** Reconstruction-selected FP4 or
  INT4 blocks improve mean KL, TV, top-5, and Frobenius error, but lose 0.34
  top-1 points and regress on the larger-model capture. The result supports a
  layer-selective P1 mode, not a global default.
- **M1 accumulation order is settled.** A balanced tree changes up to 29.4% of
  score bit patterns but no top-k result and at most `1.53e-5` per score. M2
  keeps sequential order to preserve the bit-exact contract.
- **M1 exponent-bound opportunity is measured.** At a four-logit margin, a
  conservative sign-and-exponent bound safely identifies 28.83% of scores and
  8.66% of complete 4x4 BERT tiles on average, with no top-k change. It requires
  a row maximum and does not identify a complete tile in either decoder head.
- **M1 decoder validation is pinned.** Two post-RoPE SmolLM2-135M heads at
  `D_HEAD=64` retain searched E4M3's aggregate advantage. Preprocessing and
  adaptive FP4/INT4 remain layer-dependent. The exponent bound covers no whole
  4x4 decoder tile at tau=4, so it is not a general P0 feature.
- **M1 multiplier structure is settled.** [ADR 0009](docs/adr/0009-use-e2m1-shift-add-products.md)
  selects an exact E2M1 shift/add product. It is formally equivalent to the
  current integer product and maps 56.24% smaller in the standalone probe. A
  same-flow complete-top comparison saves 3,313 cells but only 0.046% area, so
  the standalone area projection is rejected. The
  archived ROM is smaller in isolation but emits FP32 and excludes reduction
  cost. The selected expression is active in `qkt_engine`; all large and RTL
  precision suites retain identical scores and cycles.
- **M0 is complete.** The gate run finished after the handoff was written:
  LibreLane took the `D_HEAD=4` configuration RTL to GDS with zero DRC, zero
  LVS, and **zero antenna violations**, then stopped correctly at the hold
  checker (setup -2.03 ns, hold -0.06 ns at the slow corner, 20 ns). Recorded
  in `docs/results/physical-design.md`. Its 18.6 mW power number is **not**
  usable: no switching activity was annotated.
- **The prior-art gate is satisfied.** All nine cited papers have been read in
  full; three did not match their abstracts. Only three report synthesized
  hardware, none in an open PDK. `docs/related-work.md` states plainly what this
  project can and cannot claim, so results may now be positioned against it.
  Per-block FP4/INT4 is **not** a novelty track: MixFP4 publishes the mechanism,
  the scale-sign-bit encoding, and the tensor-core area.
- **Annotated power is reproducible.** `make gate-power RUN=<librelane run>`
  simulates a routed netlist at gate level and reports per-corner power with
  activity annotated, refusing to print a number when nothing annotates.
- **Setup closes; hold does not.** The `m2-signoff-40ns` run reached post-route
  STA with extracted parasitics before the session ended. Detailed routing
  finished with **0 violations**, DRC passed, antennas are 4 nets and 4 pins, and
  **setup passes at all nine corners**: worst +9.8463 ns at 40 ns, a routed
  setup-limited minimum period of **30.15 ns**. **Hold fails at the slow corner
  at -1.6856 ns.** Recorded in `docs/results/physical-design.md` and
  `docs/results/data/m2-signoff-40ns.csv`. The run stopped before Magic and
  KLayout DRC, LVS, and GDS, so the M2 gate is **not** met.
- **In flight, relaunched 2026-10-01 after a toolchain repair.** `m2-signoff-hold`, the
  hold-margin signoff run described below. It survives the session that launched
  it. Check `build/m2-signoff-hold.out`,
  `build/librelane/m2-signoff-hold/pnr.log`, and whether
  `build/librelane/m2-signoff-hold/runs/pnr/final/` exists. If it reached GDS,
  record DRC, LVS, antenna, and nine-corner timing, then run
  `make gate-power RUN=m2-signoff-hold` for an SPEF-backed power number. If it
  died, re-launch it:

  ```
  PL_RESIZER_HOLD_SLACK_MARGIN=0.3 GRT_RESIZER_HOLD_SLACK_MARGIN=0.3 \
  PL_RESIZER_SETUP_SLACK_MARGIN=0.1 GRT_RESIZER_SETUP_SLACK_MARGIN=0.05 \
  SYNTH_CLOCK_PERIOD=8 ./scripts/run_librelane.sh m2-signoff-hold 40 full
  ```

  Hold failures are period-independent, so a slower clock will not help. The
  global-route checkpoint passed hold at +0.4007 ns with repair off, so enabling
  setup repair introduced these paths.
- **E4M3 is selectable end to end.** `SCALE_FORMAT=1` on the top is protocol
  version 7, or 8 with K reuse, and passes every integration suite with each
  score bit-exact against a single-rounding reference, including T=512,
  `ENGINES=8`, and K reuse. Default stays `SCALE_FORMAT=0` and is unchanged.
  Lint covers fourteen sets, three of them E4M3.
- **ADR 0008's area claim is corrected.** Integrated, E4M3 is **10.9% fewer
  cells but only 0.12% less area**, not 4.89x. The probe number does not
  transfer, exactly as ADR 0009 found for the multiplier: the removed cells are
  small combinational ones and mapped area is dominated by flops. **`sq` and
  `sk` are still 32-bit**, so the four-times scale-storage saving is unrealized
  and that is where the area should come from. Accuracy, exactness, and three
  fewer cycles are all confirmed.
- **Exact next step after that: narrow the scale storage.** This is the step
  that pays for E4M3 in area. Change `sq` and `sk` in
  `rtl/top/qkt_chiplet_top.sv` from `logic [31:0]` to one byte when
  `SCALE_FORMAT=1`, and pack eight scales per 64-bit beat in `FE_SCALES`
  instead of two. That changes the input-beat count, so
  `scripts/cycle_model.py` and the testbench's scale sender move with it, and
  the recorded E4M3 beat counts change. At `T_MAX=16` it frees 3,072 flops; the
  saving scales with `T_MAX`, and flops are what dominates mapped area here.
  Expect the cycle model's recorded E4M3 rows to need regenerating, not the
  FP32 ones.
- **Then, separately.** Decide whether E4M3 becomes the *default*. It is not
  yet, deliberately: every recorded result is FP32, so flipping the default
  invalidates them all at once. Do it only after the storage narrowing is
  measured, and regenerate the recorded cycle and precision rows in the same
  commit.


### Gotchas

- **The LibreLane venv breaks when the system python upgrades.** This machine
  moved from python3.12 to 3.14, which left the venv's interpreter symlink
  dangling, and every run failed with "No such file or directory" even though
  `ls` showed the file. `scripts/install_librelane.sh` now builds the venv
  against a uv-managed interpreter and repairs it when re-run; run it first if
  any LibreLane command fails that way.

- OpenLane's Yosys 0.38 rejects `automatic` variables inside procedural blocks,
  though Verilator accepts them. Use module-level signals.
- `SYNTH_SIZING` does nothing in OpenLane 1.1.1 when `SYNTH_BUFFERING` is 1.
- Single synthesis runs move by about 0.5 ns at the slow corner for reasons
  unrelated to the edit. Do not read smaller deltas as significant.
- Verilator 5 evaluates the RTL `assert property` checks by default, so the
  integration suites really do check them.
- `run_physical.sh` mounts the working tree into the container, so never edit
  `rtl/` or the script itself while a physical run or sweep is going.
- The bash auto-approval classifier sometimes fails on long heredoc commands;
  writing a file with the editor tool and running a short command works.

## Picking this up

### 1. M0 is done; start at M1

The gate run finished and is recorded. The toolchain takes this design RTL to
GDS, and LibreLane's detailed-route antenna repair removed the antenna
violations that every OpenLane 1.1.1 route carried. Timing was not the gate and
was not met, at a toy `D_HEAD=4`.

### 2. M1, in this order

The scale-format question is closed by [ADR 0008](docs/adr/0008-e4m3-block-scales.md).
What is left, all in `scripts/eval_precision.py` behind new flags, following
the `--scale-study` pattern so committed record shapes never change:

1. **Softmax-invariant preprocessing.** K channel-mean centering, and Hadamard
   rotation of Q and K. Both leave `QK^T` unchanged in exact arithmetic, so
   they are free accuracy if they help FP4. Measure on the four captures.
2. **Per-block FP4 or INT4**, selected by reconstruction error, which is
   novelty track 2. INT4 products reach 64 against FP4's 144, so both fit the
   existing 13-bit Bs=16 accumulator.
3. **Sequential versus tree cross-block accumulation.** M2 needs sequential;
   measure the difference now and redefine the reference if it moves.
4. **Exponent-only score bound** for novelty track 4: what fraction of scores
   and whole tiles fall below `rowmax - tau`, and what skipping them costs in
   softmax agreement.
5. **Two modern decoder captures** with `D_HEAD=64` through
   `scripts/capture_transformer_qk.py`, in an isolated uv environment, pinned
   revision and SHA-256 recorded.
6. **Multiplier cost probe**, the same shape as `rtl/probe/scaler_probe.sv`:
   the current decode-and-multiply against an exact shift-add E2M1 multiplier
   (products are `{1,3} x 2^e`) against the product ROM in
   `archive/superseded-rtl/fp4_mul_lut.sv`. That is novelty track 3.

Each of 1 to 5 is one commit with a results-record update; 6 ends in an ADR.

### 3. Then M2, the first routed milestone

Block-streaming accumulator plus the ADR 0008 scaler, then route in LibreLane
and get the project's first valid dynamic power number. See
[the roadmap](docs/project-status.md#roadmap-milestones-m0-to-m4).

## Handoff log

Newest first. Keep the last six to eight entries here, whichever keeps this
file under 24 KB, and move older ones to
[docs/handoff-log.md](docs/handoff-log.md).

### 2026-10-01 — Claude (Opus 5) — hold diagnosed: an input-delay constraint

**Done.** Classified the 1,838 hold failures the previous session left open
rather than raising margins again, as that handoff asked. **Every violating
path starts at an input port and none is register to register**, concentrated on
`s_tdata` (813), `wdata` (91), `s_tvalid` (34), and `awaddr` (33). The SDC
constrained data inputs to a 3.0 ns minimum delay referenced to the clock
source while the capture edge arrives through 4.90 to 5.98 ns of propagated
clock-tree insertion delay at the slow corner. The worst path arrives at
4.187 ns against a 6.085 ns requirement. The interface model was wrong, not the
logic, which is why larger placement hold margins moved worst slack from
-1.6856 to -1.8979 ns.

**Measured, on the frozen `m2-signoff-hold` netlist.** Hold slack tracks the
minimum input delay one for one, so it closes at all nine corners at and above
4.898 ns: -1.8979 ns and 1,838 endpoints at 3.0 ns, +0.1021 ns and zero at
5.0 ns, +0.2684 ns and zero at 6.0 ns. At 6.0 ns the worst hold slack equals
the register-to-register figure at every corner, so input paths are no longer
the critical hold class and more buys nothing. **Worst setup slack is
+9.4961 ns at every value**, as the maximum input delay is a separate
constraint. Rows in `docs/results/data/m2-hold-input-delay.csv`.

**Changed.** `config/librelane/qkt_chiplet_top/constraints.sdc` defaults the
input minimum delay to 6.0 ns, with the reasoning at the constraint, an
`IO_MIN_DELAY_CONSTRAINT` override for the STA harness, and a guard that
refuses a minimum above the 8.0 ns maximum rather than signing off against
contradictory constraints. The OpenLane 1.1.1 SDC is untouched at 3.0 ns so
recorded results stay reproducible. `IO_MIN_DELAY_CONSTRAINT` is deliberately
not a LibreLane config key, since LibreLane rejects variables it does not know;
the flow uses the default and only the STA harness overrides it.

**Added.** `scripts/run_routed_sta.sh` and `scripts/sta/routed_hold.tcl`
re-check setup and hold on an existing routed netlist with extracted
parasitics, over three Liberty corners crossed with three SPEF corners, and
classify every violating path as input-port or register sourced. At 3.0 ns it
reproduces `m2-signoff-hold` exactly, all nine worst hold and setup slacks,
hold TNS, and the 269/553/1,016 endpoint counts. That is what licenses using it
as evidence; without the agreement it would be a second opinion, not a check.

**Also done, second finding.** Extended the harness to count slew and
capacitance violators and to check against the library's per-pin limits instead
of the project's design-wide ones. It reproduces all eighteen recorded counts
under the project limits first. Against library limits the worst corner has
**272 slew and 23 capacitance** violations rather than 15,977 and 989, and the
typical and fast corners are clean, so 98.3% and 97.7% of the headline counts
are margin against a constraint the project chose. Two independent counting
methods agree on 272. The limit stays; what changes is that the open gate item
is 272 pins and tractable. Rows in `docs/results/data/m2-slew-cap-limits.csv`.

**Verified.** `make test` and `make check-docs` pass. The netlist is untouched,
so the recorded DRC, LVS, and power numbers still stand.

**Next, in order.**
1. **A full run at the new default**, to confirm placement and route hold repair
   given a satisfiable constraint spend no area and leave setup alone. Same
   command as `m2-signoff-hold` but the hold margins can drop back toward 0.05:
   0.3 was compensating for a constraint, and the global-route checkpoint
   already passed hold at +0.4007 ns with repair off.
2. **Slew and capacitance**, now scoped to 272 and 23 pins rather than 15,977
   and 989, because the headline counts were against project constraints
   tighter than the library's. Start at the clock input drive: the SDC assumes
   an `inv_2` drives the clock root, giving the `clk` port a 2.033 ns slew, and
   a stronger `SYNTH_CLK_DRIVING_CELL` should cut both that and the clock
   insertion delay behind the hold failures. Measure it in a full run, since it
   moves the clock tree. Then the 33 repair-inserted `ANTENNA_*` diode pins.
3. **Antenna**, 6 nets and 7 pins, the smallest item.

Nothing is in flight. No long run was launched, deliberately: the owner stopped
the `m2-e4m3-signoff-40ns` route last session and relaunching a multi-hour run
is their call, not mine. That run still has no final state, SPEF, GDS, or
signoff metrics; resume instructions are in the entry below.

### 2026-10-01 — Codex — physical flow accepts scale format

**Done.** Added `SCALE_FORMAT` to LibreLane's synthesized parameter list and
run manifest. A generated configuration with `SCALE_FORMAT=1` contains the
expected parameter, so the routed E4M3 comparison can no longer silently build
the FP32 default.

**Stopped at owner request.** The full routed comparison was run as
`build/librelane/m2-e4m3-signoff-40ns` from revision `86a94ab`:

```text
SCALE_FORMAT=1 PL_RESIZER_HOLD_SLACK_MARGIN=0.3 \
GRT_RESIZER_HOLD_SLACK_MARGIN=0.3 PL_RESIZER_SETUP_SLACK_MARGIN=0.1 \
GRT_RESIZER_SETUP_SLACK_MARGIN=0.05 SYNTH_CLOCK_PERIOD=8 \
./scripts/run_librelane.sh m2-e4m3-signoff-40ns 40 full
```

The process was terminated cleanly when the owner requested a stop. It reached
detailed-routing optimization in step 35 and therefore produced no final state,
SPEF, GDS, or signoff metrics. `pnr.log` ends with `Aborted!`. Resume by rerunning
the exact command above; the script uses `--overwrite`, so it restarts the named
run. After completion, record final metrics and run
`make gate-power RUN=m2-e4m3-signoff-40ns`. Default selection still waits for
timing, area, and signoff evidence.

**Last completed checkpoint.** Synthesis completed in 2 min 29 s. Global route is
complete with zero overflow on every layer, 19.95% aggregate routing use,
4,070,461 um wirelength, 104,575 standard cells, and 723,982 um2 standard-cell
area after CTS hold repair. The flow is in antenna repair: the initial check
found 467 violating nets and 661 pins, then inserted 813 jumpers for 547 nets.
These are intermediate measured values; wait for detailed route and final
signoff before comparing against FP32.

### 2026-10-01 — Codex — packed E4M3 storage and stream

**Done.** Narrowed `sq` and `sk` to eight bits when `SCALE_FORMAT=1`, packed
eight E4M3 values per scale beat, retained two FP32 values per beat, and kept
the 32-bit engine interface by zero extension. Versions 7 and 8 now implement
the contract ADR 0008 selected. Padding, malformed `TLAST`, K reuse, Bs=32,
8x8 L2, and eight-engine cases pass with every score bit-exact.

**Measured.** T=512 v7 falls from 1,050,687 to 1,049,151 cycles and from 266,240
FP32-format beats to 264,704 packed beats. Eight engines take 264,799 cycles.
The cycle model reproduces all 44 recorded configurations. Same-flow synthesis
measures 40,892 cells and 140,592.34 um2 against FP32's 52,764 cells and
257,346.82 um2, a 45.37% wire-free area reduction. Default selection remains a
separate routed decision; FP32 is still the default.

**Verified.** `make test`, all 14 lint configurations, 41 model tests, scaler
unit checks, directed E4M3/Bs=32 tests, large v7/v8 and 8x8 suites, and the
eight-engine T=512 suite pass.

### 2026-10-01 — Codex — full M2 signoff outcome and SPEF-aware power

**Done.** Took ownership of Claude's `m2-signoff-hold` run and carried it through
all 80 LibreLane stages. The run produces final GDS and SPEF; setup passes at
+9.4961 ns worst slack, all three DRC checks are zero, and LVS passes. It still
does not close: hold is -1.8979 ns over 1,838 slow-corner endpoints, antenna is
6 nets/7 pins, and worst-corner slew/capacitance counts are 15,977/989.
Register-to-register hold passes at +0.2684 ns, so the next hold investigation
must classify the remaining path type instead of only increasing repair margin.

**Power correction.** `run_gate_power.sh` did not find LibreLane 3's nested
`final/spef/nom/` path and silently ran without SPEF. The glob now searches the
tree. The rerun annotates 284,357 pins and gives 23.3 to 33.7 mW, or 5.15 to
7.46 nJ per score for the 354-cycle T=8 command at 40 ns. Results are in
`docs/results/data/m2-signoff-hold.csv`; large run outputs remain ignored.

**Next.** One-byte E4M3 scale storage and eight packed scale bytes per beat are
implemented and passing in the isolated `codex/e4pack` worktree; integrate it
after this physical-result commit.

### 2026-10-01 — Codex — received E4M3 and signoff handoff

**Started.** Confirmed clean synchronized `master` at `2b7fe73`, read Claude's
E4M3 implementation and corrected integrated-area result, and claimed the
in-flight `m2-signoff-hold` run. It is still active in detailed routing. The
next code task after recording that result is one-byte E4M3 scale storage and
eight scales per input beat, with protocol, model, tests, and measured records
updated together.

### 2026-10-01 — Claude (Opus 5) — E4M3 selectable end to end; area claim corrected

**Done, in a one-hour window the owner set.** `SCALE_FORMAT` is plumbed through
the top and engine, so E4M3 block scales are now selectable in the real design
as protocol version 7, or 8 with K reuse.

- Every integration suite passes with E4M3, each score **bit-exact** against a
  single-rounding reference: the directed suites, T=512, `ENGINES=8`, and K
  reuse. The testbench carries E4M3 codes on the wire and rounds once per block
  rather than twice, matching the hardware.
- Two new assertions check ADR 0008's exactness argument rather than asserting
  it in prose: the six product bits the path discards are always zero, and the
  conversion leaves enough headroom. They fail loudly if `ACC_W` grows past 17,
  which P1's 43-bit FP8 accumulator would do.
- Lint covers fourteen parameter sets, three E4M3. Default `SCALE_FORMAT=0` is
  untouched: `make test`, 32 of 32 cycle configurations, and the T=512
  precision run all reproduce exactly.

**The finding that matters, and it is a correction.** Integrated, E4M3 gives
**10.9% fewer cells but only 0.12% less area**, against the standalone probe's
4.89x. ADR 0008, the precision record, and the results index now say so. The
cause is the same one ADR 0009 recorded for the multiplier, and I should have
expected it: the probe removes small combinational cells while mapped area here
is dominated by flip-flops. **`sq` and `sk` are still 32 bits wide**, so the
four-times scale-storage saving the ADR claims has not actually been taken yet.
That is the next step and it is where the area is.

**What survives unchanged:** better accuracy on every softmax metric across six
pinned heads, exact scale application where FP32 rounds twice, and three fewer
cycles per command.

**In flight.** The `m2-signoff-hold` run from the previous session was still in
place-and-route when this session ended; see the state above for how to check
it. It was launched from the committed RTL before the `SCALE_FORMAT` plumbing,
which does not change `SCALE_FORMAT=0` behavior, so its result is still valid
for the default build.

Older entries are in [docs/handoff-log.md](docs/handoff-log.md).
