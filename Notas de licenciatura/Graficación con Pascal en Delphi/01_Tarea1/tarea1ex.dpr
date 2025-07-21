program tarea1ex;

uses
  Vcl.Forms,
  tarea1 in 'tarea1.pas' {Form1};

{$R *.res}

begin
  Application.Initialize;
  Application.MainFormOnTaskbar := True;
  Application.CreateForm(TForm1, Form1);
  Application.Run;
end.
