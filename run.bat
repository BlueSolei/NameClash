pushd %~dp0
cd build\bin
if "%1"=="tests" (RenameSymTest.exe) else (RenameSym.exe)
popd
