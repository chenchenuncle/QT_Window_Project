#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qstyleditem_combok.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QItemSelectionModel>
#include <QDataWidgetMapper>
#include <QAction>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QSqlTableModel* dbtablemodel;
    QItemSelectionModel* itemmodel;
    QDataWidgetMapper* mapper;
    QStyledItem_combok* combox_esx;
    QStyledItem_combok* combox_ment;
    QStyledItem_combok* combox_province;

public:
    QSqlRecord& INIT(QSqlRecord&);  //返回引用初始化数据

protected:
    void Photo(QSqlRecord&record) const;//读取数据库二进制数据到组件里

private slots:
    void do_Filter(bool is);
    void do_currentChanged(const QModelIndex &current, const QModelIndex &previous);   //当选发生变化时，释放保存按钮
    void do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous);  //当行发生变化时，右侧个人信息跟随变化

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_1_triggered();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_radioButton_5_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);


    void on_action_7_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
