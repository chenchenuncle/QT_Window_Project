#ifndef DIALOGTABLE_H
#define DIALOGTABLE_H

#include <QDialog>

namespace Ui {
class Dialogtable;
}

class Dialogtable : public QDialog
{
    Q_OBJECT

public slots:
    void do_sta(int row,int curren);//接受信号

signals:
    void do_show(int row,int curren);//发送信号

public:
    explicit Dialogtable(QWidget *parent = nullptr);
    ~Dialogtable();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogtable *ui;
};

#endif // DIALOGTABLE_H
