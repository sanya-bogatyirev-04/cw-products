#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Создавем объект который управляет работой приложения

    a.setApplicationName("reinforced concrete structures"); // Устанавливаем название приложения
    MainWindow *w = new MainWindow; // Создается окно приложения
    w->show(); // Показываем окно
    return a.exec(); // Запускаем приложение
}
