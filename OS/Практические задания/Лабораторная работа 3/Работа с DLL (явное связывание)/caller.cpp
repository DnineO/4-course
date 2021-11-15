/************************************************************************
                          ������������ ������ N3

                                ������ 2.

                               CALLER.CPP

       �������� ��������� ��� ������ ������� �� DLL (����� ����������)

************************************************************************/
#include <windows.h>


typedef  LPSTR  (*pfn) (void);



WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{

   HMODULE hMod = LoadLibrary ("testdll.dll");


   if (!hMod)
      return MessageBox (NULL, "������ �������� testdll.dll!\n", "������!", MB_OK | MB_ICONEXCLAMATION);


   pfn addr = (pfn)GetProcAddress (hMod, "_Test");

   if (!addr)
      return MessageBox (NULL, "������ ��������� ������ �������!\n", "������!", MB_OK | MB_ICONEXCLAMATION);




   if (!str)
      return MessageBox (NULL, "�������� ������ ������!\n", "������!", MB_OK | MB_ICONEXCLAMATION);
   MessageBox (NULL, str, "����� �� DLL!", MB_OK | MB_ICONEXCLAMATION);


   FreeLibrary (hMod);

   return 0;    
}

