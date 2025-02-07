#include <windows.h>

// ��������� ����� ������� ��� ����� ���������� ���������� �� �� ���������,
// �� ��������� ��������� �� �������, ������� ��� �� ���, ��� � ������� 
// Test, ������� � ���� ������� ���������� �� DLL. � ������ ������ - ���������
// �� �������, ������������ LPCWSTR, � ����������� void. ��� ��������
// ����������� ������������� ��������� ��� ������ ���������, ������� ��� PFN.

typedef  LPCWSTR(*pfn) (void);

/* ����������, ����������� ����� ���������� DLL, ������ ��������� ���������
   ���� ��������:
   - �������� DLL (����� LoadLibrary())
   - ��������� ������ ������ ������� (����� GetProcAddress())
   - �������� DLL (����� FreeLibrary())

*/

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    // �������� DLL � ������ TESTDLL.DLL � �������� ������������ ��������
    // ���������� hMod �������� ������������  DLL
    HMODULE hMod = LoadLibrary(L"Dll.dll");

    // ���� ���������� ����������� DLL = NULL, ������ �������� �� �������
    if (!hMod)
        return MessageBox(NULL, L"������ �������� testdll.dll!\n", L"������!", MB_OK | MB_ICONEXCLAMATION);

    /* ��������� ������ �������. �� DLL � ������������ hMod, �.�. � ������
       ������ TESTDLL.DLL ���������� ����� ������� � ������ Test (��. TESTDLL.CPP).
       �����, �� �������� ����������� �������, ��������� � ���������� ADDR.
    */
    pfn addr = (pfn)GetProcAddress(hMod, "Test");

    // ���� ������� ������� �����, ������ ������� � ����� ������ �� �������
    // ��� ����������� � DLL
    if (!addr)
        return MessageBox(NULL, L"������ ��������� ������ �������!\n", L"������!", MB_OK | MB_ICONEXCLAMATION);

    // ����� ������� �� �� ������ � ��������� ������, ������� ���������� Test()
    LPCWSTR str = (*addr)();

    // �������������� �������� �� ����
    if (!str)
        return MessageBox(NULL, L"�������� ������ ������!\n", L"������!", MB_OK | MB_ICONEXCLAMATION);

    // ����� ������ �� ����� ��� ������������ ��������� ������  ������� 
    // Test() �� ���������� TESTDLL.DLL
    MessageBox(NULL, str, L"����� �� DLL!", MB_OK | MB_ICONEXCLAMATION);

    // �������� ����� �������� ���������� TESTDLL.DLL
    FreeLibrary(hMod);

    return 0;
}


