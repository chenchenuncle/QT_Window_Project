#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QFile file;
    QDataStream data;

public:
//只适合读取数据流(打开文件还需要通过别的接口打开文本)
template <class T>//读取数据
    void read(T& da);
template <class T>//写入数据
    void  wired(T& da);

//选择文档还是自开发
template <class T>
    void Read(T& t);//(读取)添加(无关要紧)参数让他自动识别类型
template <class T>
    void Wired(T& type);       //(写入)

//开发对于复杂类的模板，总一调用QDatastream序化接口
template <class T>
void   Read_complex(T&t);
template <class T>
void Wired_complex(T&t);

public:
    void txt_clean();//清空测试文本框
    void pout_clean();//清空全部输入文本框


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_0_triggered();

    void on_pushButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);


    void on_radioButton_3_toggled(bool checked);

    void on_radioButton_4_toggled(bool checked);

    void on_pushButton_17_clicked();

    void on_pushButton_28_clicked();


    void on_pushButton_5_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_29_clicked();


    void on_pushButton_21_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_27_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_34_clicked();

    void on_pushButton_33_clicked();

    void on_pushButton_35_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_23_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
};

//针对char*（指针）类别,(请重新开发指针的模板)选择实序化
template<> void MainWindow::Read<char*>(char*& t);
template<> void MainWindow::Wired<char*>(char*& t);
//实序化QByteArray类型,为了保证官网接口和自定义接口都能互相使用，会按的序化要求来开发自定义接口
template<> void MainWindow::Read<QByteArray>(QByteArray& t);
template<> void MainWindow::Wired<QByteArray>(QByteArray& t);
//qstring类型
template<> void MainWindow::Read<QString>(QString& t);
template<> void MainWindow::Wired<QString>(QString& t);

#endif // MAINWINDOW_H
