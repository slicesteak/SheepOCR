#ifndef HELPINFO_H
#define HELPINFO_H

#include <QMainWindow>

namespace Ui {
class helpinfo;
}

class helpinfo : public QMainWindow
{
    Q_OBJECT

public:
    explicit helpinfo(QWidget *parent = nullptr);
    ~helpinfo();

private:
    Ui::helpinfo *ui;
};

#endif // HELPINFO_H
