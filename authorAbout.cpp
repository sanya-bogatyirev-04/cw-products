#include "authorAbout.h"
#include "ui_authorAbout.h"

AuthorAbout::AuthorAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AuthorAbout)
{
    ui->setupUi(this); // Инициализация интерфейса для окна
}

AuthorAbout::~AuthorAbout()
{
    delete ui; // Освобождение памяти, выделенной для интерфейса
}

void AuthorAbout::on_okButton_clicked()
{
    this->close(); // Закрытие диалогового окна
}

