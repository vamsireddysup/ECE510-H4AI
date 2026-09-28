# P1: dynamic precision and sparsity

This is the next research problem. It begins after P0 is physically closed so
energy per format can be measured against a valid routed baseline.

## The question

> How can an AI accelerator dynamically select FP4, INT4, or FP8 precision and
> exploit sparsity according to layer and workload characteristics to minimize
> memory traffic and energy while maintaining accuracy?

The work couples the software and hardware decisions: the model measures accuracy
and sparsity on the same pinned workloads, while the RTL measures format-specific
storage, arithmetic, routing, and energy costs. A selection policy is useful only
when both sides are measured.

## Accumulator width at `D_HEAD=64`

**FP4 E2M1** decodes to signed half units with magnitudes 0, 1, 2, 3, 4, 6, 8,
and 12. The maximum product is `12 * 12 = 144` in quarter units. Over 64 terms,
`144 * 64 = 9216`, so `ceil(log2(9217)) = 14` magnitude bits plus sign: **15
bits**.

**Signed INT4** ranges from -8 to 7. The maximum product is 64. Over 64 terms,
`64 * 64 = 4096`, so `ceil(log2(4097)) = 13` magnitude bits plus sign: **14
bits**. It fits within the current FP4 accumulator width.

**FP8 E4M3** has smallest subnormal `2^-9` and largest normal 448. Expressed in
units of `2^-9`, the maximum is `448 * 512 = 229,376`, which needs 18 bits. The
maximum product is `52,613,349,376`, or 36 bits. Summing 64 terms reaches about
`3.367e12`, requiring 42 magnitude bits plus sign: **43 bits**.

Exact support for all three formats therefore widens each accumulator from 15 to
43 bits, or 2.87x. A 4x4 tile adds `(43 - 15) * 16 = 448` state bits plus wider
adders. FP8 decode also needs an 18-bit shift range; decoding during load trades
`O(B^2*D)` repeated decode work for wider tile storage.

## Multiplier options

The M0 through M4 study holds the FP4 format and workload fixed. Every option must
match the Python model bit-for-bit and be synthesized separately so area, timing,
and energy differences remain attributable.

| Option | Design | Measurement role |
| --- | --- | --- |
| M0 | Decode to signed half units, multiply, and accumulate exactly | Current reference |
| M1 | Select `{1,3}` significands and shift by the summed exponent | Exact E2M1-specific logic without a general multiplier |
| M2 | Use the verified 256-entry FP4 product ROM in [`archive/superseded-rtl/fp4_mul_lut.sv`](../../archive/superseded-rtl/fp4_mul_lut.sv) | Table-based comparison point |
| M3 | Use one integer multiplier sized for the widest enabled format, with FP4 and INT4 in its low bits | Simple multi-format baseline |
| M4 | Pack several narrow products into one wide multiplication structure | Area and utilization experiment |

For M1, nonzero E2M1 magnitudes are `{1,2,4,8}` and `{3,6,12}`, or `{1,3} *
2^e`. Their product is `(m1*m2) << (e1+e2)`, with `m1*m2` in `{1,3,9}` and a
shift from 0 through 6. The maximum remains `9 << 4 = 144`.

## Sparsity analysis

FP4 quantization creates zero codes when a value falls below half a scale unit,
and E2M1 has two zero encodings. The model must measure zero-code frequency and
accuracy together for every format and block size.

The current datapath has one shared reduction index driving all
`TILE_SIZE*TILE_SIZE` accumulators. It can skip a cycle only when a complete Q or
K reduction column is zero. Per-element skipping requires independent PE operand
queues or equivalent scheduling state. Structured N:M sparsity along the
reduction axis works with a shared index, but it changes both the quantizer and
the stream representation.

The first sparsity result is therefore a measurement: zero-code fraction,
all-zero-column fraction, softmax quality, and transferred bytes by layer and
format. RTL is justified only when those measurements predict a net traffic or
energy reduction after metadata and control costs.

## Score conversion prerequisite

Before a 43-bit FP8 accumulator is enabled, replace `score_scaler`'s current
`quarter_to_fp32` conversion. Its expression
`23'(magnitude) << (23-leading)` is valid for today's `ACC_W=13/14`, but a
43-bit accumulator can have `leading` up to 42. The cast would discard high bits,
and `23-leading` would become a negative shift count interpreted as a large
unsigned shift. P1 needs width-independent normalization with explicit round,
guard, and sticky handling.

## Stages

| Stage | Work |
| --- | --- |
| P1.1 | Add INT4 and FP8 E4M3 to the model and measure accuracy on the pinned P0 inputs |
| P1.2 | Implement and synthesize multiplier options M0 through M4 at fixed FP4 precision |
| P1.3 | Make the accumulator and score conversion width-safe through 43 bits |
| P1.4 | Measure format-dependent sparsity and the useful structured skip opportunities |
| P1.5 | Define a per-layer or per-tile format and sparsity selection policy |
| P1.6 | Measure the complete policy's accuracy, traffic, routed area, timing, and energy Pareto front |

P1 does not start until P0.7 provides a routed, hold-clean result with qualified
power. Without that baseline, the primary objective, energy by format, cannot be
measured.

## Related

- [Problem statements](README.md)
- [P0](p0-dense-fp4-matmul.md)
- [Architecture](../architecture.md)
- [Superseded RTL, including the FP4 product ROM](../../archive/superseded-rtl/README.md)
