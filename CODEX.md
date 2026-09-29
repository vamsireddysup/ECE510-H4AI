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

Active agent: Codex, 2026-09-29. Implementing M2 P0 physical closure work.

## Current state

Updated 2026-09-29 by Codex.

- **Branch and commit.** `master`, pushed to
  `vamsireddysup/FP4-transformer-attention-accelerator`. CI and `make test`
  pass.
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
- **Open blocker.** No floorplan has routed with the current RTL. Congestion is
  dominated by `acc_bank` nets. M2's block-streaming accumulator is the planned
  fix.
- **No valid dynamic power number exists yet.** That is M2's deliverable.
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
  current integer product and maps 56.24% smaller in the standalone probe. The
  archived ROM is smaller in isolation but emits FP32 and excludes reduction
  cost. The selected expression is active in `qkt_engine`; all large and RTL
  precision suites retain identical scores and cycles.
- **M0 is complete.** The gate run finished after the handoff was written:
  LibreLane took the `D_HEAD=4` configuration RTL to GDS with zero DRC, zero
  LVS, and **zero antenna violations**, then stopped correctly at the hold
  checker (setup -2.03 ns, hold -0.06 ns at the slow corner, 20 ns). Recorded
  in `docs/results/physical-design.md`. Its 18.6 mW power number is **not**
  usable: no switching activity was annotated.
- **Exact next step.** Start M2 with the block-streaming accumulator and combine
  it with the ADR 0008 E4M3 scaler and ADR 0009 shift/add product.

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

### 2026-09-29 — Codex — M1 element-format result

**Done.** Added `--element-format-study` for fixed FP4, fixed signed INT4, and
per-block reconstruction-error selection under searched E4M3 scales. Adaptive
selection uses INT4 for 62.14% of Q/K blocks and improves mean KL from 0.02114
to 0.01875, but top-1 falls from 90.82% to 90.48% and small-BERT L3 H0 regresses.
It remains a layer-selective candidate. One format bit per block is required;
the existing 13-bit Bs=16 accumulator covers all native product bounds.

**Verification.** The model suite regenerates all 12 rows and capture hashes.
Next is sequential versus tree cross-block accumulation.
