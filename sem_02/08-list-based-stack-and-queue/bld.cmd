@echo off
set bldDir=%~dp0_build

echo %bldDir%
mkdir %bldDir%
cd %bldDir%
cmake ..
cmake --build .
cd ..

