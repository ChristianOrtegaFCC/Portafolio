object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 673
  ClientWidth = 752
  Color = 3481097
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 396
    Top = 1
    Width = 573
    Height = 42
    Caption = 'EDITOR PARA AGUA DE PUEBLA '
    Color = clBlack
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clAqua
    Font.Height = -35
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentColor = False
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 49
    Width = 180
    Height = 241
    Color = clBlack
    ParentBackground = False
    TabOrder = 0
    object Label3: TLabel
      Left = 22
      Top = 67
      Width = 73
      Height = 19
      Caption = #193'ngulo : '
      Color = clWhite
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentColor = False
      ParentFont = False
    end
    object Label4: TLabel
      Left = 15
      Top = 48
      Width = 150
      Height = 13
      Caption = '_________________________'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Button1: TButton
      Left = 12
      Top = 10
      Width = 75
      Height = 40
      Cursor = crHandPoint
      Caption = 'Tubo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 93
      Top = 9
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Manguera'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 93
      Top = 144
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Distribuidor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 12
      Top = 97
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Casa'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 93
      Top = 97
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Edificio'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 12
      Top = 144
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Bomba'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 12
      Top = 191
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Medidor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 6
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 93
      Top = 191
      Width = 75
      Height = 41
      Cursor = crHandPoint
      Caption = 'Llave'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 7
      OnClick = Button8Click
    end
    object Edit1: TEdit
      Left = 101
      Top = 70
      Width = 55
      Height = 21
      TabOrder = 8
      Text = '0'
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 294
    Width = 180
    Height = 133
    Color = 3481097
    ParentBackground = False
    TabOrder = 1
    object Button11: TButton
      Left = 7
      Top = 7
      Width = 164
      Height = 28
      Cursor = crHandPoint
      Caption = 'Borrar seleccionado'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 7
      Top = 37
      Width = 164
      Height = 27
      Cursor = crHandPoint
      Caption = 'Borrar todo'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button12Click
    end
    object Button13: TButton
      Left = 52
      Top = 101
      Width = 77
      Height = 27
      Cursor = crHandPoint
      Caption = 'Cotizacion'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button13Click
    end
    object Button14: TButton
      Left = 7
      Top = 70
      Width = 76
      Height = 27
      Cursor = crHelp
      Caption = 'Autor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button14Click
    end
    object Button15: TButton
      Left = 95
      Top = 70
      Width = 76
      Height = 27
      Cursor = crNoDrop
      Caption = 'Salir'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 4
      OnClick = Button15Click
    end
  end
  object Panel3: TPanel
    Left = 8
    Top = 433
    Width = 180
    Height = 151
    Color = clBackground
    ParentBackground = False
    TabOrder = 2
    object Label5: TLabel
      Left = 6
      Top = 106
      Width = 51
      Height = 14
      Caption = 'Nombre: '
      Color = clCream
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentColor = False
      ParentFont = False
    end
    object Label6: TLabel
      Left = 11
      Top = 44
      Width = 154
      Height = 13
      Caption = '___________________'#31#31'___'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button9: TButton
      Left = 20
      Top = 64
      Width = 139
      Height = 40
      Cursor = crHandPoint
      Caption = 'Guardar Dise'#241'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 20
      Top = 8
      Width = 139
      Height = 42
      Cursor = crHandPoint
      Caption = 'Abrir Dise'#241'o'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button10Click
    end
    object Edit2: TEdit
      Left = 7
      Top = 122
      Width = 169
      Height = 21
      TabOrder = 2
    end
  end
  object ScrollBox1: TScrollBox
    Left = 194
    Top = 47
    Width = 1160
    Height = 620
    TabOrder = 3
    object Image1: TImage
      Left = 0
      Top = 0
      Width = 2000
      Height = 2000
      Cursor = crCross
      OnClick = Image1Click
      OnMouseMove = Image1MouseMove
    end
    object Label2: TLabel
      Left = -2
      Top = -2
      Width = 26
      Height = 23
      Cursor = crCross
      Caption = '[  ]'
      Color = 16513249
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentColor = False
      ParentFont = False
    end
  end
  object Panel4: TPanel
    Left = 8
    Top = 587
    Width = 180
    Height = 80
    Color = 3481097
    ParentBackground = False
    TabOrder = 4
    object Button17: TButton
      Left = 6
      Top = 6
      Width = 127
      Height = 39
      Caption = 'No inclu'#237'r extremos'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button17Click
    end
    object Button18: TButton
      Left = 6
      Top = 48
      Width = 167
      Height = 26
      Caption = 'Desactivar apuntador [ ]'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button18Click
    end
    object Button16: TButton
      Left = 132
      Top = 6
      Width = 42
      Height = 39
      Caption = 'Info'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button16Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 162
    Top = 390
  end
end
