# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
from __future__ import annotations

import re
from pathlib import Path

import pytest

from model.qkt_model import fp4_decode, fp4_encode, fp4_product_bits, qkt

REPO_ROOT = Path(__file__).resolve().parents[2]
LUT_PATH = REPO_ROOT / "archive/superseded-rtl/fp4_mul_lut.sv"


def read_rtl_lut() -> dict[int, int]:
    pattern = re.compile(
        r"8'h(?P<index>[0-9A-F]{2}): result = 32'h(?P<result>[0-9A-F]{8});"
    )
    entries = {
        int(match.group("index"), 16): int(match.group("result"), 16)
        for match in pattern.finditer(LUT_PATH.read_text())
    }
    assert len(entries) == 256
    return entries


def test_all_fp4_products_match_rtl_lut() -> None:
    rtl_lut = read_rtl_lut()
    for a in range(16):
        for b in range(16):
            assert fp4_product_bits(a, b) == rtl_lut[(a << 4) | b]


@pytest.mark.parametrize("code", range(8))
def test_positive_values_round_trip(code: int) -> None:
    assert fp4_encode(fp4_decode(code)) == code


@pytest.mark.parametrize("code", range(9, 16))
def test_negative_values_round_trip(code: int) -> None:
    assert fp4_encode(fp4_decode(code)) == code


def test_reference_matrix_matches_m4_case() -> None:
    q_values = [
        [1.0, 0.0, 1.0, 0.0],
        [0.0, 1.0, 0.0, 1.0],
        [1.0, 1.0, 0.0, 0.0],
        [0.0, 0.0, 1.0, 1.0],
    ]
    codes = [[fp4_encode(value) for value in row] for row in q_values]
    assert qkt(codes, codes) == [
        [2.0, 0.0, 1.0, 1.0],
        [0.0, 2.0, 1.0, 1.0],
        [1.0, 1.0, 2.0, 0.0],
        [1.0, 1.0, 0.0, 2.0],
    ]


def test_scales_are_applied_by_output_row_and_column() -> None:
    q_codes = [[fp4_encode(1.0)], [fp4_encode(2.0)]]
    k_codes = [[fp4_encode(3.0)], [fp4_encode(4.0)]]
    assert qkt(q_codes, k_codes, [0.5, 2.0], [4.0, 0.25]) == [
        [6.0, 0.5],
        [48.0, 4.0],
    ]


def test_invalid_shapes_are_rejected() -> None:
    with pytest.raises(ValueError):
        qkt([], [])
    with pytest.raises(ValueError):
        qkt([[1, 2]], [[1]])
    with pytest.raises(ValueError):
        qkt([[1]], [[1]], q_scales=[1.0, 2.0])
