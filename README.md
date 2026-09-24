# FP4 QK^T Accelerator Chiplet

[![CI](https://github.com/vamsireddysup/ECE510-H4AI/actions/workflows/ci.yml/badge.svg?branch=master)](https://github.com/vamsireddysup/ECE510-H4AI/actions/workflows/ci.yml)

I use this repository to develop a Sky130-targeted accelerator for dense
`Q * K^T` attention scores. The active interface accepts FP4 E2M1 Q/K inputs
with per-row FP32 scales and returns FP32 scores. I keep the M1-M4 coursework
snapshots in `archive/` unchanged.

## Current status

The default 4x4 engine uses exact quarter-unit integer dot products and two
pipelined FP32 scale multipliers. Its [version 1 stream contract](docs/stream-protocol.md)
packs 16 FP4 values or two FP32 values per 64-bit beat. It supports partial
edge tiles, input and output stalls, error status, and repeated commands.

| Verified configuration | Result |
| --- | --- |
| 4x4, `D_HEAD=4`, T=4 | Original 16/16 numerical case; 49 simulated core cycles with stalls |
| 4x4, `D_HEAD=64`, T=512 | 262,144/262,144 scores; 1,049,150 simulated cycles with ready host |
| Host traffic at T=512 | 3,166,208 transferred bytes; 10.60 FLOP/byte |
| Historical Sky130 mapped area before P0.3, 4x4, `D_HEAD=64`, `T_MAX=16` | 304,468 um²; current banked scheduler not yet remapped |

An optional version 2 build caches K for a whole command. At T=512 it lowers
traffic to 1,085,440 bytes and completes in 1,051,182 cycles. Simulated 8x8 and
16x16 default builds complete the same workload in 287,392 and 269,120 core
cycles. Their pre-P0.3 mapped cell areas at `T_MAX=16` are 571,637 and 1,446,323 um².
At `T_MAX=512`, the mapped 4x4 standard-cell areas are 1,596,280 um² for
the default design and 6,672,971 um² for register-based K reuse.
These variants have not closed full-chip timing or power. The
[design-space record](docs/results/design-space.md) compares their tradeoffs.

The 512 case contains 16,384 output tiles. These are simulation and synthesis
results, not measured silicon latency or CPU speedup. The custom FP32
multiplier still needs wider numerical qualification. See the
[reviewed measurement](docs/results/packed-engine.md) for test conditions and
limits.

## Run it

From the repository root:

```bash
make doctor
make test                    # lint, model, small integration suite
make test-integration-large  # T=64/128/512 at D_HEAD=64
make test-integration-reuse-large # optional K reuse version 2
make test-array8-large        # 8x8 simulated sweep
make test-array16-large       # 16x16 simulated sweep
make report-sim               # cycle, utilization, and byte CSV
python3 scripts/bench_cpu.py > build/cpu-benchmark.json
python3 scripts/eval_precision.py > build/synthetic-precision.json
./scripts/run_synthesis.sh 4 64 16
```

The CPU benchmark needs NumPy. Sky130 synthesis needs Yosys and the Sky130 HD
Liberty file; set `SKY130_LIB` if it is not in the local Volare installation.
`make lint` checks five parameter sets, including both stream versions at
`T_MAX=512` and the 8x8/16x16 variants.
Generated logs and binaries stay under ignored `build/`.

## Project map

Start at the [documentation index](docs/README.md), which lists every document
and what it is authoritative for. The short path:

- [Problem statements](docs/problem-statements/README.md): P0 active, P1 next, P2 shelved
- [Architecture](docs/architecture.md): blocks, dataflow, and the cycle cost model
- [Stream protocol](docs/stream-protocol.md): packet order, status codes, register map
- [Verification plan](docs/verification-plan.md): what each check proves, and the gaps
- [Development plan](docs/roadmap.md) and [decision records](docs/adr/README.md)
- [Project context](docs/project-context.md) and [repository layout](docs/repository-layout.md)
- [Latest verification](docs/results/latest-verification.md), [design space](docs/results/design-space.md), [synthetic precision](docs/results/precision.md)
- [Active RTL](rtl/README.md), [testbenches](tb/README.md), [reference model](model/README.md), [scripts](scripts/README.md)
- [Course archive](archive/README.md) and [superseded RTL](archive/superseded-rtl/README.md)

P0.2 selects 1x32 FP32 block scales for the next interface version. P0.3 now
overlaps load, compute, scale, and output, measuring 1.736x speedup and 99.945%
array activity at 4x4. The next RTL stage implements that scale format, and the K
scratchpad still needs banked storage rather than registers. Full-chip Sky130 timing, routing, and power
will decide whether 8x8 or 16x16 arrays are useful. The stage order and exit
conditions are in [the P0 plan](docs/problem-statements/p0-dense-fp4-matmul.md).

## Related

- [Documentation index](docs/README.md)
- [Problem statements](docs/problem-statements/README.md)
- [Changelog](CHANGELOG.md)
- [Contribution workflow](CONTRIBUTING.md)
