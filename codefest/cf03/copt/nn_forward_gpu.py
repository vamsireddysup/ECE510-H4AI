"""
COPT: Neural network forward pass on GPU
Network: 4 inputs -> 5 hidden (ReLU) -> 1 output (linear)
Batch size: 16

Course: ECE 510 Spring 2026, Portland State University
"""

import torch
import torch.nn as nn
import sys

# Detect GPU
device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

if not torch.cuda.is_available():
    print("No CUDA GPU found. Exiting.")
    sys.exit(1)

print(f"Device: {torch.cuda.get_device_name(0)}")

# Define network: 4 -> 5 (ReLU) -> 1 (linear)
model = nn.Sequential(
    nn.Linear(4, 5),
    nn.ReLU(),
    nn.Linear(5, 1)
)

# Move model to GPU
model.to(device)
print(f"Model device: {next(model.parameters()).device}")

# Random input batch [16, 4]
x = torch.randn(16, 4).to(device)
print(f"Input shape: {x.shape}")
print(f"Input device: {x.device}")

# Forward pass
with torch.no_grad():
    output = model(x)

print(f"Output shape: {output.shape}")
print(f"Output device: {output.device}")
print(f"Output (first 4 values): {output[:4].squeeze().tolist()}")
