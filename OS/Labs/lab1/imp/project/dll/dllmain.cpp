// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <windows.h>


LPCWSTR GetSomeString()         
{                              
    return L"Hello from DLL!\n";
}


LPCWSTR  __declspec (dllexport) Test(void)
{
    return GetSomeString();
}


BOOL WINAPI DllEntryPoint(HINSTANCE, DWORD, DWORD)
{
    return 1;
}