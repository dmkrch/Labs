object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 644
  ClientWidth = 1115
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    AlignWithMargins = True
    Left = 40
    Top = 96
    Width = 522
    Height = 369
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Label1: TLabel
    Left = 584
    Top = 370
    Width = 82
    Height = 14
    Caption = 'X center coord'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 680
    Top = 370
    Width = 83
    Height = 14
    Caption = 'Y center coord'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 584
    Top = 419
    Width = 27
    Height = 16
    Caption = 'Area'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 694
    Top = 421
    Width = 4
    Height = 16
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 680
    Top = 419
    Width = 56
    Height = 16
    Caption = 'Perimeter'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object RadioGroup1: TRadioGroup
    Left = 584
    Top = 206
    Width = 90
    Height = 158
    Items.Strings = (
      'Ellipse'
      'Circle'
      'Trapezium'
      'Parallelogram'
      'Rectangle'
      'Triangle')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 472
    Top = 423
    Width = 74
    Height = 29
    Caption = 'Clear'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    OnClick = Button1Click
  end
  object ComboBox1: TComboBox
    Left = 584
    Top = 179
    Width = 90
    Height = 21
    TabOrder = 2
    Text = 'Black'
    OnChange = ComboBox1Change
    Items.Strings = (
      'Black'
      'Red'
      'Green'
      'Gray'
      'Blue'
      'Yellow'
      'White')
  end
  object ComboBox2: TComboBox
    Left = 680
    Top = 179
    Width = 91
    Height = 21
    ItemIndex = 2
    TabOrder = 3
    Text = 'Green'
    OnChange = ComboBox2Change
    Items.Strings = (
      'Black'
      'Red'
      'Green'
      'Gray'
      'Blue'
      'Yellow'
      'White')
  end
  object Edit1: TEdit
    Left = 680
    Top = 266
    Width = 41
    Height = 21
    TabOrder = 4
    Text = 'SideBot'
  end
  object Edit2: TEdit
    Left = 727
    Top = 266
    Width = 42
    Height = 21
    TabOrder = 5
    Text = 'SideTop'
  end
  object Edit3: TEdit
    Left = 680
    Top = 293
    Width = 41
    Height = 21
    TabOrder = 6
    Text = 'SideBot'
  end
  object Edit4: TEdit
    Left = 584
    Top = 390
    Width = 90
    Height = 21
    TabOrder = 7
  end
  object Edit5: TEdit
    Left = 680
    Top = 390
    Width = 91
    Height = 21
    TabOrder = 8
  end
  object Edit6: TEdit
    Left = 584
    Top = 441
    Width = 90
    Height = 21
    TabOrder = 9
  end
  object Edit7: TEdit
    Left = 680
    Top = 441
    Width = 91
    Height = 21
    TabOrder = 10
  end
  object RadioGroup2: TRadioGroup
    Left = 584
    Top = 96
    Width = 187
    Height = 77
    Items.Strings = (
      'Draw'
      'Move'
      'Scale')
    TabOrder = 11
  end
end