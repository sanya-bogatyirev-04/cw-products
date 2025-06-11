#ifndef TABLE_HPP
#define TABLE_HPP

#include "data.hpp"

#include <QAbstractTableModel>
#include <QMimeData>

/**
 * @brief Кастомная модель таблицы
 * @details Наследует QAbstractTableModel и предоставляет функциональность
 *          для работы с табличными данными строительных изделий.
 */
class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT

    const int columnsNum;     ///< Количество столбцов в таблице
    QList<Data> DataModelList; ///< Список данных таблицы

signals:
    /**
     * @brief Сигнал об изменении данных в модели
     */
    void modelDataChanged();

public:
    /**
     * @brief Конструктор модели
     * @param parent Родительский объект
     */
    explicit MyTableModel(QObject *parent = nullptr);

    /**
     * @brief Возвращает количество строк
     * @param parent Индекс родителя
     * @return Количество строк в модели
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Возвращает количество столбцов
     * @param parent Индекс родителя
     * @return Количество столбцов в модели
     */
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Возвращает данные для отображения
     * @param index Индекс ячейки
     * @param role Роль данных
     * @return Данные в формате QVariant
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     * @brief Возвращает флаги ячейки
     * @param index Индекс ячейки
     * @return Флаги ячейки
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     * @brief Устанавливает данные в модель
     * @param index Индекс ячейки
     * @param value Новое значение
     * @param role Роль данных
     * @return Успешность операции
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    /**
     * @brief Возвращает данные заголовка
     * @param section Секция заголовка
     * @param orientation Ориентация заголовка
     * @param role Роль данных
     * @return Данные заголовка
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     * @brief Добавляет новую строку
     * @param value Данные для добавления
     * @return Успешность операции
     */
    bool appendRow(const Data &value = Data());

    /**
     * @brief Удаляет строку
     * @param position Позиция строки
     * @return Успешность операции
     */
    bool removeRow(const int position);

    /**
     * @brief Возвращает данные из таблицы
     * @param row Номер строки
     * @return Объект Data с данными строки
     */
    Data getDataFromTable(int row);

    /**
     * @brief Очищает таблицу
     */
    void dropTable();

    /**
     * @brief Перезаписывает данные в строке
     * @param row Номер строки
     * @param value Новые данные
     */
    void overWriteData(int row, const Data &value = Data());

    /**
     * @brief Обновляет заголовки столбцов
     */
    void updateHeaders();
};

#endif // TABLE_HPP
