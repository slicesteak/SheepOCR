#include "tcpclient.h"
#include "widget.h"

#define ip "114.116.223.74"
#define port 3306

TcpClient::TcpClient(QWidget *parent) :
    QMainWindow(parent)
{
    connected=0;
    init();
    connectServer();
}

TcpClient::~TcpClient()
{
    delete tcpSocket;
}

void TcpClient::init()
{
    tcpSocket=new QTcpSocket(this);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),
            this,SLOT(displayError(QAbstractSocket::SocketError)));   //发生错误时执行displayError函数
}

void TcpClient::connectServer()
{
    tcpSocket->abort();   //取消已有的连接
    tcpSocket->connectToHost(ip,port);//连接服务器，需要维护的部分
    if (tcpSocket->waitForConnected(500)) {
        connected=1;
    }
    else{
        //QMessageBox::information(this,"信息提示","连接服务器超时!",QMessageBox::Ok);
        connected=0;
    }
    connect(tcpSocket,SIGNAL(readyRead()),this,SLOT(readMessages()));
}



void TcpClient::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString();   //输出出错信息
}


void TcpClient::readMessages()
{
    QString data=tcpSocket->readAll();
    QStringList list=data.split("#");
    if(list[0]=="a" && list[1]=="true"){
        register_status=1;
        QMessageBox::information(this,"信息提示","注册成功!",QMessageBox::Ok);
    }
    else if(list[0]=="a" && list[1]=="false"){
        register_status=0;
        QMessageBox::information(this,"信息提示","注册失败,用户名已经被注册!",QMessageBox::Ok);
     }
    else if(list[0]=="b" && list[1]=="true"){

        UName=list[2];
        app_id=list[3];
        api_key=list[4];
        secret_key=list[5];
        accessToken=list[6];
        info_ready=1;
        login_status=1;
        //QMessageBox::information(this,"信息提示","登录成功!",QMessageBox::Ok);
    }
    else if(list[0]=="b" && list[1]=="false"){
        login_status=0;
        QMessageBox::information(this,"信息提示","登录失败,用户名或密码错误!",QMessageBox::Ok);
    }
    else if(list[0]=="c" && list[1]=="false"){
        QMessageBox::information(this,"信息提示","麻了!",QMessageBox::Ok);
    }
    else if(list[0]=="c" && list[1]=="true"){
        info_ready=3;
    }
    else if(list[0]=="d"){
        UName=list[2];
        app_id=list[3];
        api_key=list[4];
        secret_key=list[5];
        accessToken=list[6];
        info_ready=2;
    }
    else
        return;
}

bool TcpClient::get_status(){
    if(connected==1){
        return true;
    }
    else{
        return false;
    }
}


void TcpClient::write(QString data){
    tcpSocket->write(data.toLatin1());
}
