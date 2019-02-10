object FormXLock: TFormXLock
  Left = 840
  Top = 610
  BorderIcons = [biSystemMenu, biMinimize]
  BorderStyle = bsSingle
  Caption = 'XLock Controls'
  ClientHeight = 92
  ClientWidth = 158
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  OnDestroy = FormDestroy
  PixelsPerInch = 96
  TextHeight = 13
  object ChkNumLock: TCheckBox
    Left = 40
    Top = 8
    Width = 97
    Height = 17
    Caption = 'NumLock'
    Checked = True
    State = cbChecked
    TabOrder = 0
  end
  object ChkCapsLock: TCheckBox
    Left = 40
    Top = 40
    Width = 97
    Height = 17
    Caption = 'CapsLock'
    TabOrder = 1
  end
  object ChkInsert: TCheckBox
    Left = 40
    Top = 72
    Width = 97
    Height = 17
    Caption = 'Insert'
    Checked = True
    State = cbChecked
    TabOrder = 2
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 16
    Top = 16
  end
end
