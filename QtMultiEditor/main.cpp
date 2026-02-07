#include "mainwindow.h"
#include "start.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //登录页面
    Start ow;
    if(ow.exec()==QDialog::Accepted)
    {
        //启动动画
        QPixmap pixmap(":/qrc/20200424211346_ldswb.gif");
        QSplashScreen splash(pixmap);
        splash.show();
        //延迟2秒进入主页面
        QTimer timer;
        timer.setInterval(3000);
        timer.start();
        while(timer.remainingTime()!=0);

        MainWindow w;
        w.show();

        splash.finish(&w);
        return a.exec();
    }
    return 0;
}
