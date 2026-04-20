#include "qstyleditem_combok.h"
#include <QComboBox>

QStyledItem_combok::QStyledItem_combok(QWidget *parent):QStyledItemDelegate(parent){}

void QStyledItem_combok::setinit(QStringList str)
{
    list=str;
}


QWidget *QStyledItem_combok::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QComboBox* box=new QComboBox(parent);
    box->addItems(list);    //编辑表格信息
    return static_cast<QWidget*>(box);
}

void QStyledItem_combok::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str=index.data().toString();
    static_cast<QComboBox*>(editor)->setCurrentText(str);
}

void QStyledItem_combok::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QString str=static_cast<QComboBox*>(editor)->currentText();
    model->setData(index,QVariant(str));
}

void QStyledItem_combok::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
