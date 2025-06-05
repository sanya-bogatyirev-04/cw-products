#ifndef GRAPF_H
#define GRAPF_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui {
class Grapf;
}

/**
 *   Grapf
 *   Класс отображения графика
 *   Класс отвечает за вычисление и отображние графика
 */
class Grapf : public QDialog
{
    Q_OBJECT

signals:
    /**
     *   Сигнал о том, что окно с графиком закрыто.
     */
    void grapfClosed();

public:
    /**
     *   Метод, записывающий значение в словарь
     *   Если ключ существует, то значение добавляется по ключу, иначе создается новое
     *   type тип изделия - ключ
     *   length длина - значение
     */
    void insertIntoMap(QString type, double length);

    /**
     *   Метод, полностью очищающий словарь
     */
    void dropMapData();

    /**
     *   Метод, переводящий интерфейс
     */
    void retranslate();

    /**
     *   Метод, устанавливающий новое имя для окна
     *   parentPart строка - имя прявязанного основоного окна
     */
    void setNewWindowName(QString parentPart);

protected:
    /**
     *   Обработчик события закрытия окна.
     *   event Событие закрытия окна.
     */
    void closeEvent(QCloseEvent *event) override;

    /**
     *   Обработчик события отрисовки графика.
     *   Вычисляет и полностью отрисовывает график на основе данных словаря
     *   event Событие рисования в окне.
     */
    void paintEvent(QPaintEvent *event) override;

public:
    ///   Конструктор по умолчанию
    explicit Grapf(QWidget *parent = nullptr);

    ///   Деструктор по умолчанию
    ~Grapf();

private:
    ///   Ссылка на интерфейс окна
    Ui::Grapf *ui;

    ///   Словарь для построения графика
    QMap<QString, double> data;

    ///   Хранит оригинальное название окна (Название в состоянии когда файл не открыт)
    QString orginalTitle = "";
};

#endif // GRAPF_H
