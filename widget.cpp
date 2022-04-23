#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsDropShadowEffect>
#include<QtDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setProperty("canMove",true);
    this->initUi();
    this->initMember();


    //通信完成后，自动执行getBack
    connect(myOCR.manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getres()));
    //解除绑定
    //disconnect(myOCR.manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(getres()));
}

Widget::~Widget()
{
    delete ui;
}

/**********************************************************初始化函数****************************************************************/

void Widget::initUi()
{
    //初始化窗口边框
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    QGraphicsDropShadowEffect *shadow = new QGraphicsDropShadowEffect(this);
    shadow->setOffset(0, 0);
    shadow->setColor(QColor("#444444"));
    shadow->setBlurRadius(16);
    ui->w_bg->setGraphicsEffect(shadow);
    ui->lay_bg->setMargin(12);

    //Logo
    QPixmap logo(":/icons/logo.png");
    ui->lab_logo->setPixmap(logo);

    //itemLogo
    QPixmap item1(":/icons/item_01.png");
    QPixmap item2(":/icons/item_02.png");
    ui->lab_item_01->setPixmap(item1);
    ui->lab_item_02->setPixmap(item2);


    ui->radioButton->setToolTip("在通用文字识别的基础上，提供更高精度的识别服务，支持更多语种识别（丹麦语、荷兰语、马来语、瑞典语、印尼语、波兰语、罗马尼亚语、土耳其语、希腊语、匈牙利语、泰语、越语、阿拉伯语、印地语及部分中国少数民族语言），并将字库从1w+扩展到2w+，能识别所有常用字和大部分生僻字。");
    ui->radioButton_3->setToolTip("提供多场景、多语种、高精度的整图文字检测和识别服务，支持生僻字识别，并支持 25 种语言识别，\n相对于通用文字识别（含位置信息版）该产品精度更高，但是识别耗时会稍长。");
    ui->radioButton_2->setToolTip("基于业界领先的深度学习技术，提供多场景、多语种、高精度的整图文字检测和识别服务，\n多项ICDAR指标居世界第一。");
    ui->radioButton_4->setToolTip("基于业界领先的深度学习技术，提供多场景、多语种、高精度的整图文字检测和识别服务。\n在通用文字识别的基础上，返回文字在图片中的位置信息，方便用户进行版式的二次处理。");
    ui->radioButton_12->setToolTip("可对办公类文档版面进行分析，输出图、表、标题、文本的位置，并输出分版块内容的OCR识别结果，\n支持中、英两种语言，手写、印刷体混排多种场景。");
    ui->radioButton_11->setToolTip("针对网络图片进行专项优化，\n支持识别艺术字体或背景复杂的文字内容。");
    ui->radioButton_9->setToolTip("支持识别艺术字体或背景复杂的文字内容，除文字信息外，\n还可返回每行文字的位置信息、行置信度，以及单字符内容和位置等。");
    ui->radioButton_10->setToolTip("支持对图片中的手写中文、手写数字进行检测和识别，\n针对不规则的手写字体进行专项优化，识别准确率可达90%以上。");
    ui->radioButton_8->setToolTip("支持识别图片/PDF格式文档中的表格内容，返回各表格的表头表尾内容、\n单元格文字内容及其行列位置信息，全面覆盖各类表格样式，\n包括常规有线表格、无线表格、含合并单元格表格。\n同时，支持多表格内容识别。");
    ui->radioButton_7->setToolTip("对图片中的表格文字内容进行提取和识别，结构化输出表头、表尾及每个单元格的文字内容。\n支持识别常规表格及含合并单元格表格，并可选择以JSON或Excel形式进行返回。");
    ui->radioButton_6->setToolTip("支持识别表格线齐全的常规表格和无框线表格的单元格内容，结构化输出表头、\n表尾及每个单元格的文字内容。 本接口为同步接口，\n相比于异步接口，本接口在请求后会实时返回请求结果。");
    ui->radioButton_5->setToolTip("检测并识别合同文件或常用票据中的印章，输出文字内容、印章位置信息以及相关置信度，\n已支持圆形章、椭圆形章、方形章等常见印章检测与识别。");
    ui->radioButton_13->setToolTip("对图片中的数字进行提取和识别，自动过滤非数字内容，\n仅返回数字内容及其位置信息，识别准确率超过99%。");
    ui->radioButton_14->setToolTip("对图片中的二维码、条形码进行检测和识别，返回存储的文字信息及其位置信息。");
}

void Widget::initMember()
{
    this->myMbox = new MyMessageBox();
    connect(myMbox,SIGNAL(btnchicked(int)),this,SLOT(changeMboxReturn(int)));

    //最小化到托盘
    QIcon icon = QIcon(":/icons/logo.png");//设置最小图标
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(icon);
    trayIcon->setToolTip("Peach"); //提示文字
    //添加托盘列表项(还原与退出)
    returnNormal = new QAction(" Show", this);
    returnNormal->setFont(QFont("Arial", 9));
    returnNormal->setObjectName("returnNormal");
    returnNormal->setIcon(QIcon(":/icons/show.png"));
    quitAction = new QAction(" Quit", this);
    quitAction->setFont(QFont("Arial", 9));
    quitAction->setObjectName("quitAction");
    quitAction->setIcon(QIcon(":/icons/out.png"));
    connect(quitAction, SIGNAL(triggered()), qApp, SLOT(quit()));           //绑定槽函数退出
    connect(returnNormal, SIGNAL(triggered()), this, SLOT(showNormal()));   //绑定槽函数还原界面

    //创建托盘菜单(必须先创建动作，后添加菜单项，还可以加入菜单项图标美化)
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(returnNormal);
    trayIconMenu->addAction(quitAction);
    trayIcon->setContextMenu(trayIconMenu);
}

/**********************************************************自定义函数****************************************************************/

void Widget::littleShow()
{
    this->hide();//隐藏主窗口
    trayIcon->show();//显示托盘

    //显示到系统提示框的信息
    QString title="Peach";
    QString text="正自动在后台运行";
    trayIcon->showMessage(title,text,QSystemTrayIcon::Information,3000); //此参数为提示时长
}

/**********************************************************控件槽函数****************************************************************/

void Widget::closeEvent(QCloseEvent *event)
{
    myMbox->setIcon("question");
    myMbox->setBodyText("How to leave?");
    myMbox->setButtonText("Little","Logout");
    myMbox->exec();
    if(mbox_return == 0) {
        event->ignore();
    }else if(mbox_return == 1){
        event->ignore();
        littleShow();
    }
}

void Widget::changeMboxReturn(int num)
{
    this->mbox_return = num;
}

void Widget::on_btn_main_item_1_clicked()
{
    ui->sw_main->setCurrentIndex(0);
}

void Widget::on_btn_main_item_2_clicked()
{
    ui->sw_main->setCurrentIndex(1);
}

void Widget::on_btn_main_item_3_clicked()
{
    ui->sw_main->setCurrentIndex(2);
}

void Widget::on_btn_main_item_4_clicked()
{
    ui->sw_main->setCurrentIndex(3);
}

void Widget::on_btn_logout_clicked()
{
    close();
}

void Widget::on_btn_littleshow_clicked()
{
    showMinimized();
}

void Widget::on_btn_menu_item_3_clicked()
{

    QString path=ui->picPath->toPlainText();
//    qDebug()<<path;
    QFile myfile(path);
    if(myfile.exists())
    {
        myOCR.scanPic(path);
        myOCR.sendRequest();
    }
    else
    {
        myMbox->setIcon("question");                      //设置图标，可选值：check（确定）、question（疑问）、warn（警告）、error（报错）
        myMbox->setBodyText("文件 "+path+" 不存在，请重新输入路径");            //设置正文内容
        myMbox->setButtonText("确定");                     //设置单个按钮
        myMbox->setButtonText("确定","取消");               //设置两个按钮
        myMbox->exec();                                   //激活弹窗
    }

}

void Widget::getres(){
//    qDebug()<<"QSslSocket="<<QSslSocket::sslLibraryBuildVersionString();
//    qDebug() << "OpenSSL支持情况:" << QSslSocket::supportsSsl();
    myOCR.receiveResult();
    qDebug()<<"get the result"<<myOCR.result;
    ui->lab_mess_1->setText(myOCR.result);
    //myOCR.result.clear();
}

