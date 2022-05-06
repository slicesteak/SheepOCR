#include "modifywidget.h"
#include "ui_modifywidget.h"
#include <Qtsql>

ModifyWidget::ModifyWidget(QWidget *parent,QString Username,QString ID,QString APIK,QString SK,QString Token) :
    QDialog(parent),
    ui(new Ui::ModifyWidget)
{
    this->username=Username;
    this->app_id=ID;
    this->api_key=APIK;
    this->secret_key=SK;
    this->accessToken=Token;
    ui->setupUi(this);
    this->initUi();
}

void ModifyWidget::initUi(){
    //ui->usernameLineEdit->setText(this->username);
    ui->AppIDLineEdit->setText(this->app_id);
    ui->APIKLineEdit->setText(this->api_key);
    ui->SKLineEdit->setText(this->secret_key);
    ui->TokenLineEdit->setText(this->accessToken);
}

ModifyWidget::~ModifyWidget()
{
    delete ui;
}

void ModifyWidget::on_confirmBtn_clicked()
{
    QString AppID=ui->AppIDLineEdit->text();
    QString APIK=ui->APIKLineEdit->text();
    QString SK=ui->SKLineEdit->text();
    QString token=ui->TokenLineEdit->text();
    QString s=QString("update user set app_id='%1',api_key='%2',sk='%3',token='%4' where username='%5' ").arg(AppID).arg(APIK).arg(SK).arg(token).arg(this->username);
    QSqlQuery query;
    query.exec(s);
    this->hide();
}
