#ifndef DATE_H
#define DATE_H

#include <QStyledItemDelegate>
#include <QDateEdit>

class Date : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit Date(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;
};

#endif // DATE_H
