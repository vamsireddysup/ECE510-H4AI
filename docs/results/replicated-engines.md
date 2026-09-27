# Replicated-engine study

This study asks whether several small 4x4 engines are a better scaling path than
one wider array. No replicated RTL exists yet. N=1 cycle rows are measured and
exact; N greater than one is a projected, ideal arbitration model.

## Shared-port cycle model

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

The generated [full sweep](replicated-engine-model.csv) also covers 8x8 and
16x16 engines at N=1, 2, 4, 8, and 16 for both protocols. Regenerate it with:

```bash
python3 scripts/cycle_model.py \
  --replication-csv docs/results/replicated-engine-model.csv
```

## Mapped area breakdown

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
[area record](p0-b-area.csv) preserves both the result and the gap.

## Ordering decision

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

## Recommendation

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

This direction follows established clustered and partitionable accelerator
work: [Simba](https://doi.org/10.1145/3352460.3358302) measures fine-grained
multi-chip tiling, [Planaria](https://www.microarch.org/micro53/papers/738300a681.pdf)
fissions an array dynamically, [SIGMA](https://doi.org/10.1109/HPCA47549.2020.00015)
uses a flexible interconnect for scalable irregular GEMM, and
[Eyeriss v2](https://arxiv.org/abs/1807.07928) clusters PEs behind a hierarchical
mesh. They support studying small replicated units; they do not remove this
design's measured shared-port and mapped-area limits.

## Related

- [Results index](README.md)
- [Critical-path optimization](critical-path.md)
- [Architecture](../architecture.md)
- [Development plan](../roadmap.md)
