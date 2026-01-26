#ifndef TO_COMBOBOXITEM_H
#define TO_COMBOBOXITEM_H

#include <QStyledItemDelegate>

class to_comboBoxitem : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit to_comboBoxitem(QObject *parent = nullptr);
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index)const;//获取数据模型显示组件
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;//获取组件数据储存数据模型
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TO_COMBOBOXITEM_H
