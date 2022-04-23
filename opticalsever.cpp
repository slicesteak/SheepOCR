#include "opticalsever.h"
#include<QtNetwork/QNetworkAccessManager>


Option::Option():mode(MODE_ACCURATE_BASIC)
  ,app_id("25882743")
  ,api_key("6rkXHclKC0LKkSsm4GZTlySz")
  ,secret_key("tISesOCtKxrIyjMD5uHpnubxgkhBm6fW")
    ,accessToken("24.ee411a21021406f10e64e7ca6cc84cd8.2592000.1651311561.282335-25882743")
    ,URLProfix("https://aip.baidubce.com/rest/2.0/ocr/v1/")
{

}

Option::~Option(){}


OpticalSever::OpticalSever(QObject * parent):QObject(parent)
{
    manager=new QNetworkAccessManager();
    this->OCR_notice_box = new MyMessageBox();
    
    //通信完成后，自动执行receive 结果
    connect(this->manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(receiveResult()));
    //解除绑定
    //disconnect(this->manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(receiveResult()));
}

OpticalSever::~OpticalSever(){}

void OpticalSever::start()
{
    QFile myfile(this->configOption.path);
    if(myfile.exists())
    {
        scanPic();
        sendRequest();
    }
    else
        infoNotice(IMG_NOT_EXIST);
}

void OpticalSever::scanPic()
{
    QImage img(this->configOption.path);
    QByteArray imageData;
    QBuffer buffer(&imageData);
    img.save(&buffer,"png");    
    this->imgBase64 = QUrl::toPercentEncoding(imageData.toBase64());
    buffer.close();
}

void OpticalSever::setConfig()
{
    //url.setUrl("https://aip.baidubce.com/rest/2.0/ocr/v1/idcard"  + "?access_token=" + accessToken );
}

void OpticalSever::sendRequest()
{
    if(imgBase64.length()>IMG_MAX_SIZE) //图片经过转码后不能超过最大值
    {
        this->infoNotice(IMG_OVER_SIZE);
        return;
    }
    QUrl dest(configOption.getURL());
    qDebug()<<configOption.getURL();
    if(dest.isEmpty())
    {
        this->infoNotice(INVALID_MODE);
        return;
    }
    this->request.setUrl(dest);
//    request.setRawHeader("Content-Type", "application/x-www-form-urlencoded");
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    QByteArray body;
    body.append("image=");
    body.append(imgBase64);
    reply=manager->post(request,body);
    qDebug()<<"成功send(),如果图片较大,需要稍微等一下,我应该加个什么UI提醒的功能";
}

void OpticalSever::receiveResult(){

    qDebug()<<"成功receive()";
    QByteArray data=reply->readAll();
//    qDebug()<<data;

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

void OpticalSever::TokenUpdate()
{
    //更新token
    QUrl dest("https://aip.baidubce.com/oauth/2.0/token");
}


QString Option::getURL()
{
    //到时候用configure生成对应的URL
    QString Mode="";
    switch (mode) {
        case MODE_ACCURATE_BASIC: Mode="accurate_basic";break;
        case MODE_ACCURATE: Mode="accurate";break;
        case MODE_GENERAL_BASIC: Mode="general_basic";break;
        case MODE_GENERAL  :Mode="general";break;
        case MODE_DOC_ANALYSIS_OFFICE: Mode="doc_analysis_office";break;
        case MODE_WEBIMAGE  :Mode="webimage";break;
        case MODE_WEBIMAGE_LOC :Mode="webimage_loc";break;
        case MODE_HANDWRITING  :Mode="handwriting";break;
        case MODE_TABLE  :Mode="table";break;
        case MODE_SEAL :Mode="seal";break;
        case MODE_NUMBERS  :Mode="numbers";break;
        case MODE_QRCODE: Mode="qrcode";break;
    default: return"";
    }
    QString url=URLProfix+Mode+"?access_token="+accessToken;

    return url;
}

void OpticalSever::infoNotice(int error_msg){

    //设置图标，可选值：check（确定）、question（疑问）、warn（警告）、error（报错）
    OCR_notice_box->setIcon("error");
    OCR_notice_box->setButtonText("确定"); //设置单个按钮

    switch (error_msg) {
        case IMG_OVER_SIZE:
            OCR_notice_box->setBodyText("文件体积过大，请重新选择图片"); //设置正文内容
            break;
        case IMG_NOT_EXIST:
            OCR_notice_box->setBodyText("图片"+this->configOption.path+"不存在，请重新选择图片");
            break;
        case INVALID_MODE:
            OCR_notice_box->setBodyText("识别模式设置错误");
            break;
    }

    OCR_notice_box->exec();         //激活弹窗
}

