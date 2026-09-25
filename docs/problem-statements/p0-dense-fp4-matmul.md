# P0: dense FP4 matrix multiplication

This is the active problem statement. Read it to see what the current engine still
has to prove and in what order.

## The question

Build an accelerator for the dense `Q * K^T` matrix product with FP4 E2M1 inputs,
exact integer accumulation, and FP32 scores, that is accurate enough to be usable,
sustains a defensible fraction of its arithmetic peak, and has routed Sky130
timing and power for one named configuration.

## What is already done

The engine is functionally correct across a wide test surface: T=1/4/7/8/16 at
`D_HEAD=4` and `64`, T=64/128/512 at `D_HEAD=64`, partial edge tiles, malformed
packets, reset, repeated commands, backpressure, and AXI4-Lite handshake
ordering. Protocol version 4 and the 8x8 and 16x16 builds also pass. A closed-form
cycle model reproduces all 16 benchmarked configurations exactly; see
[architecture](../architecture.md).

## The remaining open problems

**Real-activation accuracy is still unknown.** P0.4 implements the selected
1x32 FP32 format and measures 14.23% relative Frobenius error on the pinned
Gaussian workload. P0.8 must test transformer activations with outliers before
that synthetic result can support a usability claim. See
[precision](../results/precision.md).

**K reuse saves traffic but no longer saves time.** Version 4 cuts host traffic
2.91x and input beats 51.8x under the block-scale contract, but is 2,032 cycles
slower because its complete cache fill is command startup. Version 3 occupies
the 64-bit streams for only 37.75% of its T=512 command, so bandwidth is not its
measured ceiling. The register scratchpad grows mapped cell area 4.18x at full
capacity. P0.5 therefore waits for P0.7 power evidence. See
[design space](../results/design-space.md).

**Nothing is routed.** Every area figure is Yosys mapping. There is no frequency,
latency in seconds, or energy for this top.

## Stages

| Stage | Work | Exit condition |
| --- | --- | --- |
| P0.1 | Repository and documentation hygiene | `make check-docs` passes with the extended checks; no reference to a path that does not exist outside `archive/` |
| P0.2 | **Complete:** sweep Bs 64/32/16/8/4/2 with FP32 and three E8M0 rules | [ADR 0003](../adr/0003-fp32-scales-with-32-element-blocks.md) selects 1x32 FP32 from softmax metrics |
| P0.3 | **Complete:** overlap load, compute, scale, and output | 99.945% measured 4x4 array activity before the block-scale interface; scaling binds at 8x8/16x16 |
| P0.4 | **Complete:** implement parameterized 1x32 FP32 scales | All T=512 RTL scores match the software path bit-exactly; 14.23% measured relative Frobenius error |
| P0.6 | **Complete:** decide output width from measurement | Keep 64 bits; two scaler lanes move 8x8 to CALC, four move 16x16 to OUTPUT |
| P0.7 | Route the complete top at the selected configuration | Routed timing and power exist, so a latency in seconds exists |
| P0.5 | Decide K reuse after P0.7 | Project avoided host-transfer energy against routed power and storage cost; implement SRAM only if it wins, otherwise close the experiment in an ADR |
| P0.8 | Measure error on real transformer activations | A pinned capture with its SHA-256 and a real-activation error, or a statement that no capture was obtained |

P0.2 comes before the RTL stages so the interface is not rebuilt twice. P0.3 is
format-independent, so it does not wait on P0.2.
P0.7 now precedes P0.5 because K reuse has no cycle benefit after overlap; routed
power is required before its traffic reduction can justify more storage.

## Note on stage ordering

[The roadmap](../roadmap.md) previously filed precision under later experiments
and expected the 64-bit output port to be the next bottleneck. Both are corrected
here: precision is first, and the stage that binds under overlap at 8x8 and 16x16
is the scale pipeline, not the output port. The derivation is in
[architecture](../architecture.md).

## Related

- [Problem statements](README.md)
- [Architecture](../architecture.md)
- [Development plan](../roadmap.md)
- [Precision result](../results/precision.md)
- [Design-space experiment](../results/design-space.md)
