# Professional repository reorganization plan

## Objective

I am converting this course-checkpoint repository into a maintainable hardware
project without losing my submission history. I want one active RTL tree, one
build interface, automated tests, clear specifications, and a clean split
between source files and generated output.

I will keep the behavior unchanged while I reorganize the files. I will start
larger arrays, new arithmetic, and protocol changes only after the new layout
reproduces my existing 4x4 result.

## Rules I will follow

1. Create a migration branch before moving files.
2. Preserve the current M1-M4 directories until the canonical baseline passes.
3. Copy first, verify, then archive with `git mv`; do not delete history during
   the migration.
4. Preserve the current untracked `project/m3/run_m3_when_ready.sh` until its
   purpose and desired destination are confirmed.
5. Do not mix behavior changes with path/build-system changes.
6. Never label projected 8x8 or 16x16 results as measured.
7. Do not commit generated Verilator, waveform, OpenLane, PDK, virtual
   environment, or tool-cache directories.

## Target layout

```text
.
├── README.md                     project overview and quick start
├── LICENSE                       explicit reuse terms
├── CONTRIBUTING.md               workflow, style, tests, commits
├── CHANGELOG.md                  user-visible engineering milestones
├── Makefile                      stable human/CI command interface
├── pyproject.toml                Python tools, model, and test dependencies
├── uv.lock                       pinned Python environment
├── .editorconfig                 basic editor consistency
├── .gitignore                    generated artifact policy
├── .github/
│   ├── workflows/ci.yml          lint, unit tests, integration smoke test
│   ├── ISSUE_TEMPLATE/
│   └── pull_request_template.md
├── rtl/
│   ├── core/                     PE, array, FP4/FP32 arithmetic
│   ├── memory/                   tile and scale storage
│   ├── control/                  tile controller and register block
│   ├── interfaces/               AXI4-Lite and AXI4-Stream logic
│   ├── top/                      integrated top and synthesis wrappers
│   └── filelist.f                single canonical compile order
├── tb/
│   ├── unit/                     arithmetic, PE, array, interface tests
│   ├── integration/              full-chip and multi-tile tests
│   ├── assertions/               protocol and internal invariants
│   └── data/                     small deterministic test vectors
├── model/
│   ├── qkt_model/                FP4 encode/decode and golden QK^T model
│   └── tests/                    randomized model tests
├── scripts/
│   ├── bootstrap.sh              validate/install project-local dependencies
│   ├── lint.sh                   RTL and repository checks
│   ├── test.sh                   regression entrypoint
│   ├── synth.sh                  synthesis entrypoint
│   └── report_results.py         normalize metrics into versioned summaries
├── config/
│   ├── verilator/                warning policy
│   ├── yosys/                    synthesis scripts
│   └── openlane/                 pinned flow configuration
├── constraints/                  clocks, IO delays, floorplan constraints
├── docs/
│   ├── architecture.md           blocks, dataflow, timing model
│   ├── specification.md          supported dimensions and numeric behavior
│   ├── register-map.md           AXI4-Lite contract
│   ├── stream-protocol.md        packet format and handshake contract
│   ├── verification-plan.md      coverage and test matrix
│   ├── results/                  reviewed compact benchmark/signoff summaries
│   ├── adr/                      architecture decision records
│   └── development/              project context and roadmap
├── archive/
│   ├── coursework/codefest/      weekly exercises, unchanged
│   ├── milestones/m1/            historical submissions, unchanged
│   ├── milestones/m2/
│   ├── milestones/m3/
│   ├── milestones/m4/
│   └── experiments/              upgrade_archive and superseded prototypes
└── build/                        ignored generated output
```

This layout uses plain industry conventions rather than tying the project to a
single framework. FuseSoC or Edalize can be added later if IP packaging and
multi-simulator support justify the extra layer.

## Stable developer interface

I use the root `Makefile` as the main command interface. The scripts behind it
can change, but I will keep these commands stable:

| Command | Contract |
| --- | --- |
| `make doctor` | Report tool versions and actionable missing dependencies |
| `make setup` | Create/update project-local dependencies without replacing working system tools |
| `make format` | Apply supported source formatting |
| `make lint` | Run Verilator lint, script checks, and documentation checks |
| `make test-unit` | Run fast arithmetic, PE, array, and interface tests |
| `make test-integration` | Run the 4x4 full-chip reference regression |
| `make test` | Run all required pre-commit regressions |
| `make test-multitile` | Run multi-tile correctness and backpressure tests |
| `make synth` | Run quick Yosys synthesis on the canonical target |
| `make pnr` | Run the pinned OpenLane flow explicitly, never as a normal CI step |
| `make clean` | Remove only the repository's `build/` directory |

No cleanup target may remove arbitrary paths, source files, archived evidence,
or external PDK/tool installations.

## Toolchain policy

### Existing local baseline

As inventoried on 2026-09-24:

- Verilator 5.041 development build
- Yosys 0.44
- Python 3.12.3
- uv 0.11.14
- Docker 29.8.1
- GTKWave installed but unavailable in the headless shell
- CMake, Ninja, and clang-format absent
- the installed `sby` command errors and must be diagnosed before formal work

### How I will keep runs reproducible

- Record working versions in `make doctor` output and CI logs.
- Pin Python dependencies in `pyproject.toml` and `uv.lock`.
- Pin GitHub Actions by major version initially and use dependency updates
  deliberately.
- Pin the OpenLane container by immutable digest after validating the baseline;
  do not use a floating `latest` tag for published results.
- Keep PDK data outside the repository and document the exact PDK revision.
- Prefer project-local tools or containers. Do not uninstall functional system
  packages unless a demonstrated incompatibility requires it.
- Add formal tools only when the first assertions exist; repair `sby` at that
  point rather than making it a blocker for structural migration.

## Migration phases

### Phase A: freeze and characterize the baseline

Status: in progress on `refactor/professional-layout`.

Work:

1. Create `refactor/professional-layout` from the current commit.
2. Preserve all current user changes and record their ownership.
3. Add a temporary baseline script that compiles `project/m4/src` in `build/`.
   Because the repository's parent path contains spaces and Verilator's GNU
   Make backend rejects such build paths, compilation uses a temporary
   space-free directory and copies logs and summaries into `build/`.
4. Strengthen the reference test so it separately reports:
   - 16/16 numerical outputs;
   - AXI-Lite read/write completion;
   - input and output stream handshake correctness;
   - `tile_count == 1`;
   - `cycle_count == 498` as an informational compatibility metric;
   - `done == 1` as a required protocol check.
5. Capture the expected current failure that numerical results pass while
   `done` is not observed. Do not silently redefine this as success.

I will move on when:

- The historical numeric result is reproducible from a clean build directory.
- Known status/protocol failures are visible and classified.
- Running the baseline leaves `git status` unchanged.

### Phase B: introduce the professional skeleton

Work:

1. Add root metadata, Makefile, Python project files, CI, docs, and empty
   canonical directories.
2. Copy the M4 RTL into the canonical hierarchy without editing module logic.
3. Copy or adapt the strongest M2/M4 testbenches into `tb/`.
4. Establish `rtl/filelist.f` as the only canonical source list.
5. Generate all output beneath `build/`.
6. Add license checks and file headers after a license is selected.

I will move on when:

- Canonical and M4 trees produce bit-for-bit-equivalent 4x4 outputs.
- Verilator lint has a reviewed warning baseline; suppressions are narrow and
  documented.
- `make doctor`, `make lint`, and `make test-integration` work from repository
  root.

### Phase C: build the verification foundation

Work:

1. Move the Python FP4 and QK^T reference logic into an importable model.
2. Use deterministic seeds and machine-readable result files.
3. Add unit tests for all 256 FP4 products, FP32 special cases in the supported
   numeric subset, PE reduction, stagger timing, buffers, and AXI registers.
4. Add integration tests for reset, stalls, output backpressure, malformed
   commands, repeat commands, and timeouts.
5. Add SystemVerilog assertions for stable-valid behavior, counter ranges,
   legal FSM transitions, and completion.
6. Add coverage goals to `docs/verification-plan.md`.

I will move on when:

- `make test` is deterministic and suitable for pull-request CI.
- Every known correctness limitation has a failing test, an issue, or an
  explicit unsupported-feature statement.

### Phase D: archive the coursework presentation

Work:

1. After canonical equivalence passes, move course artifacts with `git mv` into
   `archive/` so file history remains traceable.
2. Move compact final figures and validated results needed by the professional
   README into `docs/results/`.
3. Keep raw multi-gigabyte generated OpenLane runs outside Git. Publish them as
   release artifacts only when needed for reproducibility.
4. Rewrite the root README around the product, architecture, verified status,
   quick start, results, and roadmap—not course due dates.

I will move on when:

- A new contributor can identify the canonical RTL and run the smoke test
  without reading milestone documentation.
- Historical reports remain discoverable and unchanged under `archive/`.

### Phase E: establish synthesis and result provenance

Work:

1. Add quick Yosys synthesis for each supported parameter set.
2. Define two named synthesis targets:
   - `array`: compatibility with the historical M4 physical result;
   - `chiplet`: the complete integrated top, including control and interfaces.
3. Store configuration, commit hash, tool versions, parameters, clocks, and
   summarized metrics together for every published run.
4. Validate OpenLane with a pinned container and PDK revision.
5. Keep claims from different RTL revisions or target scopes out of the same
   comparison table.

I will move on when:

- A result summary can be traced to one commit, one source manifest, one
  parameter set, and one toolchain.

### Phase F: begin new architecture work

After Phases A-E, I will:

1. Write a failing two-tile test.
2. Add PE/array tile-restart semantics and fix controller traversal.
3. Resolve array-input ownership and remove dead single-read paths.
4. Specify and implement true 64-bit stream packing.
5. Add partial-tile masks and dimension validation.
6. Evaluate accumulator alternatives and pipeline changes.
7. Scale in measured steps: 4x4/D64, 8x8/D64, then 16x16/D64.

For each design experiment, I will use a short-lived branch and record why I
tried it, what alternatives I considered, what I measured, and what I decided.

## CI structure

I will keep pull-request CI fast and deterministic:

1. repository hygiene and documentation links;
2. Verilator lint;
3. Python model tests;
4. RTL unit tests in parallel;
5. 4x4 end-to-end integration test;
6. quick Yosys synthesis and area sanity threshold.

Nightly or manually dispatched workflows may run randomized tests, multiple
parameter configurations, formal checks, and larger synthesis. OpenLane PnR
should be manual or scheduled because of runtime, storage, and PDK licensing or
distribution constraints.

## Artifact and Git policy

Tracked:

- RTL, testbenches, scripts, specifications, constraints, manifests;
- small deterministic vectors;
- compact reviewed logs and CSV/JSON summaries;
- final plots and signoff summaries tied to a commit.

Ignored or externally archived:

- Verilator-generated C++ and object directories;
- VCD/FST waveforms except deliberately curated examples;
- full OpenLane run trees, GDS intermediates, ODB, SPEF, extraction logs;
- PDKs, Docker layers, virtual environments, caches;
- local editor and OS files.

## Proposed commit sequence

I will keep commits small enough to review and bisect:

1. `docs: define professional repository migration`
2. `build: add doctor and clean build-directory contract`
3. `test: capture M4 numerical baseline and done-status failure`
4. `chore: add canonical repository skeleton`
5. `rtl: import M4 sources without behavior changes`
6. `test: port unit and integration regressions`
7. `ci: run lint model tests and 4x4 regression`
8. `docs: publish architecture protocol and verification specifications`
9. `archive: move coursework snapshots after equivalence`
10. `synth: add traceable array and integrated targets`

## Definition of migration complete

The repository is ready for new designs when all of the following are true:

- one canonical RTL source tree exists;
- one root command runs lint and the verified baseline;
- builds produce no untracked files outside `build/`;
- CI enforces the baseline;
- the golden model and protocol are documented;
- historical coursework is archived but accessible;
- numeric pass and protocol/status pass are distinct checks;
- synthesis results state target scope and provenance;
- the first multi-tile bug is represented by a reproducible failing test.
