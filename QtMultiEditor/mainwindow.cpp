#include "mainwindow.h"
#include "qmessagebox.h"
#include "qobjectdefs.h"
#include "qwindowdefs.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "ttable.h"
#include "formdoc.h"
#include "widget_edit.h"
#include <QMdiSubWindow>

bool MainWindow::isActivate()
{
    if(!ui->actionMDI->isChecked())
    {
        QMessageBox::information(this,"信息框","请激活MID模式！");
        return true;
    }
    else
        return false;
}

void MainWindow::do_take_tabwidget(int model)
{
    tabwidget->removeTab(model);
}

void MainWindow::do_show(QAction *action)
{
    if(action==ui->action_11)
    {
        ui->action->setVisible(true);
        ui->action_13->setVisible(true);
        ui->actionwigdet->setVisible(true);
        ui->action_wigdet->setVisible(true);
        ui->action_9->setVisible(false);
        ui->action_10->setVisible(false);
    }
    else
    {
        ui->action->setVisible(false);
        ui->action_13->setVisible(false);
        ui->actionwigdet->setVisible(false);
        ui->action_wigdet->setVisible(false);
        ui->action_9->setVisible(true);
        ui->action_10->setVisible(true);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched==tabwidget)
    {
    if(event->type()==QEvent::Paint)
    {
        QPainter painter(static_cast<QTabWidget*>(watched));
        painter.drawPixmap(static_cast<QPaintEvent*>(event)->rect(),QPixmap(":/qrc/风景图.png"));
        return true;
    }
    }
    return QWidget::eventFilter(watched,event);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //让2个模式排斥
    group=new QActionGroup(this);
    group->addAction(ui->actionMDI);
    group->addAction(ui->action_11);
    //初始化模式
    ui->action->setVisible(false);
    ui->action_13->setVisible(false);
    ui->actionwigdet->setVisible(false);
    ui->action_wigdet->setVisible(false);
    ui->action_9->setVisible(true);
    ui->action_10->setVisible(true);
    connect(group,SIGNAL(triggered(QAction*)),this,SLOT(do_show(QAction*)));
    //对多种窗口初始化
    midarea=new QMdiArea();
    tabwidget=new QTabWidget();
    this->setCentralWidget(midarea);
    tabwidget->installEventFilter(this);
    tabwidget->setTabsClosable(true);

    midarea->setTabsMovable(false);
    midarea->setTabsClosable(true);
    connect(tabwidget,SIGNAL(tabCloseRequested(int)),this,SLOT(do_take_tabwidget(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_action_11_triggered()
{
    this->takeCentralWidget();
    this->setCentralWidget(tabwidget);
}


void MainWindow::on_actionMDI_triggered()
{
    this->takeCentralWidget();
    this->setCentralWidget(midarea);
}


void MainWindow::on_actionwigdet_triggered()
{
    FormDoc* doc=new FormDoc();
    doc->setAttribute(Qt::WA_DeleteOnClose);
    tabwidget->addTab(doc,"基础窗口");
}


void MainWindow::on_action_wigdet_triggered()
{
    FormDoc* doc=new FormDoc;
    doc->setAttribute(Qt::WA_DeleteOnClose);
    doc->setWindowTitle("widget");
    doc->show();
}


void MainWindow::on_action_triggered()
{
    TTable* table=new TTable();
    table->setAttribute(Qt::WA_DeleteOnClose);
    tabwidget->addTab(table,"表格窗口");
}


void MainWindow::on_action_13_triggered()
{
    TTable* table=new TTable;
    table->setAttribute(Qt::WA_DeleteOnClose);
    table->setWindowTitle("tablewidget");
    table->show();
}


void MainWindow::on_action_1_triggered()
{
    if(isActivate()) return;
    widget_edit* widget=new widget_edit;
    widget->setWindowTitle("基础窗口");
    QMdiSubWindow* window=midarea->addSubWindow(widget);
    window->show();
    connect(widget, &widget_edit::do_isWindowModified, window, &QMdiSubWindow::setWindowModified);
}

void MainWindow::on_action_2_triggered()
{
    QMdiSubWindow* mdisubwindow=midarea->currentSubWindow();
    if(mdisubwindow==nullptr||isActivate())
    {
        QMessageBox::information(this,"信息框","请激活MID模式和窗口！");
        return ;
    }
    widget_edit* widget=static_cast<widget_edit*>(mdisubwindow->widget());
    if(widget->isment())
    {
        QMessageBox::information(this,"信息框","已打开文件！");
        return ;
    }
    QString str=QFileDialog::getOpenFileName(this,"打开一个文件",QDir::currentPath(),"全部文件(*.*)");
    if(str.isEmpty())
    {
        QMessageBox::information(this,"信息框","没有选择文件！");
        return ;
    }
    widget->clean();
    QFile file(str);
    if(!file.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text))
        return ;
    QTextStream out(&file);
    while(!out.atEnd())
        (*widget)<<out.readLine();
    //用文件名取名窗口
    widget->setWindowTitle(QFileInfo(str).fileName()+"[*]");
    widget->setment(true);
}

void MainWindow::on_action_3_triggered()
{
    if(isActivate()) return;
    QMdiSubWindow* widget=midarea->currentSubWindow();
    if(widget==nullptr)
        return ;
    static_cast<widget_edit*>(widget->widget())->text_modfid();
}


void MainWindow::on_action_4_triggered()
{
    if(isActivate()) return;
    midarea->closeAllSubWindows();
}


void MainWindow::on_action_5_triggered()
{
    if(isActivate()) return;
    ((widget_edit*)midarea->currentSubWindow()->widget())->do_cut();
}


void MainWindow::on_action_6_triggered()
{
    if(isActivate()) return;
    ((widget_edit*)midarea->currentSubWindow()->widget())->do_copy();
}


void MainWindow::on_action_7_triggered()
{
    if(isActivate()) return;
    ((widget_edit*)midarea->currentSubWindow()->widget())->do_paste();
}


void MainWindow::on_action_8_triggered()
{
    if(isActivate()) return;
    ((widget_edit*)midarea->currentSubWindow()->widget())->do_paste();
}


void MainWindow::on_action_9_triggered()
{
    midarea->cascadeSubWindows();
}


void MainWindow::on_action_10_triggered()
{
    midarea->tileSubWindows();
}

