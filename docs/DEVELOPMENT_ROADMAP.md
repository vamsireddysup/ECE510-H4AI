# Development roadmap

I want the next version to be a maintainable accelerator project, not another
milestone copy. I will fix the known control and reuse problems before scaling
the array, and I will verify each stage before moving to the next one.

## Phase 0: preserve and baseline

- Keep M1-M4 unchanged as submission history.
- Record the current 4x4 build and numerical result.
- Add a top-level developer command that builds outside source directories.
- Make regressions fail on protocol/status errors, not only wrong numbers.

I will move on when one command runs lint and the 4x4 end-to-end test, and fails
when `DONE`, counters, handshakes, or numerical outputs are wrong.

## Phase 1: canonicalize the project

I will create this active layout and start it from `project/m4/src`:

```text
rtl/            canonical synthesizable RTL
tb/             unit and integration testbenches
model/          FP4/microscaling golden reference
scripts/        reproducible lint, simulation, and synthesis entrypoints
constraints/    clock and physical-design constraints
docs/           architecture, protocol, decisions, and results
build/          generated and ignored
```

I will not delete milestone copies during this work. I will add CI for lint and
fast tests, and replace repeated source lists with one manifest.

I will move on when the active sources reproduce the 4x4 result and the test
leaves Git clean.

## Phase 2: make tiling correct

- Add explicit `tile_start`/`clear_accumulator` semantics to the array and PE.
- Reset product count, accumulator state, result valid, and all tile-local state
  without resetting the entire chip.
- Remove the second/legacy owner of array input signals.
- Define Q reuse and K reload behavior for every `(tile_row, tile_col)` pair.
- Use ceiling division and valid masks for sequence lengths that are not a
  multiple of `TILE_SIZE`.
- Define whether multiple commands may run without global reset, then test it.

Required tests: two K tiles, two Q tiles, 2x2 tile grid, partial final tile,
back-to-back commands, input stalls, and output backpressure.

I will move on when randomized multi-tile outputs match the software model.

## Phase 3: define and fix the host protocol

I will write a versioned register map and stream packet format before changing
the interface RTL. I will then implement the documented packing or clearly keep
a simpler format. My preferred packed format is:

- two FP32 scale values per 64-bit input beat;
- sixteen FP4 values per 64-bit input beat;
- two FP32 scores per 64-bit output beat;
- explicit packet/type framing and precise `TLAST` rules;
- stable `TVALID` and payload while `TREADY` is low;
- sticky done/error status with software-visible clearing behavior.

I will move on when protocol assertions and randomized stall tests pass.

## Phase 4: improve arithmetic architecture

I will first choose an accuracy target: exact accumulation for FP4 products,
bounded error against FP32, or fuller IEEE behavior. Then I will compare:

1. Keep FP32 accumulation and pipeline/retime the feedback path.
2. Accumulate exactly in a fixed-point or Kulisch-style accumulator and convert
   once at the output.
3. Use a shared reduction structure if area is more important than throughput.

The current PE stores every product and serially adds it. A larger array should
avoid `SIZE^2 * D_HEAD` FP32 product storage unless measurements justify it.

I will move on when the chosen arithmetic passes edge cases and randomized
tests, with latency, initiation interval, area, and error recorded.

## Phase 5: scale by evidence

I will test configurations in this order:

1. 4x4 array, `D_HEAD=4` (compatibility baseline)
2. 4x4 array, `D_HEAD=64` (real reduction depth)
3. 8x8 array, `D_HEAD=64`
4. 16x16 array, `D_HEAD=64`
5. tiled sequence tests up to the chosen `T_MAX` (historically 512)

At every step record simulation cycles, effective utilization, compile time,
cell area, worst slack, and power. Stop scaling when memory ports, routing,
compile resources, or timing become the dominant constraint and address that
constraint explicitly.

I will call 16x16 results measured only after an actual run. Every physical
design result will state which modules were included.

## Phase 6: full-chip physical design

- Synthesize the integrated top, not only `systolic_array_flat`.
- Infer or instantiate practical memories instead of flip-flop-expanded arrays.
- Pipeline the FP32/fixed-point critical path based on STA evidence.
- Address reset fanout through reset architecture and physical synthesis, not an
  RTL buffer tree tied to one standard-cell library unless required.
- Add floorplan and clock constraints suited to the integrated design.
- Archive compact signoff summaries; keep full run products outside Git.

I will finish this stage when DRC, LVS, timing, and power results use the same
integrated RTL revision and configuration as functional verification.

## First implementation slice

I will first create the active source tree and regression without changing
behavior. My first functional change will start with a failing two-tile test,
then add PE tile restart. That gives me a clean baseline for later experiments.
