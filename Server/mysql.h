#ifndef MYSQL_H
#define MYSQL_H

#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QMessageBox>

class MySql
{
public:
    MySql();
    void initsql(QString ip,QString password);
    void createtable();
    bool ExecuteSql(QString strSQL);//执行不返回数据集的SQL语句
    QString ExecuteSqlEx(QString strSQL);//执行返回数据集的SQL语句
    QString loguser(QString name,QString passward);
    bool signup(QString name,QString passward);
    QString getinfo(QString name);

private:
    QSqlQuery *query;
};

#endif // MYSQL_H
