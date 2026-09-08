unit Unit1;

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
    Button6: TButton;
    Button7: TButton;
    Button8: TButton;
    Button9: TButton;
    Button10: TButton;
    procedure FormCreate(Sender: TObject);
    procedure Button8Click(Sender: TObject);
    procedure Button7Click(Sender: TObject);
    procedure Button5Click(Sender: TObject);
    procedure Button6Click(Sender: TObject);
    procedure Button1Click(Sender: TObject);
    procedure Button3Click(Sender: TObject);
    procedure Button2Click(Sender: TObject);
    procedure Button4Click(Sender: TObject);
    procedure Button9Click(Sender: TObject);
    procedure Button10Click(Sender: TObject);
  private
    { Private declarations }
  public
    { Public declarations }
  end;
   // Definición de TPoint3D
type
TPoint3D = packed record
x: Real;
y: Real;
z: Real;
end;
// Definición de constantes
const
TamFig = 1;
// Definición de variables
// globales
var
Cubo : Array[1..10] of TPoint3D;   //Definición del Cubo
P, Q : TPoint;  //Variables para pintar en pantalla.
xAux, yAux, zAux,OjoAObjeto,D : Real;  //Variables auxiliares para la rotación.
var
  Form1: TForm1;

implementation

{$R *.dfm}

procedure TForm1.Button10Click(Sender: TObject);
begin
OjoAObjeto := OjoAObjeto/1.10;
  Button7Click(Sender);
end;

procedure TForm1.Button1Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rx a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
yAux := (Cubo[i].y * COS( -alfa )) + (Cubo[i].z * SIN( -alfa ));
zAux := -(Cubo[i].y * SIN( -alfa )) + (Cubo[i].z * COS( -alfa ));
Cubo[i].y := yAux;
Cubo[i].z := zAux;

end;
Button7Click(Sender);
end;


procedure TForm1.Button2Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rx a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
yAux := (Cubo[i].y * COS( alfa )) + (Cubo[i].z * SIN( alfa ));
zAux := -(Cubo[i].y * SIN( alfa )) + (Cubo[i].z * COS( alfa ));
Cubo[i].y := yAux;
Cubo[i].z := zAux;

end;
Button7Click(Sender);
end;

procedure TForm1.Button3Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rz a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
xAux := (Cubo[i].x * COS( -alfa )) + (Cubo[i].z * SIN( -alfa ));
zAux := -(Cubo[i].x * SIN( -alfa )) + (Cubo[i].z * COS( -alfa ));
Cubo[i].x := xAux;
Cubo[i].z := zAux;
end;
Button7Click(Sender)
end;

procedure TForm1.Button4Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rz a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
xAux := (Cubo[i].x * COS( alfa )) + (Cubo[i].z * SIN( alfa ));
zAux := -(Cubo[i].x * SIN( alfa )) + (Cubo[i].z * COS( alfa ));
Cubo[i].x := xAux;
Cubo[i].z := zAux;
end;
Button7Click(Sender)
end;

procedure TForm1.Button5Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rz a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
xAux := (Cubo[i].x * COS( -alfa )) + (Cubo[i].y * SIN( -alfa ));
yAux := -(Cubo[i].x * SIN( -alfa )) + (Cubo[i].y * COS( -alfa ));
Cubo[i].x := xAux;
Cubo[i].y := yAux;
end;
Button7Click(Sender);
end;

procedure TForm1.Button6Click(Sender: TObject);
Var
i: integer;
alfa : Real;
begin
// Aplica la Rotación Rz a todos los puntos del Cubo.
// El ángulo esta determinado por alfa
alfa := (5*Pi) / 180.0; // Grados a radianes
for i := 1 to 10 do
begin
xAux := (Cubo[i].x * COS( alfa )) + (Cubo[i].y * SIN( alfa ));
yAux := -(Cubo[i].x * SIN( alfa )) + (Cubo[i].y * COS( alfa ));
Cubo[i].x := xAux;
Cubo[i].y := yAux;
end;
Button7Click(Sender);
end;

procedure TForm1.Button7Click(Sender: TObject);

// (x, y, z) en 3D y (xP, yP) en 2D
//
procedure Perspectiva( x, y, z: Real; var xP, yP : Integer );
var
xAux, yAux, zAux : Real;
begin
zAux := z + OjoAObjeto;
xAux := (x * D) / zAux;
xP := Round(xAux) + 250;
yAux := (y * D) / zAux;
yP := Round(yAux) + 250;
end;

var
i: integer;
begin
Image1.canvas.Rectangle(0,0,500,500);
  // Pinta el Piso del Cubo
for i := 1 to 4 do
  begin
  Perspectiva( Cubo[i].x, Cubo[i].y, Cubo[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Cubo[i+1].x, Cubo[i+1].y, Cubo[i+1].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clBlue;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
    // Pinta el Techo del Cubo
for i := 6 to 9 do
  begin
  Perspectiva( Cubo[i].x, Cubo[i].y, Cubo[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Cubo[i+1].x, Cubo[i+1].y, Cubo[i+1].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clRed;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
    // Pinta el Paredes del Cubo (Aristas)
for i := 1 to 4 do
  begin
  Perspectiva( Cubo[i].x, Cubo[i].y, Cubo[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Cubo[i+5].x, Cubo[i+5].y, Cubo[i+5].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clGreen;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
end;


procedure TForm1.Button8Click(Sender: TObject);
begin
close();
end;

procedure TForm1.Button9Click(Sender: TObject);
begin
OjoAObjeto := OjoAObjeto*1.10;
  Button7Click(Sender);
end;

procedure TForm1.FormCreate(Sender: TObject);
var
  I: Integer;
begin
Image1.canvas.Rectangle(0,0,500,500);
// Piso del Cubo, note que Cubo[1] = Cubo[5]
Cubo[1].x := +TamFig; Cubo[1].y := +TamFig; Cubo[1].z := -TamFig;
Cubo[2].x := +TamFig; Cubo[2].y := -TamFig; Cubo[2].z := -TamFig;
Cubo[3].x := -TamFig; Cubo[3].y := -TamFig; Cubo[3].z := -TamFig;
Cubo[4].x := -TamFig; Cubo[4].y := +TamFig; Cubo[4].z := -TamFig;
Cubo[5].x := +TamFig; Cubo[5].y := +TamFig; Cubo[5].z := -TamFig;
  //Techo del Cubo, note que Cubo[6]=Cubo[10]
Cubo[6].x := +TamFig; Cubo[6].y := +TamFig; Cubo[6].z := +TamFig;
Cubo[7].x := +TamFig; Cubo[7].y := -TamFig; Cubo[7].z := +TamFig;
Cubo[8].x := -TamFig; Cubo[8].y := -TamFig; Cubo[8].z := +TamFig;
Cubo[9].x := -TamFig; Cubo[9].y := +TamFig; Cubo[9].z := +TamFig;
Cubo[10].x := +TamFig; Cubo[10].y := +TamFig; Cubo[10].z := +TamFig;
//variables de proyeccion perspectiva
OjoAObjeto := 40*4;
D := 40*2;
//Transformación de escala
for I := 1 to 10 do
  begin
    Cubo[i].x := Cubo[i].x * 40;
    Cubo[i].y := Cubo[i].y * 40;
    Cubo[i].z := Cubo[i].z * 40;
  end;


end;

end.
