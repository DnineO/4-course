/************************************************************************
                          ������ୠ� ࠡ�� N1

                                �ਬ�� 2.

                              HELLOWIN2.CPP

                        ��ઠ᭮� �ਫ������ Windows

************************************************************************/
#include <windows.h>    // ������砥� ���ᠭ�� �㭪権 API, �⠭������ ⨯��
                        // Windows � �.�.

/*  ����뢠�� ���⨯ ������� �㭪樨 (����� ��� ���뢠���� WndProc).
    ��� �����頥���� ���祭��: LRESULT CALLBACK (�㭪�� ���⭮�� �맮��).
    ��ࠬ����: ���ਯ�� ����, ���஬� �ਭ������� �㭪��,
               �����䨪��� ᮮ�饭��, ��।������ �㭪樨,
               ��ࠬ���� ᮮ�饭�� (WPARAM � LPAPAM).
*/


LRESULT CALLBACK WndProc (HWND, UINT, WPARAM, LPARAM);


/* ���ᠭ�� �㭪樨 WinMain():
   ��� �����頥���� ���祭�� - WINAPI,
   ��ࠬ����:
              HINSTANCE hInst - ���ਯ�� ⥪�饣� ������� �ਫ������,
              HINSTANCE       - �� �ᯮ������ (�ᥣ�� NULL)
              LPSTR           - ��ࠬ���� ��������� ��ப�
              int             - ०�� ������ ����  

   � ������ ��砥 �ᯮ������ ⮫쪮 ���� ��ࠬ���, ���⮬� �� �����
   ᮡ�⢥���� �������� hInst. ��稥 ��ࠬ���� �� �ᯮ�������.
*/

WINAPI WinMain (HINSTANCE hInst, HINSTANCE, LPSTR, int)
{
   WNDCLASS wcl;        // ������� ��� ����� ����
   MSG      msg;        // ������� ��� �࠭���� ��।������ ᮮ�饭��
   HWND     wnd;        // ���ਯ�� ����


   // ���������� �������� WNDCLASS - ᮧ����� ����� ����

   wcl.style  = 0;                // �⨫� ���� - �� 㬮�砭��
   wcl.lpfnWndProc = WndProc;     // ������� �㭪樥� �����砥��� WndProc
   wcl.hInstance  = hInst;        // ���ਯ�� �ਫ������
   wcl.hCursor = LoadCursor( NULL, IDC_ARROW);  // ��ଠ ����� � ����
   wcl.hIcon = LoadIcon (NULL, IDI_APPLICATION);  // ������ �ਫ������      
   wcl.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);  // ���� 䮭�      
   wcl.lpszMenuName = NULL;                     // �������� ���� ��� (NULL)
   wcl.lpszClassName = "First";            // ��� ����� ����
   wcl.cbClsExtra = wcl.cbWndExtra = 0; // �������⥫�� ��ࠬ���� (�� �����窨)


   if (!RegisterClass (&wcl)) return 0;   // ��������� ����� ����

   // �������� ����
   wnd  = CreateWindow
   (
     "First",                   // ����� ����
     "Hello, Windows!",         // ����� � ��������� ����
     WS_OVERLAPPEDWINDOW,       // �⨫� - ���筮� ���� �  ࠬ���
     CW_USEDEFAULT, CW_USEDEFAULT,  // ���न���� � ࠧ���� ���� - �� 㬮�砭��
     CW_USEDEFAULT, CW_USEDEFAULT,
     NULL, NULL,           // ����⥫�᪮�� ���� � �������� ���� ���
     hInst,           // ���� �ਭ������� �ਫ������ � ���ਯ�஬ hInst     
     NULL);           // �������⥫��� ��ࠬ��஢ ���  

   ShowWindow (wnd, SW_SHOW);           // ����� ᮧ������� ����


   /*
      ����� 横�� ��ࠡ�⪨ ᮮ�饭��
      ���� �믮������ �� �� ���, ���� �㭪�� GetMessage(), �롨����
      ᮮ�饭�� �� ��।� ᮮ�饭�� �ਫ������, �� ������ ᮮ�饭�� WM_QUIT,
      ᨣ���������饥 � �����襭�� ࠡ���. � �⮬ ��砥 GetMessage()
      �����頥� 0, � 横� �����蠥���. ����� 横�� �ந�室�� �࠭����
      ���㠫��� ����� ������ ���।�⢮� �맮�� TranslateMessage (), ��⥬
      �㭪�� DispatchMessage () ��।��� ��ࠡ�⠭��� ᮮ�饭�� ���⭮ 
      Windows, ����� ��뢠�� ��⠭�������� �� ॣ����樨 ����� ����
      callback-�㭪�� (� ������ ��砥 - WndProc). 
   */

   while (GetMessage (&msg, NULL, 0, 0))
   {
       TranslateMessage (&msg);
       DispatchMessage (&msg);
   }
  
   return msg.wParam;
}


/*
    ������� �㭪�� ���������� ��।����� � ��ࠬ��� MSG ᮮ�饭��.
    �᫨ ����㯨�� ᮮ�饭�� WM_DESTROY (�뫮 ��࠭� �����⨥ ����),
    � ����室��� ��ࠢ��� ᯥ樠�쭮� ᮮ�饭�� � �����襭�� ࠡ���
    �맮��� PostQuitMessage(). �� ��稥 ᮮ�饭�� ��ࠡ��뢠���� ��
    㬮�砭�� ᠬ�� ����樮���� ��⥬��. ��� �⮣� ��� ��।����� �
    Windows ���।�⢮� �맮�� DefWindowProc().
*/
LRESULT CALLBACK WndProc (HWND wnd, UINT msg, WPARAM wp, LPARAM lp)
{
   switch( msg )
   {

      case WM_DESTROY:
         PostQuitMessage(0);
         return 0;

      default:
         return DefWindowProc( wnd, msg, wp, lp );

   }
}

