#ifndef CAPTURECHANGE_H
#define CAPTURECHANGE_H
#include "capture/widget/capturebutton.h"
#include <QObject>
#include <QVector>
class CaptureButton;
class QPoint;
class CaptureModification : public QObject
{
    Q_OBJECT
public:
    CaptureModification(QObject *parent = nullptr) = delete;
    CaptureModification(const CaptureButton::ButtonType, const QPoint &initialPoint, const QColor &color, const int thickness, QObject *parent = nullptr);
    QColor color() const;
    QVector<QPoint> points() const;
    CaptureTool* tool() const;
    int thickness() const;
    CaptureButton::ButtonType buttonType() const;
    void addPoint(const QPoint);
protected:
    QColor m_color;
    CaptureButton::ButtonType m_type;
    QVector<QPoint> m_coords;
    CaptureTool *m_tool;
    int m_thickness;
};
#endif



















































