#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "find.h"

void MainWindow::on_actionFind_triggered()
{
    find->setupStaticColumns();
    find->show(); // Показываем диалоговое окно с интерфейсом для поиска
}

void MainWindow::findHandler(int index, const QString &data)
{
    sortmodel->setFilterKeyColumn(index); // Указываем целевой столбец для поиска
    sortmodel->setFilterRegularExpression(handleSortData(data)); // Устанавливаем регулярное выражение для фильтрации
}

void MainWindow::findCloseHandler()
{
    sortmodel->setDynamicSortFilter(false);  // Отключение сортировки в модели
    sortmodel->setFilterRegularExpression(handleSortData("")); // Устанавливаем пустую строку как регулярное выражение чтобы сбросить результат фильтрации и вернуть таблицу и исходный вид
}

QRegularExpression MainWindow::handleSortData(const QString &data)
{
    QRegularExpression regExp(QRegularExpression::escape(data), QRegularExpression::CaseInsensitiveOption); // Создаем регулярное выражение для фильтрации на основе послтупившей строки
    return regExp;
}

