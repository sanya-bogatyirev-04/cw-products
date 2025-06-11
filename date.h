#ifndef DATE_H
#define DATE_H

#include <QStyledItemDelegate>
#include <QDateEdit>

/**
 * @brief Делегат для работы с датами в таблице
 * @details Предоставляет QDateEdit для редактирования дат в ячейках таблицы.
 */
class Date : public QStyledItemDelegate
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса Date
     * @param parent Родительский объект (по умолчанию nullptr)
     */
    explicit Date(QObject *parent = nullptr);

    /**
     * @brief Создает редактор даты (QDateEdit) для ячейки таблицы
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
     * @brief Сохраняет данные из редактора в модель
     * @param editor Указатель на редактор
     * @param model Указатель на модель
     * @param index Индекс модели
     */
    void setModelData(QWidget *editor,
                      QAbstractItemModel *model,
                      const QModelIndex &index) const override;
};

#endif // DATE_H
