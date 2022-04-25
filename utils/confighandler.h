#ifndef CONFIGHANDLER_H
#define CONFIGHANDLER_H
#include "capture/widget/capturebutton.h"
#include <QList>
#include <QSettings>
class ConfigHandler
{
public:
    explicit ConfigHandler();
    QList<CaptureButton::ButtonType> getButtons();
	QColor uiMainColorValue();
    QColor uiContrastColorValue();
    QColor drawColorValue();
    int contrastOpacityValue();
private:
    QList<CaptureButton::ButtonType> fromIntToButton(const QList<int> &l);
    QList<int> fromButtonToInt(const QList<CaptureButton::ButtonType> &l);
};
#endif








































