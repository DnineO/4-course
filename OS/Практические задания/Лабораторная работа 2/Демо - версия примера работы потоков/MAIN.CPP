//---------------------------------------------------------------------------
#include <vcl.h>
#include <process.h>
#pragma hdrstop

#include "main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CGAUGES"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

int N = 5;

bool flag = false;

unsigned int __stdcall Start1 (void*)
{
   for (int j = 0; j < N; j++)  flag = false;
   for (int i = 1; i <= Form1->CGauge1->MaxValue; i++) Form1->CGauge1->Progress = i;

   HANDLE h =OpenEvent (NULL, NULL, "MYEVENT");
   SetEvent (h);
   return 0;
}

unsigned int __stdcall Start2 (void* ptr)
{
   for (int j = 0; j < N; j++)  flag = true;
   for (int i = 1; i <= (int)ptr; i++) Form1->CGauge2->Progress = i;
   return 0;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
   int n = Form1->CGauge2->MaxValue;
   HANDLE h = CreateEvent (NULL, FALSE, FALSE, "MYEVENT");

   DWORD thd1 = _beginthreadex (NULL, 1024*1024, Start1, NULL, 0, NULL);
   DWORD thd2 = _beginthreadex (NULL, 1024*1024, Start2, (void*)n, 0, NULL);

   SetThreadPriority ((HANDLE)thd1,THREAD_PRIORITY_ABOVE_NORMAL);
   SetThreadPriority ((HANDLE)thd2/*GetCurrentThread()*/,THREAD_PRIORITY_HIGHEST);


   if (WaitForSingleObject (h, 15) == WAIT_OBJECT_0)
   {
     ShowMessage ("Thread 1 done!"+IntToStr (flag));
     ResetEvent (h);
   }


}
//---------------------------------------------------------------------------
