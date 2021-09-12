unit Unit_BD;

interface

uses
  Windows, Messages, SysUtils, Classes, Graphics, Controls, Forms, Dialogs,
  Grids, DBGrids, Db, DBTables, StdCtrls, Buttons, DBCtrls, Mask;

type
  TForm1 = class(TForm)
    Table1: TTable;
    DataSource1: TDataSource;
    DBGrid1: TDBGrid;
    Table2: TTable;
    DataSource2: TDataSource;
    DBGrid2: TDBGrid;
    BitBtn1: TBitBtn;
    Table2Tovar: TStringField;
    Table2DatPrih: TDateField;
    Table2Kolvo: TIntegerField;
    DBEdit1: TDBEdit;
    DBEdit2: TDBEdit;
    DBLookupComboBox1: TDBLookupComboBox;
    InsertButton: TButton;
    EditButton: TButton;
    DeleteButton: TButton;
    PostButton: TButton;
    CancelButton: TButton;
    Button1: TButton;
    procedure InsertButtonClick(Sender: TObject);
    procedure EditButtonClick(Sender: TObject);
    procedure DeleteButtonClick(Sender: TObject);
    procedure PostButtonClick(Sender: TObject);
    procedure CancelButtonClick(Sender: TObject);
    procedure Button1Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation
 uses unit_BD2;
{$R *.DFM}

//��������
procedure TForm1.InsertButtonClick(Sender: TObject);
begin
//���� ����� ������ ������ � �������� ��� ���������
if Table2.State=dsBrowse
        then
        Table2.Insert;
end;

//��������
procedure TForm1.EditButtonClick(Sender: TObject);
begin
//���� ����� ������ ������ � �������� ��� ���������
if Table2.State=dsBrowse
        then
        Table2.Edit;
end;

//�������
procedure TForm1.DeleteButtonClick(Sender: TObject);
begin
//���� ����� ������ ������ � �������� ��� ���������
if Table2.State=dsBrowse
        then
        if MessageDlg('������� ������?',mtConfirmation,[mbYes,mbNo],0)=mrYes
                then
                Table2.Delete;
end;

//���������
procedure TForm1.PostButtonClick(Sender: TObject);
begin
//���� ����� ������ ���������� � ������ ��������������
//��� ���������� ����� ������
if Table2.State in [dsInsert, dsEdit]
        then
        Table2.Post;
end;

//��������
procedure TForm1.CancelButtonClick(Sender: TObject);
begin
//���� ����� ������ ���������� � ������ ��������������
//��� ���������� ����� ������
if Table2.State in [dsInsert, dsEdit]
        then
        Table2.Cancel;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
form2.ShowModal;
end;

end.
