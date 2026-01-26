#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QFileDialog>

void MainWindow::hdo_or_sta(QStringList str)//获取文件数据，插入表格
{
    if(str.isEmpty())
        return ;
    if(model->verticalHeaderItem(0)==nullptr)
    {
        hdo(str.at(0));
        for(int i=1;i<str.size();i++)
            sta(str.at(i));
    }
    else
        for(int i=0;i<str.size();i++)
            sta(str.at(i));
}

void MainWindow::hdo(QString str)//插入表头数据
{
    if(str.isEmpty())
        return ;
    QStringList list;
    list=str.split(" ",Qt::SkipEmptyParts);
    for(int i=0;i<list.size();i++)
    {
        QStandardItem* item=new QStandardItem(list.at(i));
        model->setHorizontalHeaderItem(i,item);
    }
}

void MainWindow::sta(QString str)//插入获取数据信息填入表格
{
    if(str.isEmpty())
        return ;
    QStringList list;
    list=str.split(" ",Qt::SkipEmptyParts);
    int row=model->rowCount();
    for(int i=0;i<list.size()-1;i++)
    {
        QStandardItem* item=new QStandardItem(list.at(i));
        model->setItem(row,i,item);
    }
    QStandardItem* item=new QStandardItem("测并取数");
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    item->setBackground(QBrush(Qt::yellow));
    if(list.at(list.size()-1)=='1')
        item->setCheckState(Qt::Checked);
    else
        item->setCheckState(Qt::Unchecked);
    model->setItem(row,list.size()-1,item);
}

void MainWindow::sta_2(int row, QStandardItemModel *model)
{
    QString str;
    int j=0;
    while(model->item(row,j)!=nullptr)
        str+=model->item(row,j++)->text()+'\t';
    ui->plainTextEdit->appendPlainText(str);
}

void MainWindow::sta_3(int row)
{
    QStandardItem* item=new QStandardItem("测并取数");
    item->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsEnabled|Qt::ItemIsUserCheckable);
    item->setBackground(QBrush(Qt::yellow));
    item->setCheckState(Qt::Unchecked);
    model->setItem(row,5,item);
}

void MainWindow::do_win(const QModelIndex &current, const QModelIndex &previous)
{
    if(!current.isValid()||current==previous)
        return;
    Display_2->setText(QString().asprintf("当前单元格:%d行%d列",current.row(),current.column()));
    Display_3->setText("单元格内容"+current.data(Qt::DisplayRole).toString());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    intitem=new to_tableitemmodel_StyledItemDelegate;
    floatitem=new to_tfloatitem;
    boxitem=new to_comboBoxitem;
    model=new QStandardItemModel;
    sitemmodel=new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(sitemmodel);
    action=new QActionGroup(this);
    action->addAction(ui->action_6);
    action->addAction(ui->action_7);
    action->addAction(ui->action_8);
    Display_1=new QLabel("当前文件");
    Display_2=new QLabel("当前单元格：");
    Display_3=new QLabel("单元格内容");
    ui->statusbar->addWidget(Display_1,400);
    ui->statusbar->addWidget(Display_2,200);
    ui->statusbar->addPermanentWidget(Display_3,200);
    ui->tableView->setItemDelegateForColumn(0,intitem);
    ui->tableView->setItemDelegateForColumn(1,floatitem);
    ui->tableView->setItemDelegateForColumn(2,floatitem);
    ui->tableView->setItemDelegateForColumn(3,floatitem);
    ui->tableView->setItemDelegateForColumn(4,boxitem);
    connect(sitemmodel,&QItemSelectionModel::currentChanged,this,&MainWindow::do_win);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_1_triggered()
{   //读取文件
    QString ldor=QCoreApplication::applicationDirPath();
    QString str=QFileDialog::getOpenFileName(this,"",ldor,("*.txt"));
    QFile fileread(str);
    //读取文件数据保存到临时内存块里
    QStringList aliststring;//文件数据
    QString string;
    if(!fileread.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        Display_3->setText("打开文件出现问题！");
    }
    QTextStream scout(&fileread);
    while(!scout.atEnd())
    {
        scout.readLineInto(&string);
        aliststring.append(string);
    }
    hdo_or_sta(aliststring);
    Display_1->setText("当前文件:"+str);
}

void MainWindow::on_action_2_triggered()
{
    QString liststr;
    ui->plainTextEdit->clear();
    //预览水平项目
    int currion=model->columnCount();
    for(int i=0;i<currion;i++)
        liststr.append(model->horizontalHeaderItem(i)->text()+"\t");
    ui->plainTextEdit->appendPlainText(liststr);
    //输出表格预览
    int row=model->rowCount();
    for(int i=0;i<row;i++)
        sta_2(i,model);
}

void MainWindow::on_action_3_triggered()
{
    int curion=model->rowCount();
    model->setRowCount(curion+1);
    sta_3(curion);
}

void MainWindow::on_action_4_triggered()
{
    int row=ui->tableView->currentIndex().row();
    model->insertRow(row);
    sta_3(row);
}

void MainWindow::on_action_5_triggered()
{
    QList<QStandardItem*> take=model->takeRow(ui->tableView->currentIndex().row());
    for(int i=0;i<take.size();i++)
        delete take[i];
}

void MainWindow::on_action_6_triggered()
{
    int sum=sitemmodel->selectedIndexes().size();
    if(sum==0)
    {
        Display_3->setText("没有选择表格！");
        return ;
    }
    for(int i=0;i<sum;i++)
    {
        QModelIndexList listindex=sitemmodel->selectedIndexes();
        model->itemFromIndex(listindex.at(i))->setTextAlignment(Qt::AlignLeft|Qt::AlignVCenter);
    }
}

void MainWindow::on_action_7_triggered()
{
    int sum=sitemmodel->selectedIndexes().size();
    if(sum==0)
    {
        Display_3->setText("没有选择表格！");
        return ;
    }
    for(int i=0;i<sum;i++)
    {
        QModelIndexList listindex=sitemmodel->selectedIndexes();
        model->itemFromIndex(listindex.at(i))->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
    }
}

void MainWindow::on_action_8_triggered()
{
    int sum=sitemmodel->selectedIndexes().size();
    if(sum==0)
    {
        Display_3->setText("没有选择表格！");
        return ;
    }
    for(int i=0;i<sum;i++)
    {
        QModelIndexList listindex=sitemmodel->selectedIndexes();
        model->itemFromIndex(listindex.at(i))->setTextAlignment(Qt::AlignRight|Qt::AlignVCenter);
    }
}


void MainWindow::on_action_9_triggered(bool checked)
{
    int i=0,sum=sitemmodel->selectedIndexes().size();
    if(sum==0)
    {
        Display_3->setText("没有选择表格！");
        return ;
    }
    while(i<sum)
    {
        QModelIndexList listindex=sitemmodel->selectedIndexes();
        QFont font=model->itemFromIndex(listindex.at(i))->font();
        font.setBold(checked);
        model->itemFromIndex(listindex.at(i++))->setFont(font);
    }
}

