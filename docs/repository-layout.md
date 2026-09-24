# Repository layout and conventions

This describes the layout that exists and the rules I hold it to. Read it before
adding a directory, renaming a document, or deciding where a new file belongs.
For the migration that produced this layout, see [`CHANGELOG.md`](../CHANGELOG.md).

## Layout

```text
.
├── README.md              entry point: what this is, verified status, how to run
├── CODEX.md               agent rules, permissions, conventions
├── CONTRIBUTING.md        human workflow
├── CHANGELOG.md           engineering history
├── LICENSE                Apache-2.0
├── NOTICE                 attribution required by Apache-2.0
├── Makefile               the stable command surface
├── pyproject.toml         Python model and test dependencies
├── uv.lock                pinned Python environment
├── .github/workflows/     CI
├── rtl/                   active synthesizable RTL only
├── tb/                    testbenches
├── model/                 Python reference model and its tests
├── scripts/               reproducible entry points behind the Makefile
├── config/                synthesis and physical-design configuration
├── docs/                  architecture, interface, plans, and reviewed results
└── archive/               coursework snapshots, superseded RTL, old experiments
```

## Rules

**`rtl/` holds only active source.** Every synthesizable file under `rtl/` is
listed in [`rtl/filelist.f`](../rtl/filelist.f) or is a documented synthesis
wrapper. Anything the active top no longer instantiates moves to
[`archive/superseded-rtl/`](../archive/superseded-rtl/README.md). This keeps lint
scope and mapped-area attribution unambiguous.

**A directory is created when its first real file exists.** Not in advance. The
retired reorganization plan listed about fifteen directories and files that were
never created, which made it unreadable as a description of anything.

**One fact has one home.** A document that needs a fact owned elsewhere links to
it. The AXI register map lives only in
[`stream-protocol.md`](stream-protocol.md), because two copies of a register map
diverge.

**Generated output goes under `build/`,** which is ignored. Reviewed summaries go
in [`docs/results/`](results/README.md). Large release outputs go in GitHub
release assets, not Git history.

## Naming

Root-level conventional files keep their uppercase names: `README.md`,
`CODEX.md`, `CONTRIBUTING.md`, `CHANGELOG.md`, `LICENSE`. Every other Markdown
file is kebab-case, including everything under `docs/`. Directory READMEs are
`README.md` at any depth.

## License provenance

The project is Apache-2.0. Every active source file under `rtl/`, `tb/`, `model/`,
and `scripts/` carries a two-line header:

```text
SPDX-License-Identifier: Apache-2.0
Copyright 2026 Vamsidhar Reddy Eraganeni
```

One-line SPDX tags rather than the full Apache header block, because a twenty-line
header on a 280-line RTL file costs more than it informs. Attribution lives in
[`NOTICE`](../NOTICE). Files under `archive/` keep their original headers.

## Documentation contract

`make check-docs` enforces the mechanical parts of this. The rest is on the
author.

Every document has exactly one H1, opens with one paragraph naming what it is for
and who reads it, moves from overview to detail, and ends with a `## Related`
section of repository-relative links.

Every document is reachable from [`README.md`](../README.md) in at most two hops,
through this file or [`docs/README.md`](README.md).

No adjective without a number. Write "3.41x fewer core cycles", not
"significantly faster". Write "6,672,971 um²", not "large area".

Every result says whether it is measured or projected, and a measured result
carries its commit, parameters, tool versions, and corner. This rule is also in
[`CODEX.md`](../CODEX.md) and applies to every file in `docs/results/`.

Never write "this becomes" or "for consistency" in place of a derivation. Show
the arithmetic, or write that the number is not known.

State a limit in the same paragraph as the result it limits, not in a separate
section a reader can skip.

Commands are copy-pasteable and name the directory they run from.

Tables compare rows. A one-row table is a paragraph.

## Related

- [Documentation index](README.md)
- [Contribution workflow](../CONTRIBUTING.md)
- [Agent rules](../CODEX.md)
- [Changelog](../CHANGELOG.md)
