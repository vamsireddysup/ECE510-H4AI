"""
Golden reference for QK^T matrix multiply.
Generates test inputs and expected output for the systolic array testbench.

Saves three files to the golden/ directory:
  q_matrix.txt     -- Q matrix, one row per line, space separated
  k_matrix.txt     -- K matrix, one row per line, space separated
  qkt_expected.txt -- Expected QK^T output, one row per line

The testbench loads q_matrix.txt and k_matrix.txt, feeds them into the
systolic array, and compares the output against qkt_expected.txt.

Matrix dimensions:
  Q:   [T x d_head] = [4 x 4]
  K:   [T x d_head] = [4 x 4]
  K^T: [d_head x T] = [4 x 4]
  QK^T result: [T x T] = [4 x 4]

Using small integers for easy manual verification.
"""

import numpy as np
import os

# ---------------------------------------------------------------------------
# Dimensions
# ---------------------------------------------------------------------------
T      = 4   # sequence length (small for testbench)
D_HEAD = 4   # head dimension

# ---------------------------------------------------------------------------
# Fixed test matrices -- small integers so you can verify by hand
# ---------------------------------------------------------------------------
Q = np.array([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [1, 0, 1, 0],
    [2, 3, 2, 3],
], dtype=np.float32)

K = np.array([
    [1, 0, 1, 0],
    [0, 1, 0, 1],
    [1, 1, 0, 0],
    [0, 0, 1, 1],
], dtype=np.float32)

# ---------------------------------------------------------------------------
# Compute QK^T
# ---------------------------------------------------------------------------
K_T   = K.T                          # transpose K: [d_head x T]
QKT   = Q @ K_T                      # matrix multiply: [T x T]

print("Q matrix:")
print(Q)
print("\nK matrix:")
print(K)
print("\nK^T matrix:")
print(K_T)
print("\nQK^T result:")
print(QKT)

# ---------------------------------------------------------------------------
# Manual verification of one element so you can check by hand
# QKT[0][0] = dot(Q row 0, K^T col 0) = dot(Q row 0, K row 0)
# = 1*1 + 2*0 + 3*1 + 4*0 = 1 + 0 + 3 + 0 = 4
# ---------------------------------------------------------------------------
print(f"\nManual check QKT[0][0]: "
      f"dot([1,2,3,4], [1,0,1,0]) = "
      f"1*1 + 2*0 + 3*1 + 4*0 = {int(QKT[0][0])}")

# ---------------------------------------------------------------------------
# Save to files
# ---------------------------------------------------------------------------
out_dir = os.path.join(os.path.dirname(__file__))
os.makedirs(out_dir, exist_ok=True)

np.savetxt(os.path.join(out_dir, "q_matrix.txt"),
           Q, fmt="%.6f", header=f"Q matrix [{T}x{D_HEAD}]")

np.savetxt(os.path.join(out_dir, "k_matrix.txt"),
           K, fmt="%.6f", header=f"K matrix [{T}x{D_HEAD}]")

np.savetxt(os.path.join(out_dir, "qkt_expected.txt"),
           QKT, fmt="%.6f", header=f"QKT expected [{T}x{T}]")

print(f"\nFiles saved to: {out_dir}")
print("  q_matrix.txt")
print("  k_matrix.txt")
print("  qkt_expected.txt")
