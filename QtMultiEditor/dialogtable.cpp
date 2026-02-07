#include "dialogtable.h"
#include "ui_dialogtable.h"

void Dialogtable::do_sta(int row, int curren)
{
    ui->spinBox->setValue(row);
    ui->spinBox_2->setValue(curren);
}


Dialogtable::Dialogtable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialogtable)
{
    ui->setupUi(this);
}

Dialogtable::~Dialogtable()
{
    delete ui;
}

void Dialogtable::on_pushButton_clicked()
{
    this->setResult(0x01);
    emit do_show(ui->spinBox->value(),ui->spinBox_2->value());
    this->hide();
}

