#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
# Install the pinned LibreLane launcher and ciel PDK manager into a venv outside
# the repository, then fetch the pinned Sky130 PDK. LibreLane runs its EDA tools
# in its own container (--dockerized), so the venv only holds the launcher.
#   ./scripts/install_librelane.sh
set -euo pipefail
script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_root="$(cd "$script_dir/.." && pwd)"
source "$repo_root/config/librelane/versions.env"

venv="${LIBRELANE_VENV:-$HOME/.local/share/fp4-accel/librelane-venv}"
pdk_root="${PDK_ROOT_LIBRELANE:-$HOME/.ciel}"

if ! command -v uv >/dev/null; then
    printf 'uv is required: https://docs.astral.sh/uv/\n' >&2
    exit 1
fi
if ! docker info >/dev/null 2>&1; then
    printf 'Docker must be running for LibreLane --dockerized.\n' >&2
    exit 1
fi

uv venv --allow-existing --python 3.12 "$venv"
uv pip install --python "$venv/bin/python" \
    "librelane==$LIBRELANE_VERSION" "ciel==$CIEL_VERSION"

"$venv/bin/ciel" enable --pdk-root "$pdk_root" --pdk-family sky130 "$SKY130_PDK_REVISION"

printf 'LibreLane %s in %s\n' \
    "$("$venv/bin/python" -c 'import importlib.metadata as m; print(m.version("librelane"))')" "$venv"
printf 'Sky130 %s in %s\n' "$SKY130_PDK_REVISION" "$pdk_root"
