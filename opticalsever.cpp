#include "opticalsever.h"
#include<QtNetwork/QNetworkAccessManager>


Option::Option():app_id("25882743")
  ,api_key("6rkXHclKC0LKkSsm4GZTlySz")
  ,secret_key("tISesOCtKxrIyjMD5uHpnubxgkhBm6fW"),
    accessToken("24.ee411a21021406f10e64e7ca6cc84cd8.2592000.1651311561.282335-25882743")
{

}

OpticalSever::OpticalSever()
{
    manager=new QNetworkAccessManager();
}


QString OpticalSever::scanPic(QString path)
{
    QImage img(path);
    QByteArray imageData;
    QBuffer buffer(&imageData);
    img.save(&buffer,"png");
    this->imgBase64 = imageData.toBase64();
    buffer.close();
    return "";
}

void OpticalSever::setConfig()
{
    //url.setUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/idcard"  + "?access_token=" + accessToken );
}

void OpticalSever::sendRequest()
{
    QUrl dest(configOption.getURL());
//    qDebug()<<configOption.getURL();

    this->request.setUrl(dest);
//    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray body;
    body.append("image=");
    body.append(QUrl::toPercentEncoding(imgBase64));
    reply=manager->post(request,body);
    qDebug()<<"成功send(),如果图片较大,需要稍微等一下,我应该加个什么UI提醒的功能";
}

void OpticalSever::receiveResult(){

    qDebug()<<"成功receive()";
    QByteArray data=reply->readAll();

    QJsonDocument jsonFile=QJsonDocument::fromJson(data);
    QJsonValue value;
    QString contents;
    QJsonValue res= jsonFile.object().value("words_result");

    for(int i=0;i<jsonFile.object().value("words_result_num").toInt();i++)
    {
        if(res[i].isObject())
        {
//            qDebug()<<"the array is obj";
//            qDebug()<<res[i].toObject().value("words").toString();
            contents+=res[i].toObject().value("words").toString()+"\n";
        }
    }
    this->result=contents;

}

void update()
{
    //更新token
    QUrl dest("https://aip.baidubce.com/oauth/2.0/token");
}


QString Option::getURL()
{
    //到时候用configure生成对应的URL
    QString url="https://aip.baidubce.com/rest/2.0/ocr/v1/general_basic?access_token=";
    url=url+QString::fromStdString(accessToken);
    return url;
}

