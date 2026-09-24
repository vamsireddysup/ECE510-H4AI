# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
from __future__ import annotations

import numpy as np
import pytest

from scripts.eval_precision import evaluate, power_of_two_scale, quantize_blocks


def test_e8m0_rounding_rules() -> None:
    ideal = np.array([0.3, 0.5, 0.8], dtype=np.float32)
    np.testing.assert_array_equal(
        power_of_two_scale(ideal, "E8M0-floor"), [0.25, 0.5, 0.5]
    )
    np.testing.assert_array_equal(
        power_of_two_scale(ideal, "E8M0-nearest"), [0.25, 0.5, 1.0]
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
