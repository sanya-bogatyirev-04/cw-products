#ifndef LANGUAGESWITCH_H
#define LANGUAGESWITCH_H

#include "mainwindow.h"

#include <QTranslator>

class MainWindow;

/**
 *   LanguageSwitch
 *   Собственный класс переводчика
 */
class LanguageSwitch: public QObject
{
    Q_OBJECT

public:
    /**
     *   Метод, дающий доступ к единственному объекту класса.
     *   возвращает единственный экземпляр класса LanguageSwitch.
     */
    static LanguageSwitch* GetInstance();

private:
   ///   Ссылка на единственный объект класса
   static LanguageSwitch* instance;

   ///   Список ссылок на все открые главные окна приложения
   QList<MainWindow*> mainWindowList;

   ///   Ссылка на переводчик кастомных тектов
   QTranslator* appTranslator = new QTranslator;

    ///   Ссылка на переводчик системных тектов
   QTranslator* qtTranslator = new QTranslator;

   ///   Строка, хранящая текущий выбранный язык
   QString language = "";

protected:
   /**
    *   Конструктор по умолччанию
    */
   LanguageSwitch(){};

public:
   /**
    *   Метод, добавляющий ссылку на главное окно в список ссылкок на главные окна
    *   window ссылка на окно котороое нужно добавить
    */
   void append(MainWindow* window);

   /**
    *   Метод, удаляющий ссылку на главное окно из списка ссылкок на главные окна
    *   window ссылка на окно котороое нужно удалить
    */
   void pop(MainWindow* window);

   /**
    *   Метод, переводящий все окна в приложении на выбранный язык
    */
   void translateAll();

   /**
    *   Метод, устанавлювающий новый кастомный переводчик в приложение
    *   locale язык, который нужно загрузить
    */
   void loadAppTranslator(QString locale);

   /**
    *   Метод, устанавливающий системный переводчик в приложении
    *   locale язык, который нужно загрузить
    */
   void loadQtTranslator(QString locale);

   /**
    *   Метод, устанавливающий системный язык
    *   locale язык, который нужно записать как новый выбранный
    */
   void setAppLanguage(QString locale);

   /**
    *   Метод, возвращающий текущий системный язык
    *   Строка, содержащая информацию о текущем системном языке
    */
   QString getAppLanguage();
};

#endif // LANGUAGESWITCH_H
