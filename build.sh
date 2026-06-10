#!/bin/bash
mkdir -p bin
echo "[BUILD] Compiling release binary to bin/calculator.out..."
g++ -O3 main.cpp -o bin/calculator.out
if [ $? -eq 0 ]; then
    echo "[SUCCESS] Build complete. Binary located in bin/ folder."
else
    echo "[ERROR] Build failed."
fi
