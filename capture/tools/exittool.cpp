#include "exittool.h"
#include <QPainter>
ExitTool::ExitTool(QObject *parent) : CaptureTool(parent)
{

}

int ExitTool::id() const
{
    return 0;
}

bool ExitTool::isSelectable() const
{
    return false;
}

QString ExitTool::iconName() const
{
    return ":/Img/Exit.png";
}

QString ExitTool::name() const
{
    return "退出截图";
}

QString ExitTool::description() const
{
    return "退出截图";
}

CaptureTool::ToolWorkType ExitTool::toolType() const
{
    return TYPE_WORKER;
}

void ExitTool::processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
    Q_UNUSED(thickness);
}

void ExitTool::onPressed()
{
    Q_EMIT requestAction(REQ_CLOSE_GUI);
}










