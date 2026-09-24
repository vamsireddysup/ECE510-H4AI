# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Small dependency-free model matching the current FP4 data path."""

from __future__ import annotations

import struct
from collections.abc import Sequence

FP4_MAGNITUDES = (0.0, 0.5, 1.0, 1.5, 2.0, 3.0, 4.0, 6.0)


def fp4_decode(code: int) -> float:
    """Decode one 4-bit E2M1 value used by the RTL lookup table."""
    if not 0 <= code <= 0xF:
        raise ValueError(f"FP4 code must be in [0, 15], got {code}")
    magnitude = FP4_MAGNITUDES[code & 0x7]
    return -magnitude if code & 0x8 else magnitude


def fp4_encode(value: float) -> int:
    """Round a real value to the nearest supported FP4 magnitude."""
    sign = 0x8 if value < 0.0 else 0
    magnitude = abs(value)
    index = min(
        range(len(FP4_MAGNITUDES)),
        key=lambda item: (abs(FP4_MAGNITUDES[item] - magnitude), item),
    )
    return sign | index


def fp32_bits(value: float) -> int:
    """Return the IEEE-754 binary32 representation of a Python float."""
    return struct.unpack(">I", struct.pack(">f", value))[0]


def fp4_product_bits(a: int, b: int) -> int:
    """Return the FP32 bits produced by multiplying two FP4 values."""
    return fp32_bits(fp4_decode(a) * fp4_decode(b))


def qkt(
    q_codes: Sequence[Sequence[int]],
    k_codes: Sequence[Sequence[int]],
    q_scales: Sequence[float] | Sequence[Sequence[float]] | None = None,
    k_scales: Sequence[float] | Sequence[Sequence[float]] | None = None,
    block_size: int | None = None,
) -> list[list[float]]:
    """Compute dequantized QK^T with scales blocked along the reduction axis.

    Flat scale vectors retain the original one-scale-per-row interface and
    require one block spanning the complete head dimension. Nested scale
    matrices contain one scale per row and reduction block.
    """
    if not q_codes or not k_codes:
        raise ValueError("Q and K must not be empty")
    depth = len(q_codes[0])
    if depth == 0:
        raise ValueError("Q and K rows must not be empty")
    if any(len(row) != depth for row in q_codes):
        raise ValueError("Q rows must have equal length")
    if any(len(row) != depth for row in k_codes):
        raise ValueError("Q and K must use the same head dimension")

    if block_size is None:
        block_size = depth
    if block_size <= 0 or block_size > depth:
        raise ValueError("block_size must be in [1, D_HEAD]")
    block_count = (depth + block_size - 1) // block_size

    def normalize_scales(
        scales: Sequence[float] | Sequence[Sequence[float]] | None,
        row_count: int,
    ) -> list[list[float]]:
        if scales is None:
            return [[1.0] * block_count for _ in range(row_count)]
        values = list(scales)
        if len(values) != row_count:
            raise ValueError("Scale count must match the number of matrix rows")
        if values and isinstance(values[0], Sequence):
            matrix = [list(row) for row in values]  # type: ignore[arg-type]
            if any(len(row) != block_count for row in matrix):
                raise ValueError("Each scale row must match the reduction block count")
            return matrix
        if block_count != 1:
            raise ValueError("Flat scales are valid only for one reduction block")
        return [[float(value)] for value in values]  # type: ignore[arg-type]

    q_scale_values = normalize_scales(q_scales, len(q_codes))
    k_scale_values = normalize_scales(k_scales, len(k_codes))

    result: list[list[float]] = []
    for q_row, q_row_scales in zip(q_codes, q_scale_values, strict=True):
        output_row = []
        for k_row, k_row_scales in zip(k_codes, k_scale_values, strict=True):
            score = 0.0
            for block in range(block_count):
                start = block * block_size
                stop = min(start + block_size, depth)
                dot = sum(
                    fp4_decode(q_row[index]) * fp4_decode(k_row[index])
                    for index in range(start, stop)
                )
                score += dot * q_row_scales[block] * k_row_scales[block]
            output_row.append(score)
        result.append(output_row)
    return result
