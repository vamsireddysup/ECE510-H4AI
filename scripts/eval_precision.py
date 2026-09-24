#!/usr/bin/env python3
"""Measure row-scaled FP4 QK^T quantization error against FP32 QK^T."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path

import numpy as np

MAGNITUDES = np.array([0, .5, 1, 1.5, 2, 3, 4, 6], dtype=np.float32)
HALF_UNITS = np.array([0, 1, 2, 3, 4, 6, 8, 12], dtype=np.int32)


def quantize_rows(values: np.ndarray) -> tuple[np.ndarray, np.ndarray]:
    row_max = np.max(np.abs(values), axis=1)
    scales = np.where(row_max == 0, 1.0, row_max / 6).astype(np.float32)
    normalized = np.abs(values / scales[:, None])
    indices = np.argmin(np.abs(normalized[:, :, None] - MAGNITUDES), axis=2)
    signed_half = HALF_UNITS[indices] * np.where(values < 0, -1, 1)
    return signed_half.astype(np.int32), scales


def evaluate(q: np.ndarray, k: np.ndarray) -> dict:
    if q.ndim != 2 or k.shape != q.shape or q.shape[1] == 0:
        raise ValueError("q and k must have the same nonempty T x D shape")
    q = np.asarray(q, dtype=np.float32)
    k = np.asarray(k, dtype=np.float32)
    if not np.isfinite(q).all() or not np.isfinite(k).all():
        raise ValueError("inputs must be finite")
    q_half, q_scale = quantize_rows(q)
    k_half, k_scale = quantize_rows(k)
    exact_quarters = q_half @ k_half.T
    fp4_scores = exact_quarters.astype(np.float32) * np.float32(.25)
    fp4_scores *= q_scale[:, None]
    fp4_scores *= k_scale[None, :]
    fp32_scores = q @ k.T
    difference = fp4_scores.astype(np.float64) - fp32_scores.astype(np.float64)
    return {
        "T": q.shape[0], "D_HEAD": q.shape[1],
        "mean_abs_error": float(np.mean(np.abs(difference))),
        "root_mean_square_error": float(np.sqrt(np.mean(difference**2))),
        "max_abs_error": float(np.max(np.abs(difference))),
        "relative_frobenius_error": float(np.linalg.norm(difference) /
            max(np.linalg.norm(fp32_scores.astype(np.float64)), 1e-30)),
        "max_abs_reference_score": float(np.max(np.abs(fp32_scores))),
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--npz", type=Path, help="Pinned Q/K activation capture with q and k arrays")
    parser.add_argument("--sizes", type=int, nargs="+", default=[4, 16, 64, 128, 512])
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--seed", type=int, default=510)
    args = parser.parse_args()
    if args.npz:
        with np.load(args.npz) as capture:
            q, k = capture["q"], capture["k"]
        digest = hashlib.sha256(args.npz.read_bytes()).hexdigest()
        result = {"source": str(args.npz), "sha256": digest,
                  "metrics": [evaluate(q, k)]}
    else:
        generator = np.random.default_rng(args.seed)
        result = {"source": "synthetic_normal", "seed": args.seed,
                  "metrics": [evaluate(
                      generator.standard_normal((size, args.depth), dtype=np.float32),
                      generator.standard_normal((size, args.depth), dtype=np.float32))
                      for size in args.sizes]}
    print(json.dumps(result, indent=2))


if __name__ == "__main__":
    main()
