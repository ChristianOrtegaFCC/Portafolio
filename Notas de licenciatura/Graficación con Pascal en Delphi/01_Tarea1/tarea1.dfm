object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 560
  ClientWidth = 667
  Color = clSkyBlue
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 47
    Width = 500
    Height = 500
    Cursor = crCross
  end
  object Label1: TLabel
    Left = 120
    Top = 0
    Width = 441
    Height = 41
    AutoSize = False
    Caption = 'Graficador de funciones FCC'
    Color = clWhite
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clNavy
    Font.Height = -29
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentColor = False
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 514
    Top = 47
    Width = 145
    Height = 186
    Color = clInactiveCaption
    ParentBackground = False
    TabOrder = 0
    object Label2: TLabel
      Left = 40
      Top = 10
      Width = 57
      Height = 16
      Caption = 'Accionar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button1: TButton
      Left = 16
      Top = 24
      Width = 113
      Height = 25
      Cursor = crHandPoint
      Caption = 'f1 = 2*X*X'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 16
      Top = 55
      Width = 113
      Height = 25
      Cursor = crHandPoint
      Caption = 'f2 = X*X*X'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clBlack
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 16
      Top = 86
      Width = 113
      Height = 25
      Cursor = crHandPoint
      BiDiMode = bdLeftToRight
      Caption = 'f3 = 8*SIN(x)'
      ParentBiDiMode = False
      ParentShowHint = False
      ShowHint = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 16
      Top = 117
      Width = 113
      Height = 25
      Cursor = crHandPoint
      Caption = 'f4 = -1*COS(x)'
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 16
      Top = 148
      Width = 113
      Height = 25
      Cursor = crHandPoint
      Caption = 'Limpiar'
      TabOrder = 4
      OnClick = Button5Click
    end
  end
  object Panel2: TPanel
    Left = 514
    Top = 239
    Width = 145
    Height = 205
    Color = clInactiveCaption
    ParentBackground = False
    TabOrder = 1
    object Label3: TLabel
      Left = 48
      Top = 8
      Width = 38
      Height = 16
      Caption = 'Editar'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label5: TLabel
      Left = 8
      Top = 22
      Width = 113
      Height = 13
      Caption = 'Graficar en el intervalo:'
    end
    object Label6: TLabel
      Left = 8
      Top = 41
      Width = 120
      Height = 23
      Caption = '(        ,        )'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Label8: TLabel
      Left = 40
      Top = 68
      Width = 61
      Height = 13
      Caption = 'a       ,        b'
    end
    object Label7: TLabel
      Left = 16
      Top = 96
      Width = 42
      Height = 13
      Caption = 'funci'#243'n: '
    end
    object Label10: TLabel
      Left = 64
      Top = 96
      Width = 4
      Height = 13
      Caption = '-'
    end
    object Edit1: TEdit
      Left = 24
      Top = 41
      Width = 33
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 80
      Top = 41
      Width = 33
      Height = 21
      TabOrder = 1
    end
  end
  object Panel3: TPanel
    Left = 514
    Top = 450
    Width = 145
    Height = 97
    Color = clInactiveCaption
    ParentBackground = False
    TabOrder = 2
    object Label4: TLabel
      Left = 48
      Top = 8
      Width = 41
      Height = 16
      Caption = 'Extras'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
    end
    object Button6: TButton
      Left = 16
      Top = 30
      Width = 49
      Height = 25
      Cursor = crHelp
      Caption = 'Autor'
      TabOrder = 0
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 71
      Top = 30
      Width = 50
      Height = 25
      Cursor = crNo
      Caption = 'Salir'
      TabOrder = 1
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 32
      Top = 61
      Width = 75
      Height = 25
      Cursor = crHelp
      Caption = ':^)'
      TabOrder = 2
      OnClick = Button8Click
    end
  end
end
