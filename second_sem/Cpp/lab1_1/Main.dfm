object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 607
  ClientWidth = 918
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 8
    Top = 24
    Width = 721
    Height = 473
  end
  object Button1: TButton
    Left = 313
    Top = 440
    Width = 89
    Height = 38
    Caption = 'Start'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clBlack
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 416
    Top = 440
    Width = 89
    Height = 38
    Caption = 'stop'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 521
    Top = 440
    Width = 89
    Height = 39
    Caption = 'Accelerate'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 624
    Top = 440
    Width = 89
    Height = 41
    Caption = 'Slow down'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button4Click
  end
  object Panel1: TPanel
    Left = 528
    Top = 40
    Width = 185
    Height = 89
    TabOrder = 4
    object Edit1: TEdit
      Left = 48
      Top = 21
      Width = 121
      Height = 21
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 48
      Top = 48
      Width = 121
      Height = 21
      TabOrder = 1
    end
    object StaticText1: TStaticText
      Left = 25
      Top = 25
      Width = 16
      Height = 17
      Caption = 'X1'
      TabOrder = 2
    end
    object StaticText2: TStaticText
      Left = 26
      Top = 48
      Width = 16
      Height = 17
      Caption = 'X2'
      TabOrder = 3
    end
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 1
    OnTimer = Timer1Timer
    Left = 16
    Top = 448
  end
end