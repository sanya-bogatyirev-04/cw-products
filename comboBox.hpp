#ifndef COMBOBOX_HPP
#define COMBOBOX_HPP

#include <QStyledItemDelegate>

/**
 * @brief Делегат для отображения QComboBox в ячейках таблицы
 * @details Позволяет использовать выпадающий список в качестве редактора для ячеек таблицы.
 */
class ComboBox : public QStyledItemDelegate
{
    Q_OBJECT

    QStringList listOptions; ///< Список вариантов для выбора в ComboBox

public:
    /**
     * @brief Конструктор класса ComboBox
     * @param parent Родительский виджет (по умолчанию nullptr)
     */
    explicit ComboBox(QWidget *parent = nullptr);

    /**
     * @brief Создает виджет-редактор (QComboBox) для ячейки таблицы
     * @param parent Родительский виджет
     * @param option Параметры отображения
     * @param index Индекс модели
     * @return Указатель на созданный редактор
     */
    QWidget *createEditor(QWidget *parent,
                          const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    /**
     * @brief Устанавливает данные из модели в редактор
     * @param editor Указатель на редактор
     * @param index Индекс модели
     */
    void setEditorData(QWidget *editor,
                       const QModelIndex &index) const override;

    /**
     * @brief Устанавливает список вариантов для ComboBox
     * @param strList Список строк для отображения
     */
    void setData(const QStringList &strList);
};

#endif // COMBOBOX_HPP
