#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Generate the pinned T=512 data used by the RTL precision comparison."""
from __future__ import annotations

import argparse
from pathlib import Path

import numpy as np

from eval_precision import quantize_blocks

HALF_TO_CODE = {0: 0, 1: 1, 2: 2, 3: 3, 4: 4, 6: 5, 8: 6, 12: 7}


def encode_fp4(half_units: np.ndarray) -> np.ndarray:
    """Encode signed half-unit integers as E2M1 codes."""
    codes = np.empty(half_units.shape, dtype=np.uint8)
    for magnitude, code in HALF_TO_CODE.items():
        codes[np.abs(half_units) == magnitude] = code
    codes[half_units < 0] |= np.uint8(8)
    return codes


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    parser.add_argument("--seed", type=int, default=510)
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--block-size", type=int, default=32)
    args = parser.parse_args()

    generator = np.random.default_rng(args.seed)
    q = k = None
    for size in (4, 16, 64, 128, 512):
        q = generator.standard_normal((size, args.depth), dtype=np.float32)
        k = generator.standard_normal((size, args.depth), dtype=np.float32)
    assert q is not None and k is not None

    q_half, q_scales, _ = quantize_blocks(q, args.block_size, "FP32")
    k_half, k_scales, _ = quantize_blocks(k, args.block_size, "FP32")
    block_count = q_scales.shape[1]
    model_scores = np.zeros((q.shape[0], q.shape[0]), dtype=np.float32)
    for block in range(block_count):
        start = block * args.block_size
        stop = min(start + args.block_size, args.depth)
        exact_quarters = q_half[:, start:stop] @ k_half[:, start:stop].T
        block_scores = exact_quarters.astype(np.float32) * np.float32(0.25)
        block_scores *= q_scales[:, block, None]
        block_scores *= k_scales[None, :, block]
        model_scores += block_scores
    reference_scores = q @ k.T

    args.output.parent.mkdir(parents=True, exist_ok=True)
    with args.output.open("wb") as capture:
        np.asarray([q.shape[0], args.depth, block_count], dtype="<u4").tofile(capture)
        q_scales.astype("<f4", copy=False).tofile(capture)
        k_scales.astype("<f4", copy=False).tofile(capture)
        encode_fp4(q_half).tofile(capture)
        encode_fp4(k_half).tofile(capture)
        model_scores.astype("<f4", copy=False).tofile(capture)
        reference_scores.astype("<f4", copy=False).tofile(capture)


if __name__ == "__main__":
    main()
