#ifndef MYSQL_H
#define MYSQL_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class MySql
{
public:
    MySql();
    void initsql(QString ip);
    void createtable();
    QString loguser(QString name,QString passward);
    bool signup(QString name,QString passward);
    QString getinfo(QString name);

private:
    QSqlQuery *query;
};

#endif // MYSQL_H
