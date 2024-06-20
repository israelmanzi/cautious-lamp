@echo off

git pull origin main -q
if %errorlevel% ne 0 (
    echo Git pull failed.
    exit /b 1
)

g++ -o main.exe main.cpp
if errorlevel 1 (
    echo Compilation failed.
    exit /b 1
)

main.exe
