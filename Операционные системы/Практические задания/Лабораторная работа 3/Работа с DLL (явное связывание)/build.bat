@echo off
@echo    
@echo                           Компилируем и компонуем DLL
@echo                           ___________________________
@echo   
bcc32.exe -tWD testdll.cpp
@echo   
@echo                           Компилируем и компонуем EXE
@echo                           ___________________________
@echo    
bcc32.exe -tWE caller.cpp
del *.tds
del *.obj
@echo    
@echo    
pause                           