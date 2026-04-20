#ifndef PERSON_SHOW_H
#define PERSON_SHOW_H

#include <QWidget>
#include <QSqlRecord>
#include <QDataWidgetMapper>

namespace Ui {
class Person_show;
}

class Person_show : public QWidget
{
    Q_OBJECT

public:enum Change{INSERT,DELETE,UPDATE,NO};

private:
    QSqlRecord record;
    QDataWidgetMapper* mapper;
    Person_show::Change idu=NO;//获取当前要操作状态

protected slots:
    void Inssrt();
    void Delete();
    void Update();

public slots:
    void do_phtoot(int);

public:
    QByteArray read_photo();//读ui照片数据
    void  wird_photo(QByteArray&);//ui存照片
    QDataWidgetMapper* mapping();//建立映射信号和槽
    void mapper_ui();          //建立ui映射
    void record_before(QSqlRecord cord);
    void Switch_sql(Person_show::Change diu){idu=diu;}//获取执行操作状态


public:
    explicit Person_show(QWidget *parent = nullptr);
    ~Person_show();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Person_show *ui;
};

#endif // PERSON_SHOW_H
