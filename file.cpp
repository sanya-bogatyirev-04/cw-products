#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "languageSwitch.h"
#include <QFile>
#include <QStringConverter>
#include <QTextStream>
#include <QMessageBox>

bool MainWindow::savefile(QString filePath)
{
    QFile file(filePath); // Создаем объект для работы с файлом
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("File saving error"), tr("File not saved")); return false; // Сообщаем пользоватею об этом и ничего не сохраняем
    }

    int colums = 0;
    int rows = model->rowCount(); // Получаем кол-во строк
    QTextStream fileout(&file); // Создаем поток для записи в файл
    fileout.setEncoding(QStringConverter::Utf8); // Устанавливаем кодировку потока
    fileout << "~File~is~safe~\n"; // Вписываем особую строку для проверки поддерживаемости файла
    for (int row = 0; row < rows; ++row)
    {
        if (colums < row){
            fileout << "\n";
        }
        Data tempelem = model->getDataFromTable(row); // Получаем данные строки
        fileout << tempelem.getSplitString(); // Записываем файл построчно, получая тектовую версию строки разделенную точку с запятой между элементамии
        colums = row;
    }
    file.close(); // Закрываем файл
    somethingMightChanged = false; // Выключаем флаг о том, что есть несохраенные изменения (тк мы все сохранили)
    return true;
}

bool MainWindow::loadfile(QString filePath)
{
    if (filePath.isEmpty()) // Если выбранный путь файла для открытия пустой то сообщаем пользователю и нечего не открываем
    {
        QMessageBox::warning(this, tr("File opening error"), tr("File not opened"));
        return false;
    }

    QFile file(filePath); // Создаем объект для работы с файлом

    if (!file.open(QFile::ReadOnly | QFile::Text)) // Если файл не открывается для чтения то соообщаем пользоватею об этом и ничего не записываем
    {
        QMessageBox::warning(this, tr("File opening error"), tr("File not opened")); return false;
    }

    QTextStream filein(&file); // Создаем поток для чтения из файла
    filein.setEncoding(QStringConverter::Utf8); // Устанавливаем кодировку потока

    if(filein.readLine() != "~File~is~safe~")
    {
        QMessageBox::warning(this, tr("File opening error"), tr("File not supported")); return false;
        file.close();
        return false;
    }

    model->dropTable(); // Очищаем таблицу

    while (!filein.atEnd())  // Пока не дойдем до конца файла
    {
        QString data = filein.readLine(); // Получаем новую строку
        model->appendRow(Data(data)); // Добавляем в список таблицы новую строку
    }
    file.close(); // Закрываем строку
    return true;
}

bool MainWindow::suggestSaveFile()
{
    if(openedPath == "" or !somethingMightChanged) return true; // Если ничего не менялось, файл не открыт то смысла предлагать сохранять нет

    QMessageBox::StandardButton reply =
                QMessageBox::question(this,
                                      tr("File might have changes"),
                                      tr("Do you want to save it?"),
                                      QMessageBox::Save | QMessageBox::No | QMessageBox::Cancel);

        if(reply==QMessageBox::Save)
        {
            ui->actionSave->trigger();
            return true;
        }
        if(reply==QMessageBox::No)
        {
            return true;
        }
        else return false;
}


