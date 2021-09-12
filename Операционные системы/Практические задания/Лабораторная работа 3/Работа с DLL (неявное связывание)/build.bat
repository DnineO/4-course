@echo off
@echo    
@echo                           Компилируем и компонуем DLL
@echo                           ___________________________
@echo   
bcc32.exe -tWD testdll.cpp
@echo   
@echo                   Создаем на основе DLL библиотеку импорта TESTDLL.LIB 
@echo                   ____________________________________________________
@echo   
implib.exe testdll testdll.dll
@echo   
@echo          Компилируем и компонуем EXE, связав его с библиотекой импорта
@echo          _____________________________________________________________
@echo    
bcc32.exe -tWE caller.cpp testdll.lib
del *.tds
del *.obj
@echo    
@echo    
pause                           