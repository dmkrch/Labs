object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 504
  ClientWidth = 785
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
    Left = 192
    Top = 80
    Width = 353
    Height = 297
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 170
      Width = 118
      Height = 16
      Caption = 'Information for input'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Memo1: TMemo
      Left = 152
      Top = 8
      Width = 193
      Height = 273
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      ReadOnly = True
      TabOrder = 0
    end
    object RadioGroup1: TRadioGroup
      Left = 8
      Top = 8
      Width = 138
      Height = 137
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = [fsBold]
      Items.Strings = (
        'Add'
        'Delete'
        'Find'
        'Show table'
        'Show popular')
      ParentFont = False
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 8
      Top = 192
      Width = 138
      Height = 21
      TabOrder = 2
    end
    object Button1: TButton
      Left = 8
      Top = 227
      Width = 138
      Height = 54
      Caption = 'Action'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button1Click
    end
  end
end
