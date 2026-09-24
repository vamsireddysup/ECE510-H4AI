# Results and transcripts

This directory holds the reviewed measurements that stay in Git. Read it to find
out which record owns which number, and where the full generated logs went.

Generated logs, binaries, and waveforms go under the ignored `build/` directory.
They are large and reproducible, so they are not committed.

## Reviewed records

| Record | Owns |
| --- | --- |
| [Packed engine result](packed-engine.md) | Per-configuration correctness, cycles, host traffic, CPU baseline, synthesis scope |
| [Design-space experiment](design-space.md) | K reuse, 8x8 and 16x16 sweeps, mapped areas, SRAM macro candidates |
| [Synthetic precision](precision.md) | Row-scaled FP4 score error against FP32 |
| [Latest verification](latest-verification.md) | The most recent local command run and its tool versions |

## Where generated output lands

Integration runs write one directory per configuration, named for its parameters:

```text
build/integration/b<tile>-t<tmax>-d<depth>-reuse<reuse>/build.log
build/integration/b<tile>-t<tmax>-d<depth>-reuse<reuse>/run.log
```

For example, the default `make test-integration` writes
`build/integration/b4-t16-d4-reuse0/` and `b4-t16-d64-reuse0/`.

`make report-sim` reads every `build/integration/*/run.log` and writes one CSV:

```text
build/integration/summary.csv
```

The archived M4 comparison run writes:

```text
build/m4-baseline/build.log
build/m4-baseline/run.log
build/m4-baseline/summary.txt
```

Yosys mapping and OpenLane write:

```text
build/synthesis/t<tile>-d<depth>-max<tmax>-reuse<reuse>/yosys.log
build/physical/<run-name>/flow.log
build/physical/<run-name>/runs/full/
```

## GitHub copies

The CI workflow uploads `build/integration/` as one artifact, kept for 30 days.
It does not become part of Git history.

For major releases I attach complete simulation and physical-design outputs to
the GitHub release. Routine runs stay reproducible local or CI artifacts.

## Related

- [Documentation index](../README.md)
- [Repository layout](../repository-layout.md)
