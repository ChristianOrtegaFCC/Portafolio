object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 671
  ClientWidth = 832
  Color = 16384
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OnCreate = FormCreate
  TextHeight = 13
  object Image1: TImage
    Left = 224
    Top = 63
    Width = 600
    Height = 600
    Cursor = crCross
    OnClick = Image1Click
  end
  object Label2: TLabel
    Left = 121
    Top = 8
    Width = 568
    Height = 45
    Cursor = crIBeam
    Caption = 'Visor 3D para agua de puebla. '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clLime
    Font.Height = -37
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 8
    Top = 64
    Width = 211
    Height = 257
    Color = clBlack
    ParentBackground = False
    TabOrder = 0
    object Label1: TLabel
      Left = 11
      Top = 134
      Width = 190
      Height = 11
      Caption = '______________________________________'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWhite
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 13
      Top = 12
      Width = 187
      Height = 19
      Cursor = crIBeam
      Caption = 'Controles de visualizaci'#243'n '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
    end
    object Button1: TButton
      Left = 29
      Top = 43
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar X'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 110
      Top = 43
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar -X'
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
      Left = 29
      Top = 74
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar Y'
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
      Left = 110
      Top = 74
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar -Y'
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
      Left = 29
      Top = 108
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar Z'
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
      Left = 110
      Top = 108
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Rotar -Z'
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
      Left = 29
      Top = 154
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Acercarse'
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
      Left = 110
      Top = 154
      Width = 75
      Height = 25
      Cursor = crHandPoint
      Caption = 'Alejarse'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 7
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 70
      Top = 191
      Width = 75
      Height = 25
      Cursor = crMultiDrag
      Caption = 'Abrir red'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 8
      OnClick = Button9Click
    end
    object Button10: TButton
      Left = 70
      Top = 222
      Width = 75
      Height = 24
      Cursor = crDrag
      Caption = 'Pintar red'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 9
      OnClick = Button10Click
    end
  end
  object Panel2: TPanel
    Left = 8
    Top = 335
    Width = 211
    Height = 111
    Color = clGreen
    ParentBackground = False
    TabOrder = 1
    object Label4: TLabel
      Left = 53
      Top = 9
      Width = 110
      Height = 19
      Cursor = crIBeam
      Caption = 'Opciones extra '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
    end
    object Button11: TButton
      Left = 75
      Top = 41
      Width = 62
      Height = 25
      Cursor = crHelp
      Caption = 'Autor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 0
      OnClick = Button11Click
    end
    object Button12: TButton
      Left = 6
      Top = 40
      Width = 62
      Height = 25
      Cursor = crNo
      Caption = 'Salir'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button12Click
    end
    object Button17: TButton
      Left = 143
      Top = 41
      Width = 62
      Height = 25
      Cursor = crHelp
      Caption = 'INFO'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button17Click
    end
    object Button18: TButton
      Left = 6
      Top = 75
      Width = 199
      Height = 25
      Cursor = crHelp
      Caption = 'Activar controles de movimiento'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button18Click
    end
  end
  object Panel3: TPanel
    Left = 8
    Top = 456
    Width = 211
    Height = 162
    Color = 10240
    ParentBackground = False
    TabOrder = 2
    object Label5: TLabel
      Left = 12
      Top = 10
      Width = 189
      Height = 18
      Cursor = crIBeam
      Caption = 'Controles de movimiento '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clLime
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Button13: TButton
      Left = 84
      Top = 39
      Width = 40
      Height = 35
      Cursor = crSizeAll
      Caption = '/\'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button13Click
    end
    object Button14: TButton
      Left = 84
      Top = 114
      Width = 40
      Height = 35
      Cursor = crSizeAll
      Caption = 'V'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button14Click
    end
    object Button15: TButton
      Left = 43
      Top = 76
      Width = 40
      Height = 35
      Cursor = crSizeAll
      Caption = '<'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 2
      OnClick = Button15Click
    end
    object Button16: TButton
      Left = 126
      Top = 76
      Width = 40
      Height = 35
      Cursor = crSizeAll
      Caption = '>'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 3
      OnClick = Button16Click
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 152
    Top = 336
  end
end
