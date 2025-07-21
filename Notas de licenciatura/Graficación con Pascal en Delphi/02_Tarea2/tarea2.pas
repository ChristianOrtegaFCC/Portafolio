unit tarea2;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.ExtCtrls, Vcl.StdCtrls;

type
  TForm1 = class(TForm)
    Label1: TLabel;
    Panel1: TPanel;
    Image1: TImage;
    Edit1: TEdit;
    Label2: TLabel;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Edit2: TEdit;
    Edit3: TEdit;
    Edit4: TEdit;
    Edit5: TEdit;
    Edit6: TEdit;
    Edit7: TEdit;
    Edit8: TEdit;
    Edit9: TEdit;
    Edit10: TEdit;
    Edit11: TEdit;
    Edit12: TEdit;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Label7: TLabel;
    Label8: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label11: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Button5: TButton;
    Label14: TLabel;
    Button6: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
var i ,max,bandNeg,pos: integer;
a1 : string;
A : array [1..12] of integer;
begin
bandNeg := 0;
A[1] := strtoint(edit1.text);
A[2] := strtoint(edit2.text);
A[3] := strtoint(edit3.text);
A[4] := strtoint(edit4.text);
A[5] := strtoint(edit5.text);
A[6] := strtoint(edit6.text);
A[7] := strtoint(edit7.text);
A[8] := strtoint(edit8.text);
A[9] := strtoint(edit9.text);
A[10] := strtoint(edit10.text);
A[11] := strtoint(edit11.text);
A[12] := strtoint(edit12.text);
Max := A[1];

for i := 1 to 11 do if A[i+1] > Max then Max := A[i+1];
for i := 1 to 12 do if A[i] < 0 then bandNeg := 1 ;

if bandNeg = 1 then
  showmessage('no puede haber valores negativos... sonso') // hay numeros negativos
else
begin
  if max = 0 then showmessage('Todos los meses tienen 0') // hay puro cero
  else
  begin // todos los numeros son trabajables
    a1 := Concat('El numero maximo es: ', inttostr(max));
    showmessage(a1);

    Image1.Canvas.TextOut(5,1,inttostr(max));
    Image1.Canvas.TextOut(5,119,inttostr(round(max*0.75)));
    Image1.Canvas.TextOut(5,244,inttostr(round(max*0.50)));
    Image1.Canvas.TextOut(5,369,inttostr(round(max*0.25)));
    Image1.Canvas.TextOut(5,486,'0');
    for i := 1 to 12 do // for para los rectangulos:
    begin
      if i = 1 then image1.canvas.brush.color := $00002D77;
      if i = 2 then image1.canvas.brush.color := clred;
      if i = 3 then image1.canvas.brush.color := $00034EFC;
      if i = 4 then image1.canvas.brush.color := $0004C5F4;
      if i = 5 then image1.canvas.brush.color := clyellow;
      if i = 6 then image1.canvas.brush.color := $0080B748;
      if i = 7 then image1.canvas.brush.color := clgreen;
      if i = 8 then image1.canvas.brush.color := $00C78791;
      if i = 9 then image1.canvas.brush.color := $0048F47C7;
      if i = 10 then image1.canvas.brush.color := clpurple;
      if i = 11 then image1.canvas.brush.color := clblue;
      if i = 12 then image1.canvas.brush.color := $00F1E6A0;

      image1.canvas.Rectangle( 25 + ((i-1)*57) , 499 , (25 + ((i-1)*57)) + 37 , 500 -  round ( 500*A[i] / max ) );

      image1.canvas.brush.color := clwhite;
      Image1.Canvas.TextOut( 37 + ((i-1)*57) , 486 -  round ( 500*A[i] / max ) ,inttostr(A[i]));

    end;
    image1.canvas.pen.color := clblack;
    image1.canvas.brush.color := clwhite;
  end;
end;

end;


procedure TForm1.Button2Click(Sender: TObject);
begin
edit1.text := '0';
edit2.text := '0';
edit3.text := '0';
edit4.text := '0';
edit5.text := '0';
edit6.text := '0';
edit7.text := '0';
edit8.text := '0';
edit9.text := '0';
edit10.text := '0';
edit11.text := '0';
edit12.text := '0';

image1.canvas.pen.color := clgreen;
image1.canvas.Rectangle(0,0,700,500) ;
image1.canvas.pen.color := clblack;
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
showmessage('Amador Ortega Christian Amauri | 16aoca@gmail.com | FCC   BUAP');
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
Application.Terminate;
end;

procedure TForm1.Button5Click(Sender: TObject);
var i : integer;
begin
edit1.text := ':^)';
edit2.text := ':^)';
edit3.text := ':^)';
edit4.text := ':^)';
edit5.text := ':^)';
edit6.text := ':^)';
edit7.text := ':^)';
edit8.text := ':^)';
edit9.text := ':^)';
edit10.text := ':^)';
edit11.text := ':^)';
edit12.text := ':^)';
Image1.Canvas.TextOut(5,1,':^)');
Image1.Canvas.TextOut(5,119,':^)');
Image1.Canvas.TextOut(5,244,':^)');
Image1.Canvas.TextOut(5,369,':^)');
Image1.Canvas.TextOut(5,486,':^)');
for i  := 1 to 10 do
  begin
    showmessage(':^)');
  end;
end;

procedure TForm1.Button6Click(Sender: TObject);
begin
edit1.text := '25';
edit2.text := '50';
edit3.text := '75';
edit4.text := '0';
edit5.text := '33';
edit6.text := '60';
edit7.text := '100';
edit8.text := '60';
edit9.text := '48';
edit10.text := '47';
edit11.text := '99';
edit12.text := '10';
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
image1.canvas.pen.color := clgreen;
image1.canvas.Rectangle(0,0,700,500);
image1.canvas.pen.color := clblack

end;

end.
