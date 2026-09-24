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
    q_scales: Sequence[float] | None = None,
    k_scales: Sequence[float] | None = None,
) -> list[list[float]]:
    """Compute dequantized QK^T for FP4 code matrices."""
    if not q_codes or not k_codes:
        raise ValueError("Q and K must not be empty")
    depth = len(q_codes[0])
    if depth == 0:
        raise ValueError("Q and K rows must not be empty")
    if any(len(row) != depth for row in q_codes):
        raise ValueError("Q rows must have equal length")
    if any(len(row) != depth for row in k_codes):
        raise ValueError("Q and K must use the same head dimension")

    q_scale_values = list(q_scales) if q_scales is not None else [1.0] * len(q_codes)
    k_scale_values = list(k_scales) if k_scales is not None else [1.0] * len(k_codes)
    if len(q_scale_values) != len(q_codes) or len(k_scale_values) != len(k_codes):
        raise ValueError("Scale count must match the number of matrix rows")

    result: list[list[float]] = []
    for q_row, q_scale in zip(q_codes, q_scale_values, strict=True):
        output_row = []
        for k_row, k_scale in zip(k_codes, k_scale_values, strict=True):
            dot = sum(
                fp4_decode(q_value) * fp4_decode(k_value)
                for q_value, k_value in zip(q_row, k_row, strict=True)
            )
            output_row.append(dot * q_scale * k_scale)
        result.append(output_row)
    return result
