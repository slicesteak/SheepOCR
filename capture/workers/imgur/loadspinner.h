#ifndef LOADSPINNER_H
#define LOADSPINNER_H
#include <QWidget>
class LoadSpinner : public QWidget
{
    Q_OBJECT
public:
    explicit LoadSpinner(QWidget *parent = nullptr);
    void setColor(const QColor &c);
    void setWidth(int w);
    void setHeight(int h);
    void start();
    void stop();
protected:
    void paintEvent(QPaintEvent *);
private slots:
    void rotate();
private:
    QColor m_color;
    QTimer *m_timer;
    int m_startAngle = 0;
    int m_span =180;
    bool m_growing;
    QRect  m_frame;
    void updateFrame();
};
#endif

























