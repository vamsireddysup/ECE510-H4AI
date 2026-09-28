#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Floorplan grid over die edge and placement density, stopping after global
# routing, run JOBS at a time. Synthesis uses SYNTH_CLOCK_PERIOD.
#   ./scripts/sweep_floorplan.sh PREFIX PERIOD "1300 1500 1800 2200" "0.45 0.55 0.65" [JOBS]
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
prefix="$1"
period="$2"
dies="$3"
densities="$4"
jobs="${5:-2}"
tasks=()
for die in $dies; do
    for density in $densities; do
        name="$prefix-d${die}-p${density/./}"
        if [[ -d "$script_dir/../build/physical/$name/runs/full/results" ]]; then
            continue
        fi
        tasks+=("$name|$die|$density")
    done
done
printf '%s\n' "${tasks[@]}" | xargs -P "$jobs" -I{} bash -c '
    IFS="|" read -r name die density <<< "{}"
    DIE_AREA="0 0 $die $die" PL_TARGET_DENSITY="$density" \
        "'"$script_dir"'/run_physical.sh" "$name" "'"$period"'" 4 1 global-route \
        > /dev/null 2>&1 && echo "done $name" || echo "FAILED $name"
'
