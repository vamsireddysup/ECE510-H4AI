# Documentation

Every active document is listed here, with the one thing it is authoritative for.
If two documents seem to own the same fact, this table decides. The M1-M4
documents under [`archive/`](../archive/README.md) are course snapshots and stay
unchanged.

## Start here

| Document | Authoritative for |
| --- | --- |
| [Problem statements](problem-statements/README.md) | Which problem is active, and what each has to prove |
| [Architecture](architecture.md) | Blocks, dataflow, and the cycle cost model |
| [Stream protocol](stream-protocol.md) | Packet order, packing, status codes, and the AXI register map |
| [Project context](project-context.md) | Current design, archived baseline, and open limits |

## Plans and conventions

| Document | Authoritative for |
| --- | --- |
| [Development plan](roadmap.md) | Completed work and the next measured experiments |
| [Verification plan](verification-plan.md) | What each check proves, and the gaps |
| [Repository layout](repository-layout.md) | Directory layout, naming, and the documentation contract |
| [Decision records](adr/README.md) | Decisions that are expensive to reverse |
| [Agent rules](../CODEX.md) | Workflow, commit policy, and verification expectations |
| [Contribution workflow](../CONTRIBUTING.md) | How a change gets made |

## Measurements

| Document | Authoritative for |
| --- | --- |
| [Results index](results/README.md) | Which record owns which number, and where logs land |
| [Packed engine result](results/packed-engine.md) | Per-configuration correctness, cycles, traffic, CPU baseline, synthesis scope |
| [Design-space experiment](results/design-space.md) | K reuse, 8x8 and 16x16 sweeps, mapped areas, SRAM candidates |
| [Synthetic precision](results/precision.md) | Block-scale sweep, softmax agreement, and the P0.2 evidence |
| [Latest verification](results/latest-verification.md) | The most recent command run and its tool versions |

## Directory notes

| Document | Covers |
| --- | --- |
| [Active RTL](../rtl/README.md) | What is synthesizable and what the parameters mean |
| [Testbenches](../tb/README.md) | What the integration test covers and how to run it |
| [Reference model](../model/README.md) | The Python FP4 numerics the RTL is checked against |
| [Scripts](../scripts/README.md) | What each script needs and where it writes |
| [Archive](../archive/README.md) | Coursework, superseded RTL, and old experiments |
| [M4 package](../archive/coursework/project/m4/README.md) | The historical submission and its reproduction |

## Conventions in one line each

Generated output goes under ignored `build/`. Reviewed summaries are committed in
[`docs/results/`](results/README.md). Large release outputs go in GitHub release
assets. Every number says whether it is measured or projected. No adjective without
a number. The full contract is in [repository layout](repository-layout.md).

## Related

- [Repository root](../README.md)
- [Repository layout and documentation contract](repository-layout.md)
