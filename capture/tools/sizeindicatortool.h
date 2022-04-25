#ifndef SIZEINDICATORTOOL_H
#define SIZEINDICATORTOOL_H
#include "capturetool.h"
class SizeIndicatorTool : public CaptureTool
{
    Q_OBJECT
public:
    explicit SizeIndicatorTool(QObject *parent = nullptr);
    int id() const override;
    bool isSelectable() const override;
    ToolWorkType toolType() const override;
    QString iconName() const override;
    QString name() const override;
    QString description() const override;
    void processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness) override;
    void onPressed() override;
};
#endif













