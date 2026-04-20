#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QSqlError>
#include <QMessageBox>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化页面
    this->setCentralWidget(ui->tableView);

    //初始化数据库
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE","socool");

    //初始化model/view
    model=new QSqlQueryModel(this);
    itemmodel=new QItemSelectionModel(model,this);
    person=new Person_show();//初始化第二个窗口
    person->setVisible(false);  //关闭编辑窗口
    ui->tableView->setModel(model);
    ui->tableView->setSelectionModel(itemmodel);
    person->mapping()->setModel(model);
    person->mapper_ui();

    //建立model与ui映射
    connect(itemmodel,&QItemSelectionModel::currentRowChanged,person->mapping(),&QDataWidgetMapper::setCurrentModelIndex);
    connect(this,&QMainWindow::destroyed,person,&Person_show::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_sql_triggered()
{
    //打开文件
    QString stlite=QFileDialog::getOpenFileName(this,"数据库文件","请打开数据库文件","*.db3 *.db *.sql");

    //如果未打开文件
    if(stlite.isEmpty())
    {
        QMessageBox::information(this,"信息","未选择数据库");
        return ;
    }

    //数据库连接
    QSqlDatabase db=QSqlDatabase::database("socool");
    db.setDatabaseName(stlite);

    //如果打开不是数据库文件或者其他原因
    if(!db.open())
    {
        QMessageBox::information(this,"信息","打开数据库失败原因:"+db.lastError().text());
        return ;
    }

    //连接数据库文件
    model->setQuery("SELECT * FROM [Employee Information]",db);


    //修改标题并显示数据
    QSqlRecord record=model->record();
    model->setHeaderData(record.indexOf("Employee_ID"),Qt::Horizontal,"工号");
    model->setHeaderData(record.indexOf("name"),Qt::Horizontal,"名字");
    model->setHeaderData(record.indexOf("Gender"),Qt::Horizontal,"性别");
    model->setHeaderData(record.indexOf("birthday"),Qt::Horizontal,"出生日期");
    model->setHeaderData(record.indexOf("province"),Qt::Horizontal,"省份");
    model->setHeaderData(record.indexOf("department"),Qt::Horizontal,"部门");
    model->setHeaderData(record.indexOf("salary"),Qt::Horizontal,"工资");
    model->setHeaderData(record.indexOf("photo"),Qt::Horizontal,"照片");
    model->setHeaderData(record.indexOf("meno"),Qt::Horizontal,"备注");
    ui->tableView->setColumnHidden(record.indexOf("photo"),true);
    ui->tableView->setColumnHidden(record.indexOf("meno"),true);

    //激活全部组件
    ui->action_Insert->setEnabled(true);
    ui->action_Insert_2->setEnabled(true);
    ui->action_at->setEnabled(true);
    ui->action_first->setEnabled(true);
    ui->action_last->setEnabled(true);
    ui->action_next->setEnabled(true);
    ui->action_rome->setEnabled(true);
    ui->action_salary->setEnabled(true);
}


void MainWindow::on_action_first_triggered()
{
    person->mapping()->toFirst();
    person->Switch_sql(Person_show::NO);
    person->show();
}


void MainWindow::on_action_last_triggered()
{
    person->mapping()->toPrevious();
    person->Switch_sql(Person_show::NO);
    person->show();
}


void MainWindow::on_action_next_triggered()
{
    person->mapping()->toNext();
    person->Switch_sql(Person_show::NO);
    person->show();
}


void MainWindow::on_action_at_triggered()
{
    person->mapping()->toLast();
    person->Switch_sql(Person_show::NO);
    person->show();
}


void MainWindow::on_action_Insert_triggered()
{

    //显示
    person->show();

    //状态改为增加数据操作
    person->Switch_sql(Person_show::INSERT);

    //获取最大工号
    int sum=0;
    QSqlQuery query("SELECT * FROM [Employee Information]",QSqlDatabase::database("socool"));
    query.prepare("SELECT Max(Employee_ID) FROM [Employee Information]");
    if(!query.exec())
    {
        QMessageBox::information(this,"查询失败","原因："+query.lastError().text());
        return;
    }
    if(!query.next())
        return;
    sum=query.value(0).toInt();

    qDebug()<<sum;
    //初始化员工数据
    QSqlRecord record=model->record();
    record.setValue("Employee_ID",sum+1);
    record.setValue("name","某某");
    record.setValue("birthday","2000-01-01");

    //
    person->record_before(record);
}


void MainWindow::on_action_Insert_2_triggered()
{
    //修改数据库
    person->Switch_sql(Person_show::UPDATE);
    person->show();
}


void MainWindow::on_action_rome_triggered()
{
    //修改状态
    person->Switch_sql(Person_show::DELETE);

    //获取要删除员工ID
    QSqlQuery query("SELECT * FROM [Employee Information]",QSqlDatabase::database("socool"));

    //获取model选择的员工信息
    if(!query.seek(person->mapping()->currentIndex()))
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

    //
    person->Switch_sql(Person_show::NO);
    model->refresh();
}


void MainWindow::on_action_salary_triggered()
{
    QSqlQuery query(QSqlDatabase::database("socool"));
    query.prepare("UPDATE 'Employee information' SET salary=salary+200");
    if(!query.exec())
        QMessageBox::information(this,"错误","问题原因:"+query.lastError().text());
    model->refresh();
}

