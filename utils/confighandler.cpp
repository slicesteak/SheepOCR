#include "confighandler.h"
#include <algorithm>
#include <QFile>
#include <QDir>
#include <QCoreApplication>

ConfigHandler::ConfigHandler(){
   
}

QList<CaptureButton::ButtonType> ConfigHandler::getButtons() {
    QList<CaptureButton::ButtonType> buttons = CaptureButton::getIterableButtonTypes().toList();
    return buttons;
}

QColor ConfigHandler::uiMainColorValue() {
	QColor res = QColor(0, 122, 204);
    return res;
}

QColor ConfigHandler::uiContrastColorValue() {
    QColor res = QColor(0, 122, 204);
    return res;
}

QColor ConfigHandler::drawColorValue() {
    QColor res(Qt::red);
    return res;
}

int ConfigHandler::contrastOpacityValue() {
	int opacity = 180;
    return opacity;
}

QList<CaptureButton::ButtonType> ConfigHandler::fromIntToButton(
        const QList<int> &l)
{
    QList<CaptureButton::ButtonType> buttons;
    for (auto const i: l)
        buttons << static_cast<CaptureButton::ButtonType>(i);
    return buttons;
}

QList<int> ConfigHandler::fromButtonToInt(
        const QList<CaptureButton::ButtonType> &l)
{
    QList<int> buttons;
    for (auto const i: l)
        buttons << static_cast<int>(i);
    return buttons;
}
