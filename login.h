#ifndef Login_H
#define Login_H

#include <QWidget>
#include <QLabel>
#include "widget.h"
#define CONNECT_DB 0//数据库开关，1连接数据库，其他不连数据库

namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

//signals:
//    void sendData(QString);

private slots:

    void on_signBtn_clicked();

    void on_sendBtn_clicked();

    void on_passBtn_clicked();

private:
    Widget* w;

    Ui::Login *ui;
};

#endif // Login_H


