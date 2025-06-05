#include "comboBox.hpp"

#include <QComboBox>
#include <QMouseEvent>

ComboBox::ComboBox(QWidget *parent):
    QStyledItemDelegate(parent)
{}

QWidget *ComboBox::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox *comboBox = new QComboBox(parent);

    // Добавляем варианты из listOptions в comboBox
    comboBox->addItems(listOptions);
    // Задаём значение по умолчанию
    comboBox->setCurrentIndex(0);

    return comboBox;
}

void ComboBox::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);

    // Берём отображаемое значение index и выбираем его в качестве начального,
    // когда пользователь захочет раскрыть список
    comboBox->setCurrentText(index.data().toString());
}

void ComboBox::setModelData(
        QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox *comboBox = qobject_cast<QComboBox *>(editor);
    // Определяем текущий выбор пользователя для вставки в таблицу
    model->setData(index, comboBox->currentText());
}

void ComboBox::setData(const QStringList &strList)
{
    // Зададим варианты для вывода в выпадающем списке comboBox
    listOptions << strList;
}
