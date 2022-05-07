#include "login.h"
#include "ui_login.h"
#include "register.h"
#include <Qtsql>
#include <QMessageBox>
#include "widget.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_signBtn_clicked()
{
    if(connected!=1){
        //连接数据库
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("114.116.223.74");
        db.setDatabaseName("user");
        db.setUserName("root");
        db.setPort(3306);
        db.setPassword("Vfish123456=");
        //如果数据库连接成功打开窗口否则退出程序
        if(db.open()){
            connected=1;
            this->hide();
            Registerwindow re;
            re.show();
            re.exec();
            this->show();
        }
        else{
            QMessageBox::warning(NULL,"error","数据库连接失败,该功能不可用");
        }
    }
    else{
        this->hide();
            Registerwindow re;
            re.show();
            re.exec();
            this->show();
    }
}

void Login::on_sendBtn_clicked()
{
    if(connected!=1){
    //连接数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("114.116.223.74");
    db.setDatabaseName("user");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("Vfish123456=");
    //如果数据库连接成功打开窗口否则退出程序
    if(db.open()){
        connected=1;
        QString  UName = ui->userLineEdit->text();
        QString  Pword = ui->passwardLineEdit->text();
        if(UName=="" || Pword=="")
            QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
        else{
            QString ID,APIK,SK,Token;

            QString s=QString("select username,app_id,api_key,sk,token from user where username='%1'and password='%2' ").arg(UName).arg(Pword);//数据库存储用户名用username密码用password
            //查询数据库如果账号和密码匹配返回真否则返回假
            QSqlQuery query;
            query.exec(s);
            if(query.first()){
                //QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
                query.exec(s);
                while(query.next()){
                    ID=query.value(1).toString();
                    APIK=query.value(2).toString();
                    SK=query.value(3).toString();
                    Token=query.value(4).toString();
                }
                w=new Widget(0,UName,ID,APIK,SK,Token,0);
                w->show();
                this->hide();
            }
            else
                QMessageBox::warning(NULL,"Error","登录失败，用户名或密码错误，请重试！！！");
        }
    }
    else{
        QMessageBox::warning(NULL,"error","数据库连接失败,该功能不可用");
    }
    }
    else{
        QString  UName = ui->userLineEdit->text();
        QString  Pword = ui->passwardLineEdit->text();
        if(UName=="" || Pword=="")
            QMessageBox::information(this,"警告","输入不能为空",QMessageBox::Ok);
        else{
            QString ID,APIK,SK,Token;

            QString s=QString("select username,app_id,api_key,sk,token from user where username='%1'and password='%2' ").arg(UName).arg(Pword);//数据库存储用户名用username密码用password
            //查询数据库如果账号和密码匹配返回真否则返回假
            QSqlQuery query;
            query.exec(s);
            if(query.first()){
                //QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
                query.exec(s);
                while(query.next()){
                    ID=query.value(1).toString();
                    APIK=query.value(2).toString();
                    SK=query.value(3).toString();
                    Token=query.value(4).toString();
                }

                w=new Widget(0,UName,ID,APIK,SK,Token,0);
                w->show();
                this->hide();
            }
            else
                QMessageBox::warning(NULL,"Error","登录失败，用户名或密码错误，请重试！！！");
        }
    }
}

void Login::on_passBtn_clicked()
{
    QString  UName ="Guest";
    w=new Widget(0,UName,1);
    w->show();
    this->hide();
}
