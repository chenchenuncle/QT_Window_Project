#include "to_comboboxitem.h"
#include <QComboBox>

to_comboBoxitem::to_comboBoxitem(QObject *parent)
    : QStyledItemDelegate{parent}
{}

QWidget *to_comboBoxitem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox *editor = new QComboBox(parent);
    QStringList list;
    list<<"待定"<<"优"<<"良"<<"一般"<<"合格"<<"不合格";
    editor->addItems(list);
    editor->setEditable(false);
    return editor;
}

void to_comboBoxitem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    static_cast<QComboBox*>(editor)->setCurrentText(index.data(Qt::DisplayRole).toString());
}

void to_comboBoxitem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QString str=static_cast<QComboBox*>(editor)->currentText();
    model->setData(index,QVariant(str),Qt::DisplayRole);
}

void to_comboBoxitem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
