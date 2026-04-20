#ifndef QSTYLEDITEM_COMBOK_H
#define QSTYLEDITEM_COMBOK_H

#include <QStyledItemDelegate>
#include <QStringList>

class QStyledItem_combok : public QStyledItemDelegate
{
    QStringList list;

public:
    QStyledItem_combok(QWidget* parent=nullptr);
    void setinit(QStringList str);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index)const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // QSTYLEDITEM_COMBOK_H
