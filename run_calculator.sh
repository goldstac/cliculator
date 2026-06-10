#!/bin/bash
if [ -f bin/calculator.out ]; then
    ./bin/calculator.out
) else (
    echo "[ERROR] Executable not found. Please run build.sh first."
fi
