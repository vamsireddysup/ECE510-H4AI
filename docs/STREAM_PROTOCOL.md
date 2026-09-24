# Packed stream protocols

These are the 64-bit AXI4-Stream contracts for the dense FP4 E2M1 QK^T
engine. The default build uses version 1 (`K_REUSE=0`). An optional K
scratchpad build uses version 2 (`K_REUSE=1`). Register `0x1C` reports the
compiled version. A command starts when software
writes bit 0 at `0x00`, after writing sequence length `T` at `0x08`.
`1 <= T <= T_MAX`; `T_MAX=512` is representable. `D_HEAD` and `TILE_SIZE`
are build parameters. The output is a dense `T x T` matrix of FP32 scores.

## Input packets

In version 1, the host sends one scale packet, then tile packets in this order:

1. `T` Q row scales followed by `T` K row scales, each FP32. A beat carries
   the earlier scale in bits 31:0 and the next in bits 63:32. This packet has
   `T` beats.
2. For each Q tile row in increasing row order, one Q packet with
   `TILE_SIZE * D_HEAD` FP4 values in row-major order. A beat carries 16
   values; the earliest value is in bits 3:0.
3. For each K tile column in increasing row order, one K packet in the same
   format. The engine emits the corresponding output tile before accepting
   the next K packet. After the last K packet for a Q tile, the next Q packet
   begins.

In version 2, the host sends all K tile packets immediately after scales, in
increasing K row order. It then sends one Q tile packet for each Q tile row.
After each Q packet, the engine emits every output tile for that Q row from
its K scratchpad. No K packet is repeated. The Q/K tile format and output
ordering are otherwise identical. The scratchpad is currently an RTL register
array with parallel row reads; a Sky130 SRAM macro is not substituted automatically.

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
`D_HEAD=64`, 15 signed bits cover the worst-case sum. The dot converts once to
FP32, then the two pipelined multipliers apply `S_Q[row]` and `S_K[row]`.
The FP32 multiplier is the existing RTL implementation; it does not implement
all IEEE rounding and subnormal behavior. Supported scale and error ranges
need further characterization.

`STATUS` at `0x04` has `DONE` at bit 0 and an error code in bits 7:4. Error
codes are `1` for invalid `T`, `2` for early `TLAST`, and `3` for a missing
`TLAST` on the expected final beat. `DONE` also asserts on an error. A new
`START` clears status and profiling counters. Reset aborts the current command.
If a sender stops before a packet is complete, the engine waits for input;
there is no transport timeout.

| Address | Read value |
| --- | --- |
| `0x0C` | Completed output tiles |
| `0x10` | Core cycles from START through completion |
| `0x14` | Cycles for the last tile, including its stream stalls |
| `0x1C` | Compiled protocol version, `1` or `2` |
| `0x20` | Accepted input beats |
| `0x24` | Accepted output beats |
| `0x28` | Cycles ready for input while input valid is low |
| `0x2C` | Cycles with output valid while output ready is low |
| `0x30` | Dot-product compute cycles |
| `0x34` | Scale-pipeline cycles |

Counters wrap at 32 bits. The command cycle count excludes idle and finished
states. Packet padding is counted in transferred bytes, not useful bytes.
