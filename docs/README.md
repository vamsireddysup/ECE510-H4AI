# Documentation

This directory contains the engineering context and forward-development plan
for the FP4 `Q * K^T` accelerator. The M1-M4 documents remain historical course
artifacts; the documents here describe how the project evolves from that
baseline.

## Recommended reading order

1. [Project context](PROJECT_CONTEXT.md) explains the accelerator, current
   module responsibilities, verified results, and known limitations.
2. [Repository reorganization plan](REPOSITORY_REORGANIZATION_PLAN.md) defines
   the target professional layout, migration phases, tool policy, CI, and
   acceptance gates.
3. [Development roadmap](DEVELOPMENT_ROADMAP.md) describes the technical path
   from the 4x4 baseline to correct multi-tile and larger-array designs.

## Documentation roles

| Document | Source of truth for |
| --- | --- |
| [Project context](PROJECT_CONTEXT.md) | Current architecture and verified baseline |
| [Repository reorganization plan](REPOSITORY_REORGANIZATION_PLAN.md) | Structural migration and repository standards |
| [Development roadmap](DEVELOPMENT_ROADMAP.md) | Future RTL and physical-design sequence |
| [M4 README](../project/m4/README.md) | Final coursework package and reproduction instructions |
| [Codex instructions](../CODEX.md) | Working, commit, verification, and Markdown conventions |

## Planned specifications

The professional layout will add focused documents for architecture, supported
numeric behavior, register map, stream protocol, verification coverage,
architecture decisions, and traceable benchmark/signoff results. Those files
should be introduced with the canonical source tree rather than populated with
unverified assumptions now.
