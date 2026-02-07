#include "dialoghead.h"
#include "ui_dialoghead.h"

QStringList Dialoghead::sta()
{
    return model->stringList();
}

void Dialoghead::ht_show(int old)
{
    int sum=model->rowCount();//旧数据表头数量
    if(old<sum)
    {
        model->removeRows(old,sum-old);
    }
    else
    {
        QStringList list(old-sum);
        model->setStringList(model->stringList()+list);
    }
}

void Dialoghead::showEvent(QShowEvent *event)//暂时不修改
{
    Q_UNUSED(event);
    QWidget::showEvent(event);
}

Dialoghead::Dialoghead(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialoghead)
{
    ui->setupUi(this);
    model=new QStringListModel;
    ui->listView->setModel(model);
}

Dialoghead::~Dialoghead()
{
    delete ui;
}

