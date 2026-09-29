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
# Output score formats. The engine emits FP32 today; the narrower formats fit
# four scores in one 64-bit beat instead of two.
OUTPUT_FORMATS = ("FP32", "FP16", "BF16")
PREPROCESSING_TYPES = ("none", "k-center", "hadamard", "k-center+hadamard")


def render_t512_table(metrics: list[dict[str, float | int | str]]) -> str:
    """Render the reviewed T=512, Bs>=8 result table from sweep records."""
    header = (
        "| Bs | Scale | Mean KL | Mean TV | Top-1 | Top-5 overlap | "
        "Rel. Frobenius | Mean abs. error | Clipped inputs | "
        "Scale B/element | FP32 adds/score |\n"
        "| ---: | --- | ---: | ---: | ---: | ---: | ---: | ---: | "
        "---: | ---: | ---: |"
    )
    rows = [header]
    for row in metrics:
        if row["T"] != 512 or int(row["block_size"]) < 8:
            continue
        rows.append(
            f"| {row['block_size']} | {row['scale_type']} | "
            f"{float(row['mean_kl_divergence']):.5f} | "
            f"{float(row['mean_total_variation']):.5f} | "
            f"{100 * float(row['top1_agreement']):.2f}% | "
            f"{100 * float(row['top5_index_agreement']):.2f}% | "
            f"{100 * float(row['relative_frobenius_error']):.2f}% | "
            f"{float(row['mean_abs_error']):.3f} | "
            f"{100 * float(row['clipped_input_fraction']):.2f}% | "
            f"{float(row['scale_bytes_per_q_or_k_element']):g} | "
            f"{row['fp32_adds_per_score']} |"
        )
    return "\n".join(rows)


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


def quantize_output(scores: np.ndarray, output_format: str) -> np.ndarray:
    """Round finished FP32 scores to a narrower output format, ties to even."""
    if output_format == "FP32":
        return scores
    if output_format == "FP16":
        return scores.astype(np.float16).astype(np.float32)
    if output_format == "BF16":
        bits = scores.astype(np.float32).view(np.uint32)
        # Round to nearest, ties to even, on the low 16 mantissa bits.
        bias = np.uint32(0x7FFF) + ((bits >> np.uint32(16)) & np.uint32(1))
        return ((bits + bias) & np.uint32(0xFFFF0000)).view(np.float32)
    raise ValueError(f"unknown output format: {output_format}")


# Scale-format study (roadmap M1). These rules are evaluated alongside, never
# instead of, the committed P0.2 and P0.8 scale types above.
SCALE_STUDY_TYPES = (
    "FP32", "FP32-4over6", "E4M3", "E4M3-4over6", "E4M3-search",
    "E8M0-OCP", "E8M0-ceil", "E8M0-UOS",
)
E2M1_MAX = 6.0
E4M3_MAX = 448.0
UOS_QMAX = 7.25  # MXAttention's data-free clipping boundary for E8M0


def _e4m3_values() -> np.ndarray:
    """Every non-negative finite E4M3 value: bias 7, NaN at S.1111.111."""
    values = [m / 8 * 2.0 ** -6 for m in range(8)]  # subnormals, including 0
    for exponent in range(1, 16):
        for mantissa in range(8):
            if exponent == 15 and mantissa == 7:
                continue
            values.append((1 + mantissa / 8) * 2.0 ** (exponent - 7))
    return np.array(sorted(set(values)), dtype=np.float64)


E4M3_VALUES = _e4m3_values()


def _e4m3_index(value: np.ndarray) -> np.ndarray:
    """Index of the nearest E4M3 value, ties to the even code."""
    value = np.clip(value, 0, E4M3_MAX)
    upper = np.clip(np.searchsorted(E4M3_VALUES, value), 1, len(E4M3_VALUES) - 1)
    lower = upper - 1
    below = value - E4M3_VALUES[lower]
    above = E4M3_VALUES[upper] - value
    pick_upper = (above < below) | ((above == below) & (upper % 2 == 0))
    return np.where(pick_upper, upper, lower)


def _e2m1(chunk: np.ndarray, scale: np.ndarray) -> tuple[np.ndarray, np.ndarray, int]:
    """Signed half units, dequantized values, and clip count for per-row scales."""
    normalized = np.abs(chunk / scale[:, None])
    clips = int(np.count_nonzero(normalized > E2M1_MAX))
    indices = np.argmin(np.abs(normalized[:, :, None] - MAGNITUDES), axis=2)
    half = HALF_UNITS[indices] * np.where(chunk < 0, -1, 1)
    return half, half.astype(np.float64) / 2 * scale[:, None], clips


def _best_scale(chunk: np.ndarray, candidates: list[np.ndarray]) -> np.ndarray:
    """Per row, the candidate scale with the lowest reconstruction MSE."""
    errors = np.stack([
        np.mean((_e2m1(chunk, scale)[1] - chunk) ** 2, axis=1) for scale in candidates
    ])
    choice = np.argmin(errors, axis=0)
    return np.stack(candidates)[choice, np.arange(chunk.shape[0])]


def quantize_blocks_study(
    values: np.ndarray, block_size: int, scale_type: str
) -> tuple[np.ndarray, np.ndarray, int]:
    """Quantize T x D values under one SCALE_STUDY_TYPES rule.

    E4M3 rules follow NVFP4: a per-tensor FP32 scale maps the largest block
    scale onto the E4M3 range, and the block scale is E4M3 relative to it. The
    tensor scale is returned folded into the block scales; in hardware the
    product of the Q and K tensor scales is one constant per command, which can
    fold into the host's softmax temperature.
    """
    if scale_type not in SCALE_STUDY_TYPES:
        raise ValueError(f"unknown study scale type: {scale_type}")
    row_count, depth = values.shape
    block_count = math.ceil(depth / block_size)
    half_units = np.empty(values.shape, dtype=np.int32)
    scales = np.empty((row_count, block_count), dtype=np.float64)
    clip_count = 0
    values = values.astype(np.float64)
    tensor_scale = max(float(np.max(np.abs(values))), 1e-30) / (E2M1_MAX * E4M3_MAX)
    for block in range(block_count):
        start = block * block_size
        stop = min(start + block_size, depth)
        chunk = values[:, start:stop]
        maximum = np.max(np.abs(chunk), axis=1)
        live = maximum > 0
        safe = np.where(live, maximum, 1.0)
        if scale_type == "FP32":
            scale = safe / E2M1_MAX
        elif scale_type == "FP32-4over6":
            scale = _best_scale(chunk, [safe / 6.0, safe / 4.0])
        elif scale_type.startswith("E4M3"):
            def e4m3(ideal: np.ndarray, offset: int = 0) -> np.ndarray:
                index = _e4m3_index(ideal / tensor_scale) + offset
                index = np.clip(index, 1, len(E4M3_VALUES) - 1)  # never a zero scale
                return E4M3_VALUES[index] * tensor_scale
            if scale_type == "E4M3":
                scale = e4m3(safe / 6.0)
            elif scale_type == "E4M3-4over6":
                scale = _best_scale(chunk, [e4m3(safe / 6.0), e4m3(safe / 4.0)])
            else:  # ScaleSearch: code offsets -2 to +6 around the max-based code
                scale = _best_scale(chunk, [e4m3(safe / 6.0, f) for f in range(-2, 7)])
        else:
            if scale_type == "E8M0-OCP":
                exponent = np.floor(np.log2(safe)) - 2  # OCP MX rule for E2M1
            elif scale_type == "E8M0-ceil":
                exponent = np.ceil(np.log2(safe / E2M1_MAX))
            else:  # E8M0-UOS
                exponent = np.ceil(np.log2(safe / UOS_QMAX))
            scale = np.exp2(np.clip(exponent, -127, 127))
        scale = np.where(live, scale, 1.0)
        half, _, clips = _e2m1(chunk, scale)
        half_units[:, start:stop] = np.where(live[:, None], half, 0)
        clip_count += clips
        scales[:, block] = scale
    return half_units, scales.astype(np.float32), clip_count


def evaluate_scale_study(
    q: np.ndarray, k: np.ndarray, block_size: int, scale_type: str
) -> dict[str, float | int | str]:
    """Label a study row with its scale storage and hardware scale operation."""
    row = evaluate(q, k, block_size, scale_type, quantizer=quantize_blocks_study)
    scale_bytes = 4 if scale_type.startswith("FP32") else 1
    operation = {"FP32": "24x24 significand multiply", "E4M3": "4-bit significand multiply",
                 "E8M0": "exponent add only"}[scale_type.split("-")[0]]
    return {
        **row,
        "scale_bytes_per_q_or_k_element": scale_bytes / block_size,
        "scale_operation": operation,
    }


def hadamard_rotate(values: np.ndarray) -> np.ndarray:
    """Apply an orthonormal Walsh-Hadamard transform along D_HEAD."""
    if values.ndim != 2 or values.shape[1] == 0:
        raise ValueError("values must be a nonempty T x D array")
    depth = values.shape[1]
    if depth & (depth - 1):
        raise ValueError("Hadamard rotation requires power-of-two D_HEAD")
    rotated = values.astype(np.float64, copy=True)
    width = 1
    while width < depth:
        for start in range(0, depth, 2 * width):
            left = rotated[:, start:start + width].copy()
            right = rotated[:, start + width:start + 2 * width].copy()
            rotated[:, start:start + width] = left + right
            rotated[:, start + width:start + 2 * width] = left - right
        width *= 2
    return (rotated / math.sqrt(depth)).astype(np.float32)


def preprocess_qk(
    q: np.ndarray, k: np.ndarray, preprocessing: str,
) -> tuple[np.ndarray, np.ndarray]:
    """Apply one softmax-invariant Q/K preprocessing rule."""
    if preprocessing not in PREPROCESSING_TYPES:
        raise ValueError(f"unknown preprocessing rule: {preprocessing}")
    q_work = np.asarray(q, dtype=np.float32)
    k_work = np.asarray(k, dtype=np.float32)
    if preprocessing.startswith("k-center"):
        k_work = (k_work.astype(np.float64)
                  - np.mean(k_work.astype(np.float64), axis=0)).astype(np.float32)
    if preprocessing.endswith("hadamard"):
        q_work = hadamard_rotate(q_work)
        k_work = hadamard_rotate(k_work)
    return q_work, k_work


def softmax(scores: np.ndarray) -> np.ndarray:
    shifted = scores.astype(np.float64) - np.max(scores, axis=1, keepdims=True)
    exponentials = np.exp(shifted)
    return exponentials / np.sum(exponentials, axis=1, keepdims=True)


def evaluate(
    q: np.ndarray, k: np.ndarray, block_size: int = 64, scale_type: str = "FP32",
    output_format: str = "FP32", quantizer=None,
) -> dict[str, float | int | str]:
    if q.ndim != 2 or k.shape != q.shape or q.shape[1] == 0:
        raise ValueError("q and k must have the same nonempty T x D shape")
    q = np.asarray(q, dtype=np.float32)
    k = np.asarray(k, dtype=np.float32)
    if not np.isfinite(q).all() or not np.isfinite(k).all():
        raise ValueError("inputs must be finite")
    if block_size > q.shape[1]:
        raise ValueError("block_size must not exceed D_HEAD")

    quantize = quantizer or quantize_blocks
    q_half, q_scale, q_clips = quantize(q, block_size, scale_type)
    k_half, k_scale, k_clips = quantize(k, block_size, scale_type)
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
    fp4_scores = quantize_output(fp4_scores, output_format)

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
    reference_top = np.argsort(
        reference_probability, axis=1, kind="stable"
    )[:, -top_k:]
    fp4_top = np.argsort(fp4_probability, axis=1, kind="stable")[:, -top_k:]
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


def evaluate_preprocessing(
    q: np.ndarray, k: np.ndarray, preprocessing: str,
    block_size: int = 16, scale_type: str = "E4M3-search",
) -> dict[str, float | int | str]:
    """Evaluate quantization after an exact softmax-invariant transform.

    K centering subtracts one constant from every score in a query row. Raw
    score errors are therefore measured after removing each row mean. Softmax
    metrics are always measured against the original, untransformed logits.
    """
    q = np.asarray(q, dtype=np.float32)
    k = np.asarray(k, dtype=np.float32)
    q_work, k_work = preprocess_qk(q, k, preprocessing)
    q_half, q_scale, q_clips = quantize_blocks_study(
        q_work, block_size, scale_type
    )
    k_half, k_scale, k_clips = quantize_blocks_study(
        k_work, block_size, scale_type
    )
    fp4_scores = np.zeros((q.shape[0], q.shape[0]), dtype=np.float32)
    for block in range(q_scale.shape[1]):
        start = block * block_size
        stop = min(start + block_size, q.shape[1])
        exact_quarters = q_half[:, start:stop] @ k_half[:, start:stop].T
        block_scores = exact_quarters.astype(np.float32) * np.float32(.25)
        block_scores *= q_scale[:, block, None]
        block_scores *= k_scale[None, :, block]
        fp4_scores += block_scores

    reference_scores = q @ k.T
    transformed_scores = q_work @ k_work.T
    divisor = math.sqrt(q.shape[1])
    reference_probability = softmax(reference_scores / divisor)
    transformed_probability = softmax(transformed_scores / divisor)
    fp4_probability = softmax(fp4_scores / divisor)
    tiny = np.finfo(np.float64).tiny
    kl_rows = np.sum(
        reference_probability
        * (np.log(np.maximum(reference_probability, tiny))
           - np.log(np.maximum(fp4_probability, tiny))), axis=1,
    )
    tv_rows = 0.5 * np.sum(
        np.abs(reference_probability - fp4_probability), axis=1
    )
    top1 = np.argmax(reference_probability, axis=1) == np.argmax(
        fp4_probability, axis=1
    )
    top_k = min(5, q.shape[0])
    reference_top = np.argsort(
        reference_probability, axis=1, kind="stable"
    )[:, -top_k:]
    fp4_top = np.argsort(fp4_probability, axis=1, kind="stable")[:, -top_k:]
    overlap = np.array([
        len(set(reference_top[row]) & set(fp4_top[row])) / top_k
        for row in range(q.shape[0])
    ])
    reference_aligned = reference_scores.astype(np.float64)
    reference_aligned -= np.mean(reference_aligned, axis=1, keepdims=True)
    fp4_aligned = fp4_scores.astype(np.float64)
    fp4_aligned -= np.mean(fp4_aligned, axis=1, keepdims=True)
    difference = fp4_aligned - reference_aligned
    return {
        "T": q.shape[0], "D_HEAD": q.shape[1],
        "block_size": block_size, "scale_type": scale_type,
        "preprocessing": preprocessing,
        "mean_kl_divergence": float(np.mean(kl_rows)),
        "mean_total_variation": float(np.mean(tv_rows)),
        "top1_agreement": float(np.mean(top1)),
        "top5_index_agreement": float(np.mean(overlap)),
        "row_centered_mean_abs_error": float(np.mean(np.abs(difference))),
        "row_centered_relative_frobenius_error": float(
            np.linalg.norm(difference)
            / max(np.linalg.norm(reference_aligned), 1e-30)
        ),
        "exact_softmax_invariance_max_abs": float(np.max(
            np.abs(reference_probability - transformed_probability)
        )),
        "clipped_input_fraction": float(
            (q_clips + k_clips) / (q.size + k.size)
        ),
    }


def evaluate_output_format(
    q: np.ndarray, k: np.ndarray, block_size: int, scale_type: str,
    output_format: str,
) -> dict[str, float | int | str]:
    """Label an evaluation with its output format without changing the
    committed scale-format record shape."""
    row = evaluate(q, k, block_size, scale_type, output_format)
    scores_per_beat = {"FP32": 2, "FP16": 4, "BF16": 4}[output_format]
    return {
        **row,
        "output_format": output_format,
        "output_bits_per_score": 32 if output_format == "FP32" else 16,
        "scores_per_64_bit_beat": scores_per_beat,
    }


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--npz", type=Path, help="Pinned Q/K capture with q and k arrays")
    parser.add_argument("--sizes", type=int, nargs="+", default=[4, 16, 64, 128, 512])
    parser.add_argument("--depth", type=int, default=64)
    parser.add_argument("--seed", type=int, default=510)
    parser.add_argument(
        "--output-formats", action="store_true",
        help="sweep FP32, FP16, and BF16 output scores at one block size",
    )
    parser.add_argument("--block-size", type=int, default=16)
    parser.add_argument(
        "--scale-study", action="store_true",
        help="compare FP32, E4M3, and E8M0 block-scale rules at one block size",
    )
    parser.add_argument(
        "--preprocessing-study", action="store_true",
        help="compare K centering and Hadamard rotation at one block size",
    )
    parser.add_argument(
        "--captures", type=Path, nargs="+",
        help="multiple pinned Q/K captures for the preprocessing study",
    )
    args = parser.parse_args()
    if args.captures:
        matrices = []
        sources = []
        for path in args.captures:
            with np.load(path) as capture:
                matrices.append((capture["q"], capture["k"]))
            sources.append({"source": str(path),
                            "sha256": hashlib.sha256(path.read_bytes()).hexdigest()})
        source = {"captures": sources}
    elif args.npz:
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
    if args.preprocessing_study:
        if not args.captures and not args.npz:
            raise ValueError("--preprocessing-study requires --npz or --captures")
        metrics = [
            {
                **evaluate_preprocessing(
                    q, k, preprocessing, args.block_size, scale_type
                ),
                "source": str(args.captures[index]) if args.captures else str(args.npz),
            }
            for index, (q, k) in enumerate(matrices)
            for scale_type in ("FP32", "E4M3-search")
            for preprocessing in PREPROCESSING_TYPES
        ]
    elif args.scale_study:
        metrics = [
            evaluate_scale_study(q, k, args.block_size, scale_type)
            for q, k in matrices
            for scale_type in SCALE_STUDY_TYPES
        ]
    elif args.output_formats:
        metrics = [
            evaluate_output_format(q, k, args.block_size, "FP32", output_format)
            for q, k in matrices
            for output_format in OUTPUT_FORMATS
        ]
    else:
        metrics = [
            evaluate(q, k, block_size, scale_type)
            for q, k in matrices
            for block_size in BLOCK_SIZES if block_size <= q.shape[1]
            for scale_type in SCALE_TYPES
        ]
    print(json.dumps({**source, "numpy_version": np.__version__, "metrics": metrics}, indent=2))


if __name__ == "__main__":
    main()
