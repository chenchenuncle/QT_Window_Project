#ifndef DIALOGHEAD_H
#define DIALOGHEAD_H

#include <QDialog>
#include <QStringListModel>

namespace Ui {
class Dialoghead;
}

class Dialoghead : public QDialog
{
    Q_OBJECT

private:
    QStringListModel* model;//更新视图数据

public:
    QStringList sta(); //引用数据表头主题列表
    void ht_show(int);     //获取表格列数

protected:
    void showEvent(QShowEvent* event);//暂时不修改

public:
    explicit Dialoghead(QWidget *parent = nullptr);
    ~Dialoghead();

private slots:

private:
    Ui::Dialoghead *ui;
};

#endif // DIALOGHEAD_H
