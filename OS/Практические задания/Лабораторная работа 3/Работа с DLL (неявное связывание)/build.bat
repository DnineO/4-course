@echo off
@echo  � 
@echo                           ��������㥬 � ������㥬 DLL
@echo                           ___________________________
@echo  �
bcc32.exe -tWD testdll.cpp
@echo  �
@echo                   ������� �� �᭮�� DLL ������⥪� ������ TESTDLL.LIB 
@echo                   ____________________________________________________
@echo  �
implib.exe testdll testdll.dll
@echo  �
@echo          ��������㥬 � ������㥬 EXE, �易� ��� � ������⥪�� ������
@echo          _____________________________________________________________
@echo   �
bcc32.exe -tWE caller.cpp testdll.lib
del *.tds
del *.obj
@echo   �
@echo   �
pause                           