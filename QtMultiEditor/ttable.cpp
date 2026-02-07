#include "ttable.h"
#include "ui_ttable.h"
#include "dialogtable.h"

void TTable::do_sta(int row, int curren)
{
    model->setRowCount(row);
    model->setColumnCount(curren);
}

TTable::TTable(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TTable)
{
    ui->setupUi(this);
    head=new Dialoghead;
    model=new QStandardItemModel;
    itemmodel=new QItemSelectionModel;
    head->setWindowModality(Qt::ApplicationModal);
    ui->tableView->setModel(model);
    itemmodel->setModel(model);
}

TTable::~TTable()
{
    delete ui;
}



void TTable::on_action_1_triggered()
{
    Dialogtable* table=new Dialogtable(this);
    connect(table,SIGNAL(do_show(int,int)),this,SLOT(do_sta(int,int)));//按确定按钮发送信号
    connect(this,SIGNAL(do_show(int,int)),table,SLOT(do_sta(int,int)));//显示传送参数
    table->setWindowModality(Qt::WindowModal);
    emit do_show(model->rowCount(),model->columnCount());//发送信号
    table->exec();
    delete table;
}


void TTable::on_action_2_triggered()
{
    head->setWindowModality(Qt::WindowModal);
    QStringList list;
    int sum=model->columnCount();
    head->ht_show(sum);
    head->exec();
    if(head->result()==0x01)
    {
        model->setHorizontalHeaderLabels(head->sta());
    }
}

