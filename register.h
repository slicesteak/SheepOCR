#ifndef REGISTER_H
#define REGISTER_H
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QGridLayout>
#include <QtNetwork>
#include<QTimer>
#include "tcpclient.h"
class Registerwindow:public QDialog
{
    Q_OBJECT

public:
    Registerwindow(QWidget *parent = 0);
    ~Registerwindow();
private:
    //声明布局
    QGridLayout *MessageLayout;
    QGridLayout *ButtonLayout;
    QGridLayout *MainLayout;
    //声明信息成员
    QLabel *UserName;
    QLabel *Password;
    QLabel *RePassword;
    QLineEdit *UserNameEdit;
    QLineEdit *PasswordEdit;
    QLineEdit *RePasswordEdit;
    QLabel *Email;
    //QLineEdit *EmailEdit;
    QPushButton *confirm;
    QPushButton *resetting;
    //声明槽

    TcpClient client;//用于与服务器连接
public slots:
    void confirm_slots();

};
#endif // REGISTER_H
