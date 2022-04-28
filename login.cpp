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
}

Login::~Login()
{
    delete ui;
}

void Login::on_signBtn_clicked()
{
      this->hide();
        Registerwindow re;
        re.show();
        re.exec();
        this->show();
}

void Login::on_sendBtn_clicked()
{
    QString  UName = ui->userLineEdit->text();
    QString  Pword = ui->passwardLineEdit->text();
    if(CONNECT_DB==1){
        QString s=QString("select * from user where username='%1'and password='%2' ").arg(UName).arg(Pword);//数据库存储用户名用username密码用password
        //查询数据库如果账号和密码匹配返回真否则返回假
        QSqlQuery query;
        query.exec(s);
        if(query.first()){
            //QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
            w=new Widget(this,UName);
            w->show();
            this->hide();
        }
        else
            QMessageBox::warning(NULL,"Error","登录失败，请重试！！！");
    }
    else{
        w=new Widget(this,UName);
        w->show();
        this->hide();
    }
}
