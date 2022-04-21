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
    img.save(&buffer,"png");   //为什么删掉就跑不了？？
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
//    body.append(imgBase64);
    //qDebug()<<QUrl::toPercentEncoding(imgBase64);

    reply=manager->post(request,body);//




//    QHttpMultiPart *mulPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);

//    QHttpPart part1;
//    part1.setRawHeader("Content-Type","application/x-www-form-urlencoded");
//    part1.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data;name=\"%1\"").arg("image")));
//    part1.setBody(QUrl::toPercentEncoding(imgBase64));

//    QHttpPart part2;
//    part2.setRawHeader("Content-Type","application/x-www-form-urlencoded");
//    part2.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant(QString("form-data;name=\"%1\"").arg("id_card_side")));
//    part2.setBody("front");

//    mulPart->append(part1);
////    mulPart->append(part2);

//    //发送数据
//    reply = manager->post(this->request, mulPart);
//    mulPart->setParent(reply);

    qDebug()<<"成功send()";
}

QString OpticalSever::receiveResult(){

    qDebug()<<"成功receive()";
    QByteArray data=reply->readAll();
//    qDebug()<<data;

    //Json数据解析
//    QJsonDocument document = QJsonDocument::fromJson(data);
//    if( !document.isNull() )
//    {
//        QString result="";
//        QJsonObject jsonObject = document.object();
//        QJsonObject jsonObject1 = jsonObject.value(QString("words_result")).toObject();
//        QJsonObject::const_iterator it = jsonObject1.constBegin();
//        QJsonObject::const_iterator end = jsonObject1.constEnd();
//        while (it != end) {
//            QString key = it.key();qDebug()<<key <<endl;
//            QString value = it.value().toObject().value("words").toString();qDebug()<<value <<endl;
//            QString pair = key + ": " + value + "\n";qDebug()<<pair <<endl;
//            result += pair;
//            it++;
//        }
//        return result;
//    }
//    return "null";
/////////////////



//    QString path;
//    QJsonDocument document;
//    QFile myfile(path);
//    myfile.open(QIODevice::ReadOnly | QIODevice::Text);
    QJsonDocument jsonFile=QJsonDocument::fromJson(data);
    QJsonValue value;
    QString contents;
    QJsonValue res= jsonFile.object().value("words_result");
    if(res.isObject())
        qDebug()<<"is obj";
    else if(res.isArray())
        qDebug()<<"is array";
    for(int i=0;i<jsonFile.object().value("words_result_num").toInt();i++)
    {
        if(res[i].isObject())
        {
            qDebug()<<"the array is obj";
            qDebug()<<res[i].toObject().value("words").toString();
            contents+=res[i].toObject().value("words").toString()+"\n";
        }
    }
    this->result=contents;
    return contents;

}

void update()
{
    QUrl dest("https://aip.baidubce.com/oauth/2.0/token");
}


QString Option::getURL()
{//到时候用configure生成对应的URL
    QString url="https://aip.baidubce.com/rest/2.0/ocr/v1/general_basic?access_token=";
    url=url+QString::fromStdString(accessToken);
    return url;
}

