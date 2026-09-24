# RTL

This is the active RTL for my accelerator. I copied the first version from the
verified M4 source without changing the logic.

## Layout

- `core/`: FP4 and FP32 arithmetic, PE, and systolic array
- `memory/`: Q, K, scale, and output storage
- `control/`: tile loading, compute, dequantization, and output sequencing
- `interfaces/`: host-side control and streaming interfaces
- `top/`: integration and synthesis wrappers
- `filelist.f`: compile order for the integrated design

I keep the old milestone RTL under `project/` as a record. New design changes
belong here and must include matching tests.
