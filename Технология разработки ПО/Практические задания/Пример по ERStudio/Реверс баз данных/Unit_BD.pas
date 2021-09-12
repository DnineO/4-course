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

//Добавить
procedure TForm1.InsertButtonClick(Sender: TObject);
begin
//если набор данных открыт и доступен для просмотра
if Table2.State=dsBrowse
        then
        Table2.Insert;
end;

//Изменить
procedure TForm1.EditButtonClick(Sender: TObject);
begin
//если набор данных открыт и доступен для просмотра
if Table2.State=dsBrowse
        then
        Table2.Edit;
end;

//Удалить
procedure TForm1.DeleteButtonClick(Sender: TObject);
begin
//если набор данных открыт и доступен для просмотра
if Table2.State=dsBrowse
        then
        if MessageDlg('Удалить запись?',mtConfirmation,[mbYes,mbNo],0)=mrYes
                then
                Table2.Delete;
end;

//Запомнить
procedure TForm1.PostButtonClick(Sender: TObject);
begin
//если набор данных находиться в режиме редактирования
//или добавления новой записи
if Table2.State in [dsInsert, dsEdit]
        then
        Table2.Post;
end;

//Отменить
procedure TForm1.CancelButtonClick(Sender: TObject);
begin
//если набор данных находиться в режиме редактирования
//или добавления новой записи
if Table2.State in [dsInsert, dsEdit]
        then
        Table2.Cancel;
end;

procedure TForm1.Button1Click(Sender: TObject);
begin
form2.ShowModal;
end;

end.
