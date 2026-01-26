    #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qlabel.h>
#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QActionGroup>
#include "to_comboboxitem.h"
#include "to_tableitemmodel_styleditemdelegate.h"
#include "to_tfloatitem.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT




private:
    to_tableitemmodel_StyledItemDelegate* intitem;
    to_tfloatitem* floatitem;
    to_comboBoxitem* boxitem;
    QActionGroup* action;//选择按钮
    QLabel* Display_1;
    QLabel* Display_2;
    QLabel* Display_3;
    QStandardItemModel* model; //数据模型
    QItemSelectionModel* sitemmodel;//（跟踪）选择多次模型
    void hdo_or_sta(QStringList);  //获取数据完成表格
    void hdo(QString );         //完成表头
    void sta(QString );         //添加数据ui里
    void sta_2(int row,QStandardItemModel*);//显示预览数据
    void sta_3(int row);         //为插入，添加最后一列写数据

private slots:
    void do_win(const QModelIndex &current, const QModelIndex &previous);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered(bool checked);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
