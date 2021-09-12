object Form1: TForm1
  Left = 253
  Top = 199
  Width = 696
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object DBGrid1: TDBGrid
    Left = 16
    Top = 48
    Width = 345
    Height = 120
    DataSource = DataSource1
    TabOrder = 0
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'Tovar'
        Title.Caption = 'Товар'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'EdIzm'
        Title.Caption = 'Ед. изм.'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Zena'
        Title.Caption = 'Цена'
        Visible = True
      end>
  end
  object DBGrid2: TDBGrid
    Left = 16
    Top = 208
    Width = 345
    Height = 120
    DataSource = DataSource2
    ReadOnly = True
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
    Columns = <
      item
        Expanded = False
        FieldName = 'DatPrih'
        Title.Caption = 'Дата прихода'
        Width = 90
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Tovar'
        Title.Caption = 'Товар'
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'Kolvo'
        Title.Caption = 'Количество'
        Visible = True
      end>
  end
  object BitBtn1: TBitBtn
    Left = 16
    Top = 408
    Width = 75
    Height = 25
    TabOrder = 2
    Kind = bkClose
  end
  object DBEdit1: TDBEdit
    Left = 16
    Top = 344
    Width = 105
    Height = 21
    DataField = 'DatPrih'
    DataSource = DataSource2
    TabOrder = 3
  end
  object DBEdit2: TDBEdit
    Left = 248
    Top = 344
    Width = 105
    Height = 21
    DataField = 'Kolvo'
    DataSource = DataSource2
    TabOrder = 4
  end
  object DBLookupComboBox1: TDBLookupComboBox
    Left = 120
    Top = 344
    Width = 129
    Height = 21
    DataField = 'Tovar'
    DataSource = DataSource2
    KeyField = 'Tovar'
    ListField = 'Tovar'
    ListSource = DataSource1
    TabOrder = 5
  end
  object InsertButton: TButton
    Left = 16
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Добавить'
    TabOrder = 6
    OnClick = InsertButtonClick
  end
  object EditButton: TButton
    Left = 112
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Изменить'
    TabOrder = 7
    OnClick = EditButtonClick
  end
  object DeleteButton: TButton
    Left = 208
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Удалить'
    TabOrder = 8
    OnClick = DeleteButtonClick
  end
  object PostButton: TButton
    Left = 304
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Запомнить'
    TabOrder = 9
    OnClick = PostButtonClick
  end
  object CancelButton: TButton
    Left = 408
    Top = 376
    Width = 75
    Height = 25
    Caption = 'Отменить'
    TabOrder = 10
    OnClick = CancelButtonClick
  end
  object Button1: TButton
    Left = 120
    Top = 408
    Width = 75
    Height = 25
    Caption = 'Wizard'
    TabOrder = 11
    OnClick = Button1Click
  end
  object Table1: TTable
    Active = True
    DatabaseName = 'PROBA'
    TableName = 'Tovary.db'
    Left = 104
    Top = 16
  end
  object DataSource1: TDataSource
    DataSet = Table1
    Left = 56
    Top = 16
  end
  object Table2: TTable
    Active = True
    DatabaseName = 'PROBA'
    IndexFieldNames = 'DatPrih;Tovar'
    TableName = 'Prihod.DB'
    Left = 24
    Top = 176
    object Table2Tovar: TStringField
      FieldName = 'Tovar'
      Required = True
    end
    object Table2DatPrih: TDateField
      FieldName = 'DatPrih'
      Required = True
    end
    object Table2Kolvo: TIntegerField
      FieldName = 'Kolvo'
      Required = True
    end
  end
  object DataSource2: TDataSource
    DataSet = Table2
    Left = 64
    Top = 176
  end
end
