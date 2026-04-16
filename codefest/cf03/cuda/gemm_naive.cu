/*
 * gemm_naive.cu -- Naive CUDA GEMM kernel
 * One thread per output element C[i][j]
 * No data reuse -- every element loaded fresh from global memory
 *
 * Matrix size: 1024 x 1024, FP32
 */

#include <stdio.h>
#include <cuda_runtime.h>

#define N 1024

__global__ void gemm_naive(float* A, float* B, float* C, int n) {
    int row = blockIdx.y * blockDim.y + threadIdx.y;
    int col = blockIdx.x * blockDim.x + threadIdx.x;

    if (row < n && col < n) {
        float sum = 0.0f;
        for (int k = 0; k < n; k++) {
            sum += A[row * n + k] * B[k * n + col];
        }
        C[row * n + col] = sum;
    }
}

int main() {
    int size = N * N * sizeof(float);

    float *h_A = (float*)malloc(size);
    float *h_B = (float*)malloc(size);
    float *h_C = (float*)malloc(size);

    // Initialize with small values
    for (int i = 0; i < N * N; i++) {
        h_A[i] = 0.01f;
        h_B[i] = 0.01f;
    }

    float *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    dim3 block(16, 16);
    dim3 grid((N + block.x - 1) / block.x, (N + block.y - 1) / block.y);

    // Warmup
    gemm_naive<<<grid, block>>>(d_A, d_B, d_C, N);
    cudaDeviceSynchronize();

    // Timing
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);
    gemm_naive<<<grid, block>>>(d_A, d_B, d_C, N);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    float ms = 0;
    cudaEventElapsedTime(&ms, start, stop);

    double flops = 2.0 * N * N * N;
    double gflops = flops / (ms * 1e6);

    printf("gemm_naive: N=%d\n", N);
    printf("Time:       %.4f ms\n", ms);
    printf("GFLOP/s:    %.2f\n", gflops);

    // Arithmetic intensity
    // Bytes: 2*N^3*4 (reads, no reuse) + N^2*4 (writes)
    double bytes = 2.0 * N * N * N * 4 + (double)N * N * 4;
    double ai = flops / bytes;
    printf("AI:         %.4f FLOP/byte\n", ai);

    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    printf("C[0][0]:    %.4f (expected %.4f)\n", h_C[0], 0.01f * 0.01f * N);

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);
    free(h_A); free(h_B); free(h_C);
    return 0;
}
