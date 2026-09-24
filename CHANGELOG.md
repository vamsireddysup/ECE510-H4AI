# Changelog

I record every change here that a reader of this repository would notice. Numbers
in this file are measured unless the entry says otherwise. For the layout and
naming rules these entries follow, see
[`docs/repository-layout.md`](docs/repository-layout.md).

## Unreleased

### Active engine

- Replaced the one-shot FP32 systolic datapath with a packed-stream engine that
  accumulates signed FP4 half-unit products as exact integers in quarter units
  and converts once per score. The superseded PE, array, controller, and buffers
  moved to [`archive/superseded-rtl/`](archive/superseded-rtl/README.md).
- Defined and versioned the 64-bit stream contract in
  [`docs/stream-protocol.md`](docs/stream-protocol.md): 16 FP4 codes or two FP32
  values per beat, per-packet `TLAST`, error codes for invalid `T` and for early
  or missing `TLAST`, and eleven read-only profiling registers.
- Added full tile-grid traversal with partial edge-tile masking, repeated
  commands without reset, and output that holds stable under backpressure.
- Made the AXI4-Lite write address and data channels independent, so they may
  arrive in either order or in the same cycle.
- Added an optional `K_REUSE=1` build that loads K once per command into an RTL
  scratchpad and reorders the stream to protocol version 2.
- Added `TILE_SIZE=8` and `16` builds, verified in simulation.
- Narrowed `K_REUSE` to a one-bit value at its five test sites, so
  `-GK_REUSE=1` lints clean under `-Wall` across Verilator versions.
- Replaced the serial tile FSM with concurrent input, compute, scaling, and output
  sequencers connected by two-bank Q, K, accumulator, and score storage. Extracted
  the parameterized score scaler into `rtl/core/score_scaler.sv`.

### Measurements

- At T=512 and `D_HEAD=64` the overlapped default 4x4 build produces 262,144
  correct scores in 1,049,150 simulated cycles, a 1.736x gain, while transferring
  3,166,208 bytes for 10.60 FLOP/byte. Array activity is 99.945%.
- Protocol version 2 cuts host traffic to 1,085,440 bytes and takes 1,051,182
  cycles after overlap. Its pre-P0.3 full-capacity register-scratchpad mapping was
  6,672,971 um² against 1,596,280 um² for version 1, so version 1 remains default.
- Simulated 8x8 and 16x16 builds complete T=512 in 287,392 and 269,120 cycles.
  Their one-lane scaler binds at 70 and 262 cycles per tile; measured array
  activity is 91.21% and 24.35%.
- Yosys maps the complete top, not an array-only wrapper, to Sky130 HD typical
  cells. These are synthesis areas with no routed timing or power.
- Recorded a fixed-seed synthetic FP4 score error of 14.90% relative Frobenius
  at T=512 under one explicit row-scale quantizer. See
  [`docs/results/precision.md`](docs/results/precision.md).
- Added a fixed-input one-thread NumPy CPU baseline at 3.72 measured GFLOP/s,
  replacing the archived CPU timing. It is observed throughput, not a peak.

### Tooling and repository

- Added `make` targets for the reuse and 8x8/16x16 variants, a five-set RTL lint,
  and `make report-sim` for cycles, utilization, and host bytes.
- Added `scripts/run_synthesis.sh`, `scripts/run_physical.sh`,
  `scripts/bench_cpu.py`, `scripts/eval_precision.py`, and
  `scripts/summarize_sim.py`, plus OpenLane configuration for the complete top.
- Added Apache-2.0 as `LICENSE`.
- Restricted `rtl/` to the modules listed in
  [`rtl/filelist.f`](rtl/filelist.f). Nine superseded modules moved to
  `archive/superseded-rtl/`.
- Renamed the documents under `docs/` to kebab-case, matching
  `docs/results/`.

### Repository migration, completed

These items came from the original reorganization plan, which has been retired in
favour of [`docs/repository-layout.md`](docs/repository-layout.md).

- Moved coursework, codefests, and old experiments under `archive/`, leaving only
  the active project at the repository root.
- Created the active `rtl/`, `tb/`, `model/`, and `scripts/` trees from the M4
  sources without changing module logic, and made `rtl/filelist.f` the single
  compile-order manifest.
- Added the `Makefile` command surface, `pyproject.toml`, `uv.lock`, and CI
  running documentation checks, lint, model tests, and the integration suite.
- Kept generated output out of Git and published CI transcripts as workflow
  artifacts.
- Made regressions fail on completion status, counters, handshakes, and
  backpressure rather than on numerical output alone.

## M4 course submission

- Verified one 4x4 `Q * K^T` tile with 16/16 correct outputs at `D_HEAD=4`, in a
  recorded 498 cycles. The untouched M4 test printed `DONE=NO`.
- Completed a Sky130 HD OpenLane run for the flat array wrapper, not the
  integrated chiplet: 324,753 um², 28.1 mW typical, 15 ns target, with negative
  nominal setup and hold slack.

## Related

- [Repository layout and naming rules](docs/repository-layout.md)
- [Decision records](docs/adr/README.md)
- [Documentation index](docs/README.md)
