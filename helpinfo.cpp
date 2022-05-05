#include "helpinfo.h"
#include "ui_helpinfo.h"

helpinfo::helpinfo(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::helpinfo)
{
    ui->setupUi(this);
    //设置不能改变大小
    setWindowFlags(Qt::MSWindowsFixedSizeDialogHint);

}

helpinfo::~helpinfo()
{
    delete ui;
}
