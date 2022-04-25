#ifndef CAPTURETOOL_H
#define CAPTURETOOL_H
#include <QObject>
#include <QVector>
class QPainter;
class CaptureTool : public QObject
{
    Q_OBJECT
public:
    enum ToolWorkType
    {
        TYPE_WORKER,
        TYPE_PATH_DRAWER,
        TYPE_LINE_DRAWER
    };
    enum Request
    {
        REQ_CLOSE_GUI,
        REQ_HIDE_GUI,
        REQ_HIDE_SELECTION,
        REQ_UNDO_MODIFICATION,
        REQ_CLEAR_MODIFICATIONS,
        REQ_SAVE_SCREENSHOT,
        REQ_SELECT_ALL,
        REQ_TO_CLIPBOARD,
        REQ_UPLOAD_TO_IMGUR,
        REQ_MOVE_MODE,
        REQ_OPEN_APP,
    };
    explicit CaptureTool(QObject *parent = nullptr);
    virtual int id() const = 0;
    virtual bool isSelectable() const = 0;
    virtual ToolWorkType toolType() const = 0;
    virtual QString iconName() const = 0;
    virtual QString name() const = 0;
    virtual QString description() const = 0;
    virtual void processImage(QPainter &painter, const QVector<QPoint> &points, const QColor &color, const int thickness) = 0;
signals:
    void requestAction(Request r);    
public slots:
    virtual void onPressed() = 0;
};
#endif


























