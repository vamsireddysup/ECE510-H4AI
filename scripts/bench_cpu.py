#!/usr/bin/env python3
"""Reproducible one-thread NumPy FP32 QK^T timing; no peak claim."""
from __future__ import annotations

import argparse
import json
import os
import platform
import statistics
import time

for variable in ("OPENBLAS_NUM_THREADS", "MKL_NUM_THREADS", "OMP_NUM_THREADS", "BLIS_NUM_THREADS"):
    os.environ[variable] = "1"

import numpy as np  # noqa: E402
from threadpoolctl import threadpool_info, threadpool_limits  # noqa: E402

MAGNITUDES = np.array([0, .5, 1, 1.5, 2, 3, 4, 6], dtype=np.float32)


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


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--sizes", type=int, nargs="+", default=[4, 16, 64, 128, 512])
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--seed", type=int, default=510)
    parser.add_argument("--trials", type=int, default=7)
    parser.add_argument("--budget", type=float, default=.1)
    args = parser.parse_args()
    with threadpool_limits(limits=1):
        result = {
            "method": "NumPy FP32 matmul; one BLAS thread; fixed FP4-derived inputs",
            "python": platform.python_version(), "processor": platform.processor(),
            "numpy": np.__version__, "seed": args.seed, "trials": args.trials,
            "thread_env": {key: os.environ[key] for key in (
                "OPENBLAS_NUM_THREADS", "MKL_NUM_THREADS", "OMP_NUM_THREADS", "BLIS_NUM_THREADS")},
            "threadpools": threadpool_info(),
            "results": [run(size, args.depth, args.seed, args.trials, args.budget) for size in args.sizes],
        }
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
