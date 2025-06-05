#ifndef AUTHORABOUT_H
#define AUTHORABOUT_H

#include <QDialog>

namespace Ui {
class AuthorAbout;
}

/**
 * AuthorAbout
 * Класс отображения интерфейса для с информацией об авторе
 */
class AuthorAbout: public QDialog
{
    Q_OBJECT

public:
    /// Конструктор по умолчанию
    explicit AuthorAbout(QWidget *parent = nullptr);

    /// Деструктор по умолчанию
    ~AuthorAbout();

private slots:
    /// Слот, обрабатывающий нажатие на кнопку "закрыть"
    void on_okButton_clicked();

private:
    /// Ссылка на интерфейс окна
    Ui::AuthorAbout *ui;
};

#endif // AUTHORABOUT_H
