#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP

#include <QStyledItemDelegate>

/**
  *   ComboBox
  *   Класс позволяет использовать QComboBox в качестве редактора ячеек
  */
class ComboBox: public QStyledItemDelegate
{
    Q_OBJECT

    ///   Переменная хранит список значений для выбора в comboBox
    QStringList listOptions;

public:
    ///   Конструктор по умолчанию
    explicit ComboBox(QWidget *parent = nullptr);


    /**
      *   Метод для создания виджета-редактора с объектом типа QComboBox
      *   parent Родительский виджет
      *   option Параметры
      *   index Индекс
      *   Указатель на созданный виджет
      */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /**
      *   Метод для передачи значения из в таблицы в виджет-редактор
      *   editor Указатель на редактор.
      *   index Индекс ячейки.
      */
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;

    /**
      *   Метод для передачи значения из виджета-редактора в таблицу
      *   editor Указатель на редактор.
      *   model Указатель на данные.
      *   index Индекс ячейки.
      */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    ///   Метод, устанавливающий значения в listOptions.
    void setData(const QStringList &strList);
};


#endif // COMBOBOX_HPP
