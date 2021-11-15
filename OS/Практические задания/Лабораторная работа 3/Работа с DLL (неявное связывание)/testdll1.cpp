/************************************************************************
                          Лабораторная работа N3

                                Пример 1.

                               TESTDLL.CPP

    Пример библиотеки DLL, экспортирующей функцию  при неявном связывании

************************************************************************/
#include <windows.h>


LPSTR GetSomeString ()        
{                             
   return "Hello from DLL!\n";
}


LPSTR  __declspec (dllexport) Test (void)
{
   return GetSomeString ();
}



BOOL WINAPI DllEntryPoint (HINSTANCE, DWORD, DWORD)
{
    return 1;   
}

