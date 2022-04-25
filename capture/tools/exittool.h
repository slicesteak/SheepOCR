#ifndef EXITTOOL_H
#define EXITTOOL_H
#include "capturetool.h"
class ExitTool : public CaptureTool
{
    Q_OBJECT
public:
    explicit ExitTool(QObject *parent = nullptr);
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


















