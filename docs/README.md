# Documentation

This index gives each active document one job and three reading paths. The root
[README](../README.md) is the five-minute project overview.

## Understand the project

| Document | Authoritative for |
| --- | --- |
| [Glossary](glossary.md) | Attention, number-format, and hardware terms |
| [Project status and plan](project-status.md) | Current implementation, completed evidence, and next gates |
| [Architecture](architecture.md) | Blocks, dataflow, and exact cycle model |
| [Research questions](problem-statements/README.md) | P0, deferred P1, and shelved P2 scope |
| [Related work](related-work.md) | Nearest published work per research track and what is not new |

## Build or change it

| Document | Authoritative for |
| --- | --- |
| [Stream protocol](stream-protocol.md) | Current packet order, packing, counters, errors, and register map |
| [Protocol history](protocol-history.md) | Compatibility meaning of versions 1 through 6 |
| [Verification plan](verification-plan.md) | What every check proves and the remaining gaps |
| [Repository layout](repository-layout.md) | Directory, naming, documentation, and rename conventions |
| [Agent rules](agent-rules.md) | Automated workflow, handoff protocol, commit policy, and result provenance |
| [Handoff log archive](handoff-log.md) | Older Claude and Codex handoff entries rotated out of `CODEX.md` |
| [Contribution workflow](../CONTRIBUTING.md) | Human change workflow |

## Review the evidence

| Document | Authoritative for |
| --- | --- |
| [Results index](results/README.md) | Prose records, machine-readable data, and generated output locations |
| [Performance and design space](results/performance.md) | Correctness, cycles, traffic, CPU comparison, array scaling, and replication |
| [Attention precision](results/precision.md) | Synthetic and pinned-activation score and softmax metrics |
| [Physical design](results/physical-design.md) | Constraint sweep, routed timing, signoff, and critical-path attribution |
| [Latest verification](results/latest-verification.md) | Most recent commands and tool versions |
| [Decision records](adr/README.md) | Decisions expensive to reverse |

## Directory notes

- [Active RTL](../rtl/README.md)
- [Integration testbench](../tb/README.md)
- [Reference model](../model/README.md)
- [Scripts](../scripts/README.md)
- [Archive](../archive/README.md)

## Related

- [Repository root](../README.md)
- [Repository layout and documentation contract](repository-layout.md)
