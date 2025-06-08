QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    authorAbout.cpp \
    comboBox.cpp \
    table.cpp \
    data.cpp \
    file.cpp \
    find.cpp \
    findWindow.cpp \
    language.cpp \
    languageSwitch.cpp \
    main.cpp \
    mainwindow.cpp \
    row.cpp

HEADERS += \
    authorAbout.h \
    comboBox.hpp \
    table.hpp \
    data.hpp \
    find.h \
    languageSwitch.h \
    mainwindow.h

FORMS += \
    authorAbout.ui \
    find.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += translations.qrc

DISTFILES += \
    pr-products.pro.user \
    translations/my_en_US.qm \
    translations/my_ru_RU.qm

TRANSLATIONS += \
    translations/my_en_US.ts \
    translations/my_ru_RU.ts
