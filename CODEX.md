# Codex project instructions

## Purpose

This is my active FP4 `Q * K^T` accelerator repository. Preserve the verified
course work while building and testing the active implementation.

Read [the documentation index](docs/README.md) before making architectural or
repository-wide changes.

## Source-of-truth policy

- Treat `archive/coursework/project/m1/` through `m4/` as historical snapshots.
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
8. Update `docs/results/latest-verification.md` whenever verification results or
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
active packed-stream v3 top runs the same numerical pattern in 49 simulated
cycles with injected host stalls; see `docs/results/latest-verification.md`.
The current active source list is `rtl/filelist.f`. Independent input, compute,
scaling, and output sequencers exchange two-bank Q, K, accumulator, and score
storage. `score_scaler.sv` owns the parameterized scaling lanes, and
`score_reducer.sv` combines scaled block scores. The older PE,
array, controller, and buffers are retained for comparison but are not active.

Numerical correctness alone is insufficient. New regressions must also check
completion status, counters, AXI handshakes, timeouts, and backpressure.
Use `docs/stream-protocol.md` for packet ordering and status definitions.
Version 3 is the default block-scale K-reload build; `K_REUSE=1` selects version 4 and a
command-level K scratchpad. `make test-integration-reuse` and
`make test-integration-reuse-large` verify that variant. The 8x8 and 16x16
tests and their cell-area results are recorded in `docs/results/design-space.md`.
`scripts/eval_precision.py` sweeps reduction-block FP32 and E8M0 scales and
reports softmax agreement, raw-score error, clipping, storage, and projected
FP32 adds. ADR 0003 selects 1x32 FP32, now implemented with parameterized block
size and score lanes. `make test-precision-rtl` compares all T=512 scores
bit-exactly. Synthetic inputs do not
substitute for real transformer activations.
`make report-sim` derives useful bytes, wire bytes, arithmetic intensity, and
array utilization from accepted-beat simulation logs.
`scripts/run_physical.sh` runs the complete 4x4/D_HEAD=64/T_MAX=16 top in
OpenLane; record its revision and final routed status before using its clock.
Treat mapped Sky130 cell area as synthesis only until full-chip timing, routing,
and power checks finish. Do not derive active latency from the archived 15 ns
array-only constraint.

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

- [Documentation index](docs/README.md)
- [Repository layout and documentation contract](docs/repository-layout.md)
- [Verification plan](docs/verification-plan.md)
- [Contribution workflow](CONTRIBUTING.md)
