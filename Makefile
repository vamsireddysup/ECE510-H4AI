.DEFAULT_GOAL := help

.PHONY: help doctor lint baseline baseline-strict test-integration test clean

help:
	@printf '%s\n' \
	  'ECE510-H4AI developer commands' \
	  '' \
	  '  make doctor          Check required and optional tools' \
	  '  make lint            Lint the active RTL source tree' \
	  '  make baseline        Reproduce the historical M4 numeric result' \
	  '  make baseline-strict Require numeric and completion-status checks' \
	  '  make test-integration Run the active 4x4 end-to-end test' \
	  '  make test            Run the current required checks' \
	  '  make clean           Remove repository-local generated output'

doctor:
	@./scripts/doctor.sh

lint:
	@./scripts/lint.sh

baseline:
	@./scripts/run_m4_baseline.sh

baseline-strict:
	@./scripts/run_m4_baseline.sh --strict

test-integration:
	@./scripts/run_integration.sh

test: lint test-integration

clean:
	@./scripts/clean.sh
