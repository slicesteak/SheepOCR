#ifndef MARKERTOOL_H
#define MARKERTOOL_H
#include "capturetool.h"
class MarkerTool : public CaptureTool
{
    Q_OBJECT
public:
    explicit MarkerTool(QObject *parent = nullptr);
    int id() const override;
    bool isSelectable() const override;
    ToolWorkType toolType() const override;
    QString iconName() const override;
    QString name() const override;
    QString description() const override;
    void processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness) override;
    void onPressed() override;
private:
    bool needsAdjustment(const QPoint &p0, const QPoint &p1) const;
};
#endif












