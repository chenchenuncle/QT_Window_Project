#ifndef TO_TABLEITEMMODEL_STYLEDITEMDELEGATE_H
#define TO_TABLEITEMMODEL_STYLEDITEMDELEGATE_H

#include <QStyledItemDelegate>
//整数项目
class to_tableitemmodel_StyledItemDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    to_tableitemmodel_StyledItemDelegate(QWidget* wigdet=nullptr);QStyledItemDelegate(wigdet);
    virtual QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    virtual void setEditorData(QWidget *editor, const QModelIndex &index)const;//获取数据模型显示组件
    virtual void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;//获取组件数据储存数据模型
    virtual void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const;
};

#endif // TO_TABLEITEMMODEL_STYLEDITEMDELEGATE_H
