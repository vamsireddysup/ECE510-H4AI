# Results and machine-readable data

This directory holds concise reviewed evidence. Prose stays at this level;
small source data lives under [`data/`](data/). Generated logs, binaries,
waveforms, and complete physical runs stay under ignored `build/`.

## Reviewed records

| Record | Owns |
| --- | --- |
| [Performance and design space](performance.md) | Correctness, cycles, traffic, CPU baseline, array and replication comparisons |
| [Attention precision](precision.md) | Synthetic plus six pinned BERT and SmolLM2 activation sweeps |
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
| [M2 signoff at 40 ns](data/m2-signoff-40ns.csv) | Detailed routing, extraction, and nine-corner post-route timing |
| [M2 annotated power](data/m2-annotated-power.csv) | First VCD-annotated power and energy per score, three corners |
| [M2 global route](data/m2-global-route.csv) | First congestion-free route of the block-streaming top, with per-corner timing |
| [M0 gate metrics](data/m0-gate-librelane-metrics.csv) | LibreLane RTL-to-GDS signoff metrics for the `D_HEAD=4` toolchain gate |
| [Floorplan sweep](data/floorplan-sweep.csv) | P0.7b F4 die and density outcomes, placed area, and congestion by stage |
| [Frequency attribution](data/frequency-attribution.csv) | P0.7b F3 mapped minimum period and area after each RTL change |
| [Synthesis sweep](data/synthesis-sweep.csv) | P0.7b F2 cells, area, and typical and slow minimum period by strategy and target |
| [Endpoint ranking at 10 ns](data/endpoint-ranking-10ns.csv) | P0.7b F1 worst endpoint per block pair at the slow and typical corners |
| [Critical-path attribution](data/critical-path-attribution.csv) | Mapped path, slack, cells, and area after each timing change |
| [Replicated-engine cycles](data/replicated-engine-cycles.csv) | Engine-count sweeps for protocols v3/v4 and tile sizes 4/8/16 |
| [E4M3 integrated cost](data/e4m3-integrated-cost.csv) | Complete-top cells, area, and cycles for FP32 against E4M3 scales |
| [Scaler format cost](data/scaler-format-cost.csv) | Mapped Sky130 area of one score lane's scaling path per scale format |
| [FP4 multiplier cost](data/fp4-multiplier-cost.csv) | Mapped Sky130 area of generic, E2M1 shift/add, and FP32 ROM product structures |
| [Integrated FP4 multiplier cost](data/fp4-multiplier-integrated-cost.csv) | Same-flow complete-top generic versus E2M1 shift/add mapping |
| [Block-scale format study](data/scale-format-study.csv) | FP32, E4M3, and E8M0 scale rules across the four pinned captures |
| [Preprocessing study](data/preprocessing-study.json) | K centering and Hadamard rotation under FP32 and searched E4M3 scales |
| [Element-format study](data/element-format-study.json) | Fixed FP4, fixed INT4, and reconstruction-selected blocks under searched E4M3 scales |
| [Accumulation-order study](data/accumulation-order-study.json) | Sequential and balanced-tree FP32 cross-block reductions |
| [Exponent-bound study](data/exponent-bound-study.json) | Safe sign-and-exponent score and 4x4 tile skip coverage at five logit margins |
| [Decoder validation study](data/decoder-validation-study.json) | All five M1 arithmetic probes on two pinned SmolLM2 decoder heads |
| [Output format sweep](data/output-format-sweep.csv) | FP32, FP16, and BF16 output scores across the four pinned captures |
| [CPU baseline](data/cpu-baseline.csv) | Reference-BLAS and OpenBLAS medians, throughput, and fraction of peak |
| [Replicated-engine measurements](data/replicated-engine-measured.csv) | Measured engine-count cycles, beats, and model error |
| [Replicated-engine area](data/replicated-engine-area.csv) | Mapped hierarchy and conservative replication projections |
| [Pinned activation captures and sweeps](precision.md#transformer-activation-captures) | Six BERT and SmolLM2 `.npz` captures, their SHA-256 values, and generated records |

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
