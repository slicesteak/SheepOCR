#include "suspendball.h"
#include "ui_widget.h"

#include <suspendball.h>
#include "widget.h"
#include "ui_suspendball.h"

#include<QDesktopServices>
#include<QUrl>
#include <QWidget>
#include<QMessageBox>
#include<QtDebug>
#include<QBuffer>
#include<QObject>
#include<QPushButton>



suspendball::suspendball(QWidget *parent) :
    QWidget(parent,Qt::FramelessWindowHint),
    ui(new Ui::suspendball)
{
    ui->setupUi(this);


    // 置顶
    this->setWindowOpacity(1);
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground, true);
    //this->setWindowModality(Qt::ApplicationModal);


    ////    样式
    //    const QString m_ball_SheetStyle = "min-width: 28px; min-height: 28px;"
    //                                       "max-width: 28px; max-height: 28px;"
    //                                       "border-radius: 8px; border: 1px;"
    //                                       "solid black; background: red";
    ////    样式添加到lable中
    //    ui->label->setStyleSheet(m_ball_SheetStyle);

    QPixmap *pixw;
     pixw = new QPixmap(ui->label->size());
      pixw->load(":/icons/sheep.png");
      ui->label->setPixmap(*pixw);
//     ui->label->setStyleSheet("background-image:url(:/icons/logo.png");

     act_Menu =new QMenu(this);
     act_show=new QAction("显示主窗口",this);
    act_show->setFont(QFont("Arial", 9));
     act_show->setObjectName("returnNormal");
     act_show->setIcon(QIcon(":/icons/logo.png"));
     act_jietu=new QAction("截图",this);
     act_delete=new QAction("退出",this);
     act_delete->setIcon(QIcon(":/icons/out.png"));


     connect(act_show, &QAction::triggered,this,[=](){
         qDebug()<<"发送信号";
         emit showwidget();
         this->close();
 connect(act_show, SIGNAL(triggered(bool)), this, SLOT(showNormal(bool)));

        });
     connect(act_jietu, &QAction::triggered,this,[=](){
        emit CallSreenShot();
        });
     connect(act_delete, &QAction::triggered,this,[=](){
           connect(act_delete, SIGNAL(triggered()), qApp, SLOT(quit()));
           qApp->quit();

        });
     act_Menu->addAction(act_show);
     act_Menu->addAction(act_jietu);
     act_Menu->addAction(act_delete);

}


suspendball::~suspendball()
{
    delete ui;
}


void suspendball::showNormal(bool)
{
    qDebug()<<"发送信号";
    emit showwidget();
}
void suspendball::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        relativePos = this->pos() - event->globalPos();
    }
    if(event->button() == Qt::MidButton) {      // 鼠标中间键点击（点击滚轮）

    }
    if(event->button() == Qt::RightButton) {
//         QDesktopServices::openUrl(QUrl("file:///C:/Users/24110/Desktop/刘觉明.jpg", QUrl::TolerantMode));
        act_Menu->exec(QCursor::pos());
            event->accept();
    }
}

// 鼠标移动
void suspendball::mouseMoveEvent(QMouseEvent *event)
{
  // 让小球跟着鼠标走
    this->move(event->globalPos() + relativePos);
    this->show();
}


//双击
void suspendball::mouseDoubleClickEvent(QMouseEvent *event)
{
    //发出信号,显示截图窗口
    emit CallSreenShot();
}
