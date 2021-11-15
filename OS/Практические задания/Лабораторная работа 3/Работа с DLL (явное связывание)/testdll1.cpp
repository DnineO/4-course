/************************************************************************
                          Лабораторная работа N3

                                Пример 2.

                               TESTDLL.CPP

     Пример библиотеки DLL, экспортирующей функцию при явном связывании

************************************************************************/
#include <windows.h>


LPSTR GetSomeString ()       
{                            
   return "Hello from DLL!\n";
}


extern "C" LPSTR  __declspec (dllexport) Test (void)
{
   return GetSomeString ();
}


BOOL WINAPI DllEntryPoint (HINSTANCE, DWORD, DWORD)
{
    return 1;    
}

