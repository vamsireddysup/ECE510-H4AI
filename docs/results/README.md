# Results and machine-readable data

This directory holds concise reviewed evidence. Prose stays at this level;
small source data lives under [`data/`](data/). Generated logs, binaries,
waveforms, and complete physical runs stay under ignored `build/`.

## Reviewed records

| Record | Owns |
| --- | --- |
| [Performance and design space](performance.md) | Correctness, cycles, traffic, CPU baseline, array and replication comparisons |
| [Attention precision](precision.md) | Synthetic and four pinned BERT activation sweeps |
| [Physical design](physical-design.md) | Complete-top routes, timing and floorplan sweeps, signoff, and critical-path attribution |
| [Latest verification](latest-verification.md) | Most recent command run and tool versions |

## Data

| Artifact | Content |
| --- | --- |
| [Synthetic precision sweep](data/synthetic-precision-sweep.json) | Fixed-seed block-size and scale-format metrics |
| [Pipeline overlap simulation](data/pipeline-overlap-simulation.csv) | P0.3 cycles, utilization, traffic, and stalls |
| [Block-scale lane sweep](data/block-scale-lane-sweep.csv) | Bs=32 array and lane measurements |
| [Bs=16 default simulation](data/bs16-default-simulation.csv) | Current protocol cycles, traffic, utilization, and RTL precision |
| [Physical constraint sweep](data/physical-constraint-sweep.csv) | Floorplan, timing, and signoff outcomes |
| [Critical-path attribution](data/critical-path-attribution.csv) | Mapped path, slack, cells, and area after each timing change |
| [Replicated-engine cycles](data/replicated-engine-cycles.csv) | Engine-count sweeps for protocols v3/v4 and tile sizes 4/8/16 |
| [Replicated-engine measurements](data/replicated-engine-measured.csv) | Measured engine-count cycles, beats, and model error |
| [Replicated-engine area](data/replicated-engine-area.csv) | Mapped hierarchy and conservative replication projections |
| [Pinned BERT captures and sweeps](precision.md#transformer-activation-captures) | Four `.npz` captures, their SHA-256 values, and four JSON records |

## Generated output

Integration logs use
`build/integration/b<tile>-t<tmax>-d<depth>-reuse<reuse>-sb<block>-sl<lanes>-e<engines>/`.
`make report-sim` writes `build/integration/summary.csv`. Synthesis and physical
runs use `build/synthesis/` and `build/physical/`. CI uploads integration output
for 30 days; major complete runs may be attached to a GitHub release.

## Related

- [Documentation index](../README.md)
- [Repository layout](../repository-layout.md)
- [Project status](../project-status.md)
