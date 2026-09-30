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

Active agent: Claude (Opus 5), 2026-09-29. Verifying the M1 and M2 handoff,
then resuming the stopped M2 physical checkpoint.

## Current state

Updated 2026-09-29 by Codex.

- **Branch and commit.** `master`, pushed to
  `vamsireddysup/FP4-transformer-attention-accelerator`. CI and `make test`
  pass.
- **Last integrated synthesis.** The M2 block-streaming 4x4 top at `bb85cde`
  maps to 53,137 cells and 257,922.37 um2. The pre-M2 shift/add checkpoint was
  82,388 cells and 257,530.74 um2 in the same wire-free flow.
- **Active plan.** The research-backed roadmap, milestones M0 to M4, is in
  [docs/project-status.md](docs/project-status.md#roadmap-milestones-m0-to-m4).
  M0 and M1 are complete. The next milestone is **M2, P0 physical closure**.
- **Where the design is.** 4x4 FP4 QK^T engine with 1x16 FP32 block scales,
  exact integer block accumulation, `ENGINES` replication (1 to 16), protocol
  versions 5 and 6 by default. All 32 recorded cycle configurations re-simulate
  exactly (`python3 scripts/check_cycle_model.py`).
- **Best timing evidence.** Mapped netlist, `DELAY 0` at an 8 ns target, no
  wires: 18.241 ns slow-corner and 8.998 ns typical-corner minimum period at
  `34d9df5`. This is not a routed or closing frequency.
- **The congestion blocker is cleared.** The M2 block-streaming top completes
  global routing with **zero overflow on every metal layer**, zero antenna, zero
  slew, and zero capacitance violations, and hold passes at the slow corner at
  **+0.4007 ns** against -1.2765 ns before. Recorded in
  `docs/results/physical-design.md`. What remains is frequency: setup misses by
  9.94 ns at 30 ns, so the slow-corner minimum period is 39.94 ns.
- **The first valid power number exists.** 18.6 to 26.8 mW across three corners
  and 4.12 to 5.93 nJ per score, from a gate-level VCD with 257,686 pin
  activities annotated. The clock tree is 33% of total power and sequential
  cells about half, so this design is dominated by state and clocking, not
  arithmetic. Caveats: global-route netlist without SPEF, one T=8 command, and
  40 ns rather than a closed period.
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
- **Superseded note, kept for the record.** The earlier entry below said only
  the two nearest papers were reviewed.
  [docs/related-work.md](docs/related-work.md) now carries a full-text review
  and corrects three claims the abstract-level version got wrong. Net effect:
  per-block FP4/INT4 is **not** a strong novelty track, since MixFP4 already
  publishes the mechanism, the scale-sign-bit encoding, and 3.1% tensor-core
  area; and softmax-metric evaluation is table stakes, not a differentiator.
  What survives is the open-PDK priced co-design, the maintained bit-exactness,
  and the specific finding that searched E4M3 is both more accurate and 4.89x
  smaller than FP32 scales.
- **Annotated power is reproducible.** `make gate-power RUN=<librelane run>`
  simulates a routed netlist at gate level and reports per-corner power with
  activity annotated, refusing to print a number when nothing annotates.
- **In flight.** `m2-signoff-40ns`, a full signoff run at 40 ns with timing
  repair enabled and margins set, in detailed routing for over an hour. Check
  `build/m2-signoff.out` and `build/librelane/m2-signoff-40ns/pnr.log`. When it
  finishes: record DRC, LVS, antenna, slew, and per-corner setup and hold, then
  re-run `make gate-power RUN=m2-signoff-40ns` so the power number carries
  extracted SPEF parasitics rather than estimated wires.
- **Exact next step after that.** Replace the FP32 scale path with the ADR 0008
  searched-E4M3 scaler as protocol version 7. A verified drop-in already exists:
  the scaler in the scratchpad adds a `SCALE_FORMAT` parameter, keeps the FP32
  path bit-identical (3,000 cases checked) and is bit-exact in E4M3 (4,000
  cases). Its E4M3 latency is 3 cycles against 6, so `SCALE_PIPELINE_LATENCY` in
  `scripts/cycle_model.py` goes from 7 to 4 and the recorded cycle counts move.
  Scores change too, because the new path is exact where the old rounded twice,
  so the model and testbench must adopt the exact reference together with the
  RTL. Power says why it is worth doing: the clock tree and sequential cells are
  five sixths of total power, and E4M3 removes flops as well as multiplier area.

### Gotchas

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

### 2026-09-29 — Codex — M2 physical checkpoint stopped for handoff

**Stopped cleanly at the owner's five-minute boundary.** Same-flow wire-free
synthesis maps `bb85cde` to 53,137 cells and 257,922.37 um2: 29,251 fewer cells
than pre-M2, with area 0.15% higher because the FP32 adder remains. A LibreLane
3.0.14 run completed synthesis, global placement, repair, and detailed
placement, then was interrupted during CTS. Pre-CTS minimum period is 45.41 ns;
there is no routing or signoff result yet.

**Resume.** Evidence is in ignored
`build/librelane/m2-block-stream-grt-30ns/`. Re-run
`SYNTH_CLOCK_PERIOD=8 ./scripts/run_librelane.sh m2-block-stream-grt-30ns 30 global-route`
for a clean completed checkpoint. The values already obtained are committed in
`docs/results/data/m2-block-stream-checkpoint.csv`. All RTL verification was
completed and pushed in `bb85cde`; only documentation from this physical
checkpoint is in the handoff commit.

### 2026-09-29 — Codex — M2 block streaming implemented

**Done.** Replaced two tile-by-block accumulator banks with two single-block
ping-pong banks. Completed blocks stream through one set of score lanes, and a
partial-score array plus FP32 adder preserves left-to-right block rounding.
The 4x4 T=512 default improves by six cycles to 1,050,690 with every score bit
unchanged. Wider arrays now expose the real per-block scaling cost: 8x8 L2 is
526,458 cycles and 16x16 L4 is 264,474.

**Verification.** Eleven lint configurations and directed plus large integration
suites pass. The updated cycle model exactly reproduces all 32 recorded
configurations. Next map and route this structural checkpoint, then integrate
the ADR 0008 E4M3 scaler.

### 2026-09-29 — Codex — M2 block-streaming start

**Started.** Confirmed clean synchronized `master` at `df6edb1`, read the shared
handoff and active dataflow, and claimed the lock. The atomic task removes the
tile-wide block accumulator read mux while preserving score bits, protocol, and
recorded cycles unless a measured pipeline dependency requires a model update.

### 2026-09-29 — Codex — integrated multiplier checkpoint

**Done.** Fixed `run_synthesis.sh` path quoting and mapped the 4x4 complete top
on both sides of the shift/add change. Generic multiplication maps to 85,701
cells and 257,649.61 um2; shift/add maps to 82,388 cells and 257,530.74 um2.
The 3,313-cell reduction survives, while the standalone area projection does
not: full-top area improves only 0.046%.

**Verification.** Both rows use the same Yosys, Sky130 library, parameters, and
wire-free flow. Next is the block-streaming accumulator and a routed congestion
measurement.

Older entries are in [docs/handoff-log.md](docs/handoff-log.md).
