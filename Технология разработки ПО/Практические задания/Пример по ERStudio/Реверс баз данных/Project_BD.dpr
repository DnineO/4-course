program Project_BD;

uses
  Forms,
  Unit_BD in 'Unit_BD.pas' {Form1},
  Unit_BD2 in 'Unit_BD2.pas' {Form2};

{$R *.RES}

begin
  Application.Initialize;
  Application.CreateForm(TForm1, Form1);
  Application.CreateForm(TForm2, Form2);
  Application.Run;
end.
