#include "table.hpp"
#include "data.hpp"
#include "mainwindow.h"
#include "date.h"

#include <QMessageBox>

MyTableModel::MyTableModel(QObject *parent) : QAbstractTableModel(parent), columnsNum(9)
{}

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return DataModelList.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return columnsNum;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    int row = index.row();
    int column = index.column();

    switch(role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
        switch (column)
        {
        case 0: return DataModelList.at(row).getID();
        case 1: return DataModelList.at(row).getName();
        case 2: return DataModelList.at(row).getType();
        case 3: return DataModelList.at(row).getMark();
        case 4: return DataModelList.at(row).getLenght();
        case 5: return DataModelList.at(row).getWidth();
        case 6: return DataModelList.at(row).getWeight();
        case 7: return DataModelList.at(row).getFittings();
        case 8: return DataModelList.at(row).getDate();
            break;
        }
    default:
        return QVariant();
    }
}

bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role == Qt::EditRole)
    {
        layoutAboutToBeChanged();

        int row = index.row();
        int column = index.column();

        switch (column)
        {
        case 0: DataModelList[row].setID(value.toInt()); break;
        case 1: DataModelList[row].setName(value.toString()); break;
        case 2: DataModelList[row].setType(value.toString()); break;
        case 3: DataModelList[row].setMark(value.toString()); break;
        case 4: DataModelList[row].setLength(value.toDouble()); break;
        case 5: DataModelList[row].setWidth(value.toDouble()); break;
        case 6: DataModelList[row].setWeight(value.toDouble()); break;
        case 7: DataModelList[row].setFittings(value.toString()); break;
        case 8: DataModelList[row].setDate(value.toString()); break;
        }

        emit modelDataChanged();
        layoutChanged();

        return true;
    }
    return false;
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section)
        {
        case 0: return tr("ID");
        case 1: return tr("Name");
        case 2: return tr("Type");
        case 3: return tr("Mark");
        case 4: return tr("Length");
        case 5: return tr("Width");
        case 6: return tr("Weight");
        case 7: return tr("Fittings");
        case 8: return tr("Date");
        }
    return QVariant();
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const
{
    if(index.isValid())
        return  Qt::ItemIsEnabled |
               Qt::ItemIsSelectable |
               Qt::ItemIsEditable |
               Qt::ItemIsDragEnabled |
               Qt::ItemIsDropEnabled;
    else
        return Qt::NoItemFlags;
}

bool MyTableModel::appendRow(const Data &value)
{
    int position = rowCount();
    beginInsertRows(QModelIndex(), position, position);
    DataModelList.append(value);
    endInsertRows();
    return true;
}

bool MyTableModel::removeRow(const int position)
{
    if (DataModelList.isEmpty()) return false;

    beginRemoveRows(QModelIndex(), position, position);
    DataModelList.removeAt(position);
    emit modelDataChanged();
    endRemoveRows();
    return true;
}

Data MyTableModel::getDataFromTable(int row)
{
    return DataModelList.at(row);
}

void MyTableModel::dropTable()
{
    int rows = rowCount();
    for (int deletedrows = 0; deletedrows < rows; ++deletedrows) removeRow(0);
    emit dataChanged(this->index(0, 0), this->index(0, 0));
}

void MyTableModel::overWriteData(int row, const Data &value)
{
    layoutAboutToBeChanged();
    DataModelList.replace(row, value);
    emit dataChanged(this->index(0, 0), this->index(0, 0));
    layoutChanged();
}

void MyTableModel::updateHeaders()
{
    emit headerDataChanged(Qt::Horizontal, 0, columnCount() - 1);
}
