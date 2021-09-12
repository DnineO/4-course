@echo off
@echo   
@echo          Компилируем и компонуем EXE
@echo          _____________________________________________________________
@echo    
bcc32.exe -tW test.cpp
del *.tds
del *.obj
@echo    
@echo    
pause                           