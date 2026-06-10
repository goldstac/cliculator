@echo off
title C++ TUI Calculator
if exist bin\calculator.exe (
    bin\calculator.exe
) else (
    echo [ERROR] Executable not found. Please run build.bat first.
    pause
)
