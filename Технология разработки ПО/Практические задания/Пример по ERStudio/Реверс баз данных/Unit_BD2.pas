unit Unit_BD2;

interface

uses
  Windows, Messages, Classes, SysUtils, Graphics, Controls, StdCtrls, Forms,
  Dialogs, DBCtrls, DB, DBTables, Mask, ExtCtrls;

type
  TForm2 = class(TForm)
    Table1Tovar: TStringField;
    Table1EdIzm: TStringField;
    Table1Zena: TIntegerField;
    ScrollBox: TScrollBox;
    Label1: TLabel;
    EditTovar: TDBEdit;
    Label2: TLabel;
    EditEdIzm: TDBEdit;
    Label3: TLabel;
    EditZena: TDBEdit;
    DBNavigator: TDBNavigator;
    Panel1: TPanel;
    DataSource1: TDataSource;
    Panel2: TPanel;
    Table1: TTable;
    procedure FormCreate(Sender: TObject);
  private
    { private declarations }
  public
    { public declarations }
  end;

var
  Form2: TForm2;

implementation

{$R *.DFM}

procedure TForm2.FormCreate(Sender: TObject);
begin
  Table1.Open;
end;

end.