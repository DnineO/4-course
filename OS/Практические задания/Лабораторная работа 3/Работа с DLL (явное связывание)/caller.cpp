/************************************************************************
                          Лабораторная работа N3

                                Пример 2.

                               CALLER.CPP

       Тестовая программа для вызова функции из DLL (явное связывание)

************************************************************************/
#include <windows.h>


typedef  LPSTR  (*pfn) (void);



WINAPI WinMain (HINSTANCE, HINSTANCE, LPSTR, int)
{

   HMODULE hMod = LoadLibrary ("testdll.dll");


   if (!hMod)
      return MessageBox (NULL, "Ошибка загрузки testdll.dll!\n", "ОШИБКА!", MB_OK | MB_ICONEXCLAMATION);


   pfn addr = (pfn)GetProcAddress (hMod, "_Test");

   if (!addr)
      return MessageBox (NULL, "Ошибка получения адреса функции!\n", "ОШИБКА!", MB_OK | MB_ICONEXCLAMATION);




   if (!str)
      return MessageBox (NULL, "Получена пустая строка!\n", "ОШИБКА!", MB_OK | MB_ICONEXCLAMATION);
   MessageBox (NULL, str, "Вызов из DLL!", MB_OK | MB_ICONEXCLAMATION);


   FreeLibrary (hMod);

   return 0;    
}

