#ifndef FIND_H
#define FIND_H

#include <QDialog>

namespace Ui {
class Find;
}

/**
 * Find
 * Класс отображения интерфеса для поска
 * Класс отвечает отображение интерфеса поиска
 */
class Find : public QDialog
{
    Q_OBJECT

signals:
    /**
     * Сигнал, о том, что нужно произвести поиск
     * column столбец, в котором нужно произвести поиск
     * filter строка, фильтр для поиска
     */
    void findSignal(int column, const QString& filter);

    /// Сигнал о закрытии окна поиска
    void findclosed();

protected:

    /**
     * Обработчик события закрытия окна.
     * event Событие закрытия окна.
     */
    void closeEvent(QCloseEvent *event) override;

public:
    /// Конструктор по умолчанию
    explicit Find(QDialog *parent = nullptr);

    /// Деструктор по умолчанию
    ~Find();

    /**
     * Метод, переводящий интерфейс
     */
    void retranslate();

    /**
     * Метод, устанавливающий новое имя для окна
     * parentPart строка - имя прявязанного основоного окна
     */
    void setNewWindowName(QString parentPart);

private slots:
    /// Слот, обрабатывающий нажатие на кнопку "закрыть"
    void on_closeButton_clicked();

    /**
     * Слот, обрабатывающий изменение в строке для ввода теста поиска
     * arg1 тест в строке для поиска
     */
    void on_lineEdit_textChanged(const QString &arg1);


    /**
     * Слот, обрабатывающий изменение в ComboBox выбора столбца сортироки
     * index Индекс выбранного столбца сортировки
     */
    void on_columnBox_currentIndexChanged(int index);

private:
    /// Ссылка на интерфейс окна
    Ui::Find *ui;

    /// Хранит оригинальное название окна (Название в состоянии когда файл не открыт)
    QString orginalTitle = "";

};

#endif // FIND_H
