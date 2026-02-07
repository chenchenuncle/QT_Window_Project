#ifndef FORMDOC_H
#define FORMDOC_H

#include "qtoolbar.h"
#include <QWidget>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QPlainTextEdit>
#include <QDialog>
#include <QDir>

namespace Ui {
class FormDoc;
}

class FormDoc : public QWidget
{
    Q_OBJECT

private:
    QPlainTextEdit* edit;//建立文本
    QVBoxLayout* layout;//建立图形表
    QToolBar* toolbar;//建立工具栏

public:
    explicit FormDoc(QWidget *parent = nullptr);
    ~FormDoc();

private slots:
    void on_action_1_triggered();

    void on_action_2_triggered();

private:
    Ui::FormDoc *ui;
};

#endif // FORMDOC_H
