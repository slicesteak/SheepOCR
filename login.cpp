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
    QString ID,APIK,SK,Token;

        QString s=QString("select username,app_id,api_key,sk,token from user where username='%1'and password='%2' ").arg(UName).arg(Pword);//数据库存储用户名用username密码用password
        //查询数据库如果账号和密码匹配返回真否则返回假
        QSqlQuery query;
        if(query.exec(s)){
            //QMessageBox::information(NULL, "登陆成功", "登陆成功！！！", QMessageBox::Yes);
            while(query.next()){
                    ID=query.value(1).toString();
                    APIK=query.value(2).toString();
                    SK=query.value(3).toString();
                    Token=query.value(4).toString();
                }
            w=new Widget(this,UName,ID,APIK,SK,Token,0);
            w->show();
            this->hide();
        }
        else
            QMessageBox::warning(NULL,"Error","登录失败，请重试！！！");
}

void Login::on_passBtn_clicked()
{
    QString  UName ="Guest";
    w=new Widget(0,UName,1);
    w->show();
    this->hide();
}
