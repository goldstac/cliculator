@echo off
title C++ TUI Calculator Launcher
cls

:: Check if g++ is installed
where g++ >nul 2>nul
if %errorlevel% neq 0 (
    echo Error: g++ compiler not found in your PATH.
    echo Please install MinGW or MSYS2 to run this script.
    pause
    exit /b
)

echo [STATUS] Compiling your TUI Calculator...
g++ -O3 main.cpp -o calculator.exe

if %errorlevel% equ 0 (
    echo [SUCCESS] Launching...
    cls
    :: Run the calculator
    calculator.exe
    
    :: Cleanup after the program closes
    del calculator.exe
) else (
    echo [ERROR] Compilation failed. Check your C++ code for errors.
    pause
)
