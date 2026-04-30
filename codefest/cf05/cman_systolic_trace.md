# CMAN -- Systolic array trace (weight-stationary)

**Given:**
- A = [[1, 2], [3, 4]]
- B = [[5, 6], [7, 8]]
- Expected C = A × B = [[19, 22], [43, 50]]

---

## Task 1: PE diagram with preloaded weights

Weight-stationary: B values are preloaded and stay fixed in each PE.
Activations (A rows) stream left to right. Partial sums flow downward.

```
         Col 0       Col 1
       +----------+----------+
Row 0  | PE[0][0] | PE[0][1] |
       | weight=5 | weight=6 |
       +----------+----------+
              ↓ psum      ↓ psum
       +----------+----------+
Row 1  | PE[1][0] | PE[1][1] |
       | weight=7 | weight=8 |
       +----------+----------+

Preloaded weights:
  PE[0][0] = B[0][0] = 5
  PE[0][1] = B[0][1] = 6
  PE[1][0] = B[1][0] = 7
  PE[1][1] = B[1][1] = 8

Data flow:
  A rows enter from the left (row 1 staggered by 1 cycle)
  Partial sums flow downward from row 0 into row 1
```

---

## Task 2: Cycle-by-cycle trace table

| Cycle | Row 0 input | Row 1 input | PE[0][0] psum | PE[0][1] psum | PE[1][0] psum | PE[1][1] psum | Output C |
|-------|-------------|-------------|---------------|---------------|---------------|---------------|----------|
| 1     | A[0][0]=1   | --          | 1×5 = 5       | 1×6 = 6       | 0             | 0             | --       |
| 2     | A[0][1]=2   | A[1][0]=3   | 5+2×5 = 15    | 6+2×6 = 18    | 5+3×7 = 26    | 6+3×8 = 30    | --       |
| 3     | --          | A[1][1]=4   | 15 (done)     | 18 (done)     | 26+4×7 = 54   | 30+4×8 = 62   | --       |
| 4     | --          | --          | drain         | drain         | drain         | drain         | C[0][0]=19, C[0][1]=22, C[1][0]=43, C[1][1]=50 |

**How final results are computed:**

```
C[0][0] = A[0][0]×B[0][0] + A[0][1]×B[1][0] = 1×5 + 2×7 = 5  + 14 = 19
C[0][1] = A[0][0]×B[0][1] + A[0][1]×B[1][1] = 1×6 + 2×8 = 6  + 16 = 22
C[1][0] = A[1][0]×B[0][0] + A[1][1]×B[1][0] = 3×5 + 4×7 = 15 + 28 = 43
C[1][1] = A[1][0]×B[0][1] + A[1][1]×B[1][1] = 3×6 + 4×8 = 18 + 32 = 50
```

Row 0 partial sums (15 and 18) flow down into row 1 PEs and combine
with row 1 activations to produce the final C row 1 outputs.

---

## Task 3: Counts

**(a) Total MAC operations:**

```
Total MACs = N^3 = 2^3 = 8
```

Each of the 4 output elements requires N=2 MAC operations.
4 output elements × 2 MACs each = 8 total MACs.

**(b) Number of times each input value is reused:**

Each element of A is reused 2 times -- once per column of B.
B has 2 columns, so each of the 4 A values is used 2 times.
Total uses of A = 4 elements × 2 reuses = 8 total uses.

**(c) Off-chip memory accesses:**

```
A reads:   4 elements × 1 load each  = 4 accesses
B reads:   4 elements × 1 pre-load   = 4 accesses (loaded once before compute)
C writes:  4 elements × 1 store each = 4 accesses
Total:     12 off-chip memory accesses
```

In weight-stationary dataflow, B weights are loaded once and reused
for every input activation -- this is the key advantage. Without
weight-stationary, B would need to be reloaded N times per output
row, resulting in N × 4 = 8 accesses for B instead of 4.

---

## Task 4: Output-stationary answer

In output-stationary dataflow, the partial sums (accumulated output
values) stay fixed in each PE for the entire computation, while both
weights and activations stream through the array.
