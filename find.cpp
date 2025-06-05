#include "find.h"
#include "ui_find.h"

#include <QCloseEvent>

Find::Find(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::Find)
{
    ui->setupUi(this);
    orginalTitle = this->windowTitle();
}

Find::~Find()
{
    delete ui;
}

void Find::closeEvent(QCloseEvent *event)
{
    ui->lineEdit->setText(""); // Устанавливаем пустую строку в lineEdit для ввода
    emit this->findclosed(); // Издаем сигнал о том что окно поиска закрыто
    event->accept(); // Принимаем событие об зактытии окна
}

void Find::on_closeButton_clicked()
{
    this->close(); // Закрываем файл
}

void Find::retranslate()
{
    ui->retranslateUi(this); // Переводим файл
    orginalTitle = this->windowTitle(); // Сохраняем новый перевод оригинального названия
}

void Find::setNewWindowName(QString parentPart)
{
    // Формируем новое название окна
    QString windowname = orginalTitle + tr(" in ");
    windowname += parentPart;
    setWindowTitle(windowname);

}

void Find::on_lineEdit_textChanged(const QString &arg1)
{
    emit this->findSignal(ui->columnBox->currentIndex() - 1, arg1); // издаем сигнал о том что нужно осущесвить фильтрацию
}

void Find::on_columnBox_currentIndexChanged(int index)
{
    Q_UNUSED(index);
    emit this->findSignal(ui->columnBox->currentIndex() - 1, ui->lineEdit->text()); // издаем сигнал о том что нужно осущесвить фильтрацию
}

