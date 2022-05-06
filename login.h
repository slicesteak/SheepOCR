#ifndef Login_H
#define Login_H

#include <QWidget>
#include <QLabel>
#include "widget.h"
#include <QtNetwork>
#include"mymessagebox.h"



namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:

    void on_signBtn_clicked();

    void on_sendBtn_clicked();

    void on_passBtn_clicked();
private:
    Widget* w;

    Ui::Login *ui;
    int connected;

};

#endif // Login_H


