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
| `generate_precision_capture.py` | `make test-precision-rtl` | pinned NumPy | `build/precision-rtl/t512-bs16.bin` |
| `run_precision_rtl.sh` | `make test-precision-rtl` | Verilator, g++, pinned NumPy | `build/precision-rtl/{build,run}.log` |
| `run_m4_baseline.sh` | `make baseline`, `make baseline-strict` | Verilator, g++ | `build/m4-baseline/{build,run}.log` and `build/m4-baseline/summary.txt` |
| `summarize_sim.py` | `make report-sim` | Python 3.10+ | `build/integration/summary.csv`, read from every `build/integration/*/run.log` |
| `cycle_model.py` | run directly | Python 3.10+ | stdout only; exits non-zero if the model no longer matches all 24 measured configurations |
| `eval_precision.py` | run directly | NumPy | stdout JSON with the block-scale sweep; redirect to `build/data/synthetic-precision-sweep.json` |
| `capture_transformer_qk.py` | P0.8 documented command | PyTorch 2.8.0+cpu, Transformers 4.56.2, NumPy | deterministic NPZ at the requested path |
| `bench_cpu.py` | run directly | NumPy | stdout JSON; redirect to `build/cpu-benchmark.json` |
| `run_synthesis.sh` | run directly as `./scripts/run_synthesis.sh TILE DEPTH TMAX [REUSE] [BLOCK] [LANES]` | Yosys, Sky130 HD Liberty | `build/synthesis/t<tile>-d<depth>-max<tmax>-reuse<reuse>-sb<block>-sl<lanes>/yosys.log` |
| `run_physical.sh` | `./scripts/run_physical.sh RUN PERIOD [TILE] [LANES] [MODE]` | Docker, pinned OpenLane image, Sky130 PDK | `build/physical/<run-name>/`, with an absolute die area, generated config, manifest, log, and `runs/full/`; use mode `synthesis` for a reproducible synthesis-only checkpoint. Mode `global-route` stops after global routing without timing repair. `ENGINES`, `SYNTH_STRATEGY`, `SYNTH_SIZING`, `SYNTH_BUFFERING`, `STD_CELL_LIBRARY`, `MAX_TRANSITION_CONSTRAINT`, and `SYNTH_CLOCK_PERIOD` (a separate synthesis target) are environment overrides |
| `sweep_synthesis.sh` | `./scripts/sweep_synthesis.sh PREFIX "PERIODS" "STRATEGY|STRATEGY" [JOBS]` | Docker, pinned OpenLane image | one synthesis-only `run_physical.sh` run per period and strategy, `JOBS` at a time |
| `check_cycle_model.py` | `python3 scripts/check_cycle_model.py` | Verilator, Python | re-simulates every recorded cycle-model configuration and fails on any mismatch |
| `collect_synthesis.py` | `python3 scripts/collect_synthesis.py "build/physical/GLOB" --csv FILE` | Python, Docker, pinned OpenLane image | cells, mapped area, and typical and slow worst path per synthesis run |
| `sta/endpoint_paths.tcl` | inside the OpenLane image as `sta -exit -no_init`, with `RUN_DIR`, `LIB`, and `PATHS` set | OpenSTA in the pinned image | ranked worst setup endpoints with the RTL register behind each instance |
| `rank_endpoints.py` | `python3 scripts/rank_endpoints.py STA_OUTPUT [--csv FILE] [--top N]` | Python | endpoints grouped by owning block, plus the worst endpoint per block pair |
| `sweep_routed_timing.sh` | run after a completed physical run | Docker, pinned OpenLane image, routed netlist and maximum-RC SPEF | `build/physical/<run-name>/timing-sweep.{tcl,log}` with multi-corner setup and hold at each requested period |
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
