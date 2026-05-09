# CMAN — Resistive Crossbar Read Analysis

## Circuit setup

2×2 crossbar with fixed cell resistances:

```
R[0][0] = 1 kΩ (on)   R[0][1] = 2 kΩ (off)
R[1][0] = 2 kΩ (off)  R[1][1] = 1 kΩ (on)
```

Rows carry input voltages; columns sense output currents.

---

## Task 1 — Ideal read

**Conditions:** V_row0 = 1 V, col 0 at virtual ground (0 V), row 1 and col 1 grounded.

Only R[0][0] connects the driven row to the sensed column:

$$I_{col0} = \frac{V_{row0} - V_{col0}}{R[0][0]} = \frac{1 - 0}{1\,k\Omega} = 1\,\text{mA}$$

**I_col0, ideal = 1 mA**

---

## Task 2 — Sneak path read

**Conditions:** V_row0 = 1 V, col 0 = 0 V, row 1 and col 1 **floating**.

Four resistors now form a conducting loop. Let V_row1 and V_col1 be the unknown floating node voltages.

**KCL at V_col1:**

$$\frac{1 - V_{col1}}{2\,k\Omega} = \frac{V_{col1} - V_{row1}}{1\,k\Omega}$$

**KCL at V_row1:**

$$\frac{V_{col1} - V_{row1}}{1\,k\Omega} = \frac{V_{row1} - 0}{2\,k\Omega}$$

**Solving:**

From KCL at V_row1:

$$2(V_{col1} - V_{row1}) = V_{row1} \implies V_{row1} = \frac{2}{3}\,V_{col1}$$

Substituting into KCL at V_col1:

$$\frac{1 - V_{col1}}{2} = \frac{V_{col1}}{3} \implies 3 - 3\,V_{col1} = 2\,V_{col1}$$

$$\boxed{V_{col1} = 0.6\,\text{V}, \quad V_{row1} = 0.4\,\text{V}}$$

**Actual I_col0:**

| Path | Current |
|---|---|
| R[0][0]: (1 − 0) / 1 kΩ | 1.0 mA |
| R[1][0]: (0.4 − 0) / 2 kΩ | 0.2 mA |
| **Total** | **1.2 mA** |

**I_col0, actual = 1.2 mA** — 20% higher than ideal.

---

## Task 3 — Impact on MVM

Floating rows and columns create unintended conductive paths through neighboring cells. The sensed column current is no longer produced solely by the targeted weight, corrupting the analog dot-product result. In larger N×N arrays the number of alternate sneak paths grows with N², making accurate MVM increasingly unreliable without isolation devices, active biasing, or read compensation techniques.
