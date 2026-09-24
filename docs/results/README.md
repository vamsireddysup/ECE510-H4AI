# Results and transcripts

I keep two levels of test output:

1. Full generated logs, summaries, and waveforms go under the ignored `build/`
   directory. They are easy to regenerate and can be large.
2. Reviewed results that should remain in Git go in this directory.

The active integration run writes:

```text
build/integration/build.log
build/integration/run.log
build/integration/summary.txt
```

The untouched M4 comparison run writes:

```text
build/m4-baseline/build.log
build/m4-baseline/run.log
build/m4-baseline/summary.txt
```

I summarize the latest reviewed run in
[`latest-verification.md`](latest-verification.md). I update it when the design,
test coverage, parameters, or tool versions change.
