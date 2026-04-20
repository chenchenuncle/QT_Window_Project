#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "person_show.h"
#include <QMainWindow>
#include <QSqlQueryModel>
#include <QItemSelectionModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSqlQueryModel* model;
    QItemSelectionModel* itemmodel;
    Person_show* person;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_sql_triggered();

    void on_action_first_triggered();

    void on_action_last_triggered();

    void on_action_next_triggered();

    void on_action_at_triggered();

    void on_action_Insert_triggered();

    void on_action_Insert_2_triggered();

    void on_action_rome_triggered();

    void on_action_salary_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
