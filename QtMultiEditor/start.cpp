#include "start.h"
#include "qevent.h"
#include "ui_start.h"
#include <QByteArray>
#include <QCryptographicHash>
#include <QSettings>
#include <QMessageBox>

void Start::Initialize()
{
    ui->lineEdit->setText(QSettings().value("Account").toString());
    if(QSettings().value("password").toString()==password)
        ui->lineEdit_2->setText("88888");
    else
        ui->lineEdit_2->setText("");
}

void Start::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        ispos=true;
        point=event->globalPosition().toPoint()-this->pos();
    }
    return QDialog::mousePressEvent(event);
}

void Start::mouseMoveEvent(QMouseEvent *event)
{
    QPoint eventpos=event->globalPosition().toPoint();
    if(ispos&&(event->buttons()&Qt::LeftButton)&&(eventpos-point).manhattanLength()>QApplication::startDragDistance())
    {
        move(eventpos-point);
        point=eventpos-this->pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void Start::mouseReleaseEvent(QMouseEvent *event)
{
    ispos=false;
    event->accept();
}

Start::Start(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Start)
{
    ui->setupUi(this);

    //this->setWindowFlags(Qt::SplashScreen);
    QApplication::setOrganizationName("Qt_WWA");
    QApplication::setApplicationName("window");

    //加密初始化密码
    QByteArray drow=QString("88888").toLocal8Bit();
    QCryptographicHash Encryption(QCryptographicHash::Md5);
    Encryption.addData(drow);
    password=Encryption.result().toHex();
    Initialize();


}

Start::~Start()
{
    delete ui;
}

void Start::on_pushButton_clicked()
{   QCryptographicHash setting(QCryptographicHash::Md5);
    setting.addData(ui->lineEdit_2->text().toLocal8Bit());
    if(ui->lineEdit->text()!=Account)
    {
        Wrong++;
        QMessageBox::information(this,"信息框","无此账号");
    }
    else if(password!=QString(setting.result().toHex()))
    {
        Wrong++;
        QMessageBox::information(this,"信息框","密码错误");
    }
    else
    {
        //密码正确，下次初始化账号和密码存到注册表里
        QSettings settings;
        settings.setValue("Account",Account);
        settings.setValue("password",password);
        this->setResult(QDialog::Accepted);
        this->setVisible(false);
    }
    if(Wrong>3)
    {
        QMessageBox::information(this,"信息框","错误字数过多");
        this->close();
    }
}


void Start::on_pushButton_3_clicked()
{
    QSettings settings;
    settings.remove("Account");
    settings.remove("password");
}

