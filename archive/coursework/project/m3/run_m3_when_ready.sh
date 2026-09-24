#!/bin/bash
LOG=~/m3_synthesis.log
exec > >(tee $LOG) 2>&1

echo "=== Started: $(date) ==="

# Wait for yosys build
cd ~/Tools/yosys-0.44
echo "Building yosys..."
make -j$(nproc) 2>&1 | tail -5

if [ ! -f ~/Tools/yosys-0.44/yosys ]; then
    echo "ERROR: yosys build failed"
    exit 1
fi

echo "Yosys built: $(./yosys --version)"

# Install
sudo cp yosys /usr/local/bin/yosys
sudo cp yosys-abc /usr/local/bin/yosys-abc

# Run synthesis
cd "/home/vamsidhar-reddy-eraganeni/Desktop/PSU Courses/ECE510 - Hardware for AI/ECE510-H4AI/project/m3"
echo "Running synthesis..."
/usr/local/bin/yosys runs/synth.ys 2>&1 | tee runs/yosys_synth.log

echo "=== Done: $(date) ==="
