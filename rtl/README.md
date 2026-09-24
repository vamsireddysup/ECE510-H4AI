# Active RTL

`qkt_chiplet_top.sv` is the active QK^T accelerator. It accepts packed FP4
E2M1 Q/K tiles and FP32 row scales, computes exact integer dot products in
quarter units, applies two pipelined FP32 scale multipliers, and emits packed
FP32 scores. See the [version 1 stream contract](../docs/STREAM_PROTOCOL.md).

`rtl/filelist.f` lists the active top and its two dependencies. The older
`systolic_array`, `pe`, `tile_controller`, and tile/scale buffer modules remain
under `rtl/` as comparison references but are not instantiated by the current
top. The historical M1-M4 submissions remain untouched in `archive/`.

The active top is parameterized by `TILE_SIZE`, `D_HEAD`, and `T_MAX`.
`T_MAX=512` is accepted without truncating the software-written dimension.
The currently verified integrated configuration is `TILE_SIZE=4`, including
`D_HEAD=4` and `64`. See [latest verification](../docs/results/latest-verification.md)
for tested sequence lengths and measurement scope.
