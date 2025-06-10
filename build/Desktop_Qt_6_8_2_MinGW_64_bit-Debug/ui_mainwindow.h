/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRussian;
    QAction *actionEnglish;
    QAction *actionOpen;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionNew;
    QAction *actionSave_as;
    QAction *actionSave;
    QAction *actionAdd_row;
    QAction *actionRemove_row;
    QAction *actionCopy_row;
    QAction *actionCut_row;
    QAction *actionPaste_row;
    QAction *actionFind;
    QAction *actionAutor;
    QAction *actionSortDeny;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuLanguage;
    QMenu *menuAbout;
    QMenu *menuEdit;
    QMenu *menuFilter;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1030, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(950, 250));
        actionRussian = new QAction(MainWindow);
        actionRussian->setObjectName("actionRussian");
        actionEnglish = new QAction(MainWindow);
        actionEnglish->setObjectName("actionEnglish");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/eng.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        actionEnglish->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName("actionClose");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        QFont font;
        actionNew->setFont(font);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName("actionSave_as");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionAdd_row = new QAction(MainWindow);
        actionAdd_row->setObjectName("actionAdd_row");
        actionRemove_row = new QAction(MainWindow);
        actionRemove_row->setObjectName("actionRemove_row");
        actionCopy_row = new QAction(MainWindow);
        actionCopy_row->setObjectName("actionCopy_row");
        actionCut_row = new QAction(MainWindow);
        actionCut_row->setObjectName("actionCut_row");
        actionPaste_row = new QAction(MainWindow);
        actionPaste_row->setObjectName("actionPaste_row");
        actionFind = new QAction(MainWindow);
        actionFind->setObjectName("actionFind");
        actionAutor = new QAction(MainWindow);
        actionAutor->setObjectName("actionAutor");
        actionSortDeny = new QAction(MainWindow);
        actionSortDeny->setObjectName("actionSortDeny");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        tableView = new QTableView(centralwidget);
        tableView->setObjectName("tableView");
        tableView->setEditTriggers(QAbstractItemView::EditTrigger::AnyKeyPressed|QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed);
        tableView->setDragDropOverwriteMode(false);
        tableView->setDragDropMode(QAbstractItemView::DragDropMode::NoDragDrop);
        tableView->setDefaultDropAction(Qt::DropAction::IgnoreAction);
        tableView->setAlternatingRowColors(true);
        tableView->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableView->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableView->setSortingEnabled(true);

        verticalLayout->addWidget(tableView);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1030, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuLanguage = new QMenu(menubar);
        menuLanguage->setObjectName("menuLanguage");
        menuAbout = new QMenu(menubar);
        menuAbout->setObjectName("menuAbout");
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName("menuEdit");
        menuFilter = new QMenu(menubar);
        menuFilter->setObjectName("menuFilter");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuFilter->menuAction());
        menubar->addAction(menuAbout->menuAction());
        menubar->addAction(menuLanguage->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionClose);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuLanguage->addAction(actionRussian);
        menuLanguage->addAction(actionEnglish);
        menuAbout->addAction(actionAutor);
        menuEdit->addAction(actionAdd_row);
        menuEdit->addAction(actionRemove_row);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut_row);
        menuEdit->addAction(actionCopy_row);
        menuEdit->addAction(actionPaste_row);
        menuEdit->addSeparator();
        menuFilter->addAction(actionFind);
        menuFilter->addAction(actionSortDeny);
        menuFilter->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionRussian->setText(QCoreApplication::translate("MainWindow", "\320\240\321\203\321\201\321\201\320\272\320\270\320\271", nullptr));
        actionEnglish->setText(QCoreApplication::translate("MainWindow", "English", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionClose->setText(QCoreApplication::translate("MainWindow", "Close", nullptr));
#if QT_CONFIG(shortcut)
        actionClose->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+W", nullptr));
#endif // QT_CONFIG(shortcut)
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionNew->setText(QCoreApplication::translate("MainWindow", "Create", nullptr));
#if QT_CONFIG(shortcut)
        actionNew->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave_as->setText(QCoreApplication::translate("MainWindow", "Save as", nullptr));
#if QT_CONFIG(shortcut)
        actionSave_as->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Shift+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
#if QT_CONFIG(shortcut)
        actionSave->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAdd_row->setText(QCoreApplication::translate("MainWindow", "Add to end", nullptr));
#if QT_CONFIG(shortcut)
        actionAdd_row->setShortcut(QCoreApplication::translate("MainWindow", "Ins", nullptr));
#endif // QT_CONFIG(shortcut)
        actionRemove_row->setText(QCoreApplication::translate("MainWindow", "Remove", nullptr));
#if QT_CONFIG(shortcut)
        actionRemove_row->setShortcut(QCoreApplication::translate("MainWindow", "Del", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCopy_row->setText(QCoreApplication::translate("MainWindow", "Copy", nullptr));
#if QT_CONFIG(shortcut)
        actionCopy_row->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_CONFIG(shortcut)
        actionCut_row->setText(QCoreApplication::translate("MainWindow", "Cut", nullptr));
#if QT_CONFIG(shortcut)
        actionCut_row->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+X", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPaste_row->setText(QCoreApplication::translate("MainWindow", "Paste", nullptr));
#if QT_CONFIG(shortcut)
        actionPaste_row->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+V", nullptr));
#endif // QT_CONFIG(shortcut)
        actionFind->setText(QCoreApplication::translate("MainWindow", "Find", nullptr));
#if QT_CONFIG(shortcut)
        actionFind->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+F", nullptr));
#endif // QT_CONFIG(shortcut)
        actionAutor->setText(QCoreApplication::translate("MainWindow", "Author", nullptr));
        actionSortDeny->setText(QCoreApplication::translate("MainWindow", "Ruturn to original sorting", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuLanguage->setTitle(QCoreApplication::translate("MainWindow", "Language", nullptr));
        menuAbout->setTitle(QCoreApplication::translate("MainWindow", "About", nullptr));
        menuEdit->setTitle(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        menuFilter->setTitle(QCoreApplication::translate("MainWindow", "Filter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
