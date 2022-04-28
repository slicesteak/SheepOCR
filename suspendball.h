#ifndef SUSPENDBALL_H
#define SUSPENDBALL_H

#include<QWidget>
#include<QMouseEvent>
#include<QPoint>
#include <QMenu>
#include<QAction>
#include <QMouseEvent>
#include <QVector>

namespace Ui {
class suspendball;
}

class suspendball : public QWidget
{
    Q_OBJECT

public:
    explicit suspendball(QWidget *parent = 0);
    ~suspendball();
    QMenu *pMenu;

public slots:
 void showNormal(bool);
protected:
    void mousePressEvent(QMouseEvent *event);//鼠标点击
    void mouseMoveEvent(QMouseEvent *event);//鼠标移动
    void mouseDoubleClickEvent(QMouseEvent *event);//双击函数
    void jietu();//
    void showListMenu(const QPoint& point);//右键菜单栏

    QAction *act_show;
    QAction *act_jietu;
    QAction *act_delete;
    QMenu *act_Menu;

signals:
     void showwidget();//显示主窗口信号
     void CallSreenShot();//呼叫截图信号

private:
    Ui::suspendball *ui;
    QPoint relativePos;//当前位置
    QRect _mainWindowRect;//父窗口举行
};

#endif // SUSPENDBALL_H
