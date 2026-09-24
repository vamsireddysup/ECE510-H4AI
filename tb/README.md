# Testbenches

This directory holds the testbenches for the active engine. Read it to find out
what the one current test covers and where its output goes.

`integration/tb_qkt_chiplet.cpp` is the only testbench. It drives the complete
`qkt_chiplet_top` through its AXI4-Lite and AXI4-Stream ports and checks every
score against an exact integer-dot reference computed in the testbench.

There is no `unit/` directory yet. Per
[the layout rules](../docs/repository-layout.md), it will be created when the
first unit test exists, not before.

## What the integration test checks

Scores at `D_HEAD=4` and `64`, sequence lengths T=1/4/7/8/16 in the small suite
and T=64/128/512 in the large suite, including partial edge tiles at T=7. It also
checks per-packet `TLAST` position, output payload stability while `TREADY` is
low, zero padding on an odd final beat, accepted input and output beat counts,
completed tile counts, dot-product and scale cycle counts, the three error codes,
reset mid-command, repeated commands without reset, AXI4-Lite write-data-first
and same-cycle writes, byte strobes, and stable read data under backpressure.

The original M4 numerical pattern is one of the cases, so the historical 16/16
result stays covered. The small suite injects host stalls on both streams; the
large suite runs with a continuously ready host so its cycle counts are
comparable across configurations.

## Running it

From the repository root:

```bash
make test-integration              # small suite, D_HEAD=4 and 64
make test-integration-large        # T=64/128/512 at D_HEAD=64
make test-integration-reuse        # protocol version 2, K reuse
make test-integration-reuse-large  # version 2 at T=64/128/512
make test-array8                   # 8x8
make test-array16                  # 16x16
```

Generated binaries and logs go to `build/integration/`, one directory per
configuration. See [results and transcripts](../docs/results/README.md) for the
exact paths.

## Related

- [Verification records](../docs/results/latest-verification.md)
- [Stream protocol](../docs/stream-protocol.md)
- [Active RTL](../rtl/README.md)
- [Documentation index](../docs/README.md)
