.DEFAULT_GOAL := help

.PHONY: help doctor check-docs lint baseline baseline-strict test-model test-integration test-integration-large test-integration-reuse test-integration-reuse-large test-array8 test-array16 test-array8-large test-array16-large test clean

help:
	@printf '%s\n' \
	  'ECE510-H4AI developer commands' \
	  '' \
	  '  make doctor          Check required and optional tools' \
	  '  make check-docs      Check active Markdown structure and links' \
	  '  make lint            Lint the active RTL source tree' \
	  '  make baseline        Reproduce the historical M4 numeric result' \
	  '  make baseline-strict Require numeric and completion-status checks' \
	  '  make test-model      Test the FP4 and QK^T reference model' \
	  '  make test-integration Run the active 4x4 end-to-end test' \
	  '  make test-integration-large Run T=64/128/512, D_HEAD=64' \
	  '  make test-integration-reuse Test version 2 K reuse' \
	  '  make test-integration-reuse-large Test K reuse at T=64/128/512' \
	  '  make test-array8     Verify 8x8, D_HEAD=64' \
	  '  make test-array16    Verify 16x16, D_HEAD=64' \
	  '  make test-array8-large  Benchmark 8x8 at T=64/128/512' \
	  '  make test-array16-large Benchmark 16x16 at T=64/128/512' \
	  '  make test            Run the current required checks' \
	  '  make clean           Remove repository-local generated output'

doctor:
	@./scripts/doctor.sh

check-docs:
	@python3 scripts/check_markdown.py

lint:
	@./scripts/lint.sh

baseline:
	@./scripts/run_m4_baseline.sh

baseline-strict:
	@./scripts/run_m4_baseline.sh --strict

test-model:
	@python3 -m pytest model/tests

test-integration:
	@./scripts/run_integration.sh

test-integration-large:
	@./scripts/run_integration.sh --large

test-integration-reuse:
	@./scripts/run_integration.sh --reuse

test-integration-reuse-large:
	@./scripts/run_integration.sh --reuse-large

test-array8:
	@./scripts/run_integration.sh --array8

test-array16:
	@./scripts/run_integration.sh --array16

test-array8-large:
	@./scripts/run_integration.sh --array8-large

test-array16-large:
	@./scripts/run_integration.sh --array16-large

test: check-docs lint test-model test-integration

clean:
	@./scripts/clean.sh
