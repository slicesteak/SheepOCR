#include "login.h"
#include "ui_login.h"
#include "register.h"
#include <QtSql>
#include <QMessageBox>
#include "widget.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    client.init();
    client.connectServer();
}

Login::~Login()
{
    delete ui;
}

void Login::on_signBtn_clicked()
{
    if(client.get_status()){

      this->hide();
        Registerwindow re;
        re.show();
        re.exec();
//        init();
//        connectServer();
        this->show();
    }
    else{
        QMessageBox::information(this,"信息提示","未连接上服务器，该功能不可用!",QMessageBox::Ok);
    }
}

void Login::on_sendBtn_clicked()
{
    if (client.get_status()){
        QString userName=ui->userLineEdit->text();
        QString passward=ui->passwardLineEdit->text();
        if(userName=="" || passward=="")
            QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
        else{
            QString bs="b";
            QString data=bs+"#"+userName+"#"+passward;
            client.write(data);
            while((client.login_status!=1)||(client.info_ready!=1)){
                QCoreApplication::processEvents();
            }
            w=new Widget(0,userName,client.app_id,client.api_key,client.secret_key,client.accessToken,0);
            w->show();
            this->hide();
            //tcpSocket->write(data.toLatin1());
            //        if(timer->isActive()==true){
            //            timer->stop();
            //        }
            //        if(timer->isActive()==false){
            //            timer->start(100);
            //        }
        }
    }
    else{
        QMessageBox::information(this,"信息提示","未连接上服务器，该功能不可用!",QMessageBox::Ok);
    }


//    QString  UName = ui->userLineEdit->text();
//    QString  Pword = ui->passwardLineEdit->text();
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
//            QString s=QString("select * from user where username='%1'and password='%2' ").arg(UName).arg(Pword);//数据库存储用户名用username密码用password
//            //查询数据库如果账号和密码匹配返回真否则返回假
//            QSqlQuery query;
//            query.exec(s);
//            if(query.first()){
//                //QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
//                w=new Widget(this,UName,0);
//                w->show();
//                this->hide();
//            }
//            else
//                QMessageBox::warning(NULL,"Error","登录失败，请重试！！！");
//        }
//        else
//        {
//            QMessageBox::warning(NULL,"error","数据库连接失败");
//        }

//    }
//    else{
//        w=new Widget(this,UName,0);
//        w->show();
//        this->hide();
//    }
}


void Login::on_passBtn_clicked()
{
    QString  UName ="Guest";
    w=new Widget(0,UName,1);
    w->show();
    this->hide();
}
