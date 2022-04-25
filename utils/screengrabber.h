#ifndef SCREENGRABBER_H
#define SCREENGRABBER_H
#include "utils/desktopinfo.h"
#include <QObject>
class ScreenGrabber : public QObject
{
    Q_OBJECT
public:
    explicit ScreenGrabber(QObject *parent = nullptr);
    QPixmap grabEntireDesktop(bool &ok);
private:
    DesktopInfo m_info;
};
#endif











































