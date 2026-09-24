# Project context

I use this repository for a Sky130-targeted FP4 E2M1 QK^T accelerator. The
active top computes dense FP32 scores with FP32 Q and K scales per 32 reduction
elements. It does
not include masking, softmax, or the multiplication by V. M1-M4 course work in
`archive/` remains a historical snapshot.

## Active implementation

The active `qkt_chiplet_top` accepts packed 64-bit input packets, holds two banks each for Q tiles, K tiles, exact accumulators, and FP32 scores,
and computes all scores of a 4x4 output tile from exact block-local
quarter-unit integer dot products. Parallel multiplier pairs apply the block
scales, and an FP32 adder combines the two default blocks. It emits two FP32
scores per 64-bit beat, with a zero-padded upper half on odd final beats. See
[stream protocol version 3](stream-protocol.md) for
packet order, status codes, and counters.
An optional `K_REUSE=1` build changes the packet order to version 4 and keeps
K in an RTL scratchpad for the whole command. Its physical storage choice is
still open.

The active module list is `rtl/filelist.f`, and `rtl/` holds only those
modules. The superseded PE, systolic array, tile controller, FP4 multiplier,
and buffers moved to
[`archive/superseded-rtl/`](../archive/superseded-rtl/README.md) as comparison
RTL; the active top does not instantiate them. P0.4 restored and corrected the
three-stage FP32 adder for cross-block reduction. The custom FP32 units round
finite normal results to nearest even but do not implement gradual underflow or
every IEEE exception and signed-zero rule.

## Verified active results

The 4x4 top passes T=1/4/7/8/16 at `D_HEAD=4/64` and T=64/128/512 at
`D_HEAD=64`, including edge tiles and repeated commands. The 512 run contains
16,384 output tiles and completes 262,144 scores in 1,049,665 simulated core
cycles with a continuously ready host. Full counters, host traffic, CPU timing,
and Sky130 synthesis scope are in [the reviewed result](results/packed-engine.md).
No routed active-top clock, power, or silicon latency is available yet.
The optional K-reuse build and 8x8/16x16 default builds also pass T=512.
Their cycle, traffic, and synthesis comparisons are in the
[design-space record](results/design-space.md).

## Archived course baseline

The M4 snapshot uses a one-shot FP32 product-buffering PE and a one-value-per-
beat controller. Its passing 4x4 numerical test used `D_HEAD=4` and recorded
498 cycles; the untouched M4 test printed `DONE=NO`. The later active pre-upgrade
integration test asserted completion for that one tile, but it did not prove
multi-tile behavior. The archived layout synthesized a flat 4x4 array wrapper,
not the integrated chiplet. It recorded 324,753 um² synthesis area, 28.1 mW
typical power, and a 15 ns target; nominal parasitic setup and hold slack were
negative. Those numbers cannot establish active-top timing closure.

The old 512 projection counted 262,144 output tiles; the correct count for 4x4
output tiles is 16,384. The 498-cycle observation also used `D_HEAD=4`, so it
cannot predict `D_HEAD=64` latency. I keep archival documents unchanged and
state corrections in active records.

## Remaining engineering work

The default host stream reloads K for each output tile. Physical K banking,
broader scale-arithmetic qualification, real activation error, and routed full-chip Sky130
timing and power remain open.
The [development plan](roadmap.md) gives the order and acceptance
evidence for those steps.

## Related

- [Architecture](architecture.md)
- [Stream protocol](stream-protocol.md)
- [Development plan](roadmap.md)
- [Documentation index](README.md)
