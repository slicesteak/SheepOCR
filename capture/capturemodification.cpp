#include "capture/tools/capturetool.h"
#include "capturemodification.h"
#include "capture/tools/toolfactory.h"
#include "capture/tools/capturetool.h"
#include <QColor>

CaptureModification::CaptureModification(
        const CaptureButton::ButtonType t,
        const QPoint &p,
        const QColor &c,
        const int thickness,
        QObject *parent) :
    QObject(parent),
    m_color(c),
    m_type(t),
    m_thickness(thickness)
{
    m_tool = ToolFactory().CreateTool(t, this);
    m_coords.append(p);
    if (m_tool->isSelectable()) {
        m_coords.append(p);
    }
}

CaptureButton::ButtonType CaptureModification::buttonType() const {
    return m_type;
}

QColor CaptureModification::color() const {
    return m_color;
}

QVector<QPoint> CaptureModification::points() const {
    return m_coords;
}

CaptureTool* CaptureModification::tool() const{
    return m_tool;
}

int CaptureModification::thickness() const {
    return m_thickness;
}

void CaptureModification::addPoint(const QPoint p) {
    if (m_tool->toolType() == CaptureTool::TYPE_LINE_DRAWER) {
        m_coords[1] = p;
    } else {
        m_coords.append(p);
    }
}





