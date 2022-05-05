#ifndef MODIFYWIDGET_H
#define MODIFYWIDGET_H

#include <QDialog>
#include"tcpclient.h"

namespace Ui {
class ModifyWidget;
}

class ModifyWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ModifyWidget(QWidget *parent = nullptr,QString Username=0,QString ID=0,QString APIK=0,QString SK=0,QString Token=0);
    ~ModifyWidget();

private slots:
    void on_confirmBtn_clicked();

private:
    QString username;
    QString app_id;
    QString api_key;
    QString secret_key;
    QString accessToken;
    Ui::ModifyWidget *ui;
    void initUi();
    TcpClient client;
};

#endif // MODIFYWIDGET_H
