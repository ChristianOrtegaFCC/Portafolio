unit tarea1;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Label1: TLabel;
    Panel1: TPanel;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Panel2: TPanel;
    Panel3: TPanel;
    Label2: TLabel;
    Label3: TLabel;
    Label4: TLabel;
    Label5: TLabel;
    Label6: TLabel;
    Edit1: TEdit;
    Edit2: TEdit;
    Button6: TButton;
    Button7: TButton;
    Label8: TLabel;
    Button8: TButton;
    Label7: TLabel;
    Label10: TLabel;
    procedure FormCreate(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button8Click(Sender: TObject);
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
var a,b,Col,Ren,i: Integer;
var Max,Min,Dx,x,Fx: Real;
var auxcol, auxren : integer ;
begin
   label10.Caption := ('2*x*x');
   a := StrToInt(Edit1.Text);
   b := StrToInt(Edit2.Text);
   Max := 2*a*a;
   Min := Max;
   Dx := (b - a) / 250;

   //Calculo de ventana
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := 2*x*x;
      if (Fx > Max) then Max := Fx;
      if (Fx < min) then Min := Fx;
      x := x + Dx;
      end;

   //Mapeo
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := 2*x*x;
      Ren := Round(((250-0)/(Min - Max)) * (Fx - Max) + 0);
      Image1.Canvas.Pixels[Col, Ren] := clred;
      x := x + Dx;
      end;

      // ejes de la función en particular
      image1.canvas.pen.color := $ff32f9;
      auxcol := round( (a*250)/ (a-b) );
      if ((auxcol > -1) and (auxcol < 251)) then
      begin
      image1.canvas.moveto(auxcol,0);
      image1.canvas.lineto(auxcol,250);
      end;

      auxren := round ( (max*250) / (max-min));
      if ((auxren > -1) and (auxren < 251)) then
      begin
      image1.canvas.moveto(0,auxren);
      image1.canvas.lineto(250,auxren);
      end;
      image1.canvas.pen.color := clblack;

end;

procedure TForm1.Button2Click(Sender: TObject); // :^)
var a,b,Col,Ren: Integer;
var Max,Min,Dx,x,Fx: Real;
var auxcol, auxren: integer ;
begin
   label10.Caption := ('x*x*x');
   a := StrToInt(Edit1.Text);
   b := StrToInt(Edit2.Text);
   Max := a*a*a;
   Min := Max;
   Dx := (b - a) / 250;
   //Calculo de ventana
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := x*x*x;
      if (Fx > Max) then Max := Fx;
      if (Fx < Min) then Min := Fx;
      x := x + Dx;
      end;

   //Mapeo
   x := a;
   for Col := 250 to 500 do
      begin
      Fx := x*x*x;
      Ren := Round(((250-0)/(Min - Max)) * (Fx - Max) + 0);
      Image1.Canvas.Pixels[Col, Ren] := clblue;
      x := x + Dx;
      end;

      // ejes de la función en particular
      image1.canvas.pen.color := $ff32f9;
      auxcol := round( (a*250)/ (a-b) );
      if ((auxcol > -1) and (auxcol < 251)) then
      begin
      image1.canvas.moveto(auxcol+250,0);
      image1.canvas.lineto(auxcol+250,250);
      end;
      // :^)
      auxren := round ( (max*250) / (max-min));
      if ((auxren > -1) and (auxren < 251)) then
      begin
      image1.canvas.moveto(250,auxren);
      image1.canvas.lineto(500,auxren);
      end;
      image1.canvas.pen.color := clblack;

end;

procedure TForm1.Button3Click(Sender: TObject);
var a,b,Col,Ren: Integer;
var Max,Min,Dx,x,Fx : Real;
var auxcol, auxren : integer ;
begin
   label10.Caption := ('8*sin(x)');
   a := StrToInt(Edit1.Text);
   b := StrToInt(Edit2.Text);
   Max := 8*Sin(a);
   Min := Max;
   Dx := (b - a) / 250;
   //Calculo de ventana
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := 8*Sin(x);
      if (Fx > Max) then Max := Fx;
      if (Fx < Min) then Min := Fx;
      x := x + Dx;
      end;

   //Mapeo
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := 8*Sin(x);
      Ren := Round(((250-0)/(Min - Max)) * (Fx - Max) + 0);
      Image1.Canvas.Pixels[Col, Ren+250] := clgreen;
      x := x + Dx;
      end;

      // ejes de la función en particular
      image1.canvas.pen.color := $ff32f9;
      auxcol := round( (a*250)/ (a-b) );
      if ((auxcol > -1) and (auxcol < 251)) then
      begin
      image1.canvas.moveto(auxcol,250);
      image1.canvas.lineto(auxcol,500);
      end;

      image1.canvas.moveto(0,375);
      image1.canvas.lineto(250,375);
      image1.canvas.pen.color := clblack;

end;

procedure TForm1.Button4Click(Sender: TObject);
var a,b,Col,Ren: Integer;
var Max,Min,Dx,x,Fx: Real;
var auxcol, auxren: integer ;
begin
   label10.Caption := ('-1*cos(x)');
   a := StrToInt(Edit1.Text);
   b := StrToInt(Edit2.Text);
   Max := -1*Cos(a);
   Min := Max;
   Dx := (b - a) / 250;
   //Calculo de ventana
   x := a;
   for Col := 1 to 250 do
      begin
      Fx := -1*Cos(x);
      if (Fx > Max) then Max := Fx;
      if (Fx < Min) then Min := Fx;
      x := x + Dx;
      end;

   //Mapeo
   x := a;
   for Col := 250 to 500 do
      begin
      Fx := -1*Cos(x);
      Ren := Round(((250-0)/(Min - Max)) * (Fx - Max) + 0);
      Image1.Canvas.Pixels[Col, Ren+250] := $730075;//$810084;
      x := x + Dx;
      end;

      // ejes de la función en particular
      image1.canvas.pen.color := $ff32f9;
      auxcol := round( (a*250)/ (a-b) );
      if ((auxcol > -1) and (auxcol < 251)) then
      begin
      image1.canvas.moveto(auxcol+250,250);
      image1.canvas.lineto(auxcol+250,500);
      end;

      image1.canvas.moveto(250,375);
      image1.canvas.lineto(500,375);
      image1.canvas.pen.color := clblack;

end;

procedure TForm1.Button5Click(Sender: TObject);
var
  I : integer;
begin
Image1.Canvas.Rectangle(0,0,500,500);
for I := 0 to 500 do
begin
    Image1.canvas.pixels[0+I,250] := clblack;
    Image1.canvas.pixels[250,0+I] := clblack;
end;

end;

procedure TForm1.Button6Click(Sender: TObject);
begin
showmessage('Autor:           Christian Amauri Amador Ortega');
end;

procedure TForm1.Button7Click(Sender: TObject);
begin
Application.Terminate
end;

procedure TForm1.Button8Click(Sender: TObject);
var i : integer;
begin
Edit1.Text := (':^)');
Edit2.Text := (':^)');
for i := 1 to 10 do
  showmessage(':^)');

end;

procedure TForm1.FormCreate(Sender: TObject);
var
 I : integer;
begin
for I := 0 to 500 do
begin
    Image1.canvas.pixels[0+I,250] := clblack;
    Image1.canvas.pixels[250,0+I] := clblack;
end;
Edit1.Text := ('-2');
Edit2.Text := ('3');

end;

end.
