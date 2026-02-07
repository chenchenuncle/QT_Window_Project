#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QActionGroup>
#include <QTabWidget>
#include <QMdiArea>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QActionGroup* group; //排斥按钮
    QMdiArea* midarea; //MDI模式
    QTabWidget* tabwidget;//多窗口模式情况下


public:
    bool isActivate();

private slots:
    void do_take_tabwidget(int);
    void do_show(QAction*);//控制模式显示

protected:
    bool eventFilter(QObject *watched, QEvent *event);

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_action_11_triggered();

    void on_actionMDI_triggered();

    void on_actionwigdet_triggered();

    void on_action_wigdet_triggered();

    void on_action_triggered();

    void on_action_13_triggered();

    void on_action_1_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_7_triggered();

    void on_action_8_triggered();

    void on_action_9_triggered();

    void on_action_10_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
