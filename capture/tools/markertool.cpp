#include "markertool.h"
#include <QPainter>

#define ADJ_VALUE 14

MarkerTool::MarkerTool(QObject *parent) : CaptureTool(parent) {

}

int MarkerTool::id() const {
    return 0;
}

bool MarkerTool::isSelectable() const {
    return true;
}

QString MarkerTool::iconName() const {
    return ":/Img/marker.png";
}

QString MarkerTool::name() const {
    return tr("Marker");
}

QString MarkerTool::description() const
{
    return "Sets the Marker as the paint tool";
}

CaptureTool::ToolWorkType MarkerTool::toolType() const
{
    return TYPE_LINE_DRAWER;
}

void MarkerTool::processImage(
        QPainter &painter,
        const QVector<QPoint> &points,
        const QColor &color,
        const int thickness)
{
    QPoint p0 = points[0];
    QPoint p1 = points[1];
    if (needsAdjustment(p0, p1)) {
        p1.setY(p0.y());
    }
    painter.setOpacity(0.35);
    painter.setPen(QPen(color, 14 + thickness));
    painter.drawLine(p0, p1);
    painter.setOpacity(1);
}

void MarkerTool::onPressed() {
}

bool MarkerTool::needsAdjustment(const QPoint &p0, const QPoint &p1) const {
    return (p1.y() >= p0.y() - ADJ_VALUE) && (p1.y() <= p0.y() + ADJ_VALUE);
}
