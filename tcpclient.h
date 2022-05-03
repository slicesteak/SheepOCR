#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QMainWindow>
#include <QtNetwork>
#include <QMessageBox>

class TcpClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit TcpClient(QWidget *parent = 0);
    ~TcpClient();
    void init();
    void connectServer();
    bool get_status();
    void write(QString data);
    int login_status;//登录状态
    int register_status;//注册状态
    int info_ready;//获取用户信息状态
    QString  UName;//用户名
    QString app_id;
    QString api_key;
    QString secret_key;
    QString accessToken;

private slots:

    void displayError(QAbstractSocket::SocketError);

    void readMessages();

private:
    QTcpSocket *tcpSocket;//用于连接服务器
    int connected;//判断是否连接上服务器

};

#endif // TCPCLIENT_H
