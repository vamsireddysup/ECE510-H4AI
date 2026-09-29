# Agent project instructions

## Purpose

This is my active FP4 `Q * K^T` accelerator repository. Preserve the verified
course work while building and testing the active implementation.

Read [the documentation index](README.md) before making architectural or
repository-wide changes.

## Handoff protocol

**Start here: read the root [`CODEX.md`](../CODEX.md) before anything else.**
It holds the lock, the current state, "Picking this up", and the handoff log.

Claude Code and Codex both work on this repository, one at a time, as each has
credits. The root `CODEX.md` is the shared entry point: it holds the lock, the
current state, and the handoff log, and `AGENTS.md` points to it so Codex loads
it automatically. There is no `CLAUDE.md`.

- Start every session with `CODEX.md`, these rules, `git status`, and the git
  log since the newest handoff entry. Stop if another agent holds the lock.
- After every verified commit, update the current state and add a handoff
  entry, then push. The handoff is never more than one step behind the code.
- Re-read the lock and check `HEAD` immediately before committing. If either
  changed, reconcile first. Once an agent hands off a background run, the
  receiving agent owns recording its result; the former agent must not resume
  and commit after the lock changes.
- Neither agent can read its own credit percentage, so there is no reliable
  "at 80%" trigger. Stop deliberately when the owner says so, when a context or
  usage warning appears, or when the next step will not fit: finish the atomic
  step, commit, write the entry, push, and clear the lock.
- The first session after a milestone re-runs that milestone's gate commands
  before starting new work.
- Keep `CODEX.md` under about 24 KB; move handoff entries older than the newest
  eight to `docs/handoff-log.md`.

## Source-of-truth policy

- Treat `archive/coursework/project/m4/` as the retained historical snapshot.
- Treat `rtl/` as the active source of truth.
- Treat `archive/coursework/project/m4/src/` as the untouched course reference.
- Do not edit duplicated milestone RTL to implement new features.
- Keep measured results separate from projections. The verified implementation
  is 4x4; 16x16 results are projections until actual runs prove otherwise.
- Preserve user-created or unrelated untracked files unless their inclusion is
  explicitly requested.

## Development workflow

1. Inspect `git status` before changing files.
2. Keep structural migration and behavioral changes in separate commits.
3. Add or strengthen a test before fixing a correctness bug.
4. Build generated output under `build/` or `/tmp`, never beside source files.
5. Run checks appropriate to the change before committing.
6. Confirm that tests do not leave unexpected untracked files.
7. Update the relevant Markdown documentation with every interface,
   architecture, parameter, workflow, or measured-result change.
8. Update `results/latest-verification.md` whenever verification results or
   tool versions change.

## Commit policy

- Commit each complete logical update after it is verified.
- Use one concise subject line, preferably under 60 characters.
- Use the form `area: short action`, for example:
  - `docs: add migration plan`
  - `build: add regression targets`
  - `test: cover two-tile execution`
  - `rtl: reset PEs between tiles`
- Avoid long multi-paragraph commit messages unless a non-obvious migration or
  compatibility decision genuinely requires explanation.
- Never combine unrelated user changes with the current task's commit.
- Work directly on `master`. Do not create another branch unless I ask for one.
- Push every verified commit to `origin/master`.
- Do not amend, rebase, force-push, or rewrite existing history unless the user
  explicitly requests it.

## Verification expectations

Use `make test` for the active design and `make test-integration-large` for the
T=64/128/512 run. `make lint` checks the default, K-reuse, 8x8, and 16x16
parameter sets. The historical compatibility point is:

- `TILE_SIZE=4`
- `D_HEAD=4`
- `T_MAX=16`
- 16/16 numerical outputs correct
- recorded `CYCLE_COUNT=498`

That 498-cycle result belongs to the pre-upgrade, one-tile controller. The
active packed-stream v5 top runs the same numerical pattern in 49 simulated
cycles with injected host stalls; see `results/latest-verification.md`.
The current active source list is `rtl/filelist.f`. Independent input, compute,
scaling, and output sequencers exchange two-bank Q, K, accumulator, and score
storage. `score_scaler.sv` owns the parameterized scaling lanes, and
`score_reducer.sv` combines scaled block scores. The older PE,
array, controller, and buffers are retained for comparison but are not active.

Numerical correctness alone is insufficient. New regressions must also check
completion status, counters, AXI handshakes, timeouts, and backpressure.
Use `stream-protocol.md` for packet ordering and status definitions.
Version 5 is the default 1x16 block-scale K-reload build; `K_REUSE=1` selects version 6 and a
command-level K scratchpad. `make test-integration-reuse` and
`make test-integration-reuse-large` verify that variant. The 8x8 and 16x16
tests and their cell-area results are recorded in `results/performance.md`.
`scripts/eval_precision.py` sweeps reduction-block FP32 and E8M0 scales and
reports softmax agreement, raw-score error, clipping, storage, and projected
FP32 adds. Protocol versions 5 and 6 implement ADR 0004's 1x16 FP32 format with
a parameterized block size and score lanes; versions 3 and 4 retain 1x32
compatibility. Four pinned BERT heads across two model sizes support that
choice. `make test-precision-rtl` compares all default 1x16 T=512 scores
bit-exactly.
`make report-sim` derives useful bytes, wire bytes, arithmetic intensity, and
array utilization from accepted-beat simulation logs.
`scripts/run_physical.sh` runs the complete 4x4/D_HEAD=64/T_MAX=16 top in
OpenLane; its `synthesis` mode records comparable mapped timing checkpoints.
Variable scale-launch division has been replaced with coordinate counters,
scale reads are prefetched, and integer conversion uses a bounded priority
tree. The mapped path is 58.09 ns. The optimized 2200 um-die route is DRC/LVS
clean and its fixed-layout sweep closes setup at 30.5 ns, but it fails
multi-corner hold by 1.2765 ns and retains antenna, slew, and fanout violations.
Its dynamic-power report is not qualified; see
`results/physical-design.md`.
The selected 16x16 four-lane route attempt did not get through Yosys
`OPT_MEM_PRIORITY` in 20 minutes 49 seconds, so it has no mapped or physical
result.
Do not call it timing closed or use its dynamic power numbers. ADR 0005 closes
the register-based K-reuse experiment using a labeled slow-corner leakage and
off-chip-energy projection. Do not derive active latency from the archived
15 ns array-only constraint.

`scripts/cycle_model.py` also models replicated engines and is exact against
all 32 recorded configurations. The current implementation assigns K tile
columns round-robin and retires engines in order, so replication does not
change the stream format or require a general reorder buffer. See
`results/performance.md` before proposing a replicated top.

For every published benchmark or synthesis result, record:

- Git commit;
- RTL target and included modules;
- parameter values;
- tool and PDK versions;
- clock constraint;
- measured versus projected status.

## Markdown standards

- Write project goals, choices, and results from my point of view.
- Keep the tone natural and direct. Do not use AI-style filler, marketing
  language, or unnecessary polish.
- Preserve historical coursework documents in their original voice.
- Give every document one clear H1 title.
- Start with purpose and scope, then move from overview to details.
- Keep headings descriptive and nesting consistent.
- Prefer short paragraphs and tables only when they improve comparison.
- Use repository-relative links and verify them after moving files.
- Label historical facts, current behavior, known limitations, and future work
  explicitly.
- Avoid duplicating large explanations; link to the source-of-truth document.
- Keep commands copy-pasteable from the directory stated in the document.
- Update `docs/README.md` when adding, renaming, or replacing documentation.

## Safety and cleanup

- Do not delete milestone evidence during the initial migration.
- Use `git mv` when archiving tracked files so history remains traceable.
- Do not commit PDKs, virtual environments, caches, generated Verilator files,
  full OpenLane run trees, or ordinary waveform output.
- Keep only deliberately reviewed result summaries, plots, and signoff evidence.
- Upload routine CI transcripts as temporary workflow artifacts, not commits.
- Put complete major-release outputs in GitHub Release assets rather than Git
  history.
- Cleanup commands must target only known generated directories such as
  repository-local `build/`.
- Prefer pinned, project-local, or containerized tools. Do not uninstall a
  working system tool merely to obtain a newer version.

## Related

- [Documentation index](README.md)
- [Repository layout and documentation contract](repository-layout.md)
- [Verification plan](verification-plan.md)
- [Contribution workflow](../CONTRIBUTING.md)
