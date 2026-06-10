#!/bin/bash

# Clear screen and set title if supported
clear
echo -ne "\033]0;C++ TUI Calculator Launcher\007"

# Check if g++ or clang++ is installed
if ! command -v g++ &> /dev/null; then
    echo "Error: g++ compiler could not be found."
    echo "Please install build-essential (Linux) or Xcode Command Line Tools (macOS)."
    exit 1
fi

echo "[STATUS] Compiling your TUI Calculator..."
g++ -O3 main.cpp -o calculator.out

if [ $? -eq 0 ]; then
    echo "[SUCCESS] Launching..."
    clear
    # Run the calculator
    ./calculator.out
    
    # Cleanup after the program closes
    rm calculator.out
else
    echo "[ERROR] Compilation failed. Check your C++ code for errors."
    read -p "Press Enter to exit..."
fi
