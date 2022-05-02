#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QMainWindow>
#include <QtNetwork>
#include <QTimer>
#include "mysql.h"

namespace Ui {
class TcpServer;
}

class TcpServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TcpServer(QWidget *parent = 0);
    ~TcpServer();

    QString checkSignIn(QString name,QString passward);
    bool checkSignUp(QString name,QString passward);
    QString getinfo(QString name);

protected:
    void init();                         // 初始化函数用于完成一些诸如信号与槽之间的联系和变量初始化工作

private slots:
    void on_startBtn_clicked();

    void acceptConnection();

    void receiveData();

    void displayError(QAbstractSocket::SocketError);


private:
    Ui::TcpServer *ui;
    QTcpSocket *tcpSocket;
    QTcpServer *tcpServer;
    QString ip;
    MySql ms;
};

#endif // TCPSERVER_H
