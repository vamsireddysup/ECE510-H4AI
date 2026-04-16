/*
 * gemm_tiled.cu -- Tiled CUDA GEMM kernel
 * Shared memory tiling with tile size T=8
 * Each tile loaded once into shared memory, reused T times
 *
 * Matrix size: 1024 x 1024, FP32
 */

#include <stdio.h>
#include <cuda_runtime.h>

#define N    1024
#define T    8

__global__ void gemm_tiled(float* A, float* B, float* C, int n) {
    __shared__ float sA[T][T];
    __shared__ float sB[T][T];

    int row = blockIdx.y * T + threadIdx.y;
    int col = blockIdx.x * T + threadIdx.x;
    float sum = 0.0f;

    // Step through tiles along k dimension
    for (int t = 0; t < (n + T - 1) / T; t++) {

        // Load tile of A into shared memory
        if (row < n && t * T + threadIdx.x < n)
            sA[threadIdx.y][threadIdx.x] = A[row * n + t * T + threadIdx.x];
        else
            sA[threadIdx.y][threadIdx.x] = 0.0f;

        // Load tile of B into shared memory
        if (col < n && t * T + threadIdx.y < n)
            sB[threadIdx.y][threadIdx.x] = B[(t * T + threadIdx.y) * n + col];
        else
            sB[threadIdx.y][threadIdx.x] = 0.0f;

        __syncthreads();

        // Compute partial dot product using shared tile
        for (int k = 0; k < T; k++) {
            sum += sA[threadIdx.y][k] * sB[k][threadIdx.x];
        }

        __syncthreads();
    }

    if (row < n && col < n)
        C[row * n + col] = sum;
}

int main() {
    int size = N * N * sizeof(float);

    float *h_A = (float*)malloc(size);
    float *h_B = (float*)malloc(size);
    float *h_C = (float*)malloc(size);

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

    dim3 block(T, T);
    dim3 grid((N + T - 1) / T, (N + T - 1) / T);

    // Warmup
    gemm_tiled<<<grid, block>>>(d_A, d_B, d_C, N);
    cudaDeviceSynchronize();

    // Timing
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);

    cudaEventRecord(start);
    gemm_tiled<<<grid, block>>>(d_A, d_B, d_C, N);
    cudaEventRecord(stop);
    cudaEventSynchronize(stop);

    float ms = 0;
    cudaEventElapsedTime(&ms, start, stop);

    double flops = 2.0 * N * N * N;
    double gflops = flops / (ms * 1e6);

    printf("gemm_tiled: N=%d, T=%d\n", N, T);
    printf("Time:       %.4f ms\n", ms);
    printf("GFLOP/s:    %.2f\n", gflops);

    // Arithmetic intensity
    // Tiled: each element loaded once = 2*N^2*4 bytes
    double bytes = 2.0 * N * N * 4 + (double)N * N * 4;
    double ai = flops / bytes;
    printf("AI:         %.4f FLOP/byte\n", ai);

    cudaMemcpy(h_C, d_C, size, cudaMemcpyDeviceToHost);
    printf("C[0][0]:    %.4f (expected %.4f)\n", h_C[0], 0.01f * 0.01f * N);

    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);
    free(h_A); free(h_B); free(h_C);
    return 0;
}
