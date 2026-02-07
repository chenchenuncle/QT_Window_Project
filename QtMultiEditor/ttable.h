#ifndef TTABLE_H
#define TTABLE_H

#include "dialoghead.h"
#include <QMainWindow>
#include <QStandardItemModel>
#include <QItemSelectionModel>

namespace Ui {
class TTable;
}

class TTable : public QMainWindow
{
    Q_OBJECT

private:
    Dialoghead* head;
    QStandardItemModel* model;
    QItemSelectionModel* itemmodel;

public slots:
    void do_sta(int,int);

signals:
    void do_show(int,int);

public:
    explicit TTable(QWidget *parent = nullptr);
    ~TTable();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

private:
    Ui::TTable *ui;
};

#endif // TTABLE_H
