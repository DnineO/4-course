/************************************************************************
                          ������������ ������ N3

                                ������ 1.

                               CALLER.CPP

       �������� ��������� ��� ������ ������� �� DLL (������� ����������)

************************************************************************/
#include <windows.h>

extern LPSTR Test (void);

WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
    LPSTR str = Test ();        // ����� ������� �� DLL
    return MessageBox (NULL, str, "����� �� DLL!", MB_OK | MB_ICONEXCLAMATION);
}

