#include "widget.h"
#include "appinit.h"
#include <QApplication>
#include <QFile>
#include <QFont>
#include "login.h"
#include <QApplication>
#include <QtSql>
#include <QMessageBox>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    //加载样式表
    QFile file(":/css/index.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }

    //全局字体
    QFont font("Arial", 10);
    a.setFont(font);

    //屏幕拖动
    AppInit::Instance()->start();
    Login lw;
    lw.show();
//    if(CONNECT_DB==1){

//        //连接数据库
//        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
//        db.setHostName("localhost");
//        db.setDatabaseName("user");
//        db.setUserName("root");
//        db.setPort(3306);
//        db.setPassword("123456");
//        //如果数据库连接成功打开窗口否则退出程序
//        if(db.open())
//        {
//            lw.show();
//        }
//        else
//        {
//            QMessageBox::warning(NULL,"error","数据库连接失败");
//            return 0;
//        }
//    }
//    else{
//        lw.show();
//    }


    return a.exec();
}
