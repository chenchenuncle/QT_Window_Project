#include "formdoc.h"
#include "ui_formdoc.h"
#include <QToolBar>
#include <QMessageBox>
#include <QFontDialog>

FormDoc::FormDoc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormDoc)
{
    ui->setupUi(this);
    //初始化ui
    layout=new QVBoxLayout(this);

    toolbar=new QToolBar;
    edit=new QPlainTextEdit;
    layout->addWidget(toolbar,1);
    layout->addWidget(edit,10);
    //初始化工具栏
    toolbar->addAction(ui->action_1);
    toolbar->addAction(ui->action_2);
    toolbar->addAction(ui->action_3);
    toolbar->addAction(ui->action_4);
    toolbar->addAction(ui->action_5);
    toolbar->addAction(ui->action_6);
    toolbar->addAction(ui->action_7);
    toolbar->addSeparator();
    toolbar->addAction(ui->action_8);
    toolbar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    //建立按钮关系
    connect(ui->action_3,&QAction::triggered,edit,&QPlainTextEdit::cut);
    connect(ui->action_4,&QAction::triggered,edit,&QPlainTextEdit::copy);
    connect(ui->action_5,&QAction::triggered,edit,&QPlainTextEdit::paste);
    connect(ui->action_6,&QAction::triggered,edit,&QPlainTextEdit::undo);
    connect(ui->action_7,&QAction::triggered,edit,&QPlainTextEdit::redo);
}

FormDoc::~FormDoc()
{
    delete ui;
}

void FormDoc::on_action_1_triggered()
{
    edit->clear();
    QString str=QDir::currentPath();
    QString name=QFileDialog::getOpenFileName(this,"请打开一个文件",str,("c,h,ui文件(*.c *.cpp *.h *.ui),"));
    QFile aput(name);
    if(!aput.open(QIODeviceBase::ReadOnly|QIODeviceBase::Text))
        QMessageBox::information(this,"信息框","没有正确的打开文件");
    QTextStream out(&aput);
    while(!out.atEnd())
        edit->appendPlainText(out.readLine());
}


void FormDoc::on_action_2_triggered()
{
    bool ok=false;
    QFont font=edit->font();
    font=QFontDialog::getFont(&ok,this);
    edit->setFont(font);
}

