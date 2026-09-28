#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Reproducible NumPy FP32 QK^T timing with host provenance.

The one-thread path is the baseline and is unchanged. The host block, the
optional all-core mode, and the theoretical peak are additions; the peak is
reported as a ceiling and is never the baseline.
"""
from __future__ import annotations

import argparse
import json
import os
import platform
import re
import statistics
import subprocess
import sys
import time
from pathlib import Path

ALL_CORE_CHILD = os.environ.get("QKT_BENCH_ALL_CORES") == "1"

if not ALL_CORE_CHILD:
    for variable in ("OPENBLAS_NUM_THREADS", "MKL_NUM_THREADS", "OMP_NUM_THREADS", "BLIS_NUM_THREADS"):
        os.environ[variable] = "1"

import numpy as np  # noqa: E402
from threadpoolctl import threadpool_info, threadpool_limits  # noqa: E402

MAGNITUDES = np.array([0, .5, 1, 1.5, 2, 3, 4, 6], dtype=np.float32)


def read_int(path: str) -> int | None:
    try:
        return int(Path(path).read_text().strip())
    except (OSError, ValueError):
        return None


def cpu_topology() -> dict:
    """Physical and logical core counts from /proc/cpuinfo."""
    logical = 0
    physical: set[tuple[str, str]] = set()
    package = core = None
    model = None
    flags: set[str] = set()
    try:
        text = Path("/proc/cpuinfo").read_text()
    except OSError:
        return {"logical_cores": os.cpu_count(), "physical_cores": None,
                "model_name": None, "detected_isa": []}
    for line in text.splitlines():
        if ":" not in line:
            if package is not None and core is not None:
                physical.add((package, core))
            package = core = None
            continue
        key, _, value = line.partition(":")
        key, value = key.strip(), value.strip()
        if key == "processor":
            logical += 1
        elif key == "model name" and model is None:
            model = value
        elif key == "physical id":
            package = value
        elif key == "core id":
            core = value
        elif key == "flags" and not flags:
            flags = set(value.split())
    if package is not None and core is not None:
        physical.add((package, core))
    isa = [name for name in ("avx512f", "avx512dq", "avx2", "fma", "sse2")
           if name in flags]
    return {
        "model_name": model,
        "logical_cores": logical or os.cpu_count(),
        "physical_cores": len(physical) or None,
        "detected_isa": isa,
    }


def host_block() -> dict:
    """Everything a reader needs to judge whether this number transfers."""
    topology = cpu_topology()
    nominal = None
    if topology["model_name"]:
        match = re.search(r"@\s*([\d.]+)\s*GHz", topology["model_name"])
        if match:
            nominal = float(match.group(1)) * 1e9
    base = read_int("/sys/devices/system/cpu/cpu0/cpufreq/base_frequency")
    maximum = read_int("/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_max_freq")
    memory = None
    try:
        for line in Path("/proc/meminfo").read_text().splitlines():
            if line.startswith("MemTotal:"):
                memory = int(line.split()[1]) * 1024
                break
    except OSError:
        pass
    pools = threadpool_info()
    return {
        **topology,
        "nominal_clock_hz": nominal,
        "sysfs_base_clock_hz": base * 1000 if base else None,
        "sysfs_max_clock_hz": maximum * 1000 if maximum else None,
        "memory_bytes": memory,
        "os": f"{platform.system()} {platform.release()}",
        "platform": platform.platform(),
        "libc": " ".join(platform.libc_ver()),
        "blas_libraries": [
            {key: pool.get(key) for key in
             ("user_api", "internal_api", "filepath", "version",
              "num_threads", "threading_layer")}
            for pool in pools
        ],
        "threadpool_detected": bool(pools),
    }


def single_core_peak(host: dict, clock_hz: float | None) -> dict | None:
    """Theoretical single-core FP32 peak. A ceiling, never a baseline."""
    if clock_hz is None:
        return None
    isa = host["detected_isa"]
    if "avx512f" in isa:
        name, lanes = "AVX-512", 16
    elif "avx2" in isa and "fma" in isa:
        name, lanes = "AVX2+FMA", 8
    else:
        return None
    per_fma_unit = lanes * 2  # one fused multiply-add per lane
    return {
        "note": "theoretical ceiling from detected ISA and clock; not a baseline",
        "isa": name,
        "clock_hz": clock_hz,
        "fp32_lanes": lanes,
        "flops_per_cycle_per_fma_unit": per_fma_unit,
        # Issue width is not detectable here, so both cases are reported and
        # the caller must not silently pick one.
        "peak_gflop_s_one_fma_unit": clock_hz * per_fma_unit / 1e9,
        "peak_gflop_s_two_fma_units": clock_hz * per_fma_unit * 2 / 1e9,
    }


def run(size: int, depth: int, seed: int, trials: int, budget: float) -> dict:
    generator = np.random.default_rng(seed + size)
    q_codes = generator.integers(0, 16, (size, depth), dtype=np.uint8)
    k_codes = generator.integers(0, 16, (size, depth), dtype=np.uint8)
    q_scales = generator.choice(np.array([.5, 1, 2], dtype=np.float32), size=size)
    k_scales = generator.choice(np.array([.5, 1, 2], dtype=np.float32), size=size)
    q = MAGNITUDES[q_codes & 7] * np.where(q_codes & 8, -1, 1) * q_scales[:, None]
    k = MAGNITUDES[k_codes & 7] * np.where(k_codes & 8, -1, 1) * k_scales[:, None]
    q = np.ascontiguousarray(q, dtype=np.float32)
    k = np.ascontiguousarray(k, dtype=np.float32)
    output = np.empty((size, size), dtype=np.float32)
    for _ in range(10):
        np.matmul(q, k.T, out=output)
    repeats = 1
    while True:
        begin = time.perf_counter()
        for _ in range(repeats):
            np.matmul(q, k.T, out=output)
        if time.perf_counter() - begin >= budget or repeats >= 1_000_000:
            break
        repeats *= 2
    samples = []
    for _ in range(trials):
        begin = time.perf_counter_ns()
        for _ in range(repeats):
            np.matmul(q, k.T, out=output)
        samples.append((time.perf_counter_ns() - begin) / repeats)
    median_ns = statistics.median(samples)
    return {
        "T": size, "D_HEAD": depth, "repeats_per_trial": repeats,
        "median_ns": median_ns, "min_ns": min(samples),
        "measured_gflop_s": (2 * size * size * depth) / median_ns,
        "checksum": float(np.sum(output, dtype=np.float64)),
    }


def all_core_child(args) -> dict:
    """Re-run the same problem in a process that was never thread-pinned."""
    if ALL_CORE_CHILD:
        return {
            "method": "same problem and inputs; every BLAS thread allowed",
            "threadpools": threadpool_info(),
            "results": [run(size, args.depth, args.seed, args.trials, args.budget)
                        for size in args.sizes],
        }
    environment = dict(os.environ)
    environment["QKT_BENCH_ALL_CORES"] = "1"
    for variable in ("OPENBLAS_NUM_THREADS", "MKL_NUM_THREADS",
                     "OMP_NUM_THREADS", "BLIS_NUM_THREADS"):
        environment.pop(variable, None)
    command = [
        sys.executable, os.path.abspath(__file__), "--all-cores",
        "--depth", str(args.depth), "--seed", str(args.seed),
        "--trials", str(args.trials), "--budget", str(args.budget),
        "--sizes", *[str(size) for size in args.sizes],
    ]
    completed = subprocess.run(
        command, env=environment, capture_output=True, text=True, check=True
    )
    return json.loads(completed.stdout)["all_cores"]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--sizes", type=int, nargs="+", default=[4, 16, 64, 128, 512])
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--seed", type=int, default=510)
    parser.add_argument("--trials", type=int, default=7)
    parser.add_argument("--budget", type=float, default=.1)
    parser.add_argument(
        "--all-cores", action="store_true",
        help="additionally time the same problem with every BLAS thread allowed",
    )
    args = parser.parse_args()
    host = host_block()
    with threadpool_limits(limits=1):
        result = {
            "method": "NumPy FP32 matmul; one BLAS thread; fixed FP4-derived inputs",
            "python": platform.python_version(), "processor": platform.processor(),
            "numpy": np.__version__, "seed": args.seed, "trials": args.trials,
            "thread_env": {key: os.environ.get(key) for key in (
                "OPENBLAS_NUM_THREADS", "MKL_NUM_THREADS", "OMP_NUM_THREADS", "BLIS_NUM_THREADS")},
            "threadpools": threadpool_info(),
            "results": [run(size, args.depth, args.seed, args.trials, args.budget) for size in args.sizes],
        }
    result["host"] = host
    result["cache_residency"] = (
        "warm by construction: q, k, and the output buffer are reused across "
        "every repeat, so the working set stays resident. This favours the CPU."
    )
    for clock_name, clock in (
        ("sysfs_max_clock_hz", host["sysfs_max_clock_hz"]),
        ("sysfs_base_clock_hz", host["sysfs_base_clock_hz"]),
    ):
        peak = single_core_peak(host, clock)
        if peak:
            result.setdefault("single_core_peak", {})[clock_name] = peak
    peaks = result.get("single_core_peak", {}).get("sysfs_max_clock_hz")
    if peaks:
        for row in result["results"]:
            row["fraction_of_one_fma_unit_peak"] = (
                row["measured_gflop_s"] / peaks["peak_gflop_s_one_fma_unit"]
            )

    if args.all_cores:
        # A BLAS fixes its pool size when it loads, so the all-core run has to
        # be a fresh process that never saw the pinning. This keeps the
        # one-thread path above completely untouched.
        result["all_cores"] = all_core_child(args)
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
