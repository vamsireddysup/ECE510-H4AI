# 0005: close register-based K reuse

Accepted, September 2026. Supersedes
[ADR 0002](0002-k-reload-is-the-default.md).

## Decision

Keep K reload as the supported default and close the current register-based
command-level K-reuse experiment. Do not implement the proposed SRAM version in
P0 without new power evidence. Retain protocol version 4 and its tests as
reproducible experimental evidence.

Reopen K reuse if a routed SRAM implementation has valid dynamic and leakage
power, a measured host link exceeds the break-even energy below, or a future
workload saturates the input stream and gives reuse a latency benefit.

## Evidence

At T=512, version 4 saves 2,080,768 host bytes but takes 2,032 more cycles than
version 3. Version 3 accepts 396,288 stream beats in 1,049,665 cycles, so the
64-bit stream is occupied for only 37.75% of the command. K reuse has no
measured bandwidth or latency case after phase overlap.

Horowitz reports a rough 45 nm DRAM cost of 1.3 to 2.6 nJ per 64-bit access in
Figure 1.1.9 of [Computing's Energy Problem](https://doi.org/10.1109/ISSCC.2014.6757323).
Applying that external, technology-mismatched range gives a **projected** host
energy saving of 0.338 to 0.676 mJ per T=512 command. It is a sensitivity range,
not a measurement of this accelerator's host link.

The 225 ns route projects a 236.17 ms command. The avoided transfer energy
therefore supports at most 1.432 to 2.863 mW of incremental on-chip power. The
routed T_MAX=16 top has 864,944 um2 of standard cells and reports 0.495 mW
slow-corner leakage. Scaling that leakage density by the historical
T_MAX=512 register implementation's 5,076,691 um2 area increment projects
**2.905 mW** incremental leakage, or **0.686 mJ** per command. Leakage alone is
slightly above even the high DRAM saving before any dynamic storage or mux
energy is added.

This comparison crosses revisions, capacities, and process nodes. It is a
projection, and the route's dynamic power is invalid. It is sufficient to
reject the existing register implementation because its full-capacity area
increment is also larger than the complete 4.84 mm2 routed die.

## Alternatives considered

**Implement eight 2 KiB SRAM macros now.** Their estimated 2,276,308 um2
footprint is 34.1% of the register array's mapped area. That estimate excludes
bank routing, peripherals, clocked-read scheduling, and power. Building it now
would replace a measured losing implementation with an unmeasured one.

**Keep register reuse active until dynamic power works.** The implementation has
no latency benefit, exceeds the current die at full capacity, and fails the
conservative leakage projection. More work on it does not improve the decision.

**Remove protocol version 4 immediately.** Keeping the verified experiment
makes the traffic result reproducible and provides a comparison point if SRAM
or host-link evidence later reopens the question.

## Consequences

P0.5 completes without a new SRAM controller. Version 3 remains the active
contract. Physical work returns to hold, slew, fanout, and trustworthy dynamic
power on the smaller default top before routing larger arrays.

The decision does not claim that K reuse is universally inefficient. It closes
the parallel-read register implementation under the measured P0 workload and
states the evidence needed to reconsider it.

## Related

- [Decision records](README.md)
- [Physical-design result](../results/physical-design.md)
- [Design-space experiment](../results/design-space.md)
- [Development plan](../roadmap.md)
