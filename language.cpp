#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "find.h"
#include "languageSwitch.h"

void MainWindow::changeLanguage(QString locale)
{
    if(locale == "") locale = "ru_RU"; // По умолчанию Ставим Русский язык, если не указано на какой язык переводить
    LanguageSwitch* languageSwitch = LanguageSwitch::GetInstance(); // Получаем единственный объект кастомного переводчика
    languageSwitch->loadAppTranslator(locale); // Устанавливаем ему кастовный перевод
    languageSwitch->translateAll(); // Переводим все окна
    languageSwitch->setAppLanguage(locale); // Обновляем информацию о выбранном языке в переводчике
}

void MainWindow::retranslate()
{
    ui->retranslateUi(this); // Переводик интерфейс
    find->retranslate(); // Переводим окно поиска
}


void MainWindow::on_actionRussian_triggered()
{
    changeLanguage("ru_RU"); // Ставим Русский Язык
}

void MainWindow::on_actionEnglish_triggered()
{
    changeLanguage("en_US"); // Ставим Английский Язык
}
