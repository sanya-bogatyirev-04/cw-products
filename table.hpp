#ifndef TABLE_HPP
#define TABLE_HPP

#include "data.hpp"

#include <QAbstractTableModel>
#include <QMimeData>

/**
 *   MyTableModel
 *    Собственная реализация класса QAbstractTableModel.
 *   Отвечает за работу tableView.
 */
class MyTableModel : public QAbstractTableModel
{
    Q_OBJECT

    ///    Кол-во столбцов
    const int columnsNum;

    ///    Список данных для строк в таблице
    QList<Data> DataModelList;

signals:
    ///    Сигнал о прошедших изменениях данных в таблице
    void modelDataChanged();

public:
    ///    Контструктор по умолчанию
    explicit MyTableModel(QObject *parent = nullptr);

    ///    Метод, возвращающий кол-во строк в модели
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    ///    Метод, возвращающий кол-во столбиков в модели
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     *    Метод, возвращающий обработанные данные для отображения в таблице
     *   index Индекс ячейки в модели.
     *   role Роль (отображение, редактирование и тд).
     *   пустой QVariant, или данные для отображения
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     *    Метод, возвращающий набор флагов ячейки
     *   index Индекс ячейки в модели.
     *   Набор активных флагов (параметров) ячейки
     */
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    /**
     *    Метод, обновлящий данные в списке, после взаимодейсвтвия с ними через tableView
     *   index Индекс ячейки в таблице.
     *   value Значение, которое требуется установить
     *   role Роль (отображение, редактирование и тд.).
     *   успешно ли прошла установка данных
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    /**
     *    Метод, возвращает сформированный заголовок
     *   section Столбец в таблице.
     *   orientation Ориентация (для определения строка/столбец).
     *   role Роль (отображение, редактирование и тд.). По умолчанию DisplayRole.
     *   Сформированный заголовок.
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     *    Метод, добавляющий новую строку в список данных.
     *   value Объект класса DataElement, по умолчанию пустой.
     *   bool Запись добавлена успешно.
     */
    bool appendRow(const Data &value = Data());

    /**
     *    Метод, удалияющий строку из списка данных.
     *   position Номер удаляемой строки.
     *   bool Запись удалена успешно.
     */
    bool removeRow(const int position);

    /**
     *    Метод для получения записи из таблицы.
     *   DataElement данные.
     */
    Data getDataFromTable(int);

    ///    Очищает таблицу.
    void dropTable();
    /**
     *    Метод, перезаписывающий данные в заданной строке.
     *   row Строка, в которую нужно перезаписать данные.
     *   value DataElement, на который нужно сделать замену.
     */
    void overWriteData(int row, const Data &value = Data());

    /**
     *    Метод, обновляющий заголовки столбцов.
     *   Уведомляет QTableView о необходимости перерисовки заголовков.
     */
    void updateHeaders();
};

#endif // TABLE_HPP
