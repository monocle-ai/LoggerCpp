  
@echo off
pushd %~dp0\..\
call vendor\premake\premake5.exe vs2013
popd
PAUSE