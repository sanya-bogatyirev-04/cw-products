#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP

#include <QStyledItemDelegate>

/**
  * @class ComboBox
  * @brief Класс позволяет использовать QComboBox в качестве редактора ячеек
  */
class ComboBox: public QStyledItemDelegate
{
    Q_OBJECT

    /// @brief Переменная хранит список значений для выбора в comboBox
    QStringList listOptions;

public:
    /// @brief Конструктор по умолчанию
    explicit ComboBox(QWidget *parent = nullptr);


    /**
      * @brief Метод для создания виджета-редактора с объектом типа QComboBox
      * @param parent Родительский виджет
      * @param option Параметры
      * @param index Индекс
      * @return Указатель на созданный виджет
      */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /**
      * @brief Метод для передачи значения из в таблицы в виджет-редактор
      * @param editor Указатель на редактор.
      * @param index Индекс ячейки.
      */
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;

    /**
      * @brief Метод для передачи значения из виджета-редактора в таблицу
      * @param editor Указатель на редактор.
      * @param model Указатель на данные.
      * @param index Индекс ячейки.
      */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;

    /// @brief Метод, устанавливающий значения в listOptions.
    void setData(const QStringList &strList);
};


#endif // COMBOBOX_HPP
