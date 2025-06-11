#ifndef LANGUAGESWITCH_H
#define LANGUAGESWITCH_H

#include "mainwindow.h"
#include <QTranslator>

class MainWindow;

/**
 * @brief Класс для управления переводами интерфейса
 * @details Реализует паттерн Singleton для централизованного управления локализацией
 */
class LanguageSwitch: public QObject
{
    Q_OBJECT

public:
    /**
     * @brief Возвращает единственный экземпляр класса
     * @return Указатель на экземпляр LanguageSwitch
     */
    static LanguageSwitch* GetInstance();

private:
    static LanguageSwitch* instance; ///< Единственный экземпляр класса
    QList<MainWindow*> mainWindowList; ///< Список главных окон приложения
    QTranslator* appTranslator = new QTranslator; ///< Переводчик кастомных текстов
    QTranslator* qtTranslator = new QTranslator; ///< Переводчик системных текстов
    QString language = ""; ///< Текущий язык интерфейса

protected:
    /**
     * @brief Конструктор по умолчанию
     */
    LanguageSwitch(){};

public:
    /**
     * @brief Добавляет главное окно в список
     * @param window Указатель на главное окно
     */
    void append(MainWindow* window);

    /**
     * @brief Удаляет главное окно из списка
     * @param window Указатель на главное окно
     */
    void pop(MainWindow* window);

    /**
     * @brief Переводит все окна приложения
     */
    void translateAll();

    /**
     * @brief Загружает кастомный переводчик
     * @param locale Язык для перевода
     */
    void loadAppTranslator(QString locale);

    /**
     * @brief Загружает системный переводчик
     * @param locale Язык для перевода
     */
    void loadQtTranslator(QString locale);

    /**
     * @brief Устанавливает язык приложения
     * @param locale Язык интерфейса
     */
    void setAppLanguage(QString locale);

    /**
     * @brief Возвращает текущий язык приложения
     * @return Текущий язык
     */
    QString getAppLanguage();
};

#endif // LANGUAGESWITCH_H
