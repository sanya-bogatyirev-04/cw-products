#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "table.hpp"

#include <QMessageBox>
#include <QClipboard>

void MainWindow::on_actionAdd_row_triggered()
{
    if (!model) {
        qWarning() << "Model is not initialized!";
        return;
    }

    int row = model->rowCount();
    Data emptyElement;
    model->appendRow(emptyElement);

    if (sortmodel && ui->tableView) {
        QModelIndex newIndex = sortmodel->mapFromSource(model->index(row, 0));
        ui->tableView->setCurrentIndex(newIndex);
    }
    modelDataChanged();
}

void MainWindow::on_actionRemove_row_triggered()
{
    if (!model || !sortmodel || !ui->tableView) {
        qWarning() << "Required objects not initialized!";
        return;
    }

    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        QMessageBox::information(this, tr("Deletion Error"),
                                 tr("No row selected"));
        return;
    }

    int currentRow = sortmodel->mapToSource(currentIndex).row();
    if (!model->removeRow(currentRow)) {
        QMessageBox::information(this, tr("Deletion Error"),
                                 tr("Failed to remove row or table is empty"));
    }
}

void MainWindow::on_actionCopy_row_triggered()
{
    if (!model || !sortmodel || !ui->tableView) {
        qWarning() << "Required objects not initialized!";
        return;
    }

    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        return;
    }

    int currentRow = sortmodel->mapToSource(currentIndex).row();
    if (currentRow >= 0 && currentRow < model->rowCount()) {
        QApplication::clipboard()->setText(model->getDataFromTable(currentRow).getSplitString());
    }
}

void MainWindow::on_actionCut_row_triggered()
{
    if (!model || !sortmodel || !ui->tableView) {
        qWarning() << "Required objects not initialized!";
        return;
    }

    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        return;
    }

    int currentRow = sortmodel->mapToSource(currentIndex).row();
    if (currentRow >= 0 && currentRow < model->rowCount()) {
        QApplication::clipboard()->setText(model->getDataFromTable(currentRow).getSplitString());
        model->overWriteData(currentRow);
    }
}

void MainWindow::on_actionPaste_row_triggered()
{
    if (!model || !sortmodel || !ui->tableView) {
        qWarning() << "Required objects not initialized!";
        return;
    }

    QModelIndex currentIndex = ui->tableView->currentIndex();
    if (!currentIndex.isValid()) {
        return;
    }

    int currentRow = sortmodel->mapToSource(currentIndex).row();
    if (currentRow >= 0 && currentRow < model->rowCount()) {
        QString line = QApplication::clipboard()->text();
        if (line.count(";") != 9) {
            QMessageBox::warning(this,
                                 tr("Unsupported Input Data Format"),
                                 tr("Data format is not supported.\nYou can paste only rows with 9 columns."));
            return;
        }
        model->overWriteData(currentRow, Data(line));
    }
}
