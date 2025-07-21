object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 543
  ClientWidth = 715
  Color = clBtnFace
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
    Top = 8
    Width = 500
    Height = 500
  end
  object Panel1: TPanel
    Left = 538
    Top = 8
    Width = 151
    Height = 500
    TabOrder = 0
    object Button1: TButton
      Left = 32
      Top = 12
      Width = 75
      Height = 25
      Caption = 'Rotacion X +'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 32
      Top = 57
      Width = 75
      Height = 25
      Caption = 'Rotacion X -'
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 32
      Top = 97
      Width = 75
      Height = 25
      Caption = 'Rotaci'#243'n Y +'
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 32
      Top = 136
      Width = 75
      Height = 25
      Caption = 'Rotaci'#243'n Y -'
      TabOrder = 3
      OnClick = Button4Click
    end
    object Button5: TButton
      Left = 33
      Top = 176
      Width = 75
      Height = 25
      Caption = 'Rotacion Z+'
      TabOrder = 4
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 32
      Top = 215
      Width = 75
      Height = 25
      Caption = 'Rotacion Z -'
      TabOrder = 5
      OnClick = Button6Click
    end
    object Button7: TButton
      Left = 32
      Top = 259
      Width = 75
      Height = 25
      Caption = 'Pinta cubo'
      TabOrder = 6
      OnClick = Button7Click
    end
    object Button8: TButton
      Left = 32
      Top = 347
      Width = 75
      Height = 25
      Caption = 'Salir'
      TabOrder = 7
      OnClick = Button8Click
    end
    object Button9: TButton
      Left = 32
      Top = 305
      Width = 75
      Height = 25
      Caption = 'Escala'
      TabOrder = 8
      OnClick = Button9Click
    end
  end
end
