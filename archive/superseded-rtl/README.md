# Superseded RTL

These nine modules built the pre-upgrade `Q * K^T` datapath. The active
`qkt_chiplet_top` does not instantiate any of them, and `rtl/filelist.f` does not
list them. I keep them here so the packed-stream engine can be compared against
the design it replaced, and so the M4 physical result stays traceable to source I
can still read.

Nothing here is on the active build path. New design work belongs in
[`rtl/`](../../rtl/README.md).

## What each file was

| File | Role in the superseded design |
| --- | --- |
| `pe.sv` | Output-stationary PE that buffered all `D_HEAD` FP4 products, then accumulated them serially through `fp32_add`. One-shot after reset: `prod_count` stayed at `D_HEAD`, so a second output tile could not be trusted. |
| `systolic_array.sv` | Parameterized `SIZE x SIZE` PE grid with input staggering. |
| `systolic_array_flat.sv` | Flat-port wrapper around `systolic_array` for the older Yosys frontend. This wrapper, not the integrated chiplet, was the target of the archived M4 OpenLane run. |
| `fp4_mul_lut.sv` | 256-entry ROM giving the FP32 product of every FP4 E2M1 pair. |
| `fp4_mul.sv` | Registered one-cycle wrapper around `fp4_mul_lut`. |
| `fp32_add.sv` | Three-stage custom FP32 adder used by the PE accumulator. |
| `tile_buffer.sv` | Q, K, and output tile storage. |
| `scale_sram.sv` | Q and K row-scale storage. |
| `tile_controller.sv` | Load, compute, dequantize, and stream FSM with tile traversal. |

## Why they were replaced

The active top accumulates signed FP4 half-unit products as exact integers in
quarter units and converts once per score, so it needs no FP4 product ROM and no
FP32 adder. It also reads and writes packed 64-bit beats rather than one value
per beat, and it traverses the full tile grid including partial edge tiles, which
the one-shot PE could not do.

`model/tests/test_reference.py` still parses `fp4_mul_lut.sv` from this
directory to check all 256 FP4 products against the Python model, so that file
is load-bearing for the test suite even though no RTL instantiates it.

## Related

- [Active RTL](../../rtl/README.md)
- [Project context](../../docs/project-context.md)
- [Archive index](../README.md)
