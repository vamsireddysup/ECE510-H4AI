# Archive

This directory holds material I keep for the record but do not build. Read it to
find a coursework submission, a superseded module, or an old experiment. Nothing
here is on the active build path; the active design is under
[`rtl/`](../rtl/README.md).

## Contents

| Path | What it is |
| --- | --- |
| [`superseded-rtl/`](superseded-rtl/README.md) | The nine modules the packed-stream engine replaced, kept for comparison |
| `coursework/project/m1/` through `m4/` | The original M1-M4 submissions, unchanged |
| [`coursework/project/m4/`](coursework/project/m4/README.md) | The final course package and its reproduction instructions |
| `coursework/codefest/cf01/` through `cf09/` | Weekly course exercises |
| `coursework/project/` loose files | `heilmeier.md`, `algorithm_notes.md`, `scope_assessment.md`, `remaining_tasks.md`, and the early `hdl/` prototype |
| `coursework/project/upgrade_archive/` | Superseded upgrade experiments predating the active tree |
| `experiments/smoke_test/` | The original Verilator environment check |

`.gitignore` also reserves `archive/local/` and `archive/reference/` for untracked
local tooling and reference material. Neither is present in a fresh clone.

## Why the coursework stays unchanged

The M1-M4 directories are the submitted record. I do not edit them to fix a
mistake found later; I state the correction in the active documents instead. Two
corrections that matter when reading them: the archived 498-cycle result used
`D_HEAD=4` and one tile, and the archived 512 projection counted 262,144 output
tiles where a 512x512 matrix has 16,384 at `TILE_SIZE=4`. Both are recorded in
[project context](../docs/project-context.md).

## Related

- [Project context](../docs/project-context.md)
- [Documentation index](../docs/README.md)
- [Active RTL](../rtl/README.md)
