#!/usr/bin/env bash
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni

read_rtl_filelist() {
    local repo_root="$1"
    local filelist="$repo_root/rtl/filelist.f"
    local line

    RTL_SOURCES=()
    while IFS= read -r line || [[ -n "$line" ]]; do
        [[ -z "$line" || "$line" == \#* ]] && continue
        RTL_SOURCES+=("$repo_root/$line")
    done < "$filelist"
}
