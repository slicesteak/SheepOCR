#ifndef TOOLFACTORY_H
#define TOOLFACTORY_H
#include <QObject>
#include "capture/widget/capturebutton.h"
#include "capture/tools/capturetool.h"
class CaptureTool;
class ToolFactory : public QObject
{
    Q_OBJECT
public:
    enum ToolType
    {
    };
    explicit ToolFactory(QObject *parent = nullptr);
    ToolFactory(const ToolFactory &) = delete;
    ToolFactory & operator=(const ToolFactory &) = delete;
    CaptureTool* CreateTool(CaptureButton::ButtonType t, QObject *parent = nullptr);
};
#endif


































