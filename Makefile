.DEFAULT_GOAL := help

.PHONY: help doctor baseline baseline-strict clean

help:
	@printf '%s\n' \
	  'ECE510-H4AI developer commands' \
	  '' \
	  '  make doctor          Check required and optional tools' \
	  '  make baseline        Reproduce the historical M4 numeric result' \
	  '  make baseline-strict Require numeric and completion-status checks' \
	  '  make clean           Remove repository-local generated output'

doctor:
	@./scripts/doctor.sh

baseline:
	@./scripts/run_m4_baseline.sh

baseline-strict:
	@./scripts/run_m4_baseline.sh --strict

clean:
	@./scripts/clean.sh
