# Contributing

I use this workflow for changes to the project:

1. Work directly on `master` and check `git status` before changing files.
2. Add or update a test for the behavior being changed.
3. Keep generated files under `build/`.
4. Run `make lint` and the tests related to the change.
5. Update the matching documentation.
6. Commit one logical change with a short message such as
   `rtl: reset PEs between tiles`.

The milestone directories under `archive/coursework/project/` are historical
records. New RTL belongs under `rtl/`, and new tests belong under `tb/`.

Measured and projected results must be labeled separately. A benchmark or
synthesis result should include the commit, parameters, tool versions, clock,
and the exact target that was tested.

## Related

- [Agent rules and commit policy](CODEX.md)
- [Repository layout and documentation contract](docs/repository-layout.md)
- [Documentation index](docs/README.md)
