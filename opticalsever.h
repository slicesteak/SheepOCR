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
#include"mymessagebox.h"


//error info
#define IMG_MAX_SIZE 4194304
#define IMG_OVER_SIZE 0
#define IMG_NOT_EXIST 1
#define INVALID_MODE 2
#define TIME_OUT 3

#define MODE_ACCURATE_BASIC 0  //通用文字识别（高精度版）
#define MODE_ACCURATE 1  //通用文字识别（高精度含位置版）
#define MODE_GENERAL_BASIC 2  //通用文字识别（标准版）     *默认是这个
#define MODE_GENERAL 3  //通用文字识别（标准含位置版）
#define MODE_DOC_ANALYSIS_OFFICE 4  //办公文档识别
#define MODE_WEBIMAGE 5  //网络图片文字识别
#define MODE_WEBIMAGE_LOC 6  //网络图片文字识别（含位置版）
#define MODE_HANDWRITING 7  //手写文字识别
#define MODE_TABLE 8  //表格文字识别V2
#define MODE_SEAL 9  //印章识别
#define MODE_NUMBERS 10  //数字识别
#define MODE_QRCODE 11  //二维码识别


class Option
{
public:
    QString path;//待识别的图片存放路径
    int mode; //识别模式
    Option();
    ~Option();
    QString getURL();

private:
    QString app_id;
    QString api_key;
    QString secret_key;
    QString accessToken;
    QString URLProfix;
};

class OpticalSever: public QObject
{
    Q_OBJECT
    
public:

    Option configOption;
    QNetworkAccessManager *manager;//用于管理请求数据的发送
    bool canReceive;
    OpticalSever(QObject * parent);
    ~OpticalSever();

    void setConfig();  //设置识别选项
    void start(); //开始识别，需要先设置图片路径path，然后才能识别
    QString getResult();
    void TokenUpdate();  //更新token

signals:
    void sig_changebacktoselectmode();

private:    
    QString result;  //存储返回的result
    QNetworkReply *reply;       //用于接受返回数据
    QNetworkRequest request;    //设置发送的请求设定    
    QByteArray imgBase64;       //图片编码并进行urlencode
    MyMessageBox *OCR_notice_box;//各种情况的提醒

    void scanPic(); //识别图片，将图片转base64
    void sendRequest();  //发送请求    

    void infoNotice(int error_msg);  //显示错误信息
    
private slots:
    void receiveResult();  //接收返回结果,并将结果保存

};

#endif // SCANPIC_H
