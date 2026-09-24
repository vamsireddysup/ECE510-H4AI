# P1: format-agile precision and sparsity

This is the next problem statement. It starts no earlier than P0.4, because
measuring the cost of changing format needs a settled baseline format and a
settled accumulator. Read it to see the thesis and how it will be tested.

## The question

> How can an AI accelerator dynamically select FP4/INT4/FP8 precision and exploit
> sparsity according to layer/workload characteristics to minimize memory traffic
> and energy while maintaining accuracy?

## The thesis

Published precision-scalable MAC work reaches format agility by bit-slicing and
shift-add composition, and pays for it: benchmarking across 72 architectures in
28 nm reports that spatial sub-computation designs can need up to 4.4x the area of
a fixed MAC, with shift-add logic alone accounting for roughly 67% of area and 79%
of power.

P0's datapath is a different substrate. It already decodes to small signed
integers and accumulates exactly, deferring all rounding to one conversion. On
that substrate, changing format means changing a decode front-end and an
accumulator width, with no reconfigurable multiplier topology.

The testable claim: **for MX block formats, format agility bought through exact
integer accumulation costs accumulator width and decode logic, not multiplier
reconfiguration, and the crossover against sub-word-parallel scaling is
measurable.**

## Accumulator width, worked at `D_HEAD=64`

This is the arithmetic the thesis rests on.

**FP4 E2M1**, decoded to half units with magnitudes 0, 1, 2, 3, 4, 6, 8, 12.
Maximum product `12 * 12 = 144` in quarter units. Over 64 terms,
`144 * 64 = 9216`, so `ceil(log2(9217)) = 14` bits plus sign: **15 bits**. This is
`ACC_W` today.

**INT4 signed**, range -8 to 7. Maximum product `(-8) * (-8) = 64`. Over 64 terms,
`64 * 64 = 4096`, so `ceil(log2(4097)) = 13` bits plus sign: **14 bits**. It fits
the existing accumulator unchanged, so INT4 costs a decode change and nothing
else.

**FP8 E4M3**, smallest subnormal `2^-9`, largest normal 448. As an integer in
units of `2^-9` the maximum is `448 * 512 = 229,376`, which is 18 bits. The
product is `229,376^2 = 52,613,349,376`, which is 36 bits. Over 64 terms,
`3.367e12`, which is 42 bits plus sign: **43 bits**.

So covering all three exactly widens the accumulator from 15 to 43 bits, a factor
of 2.87. At `TILE_SIZE=4` there are 16 accumulators, so the incremental cost is
`(43 - 15) * 16 = 448` flip-flops plus wider adders. That is the figure to put
against the published 4.4x.

**Two costs that are not hidden.** FP8 decode is a 4-bit significand shifted by up
to 17 positions, so an 18-bit barrel shifter per operand; moving it to load time
makes it `O(B*D)` rather than `O(B^2*D)` but widens the tile buffer. And an
18 by 18 multiplier idles in FP4 mode, and recovering that waste by packing narrow
multiplies into it is option M4 below, which reintroduces the overhead the thesis
claims to avoid. The contribution is locating the crossover for MX formats on a
small engine, not escaping the tradeoff.

## The multiplier study

Five options, format held at FP4, each bit-exact against the Python model and
synthesized separately so area differences are attributable.

| Option | Design | Role |
| --- | --- | --- |
| M0 | Decode to signed half units, then a signed multiply, accumulated exactly | The current design, and the reference for the other four |
| M1 | Select and shift | The nonzero decode magnitudes are `{1,2,4,8}` and `{3,6,12}`, which is `{1,3} * 2^e`, so a product is `(m1*m2) << (e1+e2)` with `m1*m2` in `{1,3,9}` and the shift in `0..6`, reaching `9 << 4 = 144`. A 4-bit mux and a small shifter, exact, no multiplier |
| M2 | The 256-entry FP4 product ROM in [`archive/superseded-rtl/fp4_mul_lut.sv`](../../archive/superseded-rtl/fp4_mul_lut.sv) | Already verified against the model, so a free comparison point |
| M3 | One integer multiplier sized for the widest supported format, FP4 and INT4 using the low bits | The thesis position |
| M4 | Sub-word-parallel packing of several narrow multiplies into one wide unit | The opposing position; M3 against M4 is what makes the study a result |

M1's structure has not surfaced in my literature search stated for E2M1, but it
follows directly from the format and may exist in industrial designs, so it is
supporting work rather than a headline claim.

## The sparsity question

Sparsity here is coupled to precision, not orthogonal to it. FP4 quantization
manufactures zeros, because any value below half a scale unit maps to code 0, and
E2M1 has two zero encodings. Published work finds that quantization and sparsity
interact and that their errors are not additive.

The dataflow constrains what is exploitable. `depth` is one shared index driving
all `TILE_SIZE^2` accumulators in the same cycle, so a reduction step can only be
skipped when an entire Q or K column is zero. Per-element skipping needs per-PE
operand queues, which is a large change. Structured N:M along the reduction axis
composes with a shared index but requires changing the quantizer, so it is
hardware and software co-design.

This stage is therefore a measurement with a predicted negative answer: measure
the zero-code fraction and the all-zero-column fraction as a function of format and
block size, and propose a mechanism only if the measurement justifies one. A
measured negative result is the honest deliverable if that is what the data says.

## Stages

| Stage | Work |
| --- | --- |
| P1.1 | Model support for INT4 and FP8 E4M3, with accuracy on the same inputs as P0.2 |
| P1.2 | The multiplier study: M0 through M4 at fixed format, each synthesized |
| P1.3 | The format-agile datapath: widened accumulator, load-time decode |
| P1.4 | The sparsity measurement |
| P1.5 | The selection policy and its descriptor or register interface |
| P1.6 | The comparison matrix and its Pareto front |

P1.5 comes last because a policy that selects between formats is meaningless until
each format has a measured cost.

## Before P1.2 starts

The closest prior art claims support for all six MX data types in TSMC 16 nm. Only
its abstract has been read. Its full text must be read and this thesis re-checked;
if the gap closes, P1 changes.

## Related

- [Problem statements](README.md)
- [P0](p0-dense-fp4-matmul.md)
- [Architecture](../architecture.md)
- [Superseded RTL, including the FP4 product ROM](../../archive/superseded-rtl/README.md)
