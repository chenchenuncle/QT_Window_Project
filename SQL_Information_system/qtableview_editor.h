#ifndef QTABLEVIEW_EDITOR_H
#define QTABLEVIEW_EDITOR_H

#include <QTableView>

class QTableView_Editor : public QTableView
{
public:
    QTableView_Editor(QWidget* =nullptr);

public:
    void commitData_Mandatory(QAbstractItemDelegate*);//强制正在编辑的数据
};

#endif // QTABLEVIEW_EDITOR_H
