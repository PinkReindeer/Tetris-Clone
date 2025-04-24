@echo off

setlocal enabledelayedexpansion

set "DEVKIT_BIN=C:\raylib\w64devkit\bin"
set "PATH=%DEVKIT_BIN%;%PATH%"

set "PROJECT_ROOT=C:\Cpp_Project\Tetris"
set "SRC_DIR=%PROJECT_ROOT%\src"
set "EXE_NAME=%PROJECT_ROOT%\tetris.exe"
set "RAYLIB_DIR=C:\raylib\w64devkit\x86_64-w64-mingw32"

set "INCLUDE_PATH=-I%RAYLIB_DIR%\include"
set "LIB_PATH=-L%RAYLIB_DIR%\lib"
set "LIBS=-lraylib -lopengl32 -lgdi32 -lwinmm -static-libgcc -static-libstdc++"

set "ALL_SRC="
for %%f in ("%SRC_DIR%\*.cpp") do (
    set "ALL_SRC=!ALL_SRC! "%%f""
)

echo g++ !ALL_SRC! -o "%EXE_NAME%" %INCLUDE_PATH% %LIB_PATH% %LIBS%
g++ !ALL_SRC! -o "%EXE_NAME%" %INCLUDE_PATH% %LIB_PATH% %LIBS%

if %errorlevel% equ 0 (
    echo Build succeeded: "%EXE_NAME%"
) else (
    echo Build failed.
)
pause
endlocal