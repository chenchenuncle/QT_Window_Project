#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QActionGroup>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QBuffer>


QSqlRecord &MainWindow::INIT(QSqlRecord& record)
{
    int max=0;
    //获取工号最大值的一个
    {
        bool in=true;
        QSqlQuery query(QSqlDatabase::database("sqlite_scool",in));
        if(!in)
            QMessageBox::information(this,"警告","数据库打不开");
        query.prepare("SELECT MAX(Employee_ID) FROM 'Employee Information'");
        query.exec();
        if(query.next())
        {
            max=query.value(0).toInt();
            qDebug("成功");
        }
        if(!query.isValid())
        QMessageBox::information(this,"警告",query.lastError().text());
    }
    record.setValue("Employee_ID",QVariant(max+1));
    record.setValue("name",QVariant("某某"));
    record.setValue("birthday",QVariant("2000-01-01"));
    record.setValue("salary",QVariant(5000));
    return record;
}

void MainWindow::Photo(QSqlRecord &record) const
{
    // 获取图片数据
    QVariant variant = record.value("photo");
    QByteArray bytearray = variant.toByteArray();

    if (bytearray.isEmpty()) {
        ui->label_2->clear();
        return;
    }

    QPixmap pixmap;
    if (!pixmap.loadFromData(bytearray)) {
        ui->label_2->clear();
        return;
    }

    // 使用 label_2 的尺寸作为目标尺寸
    QSize labelSize = ui->label_2->size();

    // 缩放到标签大小，保持宽高比，使用平滑变换
    QPixmap scaledPixmap = pixmap.scaled(
        labelSize,
        Qt::KeepAspectRatio,  // 保持宽高比
        Qt::SmoothTransformation  // 平滑变换，提高质量
        );

    // 取消自动缩放，避免双重缩放
    ui->label_2->setScaledContents(false);
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->setPixmap(scaledPixmap);
}

void MainWindow::do_Filter(bool is)
{
    Q_UNUSED(is)
    if(ui->radioButton_3->isChecked())
        dbtablemodel->setFilter("");
    else if(ui->radioButton_2->isChecked())
        dbtablemodel->setFilter("Gender='女'");
    else
        dbtablemodel->setFilter("Gender='男'");
    dbtablemodel->select();
}

void MainWindow::do_currentChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    Q_UNUSED(current);
}

void MainWindow::do_currentRowChanged(const QModelIndex &current, const QModelIndex &previous)
{
    Q_UNUSED(previous);
    //设置图片
    QSqlRecord phot=dbtablemodel->record(current.row());
    this->Photo(phot);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化全部数据
    QSqlDatabase::addDatabase("QSQLITE","sqlite_scool");//初始化db数据库
    dbtablemodel=new QSqlTableModel(this);
    itemmodel=new QItemSelectionModel(dbtablemodel,this);
    mapper=new QDataWidgetMapper(this);
    mapper->setModel(dbtablemodel);
    combox_esx=new QStyledItem_combok(this);
    combox_ment=new QStyledItem_combok(this);
    combox_province=new QStyledItem_combok(this);


    //初始化数据，构造视图/模型
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setModel(dbtablemodel);
    ui->tableView->setSelectionModel(itemmodel);

    //映射小组件和数据库数据之间关系
    mapper->setModel(dbtablemodel);
    mapper->addMapping(ui->spinBox,0);
    mapper->addMapping(ui->lineEdit,1);
    mapper->addMapping(ui->comboBox_2,2);
    mapper->addMapping(ui->dateEdit,3);
    mapper->addMapping(ui->comboBox_3,4);
    mapper->addMapping(ui->comboBox_4,5);
    mapper->addMapping(ui->doubleSpinBox,6);
    mapper->toFirst();

    //修改表格编辑模式
    QStringList list;
    list<<"男"<<"女";
    combox_esx->setinit(list);
    list.clear();
    list<<"行政部"<<"销售部"<<"生产部"<<"技术部";
    combox_ment->setinit(list);
    ui->comboBox_4->addItems(list);
    list.clear();
    QString str=(
    "河北省、山西省、辽宁省、吉林省、黑龙江省、江苏省、浙江省、安徽省、福建省、江西省、山东省、河南省、湖北省、湖南省、广东省、海南省、四川省、贵州省、云南省、陕西省、甘肃省、青海省、台湾省、"
    "内蒙古自治区、广西壮族自治区、西藏自治区、宁夏回族自治区、新疆维吾尔自治区、"
    "北京、天津、上海、重庆、特别行政区香港特别行政区、澳门特别行政区");
    list=str.split("、");
    combox_province->setinit(list);
    ui->comboBox_3->addItems(list);
    ui->tableView->setItemDelegateForColumn(2,combox_esx);
    ui->tableView->setItemDelegateForColumn(4,combox_ment);
    ui->tableView->setItemDelegateForColumn(5,combox_province);


    //初始化按钮
    ui->action_1->setEnabled(true);
    ui->action_2->setEnabled(false);
    ui->action_3->setEnabled(false);
    ui->action_4->setEnabled(false);
    ui->action_5->setEnabled(false);
    ui->action_6->setEnabled(false);
    ui->action_7->setEnabled(false);
    ui->action_8->setEnabled(false);
    ui->action_9->setEnabled(false);

    //建立槽和信号
    connect(itemmodel,&QItemSelectionModel::currentChanged,this,&::MainWindow::do_currentChanged);
    connect(itemmodel,&QItemSelectionModel::currentRowChanged,this,&::MainWindow::do_currentRowChanged);
    connect(itemmodel,&QItemSelectionModel::currentRowChanged,mapper, &QDataWidgetMapper::setCurrentModelIndex);
    //connect(ui->tableView,&QAbstractItemView::editorDestroyed,this);

    //过滤器信号
    connect(ui->radioButton,&QRadioButton::toggled,this,&::MainWindow::do_Filter);
    connect(ui->radioButton_2,&QRadioButton::toggled,this,&::MainWindow::do_Filter);
    connect(ui->radioButton_3,&QRadioButton::toggled,this,&::MainWindow::do_Filter);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_action_8_triggered()
{

    QModelIndex model=ui->tableView->currentIndex();
    //如果正在编辑
    if(ui->tableView->isPersistentEditorOpen(model))
    {
        QAbstractItemDelegate* of=ui->tableView->itemDelegateForIndex(model);
        ui->tableView->commitData_Mandatory(of);//强制提交数据
        ui->tableView->closePersistentEditor(model);
    }

    //关闭2个组件
    ui->action_8->setEnabled(false);
    ui->action_9->setEnabled(false);

    //保存更改数据
    if(!dbtablemodel->submitAll())
        QMessageBox::information(this,"信息框","保存错误原因:"+dbtablemodel->lastError().text());
}


void MainWindow::on_action_9_triggered()
{
    ui->action_9->setEnabled(false);
    ui->action_8->setEnabled(false);

    //取消所有更改
    dbtablemodel->revertAll();
}


void MainWindow::on_action_1_triggered()
{
    //选择数据库文件
    QString db_name=QFileDialog::getOpenFileName(this,"选择文件","请选择数据库文件",("*db3 *db *sql *sqlite"));
    if(db_name.isEmpty())
        return;

    //只打开通道，没有连接
    QSqlDatabase db=QSqlDatabase::database("sqlite_scool");
    db.setDatabaseName(db_name);
    if(!db.open())
    {
        QMessageBox::information(this,"信息框",db.lastError().databaseText());
        return ;
    }

    //模型重新获取db数据库文件
    delete dbtablemodel;
    dbtablemodel=new QSqlTableModel(this,db);
    itemmodel->setModel(dbtablemodel);
    ui->tableView->setModel(dbtablemodel);
    ui->tableView->setSelectionModel(itemmodel);

    //模型获取数据库以及初始化数据表
    dbtablemodel->setTable("Employee Information");
    dbtablemodel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord information;
    dbtablemodel->setSort(information.indexOf("Employee_ID"),Qt::AscendingOrder);
    information=dbtablemodel->record();
    dbtablemodel->setHeaderData(information.indexOf("Employee_ID"),Qt::Horizontal,QVariant("工号"));
    dbtablemodel->setHeaderData(information.indexOf("name"),Qt::Horizontal,QVariant("姓名"));
    dbtablemodel->setHeaderData(information.indexOf("Gender"),Qt::Horizontal,QVariant("性别"));
    dbtablemodel->setHeaderData(information.indexOf("birthday"),Qt::Horizontal,QVariant("出生日期"));
    dbtablemodel->setHeaderData(information.indexOf("province"),Qt::Horizontal,QVariant("省份"));
    dbtablemodel->setHeaderData(information.indexOf("department"),Qt::Horizontal,QVariant("部门"));
    dbtablemodel->setHeaderData(information.indexOf("salary"),Qt::Horizontal,QVariant("工资"));
    dbtablemodel->setHeaderData(information.indexOf("photo"),Qt::Horizontal,QVariant("照片"));
    dbtablemodel->setHeaderData(information.indexOf("meno"),Qt::Horizontal,QVariant("备注"));

    //修改表格编辑模式
    ui->tableView->setItemDelegateForColumn(information.indexOf("Gender"),combox_esx);
    ui->tableView->setItemDelegateForColumn(information.indexOf("department"),combox_ment);
    ui->tableView->setItemDelegateForColumn(information.indexOf("province"),combox_province);

    //初始化组件页面
    ui->radioButton_5->setChecked(true);
    ui->radioButton_3->setChecked(true);
    ui->comboBox->setCurrentText("Employee_ID");
    ui->tableView->hideColumn(information.indexOf("photo"));
    ui->tableView->hideColumn(information.indexOf("meno"));

    //重新激活映射小组件和数据库数据之间关系
    mapper->setModel(dbtablemodel);
    mapper->setSubmitPolicy(QDataWidgetMapper::AutoSubmit);
    mapper->addMapping(ui->spinBox,information.indexOf("Employee_ID"));
    mapper->addMapping(ui->lineEdit,information.indexOf("name"));
    mapper->addMapping(ui->comboBox_2,information.indexOf("Gender"));
    mapper->addMapping(ui->dateEdit,information.indexOf("birthday"));
    mapper->addMapping(ui->comboBox_3,information.indexOf("province"));
    mapper->addMapping(ui->comboBox_4,information.indexOf("department"));
    mapper->addMapping(ui->doubleSpinBox,information.indexOf("salary"));
    mapper->addMapping(ui->textEdit,information.indexOf("meno"));
    mapper->toFirst();

    //激活工作组件
    ui->action_2->setEnabled(true);
    ui->action_3->setEnabled(true);
    ui->action_4->setEnabled(true);
    ui->action_5->setEnabled(true);
    ui->action_6->setEnabled(true);
    ui->action_7->setEnabled(true);

    if (!dbtablemodel->select()) {
        QMessageBox::critical(this, "错误", "无法加载数据：" + dbtablemodel->lastError().text());
        return;
    }
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    Q_UNUSED(index);
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_action_2_triggered()
{
    //视图添加新表格
    int row=dbtablemodel->rowCount();

    //初始化新数据信息
    QSqlRecord record=dbtablemodel->record();
    INIT(record);
    dbtablemodel->insertRecord(row,record);

    //激活保存组件
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_action_3_triggered()
{
    //视图插入表格
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();

    //初始化新数据信息
    QSqlRecord record=dbtablemodel->record();
    INIT(record);
    dbtablemodel->insertRecord(row,record);

    //激活保存组件
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_action_4_triggered()
{
    //删除表格
    QModelIndex index=ui->tableView->currentIndex();
    int row=index.row();
    dbtablemodel->removeRows(row,1);

    //激活保存组件
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_action_5_triggered()
{
    //获取照片位置
    QString str=QFileDialog::getOpenFileName(this,"照片文件");

    //读取照片数据并显示
    QPixmap pixmap(str);
    QSize size=ui->label_2->size();
    // 缩放到标签大小，保持宽高比，使用平滑变换
    QPixmap scaledPixmap = pixmap.scaled(
        size,
        Qt::KeepAspectRatio,  // 保持宽高比
        Qt::SmoothTransformation  // 平滑变换，提高质量
        );
   ui->label_2->setPixmap(scaledPixmap);

    //获取数据库当前照片位置
    int row=mapper->currentIndex();//获取行的位置
    int courroom=dbtablemodel->record().indexOf("photo");//获取列的位置
    QModelIndex index=dbtablemodel->index(row,courroom);//获取照片位置

    //转成二进制
    QByteArray array;
    QBuffer cou_o(&array);
    cou_o.open(QIODeviceBase::WriteOnly);
    pixmap.save(&cou_o,"jpg");

    //图片二进制存入模型
    QVariant ant(array);
    dbtablemodel->setData(index,ant);

    //激活组件
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_action_6_triggered()
{
    //获取数据库当前照片位置
    int row=mapper->currentIndex();//获取行的位置
    int courroom=dbtablemodel->record().indexOf("photo");//获取列的位置
    QModelIndex index=dbtablemodel->index(row,courroom);//获取照片位置

    //删除组件照片
    ui->label_2->clear();

    //删除模型数据照片数据
    if(!dbtablemodel->clearItemData(index))
        QMessageBox::information(this,"信息框","删除数据库数据失败原因:"+dbtablemodel->lastError().text());

    //激活组件
    ui->action_8->setEnabled(true);
    ui->action_9->setEnabled(true);
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    QSqlRecord record=dbtablemodel->record();
    int currom=record.indexOf(arg1);
    if(ui->radioButton_5->isChecked())
        dbtablemodel->sort(currom,Qt::AscendingOrder);
    else
        dbtablemodel->sort(currom,Qt::DescendingOrder);
}


void MainWindow::on_radioButton_5_toggled(bool checked)
{
    Q_UNUSED(checked);
    QSqlRecord record=dbtablemodel->record();
    int currom=record.indexOf(ui->comboBox->currentText());
    dbtablemodel->sort(currom,Qt::AscendingOrder);
}


void MainWindow::on_radioButton_4_toggled(bool checked)
{
    Q_UNUSED(checked);
    QSqlRecord record=dbtablemodel->record();
    int currom=record.indexOf(ui->comboBox->currentText());
    dbtablemodel->sort(currom,Qt::DescendingOrder);
}

void MainWindow::on_action_7_triggered()
{
    QSqlQuery query(QSqlDatabase::database("sqlite_scool"));
    query.prepare("UPDATE 'Employee information' SET salary=salary+:1");
    query.bindValue(":1",500);
    if(!query.exec())
        qDebug()<<"执行失败";
    dbtablemodel->submitAll();
}

