object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 565
  ClientWidth = 911
  Color = 8257470
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
    Left = 271
    Top = 0
    Width = 445
    Height = 33
    Caption = 'PRODUCCION DE MAIZ EN 2020 '
    Color = clLime
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentColor = False
    ParentFont = False
  end
  object Image1: TImage
    Left = 8
    Top = 39
    Width = 700
    Height = 500
  end
  object Label14: TLabel
    Left = 40
    Top = 545
    Width = 653
    Height = 13
    Caption = 
      ' ENE.           FEB.           MAR.           ABR.           MAY' +
      '.          JUN.            JUL.           AGO.           SEP.   ' +
      '         OCT.           NOV.           DIC.'
  end
  object Panel1: TPanel
    Left = 714
    Top = 39
    Width = 185
    Height = 518
    Color = 5898156
    ParentBackground = False
    TabOrder = 0
    object Label2: TLabel
      Left = 23
      Top = 17
      Width = 53
      Height = 17
      Caption = 'Enero :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 16
      Top = 43
      Width = 68
      Height = 17
      Caption = 'Febrero :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 23
      Top = 69
      Width = 54
      Height = 17
      Caption = 'Marzo :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 28
      Top = 95
      Width = 44
      Height = 17
      Caption = 'Abril :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 27
      Top = 123
      Width = 47
      Height = 17
      Caption = 'Mayo :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 26
      Top = 150
      Width = 49
      Height = 17
      Caption = 'Junio :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label8: TLabel
      Left = 27
      Top = 176
      Width = 44
      Height = 17
      Caption = 'Julio :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label9: TLabel
      Left = 21
      Top = 203
      Width = 60
      Height = 17
      Caption = 'Agosto :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label10: TLabel
      Left = 7
      Top = 231
      Width = 83
      Height = 15
      Caption = 'Septiembre :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label11: TLabel
      Left = 16
      Top = 256
      Width = 69
      Height = 17
      Caption = 'Octubre :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label12: TLabel
      Left = 13
      Top = 285
      Width = 78
      Height = 15
      Caption = 'Noviembre :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Label13: TLabel
      Left = 14
      Top = 312
      Width = 75
      Height = 15
      Caption = 'Diciemrbe :'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Arial Rounded MT Bold'
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 96
      Top = 15
      Width = 81
      Height = 21
      TabOrder = 0
      Text = '0'
    end
    object Button1: TButton
      Left = 13
      Top = 341
      Width = 75
      Height = 38
      Cursor = crHandPoint
      Caption = 'Pinta'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 100
      Top = 341
      Width = 74
      Height = 38
      Cursor = crHandPoint
      Caption = 'Limpia'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 13
      Top = 385
      Width = 75
      Height = 38
      Cursor = crHandPoint
      Caption = 'Autor'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 3
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 100
      Top = 385
      Width = 75
      Height = 38
      Cursor = crHandPoint
      Caption = 'Salir'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 4
      OnClick = Button4Click
    end
    object Edit2: TEdit
      Left = 96
      Top = 42
      Width = 81
      Height = 21
      TabOrder = 5
      Text = '0'
    end
    object Edit3: TEdit
      Left = 96
      Top = 67
      Width = 81
      Height = 21
      TabOrder = 6
      Text = '0'
    end
    object Edit4: TEdit
      Left = 96
      Top = 94
      Width = 81
      Height = 21
      TabOrder = 7
      Text = '0'
    end
    object Edit5: TEdit
      Left = 96
      Top = 121
      Width = 81
      Height = 21
      TabOrder = 8
      Text = '0'
    end
    object Edit6: TEdit
      Left = 96
      Top = 148
      Width = 81
      Height = 21
      TabOrder = 9
      Text = '0'
    end
    object Edit7: TEdit
      Left = 96
      Top = 175
      Width = 81
      Height = 21
      TabOrder = 10
      Text = '0'
    end
    object Edit8: TEdit
      Left = 96
      Top = 202
      Width = 81
      Height = 21
      TabOrder = 11
      Text = '0'
    end
    object Edit9: TEdit
      Left = 96
      Top = 229
      Width = 81
      Height = 21
      TabOrder = 12
      Text = '0'
    end
    object Edit10: TEdit
      Left = 96
      Top = 256
      Width = 81
      Height = 21
      TabOrder = 13
      Text = '0'
    end
    object Edit11: TEdit
      Left = 96
      Top = 283
      Width = 81
      Height = 21
      TabOrder = 14
      Text = '0'
    end
    object Edit12: TEdit
      Left = 96
      Top = 310
      Width = 81
      Height = 21
      TabOrder = 15
      Text = '0'
    end
    object Button5: TButton
      Left = 18
      Top = 429
      Width = 155
      Height = 57
      Cursor = crNo
      Caption = ':^)'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -35
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 16
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 16
      Top = 492
      Width = 161
      Height = 19
      Cursor = crSQLWait
      Caption = 'Fast_Test'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -11
      Font.Name = 'Tahoma'
      Font.Style = [fsItalic]
      ParentFont = False
      TabOrder = 17
      OnClick = Button6Click
    end
  end
end
