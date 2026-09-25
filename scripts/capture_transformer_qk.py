#!/usr/bin/env python3
# SPDX-License-Identifier: Apache-2.0
# Copyright 2026 Vamsidhar Reddy Eraganeni
"""Capture one pretrained transformer's Q/K head as a deterministic NPZ."""
from __future__ import annotations

import argparse
import hashlib
import io
from pathlib import Path
import zipfile

import numpy as np
import torch
from transformers import AutoModel, AutoTokenizer

MODEL = "google/bert_uncased_L-2_H-128_A-2"
REVISION = "30b0a37ccaaa32f332884b96992754e246e48c5f"


def write_npz(path: Path, arrays: dict[str, np.ndarray]) -> None:
    """Write stable NPZ bytes so the reviewed capture has a reproducible hash."""
    path.parent.mkdir(parents=True, exist_ok=True)
    with zipfile.ZipFile(path, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        for name in sorted(arrays):
            payload = io.BytesIO()
            np.lib.format.write_array(payload, np.asarray(arrays[name]), allow_pickle=False)
            entry = zipfile.ZipInfo(f"{name}.npy", date_time=(1980, 1, 1, 0, 0, 0))
            entry.compress_type = zipfile.ZIP_DEFLATED
            entry.external_attr = 0o100644 << 16
            archive.writestr(entry, payload.getvalue())


def main() -> None:
    root = Path(__file__).resolve().parents[1]
    parser = argparse.ArgumentParser()
    parser.add_argument("output", type=Path)
    parser.add_argument(
        "--text", type=Path, default=root / "model/fixtures/alice-chapter-1.txt"
    )
    parser.add_argument("--layer", type=int, default=0)
    parser.add_argument("--head", type=int, default=0)
    args = parser.parse_args()

    torch.set_num_threads(1)
    text_bytes = args.text.read_bytes()
    text = text_bytes.decode("utf-8")
    tokenizer = AutoTokenizer.from_pretrained(MODEL, revision=REVISION)
    model = AutoModel.from_pretrained(MODEL, revision=REVISION).eval()
    encoded = tokenizer(
        text, return_tensors="pt", truncation=True, max_length=512,
        add_special_tokens=True,
    )
    if encoded["input_ids"].shape != (1, 512):
        raise ValueError("fixture must produce exactly 512 tokens")
    attention = model.encoder.layer[args.layer].attention.self
    with torch.no_grad():
        hidden = model.embeddings(
            input_ids=encoded["input_ids"],
            token_type_ids=encoded.get("token_type_ids"),
        )
        query = attention.query(hidden)
        key = attention.key(hidden)
    head_count = model.config.num_attention_heads
    head_width = model.config.hidden_size // head_count
    if not 0 <= args.head < head_count or head_width != 64:
        raise ValueError("capture requires an in-range 64-element attention head")
    q = query.reshape(512, head_count, head_width)[:, args.head, :]
    k = key.reshape(512, head_count, head_width)[:, args.head, :]
    arrays = {
        "q": q.cpu().numpy().astype("<f4"),
        "k": k.cpu().numpy().astype("<f4"),
        "input_ids": encoded["input_ids"].cpu().numpy().astype("<i8"),
        "attention_mask": encoded["attention_mask"].cpu().numpy().astype("u1"),
        "model": np.asarray(MODEL),
        "revision": np.asarray(REVISION),
        "layer": np.asarray(args.layer, dtype="<u4"),
        "head": np.asarray(args.head, dtype="<u4"),
        "text_sha256": np.asarray(hashlib.sha256(text_bytes).hexdigest()),
        "torch_version": np.asarray(torch.__version__),
    }
    write_npz(args.output, arrays)
    print(f"capture={args.output}")
    print(f"sha256={hashlib.sha256(args.output.read_bytes()).hexdigest()}")
    print(f"q_shape={q.shape} k_shape={k.shape}")


if __name__ == "__main__":
    main()
