#include "date.h"

Date::Date(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *Date::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);

    QDateEdit *editor = new QDateEdit(parent);
    editor->setCalendarPopup(true);
    editor->setDisplayFormat("dd.MM.yyyy");
    return editor;
}

void Date::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QDateEdit *dateEdit = qobject_cast<QDateEdit*>(editor);
    QString dateStr = index.data(Qt::EditRole).toString();
    dateEdit->setDate(QDate::fromString(dateStr, "dd.MM.yyyy"));
}

void Date::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateEdit *dateEdit = qobject_cast<QDateEdit*>(editor);
    model->setData(index, dateEdit->date().toString("dd.MM.yyyy"), Qt::EditRole);
}
