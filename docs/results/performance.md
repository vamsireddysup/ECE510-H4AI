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
warmup, auto-scaled repeats, and a median of trials. The one-thread path is
unchanged from the original baseline; the host block, the `--all-cores` mode,
and the theoretical peak are additions, so re-running the one-thread path
isolates the machine from the method.

### Host

| Item | Value |
| --- | --- |
| CPU | 11th Gen Intel Core i5-1145G7 |
| Cores | 4 physical, 8 logical |
| Clock | 2.6 GHz nominal, 1.5 GHz sysfs base, 4.4 GHz sysfs maximum |
| Detected ISA | AVX-512F, AVX-512DQ, AVX2, FMA |
| Memory | 16.1 GB |
| OS | Linux 7.0.0-34-generic, Ubuntu 24.04 |
| Python | 3.12.3 |

### The one-thread claim, resolved

The system NumPy 1.26.4 links `/lib/x86_64-linux-gnu/libblas.so.3`, which is
Debian's **reference Netlib BLAS 3.12.0**, not OpenBLAS. `threadpool_info()`
returns an empty list because reference BLAS has no thread pool to query, not
because detection failed. Reference BLAS is single-threaded by construction, so
the one-thread claim holds; the `--all-cores` run confirms it empirically,
measuring 9.0722 ms against 9.0625 ms with no speedup at all.

That resolves the provenance question and exposes a larger one: reference BLAS
is a weak opponent. I therefore also measured an isolated environment with
NumPy 2.5.3 and its bundled OpenBLAS 0.3.34.106.0, using the same script,
inputs, and seed.

### Measured T=512, `D_HEAD=64`

| BLAS | Mode | Median | Measured | Fraction of single-core peak |
| --- | --- | ---: | ---: | ---: |
| Reference Netlib 3.12.0 | one thread | 9.0625 ms | 3.703 GFLOP/s | 2.63% |
| Reference Netlib 3.12.0 | all cores | 9.0722 ms | 3.699 GFLOP/s | not applicable |
| OpenBLAS 0.3.34.106.0 | one thread | 0.2932 ms | 114.456 GFLOP/s | 81.29% |
| OpenBLAS 0.3.34.106.0 | all cores, 8 threads | 0.1422 ms | 235.893 GFLOP/s | not applicable |

The previously recorded figure was 9.016 ms and 3.72 GFLOP/s. The refreshed
one-thread reference-BLAS median is 9.0625 ms and 3.703 GFLOP/s, a 0.5%
difference, so the host has not materially changed and the old number was
sound for what it measured. **OpenBLAS on one thread is 30.9x faster than
that baseline on the identical problem, and 63.7x faster across four cores.**

### The theoretical peak, which is not a baseline

From the detected AVX-512 support and the 4.4 GHz sysfs maximum, one core
retires 16 FP32 lanes times two FLOPs per fused multiply-add per FMA unit. The
number of 512-bit FMA issue ports is not detectable from software here, so both
cases are reported: **140.8 GFLOP/s** with one unit and **281.6 GFLOP/s** with
two. This is a ceiling. It is never used as the baseline, and it is not a
[Roofline](https://www2.eecs.berkeley.edu/Pubs/TechRpts/2008/EECS-2008-134.html)
ceiling without an explicit memory boundary and measured bandwidth.

Reference BLAS reaches 2.63% of the one-unit peak. OpenBLAS reaches 81.29%,
which shows the gap is the library rather than the problem shape. Smaller
sequence lengths do fall away as expected: OpenBLAS measures 54.99% of peak at
T=64 and 17.15% at T=16, because a reduction depth of only 64 gives the packed
kernel little to amortize.

The measurement is **warm-cache by construction**. Q, K, and the output buffer
are reused across every repeat, and the roughly 1.3 MB working set stays
resident in the 5 MiB L2. That favours the CPU, so this baseline is
conservative from the accelerator's side.

The reviewed rows are in [`data/cpu-baseline.csv`](data/cpu-baseline.csv); the
full JSON with host and threadpool provenance is generated under `build/`.

### What this means for the accelerator

Applying the 30.5 ns setup-only bound, which is not a closed clock:

| Configuration | Projected latency | Versus reference BLAS one thread | Versus OpenBLAS one thread | Versus OpenBLAS all cores |
| --- | ---: | ---: | ---: | ---: |
| 4x4, one engine, v5 | 32.05 ms | 0.28x | 0.009x | 0.004x |
| Eight 4x4 engines, v6 | 4.13 ms | 2.20x | 0.071x | 0.035x |

Against a competently optimized BLAS the CPU wins outright on wall clock, by
14x against the best accelerator configuration on one thread and 29x on four.
That is the expected outcome for a 32.9 MHz Sky130 part and it should not be
restated as a win. The defensible comparison for this project is energy and
area per score, and neither is available yet: the route fails hold and its
dynamic power is rejected, and the replicated top has no synthesis or route at
all. No energy claim is made here.

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

## Measured replicated-engine results

The replicated RTL now exists. `ENGINES` instantiates that many `qkt_engine`
blocks under one `qkt_chiplet_top`. Engine `i` owns the output tile columns
congruent to `i` modulo `ENGINES`, so every engine works on the same Q tile row.
The table is **measured** at revision `ca8f9fd` with Verilator 5.041, 4x4,
`D_HEAD=64`, `T_MAX=512`, Bs=16, one score lane, and a continuously ready host.
Every run produced all 262,144 scores bit-exactly.

| Protocol | Engines | Core cycles | Input beats | Speedup over N=1 | Binding work |
| --- | ---: | ---: | ---: | ---: | --- |
| v5 | 1 | 1,050,696 | 266,240 | 1.000x | CALC |
| v5 | 2 | 526,424 | 266,240 | 1.996x | CALC |
| v5 | 4 | 266,344 | 266,240 | 3.945x | input |
| v5 | 8 | 266,344 | 266,240 | 3.945x | input |
| v5 | 16 | 266,344 | 266,240 | 3.945x | input |
| v6 | 1 | 1,052,728 | 6,144 | 1.000x | CALC |
| v6 | 2 | 528,448 | 6,144 | 1.992x | CALC |
| v6 | 4 | 266,320 | 6,144 | 3.953x | CALC |
| v6 | 8 | 135,280 | 6,144 | 7.782x | output |
| v6 | 16 | 135,280 | 6,144 | 7.782x | output |

Both projected limits hold. Version 5 stops improving at four engines because
the shared 64-bit input port must still accept 266,240 beats. Version 8 engines
under version 6 reach 135,280 cycles against the 131,072-cycle output floor, and
sixteen engines do not improve on that, because two FP32 scores per cycle is the
port's steady ceiling. The reviewed rows are in
[`data/replicated-engine-measured.csv`](data/replicated-engine-measured.csv).

The earlier 265,216 and 134,194 projections were Bs=32 numbers. The Bs=16
default adds 1,024 scale beats and three cross-block adds, so its comparable
projections are 266,240 and 135,224.

### An open model error

The shared-port model reproduces every measured input-beat count exactly and
remains exact at N=1, but it underestimates every measured N>1 command:

| Configuration | Projected | Measured | Error |
| --- | ---: | ---: | ---: |
| v5 N=2 | 526,408 | 526,424 | +16 |
| v5 N=4, 8, 16 | 266,240 | 266,344 | +104 |
| v6 N=2 | 528,440 | 528,448 | +8 |
| v6 N=4 | 266,296 | 266,320 | +24 |
| v6 N=8, 16 | 135,224 | 135,280 | +56 |

For version 6 at N=2, 4, and 8 the error is exactly `8*(N-1)`, which is
`(N-1)` times the 8-cycle per-tile output service time. That is consistent with
the final `N-1` tiles draining serially through the one output port at the end
of a command, which the model's single fill-and-drain term does not carry. The
pattern does not continue at N=16, and the version 5 errors do not fit it, so I
am recording the measurement as the authority and leaving the model unchanged
rather than fitting a correction I have not derived. `scripts/cycle_model.py`
prints this error table and still fails only on a single-engine mismatch.

## Replication recommendation

Do not build eight 4x4 engines under version 3. They have the same projected
265,216 cycles as four engines, while the shared-AXI area projection nearly
doubles. Eight engines become competitive only with version 4: 134,194 cycles
is close to the measured 132,362 cycles of one 16x16 L4 array.

The bounded 16x16 synthesis investigation later showed that its dynamic
accumulator ports do not scale through the available Yosys flow. [ADR
0006](../adr/0006-use-replicated-4x4-engines.md) therefore selects replicated
4x4 engines as the next RTL and physical prototype. Checkpoint 1 of that
decision is now complete and measured above. Mapped hierarchy area and a routed
result remain open, so the 4,468,427 um² projection is still the only area
number for eight engines.


## Related

- [Project status](../project-status.md)
- [Architecture](../architecture.md)
- [Physical design](physical-design.md)
- [Results index](README.md)
