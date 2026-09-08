program tarea3ex;

uses
  Vcl.Forms,
  tarea3 in 'tarea3.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
