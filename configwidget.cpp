#include "configwidget.h"
#include "ui_configwidget.h"
#include "modifywidget.h"

ConfigWidget::ConfigWidget(QWidget *parent,QString Username,QString ID,QString APIK,QString SK,QString Token) :
    QDialog(parent),
    ui(new Ui::ConfigWidget)
{
    this->username=Username;
    this->app_id=ID;
    this->api_key=APIK;
    this->secret_key=SK;
    this->accessToken=Token;

    ui->setupUi(this);
   this->initUi();
}

void ConfigWidget::initUi(){
    ui->label_username->setText(this->username);
    ui->label_AppID->setText(this->app_id);
    ui->label_APIK->setText(this->api_key);
    ui->label_SK->setText(this->secret_key);
    ui->label_token->setText(this->accessToken);
}

ConfigWidget::~ConfigWidget()
{
    delete ui;
}

void ConfigWidget::on_confirmBtn_clicked()
{
        mw=new ModifyWidget(nullptr,this->username,this->app_id,this->api_key,this->secret_key,this->accessToken);
        mw->show();
        mw->exec();
        this->hide();
}
