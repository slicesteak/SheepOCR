#include "donate.h"
#include "ui_donate.h"

donate::donate(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::donate)
{
    ui->setupUi(this);
    //设置不能改变大小
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);
}

donate::~donate()
{
    delete ui;
}
