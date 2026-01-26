#include "to_tableitemmodel_styleditemdelegate.h"
#include "qspinbox.h"

to_tableitemmodel_StyledItemDelegate::to_tableitemmodel_StyledItemDelegate(QWidget* widget):QStyledItemDelegate(widget){}

QWidget *to_tableitemmodel_StyledItemDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QSpinBox* Integer=new QSpinBox(parent);
    Integer->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Integer->setRange(0,2000);
    return Integer;
}

void to_tableitemmodel_StyledItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int sum=index.data(Qt::DisplayRole).toInt();
    static_cast<QSpinBox*>(editor)->setValue(sum);
}

void to_tableitemmodel_StyledItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    int aint=static_cast<QSpinBox*>(editor)->value();
    model->setData(index,QVariant(QString("%1").arg(aint)),Qt::DisplayRole);
}

void to_tableitemmodel_StyledItemDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
