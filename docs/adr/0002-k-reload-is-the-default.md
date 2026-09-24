# 0002: ship K reload as the default, not K reuse

Accepted, September 2026. Revisit at stage P0.5 of
[P0](../problem-statements/p0-dense-fp4-matmul.md).

## Decision

Build protocol version 1, which reloads a K tile for every output tile, as the
default. Keep protocol version 2, which loads K once per command into an on-chip
scratchpad, behind `K_REUSE=1` as an experiment.

## The tradeoff, measured

At T=512 and `D_HEAD=64` with a 4x4 tile:

| | Version 1 | Version 2 |
| --- | ---: | ---: |
| Core cycles | 1,821,184 | 1,561,088 |
| Input beats | 264,704 | 4,608 |
| Host bytes | 3,166,208 | 1,085,440 |
| Array active | 57.58% | 67.17% |
| Mapped cell area at `T_MAX=512` | 1,596,280 um² | 6,672,971 um² |

Version 2 is better on every runtime measure: 14.3% fewer cycles, 57.4x fewer
input beats, 2.9x less host traffic. It costs 4.18x the mapped standard-cell area
at full capacity.

## Why version 1 wins for now

The version 2 scratchpad is an RTL register array with parallel row reads, not a
memory macro. At T=512 it holds 16 KiB of FP4 codes, and synthesizing that as flip
flops is what produces the 4.18x. The area figure is therefore a property of the
implementation, not of the idea.

## Alternatives considered

**Map the scratchpad to Sky130 SRAM macros.** The locally installed PDK has a
2 KiB 32x512 1RW1R block with a 683.1 by 416.54 um footprint; eight of them give
16 KiB in 2,276,308 um² before routing, peripherals, and bank spacing. A 1 KiB
32x256 macro is 479.78 by 397.5 um, and sixteen would occupy 3,051,401 um². Both
are smaller than 6,672,971 um², but the macro read is clocked and needs address
scheduling that the current combinational array does not have. This is P0.5.

**Cap `T_MAX` so the register array stays small.** Works, and hides the problem
rather than solving it. The area comparison at `T_MAX=16` shows only 37.0%
overhead, which is why the full-capacity number matters.

## Consequences

The default design transfers 2,080,768 more bytes at T=512 than it needs to. That
is accepted until P0.5 decides the storage. Both variants stay verified, and both
lint, so neither path rots.

None of these areas include clock tree, routing, timing, or power. See
[the design-space record](../results/design-space.md) for the measurement
conditions.

## Related

- [Decision records](README.md)
- [Design-space experiment](../results/design-space.md)
- [Architecture](../architecture.md)
