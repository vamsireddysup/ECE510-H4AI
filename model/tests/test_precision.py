# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
from __future__ import annotations

import json
import hashlib
from pathlib import Path

import numpy as np
import pytest

from scripts.eval_precision import (
    BLOCK_SIZES,
    EXPONENT_BOUND_TAUS,
    SCALE_TYPES,
    evaluate,
    evaluate_preprocessing,
    evaluate_element_formats,
    evaluate_accumulation_order,
    evaluate_exponent_bound,
    hadamard_rotate,
    preprocess_qk,
    quantize_element_blocks,
    reduce_block_scores,
    power_of_two_scale,
    quantize_blocks,
    render_t512_table,
)
from model.qkt_model import fp4_encode, qkt

REPO_ROOT = Path(__file__).resolve().parents[2]
PRECISION_JSON = REPO_ROOT / "docs/results/data/synthetic-precision-sweep.json"
PRECISION_MARKDOWN = REPO_ROOT / "docs/results/precision.md"
ACTIVATION_CAPTURE = REPO_ROOT / "docs/results/data/bert-tiny-layer0-head0.npz"
ACTIVATION_JSON = REPO_ROOT / "docs/results/data/bert-tiny-layer0-head0-precision.json"
PREPROCESSING_JSON = REPO_ROOT / "docs/results/data/preprocessing-study.json"
ELEMENT_FORMAT_JSON = REPO_ROOT / "docs/results/data/element-format-study.json"
ACCUMULATION_JSON = REPO_ROOT / "docs/results/data/accumulation-order-study.json"
EXPONENT_BOUND_JSON = REPO_ROOT / "docs/results/data/exponent-bound-study.json"


def test_e8m0_rounding_rules() -> None:
    ideal = np.array([0.3, 0.5, 0.8], dtype=np.float32)
    np.testing.assert_array_equal(
        power_of_two_scale(ideal, "E8M0-floor"), [0.25, 0.5, 0.5]
    )
    np.testing.assert_array_equal(
        power_of_two_scale(ideal, "E8M0-nearest"), [0.25, 0.5, 1.0]
    )
    np.testing.assert_array_equal(
        power_of_two_scale(ideal, "E8M0-ceil"), [0.5, 0.5, 1.0]
    )


def test_block_quantizer_handles_partial_and_zero_blocks() -> None:
    values = np.array([[0, 0, 0, 1, -6]], dtype=np.float32)
    half, scales, clips = quantize_blocks(values, 3, "FP32")
    np.testing.assert_array_equal(half, [[0, 0, 0, 2, -12]])
    np.testing.assert_array_equal(scales, [[1.0, 1.0]])
    assert clips == 0


def test_floor_dequantization_scale_can_clip() -> None:
    _, _, clips = quantize_blocks(
        np.array([[5.0, 1.0]], dtype=np.float32), 2, "E8M0-floor"
    )
    assert clips == 1


def test_ceil_dequantization_scale_does_not_clip() -> None:
    _, _, clips = quantize_blocks(
        np.array([[5.0, 1.0]], dtype=np.float32), 2, "E8M0-ceil"
    )
    assert clips == 0


def test_softmax_invariant_preprocessing() -> None:
    generator = np.random.default_rng(19)
    q = generator.standard_normal((7, 8), dtype=np.float32)
    k = generator.standard_normal((7, 8), dtype=np.float32)
    reference = q @ k.T
    reference_probability = np.exp(reference - np.max(reference, axis=1, keepdims=True))
    reference_probability /= np.sum(reference_probability, axis=1, keepdims=True)
    for preprocessing in ("k-center", "hadamard", "k-center+hadamard"):
        q_work, k_work = preprocess_qk(q, k, preprocessing)
        scores = q_work @ k_work.T
        probability = np.exp(scores - np.max(scores, axis=1, keepdims=True))
        probability /= np.sum(probability, axis=1, keepdims=True)
        np.testing.assert_allclose(probability, reference_probability, rtol=2e-6, atol=2e-7)


def test_hadamard_rotation_requires_power_of_two_depth() -> None:
    with pytest.raises(ValueError, match="power-of-two"):
        hadamard_rotate(np.ones((2, 6), dtype=np.float32))


def test_preprocessing_record_uses_row_shift_aligned_error() -> None:
    q = np.eye(4, dtype=np.float32)
    k = np.arange(16, dtype=np.float32).reshape(4, 4)
    row = evaluate_preprocessing(q, k, "k-center", 4, "FP32")
    assert row["exact_softmax_invariance_max_abs"] < 1e-6
    assert "row_centered_relative_frobenius_error" in row


def test_preprocessing_study_matches_committed_json() -> None:
    """Keep every preprocessing row tied to the four pinned captures."""
    committed = json.loads(PREPROCESSING_JSON.read_text())
    expected = committed["metrics"]
    regenerated = []
    for source in committed["captures"]:
        path = REPO_ROOT / source["source"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == source["sha256"]
        with np.load(path, allow_pickle=False) as capture:
            q, k = capture["q"], capture["k"]
        for scale_type in ("FP32", "E4M3-search"):
            for preprocessing in ("none", "k-center", "hadamard", "k-center+hadamard"):
                regenerated.append({
                    **evaluate_preprocessing(q, k, preprocessing, 16, scale_type),
                    "source": source["source"],
                })
    assert len(regenerated) == len(expected)
    for actual, recorded in zip(regenerated, expected, strict=True):
        assert actual.keys() == recorded.keys()
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]


def test_adaptive_element_format_minimizes_block_reconstruction() -> None:
    values = np.array([[0.1, 0.2, 0.3, 6.0], [-5.0, -1.0, 1.0, 5.0]], dtype=np.float32)
    results = {}
    for element_format in ("FP4", "INT4", "adaptive"):
        code, scale, unit, _, _ = quantize_element_blocks(values, 4, element_format)
        reconstruction = code * unit[:, 0, None] * scale[:, 0, None]
        results[element_format] = np.mean((reconstruction - values) ** 2, axis=1)
    assert np.all(results["adaptive"] <= results["FP4"])
    assert np.all(results["adaptive"] <= results["INT4"])


def test_mixed_element_accumulator_bound() -> None:
    q = np.array([[6.0] * 16, [-8.0] * 16], dtype=np.float32)
    row = evaluate_element_formats(q, q, "adaptive", 16)
    assert row["accumulator_bits_bs16"] == 13


def test_element_format_study_matches_committed_json() -> None:
    """Regenerate fixed and adaptive format rows from pinned captures."""
    committed = json.loads(ELEMENT_FORMAT_JSON.read_text())
    regenerated = []
    for source in committed["captures"]:
        path = REPO_ROOT / source["source"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == source["sha256"]
        with np.load(path, allow_pickle=False) as capture:
            q, k = capture["q"], capture["k"]
        for element_format in ("FP4", "INT4", "adaptive"):
            regenerated.append({
                **evaluate_element_formats(q, k, element_format, 16),
                "source": source["source"],
            })
    for actual, recorded in zip(regenerated, committed["metrics"], strict=True):
        assert actual.keys() == recorded.keys()
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]


def test_tree_and_sequential_reduction_are_distinct() -> None:
    blocks = [
        np.array([[1e20]], dtype=np.float32),
        np.array([[1.0]], dtype=np.float32),
        np.array([[-1e20]], dtype=np.float32),
        np.array([[1.0]], dtype=np.float32),
    ]
    assert reduce_block_scores(blocks, "sequential")[0, 0] == 1.0
    assert reduce_block_scores(blocks, "tree")[0, 0] == 0.0


def test_accumulation_order_study_matches_committed_json() -> None:
    """Regenerate sequential and tree reductions from pinned captures."""
    committed = json.loads(ACCUMULATION_JSON.read_text())
    regenerated = []
    for source in committed["captures"]:
        path = REPO_ROOT / source["source"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == source["sha256"]
        with np.load(path, allow_pickle=False) as capture:
            q, k = capture["q"], capture["k"]
        for scale_type in ("FP32", "E4M3-search"):
            for order in ("sequential", "tree"):
                regenerated.append({
                    **evaluate_accumulation_order(q, k, order, 16, scale_type),
                    "source": source["source"],
                })
    for actual, recorded in zip(regenerated, committed["metrics"], strict=True):
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]


def test_exponent_bound_preserves_the_row_maximum() -> None:
    """A safe threshold must retain the unpruned maximum in every row."""
    q = np.array([[1, 2, -1, 0], [-2, 1, 0.5, 3]], dtype=np.float32)
    row = evaluate_exponent_bound(q, q, tau=0.0, block_size=4, tile_size=1)
    assert row["score_skip_top1_agreement_to_unpruned"] == 1.0
    assert row["safe_score_fraction"] <= row["oracle_score_fraction"]


def test_exponent_bound_study_matches_committed_json() -> None:
    """Regenerate every safe-bound row from the four pinned captures."""
    committed = json.loads(EXPONENT_BOUND_JSON.read_text())
    regenerated = []
    for source in committed["captures"]:
        path = REPO_ROOT / source["source"]
        assert hashlib.sha256(path.read_bytes()).hexdigest() == source["sha256"]
        with np.load(path, allow_pickle=False) as capture:
            q, k = capture["q"], capture["k"]
        for tau in EXPONENT_BOUND_TAUS:
            regenerated.append({
                **evaluate_exponent_bound(q, k, tau, 16),
                "source": source["source"],
            })
    for actual, recorded in zip(regenerated, committed["metrics"], strict=True):
        assert actual.keys() == recorded.keys()
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]


def test_reference_accepts_numpy_block_scale_rows() -> None:
    codes = [[fp4_encode(1.0)] * 4]
    scales = np.array([[2.0, 3.0]], dtype=np.float32)
    assert qkt(codes, codes, scales, scales, block_size=2) == [[26.0]]


def test_legacy_evaluation_point_is_reproducible() -> None:
    generator = np.random.default_rng(510)
    q = k = None
    for size in [4, 16, 64, 128, 512]:
        q = generator.standard_normal((size, 64), dtype=np.float32)
        k = generator.standard_normal((size, 64), dtype=np.float32)
    result = evaluate(q, k, 64, "FP32")
    assert result["relative_frobenius_error"] == pytest.approx(0.1490, abs=5e-5)
    assert result["fp32_adds_per_score"] == 0
    assert result["scale_bytes_per_q_or_k_element"] == 0.0625


def test_t512_sweep_matches_committed_json() -> None:
    """Catch result drift while allowing physical reduction-order variation.

    NumPy and SIMD implementations can change float64 reductions below the
    ninth significant digit. A 1e-6 relative tolerance admits that numerical
    noise while still rejecting table errors at the observed 1e-3 scale.
    """
    committed = json.loads(PRECISION_JSON.read_text())
    generator = np.random.default_rng(committed["seed"])
    q = k = None
    for size in [4, 16, 64, 128, 512]:
        q = generator.standard_normal((size, 64), dtype=np.float32)
        k = generator.standard_normal((size, 64), dtype=np.float32)
    regenerated = [
        evaluate(q, k, block_size, scale_type)
        for block_size in BLOCK_SIZES
        for scale_type in SCALE_TYPES
    ]
    expected = [row for row in committed["metrics"] if row["T"] == 512]
    assert len(regenerated) == len(expected)
    for actual, recorded in zip(regenerated, expected, strict=True):
        assert actual.keys() == recorded.keys()
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]
    assert render_t512_table(expected) in PRECISION_MARKDOWN.read_text()


def test_real_activation_fp32_sweep_matches_committed_json() -> None:
    """Keep the pinned capture and the format decision machine-checkable."""
    committed = json.loads(ACTIVATION_JSON.read_text())
    assert hashlib.sha256(ACTIVATION_CAPTURE.read_bytes()).hexdigest() == committed["sha256"]
    with np.load(ACTIVATION_CAPTURE, allow_pickle=False) as capture:
        q, k = capture["q"], capture["k"]
    expected = [
        row for row in committed["metrics"] if row["scale_type"] == "FP32"
    ]
    regenerated = [evaluate(q, k, block_size, "FP32") for block_size in BLOCK_SIZES]
    for actual, recorded in zip(regenerated, expected, strict=True):
        for key in actual:
            if isinstance(actual[key], float):
                assert actual[key] == pytest.approx(recorded[key], rel=1e-6, abs=1e-12)
            else:
                assert actual[key] == recorded[key]
