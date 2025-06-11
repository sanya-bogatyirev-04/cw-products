#ifndef FIND_H
#define FIND_H

#include <QDialog>

namespace Ui {
class Find;
}

/**
 * @brief Класс диалогового окна поиска
 * @details Предоставляет интерфейс для поиска и фильтрации данных в таблице
 */
class Find : public QDialog
{
    Q_OBJECT

signals:
    /**
     * @brief Сигнал запроса поиска
     * @param column Номер столбца для поиска
     * @param filter Строка фильтра
     */
    void findSignal(int column, const QString& filter);

    /**
     * @brief Сигнал о закрытии окна поиска
     * @details Отменяет активную фильтрацию при закрытии окна
     */
    void findclosed();

protected:
    /**
     * @brief Обработчик события закрытия окна
     * @param event Событие закрытия окна
     */
    void closeEvent(QCloseEvent *event) override;

public:
    /**
     * @brief Конструктор класса Find
     * @param parent Родительский виджет
     */
    explicit Find(QDialog *parent = nullptr);

    /**
     * @brief Деструктор класса Find
     */
    ~Find();

    /**
     * @brief Заполняет ComboBox статическими данными
     * @details Инициализирует выпадающий список столбцами для поиска
     */
    void setupStaticColumns();

    /**
     * @brief Переводит интерфейс окна
     */
    void retranslate();

    /**
     * @brief Устанавливает новое имя для окна
     * @param parentPart Часть названия родительского окна
     */
    void setNewWindowName(QString parentPart);

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "Закрыть"
     */
    void on_closeButton_clicked();

    /**
     * @brief Слот для обработки изменения текста поиска
     * @param arg1 Текст для поиска
     */
    void on_lineEdit_textChanged(const QString &arg1);

    /**
     * @brief Слот для обработки изменения выбранного столбца
     * @param index Индекс выбранного столбца
     */
    void on_columnBox_currentIndexChanged(int index);

private:
    Ui::Find *ui; ///< Указатель на интерфейс окна
    QString orginalTitle = ""; ///< Оригинальное название окна
};

#endif // FIND_H
