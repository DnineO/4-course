@echo off
@echo  � 
@echo                           ��������㥬 � ������㥬 DLL
@echo                           ___________________________
@echo  �
bcc32.exe -tWD testdll.cpp
@echo  �
@echo                           ��������㥬 � ������㥬 EXE
@echo                           ___________________________
@echo   �
bcc32.exe -tWE caller.cpp
del *.tds
del *.obj
@echo   �
@echo   �
pause                           