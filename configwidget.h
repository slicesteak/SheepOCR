#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QDialog>
#include "modifywidget.h"

namespace Ui {
class ConfigWidget;
}

class ConfigWidget : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigWidget(QWidget *parent = nullptr,QString Username=0,QString ID=0,QString APIK=0,QString SK=0,QString Token=0);
    ~ConfigWidget();

private slots:
    void on_confirmBtn_clicked();


private:
    QString username;
    QString app_id;
    QString api_key;
    QString secret_key;
    QString accessToken;
    Ui::ConfigWidget *ui;
    ModifyWidget* mw;
    void initUi();
};

#endif // CONFIGWIDGET_H
