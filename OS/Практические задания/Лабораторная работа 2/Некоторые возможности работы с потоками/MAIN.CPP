//---------------------------------------------------------------------------
#include <vcl.h>
#include <tlhelp32.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

DWORD WINAPI NewThreadStartProc (LPVOID);
const int N = 20;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet1Show(TObject *Sender)
{
   HANDLE hSnap = CreateToolhelp32Snapshot (TH32CS_SNAPALL, 0);
   ListBox1->Clear();

   PROCESSENTRY32 prc;
   prc.dwSize = sizeof (PROCESSENTRY32);
   if (!Process32First (hSnap, &prc)) return;
   do
   {
     PROCESSENTRY32* tmp = new PROCESSENTRY32;
     CopyMemory (tmp, &prc, sizeof (prc));
     ListBox1->Items->AddObject (prc.szExeFile, (TObject*)tmp);
   } while (Process32Next (hSnap, &prc));
   CloseHandle(hSnap);
   ListBox1->ItemIndex = 0;
   ListBox1Click (this);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TabSheet2Show(TObject *Sender)
{
   HANDLE hSnap = CreateToolhelp32Snapshot (TH32CS_SNAPALL, 0);
   ListBox2->Clear();

   THREADENTRY32 thd;
   thd.dwSize = sizeof (THREADENTRY32);
   if (!Thread32First (hSnap, &thd)) return;
   do
   {
     THREADENTRY32* tmp = new THREADENTRY32;
     CopyMemory (tmp, &thd, sizeof (thd));
     ListBox2->Items->AddObject (IntToHex ((int)thd.th32ThreadID, 8), (TObject*)tmp);
   } while (Thread32Next (hSnap, &thd));
   CloseHandle(hSnap);
   ListBox2->ItemIndex = 0;
   ListBox2Click (this);

}

//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
   PROCESSENTRY32 prc = *((PROCESSENTRY32*)(ListBox1->Items->Objects[ListBox1->ItemIndex]));
   Label1->Caption = "Размер структуры PROCESSENTRY32: " + IntToStr (prc.dwSize) + " байт";
   Label2->Caption = "Количество потоков в процессе: " + IntToStr (prc.cntThreads);
   Label3->Caption = "Количество ссылок на объект ядра: " + IntToStr (prc.cntUsage);
   Label4->Caption = "Класс приоритета процесса: " + IntToStr ((int)prc.pcPriClassBase);
   Label5->Caption = "ID процесса: " + IntToHex ((int)prc.th32ProcessID,8);
   Label6->Caption = "ID родительского процесса: " + IntToHex ((int)prc.th32ParentProcessID,8);
   Label7->Caption = "ID модуля процесса: " + IntToHex ((int)prc.th32ModuleID,8);
   Label8->Caption = "Дескриптор основной кучи процесса: " + IntToHex ((int)prc.th32DefaultHeapID,8);
   Label9->Caption = "Флаги процесса: " + IntToHex ((int)prc.dwFlags,8);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListBox2Click(TObject *Sender)
{
   THREADENTRY32 thd = *((THREADENTRY32*)(ListBox2->Items->Objects[ListBox2->ItemIndex]));
   Label10->Caption = "Размер структуры THREADENTRY32: " + IntToStr (thd.dwSize) + " байт";
   Label11->Caption = "Количество ссылок на объект ядра: " + IntToStr (thd.cntUsage);
   Label12->Caption = "ID потока: " + IntToHex ((int)thd.th32ThreadID,8);
   Label13->Caption = "ID процесса-владельца: " + IntToHex ((int)thd.th32OwnerProcessID,8);
   Label14->Caption = "Базовый приоритет потока: " + IntToStr ((int)thd.tpBasePri);
   Label15->Caption = "Дельта приоритета потока: " + IntToStr ((int)thd.tpDeltaPri);
   Label16->Caption = "Флаги процесса: " + IntToHex ((int)thd.dwFlags,8);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  if (!ListBox1->ItemIndex == -1) return;

  PROCESSENTRY32 prc = *((PROCESSENTRY32*)(ListBox1->Items->Objects[ListBox1->ItemIndex]));
  HANDLE ps = OpenProcess (PROCESS_ALL_ACCESS, NULL, prc.th32ProcessID);

  if (ps && (TerminateProcess(ps, -9)) )
      ShowMessage ("Процесс успешно завершен!");
  else
      ShowMessage ("Невозможно завершить процесс!");

  TabSheet1Show (this);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  if (!OpenDialog1->Execute()) return;

  si.cb = sizeof (STARTUPINFO);
  si.lpReserved  = NULL;
  si.lpDesktop   = NULL;
  si.lpTitle      = NULL;
  si.dwFlags      = STARTF_USESHOWWINDOW;
  si.cbReserved2 = 0;
  si.lpReserved2 = NULL;
  si.wShowWindow = SW_SHOWMINIMIZED;


  if (!CreateProcess (NULL, OpenDialog1->FileName.c_str(), NULL, NULL, FALSE,
                      0, NULL, NULL, &si, &pi))
  {
      Application->MessageBox ("Не могу создать процесс", "ОШИБКА!!!", MB_OK | MB_ICONERROR);
      return;
  }

  TabSheet1Show (this);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
   DWORD tid;
   CreateThread (NULL, 0, NewThreadStartProc, NULL, 0,  &tid);
   TabSheet2Show (this);
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  count--;
  Label18->Caption = IntToStr (count);
}


//---------------------------------------------------------------------------
DWORD WINAPI NewThreadStartProc (LPVOID)
{
  Form1->count = N;
  Form1->Label17->Visible = true;
  Form1->Label18->Caption = IntToStr (Form1->count);
  Form1->Label18->Visible = true;
  Form1->Timer1->Enabled = true;

  while (1)
  {
    if (Form1->count == 0) break;
  }

  Form1->Timer1->Enabled = false;
  Form1->Label17->Visible = false;
  Form1->Label18->Visible = false;

  return 1;
}

