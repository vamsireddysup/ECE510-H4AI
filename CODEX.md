# Project handoff and agent entry point

This is the single entry point for every coding agent on this repository,
Claude Code and Codex alike. It holds the live project state and the handoff
log. The working rules live in [docs/agent-rules.md](docs/agent-rules.md); read
them before changing anything. There is deliberately no `CLAUDE.md`, and
`AGENTS.md` only points here, so both agents work from one set of rules and one
record of what happened.

Keep this file under about 24 KB. Codex truncates project instructions at
32 KiB by default, so older handoff entries move to
[docs/handoff-log.md](docs/handoff-log.md).

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

Active agent: Codex, 2026-10-01. Owning the in-flight hold-margin signoff run,
then narrowing E4M3 scale storage.

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
- **Full M2 signoff now runs to completion but does not close.** At 40 ns,
  nine-corner setup passes with +9.4961 ns worst slack, detailed-route, Magic,
  and KLayout DRC are zero, and LVS passes. Hold fails at -1.8979 ns over 1,838
  endpoints in slow corners; six antenna nets and substantial slew/capacitance
  violations remain. Register-to-register hold passes at +0.2684 ns. See
  `docs/results/physical-design.md`.
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

Newest first. Keep the last eight entries here and move older ones to
[docs/handoff-log.md](docs/handoff-log.md).

### 2026-10-01 — Codex — physical flow accepts scale format

**Done.** Added `SCALE_FORMAT` to LibreLane's synthesized parameter list and
run manifest. A generated configuration with `SCALE_FORMAT=1` contains the
expected parameter, so the routed E4M3 comparison can no longer silently build
the FP32 default.

**In flight.** The full routed comparison is running as
`build/librelane/m2-e4m3-signoff-40ns` from revision `86a94ab`:

```text
SCALE_FORMAT=1 PL_RESIZER_HOLD_SLACK_MARGIN=0.3 \
GRT_RESIZER_HOLD_SLACK_MARGIN=0.3 PL_RESIZER_SETUP_SLACK_MARGIN=0.1 \
GRT_RESIZER_SETUP_SLACK_MARGIN=0.05 SYNTH_CLOCK_PERIOD=8 \
./scripts/run_librelane.sh m2-e4m3-signoff-40ns 40 full
```

Check `synth.log`, then `pnr.log`; record the final metrics and rerun
`make gate-power RUN=m2-e4m3-signoff-40ns` if final SPEF is produced. Default
selection waits for timing, area, and signoff evidence from this run.

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

### 2026-10-01 — Claude (Opus 5) — E4M3 scale path landed, first unit check

**Done, in a 30-minute window the owner set.**

- `rtl/core/score_scaler.sv` gains `SCALE_FORMAT`. 0 is the default FP32 path
  and is **bit-identical and cycle-identical** to the two-multiplier design:
  eleven lint sets, `make test`, both T=512 protocols at 1,050,690 and
  1,052,722 cycles, **32 of 32** recorded cycle configurations, and the T=512
  precision run at `ENGINES` 1 and 8 all reproduce exactly. 1 is the ADR 0008
  E4M3 path: one narrow significand multiply, 3 scale cycles rather than 6, and
  exact because the product fits FP32's significand for `ACC_W <= 17`.
  **Nothing selects it yet**, by design, so this commit cannot change a result.
- `tb/unit/tb_score_scaler.cpp` and `make test-unit` are the first `tb/unit`
  check. FP32 must reproduce two chained single-precision roundings and E4M3
  must be exact; 4,000 random pairs each against a double-precision reference,
  both 0 mismatches. It runs inside `make test`. The verification plan's "there
  are no unit tests" gap is rewritten rather than deleted, because every other
  arithmetic block is still covered only through the full top.

**Why the unit check mattered.** The E4M3 path was verified last session in a
scratchpad that did not survive, so the RTL would have entered the tree with no
standing evidence. Landing the check first means the next agent can change it
and know immediately whether it still holds.

**Next, in order.** Finish the in-flight `m2-signoff-hold` run and record it.
Then switch the default to `SCALE_FORMAT=1` as protocol version 7, which is the
step that **does** change results: scores change because the path is exact where
the old one rounded twice, `SCALE_PIPELINE_LATENCY` in
`scripts/cycle_model.py` goes from 7 to 4, scale storage narrows to one byte,
and the scale packet carries eight scales per beat instead of two. The RTL,
model, testbench, and cycle model must move in one commit. Power says why it is
worth doing: the clock tree and sequential cells are five sixths of total power,
and E4M3 removes flops as well as multiplier area.

### 2026-09-30 — Claude (Opus 5) — signoff reaches extraction; session end

**Stopped** because the owner is handing over to Codex. The tree is clean and
everything is pushed; `make test` passes. Nothing is half-finished in the
repository.

**Done.** The `m2-signoff-40ns` run was killed by the session ending, but it had
already gone much further than the previous checkpoint, so its results are
recorded rather than discarded: detailed routing **0 violations**, DRC checker
passed, antennas 4 nets and 4 pins, longest net 1,795.89 um, RCX extraction
complete with a 123 MB nominal SPEF, and nine-corner post-route STA.

**The headline.** With timing repair enabled and extracted parasitics,
**setup closes at every corner**, worst +9.8463 ns at 40 ns, which is a routed
setup-limited minimum period of **30.15 ns**. **Hold fails at the slow corner at
-1.6856 ns**, while typical and fast pass. The global-route checkpoint passed
hold at +0.4007 ns with repair off, so enabling setup repair introduced these
paths: an ordinary setup-versus-hold trade, fixable with larger hold margins,
not a structural problem. Because the run stopped before Magic and KLayout DRC,
LVS, and GDS, **the M2 gate is not met**.

**Everything this session, in order.** Verified Codex's M1 and M2 handoff
independently, 32 of 32 cycle configurations exact. Resumed the interrupted
checkpoint and got the **first congestion-free route**, zero overflow on every
metal layer. Completed the **full-text prior-art review** of all nine cited
papers, of which three did not match their abstracts, which cost us the
per-block FP4/INT4 novelty track. Found and recorded that **E4M3 scale
application is exact**. Built the gate-level power path and produced the
project's **first valid power number**, 18.6 to 26.8 mW and 4.12 to 5.93 nJ per
score with 257,686 annotated pin activities. Rotated the handoff log.

**Left ready but not integrated.** A verified E4M3 `score_scaler` drop-in exists
outside `rtl/`; see the note above for where and what it changes.

### 2026-09-29 — Claude (Opus 5) — first valid power number

**Done.** Built the missing half of M2's deliverable:
`scripts/gen_gate_stimulus.py`, `tb/gate/tb_gate_power.v`, and
`scripts/sta/annotated_power.tcl`. A gate-level Icarus run of the routed
netlist passes (128 input and 32 output beats) and dumps a 72 MB VCD; OpenSTA
annotates **257,686 pin activities** and reports 18.6 to 26.8 mW across the
three corners, 4.12 to 5.93 nJ per score for the 354-cycle T=8 command.
Recorded in `docs/results/physical-design.md` and
`docs/results/data/m2-annotated-power.csv`.

**The trap, worth knowing.** OpenSTA separates VCD hierarchy with **`/`**, not
`.`. With `tb_gate_power.dut` it printed "Annotated 0 pin activities" and then
reported a perfectly plausible 21.2 mW that was pure default-toggle guesswork.
`tb_gate_power/dut` annotates 257,686. `annotated_power.tcl` now exits non-zero
when nothing annotates, so that failure cannot be published again.

**What the number says.** The clock tree is a third of total power at every
corner and sequential cells about half, so state and clocking dominate, not
arithmetic. That points at the E4M3 scaler, which removes flops as well as
multiplier area, and at replication, which amortizes one clock tree.

**Limits.** Global-route netlist **without SPEF**, one T=8 command rather than
T=512, and 40 ns rather than a timing-closed period.

### 2026-09-29 — Claude (Opus 5) — prior-art gate satisfied; E4M3 exactness

**Done.** Finished the full-text review of all nine cited papers, extracting
each with `pdftotext` locally because the fetcher cannot decompress arXiv PDFs.
Three of nine did not match their abstracts, and two of those corrections
narrowed the project's claims. `docs/related-work.md` now records the
corrections, what the project can claim, and what it must not.

**Found while planning the E4M3 RTL, and worth more than the review.** E4M3
block scales **apply exactly**. A Bs=16 accumulator is 13 bits, so at most 12
significant bits; two E4M3 significands add 4 bits each; 20 bits fits FP32's
24. Measured: 0 of 60,000 random triples need rounding with E4M3 against 59,990
with FP32, which the current design rounds twice. The bound is `ACC_W <= 17`,
met at every supported block size and **not** met by P1's 43-bit FP8
accumulator. This is a third independent argument for ADR 0008, it removes
rounding logic from the scaler, and it makes the software reference a plain
double product rounded once. Recorded in ADR 0008 and the precision record.

**Consequence for the RTL.** E4M3 changes score bits, because the new path is
exact where the old rounded twice. The protocol version 7 bump is therefore a
numerical bump too, and the model and testbench must adopt the exact reference
together with the RTL.

**In flight.** A full signoff run, `m2-signoff-40ns` at 40 ns with timing repair
enabled and setup and hold margins set. Check
`build/librelane/m2-signoff-40ns/pnr.log` and `runs/pnr/final/metrics.json`.

### 2026-09-29 — Claude (Opus 5) — the block-streaming top routes, zero congestion

**Done.** Resumed the interrupted checkpoint;
`SYNTH_CLOCK_PERIOD=8 ./scripts/run_librelane.sh m2-block-stream-grt-30ns 30 global-route`
completed at `8ffc662`. **Zero routing overflow on li1 and met1 through met5**,
27.82% total routing utilization, 118,109 instances, 879,704 um², estimated wire
3,427,020 um, 0 antenna violations with 635 diodes, 0 slew, 0 capacitance, and
hold **+0.4007 ns** at the slow corner. Recorded in
`docs/results/physical-design.md` and `docs/results/data/m2-global-route.csv`.

**Why it matters.** Congestion, caused by the accumulator banks, blocked every
floorplan in P0.7b; `acc_bank` nets were nearly all of the overflow. Streaming
one block at a time removes that array and the 32-to-1 scaler read mux, and the
route is now clean with room to spare. Hold passing and slew and capacitance
being clean also remove the three reasons the old dynamic-power report was
rejected.

**Still open.** Setup misses by 9.94 ns at 30 ns, so the slow-corner minimum
period is 39.94 ns; fast-corner hold is -0.0351 ns. This checkpoint ran with
timing repair **off** and stops after antenna repair, so it is not signoff: no
detailed routing, extraction, DRC, LVS, or power.

**Next.** The ADR 0008 E4M3 scaler, which also shortens the path that now sets
setup timing.

### 2026-09-29 — Claude (Opus 5) — verified the Codex handoff; corrected prior art

**Verified Codex's work independently**, per the cross-agent rule. `make test`
passes and `scripts/check_cycle_model.py` re-simulates **32 of 32** recorded
configurations exactly on the block-streaming RTL at `bb85cde`. The M1 and M2
claims in this file hold.

**Done.** Full-text review of the two nearest papers, extracted locally with
`pdftotext` because the fetcher could not decompress them. It corrected three
things the abstract-level page had wrong, all recorded in
`docs/related-work.md`:

- Shift-Accumulate Attention's product is **exact** with respect to its
  quantized operands, not approximate. It changes the key format to signed
  power-of-two to get shifts, costing +0.15 perplexity against INT8, and has
  **no ASIC**: CUDA kernels plus a cost model for a hypothetical `DS4A`
  instruction. Our E2M1 shift-add needs no format change and is measured in
  Sky130, which is the real distinction.
- It **does** report attention-distribution KL and top-8 overlap, so
  softmax-metric evaluation is not a differentiator for us.
- MixFP4 covers **activations**, reports **3.1% tensor-core area and 1.5%
  power**, selects FP4-or-INT4 by a crest factor with a 2.224 threshold, and
  encodes the flag in the **sign bit of the E4M3 block scale**. Novelty track 2
  is therefore largely published, which agrees with the M1 measurement that
  adaptive selection loses top-1 and regresses on the larger capture.

**Verified.** `make test` passes; 39 documentation files check.

**In flight.** The resumed `m2-block-stream-grt-30ns` global-route run; see
the entry below for how to check it.

Older entries are in [docs/handoff-log.md](docs/handoff-log.md).
