@echo off

call D:\Github\MATLAB\Others\HXML\Source\emsdk-main\emsdk-main\emsdk activate latest

cd .

if "%1"=="" ("D:\MATLAB\R2023b\bin\win64\gmake"  -j32 -f foo_rtw.mk all) else ("D:\MATLAB\R2023b\bin\win64\gmake"  -j32 -f foo_rtw.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1