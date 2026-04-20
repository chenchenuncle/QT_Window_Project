#include "person_show.h"
#include "qfiledialog.h"
#include "qsqlerror.h"
#include "qsqlquerymodel.h"
#include "ui_person_show.h"
#include <QSqlQuery>
#include <QByteArray>
#include <QMessageBox>
#include <QBuffer>

void Person_show::Inssrt()
{
    //获取要修改一名员工信息
    record=static_cast<QSqlQueryModel*>(mapper->model())->record(mapper->currentIndex());

    //执行增加数据操作
    QSqlQuery query(QSqlDatabase::database("socool"));
    query.prepare("INSERT INTO [Employee information] (Employee_ID,name,Gender,birthday,province,department,salary,photo,meno)"" VALUES(?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,ui->spinBox->value());
    query.bindValue(1,ui->lineEdit->text());
    query.bindValue(2,ui->comboBox->currentText());
    query.bindValue(3,ui->dateEdit->date());
    query.bindValue(4,ui->comboBox_2->currentText());
    query.bindValue(5,ui->comboBox_3->currentText());
    query.bindValue(6,ui->doubleSpinBox->value());


    //图片要特殊处理
    QByteArray array=this->read_photo();
    query.bindValue(7,array);

    query.bindValue(8,ui->textEdit->toPlainText());

    if(!query.exec())
        QMessageBox::information(this,"增数据库数据问题","无法增加原因："+query.lastError().text());

    //从小到大排序ID
    query.prepare("SELECT Employee_ID,name,Gender,birthday,province,department,salary,photo,meno FROM [Employee Information] ORDER BY Employee_ID ASC");
    if(!query.exec())
        QMessageBox::information(this,"排序问题","无法实现排序原因："+query.lastError().text());

    // 将排序后的结果设置到模型
    static_cast<QSqlQueryModel*>(mapper->model())->setQuery(std::move(query));

    //关闭窗口以及刷新view
    idu=NO;
    static_cast<QSqlQueryModel*>(mapper->model())->refresh();
    this->setVisible(false);
}

void Person_show::Delete()
{
    //无需最修改
}

void Person_show::Update()
{
    {
        //获取要删除员工ID
        QSqlQuery query("SELECT * FROM [Employee Information]",QSqlDatabase::database("socool"));

        //获取model选择的数据图片位置
        if(!query.seek(mapper->currentIndex()))
        {
            QMessageBox::information(this,"访问数据库问题","无法访问原因："+query.lastError().text());
            return;
        }
        int Id=query.value("Employee_ID").toInt();

        //执行删除操作
        query.prepare("DELETE FROM [Employee Information] WHERE Employee_ID=:id");
        query.bindValue(":id",Id);
        if(!query.exec())
            QMessageBox::information(this,"删除员工问题","无法删除原因："+query.lastError().text());

    }
    //获取要修改一名员工信息
    record=static_cast<QSqlQueryModel*>(mapper->model())->record(mapper->currentIndex());

    //执行增加数据操作
    QSqlQuery query(QSqlDatabase::database("socool"));
    query.prepare("INSERT INTO [Employee information] (Employee_ID,name,Gender,birthday,province,department,salary,photo,meno)"" VALUES(?,?,?,?,?,?,?,?,?)");
    query.bindValue(0,ui->spinBox->value());
    query.bindValue(1,ui->lineEdit->text());
    query.bindValue(2,ui->comboBox->currentText());
    query.bindValue(3,ui->dateEdit->date());
    query.bindValue(4,ui->comboBox_2->currentText());
    query.bindValue(5,ui->comboBox_3->currentText());
    query.bindValue(6,ui->doubleSpinBox->value());


    //图片要特殊处理
    QByteArray array=this->read_photo();
    query.bindValue(7,array);

    query.bindValue(8,ui->textEdit->toPlainText());

    if(!query.exec())
        QMessageBox::information(this,"增数据库数据问题","无法增加原因："+query.lastError().text());

    //从小到大排序ID
    query.prepare("SELECT Employee_ID,name,Gender,birthday,province,department,salary,photo,meno FROM [Employee Information] ORDER BY Employee_ID ASC");
    if(!query.exec())
        QMessageBox::information(this,"排序问题","无法实现排序原因："+query.lastError().text());

    // 将排序后的结果设置到模型
    static_cast<QSqlQueryModel*>(mapper->model())->setQuery(std::move(query));



    //关闭窗口以及刷新view
    idu=NO;
    static_cast<QSqlQueryModel*>(mapper->model())->refresh();
    this->setVisible(false);
}

void Person_show::do_phtoot(int current)
{
    //连接数据库
    QSqlQuery query("SELECT * FROM [Employee Information]",QSqlDatabase::database("socool"));

    //获取view选择的数据图片位置
    if(!query.seek(current,false))
    {
        QMessageBox::information(this,"访问数据库问题","无法访问原因："+query.lastError().text());
        return;
    }

    //获取图片二进制数据
    QByteArray array=query.value("photo").toByteArray();
    this->wird_photo(array);
}

QByteArray Person_show::read_photo()
{
    QPixmap pixmap=ui->label_8->pixmap();
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");
    return bytes;
}

void Person_show::wird_photo(QByteArray &array)
{
    QPixmap pixmap;
    pixmap.loadFromData(array);
    ui->label_8->setPixmap(pixmap.scaled(ui->label_8->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation));
}

QDataWidgetMapper *Person_show::mapping()
{
    return mapper;
}

void Person_show::mapper_ui()
{
    //建立映射
    mapper->addMapping(ui->spinBox,0);
    mapper->addMapping(ui->lineEdit,1);
    mapper->addMapping(ui->comboBox,2);
    mapper->addMapping(ui->dateEdit,3);
    mapper->addMapping(ui->comboBox_2,4);
    mapper->addMapping(ui->comboBox_3,5);
    mapper->addMapping(ui->doubleSpinBox,6);
    mapper->addMapping(ui->textEdit,8);

}

void Person_show::record_before(QSqlRecord cord)
{
    //初始化要增，修的数据
    ui->spinBox->setValue(cord.value(0).toInt());
    ui->lineEdit->setText(cord.value(1).toString());
    ui->comboBox->setCurrentText(cord.value(2).toString());
    ui->dateEdit->setSpecialValueText(cord.value(3).toString());
    ui->comboBox_2->setCurrentText(cord.value(4).toString());
    ui->comboBox_3->setCurrentText(cord.value(5).toString());
    ui->doubleSpinBox->setValue(cord.value(6).toDouble());
    //特殊图片处理
    QByteArray array=cord.value(7).toByteArray();
    this->wird_photo(array);
    ui->textEdit->setText(cord.value(8).toString());
}

Person_show::Person_show(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Person_show)
{
    ui->setupUi(this);

    //初始化变量
    mapper=new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);

    //修改表格编辑模式
    QStringList list;
    list<<"男"<<"女";
    ui->comboBox->addItems(list);
    list.clear();
    list<<"行政部"<<"销售部"<<"生产部"<<"技术部";
    ui->comboBox_3->addItems(list);
    list.clear();
    QString str=(
        "河北省、山西省、辽宁省、吉林省、黑龙江省、江苏省、浙江省、安徽省、福建省、江西省、山东省、河南省、湖北省、湖南省、广东省、海南省、四川省、贵州省、云南省、陕西省、甘肃省、青海省、台湾省、"
        "内蒙古自治区、广西壮族自治区、西藏自治区、宁夏回族自治区、新疆维吾尔自治区、"
        "北京、天津、上海、重庆、特别行政区香港特别行政区、澳门特别行政区");
    list=str.split("、");
    ui->comboBox_2->addItems(list);

    //跟踪mapper组件变化而变化
    connect(mapper,&QDataWidgetMapper::currentIndexChanged,this,&Person_show::do_phtoot);
}

Person_show::~Person_show()
{
    delete ui;
}

void Person_show::on_pushButton_clicked()
{
    //选择图片
    QString name_photo=QFileDialog::getOpenFileName(this,"选择图片","","(*)");

    //获取图片资源
    QPixmap pixmap(name_photo);
    QByteArray bytes;
    QBuffer buffer(&bytes);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, "PNG");

    //设置图片/ui
    this->wird_photo(bytes);
}


void Person_show::on_pushButton_2_clicked()
{
    ui->label_8->setPixmap(QPixmap());
}


void Person_show::on_pushButton_3_clicked()
{
    //对要执行的状态做出修改
    switch(idu)
    {
    case INSERT:Inssrt();break;
    case DELETE:Delete();break;
    case UPDATE:Update();break;
    case NO:break;  //不做如何改变
    }
}


void Person_show::on_pushButton_4_clicked()
{
    this->setVisible(false);
}

