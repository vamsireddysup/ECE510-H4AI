# Documentation

I use this directory for the engineering notes and development plans for my FP4
`Q * K^T` accelerator. I am leaving the M1-M4 documents as course records. The
documents here cover the work I am doing after that baseline.

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
| [M4 README](../archive/coursework/project/m4/README.md) | Final coursework package and reproduction instructions |
| [Codex instructions](../CODEX.md) | Working, commit, verification, and Markdown conventions |
| [Latest verification](results/latest-verification.md) | Most recent reviewed local test run |
| [Results and transcripts](results/README.md) | Generated and tracked output locations |

## Planned specifications

As I build the new layout, I will add separate documents for the architecture,
numeric behavior, register map, stream protocol, verification coverage, design
decisions, and measured results. I will write them when the matching code and
tests exist instead of filling them with assumptions now.
