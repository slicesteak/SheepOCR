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

