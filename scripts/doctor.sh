#!/usr/bin/env bash
set -euo pipefail

required=(verilator g++ make python3 git)
optional=(yosys iverilog sby docker uv gtkwave clang-format cmake ninja)
missing_required=0

version_line() {
    local tool="$1"

    case "$tool" in
        iverilog)
            "$tool" -V 2>&1 | head -n 1
            ;;
        gtkwave)
            printf '%s\n' 'installed (GUI requires a display)'
            ;;
        sby)
            if "$tool" -V >/dev/null 2>&1; then
                "$tool" -V 2>&1 | head -n 1
            else
                printf '%s\n' 'installed but unhealthy (Python modules missing)'
            fi
            ;;
        *)
            "$tool" --version 2>&1 | head -n 1
            ;;
    esac
}

printf '%s\n' 'Required tools'
for tool in "${required[@]}"; do
    if command -v "$tool" >/dev/null 2>&1; then
        printf '  %-14s %s\n' "$tool" "$(version_line "$tool")"
    else
        printf '  %-14s %s\n' "$tool" 'MISSING'
        missing_required=1
    fi
done

printf '\n%s\n' 'Optional tools'
for tool in "${optional[@]}"; do
    if command -v "$tool" >/dev/null 2>&1; then
        printf '  %-14s %s\n' "$tool" "$(version_line "$tool")"
    else
        printf '  %-14s %s\n' "$tool" 'not installed'
    fi
done

if ((missing_required)); then
    printf '\n%s\n' 'Doctor failed: install the missing required tools.' >&2
    exit 1
fi

printf '\n%s\n' 'Doctor passed: baseline requirements are available.'
