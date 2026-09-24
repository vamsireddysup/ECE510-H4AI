# 0002: ship K reload as the default, not K reuse

Accepted, September 2026. Revisit at stage P0.5 of
[P0](../problem-statements/p0-dense-fp4-matmul.md).

## Decision

Keep K reload as the default. It was protocol version 1 under row scaling and is
version 3 under the active block-scale contract. Keep command-level K reuse
(formerly version 2, now version 4) behind `K_REUSE=1` as an experiment.

## The tradeoff, measured

At T=512 and `D_HEAD=64` with a 4x4 tile:

| | Version 1 | Version 2 |
| --- | ---: | ---: |
| Core cycles | 1,821,184 | 1,561,088 |
| Input beats | 264,704 | 4,608 |
| Host bytes | 3,166,208 | 1,085,440 |
| Array active | 57.58% | 67.17% |
| Mapped cell area at `T_MAX=512` | 1,596,280 um² | 6,672,971 um² |

These runtime figures describe the serial scheduler at the decision revision.
P0.3 later changed both cycle counts: version 1 now takes 1,049,150 cycles and
version 2 takes 1,051,182. Version 2 remains 57.4x lower in input beats and 2.9x
lower in host traffic, but its up-front cache fill is 2,032 cycles slower once
version 1 K loads are hidden behind compute. The 4.18x mapped-area comparison is
also pre-P0.3; current RTL has not been remapped.

P0.4 adds the same block-scale traffic to both paths. At revision `1311eb0`,
version 3 takes 1,049,665 cycles and 265,216 input beats; version 4 takes
1,051,697 cycles and 5,120 input beats. The storage decision is unchanged.

## Why K reload wins for now

The K-reuse scratchpad is an RTL register array with parallel row reads, not a
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
