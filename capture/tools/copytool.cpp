#include "copytool.h"
#include <QPainter>
CopyTool::CopyTool(QObject *parent) : CaptureTool(parent)
{

}

int CopyTool::id() const
{
    return 0;
}

bool CopyTool::isSelectable() const
{
    return false;
}

QString CopyTool::iconName() const
{
    return ":/Img/Save.png";
}

QString CopyTool::name() const
{
    return "保存截图";
}

QString CopyTool::description() const
{
    return "保存截图";
}

CaptureTool::ToolWorkType CopyTool::toolType() const
{
    return TYPE_WORKER;
}

void CopyTool::processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness)
{
    Q_UNUSED(painter);
    Q_UNUSED(points);
    Q_UNUSED(color);
    Q_UNUSED(thickness);
}

void CopyTool::onPressed()
{
    Q_EMIT requestAction(REQ_TO_CLIPBOARD);
    Q_EMIT requestAction(REQ_CLOSE_GUI);
}














