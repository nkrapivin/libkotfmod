@echo off

set confname=%1
echo Post-Build Configuration name: %confname%

echo Copying files...
copy /Y x64\%confname%\libkotfmod_x64.dll libkotfmod.gms23\extensions\libkotfmod\libkotfmod_x64.dll
copy /Y %confname%\libkotfmod.dll libkotfmod.gms23\extensions\libkotfmod\libkotfmod.dll
copy /Y libkotfmod.h libkotfmod.gms23\extensions\libkotfmod\libkotfmod.cpp

echo Running GmxGen...
GmxGen libkotfmod.gms23\extensions\libkotfmod\libkotfmod.yy

echo Cleanup...
del /Q /F libkotfmod.gms23\extensions\libkotfmod\libkotfmod.cpp

echo Post-Build Done.
