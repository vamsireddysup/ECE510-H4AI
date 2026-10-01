# Packed stream protocols

These are the 64-bit AXI4-Stream contracts for the dense FP4 E2M1 QK^T
engine. The default build uses version 5 (`K_REUSE=0`). An optional K
scratchpad build uses version 6 (`K_REUSE=1`). Selectable E4M3 builds use
version 7 or 8. Register `0x1C` reports the
compiled version. A command starts when software
writes bit 0 at `0x00`, after writing sequence length `T` at `0x08`.
`1 <= T <= T_MAX`; `T_MAX=512` is representable. `D_HEAD` and `TILE_SIZE`
are build parameters. The output is a dense `T x T` matrix of FP32 scores.

## Input packets

In versions 3 and 5, the host sends one scale packet, then tile packets in this
order:

1. `T * ceil(D_HEAD / SCALE_BLOCK_SIZE)` Q scales followed by the same number
   of K scales, each FP32. Scales are ordered by row, then by increasing
   reduction block within the row. A beat carries the earlier scale in bits
   31:0 and the next in bits 63:32. The packet has
   `T * ceil(D_HEAD / SCALE_BLOCK_SIZE)` beats.
2. For each Q tile row in increasing row order, one Q packet with
   `TILE_SIZE * D_HEAD` FP4 values in row-major order. A beat carries 16
   values; the earliest value is in bits 3:0.
3. For each K tile column in increasing row order, one K packet in the same
   format. The engine may accept the next K packet while computing the previous
   tile. After the last K packet for a Q tile, the next Q packet begins; input
   and output packets may be active concurrently.

Version 7 uses the same K-reload traversal as versions 3 and 5, but carries one
E4M3 scale byte per block. Eight scales occupy each beat, with the earliest in
bits 7:0. The scale packet contains
`ceil(2 * T * ceil(D_HEAD / SCALE_BLOCK_SIZE) / 8)` beats; unused bytes in its
last beat are zero. Version 8 combines this packed scale packet with the K-reuse
traversal below. Both versions assert `TLAST` on the packed packet's final beat.

In versions 4 and 6, the host sends all K tile packets immediately after scales, in
increasing K row order. It then sends one Q tile packet for each Q tile row.
After each Q packet, the engine emits every output tile for that Q row from
its K scratchpad and may accept the next Q packet concurrently. No K packet is
repeated. The Q/K tile format and output ordering are otherwise identical. The
scratchpad is currently an RTL register array with parallel row reads; a Sky130
SRAM macro is not substituted automatically.

Versions 1 and 2 used one FP32 scale per complete row. They are historical
contracts and are no longer emitted by the active RTL. Versions 3 and 4 use
32-element FP32 scale blocks with K reload and K reuse, respectively. Versions
5 and 6 keep those traversal orders and use 16-element FP32 scale blocks. The
default is version 5 with `SCALE_BLOCK_SIZE=16`; 1x32 remains a tested
compatibility parameter. A partial final block uses its own scale.
Versions 7 and 8 retain 16-element blocks and replace each FP32 block scale
with an E4M3 byte. `SCALE_FORMAT=1` selects them; the committed build default
remains FP32 while the format decision is integrated and physically measured.

A tile packet has `ceil(TILE_SIZE * D_HEAD / 16)` beats. Host data for rows
past `T-1` in an edge tile must be zero. Unused nibbles in the last beat must
be zero. The engine ignores those positions. Every packet must assert `TLAST`
exactly on its final beat. It uses the known packet length and `TLAST`
together; there is no `TKEEP`.

## Output packets

There is one output packet per Q/K tile pair, ordered by Q tile row then K
tile column. Only valid edge scores are emitted. Within a tile, scores are in
row-major order. Bits 31:0 contain the earlier score and bits 63:32 the next.
The upper half of an odd final beat is zero. `TLAST` marks the last beat of
each tile packet. `TVALID`, `TDATA`, and `TLAST` remain stable while `TREADY`
is low. The host may stall either stream indefinitely.

## Numeric meaning and status

Each FP4 code is E2M1 with magnitudes `0, 0.5, 1, 1.5, 2, 3, 4, 6` and a sign
bit. Both zero encodings decode to zero. A PE accumulates the integer product
of signed half-unit operands, so its register is exact in quarter units. At
`SCALE_BLOCK_SIZE=16`, 13 signed bits cover the worst-case sum within each
block. Each block dot converts once to FP32, then two pipelined multipliers
apply `S_Q[row][block]` and `S_K[row][block]`. A tree of three-stage FP32 adders
combines the four block scores at `D_HEAD=64`. The custom FP32 units round finite
normal results to nearest even. They do not implement gradual underflow or every
IEEE exception and signed-zero rule.

`STATUS` at `0x04` has `DONE` at bit 0 and an error code in bits 7:4. Error
codes are `1` for invalid `T`, `2` for early `TLAST`, and `3` for a missing
`TLAST` on the expected final beat. `DONE` also asserts on an error. A new
`START` clears status and profiling counters. Reset aborts the current command.
If a sender stops before a packet is complete, the engine waits for input;
there is no transport timeout.

AXI4-Lite write address and data channels may arrive in either order or in
the same cycle. Byte strobes apply to `MATRIX_SIZE` and the reserved scale
register. A read response holds its data and valid flag until accepted.

| Address | Read value |
| --- | --- |
| `0x0C` | Completed output tiles |
| `0x10` | Core cycles from START through completion |
| `0x14` | Cycles between the two most recent tile completions; for the first tile, cycles since command start |
| `0x1C` | Compiled protocol version: `3`/`4` for FP32 Bs=32, `5`/`6` for FP32 Bs=16, or `7`/`8` for packed E4M3; even versions enable K reuse |
| `0x20` | Accepted input beats |
| `0x24` | Accepted output beats |
| `0x28` | Cycles ready for input while input valid is low |
| `0x2C` | Cycles with output valid while output ready is low |
| `0x30` | Cycles with the dot-product sequencer active; exactly completed tiles times `D_HEAD` at command completion |
| `0x34` | Cycles with the score-scaling sequencer active |

Counters wrap at 32 bits. The command cycle count excludes idle and finished
states. Packet padding is counted in transferred bytes, not useful bytes.
Load, compute, scale, and output now overlap. Registers `0x30` and `0x34` may
both increment in the same clock, so phase counters are occupancy measurements
and their sum may exceed `cycle_count`. Likewise, `tile_cycles` is an elapsed
inter-completion span that can contain work on neighbouring tiles; it is not an
isolated per-tile cost. The exact compute invariant remains
`compute_cycles = tile_count * D_HEAD` when `DONE` asserts successfully, and the
integration test checks it on every command.

## Related

- [Protocol version history](protocol-history.md)
- [Architecture](architecture.md)
- [Project context](project-status.md)
- [Verification plan](verification-plan.md)
- [Documentation index](README.md)
