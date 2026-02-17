#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>

void MainWindow::txt_clean()
{
    ui->lineEdit->clear();
}

void MainWindow::pout_clean()
{
    //整数清理
    ui->spinBox->setValue(0);
    ui->spinBox_2->setValue(0);
    ui->spinBox_3->setValue(0);
    ui->spinBox_4->setValue(0);
    ui->spinBox_5->setValue(0);
    ui->spinBox_6->setValue(0);
    //浮点清理
    ui->doubleSpinBox->setValue(0.00);
    ui->doubleSpinBox_2->setValue(0.00);
    ui->doubleSpinBox_3->setValue(0.00);
    //字符串清理
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_10->clear();
    ui->lineEdit_16->clear();

}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //初始化
    data.setByteOrder(QDataStream::LittleEndian);
    data.setFloatingPointPrecision(QDataStream::DoublePrecision);
    file.setFileName("D:/QT练习/binary/shiyanqu/barray.da");
    data.setVersion(23);
    data.setDevice(&file);
    ui->lineEdit->setText(file.fileName());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_0_triggered()
{
    txt_clean();
    pout_clean();
}


void MainWindow::on_pushButton_clicked()
{
    QString str=QFileDialog::getOpenFileName(this,"选择一个文件",QDir::currentPath());
    if(str.isEmpty()||str==file.fileName())
        return;
    file.setFileName(str);
    ui->lineEdit->setText(str);
}


void MainWindow::on_radioButton_toggled(bool checked)
{
    Q_UNUSED(checked);
    data.setByteOrder(QDataStream::LittleEndian);
}

void MainWindow::on_radioButton_2_toggled(bool checked)
{
    Q_UNUSED(checked);
    data.setByteOrder(QDataStream::BigEndian);
}


void MainWindow::on_radioButton_3_toggled(bool checked)
{
    Q_UNUSED(checked);
    data.setFloatingPointPrecision(QDataStream::SinglePrecision);
}



void MainWindow::on_radioButton_4_toggled(bool checked)
{
    Q_UNUSED(checked);
    data.setFloatingPointPrecision(QDataStream::DoublePrecision);
}

template<class T>
void MainWindow::Read(T& type)//除去布尔值，都可适用
{
    //打开文本
    if(!file.open(QIODevice::ReadOnly))
        return;
    //选择读取接口
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
        data.readRawData((char*)&type,sizeof(type));
    else
        read(type);
    file.close();
}


void MainWindow::on_pushButton_17_clicked()
{
    qint8 i=(qint8)ui->spinBox->value();
    Wired(i);
}


template<class T>
void MainWindow::read(T& da)
{
    data.resetStatus();
    data>>da;
}

template<class T>
void MainWindow::wired(T& da)
{
    data.resetStatus();
    data<<da;
}

template<class T>
void MainWindow::Wired(T& type)
{
    //打开文本
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    //选择写入接口
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
        data.writeRawData((char*)&type,sizeof(type));
    else
        wired(type);
    file.close();
}

void MainWindow::on_pushButton_28_clicked()
{
    qint8 i=0;
    Read(i);
    ui->lineEdit_4->setText(QString("%1").arg(i));
}



void MainWindow::on_pushButton_5_clicked()
{
    quint8 i=(qint8)ui->spinBox_2->value();
    Wired(i);
}


void MainWindow::on_pushButton_30_clicked()
{
    quint8 i=0;
    Read(i);
    ui->lineEdit_5->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_6_clicked()
{
    qint16 i=ui->spinBox_3->value();
    Wired(i);
}


void MainWindow::on_pushButton_25_clicked()
{
    qint16 i=0;
    Read(i);
    ui->lineEdit_6->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_7_clicked()
{
    quint16 i=ui->spinBox_4->value();
    Wired(i);
}


void MainWindow::on_pushButton_19_clicked()
{
    quint16 i=0;
    Read(i);
    ui->lineEdit_7->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_8_clicked()
{
    qint32 i=ui->spinBox_5->value();
    Wired(i);
}


void MainWindow::on_pushButton_26_clicked()
{
    qint32 i=0;
    Read(i);
    ui->lineEdit_8->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_9_clicked()
{
    qint64 i=ui->spinBox_6->value();
    Wired(i);
}


void MainWindow::on_pushButton_20_clicked()
{
    qint64 i=0;
    Read(i);
    ui->lineEdit_9->setText(QString("%1").arg(i));
}



void MainWindow::on_pushButton_10_clicked()
{
    bool is=ui->checkBox->isChecked();
    Wired(is);
}


void MainWindow::on_pushButton_31_clicked()
{
    bool is=false;
    Read(is);
    ui->checkBox_2->setChecked(is);
}


void MainWindow::on_pushButton_11_clicked()
{
    qfloat16 i=(qfloat16)ui->doubleSpinBox->value();
    Wired(i);
}


void MainWindow::on_pushButton_29_clicked()
{
    qfloat16 i=0;
    Read(i);
    ui->lineEdit_11->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_12_clicked()
{
    float i=ui->doubleSpinBox_2->value();
    Wired(i);
}


void MainWindow::on_pushButton_21_clicked()
{
    float i=0;
    Read(i);
    ui->lineEdit_12->setText(QString("%1").arg(i));
}




void MainWindow::on_pushButton_13_clicked()
{
    double i=ui->doubleSpinBox_3->value();
    Wired(i);
}

void MainWindow::on_pushButton_27_clicked()
{
    double i=0;
    Read(i);
    ui->lineEdit_13->setText(QString("%1").arg(i));
}


void MainWindow::on_pushButton_16_clicked()
{

    QByteArray da=ui->lineEdit_2->text().toLocal8Bit();
    char *a=da.data();
    Wired(a);
}


void MainWindow::on_pushButton_14_clicked()
{
    char* i;
    Read(i);
    ui->lineEdit_14->setText(QString("%1").arg(i));
    delete [] i;
}

template<> void MainWindow::Read<char* >(char*& a)
{
    //打开文本
    if(!file.open(QIODevice::ReadOnly))
        return;
    //选择读取接口
    data.resetStatus();
    qint64 sum=0;
    if(ui->radioButton_5->isChecked())//官方文档接口
        data.readBytes(a,sum);
    else
    {
        read(a);
    }
    file.close();
}

template<> void MainWindow::Wired<char *>(char *&a)
{
    //打开文本
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    //选择写入接口
    data.resetStatus();
    QByteArray da(a);
    if(ui->radioButton_5->isChecked())//官方文档接口
        data.writeBytes(a,da.size());
    else
        wired(a);
    file.close();
}



void MainWindow::on_pushButton_32_clicked()
{
    QByteArray da=ui->lineEdit_10->text().toUtf8();
    Wired(da);
}


void MainWindow::on_pushButton_34_clicked()
{
    QByteArray da;
    Read(da);
    ui->lineEdit_17->setText(QString::fromUtf8(da));
}


void MainWindow::on_pushButton_33_clicked()
{
    QByteArray da=ui->lineEdit_16->text().toLatin1();
    Wired(da);
}


void MainWindow::on_pushButton_35_clicked()
{
    QByteArray da;
    Read(da);
    ui->lineEdit_20->setText(QString::fromLatin1(da));
}


void MainWindow::on_pushButton_18_clicked()
{
    QString str=ui->lineEdit_3->text();
    Wired(str);
}


void MainWindow::on_pushButton_15_clicked()
{
    QString str;
    Read(str);
    ui->lineEdit_15->setText(str);
}


void MainWindow::on_pushButton_3_clicked()
{
    bool is=false;
    QFont font=QFontDialog::getFont(&is,this);
    if(is==true)
        ui->pushButton_3->setFont(font);
}


void MainWindow::on_pushButton_2_clicked()
{
    Wired_complex(ui->pushButton_3->font());
}


void MainWindow::on_pushButton_23_clicked()
{
    QFont font;
    QFont font_2(font);//建立副本等会对比
    Read_complex(font);
    if(font.isCopyOf(font_2)) return;
    ui->lineEdit_18->setFont(font);

    ui->lineEdit_18->setText("字体");
}


void MainWindow::on_pushButton_4_clicked()
{
    QColor color=QColorDialog::getColor();
    if(color.isValid())
    {
    QPalette palette=ui->pushButton_4->palette();
    palette.setColor(QPalette::ButtonText,color);
    ui->pushButton_4->setPalette(palette);
    }
}

template<> void MainWindow::Read<QByteArray>(QByteArray &t)
{
    //打开文本
    if(!file.open(QIODevice::ReadOnly))
        return;
    //选择读取接口
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
    {
        qint32 sum=0;
        data.readRawData((char*)&sum,sizeof(sum));
        t.resize(sum);
        data.readRawData(t.data(),(qint64)sum);
    }
    else
        read(t);

    file.close();
}

template<> void MainWindow::Wired<QByteArray>(QByteArray &t)
{
    //打开文本
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    //选择写入接口
    data.setDevice(&file);
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
    {
        qint32 sum=t.size();
        data.writeRawData((char*)&sum,sizeof(sum));
        data.writeRawData(t.data(),(qint64)t.size());
    }
    else
        wired(t);
    file.close();
}

template<> void MainWindow::Wired<QString>(QString &t)
{
    //打开文本
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    //选择写入接口
    data.setDevice(&file);
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
    {
        qint32 sum=t.size();
        data.writeRawData((char*)&sum,sizeof(sum));
        data.writeRawData((char*)t.utf16(),(qint64)sum*2);
    }
    else
        wired(t);
    file.close();
}

template<> void MainWindow::Read<QString>(QString &t)
{
    //打开文本
    if(!file.open(QIODevice::ReadOnly))
        return;
    //选择读取接口
    data.resetStatus();
    if(ui->radioButton_5->isChecked())//官方文档接口
    {
        qint32 sum=0;
        ushort* str;
        data.readRawData((char*)&sum,sizeof(sum));
        str=new ushort[sum];
        data.readRawData((char*)str,(qint64)sum*2);
        t=QString::fromUtf16((char16_t*)str,sum);
        delete []str;
    }
    else
        read(t);
    file.close();
}

template<class T>
void MainWindow::Read_complex(T &t)
{
    //打开文本
    if(!file.open(QIODevice::ReadOnly))
        return;
    data.resetStatus();
    read(t);
    file.close();
}

template<class T>
void MainWindow::Wired_complex(T &t)
{
    //打开文本
    if(!file.open(QIODevice::WriteOnly|QIODevice::Truncate))
        return;
    data.resetStatus();
    wired(t);
    file.close();
}

void MainWindow::on_pushButton_24_clicked()
{
    QColor color=ui->pushButton_4->palette().color(QPalette::ButtonText);
    Wired_complex(color);
}


void MainWindow::on_pushButton_22_clicked()
{
    QPalette palette=ui->lineEdit_19->palette();
    QColor color;
    Read_complex(color);
    if(color.isValid())
    {
        palette.setColor(QPalette::Text,color);
        ui->lineEdit_19->setPalette(palette);
        ui->lineEdit_19->setText("颜色");
    }
}

