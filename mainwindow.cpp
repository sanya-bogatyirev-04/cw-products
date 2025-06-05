#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.hpp"
#include "authorAbout.h"
#include "find.h"
#include "languageSwitch.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFileInfo>
#include <QTextStream>
#include <QSettings>
#include <QModelIndex>
#include <QPainter>
#include <QFontMetrics>
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

    grapf = new Grapf();
    find = new Find();
    connect(find, SIGNAL(findSignal(int, const QString&)), this, SLOT(findHandler(int, const QString&)));
    connect(find, SIGNAL(findclosed()), this, SLOT(findCloseHandler()));

    changeLanguage(LanguageSwitch::GetInstance()->getAppLanguage());
    setDefaultHeadersSizes();
    originalTitle = this->windowTitle();
    this->activateWindow();
}

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
        if(grapf) grapf->close();
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
    delete grapf;
    delete delegateFinansing;
    delete delegateActive;
    delete ui;
}

void MainWindow::loadSettings()
{
    QSettings settings("MGSU", "cw-products");
    settings.beginGroup("MainWindowGeometry");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("position", QPoint(200, 200)).toPoint());
    settings.endGroup();

    if(LanguageSwitch::GetInstance()->getAppLanguage() == "")
        LanguageSwitch::GetInstance()->setAppLanguage(settings.value("language").toString());
}

void MainWindow::saveSettings()
{
    QSettings settings("MGSU", "cw-products");
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
    if(grapf) grapf->close();
    model->dropTable();
    openedPath = "~untitled.db";
    somethingMightChanged = true;
    setStateWhenFileOpened(true);
    setDefaultHeadersSizes();
    setNewWindowTitle();
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
        if(grapf) grapf->close();
        openedPath = filePath;
        setStateWhenFileOpened(true);
        somethingMightChanged = false;
        ui->tableView->setCurrentIndex(sortmodel->sourceModel()->index(0,0));
        ui->tableView->selectRow(0);
        ui->tableView->resizeColumnsToContents();
        setNewWindowTitle();
    }
}

void MainWindow::on_actionClose_triggered()
{
    if(!suggestSaveFile())
        return;

    openedPath = "";
    model->dropTable();
    if(find) find->close();
    if(grapf) grapf->close();
    somethingMightChanged = false;
    setStateWhenFileOpened(false);
    setNewWindowTitle();
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
    setNewWindowTitle();
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
        setNewWindowTitle();
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
    ui->actionPrint->setEnabled(state);
    ui->actionSave->setEnabled(state);
    ui->actionPaste_row->setEnabled(state);
    ui->actionGrapf->setEnabled(state);
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

void MainWindow::on_actionNew_window_triggered()
{
    MainWindow *w = new MainWindow;
    w->show();
}

void MainWindow::setNewWindowTitle()
{
    setWindowTitle(originalTitle);
}

void MainWindow::modelDataChanged()
{
    somethingMightChanged = true;
    setNewWindowTitle();
    if(grapf->isVisible())
    {
        emit ui->actionGrapf->trigger();
        grapf->update();
    }
}

void MainWindow::on_actionGrapf_triggered()
{
    grapf->dropMapData();
    int rows = model->rowCount();
    bool emptyDataTable = true;

    for (int row = 0; row < rows; ++row)
    {
        Data tempelem = model->getDataFromTable(row);
        QString name = tempelem.getType();
        double width = tempelem.getLenght();

        if (width <= 0) continue;
        if(emptyDataTable) emptyDataTable = false;
        grapf->insertIntoMap(name, width);
    }
    if(emptyDataTable) return;
    grapf->show();
    grapf->activateWindow();
    grapf->update();
}

void MainWindow::updateTableHeaders()
{
    model->updateHeaders();
}
