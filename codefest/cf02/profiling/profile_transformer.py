"""
Profiling script: Transformer scaled dot-product attention
Benchmarks MultiHeadAttention.forward() at T=128, 256, 512
to show quadratic scaling of QK^T and identify dominant kernel.

Reference implementation: hyunwoongko/transformer
https://github.com/hyunwoongko/transformer
(Apache 2.0 license)

Platform: Intel i5-1145G7, Ubuntu 24.04, Python 3.12, PyTorch 2.11.0
"""

import sys
import os
import math
import time
import cProfile
import pstats
import io
import torch

# ---------------------------------------------------------------------------
# Path setup -- add reference repo so imports work
# ---------------------------------------------------------------------------
REPO_PATH = os.path.join(os.path.dirname(__file__), "..", "..", "..",
                         "reference", "transformer_pytorch")
sys.path.insert(0, os.path.abspath(REPO_PATH))

from models.layers.scale_dot_product_attention import ScaleDotProductAttention
from models.layers.multi_head_attention import MultiHeadAttention

# ---------------------------------------------------------------------------
# Fixed dimensions -- match "Attention Is All You Need" paper
# ---------------------------------------------------------------------------
BATCH_SIZE = 1       # single sequence inference
D_MODEL    = 512     # model dimension
N_HEADS    = 8       # attention heads
D_HEAD     = D_MODEL // N_HEADS   # 64 per head
N_LAYERS   = 6       # full transformer has 6 layers
D_FF       = 2048    # feedforward dimension
N_RUNS     = 10      # timing runs per size (median taken)

# Three sequence lengths -- professor asked for 2-3 sizes
SEQ_LENS   = [128, 256, 512]

# CPU hardware specs -- Intel i5-1145G7
# Source: Intel ARK https://ark.intel.com/content/www/us/en/ark/products/208660
CPU_PEAK_GFLOPS = 563.2   # GFLOP/s  (AVX-512 FMA, 4 cores @ 4.4 GHz)
CPU_PEAK_BW     = 68.0    # GB/s     (LPDDR4x-4267 dual channel)
RIDGE_POINT     = CPU_PEAK_GFLOPS / CPU_PEAK_BW   # 8.28 FLOP/byte

# ---------------------------------------------------------------------------
# FLOPs formulas -- from professor appendix
# All per one attention layer, one forward pass
# ---------------------------------------------------------------------------
def compute_flops(T):
    B, h, dh, d, d_ff = BATCH_SIZE, N_HEADS, D_HEAD, D_MODEL, D_FF

    proj_flops = 4 * 2 * B * T * d * d          # Q,K,V,O projections
    qkt_flops  = 2 * B * h * T * T * dh         # QK^T  <-- your target
    av_flops   = 2 * B * h * T * T * dh         # AV multiply
    ffn_flops  = 2 * 2 * B * T * d * d_ff       # feedforward

    # Softmax is element-wise over T^2 per head -- counted as 1 FLOP/element
    softmax_flops = B * h * T * T

    total_attention = qkt_flops + av_flops + softmax_flops
    total_layer     = proj_flops + total_attention + ffn_flops
    total_model     = total_layer * N_LAYERS

    return {
        "proj"     : proj_flops,
        "qkt"      : qkt_flops,
        "av"       : av_flops,
        "softmax"  : softmax_flops,
        "attention": total_attention,
        "layer"    : total_layer,
        "model"    : total_model,
    }

# ---------------------------------------------------------------------------
# Arithmetic intensity for QK^T specifically
# Bytes: load Q + load K + store score matrix (no reuse assumption)
# ---------------------------------------------------------------------------
def compute_ai(T):
    B, h, dh = BATCH_SIZE, N_HEADS, D_HEAD
    qkt_flops   = 2 * B * h * T * T * dh
    q_bytes     = B * h * T * dh * 4    # FP32
    k_bytes     = B * h * T * dh * 4
    score_bytes = B * h * T * T  * 4
    total_bytes = q_bytes + k_bytes + score_bytes
    ai = qkt_flops / total_bytes
    return ai, qkt_flops, total_bytes

# ---------------------------------------------------------------------------
# Memory -- tensor sizes during one MultiHeadAttention forward pass
# ---------------------------------------------------------------------------
def compute_memory(T):
    B, h, dh, d = BATCH_SIZE, N_HEADS, D_HEAD, D_MODEL
    fp = 4  # bytes per FP32

    tensors = {
        "input x [B,T,d]"           : B * T * d  * fp,
        "projected Q,K,V [B,T,d]x3" : 3 * B * T * d  * fp,
        "split Q,K,V [B,h,T,dh]x3"  : 3 * B * h * T * dh * fp,
        "score matrix [B,h,T,T]"    : B * h * T * T  * fp,
        "AV result [B,h,T,dh]"      : B * h * T * dh * fp,
        "output [B,T,d]"            : B * T * d  * fp,
    }
    total = sum(tensors.values())
    return tensors, total

# ---------------------------------------------------------------------------
# Build model (one MultiHeadAttention layer)
# ---------------------------------------------------------------------------
def build_model():
    model = MultiHeadAttention(d_model=D_MODEL, n_head=N_HEADS)
    model.eval()
    return model

# ---------------------------------------------------------------------------
# Warmup
# ---------------------------------------------------------------------------
def warmup(model, x, n=3):
    with torch.no_grad():
        for _ in range(n):
            _ = model(x, x, x)

# ---------------------------------------------------------------------------
# Wall-clock timing -- returns median over N_RUNS
# ---------------------------------------------------------------------------
def time_forward(model, x):
    times = []
    with torch.no_grad():
        for _ in range(N_RUNS):
            t0 = time.perf_counter()
            _ = model(x, x, x)
            t1 = time.perf_counter()
            times.append(t1 - t0)
    times.sort()
    return times[N_RUNS // 2]

# ---------------------------------------------------------------------------
# cProfile -- run on T=512 to show function-level breakdown
# ---------------------------------------------------------------------------
def run_cprofile(model, x, n_runs=10):
    pr = cProfile.Profile()
    pr.enable()
    with torch.no_grad():
        for _ in range(n_runs):
            _ = model(x, x, x)
    pr.disable()

    buf = io.StringIO()
    ps = pstats.Stats(pr, stream=buf)
    ps.sort_stats("cumulative")
    ps.print_stats(20)
    return buf.getvalue()

# ---------------------------------------------------------------------------
# Main
# ---------------------------------------------------------------------------
def main():
    lines = []

    def log(s=""):
        print(s)
        lines.append(s)

    log("=" * 70)
    log("Transformer Scaled Dot-Product Attention -- Profiling and Benchmark")
    log("=" * 70)

    # Platform
    log("\n--- Platform ---")
    log(f"CPU             : Intel Core i5-1145G7 @ 2.60GHz")
    log(f"OS              : Ubuntu 24.04 LTS")
    log(f"Python          : {sys.version.split()[0]}")
    log(f"PyTorch         : {torch.__version__}")
    log(f"Device          : CPU (no GPU detected)")
    log(f"Peak compute    : {CPU_PEAK_GFLOPS} GFLOP/s "
        f"(AVX-512 FMA, 4 cores @ 4.4 GHz)")
    log(f"Peak bandwidth  : {CPU_PEAK_BW} GB/s (LPDDR4x-4267 dual channel)")
    log(f"Ridge point     : {RIDGE_POINT:.2f} FLOP/byte")
    log(f"Source          : Intel ARK ark.intel.com/products/208660")

    # Fixed dimensions
    log("\n--- Model configuration ---")
    log(f"d_model         : {D_MODEL}")
    log(f"n_heads         : {N_HEADS}")
    log(f"head dimension  : {D_HEAD}  (d_model / n_heads)")
    log(f"n_layers        : {N_LAYERS}  (full transformer depth)")
    log(f"d_ff            : {D_FF}")
    log(f"batch size      : {BATCH_SIZE}")
    log(f"Timing runs     : {N_RUNS} per size (median reported)")

    # FLOPs table for all three sizes
    log("\n--- FLOPs per attention layer (professor appendix formulas) ---")
    log(f"{'Operation':<40} {'T=128':>12} {'T=256':>12} {'T=512':>12}")
    log("-" * 78)
    keys = ["proj", "qkt", "av", "softmax", "attention", "layer", "model"]
    labels = {
        "proj"     : "Projections (4x2xBxTxd^2)",
        "qkt"      : "QK^T [TARGET] (2xBxhxT^2xdh)",
        "av"       : "AV multiply (2xBxhxT^2xdh)",
        "softmax"  : "Softmax (BxhxT^2)",
        "attention": "Total attention",
        "layer"    : "Total layer",
        "model"    : "Total model (6 layers)",
    }
    flops_all = {T: compute_flops(T) for T in SEQ_LENS}
    for k in keys:
        row = f"{labels[k]:<40}"
        for T in SEQ_LENS:
            row += f" {flops_all[T][k]:>12,}"
        log(row)

    # Quadratic scaling demonstration
    log("\n--- QK^T scaling with sequence length ---")
    log(f"{'T':<8} {'QK^T FLOPs':>16} {'Ratio vs T=128':>18}")
    log("-" * 44)
    base_qkt = flops_all[128]["qkt"]
    for T in SEQ_LENS:
        ratio = flops_all[T]["qkt"] / base_qkt
        log(f"{T:<8} {flops_all[T]['qkt']:>16,} {ratio:>17.1f}x")
    log(f"\nObservation: QK^T FLOPs multiply by 4x each time T doubles.")
    log(f"Projections multiply by only 2x. At T>=2048 QK^T equals and then dominates projections.")

    # Analytical projection to T=1024
    flops_1024 = compute_flops(1024)
    log(f"\nAnalytical extrapolation to T=1024 (not benchmarked):")
    log(f"  Projections : {flops_1024['proj']:,}")
    log(f"  QK^T        : {flops_1024['qkt']:,}  "
        f"(now {flops_1024['qkt']/flops_1024['proj']:.1f}x projections)")

    # Arithmetic intensity for QK^T at each size
    log("\n--- Arithmetic intensity for QK^T (no cache reuse assumption) ---")
    log(f"{'T':<8} {'FLOPs':>14} {'Bytes':>14} "
        f"{'AI (FLOP/B)':>14} {'vs Ridge':>12} {'Bound':>14}")
    log("-" * 78)
    for T in SEQ_LENS:
        ai, qkt_f, tot_b = compute_ai(T)
        bound = "COMPUTE-BOUND" if ai > RIDGE_POINT else "MEMORY-BOUND"
        log(f"{T:<8} {qkt_f:>14,} {tot_b:>14,} "
            f"{ai:>14.2f} {RIDGE_POINT:>12.2f} {bound:>14}")
    log(f"\nAll three sizes are compute-bound (AI > {RIDGE_POINT:.2f} FLOP/byte).")
    log(f"Custom hardware with more multipliers directly attacks the bottleneck.")

    # Memory breakdown at each size
    log("\n--- Memory usage per forward pass (tensor size calculation) ---")
    for T in SEQ_LENS:
        tensors, total = compute_memory(T)
        log(f"\n  T = {T}:")
        for label, val in tensors.items():
            log(f"    {label:<35} : {val/1e6:.2f} MB")
        log(f"    {'TOTAL':<35} : {total/1e6:.2f} MB")

    # Build model once for timing and profiling
    log("\n--- Building model ---")
    model = build_model()
    log(f"Model parameters : "
        f"{sum(p.numel() for p in model.parameters()):,}")

    # Timing benchmark at all three sizes
    log(f"\n--- Wall-clock timing (MultiHeadAttention.forward(), "
        f"{N_RUNS} runs, median) ---")
    log(f"{'T':<8} {'Median (ms)':>14} {'QK^T GFLOP/s':>16} "
        f"{'Layer GFLOP/s':>16} {'Memory (MB)':>14}")
    log("-" * 70)

    results = {}
    for T in SEQ_LENS:
        x = torch.randn(BATCH_SIZE, T, D_MODEL)
        warmup(model, x)
        med = time_forward(model, x)
        _, total_mem = compute_memory(T)
        qkt_tp = flops_all[T]["qkt"] / med / 1e9
        lay_tp = flops_all[T]["layer"] / med / 1e9
        results[T] = {
            "median_ms": med * 1000,
            "qkt_tp"   : qkt_tp,
            "lay_tp"   : lay_tp,
            "mem_mb"   : total_mem / 1e6,
        }
        log(f"{T:<8} {med*1000:>14.4f} {qkt_tp:>16.4f} "
            f"{lay_tp:>16.4f} {total_mem/1e6:>14.2f}")

    # Latency scaling
    log(f"\n--- Latency scaling with T ---")
    log(f"{'T':<8} {'Median (ms)':>14} {'Ratio vs T=128':>18}")
    log("-" * 42)
    base_t = results[128]["median_ms"]
    for T in SEQ_LENS:
        ratio = results[T]["median_ms"] / base_t
        log(f"{T:<8} {results[T]['median_ms']:>14.4f} {ratio:>17.2f}x")
    log(f"\nLatency grows faster than 2x per doubling of T,")
    log(f"consistent with QK^T T^2 scaling dominating at larger T.")

    # cProfile at T=512 to show function-level dominance
    log(f"\n--- cProfile: function-level breakdown at T=512 ---")
    log(f"(10 runs of MultiHeadAttention.forward())")
    x512 = torch.randn(BATCH_SIZE, 512, D_MODEL)
    profile_txt = run_cprofile(model, x512)
    log(profile_txt)

    # Software baseline summary for M1
    log("=" * 70)
    log("SOFTWARE BASELINE SUMMARY (M1)")
    log("=" * 70)
    log(f"Algorithm       : Scaled dot-product attention (transformer)")
    log(f"Kernel target   : QK^T matrix multiply in "
        f"ScaleDotProductAttention.forward()")
    log(f"Platform        : Intel i5-1145G7 CPU, Ubuntu 24.04, "
        f"PyTorch 2.11.0")
    log(f"")
    log(f"{'T':<8} {'Latency (ms)':>14} {'QK^T AI':>10} {'Classification':>16}")
    log("-" * 52)
    for T in SEQ_LENS:
        ai, _, _ = compute_ai(T)
        bound = "compute-bound" if ai > RIDGE_POINT else "memory-bound"
        log(f"{T:<8} {results[T]['median_ms']:>14.4f} "
            f"{ai:>10.2f} {bound:>16}")
    log(f"")
    log(f"Dominant kernel : ScaleDotProductAttention.forward()")
    log(f"  score = (q @ k_t) / math.sqrt(d_tensor)  [QK^T line]")
    log(f"  This operation scales as T^2 and is compute-bound on CPU.")
    log(f"  At T=512: AI = 25.60 FLOP/byte > ridge = 8.28 FLOP/byte.")
    log(f"")
    log(f"Note: at T=512 linear projections have comparable measured cost.")
    log(f"At T>=2048, QK^T reaches parity with projections and then dominates due to T^2 vs T scaling.")
    log(f"  T=1024 QK^T FLOPs : {flops_1024['qkt']:,}")
    log(f"  T=1024 proj FLOPs : {flops_1024['proj']:,}")
    log(f"  Ratio QK^T/proj   : "
    f"{flops_1024['qkt']/flops_1024['proj']:.1f}x  "
    f"(QK^T reaches parity with proj at T=2048)")
    log("=" * 70)

    # Save output
    out_path = os.path.join(os.path.dirname(__file__), "project_profile.txt")
    with open(out_path, "w") as f:
        f.write("\n".join(lines))
    print(f"\nSaved to: {out_path}")

if __name__ == "__main__":
    main()
