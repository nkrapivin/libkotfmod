@echo off

echo Are you sure?
pause

set JNIGEN=D:\Projects\VisualStudio\CPP\JniGen\bin\Debug\netcoreapp3.1\JniGen.exe

rem cd /D %~dp0
%JNIGEN% -domain com -company nkrapivindev -product libkotfmod -classname LKFNative -file libkotfmod.h

del /Q /F libkotfmod.gms23\extensions\libkotfmod\AndroidSource\Sdk\com.nkrapivindev.libkotfmod\src\main\java\com\nkrapivindev\libkotfmod\LKFNative.java
copy LKFNative.java libkotfmod.gms23\extensions\libkotfmod\AndroidSource\Sdk\com.nkrapivindev.libkotfmod\src\main\java\com\nkrapivindev\libkotfmod\

pause

