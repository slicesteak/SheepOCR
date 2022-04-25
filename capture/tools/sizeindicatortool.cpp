#include "sizeindicatortool.h"
#include <QPainter>

SizeIndicatorTool::SizeIndicatorTool(QObject *parent) : CaptureTool(parent) {

}

int SizeIndicatorTool::id() const {
    return 0;
}

bool SizeIndicatorTool::isSelectable() const {
    return false;
}

QString SizeIndicatorTool::iconName() const {
    return QString();
}

QString SizeIndicatorTool::name() const {
    return tr("Selection Size Indicator");
}

QString SizeIndicatorTool::description() const {
    return "Shows the dimensions of the selection (X Y)";
}

CaptureTool::ToolWorkType SizeIndicatorTool::toolType() const {
    return TYPE_WORKER;
}

void SizeIndicatorTool::processImage(
        QPainter &painter,
        const QVector<QPoint> &points,
        const QColor &color,
        const int thickness)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
    Q_UNUSED(thickness);
}

void SizeIndicatorTool::onPressed() {
}
