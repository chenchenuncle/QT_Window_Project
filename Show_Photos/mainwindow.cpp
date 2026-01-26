#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>

void MainWindow::sta()
{
    QTreeWidgetItem* he=new QTreeWidgetItem();
    he->setText(istiem1,"目录和文件");
    he->setText(istiem2,"节点类型");
    he->setText(istiem3,"最后修改日期");
    ui->treeWidget_2->clear();
    ui->treeWidget_2->setHeaderItem(he);
}

void MainWindow::sta_2(QString str)
{
    QTreeWidgetItem* tiem;
    if(str.isEmpty())
    {
    tiem=new QTreeWidgetItem(MainWindow::tiem1);
    tiem->setText(istiem1,"图片");
    }
    else
    {
        tiem=new QTreeWidgetItem(MainWindow::tiem1);
        tiem->setData(istiem1,Qt::UserRole,QVariant(str));
        tiem->setText(istiem1,sta_3(str));
    }
    QIcon icon(":/qrc/从文件夹取照片.png");
    tiem->setIcon(istiem1,icon);
    tiem->setText(istiem2,"tiem1");
    tiem->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsAutoTristate);
    tiem->setCheckState(istiem1,Qt::Unchecked);
    ui->treeWidget_2->addTopLevelItem(tiem);
}

QString MainWindow::sta_3(QString str)
{
    int sum=str.size();
    int i=str.lastIndexOf('/');
    return str.last(sum-i-1);
}

void MainWindow::sta_4(QString str)
{
    QTreeWidgetItem* item=new QTreeWidgetItem(tiem2);
    QIcon icon(":/qrc/从文件夹取照片1.png");
    item->setIcon(istiem1,icon);
    item->setText(istiem1,sta_3(str));
    item->setData(istiem1,Qt::UserRole,str);
    item->setText(istiem2,"tiem2");
    item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsAutoTristate);
    item->setCheckState(istiem1,Qt::Unchecked);
    ui->treeWidget_2->currentItem()->addChild(item);
}

void MainWindow::sta5(QString str, QTreeWidgetItem*father)
{
    if(str.isEmpty()||father==nullptr)
        return ;
    QTreeWidgetItem* item=new QTreeWidgetItem(tiem3);
    QFileInfo info(str);
    QIcon icon(":/qrc/生成真实照片.png");
    item->setIcon(istiem1,icon);
    item->setText(istiem1,info.fileName());
    item->setData(istiem1,Qt::UserRole,str);
    item->setText(istiem2,"tiem3");
    item->setText(istiem3,info.fileTime(QFileDevice::FileModificationTime).toString("yyyy-MM-dd"));
    item->setFlags(Qt::ItemIsUserCheckable|Qt::ItemIsEnabled|Qt::ItemIsSelectable|Qt::ItemIsAutoTristate);
    item->setCheckState(istiem1,Qt::Unchecked);
    father->addChild(item);
}

void MainWindow::sta_6(QTreeWidgetItem* tiem)
{
    if(tiem->childCount()==0&&tiem->type()==tiem1)
    {
        ui->treeWidget_2->takeTopLevelItem(ui->treeWidget_2->indexOfTopLevelItem(tiem));
        delete tiem;
        return ;
    }
    if(tiem->childCount()==0)
    {
        QTreeWidgetItem* pro=tiem->parent();
        pro->takeChild(pro->indexOfChild(tiem));
        delete tiem;
        return ;
    }
    for(int i=tiem->childCount()-1;i>=0;i--)
        sta_6(tiem->child(i));
    if(tiem->type()==tiem1)
    {
        ui->treeWidget_2->takeTopLevelItem(ui->treeWidget_2->indexOfTopLevelItem(tiem));
        delete tiem;
    }
    if(tiem->type()==tiem2)
    {
        QTreeWidgetItem* pro=tiem->parent();
        pro->takeChild(pro->indexOfChild(tiem));
        delete tiem;
    }
}

int MainWindow::sta_7(QTreeWidgetItem* tiem)
{
    if(tiem->childCount()==0&&tiem->type()==tiem3)
        return 1;
    else if(tiem->childCount()==0)
        return 0;
    int sum=0;
    for(int i=0;i<tiem->childCount();i++)
        sum+=sta_7(tiem->child(i));
    return sum;
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)     //初始化界面
{
    ui->setupUi(this);
    Display_1.setText("显示图片名字");
    Display_4.setButtonSymbols(QAbstractSpinBox::NoButtons);
    Display_4.setValue(100);
    Display_4.setRange(5,200);
    Display_4.setSuffix("%");
    Display_3.setText("显示目录路径");
    ui->statusBar->addWidget(&Display_1,200);
    ui->statusBar->addPermanentWidget(&Display_4,50);
    ui->statusBar->addPermanentWidget(&Display_3,200);
    sta();
    sta_2();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_act_1_triggered()  //添加目录
{
    QString str=QFileDialog::getExistingDirectory();
    QTreeWidgetItem* item=ui->treeWidget_2->currentItem();
    if(str.isEmpty())
        return ;
    if(item==nullptr)
        sta_2(str);
    else if(item->type()!=MainWindow::tiem3)
        sta_4(str);
}

void MainWindow::on_act_2_triggered()//添加图片
{
    QTreeWidgetItem* tiem=ui->treeWidget_2->currentItem();
    if(tiem==nullptr||tiem->type()==MainWindow::tiem3)
    {
        Display_1.setText("请点击目录再点击添加图片文件，不然我们无法获取目录存放图片文件！");
        return ;
    }
    QStringList str=QFileDialog::getOpenFileNames(this,"",("D:/QT练习/untitled4_7/Photo"),("(*.png *.xpm *.jpg)"));
    for(int i=0;i<str.size();i++)
        sta5(str.at(i),tiem);
    if(str.size()==0)
        Display_1.setText("无添加图片");
    else
    {
        qDebug()<<str.at(0);
        Display_5.load(str.at(0));
        ui->label->setPixmap(Display_5);
    }
}

void MainWindow::on_act_3_triggered()//删除信号
{
    QTreeWidgetItem* tiem=ui->treeWidget_2->currentItem();
    if(tiem==nullptr)
    {
        Display_1.setText("没有选择文件！");
        return ;
    }
    sta_6(tiem);
}

void MainWindow::on_act_4_triggered()
{
    if(ui->treeWidget_2->topLevelItemCount()==0)
    {
        Display_1.setText("无目录或者文件");
        return ;
    }
    int sum=0;
    for(int i=0;i<ui->treeWidget_2->topLevelItemCount();i++)
        sum+=sta_7(ui->treeWidget_2->topLevelItem(i));
    if(sum==0)
        Display_1.setText("目录（文件）没有存图片");
    else
        Display_1.setText(QString("图片总共%1").arg(sum));
}


void MainWindow::on_act_5_triggered()//放大
{
    Display_4.setValue(Display_4.value()*1.2);
    float h=Display_5.height()*Display_4.value()/100;
    float w=Display_5.width()*Display_4.value()/100;
    ui->label->setPixmap(Display_5.scaled(w,h));
}

void MainWindow::on_act_6_triggered()
{
    Display_4.setValue(Display_4.value()*0.8);
    float h=Display_5.height()*Display_4.value()/100;
    float w=Display_5.width()*Display_4.value()/100;
    ui->label->setPixmap(Display_5.scaled(w,h));
}

void MainWindow::on_act_7_triggered()
{
    Display_4.setValue(100);
    ui->label->setPixmap(Display_5);
}

void MainWindow::on_act_9_triggered()
{
    int h=ui->scrollArea->height();
    int h_2=Display_5.height();
    Display_4.setValue(float(float(h)/h_2)*100);
    {
    float h=Display_5.height()*Display_4.value()/100;
    float w=Display_5.width()*Display_4.value()/100;
    ui->label->setPixmap(Display_5.scaled(w,h));
    }
}

void MainWindow::on_act_8_triggered()
{
    int w=ui->scrollArea->height();
    int w_2=Display_5.width();
    Display_4.setValue(float(float(w)/w_2)*100);
    {
        float h=Display_5.height()*Display_4.value()/100;
        float w=Display_5.width()*Display_4.value()/100;
        ui->label->setPixmap(Display_5.scaled(w,h));
    }
}

void MainWindow::on_act_10_triggered(bool checked)
{
    ui->dockWidget->setFloating(checked);
}


void MainWindow::on_act_11_triggered(bool checked)
{
    ui->dockWidget->setVisible(checked);
}


void MainWindow::on_treeWidget_2_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    if(current==nullptr||current==previous)
    {
        Display_1.setText("没有选择文件");
        return ;
    }
    qDebug()<<current->data(istiem1,Qt::UserRole).toString();
    Display_1.setText(current->text(istiem1));
    Display_3.setText(current->data(istiem1,Qt::UserRole).toString());
    Display_5.load(current->data(istiem1,Qt::UserRole).toString());
    float h=(float)Display_5.height()*Display_4.value()/100;
    float w=(float)Display_5.width()*Display_4.value()/100;
    ui->label->setPixmap(Display_5.scaled(w,h));
}


