/************************************************************************
                          ������ୠ� ࠡ�� N3

                                �ਬ�� 2.

                               TESTDLL.CPP

     �ਬ�� ������⥪� DLL, �ᯮ�����饩 �㭪�� �� �� ��뢠���

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

