# Changelog

## Unreleased

- Started moving the course project into a single active RTL and test tree.
- Added reproducible baseline, tool-check, lint, and integration commands.
- Recorded the known completion-status and multi-tile limitations.
- Asserted completion before the final status read and made it a required test.
- Removed the unused single-read array path so the parallel tile buffer is the
  only source driving systolic-array inputs.
- Moved coursework, codefests, and old experiments under `archive/` and kept
  only the active project at the repository root.

## M4 course submission

- Verified one 4x4 `Q * K^T` tile with 16/16 correct outputs.
- Completed the recorded Sky130 HD OpenLane run for the flat array target.
