# Handoff log archive

This holds handoff entries that have rotated out of the root `CODEX.md`, which
keeps only the newest eight so Codex never truncates it. Entries are newest
first and keep the format described in the session protocol there.

## Archived entries

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
