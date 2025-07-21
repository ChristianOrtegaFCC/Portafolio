program Z_The_Hard_Oneex;

uses
  Vcl.Forms,
  Z_The_Hard_One in 'Z_The_Hard_One.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
