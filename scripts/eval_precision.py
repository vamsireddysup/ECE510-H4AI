#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Sweep reduction-block scale formats for FP4 QK^T."""
from __future__ import annotations

import argparse
import hashlib
import json
import math
from pathlib import Path

import numpy as np

MAGNITUDES = np.array([0, .5, 1, 1.5, 2, 3, 4, 6], dtype=np.float32)
HALF_UNITS = np.array([0, 1, 2, 3, 4, 6, 8, 12], dtype=np.int32)
BLOCK_SIZES = (64, 32, 16, 8, 4, 2)
SCALE_TYPES = ("FP32", "E8M0-floor", "E8M0-nearest", "E8M0-ceil")


def power_of_two_scale(ideal: np.ndarray, rule: str) -> np.ndarray:
    """Round positive dequantization scales to an E8M0 power of two."""
    logarithm = np.log2(ideal.astype(np.float64))
    if rule == "E8M0-floor":
        exponent = np.floor(logarithm)
    elif rule == "E8M0-nearest":
        exponent = np.floor(logarithm + 0.5)
    elif rule == "E8M0-ceil":
        exponent = np.ceil(logarithm)
    else:
        raise ValueError(f"unknown E8M0 rounding rule: {rule}")
    exponent = np.clip(exponent, -127, 127).astype(np.int16)
    return np.exp2(exponent).astype(np.float32)


def quantize_blocks(
    values: np.ndarray, block_size: int, scale_type: str
) -> tuple[np.ndarray, np.ndarray, int]:
    """Quantize T x D values and return half units, block scales, clips."""
    if values.ndim != 2 or block_size <= 0:
        raise ValueError("values must be T x D and block_size must be positive")
    row_count, depth = values.shape
    block_count = math.ceil(depth / block_size)
    half_units = np.empty(values.shape, dtype=np.int32)
    scales = np.empty((row_count, block_count), dtype=np.float32)
    clip_count = 0
    for block in range(block_count):
        start = block * block_size
        stop = min(start + block_size, depth)
        chunk = values[:, start:stop]
        maximum = np.max(np.abs(chunk), axis=1)
        ideal = np.where(maximum == 0, 1.0, maximum / 6).astype(np.float32)
        scale = ideal if scale_type == "FP32" else power_of_two_scale(ideal, scale_type)
        normalized = np.abs(chunk / scale[:, None])
        clip_count += int(np.count_nonzero(normalized > 6.0))
        indices = np.argmin(np.abs(normalized[:, :, None] - MAGNITUDES), axis=2)
        half_units[:, start:stop] = (
            HALF_UNITS[indices] * np.where(chunk < 0, -1, 1)
        )
        scales[:, block] = scale
    return half_units, scales, clip_count


def softmax(scores: np.ndarray) -> np.ndarray:
    shifted = scores.astype(np.float64) - np.max(scores, axis=1, keepdims=True)
    exponentials = np.exp(shifted)
    return exponentials / np.sum(exponentials, axis=1, keepdims=True)


def evaluate(
    q: np.ndarray, k: np.ndarray, block_size: int = 64, scale_type: str = "FP32"
) -> dict[str, float | int | str]:
    if q.ndim != 2 or k.shape != q.shape or q.shape[1] == 0:
        raise ValueError("q and k must have the same nonempty T x D shape")
    q = np.asarray(q, dtype=np.float32)
    k = np.asarray(k, dtype=np.float32)
    if not np.isfinite(q).all() or not np.isfinite(k).all():
        raise ValueError("inputs must be finite")
    if block_size > q.shape[1]:
        raise ValueError("block_size must not exceed D_HEAD")

    q_half, q_scale, q_clips = quantize_blocks(q, block_size, scale_type)
    k_half, k_scale, k_clips = quantize_blocks(k, block_size, scale_type)
    block_count = q_scale.shape[1]
    fp4_scores = np.zeros((q.shape[0], q.shape[0]), dtype=np.float32)
    for block in range(block_count):
        start = block * block_size
        stop = min(start + block_size, q.shape[1])
        exact_quarters = q_half[:, start:stop] @ k_half[:, start:stop].T
        block_scores = exact_quarters.astype(np.float32) * np.float32(.25)
        block_scores *= q_scale[:, block, None]
        block_scores *= k_scale[None, :, block]
        fp4_scores += block_scores

    fp32_scores = q @ k.T
    difference = fp4_scores.astype(np.float64) - fp32_scores.astype(np.float64)
    divisor = math.sqrt(q.shape[1])
    reference_probability = softmax(fp32_scores / divisor)
    fp4_probability = softmax(fp4_scores / divisor)
    tiny = np.finfo(np.float64).tiny
    kl_rows = np.sum(
        reference_probability
        * (np.log(np.maximum(reference_probability, tiny))
           - np.log(np.maximum(fp4_probability, tiny))),
        axis=1,
    )
    tv_rows = 0.5 * np.sum(
        np.abs(reference_probability - fp4_probability), axis=1
    )
    top1 = np.argmax(reference_probability, axis=1) == np.argmax(fp4_probability, axis=1)
    top_k = min(5, q.shape[0])
    reference_top = np.argpartition(reference_probability, -top_k, axis=1)[:, -top_k:]
    fp4_top = np.argpartition(fp4_probability, -top_k, axis=1)[:, -top_k:]
    overlap = np.array([
        len(set(reference_top[row]) & set(fp4_top[row])) / top_k
        for row in range(q.shape[0])
    ])
    scale_bytes = 4 if scale_type == "FP32" else 1
    return {
        "T": q.shape[0], "D_HEAD": q.shape[1],
        "block_size": block_size, "scale_type": scale_type,
        "mean_kl_divergence": float(np.mean(kl_rows)),
        "mean_total_variation": float(np.mean(tv_rows)),
        "top1_agreement": float(np.mean(top1)),
        "top5_index_agreement": float(np.mean(overlap)),
        "mean_abs_error": float(np.mean(np.abs(difference))),
        "relative_frobenius_error": float(
            np.linalg.norm(difference)
            / max(np.linalg.norm(fp32_scores.astype(np.float64)), 1e-30)
        ),
        "clipped_input_fraction": float((q_clips + k_clips) / (q.size + k.size)),
        "scale_bytes_per_q_or_k_element": scale_bytes / block_size,
        "fp32_adds_per_score": block_count - 1,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--npz", type=Path, help="Pinned Q/K capture with q and k arrays")
    parser.add_argument("--sizes", type=int, nargs="+", default=[4, 16, 64, 128, 512])
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--seed", type=int, default=510)
    args = parser.parse_args()
    if args.npz:
        with np.load(args.npz) as capture:
            matrices = [(capture["q"], capture["k"])]
        source = {"source": str(args.npz),
                  "sha256": hashlib.sha256(args.npz.read_bytes()).hexdigest()}
    else:
        generator = np.random.default_rng(args.seed)
        matrices = [(
            generator.standard_normal((size, args.depth), dtype=np.float32),
            generator.standard_normal((size, args.depth), dtype=np.float32),
        ) for size in args.sizes]
        source = {"source": "synthetic_normal", "seed": args.seed}
    metrics = [
        evaluate(q, k, block_size, scale_type)
        for q, k in matrices
        for block_size in BLOCK_SIZES if block_size <= q.shape[1]
        for scale_type in SCALE_TYPES
    ]
    print(json.dumps({**source, "metrics": metrics}, indent=2))


if __name__ == "__main__":
    main()
