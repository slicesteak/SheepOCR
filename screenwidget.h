#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>
#include <QMenu>
#include <QPoint>
#include <QSize>
#include <QMouseEvent>
//截屏对象类
class Screen
{
public:
    enum STATUS {SELECT, MOV, SET_W_H};
    Screen() {}
    Screen(QSize size);

    void setStart(QPoint pos);
    void setEnd(QPoint pos);
    QPoint getStart();
    QPoint getEnd();

    QPoint getLeftUp();
    QPoint getRightDown();

    STATUS getStatus();
    void setStatus(STATUS status);

    int width();
    int height();
    bool isInArea(QPoint pos);          // 检测pos是否在截图区域内
    void move(QPoint p);                // 按 p 移动截图区域

private:
    QPoint leftUpPos, rightDownPos;     //记录 截图区域 左上角、右下角
    QPoint startPos, endPos;            //记录 鼠标开始位置、结束位置
    int maxWidth, maxHeight;            //记录屏幕大小
    STATUS status;                      //三个状态: 选择区域、移动区域、设置width height

    void cmpPoint(QPoint &s, QPoint &e);//比较两位置，判断左上角、右下角
};

//截屏窗口类
class ScreenWidget : public QWidget
{
    Q_OBJECT
public:
    static ScreenWidget *Instance();
    explicit ScreenWidget(QWidget *parent = 0);

private:
    static QScopedPointer<ScreenWidget> self;
    QMenu *menu;            //右键菜单对象
    Screen *screen;         //截屏对象
    QPixmap *fullScreen;    //保存全屏图像
    QPixmap *bgScreen;      //模糊背景图
    QPoint movPos;          //坐标

protected:
    void contextMenuEvent(QContextMenuEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    void showEvent(QShowEvent *);



signals:
    void myclose();//完成截图信号
    void CancelScreenShot();//取消截图信号
    void usethisPath();//当使用当前截图时，发送自动设置路径信号
private slots:
    void usethis();//使用当前截图
    void saveScreen();//保存当前截图
    void saveFullScreen();//保存全屏
    void saveScreenOther();//截图另存为
    void saveFullOther();//全屏截图另存为
    void ScreenShotHide();//取消截图
};
#endif // SCREENWIDGET_H
