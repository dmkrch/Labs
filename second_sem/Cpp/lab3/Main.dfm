object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 490
  ClientWidth = 576
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
    Left = 119
    Top = 40
    Width = 361
    Height = 361
    TabOrder = 0
    object Label1: TLabel
      Left = 7
      Top = 304
      Width = 66
      Height = 13
      Caption = 'Text for input'
    end
    object Button1: TButton
      Left = 7
      Top = 8
      Width = 137
      Height = 25
      Caption = 'Delete same orders'
      TabOrder = 0
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 7
      Top = 159
      Width = 137
      Height = 25
      Caption = 'Show'
      TabOrder = 1
      OnClick = Button2Click
    end
    object RadioGroup1: TRadioGroup
      Left = 7
      Top = 95
      Width = 137
      Height = 58
      Items.Strings = (
        'Show order by id'
        'Show order by name'
        'Show all orders')
      TabOrder = 2
      OnClick = RadioGroup1Click
    end
    object Memo1: TMemo
      AlignWithMargins = True
      Left = 158
      Top = 10
      Width = 195
      Height = 345
      TabOrder = 3
    end
    object Edit1: TEdit
      Left = 7
      Top = 323
      Width = 106
      Height = 21
      TabOrder = 4
    end
    object Button3: TButton
      Left = 119
      Top = 323
      Width = 33
      Height = 22
      Caption = 'OK'
      TabOrder = 5
      OnClick = Button3Click
    end
    object RadioGroup2: TRadioGroup
      Left = 7
      Top = 39
      Width = 137
      Height = 50
      Items.Strings = (
        'Executed orders'
        'Not executed orders')
      TabOrder = 6
      OnClick = RadioGroup2Click
    end
    object Button5: TButton
      Left = 7
      Top = 248
      Width = 137
      Height = 25
      Caption = 'Execute order'
      TabOrder = 7
      OnClick = Button5Click
    end
  end
  object Button4: TButton
    Left = 126
    Top = 257
    Width = 137
    Height = 25
    Caption = 'Add order'
    TabOrder = 1
    OnClick = Button4Click
  end
  object MainMenu1: TMainMenu
    Left = 48
    Top = 40
    object S1: TMenuItem
      Caption = 'Menu'
      object Openfile1: TMenuItem
        Caption = 'Open file'
        OnClick = Openfile1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    FileName = 'D:\Prog\lab_2_sem\C++\lab3\Win32\Debug\input_info.txt'
    Left = 48
    Top = 104
  end
end
