object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 484
  ClientWidth = 682
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
    Left = 16
    Top = 48
    Width = 400
    Height = 400
    OnMouseLeave = Image1MouseLeave
    OnMouseMove = Image1MouseMove
  end
  object Panel1: TPanel
    Left = 464
    Top = 56
    Width = 210
    Height = 385
    TabOrder = 0
    object Label1: TLabel
      Left = 40
      Top = 27
      Width = 10
      Height = 13
      Caption = 'x:'
    end
    object Label2: TLabel
      Left = 40
      Top = 66
      Width = 10
      Height = 13
      Caption = 'y:'
    end
    object Label3: TLabel
      Left = 25
      Top = 109
      Width = 26
      Height = 13
      Caption = 'Rojo:'
    end
    object Label4: TLabel
      Left = 24
      Top = 186
      Width = 24
      Height = 13
      Caption = 'Azul:'
    end
    object Label5: TLabel
      Left = 25
      Top = 148
      Width = 32
      Height = 13
      Caption = 'Verde:'
    end
    object Edit1: TEdit
      Left = 72
      Top = 24
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 72
      Top = 63
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 72
      Top = 106
      Width = 121
      Height = 21
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 72
      Top = 145
      Width = 121
      Height = 21
      TabOrder = 3
    end
    object Edit5: TEdit
      Left = 72
      Top = 183
      Width = 121
      Height = 21
      TabOrder = 4
    end
    object Button1: TButton
      Left = 8
      Top = 232
      Width = 97
      Height = 25
      Caption = 'Red Rectangle'
      TabOrder = 5
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 111
      Top = 232
      Width = 90
      Height = 25
      Caption = 'Green Rectangle'
      TabOrder = 6
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 64
      Top = 280
      Width = 89
      Height = 25
      Caption = 'Blue Rectangle'
      TabOrder = 7
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 16
      Top = 327
      Width = 75
      Height = 25
      Caption = 'Open'
      TabOrder = 8
      OnClick = Abrir
    end
    object Button5: TButton
      Left = 120
      Top = 327
      Width = 75
      Height = 25
      Caption = ':^)'
      TabOrder = 9
      OnClick = Button5Click
    end
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 184
    Top = 232
  end
end
