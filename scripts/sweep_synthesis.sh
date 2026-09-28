#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Synthesis-only grid over clock period and ABC strategy, run JOBS at a time.
#   ./scripts/sweep_synthesis.sh PREFIX "20 15 12 10 8" "AREA 0|DELAY 0|DELAY 2" [JOBS]
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
prefix="$1"
periods="$2"
IFS='|' read -r -a strategies <<< "$3"
jobs="${4:-4}"
tasks=()
for period in $periods; do
    for strategy in "${strategies[@]}"; do
        tag="$(printf '%s' "$strategy" | tr 'A-Z ' 'a-z-')"
        tasks+=("$prefix-p${period}-${tag}|$period|$strategy")
    done
done
printf '%s\n' "${tasks[@]}" | xargs -P "$jobs" -I{} bash -c '
    IFS="|" read -r name period strategy <<< "{}"
    SYNTH_STRATEGY="$strategy" SYNTH_SIZING="${SYNTH_SIZING:-1}" \
        SYNTH_BUFFERING="${SYNTH_BUFFERING:-1}" \
        "'"$script_dir"'/run_physical.sh" "$name" "$period" 4 1 synthesis \
        > /dev/null 2>&1 && echo "done $name" || echo "FAILED $name"
'
