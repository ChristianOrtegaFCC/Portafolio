program tarea2ex;

uses
  Vcl.Forms,
  tarea2 in 'tarea2.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
