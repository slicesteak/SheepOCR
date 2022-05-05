#ifndef DONATE_H
#define DONATE_H

#include <QMainWindow>

namespace Ui {
class donate;
}

class donate : public QMainWindow
{
    Q_OBJECT

public:
    explicit donate(QWidget *parent = nullptr);
    ~donate();

private:
    Ui::donate *ui;
};

#endif // DONATE_H
