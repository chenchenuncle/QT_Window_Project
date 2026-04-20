#include "qtableview_editor.h"

QTableView_Editor::QTableView_Editor(QWidget *panre):QTableView(panre){};

void QTableView_Editor::commitData_Mandatory(QAbstractItemDelegate *of)
{
    //获取编辑器的组件
    QModelIndex model=this->currentIndex();
    QWidget* widget = this->indexWidget(model);

    //强制提交给模型
    of->commitData(widget);

    //主函数关闭编辑器，防止Bug
}
