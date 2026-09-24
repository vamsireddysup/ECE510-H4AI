# Active RTL

[`top/qkt_chiplet_top.sv`](top/qkt_chiplet_top.sv) is the active QK^T accelerator. It accepts packed FP4
E2M1 Q/K tiles and FP32 reduction-block scales, computes exact integer dot
products in quarter units, applies parallel pairs of pipelined FP32 scale
multipliers, combines the blocks, and emits packed FP32 scores. See the
[version 3 stream contract](../docs/stream-protocol.md).

[`core/score_scaler.sv`](core/score_scaler.sv) owns the conversion from exact
quarter-unit accumulators through both block-scale multipliers. The top has one
scaler lane per block per `SCORE_LANES`; `score_reducer.sv` combines each
score's blocks through `fp32_add.sv`.

`K_REUSE=1` selects protocol version 4 and a command-level RTL K scratchpad.
`TILE_SIZE=8` and `16` also pass simulation; none of these variants has routed
Sky130 timing or power evidence. The [design-space record](../docs/results/design-space.md)
compares them.

`rtl/filelist.f` lists the active top and its five dependencies, and `rtl/`
contains nothing else that is synthesizable. The superseded `systolic_array`,
`pe`, `tile_controller`, FP4 multiplier, FP32 adder, and tile/scale buffer
modules moved to [`archive/superseded-rtl/`](../archive/superseded-rtl/README.md);
they are kept for comparison and are not on any build path. The historical M1-M4
submissions remain untouched in `archive/`.

The active top is parameterized by `TILE_SIZE`, `D_HEAD`, `T_MAX`,
`SCALE_BLOCK_SIZE`, and `SCORE_LANES`.
`T_MAX=512` is accepted without truncating the software-written dimension.
The verified integrated configurations include `TILE_SIZE=4` at `D_HEAD=4/64`
and `TILE_SIZE=8/16` at `D_HEAD=64`. See
[latest verification](../docs/results/latest-verification.md) for tested
sequence lengths and measurement scope.

## Related

- [Architecture](../docs/architecture.md)
- [Stream protocol](../docs/stream-protocol.md)
- [Superseded RTL](../archive/superseded-rtl/README.md)
- [Documentation index](../docs/README.md)
