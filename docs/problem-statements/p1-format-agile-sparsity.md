# P1: format-agile precision and sparsity

This is the next problem statement. It starts no earlier than P0.4, because
measuring the cost of changing format needs a settled baseline format and a
settled accumulator. Read it to see the thesis and how it will be tested.

## The question

> How can an AI accelerator dynamically select FP4/INT4/FP8 precision and exploit
> sparsity according to layer/workload characteristics to minimize memory traffic
> and energy while maintaining accuracy?

## What prior work already answers

The accumulator architecture itself is occupied. The
[hybrid precision-scalable reduction tree](https://arxiv.org/abs/2511.06313)
combines exact integer reduction inside an MX block with floating-point partial
alignment between blocks. It evaluates MXINT8, MXFP8, MXFP6, and MXFP4 on an
8x8 SNAX accelerator and reports 4,065 GOPS/W for MXFP4 in 22 nm. Its companion
[precision-scalable MX accelerator](https://arxiv.org/abs/2505.22404) supports
all six OCP MX data types with hierarchical two-bit multipliers in an 8x8 array.
The authors publish SystemVerilog for both long-integer and hybrid accumulation
in the
[Precision-Scalable_MX repository](https://github.com/KULeuven-MICAS/Precision-Scalable_MX).
The review used repository revision
`bddb9f93c5cb20c61f2393715eb2928a50a4984f`, including the standalone MAC
variants and the 8x8 SNAX `Block_PE` integration.

Those designs occupy the broad accumulation direction P0 reached independently,
but the circuits are not identical. Their hybrid MAC aligns a fixed-width
product sum against a stored floating-point partial result on every accumulation
step and deliberately studies reduced mantissa width. P0 instead completes an
exact integer sum over each 16-value block, converts and scales each completed
block once, then reduces block results in FP32. P1 will not claim hybrid
integer/floating reduction, format-scalable arithmetic, or the
integer-versus-floating-point accumulation comparison as new. Its measurements
must still distinguish P0's block boundary and accuracy behavior from the
published datapath.

## The open question

The cited work evaluates general GEMM for training and continual-learning
workloads. It does not evaluate attention probability quality, and it does not
map precision choices onto independently scheduled attention tiles. P0 already
measures mean softmax KL divergence, total variation, top-1 agreement, and top-5
overlap on pinned Q/K activations. Its small replicated engines also provide a
place to select precision per output tile without widening one global array.

The testable P1 claim is therefore: **attention-aware format selection across
replicated tiles can reduce scale and operand traffic while meeting a softmax
quality target, and its routing, scheduling, and metadata costs are measurable.**
Exact per-block integer accumulation and cross-block FP32 reduction are the
baseline used to test that claim.

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
`(43 - 15) * 16 = 448` flip-flops plus wider adders. That is the local storage
cost to measure; it is not evidence of a new accumulation method.

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
| M3 | One integer multiplier sized for the widest supported format, FP4 and INT4 using the low bits | A simple baseline |
| M4 | Sub-word-parallel packing of several narrow multiplies into one wide unit | Comparison with the published hierarchical approach |

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
| P1.3 | Map published format-agile arithmetic onto a replicated attention tile |
| P1.4 | The sparsity measurement |
| P1.5 | A per-tile selection policy and its descriptor or register interface |
| P1.6 | The comparison matrix and its Pareto front |

P1.5 comes last because a policy that selects between formats is meaningless until
each format has a measured cost.

Before P1.3 widens the accumulator, replace `score_scaler`'s current
`quarter_to_fp32` conversion. Its expression
`23'(magnitude) << (23-leading)` is valid for today's `ACC_W=14/15`, but a
43-bit FP8 accumulator can have `leading` up to 42. The 23-bit cast would
discard high magnitude bits, and `23-leading` would become a negative shift
count that SystemVerilog interprets as a large unsigned shift, producing a zero
mantissa. P1.3 needs a width-independent leading-bit normalization with explicit
round, guard, and sticky handling before any 43-bit configuration is enabled.

## Research boundary

P1 begins with reproduction, not RTL invention: compare the published long
integer and hybrid implementations with P0's per-block path under the same
formats. The contribution must come from attention-specific quality and
per-tile scheduling evidence. A format unit alone, even if smaller, does not
answer the revised question.

## Related

- [Problem statements](README.md)
- [P0](p0-dense-fp4-matmul.md)
- [Architecture](../architecture.md)
- [Superseded RTL, including the FP4 product ROM](../../archive/superseded-rtl/README.md)
