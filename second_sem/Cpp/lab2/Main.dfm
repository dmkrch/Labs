object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 532
  ClientWidth = 661
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 72
    Top = 37
    Width = 417
    Height = 404
    TabOrder = 0
    object Label1: TLabel
      Left = 135
      Top = 335
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
      Left = 135
      Top = 25
      Width = 274
      Height = 304
      TabOrder = 0
    end
    object Button2: TButton
      Left = 16
      Top = 15
      Width = 113
      Height = 33
      Caption = 'Show menu'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 1
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 16
      Top = 64
      Width = 113
      Height = 34
      Caption = 'Show menu by price'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button3Click
    end
    object Button1: TButton
      Left = 16
      Top = 112
      Width = 113
      Height = 34
      Caption = 'Show all orders'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button1Click
    end
    object RadioGroup1: TRadioGroup
      Left = 16
      Top = 325
      Width = 113
      Height = 65
      Items.Strings = (
        'Price of order'
        'Add order'
        'Delete order')
      TabOrder = 4
      OnClick = RadioGroup1Click
    end
    object Button4: TButton
      Left = 319
      Top = 357
      Width = 42
      Height = 28
      Caption = 'Confirm'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 5
      OnClick = Button4Click
    end
    object Edit1: TEdit
      Left = 135
      Top = 357
      Width = 178
      Height = 21
      TabOrder = 6
    end
    object Button5: TButton
      Left = 16
      Top = 160
      Width = 113
      Height = 34
      Caption = 'Top 3 dishes'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 7
      OnClick = Button5Click
    end
    object Button6: TButton
      Left = 367
      Top = 357
      Width = 42
      Height = 28
      Caption = 'Add'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -9
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = Button6Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 512
    Top = 48
    object File1: TMenuItem
      Caption = 'File'
      object Ope1: TMenuItem
        Caption = 'Open menu'
        OnClick = Ope1Click
      end
      object Openorders1: TMenuItem
        Caption = 'Open orders'
        OnClick = Openorders1Click
      end
      object Save1: TMenuItem
        Caption = 'Save'
        OnClick = Save1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    FileName = 'C:\Users\A S U S\Desktop\input.txt'
    Left = 512
    Top = 128
  end
  object SaveDialog1: TSaveDialog
    Left = 512
    Top = 208
  end
end