#include "buttonhandler.h"

#include <QPoint>
#include <QDebug>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
namespace {
    const int SEPARATION = 6;
}

ButtonHandler::ButtonHandler(const QRect &limits, QObject *parent) :
    QObject(parent), m_limits(limits)
{
	
}

void ButtonHandler::hide() {
	m_btnWidget->hide();
}

void ButtonHandler::show() {
	m_btnWidget->show();
}

bool ButtonHandler::isVisible() const {
	return m_btnWidget->isVisible();
}

size_t ButtonHandler::size() const {
    return m_vectorButtons.size();
}

void ButtonHandler::updatePosition(const QRect &selection) {
    const int vecLength = m_vectorButtons.size();
    if (vecLength == 0) {
        return;
    }
    m_selection = selection;
	
	QPoint btnWidgetPoint;
	QPoint colorWidgetPoint;
	QRect deskrect = qApp->desktop()->screenGeometry(0);
	if (selection.bottom() + getToolSpacePosition() >= deskrect.bottom() && selection.top() < getToolSpacePosition())
	{
		int btnWidgetPointX = selection.topRight().x() - m_btnWidget->width();
		btnWidgetPointX = btnWidgetPointX < 0 ? 0 : btnWidgetPointX;
		btnWidgetPoint.setX(btnWidgetPointX);
		btnWidgetPoint.setY(0);

		colorWidgetPoint.setX(btnWidgetPointX);
		colorWidgetPoint.setY(btnWidgetPoint.y() + 38);
	}
	else if (selection.bottom() + getToolSpacePosition() >= deskrect.bottom())
	{
		int btnWidgetPointX = selection.topRight().x() - m_btnWidget->width();
		btnWidgetPointX = btnWidgetPointX < 0 ? 0 : btnWidgetPointX;
		btnWidgetPoint.setX(btnWidgetPointX);
		btnWidgetPoint.setY(selection.top() - getToolSpacePosition());

		colorWidgetPoint.setX(btnWidgetPointX);
		colorWidgetPoint.setY(btnWidgetPoint.y() + 38);
	}
	else
	{
		int btnWidgetPointX = selection.bottomRight().x() - m_btnWidget->width();
		btnWidgetPointX = btnWidgetPointX < 0 ? 0 : btnWidgetPointX;
		btnWidgetPoint.setX(btnWidgetPointX);
		btnWidgetPoint.setY(selection.bottom() + 12);

		colorWidgetPoint.setX(btnWidgetPointX);
		colorWidgetPoint.setY(btnWidgetPoint.y() + 38);
	}
	m_btnWidget->move(btnWidgetPoint);
}

// setButtons redefines the buttons of the button handler
void ButtonHandler::setButtons(QWidget* parent, const QVector<CaptureButton *> v) {
    if (v.isEmpty())
        return;

    for (CaptureButton *b: m_vectorButtons)
        delete(b);

	m_btnWidget = parent;
    m_vectorButtons = v;
    m_buttonBaseSize = v[0]->buttonBaseSize();
    m_buttonExtendedSize = m_buttonBaseSize + SEPARATION;
}


int ButtonHandler::getToolSpacePosition()
{
        return 44;
}
