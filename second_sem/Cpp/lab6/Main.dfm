object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 510
  ClientWidth = 730
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
    Left = 88
    Top = 48
    Width = 489
    Height = 369
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 261
      Width = 33
      Height = 16
      Caption = 'Name'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 239
      Width = 20
      Height = 16
      Caption = 'Key'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 336
      Width = 20
      Height = 16
      Caption = 'Key'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label4: TLabel
      Left = 8
      Top = 314
      Width = 64
      Height = 16
      Caption = 'Left nodes:'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label5: TLabel
      Left = 78
      Top = 312
      Width = 5
      Height = 18
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clRed
      Font.Height = -15
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object TreeView1: TTreeView
      Left = 8
      Top = 16
      Width = 242
      Height = 217
      Indent = 19
      TabOrder = 0
    end
    object Memo1: TMemo
      Left = 256
      Top = 16
      Width = 217
      Height = 217
      TabOrder = 1
    end
    object Button2: TButton
      Left = 256
      Top = 311
      Width = 105
      Height = 50
      Caption = 'Show'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 2
      OnClick = Button2Click
    end
    object RadioGroup1: TRadioGroup
      Left = 256
      Top = 239
      Width = 217
      Height = 66
      Items.Strings = (
        'Show by key'
        'Show directly'
        'Show backwards')
      TabOrder = 3
    end
    object Edit1: TEdit
      Left = 73
      Top = 239
      Width = 88
      Height = 21
      TabOrder = 4
    end
    object Edit2: TEdit
      Left = 73
      Top = 263
      Width = 88
      Height = 21
      TabOrder = 5
    end
    object Button1: TButton
      Left = 167
      Top = 239
      Width = 83
      Height = 43
      Caption = 'Add new'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 6
      OnClick = Button1Click
    end
    object Edit3: TEdit
      Left = 73
      Top = 336
      Width = 88
      Height = 21
      TabOrder = 7
    end
    object Button3: TButton
      Left = 167
      Top = 336
      Width = 83
      Height = 25
      Caption = 'Delete'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 8
      OnClick = Button3Click
    end
    object Button4: TButton
      Left = 167
      Top = 304
      Width = 83
      Height = 26
      Caption = 'Get amount'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 9
      OnClick = Button4Click
    end
    object Edit5: TEdit
      Left = 408
      Top = 250
      Width = 57
      Height = 21
      TabOrder = 10
    end
    object Button5: TButton
      Left = 367
      Top = 311
      Width = 106
      Height = 50
      Caption = 'Balance'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -16
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
      TabOrder = 11
      OnClick = Button5Click
    end
  end
end