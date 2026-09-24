#!/usr/bin/env python3
"""
gen_golden.py -- FP4 QK^T golden reference generator with microscaling

Generates:
  1. FP32 Q and K matrices (random, bounded for FP4 range)
  2. FP4 E2M1 encoded Q and K with per-row/col microscaling
  3. Scale factors S_Q (per Q row) and S_K (per K col)
  4. Expected QK^T output after dequantization
  5. Error analysis: MAE and max error vs FP32 reference

FP4 E2M1 representable values:
  Positive: 0.0, 0.5, 1.0, 1.5, 2.0, 3.0, 4.0, 6.0
  Negative: -0.0, -0.5, -1.0, -1.5, -2.0, -3.0, -4.0, -6.0

Microscaling:
  S_Q[i] = max(|Q[i,:]|) / 6.0
  S_K[j] = max(|K[j,:]|) / 6.0
  Q_fp4[i,:] = round_to_fp4(Q[i,:] / S_Q[i])
  K_fp4[j,:] = round_to_fp4(K[j,:] / S_K[j])
  C_raw[i,j] = dot(Q_fp4[i,:], K_fp4[j,:])   -- in FP32 accumulate
  C_deq[i,j] = C_raw[i,j] * S_Q[i] * S_K[j]  -- dequantized

Author: Vamsidhar Reddy Eraganeni
Course: ECE 510 Spring 2026, Portland State University
"""

import numpy as np
import struct
import os

# ---------------------------------------------------------------------------
# FP4 E2M1 representable values
# ---------------------------------------------------------------------------
FP4_POS = [0.0, 0.5, 1.0, 1.5, 2.0, 3.0, 4.0, 6.0]
FP4_NEG = [-0.0, -0.5, -1.0, -1.5, -2.0, -3.0, -4.0, -6.0]
FP4_ALL = FP4_POS + FP4_NEG
FP4_MAX = 6.0

def round_to_fp4(x):
    """Round a float to the nearest FP4 E2M1 representable value."""
    candidates = np.array(FP4_ALL)
    idx = np.argmin(np.abs(candidates - x))
    return candidates[idx]

def quantize_to_fp4(arr):
    """Quantize a numpy array element-wise to FP4 representable values."""
    return np.vectorize(round_to_fp4)(arr)

def encode_fp4(val):
    """Encode a FP4 representable float to 4-bit integer (0-15)."""
    fp4_map = {
         0.0: 0x0,  0.5: 0x1,  1.0: 0x2,  1.5: 0x3,
         2.0: 0x4,  3.0: 0x5,  4.0: 0x6,  6.0: 0x7,
        -0.0: 0x8, -0.5: 0x9, -1.0: 0xA, -1.5: 0xB,
        -2.0: 0xC, -3.0: 0xD, -4.0: 0xE, -6.0: 0xF
    }
    # Handle -0.0 vs 0.0
    if val == 0.0:
        return 0x0
    return fp4_map.get(val, 0x0)

def float_to_fp32_hex(f):
    """Convert float to FP32 IEEE 754 hex string."""
    packed = struct.pack('>f', float(f))
    return '0x' + packed.hex().upper()

# ---------------------------------------------------------------------------
# Parameters
# ---------------------------------------------------------------------------
np.random.seed(42)
T       = 16    # sequence length for golden reference (one tile)
D_HEAD  = 4     # head dimension (small for quick verification)
SIZE    = 4     # systolic array size for test

print(f"Generating FP4 golden reference: T={T}, D_HEAD={D_HEAD}")
print(f"FP4 E2M1 range: [{-FP4_MAX}, {FP4_MAX}]")
print()

# ---------------------------------------------------------------------------
# Step 1: Generate FP32 Q and K matrices
# Use values in range [-4, 4] to allow microscaling headroom
# ---------------------------------------------------------------------------
Q_fp32 = np.random.uniform(-4.0, 4.0, (SIZE, D_HEAD)).astype(np.float32)
K_fp32 = np.random.uniform(-4.0, 4.0, (SIZE, D_HEAD)).astype(np.float32)

print("Q matrix (FP32):")
print(np.round(Q_fp32, 3))
print()
print("K matrix (FP32):")
print(np.round(K_fp32, 3))
print()

# ---------------------------------------------------------------------------
# Step 2: FP32 reference -- ground truth
# C_ref[i,j] = Q[i,:] dot K[j,:]  (QK^T where K rows are K^T columns)
# ---------------------------------------------------------------------------
C_ref = Q_fp32 @ K_fp32.T  # [SIZE x SIZE]
print("C_ref (FP32 reference QK^T):")
print(np.round(C_ref, 4))
print()

# ---------------------------------------------------------------------------
# Step 3: Microscaling -- compute scale factors
# ---------------------------------------------------------------------------
S_Q = np.max(np.abs(Q_fp32), axis=1) / FP4_MAX  # [SIZE] per row
S_K = np.max(np.abs(K_fp32), axis=1) / FP4_MAX  # [SIZE] per col (K row)

# Avoid division by zero
S_Q = np.where(S_Q == 0, 1.0, S_Q)
S_K = np.where(S_K == 0, 1.0, S_K)

print("Scale factors S_Q (per Q row):")
print(np.round(S_Q, 6))
print()
print("Scale factors S_K (per K row = K^T col):")
print(np.round(S_K, 6))
print()

# ---------------------------------------------------------------------------
# Step 4: Quantize Q and K to FP4
# ---------------------------------------------------------------------------
Q_scaled = Q_fp32 / S_Q[:, np.newaxis]  # normalize each row
K_scaled = K_fp32 / S_K[:, np.newaxis]  # normalize each row

Q_fp4_vals = quantize_to_fp4(Q_scaled)  # FP4 representable floats
K_fp4_vals = quantize_to_fp4(K_scaled)

print("Q_fp4 (quantized to FP4 representable values):")
print(Q_fp4_vals)
print()
print("K_fp4 (quantized to FP4 representable values):")
print(K_fp4_vals)
print()

# Quantization error on inputs
Q_reconstructed = Q_fp4_vals * S_Q[:, np.newaxis]
K_reconstructed = K_fp4_vals * S_K[:, np.newaxis]

Q_quant_err = np.abs(Q_fp32 - Q_reconstructed)
K_quant_err = np.abs(K_fp32 - K_reconstructed)
print(f"Q quantization error: MAE={Q_quant_err.mean():.4f}, max={Q_quant_err.max():.4f}")
print(f"K quantization error: MAE={K_quant_err.mean():.4f}, max={K_quant_err.max():.4f}")
print()

# ---------------------------------------------------------------------------
# Step 5: Compute FP4 dot products with FP32 accumulation
# C_raw[i,j] = sum_k Q_fp4[i,k] * K_fp4[j,k]  -- in FP32
# ---------------------------------------------------------------------------
C_raw = Q_fp4_vals @ K_fp4_vals.T  # [SIZE x SIZE] in FP32

print("C_raw (FP4 inputs, FP32 accumulate, before dequantization):")
print(np.round(C_raw, 4))
print()

# ---------------------------------------------------------------------------
# Step 6: Dequantization
# C_deq[i,j] = C_raw[i,j] * S_Q[i] * S_K[j]
# ---------------------------------------------------------------------------
C_deq = C_raw * S_Q[:, np.newaxis] * S_K[np.newaxis, :]

print("C_deq (after dequantization):")
print(np.round(C_deq, 4))
print()

# ---------------------------------------------------------------------------
# Step 7: Error analysis
# ---------------------------------------------------------------------------
abs_err = np.abs(C_deq - C_ref)
rel_err = abs_err / (np.abs(C_ref) + 1e-8)

print("=" * 50)
print("Error analysis: C_deq vs C_ref (FP32 ground truth)")
print(f"  MAE:          {abs_err.mean():.4f}")
print(f"  Max error:    {abs_err.max():.4f}")
print(f"  Mean rel err: {rel_err.mean()*100:.2f}%")
print(f"  Max rel err:  {rel_err.max()*100:.2f}%")
print("=" * 50)
print()
# Filtered relative error -- exclude near-zero elements
mask = np.abs(C_ref) > 0.5
if mask.any():
    filtered_rel = rel_err[mask]
    print(f"Filtered rel err (|ref|>0.5): mean={filtered_rel.mean()*100:.2f}%, max={filtered_rel.max()*100:.2f}%")
    
# ---------------------------------------------------------------------------
# Step 8: Write output files
# ---------------------------------------------------------------------------
out_dir = os.path.dirname(os.path.abspath(__file__))
golden_dir = os.path.join(out_dir, '..', 'golden')
os.makedirs(golden_dir, exist_ok=True)

# Q matrix FP32
with open(os.path.join(golden_dir, 'q_matrix.txt'), 'w') as f:
    f.write(f'# Q matrix [{SIZE}x{D_HEAD}] FP32\n')
    for row in Q_fp32:
        f.write(' '.join(f'{v:.6f}' for v in row) + '\n')

# K matrix FP32
with open(os.path.join(golden_dir, 'k_matrix.txt'), 'w') as f:
    f.write(f'# K matrix [{SIZE}x{D_HEAD}] FP32\n')
    for row in K_fp32:
        f.write(' '.join(f'{v:.6f}' for v in row) + '\n')

# FP32 reference output
with open(os.path.join(golden_dir, 'qkt_fp32_ref.txt'), 'w') as f:
    f.write(f'# QK^T reference [{SIZE}x{SIZE}] FP32 ground truth\n')
    for row in C_ref:
        f.write(' '.join(f'{v:.6f}' for v in row) + '\n')

# Scale factors
with open(os.path.join(golden_dir, 'scale_factors.txt'), 'w') as f:
    f.write(f'# S_Q scale factors [{SIZE}] FP32\n')
    for v in S_Q:
        f.write(f'{v:.8f}\n')
    f.write(f'# S_K scale factors [{SIZE}] FP32\n')
    for v in S_K:
        f.write(f'{v:.8f}\n')

# FP4 encoded values
with open(os.path.join(golden_dir, 'q_fp4_encoded.txt'), 'w') as f:
    f.write(f'# Q_fp4 encoded [{SIZE}x{D_HEAD}] FP4 E2M1 hex\n')
    for row in Q_fp4_vals:
        f.write(' '.join(f'0x{encode_fp4(v):01X}' for v in row) + '\n')

with open(os.path.join(golden_dir, 'k_fp4_encoded.txt'), 'w') as f:
    f.write(f'# K_fp4 encoded [{SIZE}x{D_HEAD}] FP4 E2M1 hex\n')
    for row in K_fp4_vals:
        f.write(' '.join(f'0x{encode_fp4(v):01X}' for v in row) + '\n')

# Dequantized expected output
with open(os.path.join(golden_dir, 'qkt_expected.txt'), 'w') as f:
    f.write(f'# QK^T expected [{SIZE}x{SIZE}] FP32 after FP4 microscaling\n')
    f.write(f'# MAE vs FP32 ref: {abs_err.mean():.4f}\n')
    for row in C_deq:
        f.write(' '.join(f'{v:.6f}' for v in row) + '\n')

print("Output files written to golden/:")
print("  q_matrix.txt        -- FP32 Q input")
print("  k_matrix.txt        -- FP32 K input")
print("  qkt_fp32_ref.txt    -- FP32 ground truth")
print("  scale_factors.txt   -- S_Q and S_K")
print("  q_fp4_encoded.txt   -- FP4 encoded Q")
print("  k_fp4_encoded.txt   -- FP4 encoded K")
print("  qkt_expected.txt    -- expected output after dequantization")
