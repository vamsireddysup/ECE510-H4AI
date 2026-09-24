# Documentation

I keep active QK^T architecture, interface, and measurement records here. The
M1-M4 documents under `archive/` are course snapshots and remain unchanged.

| Document | Purpose |
| --- | --- |
| [Project context](project-context.md) | Active design, archive baseline, and open limits |
| [Development plan](roadmap.md) | Completed work and next measured experiments |
| [Packed stream protocol](stream-protocol.md) | Version 1 packet order, packing, status, and counters |
| [Packed engine result](results/packed-engine.md) | Correctness, cycles, traffic, CPU baseline, synthesis scope |
| [Design-space experiment](results/design-space.md) | K reuse, array-size sweeps, and SRAM candidates |
| [Synthetic precision](results/precision.md) | Row-scaled FP4 error against FP32 QK^T |
| [Latest verification](results/latest-verification.md) | Most recent local commands and tool versions |
| [Repository layout](repository-layout.md) | Directory layout, naming, and the documentation contract |
| [Codex instructions](../CODEX.md) | Workflow and commit rules |
| [M4 README](../archive/coursework/project/m4/README.md) | Historical submission and reproduction |

Generated transcripts stay in ignored `build/`. Reviewed summaries are
committed in `docs/results/`; large release outputs belong in GitHub releases.
