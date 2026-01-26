#include "to_tfloatitem.h"
#include <QDoubleSpinBox>

to_tfloatitem::to_tfloatitem(QObject *parent)
    : QStyledItemDelegate{parent}{}

QWidget *to_tfloatitem::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    QDoubleSpinBox* Tfloat=new QDoubleSpinBox(parent);
    Tfloat->setButtonSymbols(QAbstractSpinBox::NoButtons);
    Tfloat->setDecimals(2);
    Tfloat->setRange(0.00,2000.00);
    return Tfloat;
}

void to_tfloatitem::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    double TFloat=index.data(Qt::DisplayRole).toDouble();
    static_cast<QDoubleSpinBox>(editor).setValue(TFloat);
}

void to_tfloatitem::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    double Tfloat=static_cast<QDoubleSpinBox*>(editor)->value();
    model->setData(index,QVariant(QString("%1").arg(Tfloat)),Qt::DisplayRole);
}

void to_tfloatitem::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}
