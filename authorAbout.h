#ifndef AUTHORABOUT_H
#define AUTHORABOUT_H

#include <QDialog>

namespace Ui {
class AuthorAbout;
}

/**
 * @brief Класс диалогового окна "Об авторе"
 * @details Отображает информацию об авторе и предоставляет кнопку для закрытия окна.
 */
class AuthorAbout : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса AuthorAbout
     * @param parent Родительский виджет (по умолчанию nullptr)
     */
    explicit AuthorAbout(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса AuthorAbout
     * @details Освобождает ресурсы, связанные с пользовательским интерфейсом.
     */
    ~AuthorAbout();

private slots:
    /**
     * @brief Слот для обработки нажатия кнопки "OK"
     * @details Закрывает текущее диалоговое окно.
     */
    void on_okButton_clicked();

private:
    /// Указатель на сгенерированный интерфейс окна
    Ui::AuthorAbout *ui;
};

#endif // AUTHORABOUT_H
