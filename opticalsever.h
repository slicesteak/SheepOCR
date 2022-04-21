#ifndef SCANPIC_H
#define SCANPIC_H

#include<iostream>
//#include<json/json.h>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include<QtNetwork>
#include<QUrl>
#include<QFile>
#include<QtDebug>
#include<QImage>
#include<QObject>
class Option
{
public:
    std::string app_id;
    std::string api_key;
    std::string secret_key;
    std::string accessToken;

    Option();
    QString getURL();
};

class OpticalSever
{

public:

    Option configOption;
    QNetworkAccessManager *manager;//用于管理请求数据的发送
    QNetworkReply *reply;//用于接受返回数据
    QNetworkRequest request;
    QByteArray imgBase64;

public:
    OpticalSever();
    QString scanPic(QString path); //识别图片，将图片转base64
    void setConfig();  //设置识别选项
    void sendRequest();  //发送请求
    QString receiveResult();  //接收返回结果,并将结果保存
    void update();  //更新token
    QString result;

private slots:

};

#endif // SCANPIC_H
