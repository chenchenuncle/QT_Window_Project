#ifndef START_H
#define START_H

#include <QDialog>

namespace Ui {
class Start;
}

class Start : public QDialog
{
    Q_OBJECT

private:
    bool ispos=false;
    QPoint point;
    int Wrong=0;
    QString Account="12345";
    QString password;
    void Initialize();

protected:
    void mousePressEvent(QMouseEvent*event);
    void mouseMoveEvent(QMouseEvent*event);
    void mouseReleaseEvent(QMouseEvent*event);

public:
    explicit Start(QWidget *parent = nullptr);
    ~Start();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Start *ui;
};

#endif // START_H
