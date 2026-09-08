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
    Label1: TLabel;
    Button11: TButton;
    Button12: TButton;
    OpenDialog1: TOpenDialog;
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
    procedure Button11Click(Sender: TObject);
    procedure Button12Click(Sender: TObject);
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
Piramide : Array[1..10] of TPoint3D;   //Definición del Cubo
P, Q : TPoint;  //Variables para pintar en pantalla.
xAux, yAux, zAux,OjoAObjeto,D : Real;  //Variables auxiliares para la rotación.
var
  Form1: TForm1;

implementation

{$R *.dfm}

// A C E R C A R [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.Button10Click(Sender: TObject);
begin
OjoAObjeto := OjoAObjeto/1.10;
  Button7Click(Sender);
end;

// A U T O R [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.Button11Click(Sender: TObject);
begin
Showmessage('Autor: Israel Hernández Gómez | 201927821 | FCC');
end;

// A B R I R   A R C H I V O [][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.Button12Click(Sender: TObject);
var
  I : integer;
  fl : TextFile ;
  aux1,aux2,aux3: integer ;
begin
  if (opendialog1.Execute) then begin
    Assignfile(fl, opendialog1.FileName);
    Reset(fl);
    I := 1;

    // se harán ajustes a los datos leídos para dar forma a la pirámide final
    // primero leemos los datos del archivo y los guardamos en priamide[I].xyz
    // para I := 1, piso
    // para I := 2, piso
    // para I := 3, piso
    // para I := 4, piso
    // para I := 5, punta

    // obtenemos los datos de entrada: !!!!
    while not EoF(fl) do begin
      Readln(fl,aux1,aux2,aux3);
      Piramide[I].x := aux1;
      Piramide[I].y := aux2;
      Piramide[I].z := aux3;
      I := I+1;
    end;

    // ajustamos a la configuración que necesitamos:  !!!!

    // ahora definimos la punta de la pirámide:
    // primero definimos piramide[6 -> 10] := piramide[5]; (porque
    // dijimos que para I:=5, correspondían los datos de la punta)

    // datos de la punta: !!!!
    for I := 6 to 10 do begin
      Piramide[I].x := Piramide[5].x;
      Piramide[I].y := Piramide[5].y;
      Piramide[I].z := Piramide[5].z;
    end;

    // finalmente, definimos pirámide[5] := piramide[1], para respetar la
    // configuración que usamos, es decir; para un polígono de n lados,
    // utilizamos n+1 puntos, en este caso la pirámide es de base cuadrada
    // entonces la base será definida con n+1 = 4+1 = 5 puntos, con
    // P[5] = P[1]

    // redefinición de la base de la pirámide: !!!!
    Piramide[5].x := Piramide[1].x;
    Piramide[5].y := Piramide[1].y;
    Piramide[5].z := Piramide[1].z;


    //mensaje de verificación
    Showmessage('Datos leídos :)');

    CloseFile(fl);
end;

end;

// R O T A R   X + [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
yAux := (Piramide[i].y * COS( -alfa )) + (Piramide[i].z * SIN( -alfa ));
zAux := -(Piramide[i].y * SIN( -alfa )) + (Piramide[i].z * COS( -alfa ));
Piramide[i].y := yAux;
Piramide[i].z := zAux;

end;
Button7Click(Sender);
end;

// R O T A R   X - [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
yAux := (Piramide[i].y * COS( alfa )) + (Piramide[i].z * SIN( alfa ));
zAux := -(Piramide[i].y * SIN( alfa )) + (Piramide[i].z * COS( alfa ));
Piramide[i].y := yAux;
Piramide[i].z := zAux;

end;
Button7Click(Sender);
end;

// R O T A R   Y + [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
xAux := (Piramide[i].x * COS( -alfa )) + (Piramide[i].z * SIN( -alfa ));
zAux := -(Piramide[i].x * SIN( -alfa )) + (Piramide[i].z * COS( -alfa ));
Piramide[i].x := xAux;
Piramide[i].z := zAux;
end;
Button7Click(Sender)
end;

// R O T A R   Y - [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
xAux := (Piramide[i].x * COS( alfa )) + (Piramide[i].z * SIN( alfa ));
zAux := -(Piramide[i].x * SIN( alfa )) + (Piramide[i].z * COS( alfa ));
Piramide[i].x := xAux;
Piramide[i].z := zAux;
end;
Button7Click(Sender)
end;

// R O T A R   Z + [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
xAux := (Piramide[i].x * COS( -alfa )) + (Piramide[i].y * SIN( -alfa ));
yAux := -(Piramide[i].x * SIN( -alfa )) + (Piramide[i].y * COS( -alfa ));
Piramide[i].x := xAux;
Piramide[i].y := yAux;
end;
Button7Click(Sender);
end;

// R O T A R   Z - [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
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
xAux := (Piramide[i].x * COS( alfa )) + (Piramide[i].y * SIN( alfa ));
yAux := -(Piramide[i].x * SIN( alfa )) + (Piramide[i].y * COS( alfa ));
Piramide[i].x := xAux;
Piramide[i].y := yAux;
end;
Button7Click(Sender);
end;

// P I N T A   C U B O [][][][][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.Button7Click(Sender: TObject);
// (x, y, z) en 3D y (xP, yP) en 2D
procedure Perspectiva( x, y, z: Real; var xP, yP : Integer );
var
xAux, yAux, zAux : Real;
begin
zAux := z + OjoAObjeto;
xAux := (x * D) / zAux;
xP := Round(xAux) + 200;
yAux := (y * D) / zAux;
yP := Round(yAux) + 200;
end;

var
i: integer;
begin
Image1.canvas.Rectangle(0,0,400,400);
  // Pinta el Piso del Cubo
for i := 1 to 4 do
  begin
  Perspectiva( Piramide[i].x, Piramide[i].y, Piramide[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Piramide[i+1].x, Piramide[i+1].y, Piramide[i+1].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clBlue;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
    // Pinta el Techo del Cubo
for i := 6 to 9 do
  begin
  Perspectiva( Piramide[i].x, Piramide[i].y, Piramide[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Piramide[i+1].x, Piramide[i+1].y, Piramide[i+1].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clRed;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
    // Pinta el Paredes del Cubo (Aristas)
for i := 1 to 4 do
  begin
  Perspectiva( Piramide[i].x, Piramide[i].y, Piramide[i].z, P.x, P.y ); //Encuentra P.x y P.y
  Perspectiva( Piramide[i+5].x, Piramide[i+5].y, Piramide[i+5].z, Q.x, Q.y );
  Image1.Canvas.Pen.Color := clGreen;
  Image1.Canvas.MoveTo(P.x, P.y);
  Image1.Canvas.LineTo(Q.x, Q.y);
  Image1.Canvas.Pen.Color := clBlack;

  end;
end;

// C E R R A R [][][[][][][][][][][][][][][][][][][][][][][][][][][][][][][][][]
procedure TForm1.Button8Click(Sender: TObject);
begin
close();
end;

// A L E J A R [][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.Button9Click(Sender: TObject);
begin
OjoAObjeto := OjoAObjeto*1.10;
  Button7Click(Sender);
end;

// C O N S T R U C T R O R [][][][][][][][][][][][][][][][][][][][][][][][][][][
procedure TForm1.FormCreate(Sender: TObject);
var
  I: Integer;
begin
  Image1.canvas.Rectangle(0,0,400,400);

  // definimos los datos de la pirámide como nulos:
  for I := 1 to 10 do begin
    Piramide[I].x := 0;
    Piramide[I].y := 0;
    Piramide[I].z := 0;
  end;

  //variables de proyeccion perspectiva
  OjoAObjeto := 40*4;
  D := 40*2;

  //Transformación de escala
  for I := 1 to 10 do begin
    Piramide[i].x := Piramide[i].x * 40;
    Piramide[i].y := Piramide[i].y * 40;
    Piramide[i].z := Piramide[i].z * 40;
  end;
end;

end.

{

                                    :^)

                                                                               }
