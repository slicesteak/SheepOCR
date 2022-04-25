#include "savetool.h"
#include <QPainter>
SaveTool::SaveTool(QObject *parent) : CaptureTool(parent)
{

}

int SaveTool::id() const
{
    return 0;
}

bool SaveTool::isSelectable() const
{
    return false;
}

QString SaveTool::iconName() const
{
    return ":/Img/Finish.png";
}

QString SaveTool::name() const
{
    return "完成截图";
}

QString SaveTool::description() const
{
    return "完成截图";
}

CaptureTool::ToolWorkType SaveTool::toolType() const
{
    return TYPE_WORKER;
}

void SaveTool::processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
    Q_UNUSED(thickness);
}

void SaveTool::onPressed()
{
    Q_EMIT requestAction(REQ_SAVE_SCREENSHOT);
}
















