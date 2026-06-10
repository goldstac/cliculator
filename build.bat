@echo off
title Compiling TUI Calculator
if not exist bin mkdir bin
echo [BUILD] Compiling release binary to bin/calculator.exe...
g++ -O3 main.cpp -o bin/calculator.exe
if %errorlevel% equ 0 (
    echo [SUCCESS] Build complete. Binary located in bin/ folder.
) else (
    echo [ERROR] Build failed.
)
pause
