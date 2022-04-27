#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
//最小化相关
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include <QMenu>
#include <QAction>
#include"opticalsever.h"
//自定义弹窗
#include "mymessagebox.h"
#include "opticalsever.h"
#include "screenwidget.h"
#include "configwidget.h"
#include "modifywidget.h"
#include<suspendball.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString UName=0);
    QString  UName;//用户名
    ~Widget();
     suspendball *ball;// 浮动小球
    ScreenWidget *myscreenwidget; //截图模块

private slots:
    void closeEvent(QCloseEvent *event);

    void changeMboxReturn(int num);

    void on_btn_main_item_1_clicked();

    void on_btn_main_item_2_clicked();

    void on_btn_main_item_3_clicked();

    void on_btn_main_item_4_clicked();

    void on_btn_logout_clicked();

    void on_btn_littleshow_clicked();

    void on_btn_menu_item_3_clicked();

    void on_btn_menu_item_6_clicked();

    //void receiveData(QString data);   //接收传递过来的数据的槽

private:
    Ui::Widget *ui;

    MyMessageBox *myMbox;
    //自定义窗口通信参数
    int mbox_return;

    //最小化到托盘
    QSystemTrayIcon *trayIcon;
    QMenu *trayIconMenu;
    //窗口管理动作
    QAction *returnNormal;
    QAction *quitAction;

    void initUi();          //Ui界面初始化函数
    void initMember();      //成员变量初始化函数
    void littleShow();      //最小化显示函数


    OpticalSever myOCR;

    ConfigWidget* cw;

private slots:
    void slot_changebacktoselectmode();

    void on_btn_mine_clicked();

    void myshow();
};

#endif // WIDGET_H
