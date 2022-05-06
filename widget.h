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

#include"helpinfo.h"
#include"donate.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0,QString UName=0,QString app_id=0,QString api_key=0,QString secret_key=0,QString token=0,int guest_flag=1);
    explicit Widget(QWidget *parent = 0,QString UName=0,int guest_flag=1);
    ~Widget();
    enum STATUS {W,B};//枚举记录两种状态{主窗体，悬浮球}
    STATUS status;

private slots:
    void closeEvent(QCloseEvent *event);

    void changeMboxReturn(int num);

    void on_btn_main_item_1_clicked();

    void on_btn_main_item_2_clicked();

    void on_btn_main_item_3_clicked();

    void on_btn_main_item_4_clicked();

    void on_btn_logout_clicked();

    void on_btn_littleshow_clicked();

     void on_btn_menu_item_1_clicked();

    void on_btn_menu_item_3_clicked();

    void on_btn_menu_item_6_clicked();

    void on_btn_menu_item_4_clicked();

    void slot_changebacktoselectmode();

    void on_btn_mine_clicked();

    void ScreenShotShow();//显示截图窗口(隐藏悬浮球)

    void myshow();//显示主窗口(隐藏悬浮球)

    void setPath();//设置截图路径

    void ReactToCancelScreenShot();//取消截图后的显示恢复(根据状态status是主窗口W还是悬浮球B恢复原来界面)

    void on_btn_menu_item_2_clicked();


    void on_btn_menu_item_5_clicked();

private:
    Ui::Widget *ui;

    void update();

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


    OpticalSever* myOCR;

    ConfigWidget* cw;

    suspendball *ball;// 浮动小球

    ScreenWidget *myscreenwidget; //截图模块

    int guest_flag;//是否登录的标记，1为未登录

    QString  UName;//用户名
    QString app_id;
    QString api_key;
    QString secret_key;
    QString accessToken;


    helpinfo *helpinfowidget;
    donate *donatewidget;
};

#endif // WIDGET_H
