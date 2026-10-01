# Handoff log archive

This holds handoff entries that have rotated out of the root `CODEX.md`, which
keeps only the newest eight so Codex never truncates it. Entries are newest
first and keep the format described in the session protocol there.

## Archived entries

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

### 2026-09-29 — Codex — M2 shift-add integration

**Done.** Replaced every active generic FP4 multiply with the ADR 0009 exact
E2M1 exponent/shift/add expression. This is a structural substitution only;
the signed half-unit product and quarter-unit accumulator contracts do not
change.

**Verification.** `make test`, T=64/128/512 integration, and T=512 RTL
precision all pass. Every score and cycle count is unchanged. Next is the
block-streaming accumulator that removes the routed congestion source.

### 2026-09-29 — Codex — M1 complete, multiplier decision

**Done.** ADR 0009 selects the exact E2M1 shift/add product for the M2 rewrite.
It maps to 59 cells and 381.62 um2 against 127 cells and 872.09 um2 for the
current generic integer multiply. The archived FP32 ROM is 228.97 um2 but does
not include the FP32 reduction or conversion needed to replace the integer
contract. M1 is complete.

**Verification.** Yosys SAT covers all 256 input pairs. The result record pins
revision, Yosys, PDK, and library provenance. Next is M2's integrated rewrite
and physical closure gate.

### 2026-09-29 — Codex — M1 multiplier probe implementation

**Done.** Added an isolated three-way FP4 multiplier probe and runner. Yosys SAT
proves the E2M1 shift/add result equals the current decode/multiply result for
all 256 input pairs. Same-library mapping measures 872.09 um2 for the current
integer path, 381.62 um2 for shift/add, and 228.97 um2 for the archived FP32
product ROM. The ROM has a different output and accumulation contract.

**Verification.** The probe reruns successfully with Yosys 0.44 and Sky130 HD,
and Verilator lint passes. Next is the reviewed result record and decision ADR.

### 2026-09-29 — Codex — M1 decoder validation

**Done.** Extended the deterministic capture tool to BERT, OPT, and post-RoPE
Llama Q/K, then pinned first- and last-layer SmolLM2-135M heads at 512x64. A
44-row record reruns every M1 arithmetic study. Searched E4M3 retains better
decoder-mean metrics than FP32 and E8M0. Preprocessing and adaptive FP4/INT4
remain layer-dependent. The exponent bound covers no complete decoder tile at
tau=4.

**Verification.** The model suite checks both capture hashes and embedded model,
revision, and tool versions, then regenerates all 44 rows. Next is the
three-way multiplier cost probe and its ADR.

### 2026-09-29 — Codex — M1 exponent-bound result

**Done.** Added a conservative score upper bound that keeps operand signs and
power-of-two magnitude intervals but performs no mantissa multiplication. At a
four-logit margin it safely covers 28.83% of scores and 8.66% of 4x4 tiles on
average, removing 0.049% and 0.00011% of probability mass. Top-1 and top-5 are
unchanged, but tile coverage spans zero to 18.38% by capture and a row-maximum
pass is assumed, so no RTL is selected.

**Verification.** The model suite regenerates all 20 rows and asserts bound
safety. Next is two modern decoder captures with `D_HEAD=64`.

### 2026-09-29 — Codex — M1 exponent-bound start

**Started.** Confirmed clean synchronized `master` at `800c2eb`, read the
shared handoff and rules, and claimed the lock. The atomic task measures a
safe exponent-only upper bound, score and whole-tile skip coverage, and the
resulting softmax cost across all four pinned captures.

### 2026-09-29 — Codex — M1 accumulation-order result

**Done.** Added `--accumulation-study` for sequential and balanced-tree FP32
cross-block reduction under FP32 and searched E4M3 scales. Tree order changes
24.5% to 29.4% of score bit patterns but by no more than `1.53e-5`; all top-1
and top-5 results are unchanged and KL moves below `1e-9`. Sequential remains
the M2 reference because it preserves the current bit-exact contract.

**Verification.** The model suite regenerates all 16 rows and capture hashes.
Next is the exponent-only score bound study.

### 2026-09-29 — Codex — repository review handoff

**Stopped cleanly.** Read the tracked repository, fetched and compared the
renamed GitHub remote, reviewed every commit since the prior Codex handoff, and
verified the active architecture, model, flow, results, and Claude handoff.
`make test` passes: 38 documentation files, eleven lint parameter sets, 29 model
tests, and both small integration depths. Local and remote `master` are aligned.

**Next.** M1 item 1: add K channel-mean centering and Hadamard rotation behind
new `scripts/eval_precision.py` flags, measure all four pinned captures, update
the precision record, and include the handoff in the verified commit.

### 2026-09-29 — Codex — session start

**Started.** Fetched `origin`, confirmed local `master` and `origin/master` both
at `0ab7170`, confirmed a clean tree, read the shared handoff and agent rules,
and claimed the lock. The next action is to inspect and record the in-flight M0
LibreLane gate exactly as Claude specified.

### 2026-09-29 — Claude (Opus 5) — M0 gate result, after the session-end entry

**Done.** The M0 gate LibreLane run completed while the handoff was being
written, so its result is recorded rather than left for Codex:
`docs/results/physical-design.md` and
`docs/results/data/m0-gate-librelane-metrics.csv`. RTL to GDS at `D_HEAD=4`,
155,927 instances on a 0.81 mm² die, zero detailed-route, Magic, KLayout, LVS,
and **antenna** violations; stopped at the hold checker with setup -2.0313 ns
and hold -0.0605 ns at the slow corner, plus 5,061 slew and 145 capacitance
violations.

**Why it matters.** Zero antenna violations, against 332 pins and 281 nets on
the best OpenLane 1.1.1 route, where 60% of the slew violators were the repair
diodes themselves. The interaction that made the old dynamic power unusable is
gone. The 18.6 mW the run reports is still not a usable power number: nothing
annotated switching activity. M2's gate-level simulation remains the route to
the first valid one.

**Verified.** `make test` passes; tree clean.

### 2026-09-29 — Claude (Opus 5) — session end, credits

**Stopped** at the owner's request with credits running out. The tree is clean,
everything is pushed to `origin/master` at `4a740f6`, and `make test` passes.
Nothing is half-finished in the repository. The only work in flight is the M0
gate LibreLane run described above, which writes outside the repository.

**This session, in order.** Made `CODEX.md` the shared handoff and added
`AGENTS.md` (`4af41f6`); recorded the stopped F4 floorplan sweep before
deleting its trees (`e89b356`); freed 57 GB and installed a pinned LibreLane
3.0.14 (`eb4d962`); ported the flow to LibreLane and measured the block-scale
formats (`734ee74`); selected searched E4M3 scales in ADR 0008 with both an
accuracy and an area measurement (`cf7b1d8`).

**The result worth carrying forward.** Searched E4M3 block scales are better
than the FP32 default on every softmax metric across all four pinned captures
*and* map to a scaling path 4.89x smaller, at a quarter of the scale storage.
There is no accuracy-for-area trade, which is why ADR 0008 acts on it. That
combination, chosen by softmax fidelity and measured Sky130 cost together, is
the clearest novelty candidate the project has; see
[related work](related-work.md) for what is and is not new, and do not
call it novel in any document until that page's full-text review is done.

**Do not restore any wall-clock speedup claim.** At 135,280 cycles, parity with
one OpenBLAS thread needs 461 MHz and Sky130 will not give it. The claim is
energy and area per score, which is still unmeasured.

### 2026-09-29 — Claude (Opus 5) — ADR 0008, the M1 scale-format gate

**Done.** Measured the cost side of the scale format with
`rtl/probe/scaler_probe.sv` and `scripts/run_scaler_probe.sh`: one score lane's
scaling path per format, mapped to Sky130. FP32 52,280 um²; E4M3 10,695 um²,
4.89x smaller; E8M0 3,780 um², 13.83x smaller. With the accuracy table from the
previous entry this makes the decision one-sided, and ADR 0008 takes searched
E4M3. Also fixed `scripts/run_synthesis.sh`, which still hardcoded a file list
without `qkt_engine.sv` and so could not have run.

**Verified.** Both narrow probe variants are bit-exact against a
double-precision reference over 539 accumulator and scale combinations each;
the first version of the probe was wrong and the test caught it. `make test`
passes.

**Gotchas.** Yosys `stat` reports area per module, so a hierarchical read
undercounts: the FP32 variant's two `fp32_mul` instances were missing until the
script added `-flatten`. Any area number from `stat` needs flattening or
explicit summing.

### 2026-09-29 — Claude (Opus 5.5) — M0 step 4 and first M1 result

**Done.** Ported the flow to LibreLane: `config/librelane/qkt_chiplet_top/`
(config plus SDC), `scripts/librelane_config.py`, and
`scripts/run_librelane.sh`. Added the block-scale format study to
`scripts/eval_precision.py` and recorded it in `docs/results/precision.md` and
`docs/results/data/scale-format-study.csv`.

**Verified.** `make test` passes. The study quantizer reproduces the committed
FP32 path bit-for-bit, checked directly. LibreLane synthesis of the real design
completes (30,122 cells at `D_HEAD=4`).

**Gotchas found the hard way.**

- **ABC splits Yosys's scripts on whitespace, and this repository's path has
  spaces in it.** Synthesis fails with `Cannot open file "/home/.../PSU"`.
  `run_librelane.sh` therefore points the tools at a space-free symlink,
  `~/.local/share/fp4-accel/repo`, and `librelane_config.py --root` refuses a
  path with spaces. Anything new that hands a path to the tools must use
  `tool_root`, not `repo_root`.
- LibreLane lints the PDK blackbox models with Verilator by default and one
  Sky130 UDP fails to resolve, so `RUN_LINTER` is false in the config; `make
  lint` already covers the RTL over eleven parameter sets.
- `--with-initial-state` needs the last *numbered* step directory. A plain
  `ls | tail -1` picks `tmp/` and the run dies immediately.

### 2026-09-29 — Claude (Opus 5.5) — M0 steps 2 and 3

**Done.** Deleted every old `build/physical` tree (57 GB) as the owner
approved; the reviewed numbers were already in `docs/results/data/`. Stopped a
leaked memory-sampler loop left from the F4 pilot. Installed LibreLane with a
pinned, re-runnable installer. Disk is now 47% used.

**Verified.** `librelane --docker-no-tty --dockerized --smoke-test` prints
"Smoke test passed". Log in `build/librelane-smoke.log`.

**Gotchas.**

- LibreLane 3.0.14 requires `ciel>=2.3.1,<3`; ciel 3.0.0 does not install.
- Non-interactive shells need `--docker-no-tty` before `--dockerized`, or the
  container fails with "cannot attach stdin to a TTY-enabled container".
- LibreLane mounts `$HOME` at the same path, so the container sees this repo at
  its real path, which contains spaces. Whether every tool accepts that is the
  first thing the M0 gate run tests. `sanitize_path` uses `abspath`, not
  `realpath`, so a space-free symlink is the fallback.
- LibreLane's Classic flow still runs `RepairDesignPostGRT` before
  `RepairAntennas`, the same ordering that left slew violations on antenna
  diodes in OpenLane 1.1.1.

### 2026-09-29 — Claude (Opus 5.5) — M0 step 1

**Done.** Recorded the P0.7b F4 floorplan sweep in
`docs/results/physical-design.md` and `docs/results/data/floorplan-sweep.csv`
before deleting the run trees. Each run has two congestion reports: the
design-repair global route and the final global route with antenna repair.
The 1800 um and 2200 um points at density 0.45 passed the first with zero
overflow and left 24 and 14 overflowing gcells in the second. Committed
`scripts/sta/placed_timing.tcl` for M2.

**Verified.** `make test` passes.

**Next.** M0 step 2, as in "Current state".

### 2026-09-29 — Claude (Opus 5.5) — through `4f3fcd5`, plus this handoff commit

**Done.** Turned this file into the shared handoff and added the `AGENTS.md`
pointer, because Codex auto-loads `AGENTS.md` and had never been reading this
file on its own. Researched the literature and wrote the M0 to M4 roadmap into
`docs/project-status.md`. Key research findings: our 1x16 FP4 block choice
independently re-derives NVFP4, so it is not novel by itself; the owner chose
four novelty tracks: scale-format co-design, per-block FP4/INT4, an exact
multiplier-free E2M1 MAC, and exponent-first sparsity. The owner approved
deleting every old `build/physical` tree and migrating new physical work to
LibreLane 3.x, keeping the OpenLane 1.1.1 image to reproduce old results.

**Earlier in the same Claude run, P0.7b, all committed.**

- F0 (`8acb40f`, `7048905`): fixed the OpenLane file list, `ENGINES`, and
  overrides; found and fixed the Yosys `automatic` parse failure. Corrected the
  brief: `MAX_TRANSITION_CONSTRAINT` was always 0.75 ns from the PDK. 60% of the
  old slew violators are antenna-diode pins inserted after slew repair.
- F1 (`432cc19`): at the slow corner the worst path was `matrix_size` through
  `calc_start` into the accumulator, not reset; reset was worst only at the
  typical corner.
- F2 (`661e2cd`): chose `DELAY 0` at an 8 ns synthesis target.
- F3 (`117ce31` to `5ca2a50`): five cycle-neutral RTL fixes, 20.593 ns to
  18.241 ns slow-corner mapped minimum period, area down 8.95%. F3.1 also fixed
  AXI ready signals that were asserted during reset.
- F4 (`e6b68e5`, `4f3fcd5`, results not yet recorded in docs): LibreLane was
  not used; OpenLane 1.1.1 `global-route` mode at 20 ns P&R with an 8 ns
  synthesis target, timing repair off. Outcomes:

  | Die, density | Result |
  | --- | --- |
  | 1300, 0.45/0.55/0.65 | GPL-0302, cannot place; suggested density 0.68 |
  | 1500, 0.45 | GPL-0302; suggested density 0.51 |
  | 1500, 0.55 | GRT-0119 congestion, 4,921 overflow gcells, 4,657 `acc_bank` net references |
  | 1500, 0.65 | GRT-0119, 8,314 overflow gcells, 4,261 `acc_bank` references |
  | 1800, 0.45 | Global route finished; GRT-0232 congestion in antenna repair, 24 overflow gcells |
  | 1800, 0.55 | GRT-0119, 1,046 overflow gcells, 1,092 `acc_bank` references |
  | 1800, 0.65 | GRT-0119, 4,997 overflow gcells, 4,393 `acc_bank` references |
  | 2200, 0.45 | Reached antenna repair with 109 violations, then the sweep was killed |
  | 2200, 0.55 and 0.65 | Never started |

  Placed area was 1,132,098 um² at 1500 and 1,149,437 um² at 1800. The design
  prefers lower density and more area; the planned fix is structural.
- F5 and F6: not started.

**Verified.** `make test` passes at `4f3fcd5`. The check-docs, lint, model, and
integration suites all pass.

**In progress.** Nothing running.

**Next.** M0 step 1, as in "Current state".

### 2026-09-29 — Codex — reconciled concurrent M0 result

**Reconciled.** Commit `513c728` appeared while Codex held the lock. Claude's
post-handoff process recorded the same completed M0 run Codex was reviewing.
Codex discarded its duplicate uncommitted CSV and documentation edits, reviewed
Claude's commit, and retained its single authoritative result. The protocol now
requires a lock and `HEAD` recheck immediately before every commit, and assigns
recording responsibility for handed-off background runs to the receiving agent.

**Verified.** The M0 result matches the final LibreLane metrics: clean detailed
route, Magic and KLayout DRC, LVS, and antenna checks; setup WNS -2.0313 ns,
hold WNS -0.0605 ns, 5,061 slew violations, and 145 capacitance violations.
M0 is complete and M1 preprocessing is next.

### 2026-09-29 — Codex — M1 preprocessing start

**Started.** Confirmed clean synchronized `master` at `fe70a59`, read the shared
handoff and rules, and claimed the lock. The atomic task is K channel-mean
centering and Hadamard rotation across all four pinned captures, behind a new
precision-study flag that does not change existing record shapes.

### 2026-09-29 — Codex — M1 preprocessing result

**Done.** Added K channel-mean centering and normalized Walsh-Hadamard rotation
behind `--preprocessing-study`, including their combination, FP32 and searched
E4M3 scales, and all four pinned captures. The record measures raw score error
after row-mean removal, because K centering intentionally adds a softmax-inert
row shift. Neither transform becomes the default: searched E4M3 baseline mean
KL/top-1 is 0.02114/90.82%; K centering gives 0.02712/89.16%, and Hadamard gives
0.02165/90.53%. Capture-level directions differ.

**Verified.** `make test` passes with 33 model tests, eleven lint configurations,
and both integration depths. A provenance test checks all 32 study rows and all
four capture hashes. Next is per-block FP4 versus INT4.

### 2026-09-29 — Codex — M1 element-format result

**Done.** Added `--element-format-study` for fixed FP4, fixed signed INT4, and
per-block reconstruction-error selection under searched E4M3 scales. Adaptive
selection uses INT4 for 62.14% of Q/K blocks and improves mean KL from 0.02114
to 0.01875, but top-1 falls from 90.82% to 90.48% and small-BERT L3 H0 regresses.
It remains a layer-selective candidate. One format bit per block is required;
the existing 13-bit Bs=16 accumulator covers all native product bounds.

**Verification.** The model suite regenerates all 12 rows and capture hashes.
Next is sequential versus tree cross-block accumulation.

## Related

- [Agent rules and handoff protocol](agent-rules.md)
- [Project status and roadmap](project-status.md)
- [Documentation index](README.md)
