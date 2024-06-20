@echo off

git pull origin main -q && g++ -o main.exe main.cpp
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

main.exe
