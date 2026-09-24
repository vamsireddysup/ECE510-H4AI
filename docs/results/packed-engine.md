# Packed engine verification and measurement

The cycle table was measured on `master` at revision `08a307d` with Verilator
5.041 after P0.3 overlapped load, compute, scale, and output. Synthesis figures
later in this record come from pre-overlap revisions and do not measure the
added banks or scheduler.

The active top is `qkt_chiplet_top`. All cycle figures are RTL simulations. The
host-stream boundary is the two 64-bit AXI4-Stream ports; transferred bytes are
accepted input and output beats times eight.

## Correctness and simulated cycles

The integration test checks every score against the same exact integer-dot
reference used before P0.3. It also checks packet `TLAST`, stable output under
backpressure, padding, beat and tile counts, malformed packets, reset, and
repeated commands. P0.3 changes cycle placement only; every numerical score in
all required suites remains equal to the pre-overlap reference.

| T | D_HEAD | Scores | Tiles | Core cycles | Host stalls |
| ---: | ---: | ---: | ---: | ---: | --- |
| 1 | 4 | 1 | 1 | 18 | Injected |
| 4 | 4 | 16 | 1 | 49 | Injected |
| 7 | 4 | 49 | 4 | 99 | Injected |
| 8 | 4 | 64 | 4 | 123 | Injected |
| 16 | 4 | 256 | 16 | 403 | Injected |
| 1 | 64 | 1 | 1 | 154 | Injected |
| 4 | 64 | 16 | 1 | 188 | Injected |
| 7 | 64 | 49 | 4 | 373 | Injected |
| 8 | 64 | 64 | 4 | 385 | Injected |
| 16 | 64 | 256 | 16 | 1,169 | Injected |
| 64 | 64 | 4,096 | 256 | 16,510 | None |
| 128 | 64 | 16,384 | 1,024 | 65,726 | None |
| 512 | 64 | 262,144 | 16,384 | 1,049,150 | None |

At T=512, input and output beats remain 264,704 and 131,072. The run performs
33,554,432 useful FLOPs and transfers 3,166,208 bytes, for 10.60 FLOP/byte at
the host-stream boundary. It sustains 0.24986 scores per cycle and 99.945% array
activity. The previous serial controller took 1,821,184 cycles, so measured
speedup is 1.736x. The exact model attributes the 574 cycles above the
1,048,576-cycle compute floor to command fill and drain.

The mathematical payload is 1,085,440 bytes: 32,768 bytes of Q/K FP4, 4,096
bytes of row scales, and 1,048,576 bytes of FP32 output. Repeated version 1 K
packets account for most excess traffic. P0.3 overlaps that traffic with compute
but does not remove it.

The archived 498-cycle compatibility run used `D_HEAD=4` and one 4x4 tile.
There are 16,384 output tiles in a 512x512 matrix. Its one-value-per-beat
schedule would transfer about 35.9 MB at `D_HEAD=64`, or about 0.93 FLOP/byte;
that workload was not runnable in the archived RTL.

## CPU baseline and physical evidence

`scripts/bench_cpu.py` fixes FP4-derived inputs, seed 510, seven timed trials,
NumPy 1.26.4, and one requested BLAS thread. The system NumPy build reports
`blas` without a detectable thread pool, so thread count is an environment
setting rather than a verified runtime property. On this x86_64 machine, a
512x64 QK^T using FP32 NumPy matmul had a 9.016 ms median and 3.72 measured GFLOP/s.
This is an observed implementation throughput, not the CPU peak used in a
[Roofline model](https://www2.eecs.berkeley.edu/Pubs/TechRpts/2008/EECS-2008-134.html).
The benchmark JSON is generated under `build/`.

Yosys 0.44 mapped the full top (AXI control, tile storage, integer array, and
both scale multipliers) to Sky130 HD typical 25 C, 1.80 V standard cells.
At `TILE_SIZE=4`, `T_MAX=16`, mapped cell area was 204,039 um² for `D_HEAD=4`
and 303,141 um² for `D_HEAD=64`. These are synthesis areas only. There is no
post-route timing, physical area, or power measurement for the active top, so
no frequency, latency in seconds, energy, or CPU speedup is claimed. The
archived 15 ns array-only timing report has negative nominal setup and hold
slack and cannot close this top by inference.

The default `D_HEAD=64` design uses two Q and K tile banks and still reloads K
for each output tile. Version 2 K reuse and 8x8/16x16 simulation and historical
mapped synthesis comparisons are in the [design-space record](design-space.md).
Physical K scratchpad banking, post-P0.3 synthesis, SRAM macro fit, and routed
experiments remain open. FP32 quantization error against
real transformer activations is also unmeasured. The row-scale protocol is
not OCP MXFP4, which specifies 32-value blocks and E8M0 scales in the
[MX specification](https://www.opencompute.org/documents/ocp-microscaling-formats-mx-v1-0-spec-final-pdf).

## Related

- [Results index](README.md)
- [Architecture and the cycle model](../architecture.md)
- [Design-space experiment](design-space.md)
