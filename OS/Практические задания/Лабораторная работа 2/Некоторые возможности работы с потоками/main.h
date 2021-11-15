//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TListBox *ListBox1;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TListBox *ListBox2;
        TPanel *Panel2;
        TLabel *Label10;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TLabel *Label15;
        TLabel *Label16;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TOpenDialog *OpenDialog1;
        TBitBtn *BitBtn3;
        TTimer *Timer1;
        TLabel *Label17;
        TLabel *Label18;
        void __fastcall TabSheet1Show(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall TabSheet2Show(TObject *Sender);
        void __fastcall ListBox2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations

public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        DWORD count;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
