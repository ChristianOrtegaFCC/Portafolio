object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 637
  ClientWidth = 1172
  Color = clSilver
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 208
    Top = 14
    Width = 792
    Height = 42
    Caption = 'EDITOR  PARA  REDES  DE  COMPUTADORAS '
    Color = clAqua
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -35
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentColor = False
    ParentFont = False
  end
  object ScrollBox1: TScrollBox
    Left = 171
    Top = 68
    Width = 993
    Height = 561
    TabOrder = 0
    object Image1: TImage
      Left = -2
      Top = -1
      Width = 2000
      Height = 2000
      Cursor = crCross
      OnClick = Image1Click
      OnMouseMove = Image1MouseMove
    end
  end
  object Panel1: TPanel
    Left = 8
    Top = 68
    Width = 157
    Height = 234
    Color = clGradientActiveCaption
    ParentBackground = False
    TabOrder = 1
    object Label2: TLabel
      Left = 53
      Top = 4
      Width = 63
      Height = 23
      Caption = 'Pintar '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Label3: TLabel
      Left = 4
      Top = 52
      Width = 150
      Height = 13
      Caption = '_________________________'
    end
    object Label4: TLabel
      Left = 15
      Top = 71
      Width = 46
      Height = 16
      Caption = #193'ngulo:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 10
      Top = 181
      Width = 140
      Height = 10
      Caption = '___________________________________'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -8
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 8
      Top = 33
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Fibra'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 84
      Top = 33
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Cable'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 8
      Top = 199
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Firewall'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 8
      Top = 124
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Server'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 84
      Top = 199
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Switch'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 84
      Top = 124
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'PC'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 47
      Top = 156
      Width = 66
      Height = 25
      Cursor = crHandPoint
      Caption = 'Impresora'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 6
      OnClick = Button7Click
    end
    object Edit1: TEdit
      Left = 10
      Top = 91
      Width = 125
      Height = 21
      Cursor = crIBeam
      TabOrder = 7
      Text = '0'
      OnChange = Edit1Change
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 311
    Width = 157
    Height = 141
    Color = clMedGray
    ParentBackground = False
    TabOrder = 2
    object Label6: TLabel
      Left = 34
      Top = 5
      Width = 101
      Height = 23
      Caption = 'Opciones: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Button8: TButton
      Left = 8
      Top = 36
      Width = 144
      Height = 25
      Cursor = crDrag
      Caption = 'Borrar seleccionado'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 8
      Top = 70
      Width = 144
      Height = 25
      Cursor = crMultiDrag
      Caption = 'Borrar todo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 8
      Top = 104
      Width = 72
      Height = 25
      Cursor = crHelp
      Caption = 'Autor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button10Click
    end
    object Button11: TButton
      Left = 88
      Top = 104
      Width = 64
      Height = 25
      Cursor = crNo
      Caption = 'Salir'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button11Click
    end
  end
  object Panel3: TPanel
    Left = 8
    Top = 458
    Width = 157
    Height = 171
    Color = clSkyBlue
    ParentBackground = False
    TabOrder = 3
    object Label7: TLabel
      Left = 42
      Top = 6
      Width = 85
      Height = 23
      Caption = 'Archivo: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 5
      Top = 59
      Width = 147
      Height = 16
      Caption = '_____________________'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 11
      Top = 120
      Width = 44
      Height = 13
      Caption = 'Nombre: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
    end
    object Button12: TButton
      Left = 18
      Top = 35
      Width = 121
      Height = 28
      Cursor = crHandPoint
      Caption = 'Abrir dise'#241'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button12Click
    end
    object Button13: TButton
      Left = 18
      Top = 84
      Width = 121
      Height = 28
      Cursor = crHandPoint
      Caption = 'Guardar dise'#241'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button13Click
    end
    object Edit2: TEdit
      Left = 7
      Top = 138
      Width = 144
      Height = 21
      Cursor = crIBeam
      TabOrder = 2
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 152
    Top = 456
  end
end
