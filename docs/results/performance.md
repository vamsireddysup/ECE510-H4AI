# Performance and design-space results

This record brings the verified single-engine measurements, parameter sweeps,
and replicated-engine projections together. Read it to compare configurations
without reconciling stage-coded reports. Each section retains its own provenance
and measured or projected label.

## Single-engine correctness and simulated cycles

The integration test checks every score against the same exact integer-dot
software 1x32 FP32 reference bit-exactly. It also checks packet `TLAST`, stable output under
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
| 1 | 64 | 1 | 1 | 159 | Injected |
| 4 | 64 | 16 | 1 | 199 | Injected |
| 7 | 64 | 49 | 4 | 389 | Injected |
| 8 | 64 | 64 | 4 | 404 | Injected |
| 16 | 64 | 256 | 16 | 1,204 | Injected |
| 64 | 64 | 4,096 | 256 | 16,577 | None |
| 128 | 64 | 16,384 | 1,024 | 65,857 | None |
| 512 | 64 | 262,144 | 16,384 | 1,049,665 | None |

At T=512, input and output beats are 265,216 and 131,072. The run performs
33,554,432 useful FLOPs and transfers 3,170,304 bytes, for 10.58 FLOP/byte at
the host-stream boundary. It sustains 0.24974 scores per cycle. The previous
serial controller took 1,821,184 cycles, so measured
speedup is 1.735x. The exact model attributes the 1,089 cycles above the
1,048,576-cycle compute floor to command fill and drain. Array activity is
99.896% after the format change.

The mathematical payload is 1,089,536 bytes: 32,768 bytes of Q/K FP4, 8,192
bytes of block scales, and 1,048,576 bytes of FP32 output. Repeated version 3 K
packets account for most excess traffic. P0.3 overlaps that traffic with compute
but does not remove it.

The archived 498-cycle compatibility run used `D_HEAD=4` and one 4x4 tile.
There are 16,384 output tiles in a 512x512 matrix. Its one-value-per-beat
schedule would transfer about 35.9 MB at `D_HEAD=64`, or about 0.93 FLOP/byte;
that workload was not runnable in the archived RTL.

## CPU baseline and synthesis evidence

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
for each output tile. Version 4 K reuse and 8x8/16x16 simulation and historical
mapped synthesis comparisons are compared later in this record.
Physical K scratchpad banking, post-P0.3 synthesis, SRAM macro fit, and routed
experiments remain open. FP32 quantization error against
real transformer activations was unmeasured in this run. The later
[P0.8 capture](precision.md) selects 1x16. The block layout is
not OCP MXFP4 because the active scales are FP32 rather than E8M0 as specified in the
[MX specification](https://www.opencompute.org/documents/ocp-microscaling-formats-mx-v1-0-spec-final-pdf).



## Replicated-engine shared-port cycle model

For `Nt=(T/B)^2` output tiles and `N` engines, each private engine receives
`ceil(Nt/N)` tiles. Its CALC and SCALING work therefore fall with N. The input
and output interfaces remain single 64-bit ports:

```text
CALC work       = ceil(Nt/N) * D
SCALING work    = ceil(Nt/N) * scaling_cycles_per_tile
OUTPUT floor    = Nt * ceil(B^2/2)
version 3 K work = Nt * ceil(B*D/16)
INPUT floor     = total accepted input beats
```

The projected command count is the maximum shared or private work term plus the
measured N=1 startup and fill/drain terms. It is also bounded below by the total
input beats. This construction reduces exactly to the existing closed-form model
at N=1, where all 16 recorded configurations still reproduce.

At 4x4, T=512, version 3 transfers 265,216 beats. Four engines reduce CALC work
to 262,144 cycles, so the input port becomes the limit at **265,216 cycles**.
Eight engines remain at the same count. The independent output derivation is
`262,144 scores / 2 scores per beat = 131,072 cycles`, so output would allow
eight engines; input binds first.

Version 4 changes the result because it transfers 5,120 input beats. Eight 4x4
engines have 131,072 CALC cycles and meet the same 131,072-cycle output floor.
The full projected command is **134,194 cycles** after 3,088 startup and 34
fill/drain cycles. Sixteen engines do not improve it.

| Design point | v3 projected cycles | v4 projected cycles | Binding work |
| --- | ---: | ---: | --- |
| one 4x4 | 1,049,666 measured | 1,051,698 measured | CALC |
| two 4x4 | 525,378 | 527,410 | CALC |
| four 4x4 | 265,216 | 265,266 | v3 input; v4 CALC |
| eight 4x4 | 265,216 | 134,194 | v3 input; v4 CALC/output tie |
| one 16x16 L4 | 132,362 measured | not measured | output |

The generated [full sweep](data/replicated-engine-cycles.csv) also covers 8x8 and
16x16 engines at N=1, 2, 4, 8, and 16 for both protocols. Regenerate it with:

```bash
python3 scripts/cycle_model.py \
  --replication-csv docs/results/data/replicated-engine-cycles.csv
```

## Replicated-engine mapped area breakdown

Revision `1a04b01` was mapped with Yosys 0.44
`80ba43d26`, the Sky130 HD typical library from Volare revision
`0fe599b2afb6708d281543108caf8310912f54af`, and no clock constraint. These are
mapped cell areas, not placed or routed areas.

| Hierarchical component | Instances in 4x4 L1 | Mapped area |
| --- | ---: | ---: |
| Top-local sequencing, arrays, buffers, and dot logic | 1 | 437,588 um² |
| AXI4-Lite control | 1 | 8,209 um² |
| Score scaler local logic plus four FP32 multipliers | 1 | 106,812 um² |
| Score reducer local logic plus one FP32 adder | 1 | 13,126 um² |
| Complete hierarchy | 1 | **565,736 um²** |

The hierarchy cleanly identifies the AXI block and scale path. The top-local
module still mixes shared scale storage and frontend sequencing with per-engine
Q/K tile buffers, accumulator and score banks, and dot logic. I will not assign
an invented split to that 437,588 um². Sharing only the measured AXI block gives
conservative projections of 2,238,318 um² for four engines and 4,468,427 um²
for eight. Sharing K and scale storage would lower them, but needs the actual
multi-engine RTL before its mux and fanout cost can be measured.

A same-revision 16x16 L4 standalone synthesis did not finish memory-priority
lowering after 20 minutes and 2.3 GiB, so there is no new comparable 16x16 area.
The older 1,446,323 um² number predates the overlapping scheduler and block
scalers and is not silently substituted. The machine-readable
[area record](data/replicated-engine-area.csv) preserves both the result and the gap.

## Replicated-engine ordering decision

Replication should keep the existing ordered score stream. Each engine bank
will carry its global tile ordinal, and a shared output arbiter will drain only
the bank holding the next ordinal. With two score banks per engine, later tiles
can finish while an earlier tile drains. This is a bounded internal reorder
buffer and keeps protocol versions 3 and 4 unchanged.

Adding an explicit tile header would require a later protocol version (version
7 is the next unused identifier) and one extra
64-bit beat per 4x4 tile. That raises the T=512 output floor from 131,072 to
147,456 cycles, a 12.5% penalty exactly where eight engines need the output
port. I reject that option for the first prototype.

## Replication recommendation

Do not build eight 4x4 engines under version 3. They have the same projected
265,216 cycles as four engines, while the shared-AXI area projection nearly
doubles. Eight engines become competitive only with version 4: 134,194 cycles
is close to the measured 132,362 cycles of one 16x16 L4 array.

For the next route, keep **one 16x16 L4** as the second candidate after the
optimized 4x4 route. It has the better current cycle result, existing verified
RTL, and the historical area evidence is far below the conservative eight-engine
projection. Reopen a four-engine 4x4 prototype after a shared-K broadcast and
reorder-buffer RTL plan exists; it is the useful replication point for version
3 and a smaller physical experiment than eight engines.


## Related

- [Project status](../project-status.md)
- [Architecture](../architecture.md)
- [Physical design](physical-design.md)
- [Results index](README.md)
