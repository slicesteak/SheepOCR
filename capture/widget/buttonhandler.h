#ifndef BUTTONHANDLER_H
#define BUTTONHANDLER_H
#include "capturebutton.h"
#include <QVector>
#include <QObject>
class CaptureButton;
class QRect;
class QPoint;

class ButtonHandler : public QObject
{
    Q_OBJECT
public:
    ButtonHandler(const QRect &limits, QObject *parent = nullptr);
    void hideSectionUnderMouse(const QPoint &p);
    bool isVisible() const;
    bool buttonsAreInside() const;
    size_t size() const;
    void updatePosition(const QRect &selection);
    void setButtons(QWidget* parent, const QVector<CaptureButton*>);

public slots:
    void hide();
    void show();

private:
	int getToolSpacePosition();  
private:
	QWidget* m_btnWidget;
    QVector<CaptureButton*> m_vectorButtons;
    int m_buttonExtendedSize;
    int m_buttonBaseSize;
    bool m_buttonsAreInside;
    bool m_blockedRight;
    bool m_blockedLeft;
    bool m_blockedBotton;
    bool m_blockedTop;
    bool m_oneHorizontalBlocked;
    bool m_horizontalyBlocked;
    bool m_allSidesBlocked;
    QRect m_limits;
    QRect m_selection;
};
#endif





















