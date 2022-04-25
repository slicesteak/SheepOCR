#ifndef CAPTUREWIDGET_H
#define CAPTUREWIDGET_H
#include "capture/widget/capturebutton.h"
#include "capture/tools/capturetool.h"
#include "utils/confighandler.h"
#include "capture/widget/buttonhandler.h"
#include <QWidget>
#include <QPointer>
class AmplifierWidget;
class QPaintEvent;
class QResizeEvent;
class QMouseEvent;
class CaptureModification;
class QNetworkAccessManager;
class QNetworkReply;
class QColorPicker;
class Screenshot;
class CaptureWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CaptureWidget(QWidget *parent = nullptr);
	~CaptureWidget();
	void updateButtons();
	QPixmap pixmap();
signals:
	void capturePixmap(const QPixmap& pixmap); 
private slots:
	void copyScreenshot();
	void saveScreenshot();
	void uploadToImgur();
	void openWithProgram();
	bool undo();
	void leftResize();
	void rightResize();
	void upResize();
	void downResize();
	void setState(CaptureButton *);
	void handleButtonSignal(CaptureTool::Request r);
protected:
	void paintEvent(QPaintEvent *);
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);
	void keyPressEvent(QKeyEvent *);
	Screenshot* m_screenshot;
	QPoint m_dragStartPoint;
	QPoint m_mousePos;
	QRect *m_mouseOverHandle;
	QRect m_selection;
	QRect m_selectionBeforeDrag;
	bool m_mouseIsClicked;
	bool m_rightClick;
	bool m_newSelection;
	bool m_grabbing;
	bool m_toolIsForDrawing;
	int m_opacity;
	uint m_id;
	QRect m_TLHandle, m_TRHandle, m_BLHandle, m_BRHandle;
	QRect m_LHandle, m_THandle, m_RHandle, m_BHandle;
	QRect m_LSide, m_TSide, m_RSide, m_BSide;
	QVector<QRect*> m_handles;
	QVector<QRect*> m_sides;
private:
	void updateHandles();
	void updateSizeIndicator();
	void updateCursor();
	QRect extendedSelection() const;
	QVector<CaptureModification*> m_modifications;
	QPointer<CaptureButton> m_sizeIndButton;
	QPointer<CaptureButton> m_lastPressedButton;
	CaptureButton::ButtonType m_state;
	ButtonHandler *m_buttonHandler;
	QColor m_uiColor;
	QColor m_contrastUiColor;
	ConfigHandler m_config;
	AmplifierWidget* m_amplifierWidget;
};
#endif























