@echo off
if "%1"=="clean" (
    if exist wallet.exe del wallet.exe
    echo Cleaned.
    exit /b 0
)

echo Compiling wallet...
g++ -std=c++17 -Wall -Wextra -Iinclude -Iutils src\*.cpp utils\*.cpp -o wallet.exe
if %errorlevel% neq 0 (
    echo Build failed.
    exit /b %errorlevel%
)
echo Build successful! Run wallet.exe to start.
