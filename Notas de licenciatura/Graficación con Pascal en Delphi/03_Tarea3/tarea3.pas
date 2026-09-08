unit tarea3;

interface

uses
  Winapi.Windows, Winapi.Messages, System.SysUtils, System.Variants, System.Classes, Vcl.Graphics,
  Vcl.Controls, Vcl.Forms, Vcl.Dialogs, Vcl.StdCtrls, Vcl.ExtCtrls;

type
  TForm1 = class(TForm)
    Image1: TImage;
    Panel1: TPanel;
    Button1: TButton;
    Button2: TButton;
    Button3: TButton;
    Button4: TButton;
    Button5: TButton;
    Image2: TImage;
    Image3: TImage;
    Image4: TImage;
    Label1: TLabel;
    Label2: TLabel;
    Label3: TLabel;
    Timer1: TTimer;
    Edit1: TEdit;
    Button6: TButton;
    procedure Button2Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure FormCreate(Sender: TObject);
    procedure Button6Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;

var
  Form1: TForm1;
  ang1 , ang2, ang3, ang4 : real;
  god, buap,mexico,hongkong,j1 : TBitMap;
  H, M, s ,ms: word;

implementation

{$R *.dfm}

procedure TForm1.Button1Click(Sender: TObject);
begin
Timer1.Enabled := true;
end;

procedure TForm1.Button2Click(Sender: TObject);
begin
Timer1.Enabled := false;
showmessage('Amauri_Industries no se hace responsable del desface del reloj...');
end;

procedure TForm1.Button3Click(Sender: TObject);
begin
showmessage('Christian Amauri');
end;

procedure TForm1.Button4Click(Sender: TObject);
begin
Application.Terminate;
end;

procedure TForm1.Button5Click(Sender: TObject);
var
  x ,y : integer;
begin
Timer1.Enabled := false;
for x := 0 to 2 do begin
  for y := 0 to 2 do begin
    image1.Canvas.Draw(x*130,y*130,j1);
    image2.Canvas.Draw(x*130,y*130,j1);
  end;
end;
form1.Color := clred;
image3.Canvas.Draw(0,0,j1);
image4.Canvas.Draw(0,0,j1);
label1.Caption := '                :^) ';
label2.Caption := ':^) ';
label3.Caption := ':^) ';
edit1.text := ':^) ';
button1.Caption := ':^) ';
button2.Caption := ':^) ';
button3.Caption := ':^) ';
button4.Caption := ':^) ';
button6.Caption := ':^) ';
for x := 1 to 35 do showmessage(':^)');
end;


procedure TForm1.Button6Click(Sender: TObject);
begin
showmessage('En ambos relojes la manecilla roja marca la hora, la amarilla los minutos y la blanca los segundos');
showmessage('El horario en Hong kong está adelantado 13 horas con respecto al nuestro');
showmessage('Así que claro, mientras acá es AM, allá es PM y viceversa');
// vi estas la fikita plej bona homo kiu iam ajn vivis jajajajajajaj
end;

procedure TForm1.FormCreate(Sender: TObject);
begin
// kaj ni wortigos al la felica paro :^)
// la holokausto sajnos praktika serco
DecodeTime(time,H,M,S,Ms);
ang1 := 0-(s*6);
ang2 := 0-(m*6);
ang3 := 0-((h*30))- (m*0.48);
ang4 := 0-(((h+1)*30))- (m*0.48);
   mexico := TBitMap.Create;
   mexico.LoadFromFile('mexico.bmp');
   image1.Canvas.Draw(0,0,mexico);

   hongkong := TBitMap.Create;
   hongkong.LoadFromFile('hongkong.bmp');
   image2.Canvas.Draw(0,0,hongkong);

   buap := TBitMap.Create;
   buap.LoadFromFile('buap.bmp');
   image3.Canvas.Draw(0,0,buap);

   god := TBitMap.Create;
   god.LoadFromFile('god.bmp');
   image4.Canvas.Draw(0,0,god);

   j1 := TBitMap.Create;
   j1.LoadFromFile('Redemoji.bmp');
end;

procedure TForm1.Timer1Timer(Sender: TObject);
var
 seg : Array[1..4] of TPoint;
 min : Array[1..4] of TPoint;
 hor : Array[1..4] of TPoint;
 horhk : Array[1..4] of TPoint;

 I: Integer;
 xaux, yaux, alfa, beta, gamma,delta: real;
begin
Edit1.text := TimeToStr(Time) ;
 seg[1] := Point(-1,0);
 seg[2] := Point(0,1);
 seg[3] := Point(1,0);
 seg[4] := Point(0,-10);
Min[1] := Point(-1,0);
 Min[2] := Point(0,1);
 Min[3] := Point(1,0);
 Min[4] := Point(0,-8);
Hor[1] := Point(-1,0);
 Hor[2] := Point(0,1);
 Hor[3] := Point(1,0);
 Hor[4] := Point(0,-8);
Horhk[1] := Point(-1,0);
 Horhk[2] := Point(0,1);
 Horhk[3] := Point(1,0);
 Horhk[4] := Point(0,-8);

 alfa := (ang1*PI)/180.0;
 beta := (ang2*PI)/180.0;
 gamma :=  (ang3*PI)/180.0;
 delta := (ang4*PI)/180.0;
 for I := 1 to 4 do begin // escala
   seg[i].X := seg[i].x *14;
   seg[i].y := seg[i].Y *14;
   min[i].X := min[i].x *14;
   min[i].y := min[i].Y *14;
   hor[i].X := hor[i].x *12;
   hor[i].y := hor[i].Y *12;
   horhk[i].X := horhk[i].x *12;
   horhk[i].y := horhk[i].Y *12;
 end;

 for I := 1 to 4 do begin // rotación
   xaux := seg[i].X*cos(alfa) + seg[i].Y*sin(alfa);
   yaux := -seg[i].x*sin(alfa) + seg[i].Y*cos(alfa);
   seg[i].X :=Round (xaux);
   seg[i].y :=Round (yaux);

   xaux := min[i].X*cos(beta) + min[i].Y*sin(beta);
   yaux := -min[i].x*sin(beta) + min[i].Y*cos(beta);
   min[i].X :=Round (xaux);
   min[i].y :=Round (yaux);

   xaux := hor[i].X*cos(gamma) + hor[i].Y*sin(gamma);
   yaux := -hor[i].x*sin(gamma) + hor[i].Y*cos(gamma);
   hor[i].X :=Round (xaux);
   hor[i].y :=Round (yaux);

   xaux := horhk[i].X*cos(delta) + horhk[i].Y*sin(delta);
   yaux := -horhk[i].x*sin(delta) + horhk[i].Y*cos(delta);
   horhk[i].X :=Round (xaux);
   horhk[i].y :=Round (yaux);
 end;

 for I := 1 to 4 do begin //traslacion
   seg[i].X := seg[i].x +160;
   seg[i].y := seg[i].Y +160;
   min[i].X := min[i].x +160;
   min[i].y := min[i].Y +160;
   hor[i].X := hor[i].x +160;
   hor[i].y := hor[i].Y +160;
   horhk[i].X := horhk[i].x +160;
   horhk[i].y := horhk[i].Y +160;
 end;
// cu vi certas ke vi ne
// bezonas
// psikologon
// ?
 image1.Canvas.Draw(0,0,mexico);
 image1.Canvas.Polygon(seg);
 image1.Canvas.Brush.color := clyellow;
 image1.Canvas.Polygon(min);
 image1.Canvas.Brush.color := clred;
 image1.Canvas.Polygon(hor);
 image1.Canvas.Brush.color := clwhite;

 image2.Canvas.Draw(0,0,hongkong);
 image2.Canvas.Polygon(seg);
 image2.Canvas.Brush.color := clyellow;
 image2.Canvas.Polygon(min);
 image2.Canvas.Brush.color := clred;
 image2.Canvas.Polygon(horhk);
 image2.Canvas.Brush.color := clwhite;

 ang1 := ang1-6;
 ang2 := ang2-0.1;
 ang3 := ang3-0.0083333;
 ang4 := ang4-0.0083333;
end;

end.
