# Scripts

Every script here is the implementation behind a `make` target or a documented
command. Read this to find out what a script needs and where it writes. The
[`Makefile`](../Makefile) is the stable interface; these scripts may change.

All of them run from the repository root.

| Script | Behind | Needs | Writes |
| --- | --- | --- | --- |
| `doctor.sh` | `make doctor` | nothing | stdout only; exits non-zero if a required tool is missing |
| `check_markdown.py` | `make check-docs` | Python 3.10+ | stdout only |
| `lint.sh` | `make lint` | Verilator | stdout only; lints eight parameter sets |
| `read_filelist.sh` | sourced by `lint.sh` and `run_integration.sh` | nothing | nothing; exports `RTL_SOURCES` from [`rtl/filelist.f`](../rtl/filelist.f) |
| `run_integration.sh` | the `test-integration*`, `test-array8*`, and `test-array16*` targets | Verilator, g++ | `build/integration/b<tile>-t<tmax>-d<depth>-reuse<reuse>-sb<block>-sl<lanes>/{build,run}.log` |
| `generate_precision_capture.py` | `make test-precision-rtl` | pinned NumPy | `build/precision-rtl/t512-bs32.bin` |
| `run_precision_rtl.sh` | `make test-precision-rtl` | Verilator, g++, pinned NumPy | `build/precision-rtl/{build,run}.log` |
| `run_m4_baseline.sh` | `make baseline`, `make baseline-strict` | Verilator, g++ | `build/m4-baseline/{build,run}.log` and `build/m4-baseline/summary.txt` |
| `summarize_sim.py` | `make report-sim` | Python 3.10+ | `build/integration/summary.csv`, read from every `build/integration/*/run.log` |
| `cycle_model.py` | run directly | Python 3.10+ | stdout only; exits non-zero if the model no longer matches all 16 measured configurations |
| `eval_precision.py` | run directly | NumPy | stdout JSON with the block-scale sweep; redirect to `build/p0-2-precision.json` |
| `bench_cpu.py` | run directly | NumPy | stdout JSON; redirect to `build/cpu-benchmark.json` |
| `run_synthesis.sh` | run directly as `./scripts/run_synthesis.sh TILE DEPTH TMAX [REUSE] [BLOCK] [LANES]` | Yosys, Sky130 HD Liberty | `build/synthesis/t<tile>-d<depth>-max<tmax>-reuse<reuse>-sb<block>-sl<lanes>/yosys.log` |
| `run_physical.sh` | `./scripts/run_physical.sh RUN PERIOD [TILE] [LANES] [MODE]` | Docker, pinned OpenLane image, Sky130 PDK | `build/physical/<run-name>/`, with an absolute die area, generated config, manifest, log, and `runs/full/` |
| `clean.sh` | `make clean` | nothing | removes `build/` and `.pytest_cache/` only |

## Conventions

A script writes only under `build/`, never beside source. `clean.sh` removes only
the two paths named above, never an arbitrary path.

`run_synthesis.sh` finds the Sky130 HD Liberty file in a local Volare
installation. Set `SKY130_LIB` to override it.

A script that produces a number a document cites prints it in a machine-readable
form, so the document can be regenerated rather than retyped.

## Related

- [Verification plan](../docs/verification-plan.md)
- [Results and transcripts](../docs/results/README.md)
- [Repository layout](../docs/repository-layout.md)
