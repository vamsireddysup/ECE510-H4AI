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

Use `make test` for the active design. The historical compatibility point is:

- `TILE_SIZE=4`
- `D_HEAD=4`
- `T_MAX=16`
- 16/16 numerical outputs correct
- recorded `CYCLE_COUNT=498`

Numerical correctness alone is insufficient. New regressions must also check
completion status, counters, AXI handshakes, timeouts, and backpressure.

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
- Cleanup commands must target only known generated directories such as
  repository-local `build/`.
- Prefer pinned, project-local, or containerized tools. Do not uninstall a
  working system tool merely to obtain a newer version.
