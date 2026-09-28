# Archive

This directory keeps the small historical subset that active checks or project
provenance still use. The active design is under [`rtl/`](../rtl/README.md).

## Contents

| Path | What it is | Why it remains |
| --- | --- | --- |
| [`superseded-rtl/`](superseded-rtl/README.md) | Nine modules replaced by the packed-stream engine | The model test reads `fp4_mul_lut.sv`, and the active architecture records use the older modules for comparison |
| [`coursework/project/m4/`](coursework/project/m4/README.md) | Final course submission, report, source, testbench, and recorded results | `make baseline` rebuilds `m4/src/` with `m4/tb/tb_top.cpp`; the package documents the starting point |
| `coursework/project/` loose files | Early algorithm, scope, and research notes | Small provenance records for the M4 project |
| `experiments/smoke_test/adder4.v` and `tb_adder4.cpp` | Original Verilator environment check source | The two source files explain the experiment without retaining generated objects |

The M1 through M3 snapshots, weekly codefests, pre-active upgrade copy, early HDL
prototype, and committed Verilator object directory were removed on September
28, 2026. The annotated tag `pre-cleanup-2026-09-28` preserves the complete tree
before that cleanup. Git history still contains every removed blob.

`.gitignore` reserves `archive/local/` and `archive/reference/` for untracked
local tooling and reference material. Neither is present in a fresh clone.

## Reading the M4 record

The archived 498-cycle result used `D_HEAD=4` and one tile. Its 512 projection
counted 262,144 output tiles where a 512x512 matrix has 16,384 at
`TILE_SIZE=4`. Active result documents carry the corrected interpretation.

## Related

- [Documentation index](../docs/README.md)
- [Active RTL](../rtl/README.md)
- [Packed-engine result](../docs/results/packed-engine.md)
