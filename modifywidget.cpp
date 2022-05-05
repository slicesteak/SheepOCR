#include "modifywidget.h"
#include "ui_modifywidget.h"
#include <Qtsql>

ModifyWidget::ModifyWidget(QWidget *parent,QString Username,QString ID,QString APIK,QString SK,QString Token) :
    QDialog(parent),
    ui(new Ui::ModifyWidget)
{
    client.init();
    client.connectServer();
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
    while(!client.get_status()){
        QCoreApplication::processEvents();
        qDebug()<<"wwwww";
    }qDebug()<<"hhhhh";
    QString AppID=ui->AppIDLineEdit->text();
    QString APIK=ui->APIKLineEdit->text();
    QString SK=ui->SKLineEdit->text();
    QString token=ui->TokenLineEdit->text();
    QString cs="c";
    QString data=cs+"#"+this->username+"#"+AppID+"#"+APIK+"#"+SK+"#"+token;
    client.write(data);
    while(client.info_ready!=3){
        QCoreApplication::processEvents();
        qDebug()<<client.info_ready;
    }qDebug()<<"yyyyy";
    this->hide();
}
