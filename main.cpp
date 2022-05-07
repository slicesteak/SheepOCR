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

    QApplication::addLibraryPath("./plugins");
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

    return a.exec();
}
