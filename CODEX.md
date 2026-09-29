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

Active agent: none

## Current state

Updated 2026-09-29 by Claude (Opus 5.5).

- **Branch and commit.** `master`, pushed to
  `vamsireddysup/FP4-transformer-attention-accelerator`. CI and `make test`
  pass.
- **Active plan.** The research-backed roadmap, milestones M0 to M4, is in
  [docs/project-status.md](docs/project-status.md#roadmap-milestones-m0-to-m4).
  The current milestone is **M0, housekeeping and toolchain**.
- **Where the design is.** 4x4 FP4 QK^T engine with 1x16 FP32 block scales,
  exact integer block accumulation, `ENGINES` replication (1 to 16), protocol
  versions 5 and 6 by default. All 32 recorded cycle configurations re-simulate
  exactly (`python3 scripts/check_cycle_model.py`).
- **Best timing evidence.** Mapped netlist, `DELAY 0` at an 8 ns target, no
  wires: 18.241 ns slow-corner and 8.998 ns typical-corner minimum period at
  `34d9df5`. This is not a routed or closing frequency.
- **Open blocker.** No floorplan has routed with the current RTL. Congestion is
  dominated by `acc_bank` nets. M2's block-streaming accumulator is the planned
  fix.
- **No valid dynamic power number exists yet.** That is M2's deliverable.
- **Toolchain.** LibreLane 3.0.14 is installed by
  `scripts/install_librelane.sh` (venv `~/.local/share/fp4-accel/librelane-venv`,
  ciel 2.6.1, Sky130 `8afc8346a57fe1ab7934ba5a6056ea8b43078e71` in `~/.ciel`,
  image `ghcr.io/librelane/librelane:3.0.14`). Its smoke test passes. The old
  OpenLane 1.1.1 image stays for reproducing recorded results.
- **Uncommitted.** `config/librelane/qkt_chiplet_top/constraints.sdc`, the
  project SDC ported to LibreLane variable names, not yet exercised by a run.
- **Exact next step.** M0 step 4: write `config/librelane/qkt_chiplet_top/`
  base config and `scripts/run_librelane.sh` (two-phase: run to
  `Checker.NetlistAssignStatements` at the synthesis clock, then
  `--from OpenROAD.CheckSDCFiles --with-initial-state` at the P&R clock), then
  run the M0 gate: 4x4, `D_HEAD=4`, RTL to clean GDS.

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

## Handoff log

Newest first. Keep the last eight entries here and move older ones to
[docs/handoff-log.md](docs/handoff-log.md).

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
