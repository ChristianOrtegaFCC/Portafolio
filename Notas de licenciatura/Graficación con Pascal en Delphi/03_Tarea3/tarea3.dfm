object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 507
  ClientWidth = 695
  Color = clGradientActiveCaption
  Ctl3D = False
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
    Left = 16
    Top = 144
    Width = 320
    Height = 320
  end
  object Image2: TImage
    Left = 353
    Top = 144
    Width = 320
    Height = 320
  end
  object Image3: TImage
    Left = 8
    Top = 8
    Width = 130
    Height = 130
  end
  object Image4: TImage
    Left = 551
    Top = 8
    Width = 130
    Height = 130
  end
  object Label2: TLabel
    Left = 127
    Top = 470
    Width = 100
    Height = 33
    Caption = 'Puebla '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Label3: TLabel
    Left = 434
    Top = 471
    Width = 158
    Height = 33
    Caption = 'Hong Kong '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object Panel1: TPanel
    Left = 152
    Top = 8
    Width = 385
    Height = 130
    TabOrder = 0
    object Label1: TLabel
      Left = 32
      Top = 11
      Width = 315
      Height = 60
      Caption = 'Reloj FCC BUAP '
      Font.Charset = ANSI_CHARSET
      Font.Color = clHighlight
      Font.Height = -48
      Font.Name = 'Impact'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
    end
    object Button1: TButton
      Left = 16
      Top = 85
      Width = 51
      Height = 33
      Cursor = crHandPoint
      Caption = 'On'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'Impact'
      Font.Style = []
      ParentFont = False
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 73
      Top = 85
      Width = 50
      Height = 33
      Cursor = crHandPoint
      Caption = 'Off'
      Font.Charset = ANSI_CHARSET
      Font.Color = clBlack
      Font.Height = -19
      Font.Name = 'Impact'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 128
      Top = 85
      Width = 66
      Height = 33
      Cursor = crDrag
      Caption = 'Autor'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Impact'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 264
      Top = 85
      Width = 58
      Height = 33
      Cursor = crNoDrop
      Caption = 'Salir'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Impact'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 328
      Top = 85
      Width = 46
      Height = 33
      Cursor = crNo
      Caption = ':^)'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = [fsBold, fsItalic]
      ParentFont = False
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 200
      Top = 85
      Width = 58
      Height = 33
      Cursor = crMultiDrag
      Caption = 'Info'
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'Impact'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = Button6Click
    end
  end
  object Edit1: TEdit
    Left = 1
    Top = 488
    Width = 87
    Height = 19
    TabOrder = 1
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 648
    Top = 480
  end
end
