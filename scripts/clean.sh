#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
build_dir="$repo_root/build"
pytest_cache="$repo_root/.pytest_cache"

if [[ -d "$build_dir" ]]; then
    rm -rf -- "$build_dir"
    printf 'Removed %s\n' "$build_dir"
else
    printf '%s\n' 'Nothing to clean.'
fi

if [[ -d "$pytest_cache" ]]; then
    rm -rf -- "$pytest_cache"
    printf 'Removed %s\n' "$pytest_cache"
fi
