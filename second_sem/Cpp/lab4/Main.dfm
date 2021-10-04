object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'pa'
  ClientHeight = 190
  ClientWidth = 200
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 7
    Top = 5
    Width = 185
    Height = 177
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 71
      Width = 53
      Height = 13
      Caption = 'input here:'
    end
    object Label2: TLabel
      Left = 8
      Top = 125
      Width = 61
      Height = 13
      Caption = 'output here:'
    end
    object Edit1: TEdit
      Left = 8
      Top = 90
      Width = 161
      Height = 21
      TabOrder = 0
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 121
      Height = 49
      Items.Strings = (
        'Enter in infix form'
        'Enter in postfix form')
      TabOrder = 1
    end
    object Button1: TButton
      Left = 135
      Top = 8
      Width = 42
      Height = 49
      Caption = 'calc'
      TabOrder = 2
      OnClick = Button1Click
    end
    object Edit2: TEdit
      Left = 8
      Top = 144
      Width = 161
      Height = 21
      TabOrder = 3
    end
  end
end
