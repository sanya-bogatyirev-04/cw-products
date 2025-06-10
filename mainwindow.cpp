#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.hpp"
#include "authorAbout.h"
#include "find.h"
#include "languageSwitch.h"
#include "comboBox.hpp"
#include "date.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QSettings>
#include <QModelIndex>
#include <QFontMetrics>
#include <QCloseEvent>
#include <cmath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , model(new MyTableModel(this))
    , sortmodel(new QSortFilterProxyModel(this))
{
    ui->setupUi(this);
    loadSettings();
    LanguageSwitch::GetInstance()->append(this);
    setStateWhenFileOpened(false);

    sortmodel->setSourceModel(model);
    ui->tableView->setModel(sortmodel);
    sortmodel->setFilterCaseSensitivity(Qt::CaseInsensitive);
    connect(model, SIGNAL(modelDataChanged()), this, SLOT(modelDataChanged()));
    ui->tableView->verticalHeader()->hide();

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->tableView, &QWidget::customContextMenuRequested, this, &MainWindow::showCustomContextMenu);

    find = new Find();
    connect(find, SIGNAL(findSignal(int, const QString&)), this, SLOT(findHandler(int, const QString&)));
    connect(find, SIGNAL(findclosed()), this, SLOT(findCloseHandler()));

    changeLanguage(LanguageSwitch::GetInstance()->getAppLanguage());
    setDefaultHeadersSizes();
    originalTitle = this->windowTitle();
    this->activateWindow();

    ComboBox *typeDelegate = new ComboBox(ui->tableView);
    ComboBox *reinDelegate = new ComboBox(ui->tableView);
    ComboBox *markDelegate = new ComboBox(ui->tableView);

    typeDelegate->setData(QStringList({ "Плита", "Блок", "Колонна", "Лестница", "Перемычка", "Ферма", "Ригель", "Свая", "Кольцо"}));
    ui->tableView->setItemDelegateForColumn(2, typeDelegate);

    reinDelegate->setData(QStringList({ "А500С", "А400С", "А240С", "А600С"}));
    ui->tableView->setItemDelegateForColumn(7, reinDelegate);

    markDelegate->setData(QStringList({ "B20", "B15", "B25", "B30", "B10", "B40"}));
    ui->tableView->setItemDelegateForColumn(3, markDelegate);

    Date *date = new Date(this);
    ui->tableView->setItemDelegateForColumn(8, date);
}

// void MainWindow::on_actionFind_triggered()
// {
//     find->setupStaticColumns();
//     find->show();
// }

void MainWindow::setDefaultHeadersSizes()
{
    ui->tableView->horizontalHeader()->resizeSection(0, 85);
    ui->tableView->horizontalHeader()->resizeSection(1, 115);
    ui->tableView->horizontalHeader()->resizeSection(2, 115);
    ui->tableView->horizontalHeader()->resizeSection(3, 125);
    ui->tableView->horizontalHeader()->resizeSection(4, 125);
    ui->tableView->horizontalHeader()->resizeSection(5, 120);
    ui->tableView->horizontalHeader()->resizeSection(6, 125);
    ui->tableView->horizontalHeader()->resizeSection(7, 85);
    ui->tableView->horizontalHeader()->resizeSection(8, 100);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if(!suggestSaveFile())
    {
        event->ignore(); return;
    }

    QMessageBox::StandardButton reply =
        QMessageBox::question(this,
                              tr("Exit from app"),
                              tr("Close app?"),
                              QMessageBox::Yes | QMessageBox::No);

    if(reply == QMessageBox::Yes)
    {
        saveSettings();
        if(find) find->close();
        LanguageSwitch::GetInstance()->pop(this);
        event->accept();
    }
    else
    {
        event->ignore();
    }
}

MainWindow::~MainWindow()
{
    delete model;
    delete sortmodel;
    delete find;
    delete delegateFinansing;
    delete delegateActive;
    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings("MGSU", "pr-products");
    settings.beginGroup("MainWindowGeometry");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("position", QPoint(200, 200)).toPoint());
    settings.endGroup();

    if(LanguageSwitch::GetInstance()->getAppLanguage() == "")
        LanguageSwitch::GetInstance()->setAppLanguage(settings.value("language").toString());
}

void MainWindow::saveSettings()
{
    QSettings settings("MGSU", "pr-products");
    settings.beginGroup("MainWindowGeometry");
    settings.setValue("size", size());
    settings.setValue("position", pos());
    settings.endGroup();
    settings.setValue("language", LanguageSwitch::GetInstance()->getAppLanguage());
}

void MainWindow::on_actionNew_triggered()
{
    if(!suggestSaveFile())
        return;
    if(find) find->close();
    model->dropTable();
    openedPath = "~untitled.db";
    somethingMightChanged = true;
    setStateWhenFileOpened(true);
    setDefaultHeadersSizes();
    model->appendRow();
    ui->tableView->selectRow(0);
}

void MainWindow::on_actionOpen_triggered()
{
    if(!suggestSaveFile())
        return;

    QString filePath =
        QFileDialog::getOpenFileName(this,
                                     tr("Open File"),
                                     QDir::currentPath(),
                                     tr("Text Files( *.txt , *.dat , *.db);;All Files (*)"),
                                     nullptr);

    if(loadfile(filePath))
    {
        if(find) find->close();
        openedPath = filePath;
        setStateWhenFileOpened(true);
        somethingMightChanged = false;
        ui->tableView->setCurrentIndex(sortmodel->sourceModel()->index(0,0));
        ui->tableView->selectRow(0);
        ui->tableView->resizeColumnsToContents();
    }
}

void MainWindow::on_actionClose_triggered()
{
    if(!suggestSaveFile())
        return;

    openedPath = "";
    model->dropTable();
    if(find) find->close();
    somethingMightChanged = false;
    setStateWhenFileOpened(false);
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSave_triggered()
{
    if(openedPath == "~untitled.db")
    {
        ui->actionSave_as->trigger();
        return;
    }

    savefile(openedPath);
}

void MainWindow::on_actionSave_as_triggered()
{
    QString filePath =
        QFileDialog::getSaveFileName(this,
                                     tr("Save File"),
                                     QDir::currentPath(),
                                     tr("Text Files( *.txt , *.dat , *.db);;All Files (*)"),
                                     nullptr,
                                     QFileDialog::DontUseNativeDialog);

    if(savefile(filePath))
    {
        if(openedPath == "~untitled.db")
            openedPath = filePath;
    }
}

void MainWindow::setStateWhenFileOpened(bool state)
{
    ui->tableView->setEnabled(state);
    ui->actionSave_as->setEnabled(state);
    ui->actionClose->setEnabled(state);
    ui->menuEdit->setEnabled(state);
    ui->actionAdd_row->setEnabled(state);
    ui->actionRemove_row->setEnabled(state);
    ui->actionCut_row->setEnabled(state);
    ui->actionCopy_row->setEnabled(state);
    ui->actionFind->setEnabled(state);
    ui->actionSortDeny->setEnabled(state);
    ui->menuFilter->setEnabled(state);
    ui->actionSave->setEnabled(state);
    ui->actionPaste_row->setEnabled(state);
}

void MainWindow::showCustomContextMenu(const QPoint& pos)
{
    QMenu menu;

    menu.addAction(ui->actionRemove_row);
    menu.addAction(ui->actionCut_row);
    menu.addAction(ui->actionCopy_row);
    menu.addAction(ui->actionPaste_row);

    if(sortmodel->sortColumn() != -1)
    {
        menu.addSeparator();
        menu.addAction(ui->actionSortDeny);
    }

    menu.exec(ui->tableView->viewport()->mapToGlobal(pos));
}

void MainWindow::on_actionAutor_triggered()
{
    AuthorAbout aboutDialog;
    aboutDialog.setModal(true);
    aboutDialog.exec();
}

void MainWindow::on_actionSortDeny_triggered()
{
    sortmodel->sort(-1);
}


void MainWindow::modelDataChanged()
{
    somethingMightChanged = true;
}

void MainWindow::updateTableHeaders()
{
    model->updateHeaders();
}
