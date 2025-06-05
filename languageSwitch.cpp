#include "languageSwitch.h"
#include <QTranslator>
#include <QLibraryInfo>
#include <QApplication>

LanguageSwitch* LanguageSwitch::instance = NULL;

LanguageSwitch* LanguageSwitch::GetInstance(void)
{
    if (!instance) instance = new LanguageSwitch;
    return instance;
}

void LanguageSwitch::append(MainWindow *window)
{
    mainWindowList.append(window);
}

void LanguageSwitch::pop(MainWindow *window)
{
    mainWindowList.removeOne(window);
}

void LanguageSwitch::translateAll()
{
    for (MainWindow* mainWindow : mainWindowList)
    {
        qDebug() << "Translating window with title:" << mainWindow->windowTitle();
        mainWindow->retranslate();
        mainWindow->originalTitle = mainWindow->windowTitle();
        qDebug() << "New original title set:" << mainWindow->originalTitle;
        mainWindow->setNewWindowTitle();
        qDebug() << "Window title after translation:" << mainWindow->windowTitle();
    }
}

void LanguageSwitch::loadAppTranslator(QString locale)
{
    if(locale == "") locale = "ru_RU";
    bool loaded = appTranslator->load(":translations/my_" + locale + ".qm");
    if (!loaded) {
        qDebug() << "Failed to load translation file:" << ":translations/my_" + locale + ".qm";
    } else {
        qDebug() << "Successfully loaded translation file:" << ":translations/my_" + locale + ".qm";
    }
    qApp->installTranslator(appTranslator);
}

void LanguageSwitch::setAppLanguage(QString lang)
{
    language = lang;
}

QString LanguageSwitch::getAppLanguage()
{
    return language;
}
