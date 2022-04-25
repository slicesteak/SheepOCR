#include "capture/screenshot.h"
#include "capture/widget/capturebutton.h"
#include "capturemodification.h"
#include "capture/tools/capturetool.h"
#include "utils/confighandler.h"
#include <QMessageBox>
#include <QImageWriter>
#include <QFileDialog>
#include <QPainter>
#include <QBuffer>
#include <QUrlQuery>
Screenshot::Screenshot(const QPixmap &p, QObject *parent) : QObject(parent),
    m_baseScreenshot(p),
    m_modifiedScreenshot(p)
{

}

Screenshot::~Screenshot() {
}

void Screenshot::setScreenshot(const QPixmap &p) {
    m_baseScreenshot = p;
    m_modifiedScreenshot = p;
}
QPixmap Screenshot::baseScreenshot() const {
    return m_baseScreenshot;
}

QPixmap Screenshot::screenshot() const {
    return m_modifiedScreenshot;
}

QPixmap Screenshot::croppedScreenshot(const QRect &selection) const {
    return m_modifiedScreenshot.copy(selection);
}

// paintModification adds a new modification to the screenshot
QPixmap Screenshot::paintModification(const CaptureModification *modification) {
    QPainter painter(&m_modifiedScreenshot);
    painter.setRenderHint(QPainter::Antialiasing);
    paintInPainter(painter, modification);
    return m_modifiedScreenshot;
}

// paintTemporalModification paints a modification without updating the
// member pixmap
QPixmap Screenshot::paintTemporalModification(
        const CaptureModification *modification)
{
    QPixmap tempPix(m_modifiedScreenshot);
    QPainter painter(&tempPix);
//    if (modification->buttonType() != CaptureButton::TYPE_PENCIL) {
//        painter.setRenderHint(QPainter::Antialiasing);
//    }
    paintInPainter(painter, modification);
    return tempPix;
}

// paintBaseModifications overrides the modifications of the screenshot
// with new ones.
QPixmap Screenshot::overrideModifications(
        const QVector<CaptureModification*> &m)
{
    m_modifiedScreenshot = m_baseScreenshot;
    for (const CaptureModification *const modification: m) {
        paintModification(modification);
    }
    return m_modifiedScreenshot;
}

// paintInPainter is an aux method to prevent duplicated code, it draws the
// passed modification to the painter.
void Screenshot::paintInPainter(QPainter &painter,
                                const CaptureModification *modification)
{
    const QVector<QPoint> &points = modification->points();
    QColor color = modification->color();
    int thickness = modification->thickness();
    modification->tool()->processImage(painter, points, color, thickness);
}


