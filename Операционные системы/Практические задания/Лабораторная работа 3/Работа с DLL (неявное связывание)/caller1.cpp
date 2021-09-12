/************************************************************************
                          Лабораторная работа N3

                                Пример 1.

                               CALLER.CPP

       Тестовая программа для вызова функции из DLL (неявное связывание)

************************************************************************/
#include <windows.h>

extern LPSTR Test (void);

WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{
    LPSTR str = Test ();        // Вызов функции из DLL
    return MessageBox (NULL, str, "Вызов из DLL!", MB_OK | MB_ICONEXCLAMATION);
}

