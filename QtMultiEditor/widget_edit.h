#ifndef WIDGET_EDIT_H
#define WIDGET_EDIT_H

#include <QWidget>

namespace Ui {
class widget_edit;
}

class widget_edit : public QWidget
{
    Q_OBJECT

    bool ment=false;//是否已经打开文件

public:
    widget_edit* operator<<(QString);//输出流到文本
    void setment(bool);
    void clean();//删除全部文本
    bool isment(){return ment;}
    void text_modfid();//修改文本修改状态

    //实验区
signals:
    void do_isWindowModified(bool);//发出信号

public slots:
    void do_setWindowModified(bool);//接受信号
    void do_cut();//剪切内容
    void do_copy();//复制内容
    void do_paste();//贴贴内容
    void do_pleete(QFont);//字体设置的

public:
    explicit widget_edit(QWidget *parent = nullptr);
    ~widget_edit();

private:
    Ui::widget_edit *ui;
};


#endif // WIDGET_EDIT_H
