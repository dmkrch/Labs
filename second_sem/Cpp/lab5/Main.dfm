object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 534
  ClientWidth = 844
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
    Left = 184
    Top = 40
    Width = 385
    Height = 217
    TabOrder = 0
    object ListBox1: TListBox
      Left = 16
      Top = 16
      Width = 353
      Height = 137
      ItemHeight = 13
      MultiSelect = True
      TabOrder = 0
    end
    object Button1: TButton
      Left = 16
      Top = 159
      Width = 177
      Height = 43
      Caption = 'Select'
      TabOrder = 1
      OnClick = Button1Click
    end
    object Button2: TButton
      Left = 199
      Top = 159
      Width = 170
      Height = 43
      Caption = 'Move'
      TabOrder = 2
      OnClick = Button2Click
    end
  end
  object MainMenu1: TMainMenu
    Left = 696
    Top = 216
    object InitializeList1: TMenuItem
      Caption = 'Initialize List'
      OnClick = InitializeList1Click
    end
    object Showlist1: TMenuItem
      Caption = 'Show list'
      OnClick = Showlist1Click
    end
  end
end
