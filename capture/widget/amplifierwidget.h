#ifndef AMPLIFIERWIDGET_H
#define AMPLIFIERWIDGET_H
#include <QWidget>
#include "ui_amplifierwidget.h"
class AmplifierWidget : public QWidget
{
	Q_OBJECT

public:
	AmplifierWidget(QWidget *parent = 0);
	~AmplifierWidget();

public:
	void setAmplifierWidgetPixmap(const QPixmap& pixmap, QRect selection);

private:
	void paintEvent(QPaintEvent *event);

private:
	Ui::AmplifierWidget ui;
	QPixmap m_pixmap;
	QRect m_selection;
};

#endif





















