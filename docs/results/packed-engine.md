# Packed engine verification and measurement

This record covers RTL revision `8abc7b9` plus the test and documentation
updates in this commit. The active top is `qkt_chiplet_top` with a 4x4 integer
dot-product array and two FP32 scale multipliers. All cycle figures are
Verilator simulations. The host-stream boundary is the two 64-bit AXI4-Stream
ports; transferred bytes are accepted input and output beats times eight.

## Correctness and simulated cycles

The integration test checks every score against an exact integer-dot reference,
with binary-power row scales. It also checks per-packet `TLAST`, output
stability under backpressure, padding, beat counts, tile counts, error codes,
reset, and repeated commands. The original 4x4 numerical pattern is included.

| T | D_HEAD | Scores | Tiles | Core cycles | Input beats | Output beats | Host stalls |
| ---: | ---: | ---: | ---: | ---: | ---: | ---: | --- |
| 4 | 4 | 16 | 1 | 50 | 6 | 8 | Injected |
| 7 | 4 | 49 | 4 | 151 | 13 | 25 | Injected |
| 16 | 4 | 256 | 16 | 692 | 36 | 128 | Injected |
| 4 | 64 | 16 | 1 | 188 | 36 | 8 | Injected |
| 7 | 64 | 49 | 4 | 625 | 103 | 25 | Injected |
| 16 | 64 | 256 | 16 | 2432 | 336 | 128 | Injected |
| 64 | 64 | 4096 | 256 | 28,737 | 4,416 | 2,048 | None |
| 128 | 64 | 16,384 | 1,024 | 114,305 | 17,024 | 8,192 | None |
| 512 | 64 | 262,144 | 16,384 | 1,821,185 | 264,704 | 131,072 | None |

The 512 run performs 33,554,432 useful FLOPs (multiply and add counted
separately). It transfers 3,166,208 bytes, for 10.60 FLOP/byte at the named
host-stream boundary and 0.144 scores per core cycle. The mathematical payload
is 1,085,440 bytes: 32,768 bytes of Q/K FP4, 4,096 bytes of row scales, and
1,048,576 bytes of FP32 output. Repeated K packets account for most excess
traffic. The 64-bit output port can carry two scores per cycle; this design
averages below that because input reload and tile work are serial.

The archived 498-cycle compatibility run used `D_HEAD=4` and one 4x4 tile.
There are 16,384, not 262,144, such output tiles in a 512x512 matrix.
The archived 512 projection therefore does not predict this design. Its
one-value-per-beat schedule would transfer about 35.9 MB at `D_HEAD=64`, or
about 0.93 FLOP/byte; that workload was not runnable in the archived RTL.

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

The default `D_HEAD=64` design uses a single Q tile and reloads K for each
output tile. Version 2 K reuse and 8x8/16x16 simulation and mapped synthesis
comparisons are in the [design-space record](design-space.md). Physical K
scratchpad banking, double buffering, SRAM macro fit, and routed experiments
remain open. FP32 quantization error against
real transformer activations is also unmeasured. The row-scale protocol is
not OCP MXFP4, which specifies 32-value blocks and E8M0 scales in the
[MX specification](https://www.opencompute.org/documents/ocp-microscaling-formats-mx-v1-0-spec-final-pdf).
