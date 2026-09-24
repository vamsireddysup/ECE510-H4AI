# Packed engine verification and measurement

The cycle table below was re-measured on `master` at `e3ce10b` with Verilator
5.020 and again with 5.042, which agree on every value. The traffic, CPU, and synthesis figures below it come from the earlier
revision `8abc7b9` and its Verilator 5.041 runs, and are unchanged.

The active top is `qkt_chiplet_top` with a 4x4 integer dot-product array and two
FP32 scale multipliers. All cycle figures are Verilator simulations. The
host-stream boundary is the two 64-bit AXI4-Stream ports; transferred bytes are
accepted input and output beats times eight.

## Correctness and simulated cycles

The integration test checks every score against an exact integer-dot reference,
with binary-power row scales. It also checks per-packet `TLAST`, output
stability under backpressure, padding, beat counts, tile counts, error codes,
reset, and repeated commands. The original 4x4 numerical pattern is included.

| T | D_HEAD | Scores | Tiles | Core cycles | Host stalls |
| ---: | ---: | ---: | ---: | ---: | --- |
| 1 | 4 | 1 | 1 | 17 | Injected |
| 4 | 4 | 16 | 1 | 49 | Injected |
| 7 | 4 | 49 | 4 | 150 | Injected |
| 8 | 4 | 64 | 4 | 181 | Injected |
| 16 | 4 | 256 | 16 | 691 | Injected |
| 1 | 64 | 1 | 1 | 155 | Injected |
| 4 | 64 | 16 | 1 | 187 | Injected |
| 7 | 64 | 49 | 4 | 624 | Injected |
| 8 | 64 | 64 | 4 | 655 | Injected |
| 16 | 64 | 256 | 16 | 2,431 | Injected |
| 64 | 64 | 4,096 | 256 | 28,736 | None |
| 128 | 64 | 16,384 | 1,024 | 114,304 | None |
| 512 | 64 | 262,144 | 16,384 | 1,821,184 | None |

Input and output beats at T=512 are 264,704 and 131,072. The small-suite beat
counts vary with the injected stall pattern, so they are not tabulated here; the
testbench asserts them exactly against a closed-form expression on every run.

An earlier version of this table reported every core-cycle figure one higher than
register `0x10` returns, and omitted the T=1 and T=8 cases the suite runs. The
values above are re-measured from `build/integration/*/run.log` and are identical
under Verilator 5.020 and 5.042, so the discrepancy was not a simulator
difference. Every other column of the earlier table was correct, and
[`README.md`](../../README.md) and [`design-space.md`](design-space.md) already
carried the correct 49 and 1,821,184.

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

## Related

- [Results index](README.md)
- [Architecture and the cycle model](../architecture.md)
- [Design-space experiment](design-space.md)
