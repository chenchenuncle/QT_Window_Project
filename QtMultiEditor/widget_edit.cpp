#include "widget_edit.h"
#include "ui_widget_edit.h"

widget_edit *widget_edit::operator <<(QString str)
{
    ui->plainTextEdit->appendPlainText(str);
    return this;
}

void widget_edit::setment(bool is)
{
    ment=is;
}

void widget_edit::clean()
{
    ui->plainTextEdit->clear();
}

void widget_edit::text_modfid()
{
    ui->plainTextEdit->document()->setModified(false);
}


void widget_edit::do_setWindowModified(bool is)
{
    setWindowModified(is);
    emit do_isWindowModified(is);
}

void widget_edit::do_cut()
{
    ui->plainTextEdit->cut();
}

void widget_edit::do_copy()
{
    ui->plainTextEdit->copy();
}

void widget_edit::do_paste()
{
    ui->plainTextEdit->paste();
}

void widget_edit::do_pleete(QFont font)
{
    ui->plainTextEdit->setFont(font);
}

widget_edit::widget_edit(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::widget_edit)
{
    ui->setupUi(this);
    connect(ui->plainTextEdit,&QPlainTextEdit::modificationChanged,this,&widget_edit::do_setWindowModified);
}

widget_edit::~widget_edit()
{
    delete ui;
}
