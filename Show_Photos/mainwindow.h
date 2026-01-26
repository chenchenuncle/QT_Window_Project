#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include "qspinbox.h"
#include "qtreewidget.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE

namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:   ;
    enum tiemtype{tiem1=1001,tiem2,tiem3};//类型
    enum coltiempe{istiem1,istiem2,istiem3};//几列类型
private:
    QLabel Display_1;   //显示图片名字
    QLabel Display_2;   //显示图片
    QLabel Display_3;   //显示图片目录路径
    QSpinBox Display_4; //显示图片大小
    QPixmap Display_5;  //显示组件
    void sta();         //初始化界面
    void sta_2(QString="");       //初始化目录树
    QString sta_3(QString);       //保留最后文件名
    void sta_4(QString);       //建立父子树目录关系
    void sta5(QString,QTreeWidgetItem*);//添加图片关系
    void sta_6(QTreeWidgetItem *);//删除树节点
    int sta_7(QTreeWidgetItem*); //遍历节点
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_act_1_triggered();

    void on_act_2_triggered();

    void on_act_3_triggered();

    void on_act_4_triggered();

    void on_act_5_triggered();

    void on_act_6_triggered();

    void on_act_7_triggered();

    void on_act_9_triggered();

    void on_act_8_triggered();

    void on_act_10_triggered(bool checked);

    void on_act_11_triggered(bool checked);

    void on_treeWidget_2_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous);


private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
