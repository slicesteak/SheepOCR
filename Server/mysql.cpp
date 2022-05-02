#include "mysql.h"

MySql::MySql()
{

}

void MySql::initsql(QString ip)
{
    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName(ip);
    db.setUserName("root");
    //db.setPassword("!@#123");
    db.setDatabaseName("user");
    if(db.open())
        {
            qDebug()<<"Database connected successfully!";
            //createtable();
            return;
        }
    else
        {
            qDebug()<<"Database connected failed!";
            return;
        }
}

void MySql::createtable()
{
    query=new QSqlQuery;

    query->exec("create table user(name VARCHAR(30) PRIMARY KEY UNIQUE NOT NULL,passward VARCHAR(30))");

    /*创建root用户*/
    query->exec("insert into user value('root', 'root')");
}


QString MySql::loguser(QString name, QString password)
{
    QString info;
    QString Username,ID,APIK,SK,Token;
    QString str=QString("select username,app_id,api_key,sk,token from user where username='%1' and password='%2'").arg(name).arg(password);
    query=new QSqlQuery;
    if(query->exec(str)){
        while(query->next()){
            Username=query->value(0).toString();
            ID=query->value(1).toString();
            APIK=query->value(2).toString();
            SK=query->value(3).toString();
            Token=query->value(4).toString();
        }
        info="#true#"+Username+"#"+ID+"#"+APIK+"#"+SK+"#"+Token;
    }
    else{
        info="#false";
    }
    return info;
//    query->last();
//    int record=query->at()+1;
//    if(record==0)
//        return false;
//    return true;
}


bool MySql::signup(QString name,QString password)
{
    QString i=QString("insert into user(username,password) values ('%1','%2'); ").arg(name).arg(password);
    //QString S =QString("select * from user where username='%1' ").arg(name);
    QSqlQuery query;
    if(query.exec(i)){
        return true;
    }
    else{
        return false;
    }


//    QString str=QString("select * from user where username='%1").arg(name);
//    query=new QSqlQuery;
//    query->exec(str);
//    query->last();
//    int record=query->at()+1;
//    if(record!=0)
//        return false;
//    str=QString("insert into user value('%1','%2')").arg(name).arg(password);
//    bool ret=query->exec(str);
//    return ret;
}


QString MySql::getinfo(QString name)
{
    QString Username,ID,APIK,SK,Token;
    QString s=QString("select username,app_id,api_key,sk,token from user where username='%1' ").arg(name);
    QSqlQuery query;
    query.exec(s);
    while(query.next()){
        Username=query.value(0).toString();
        ID=query.value(1).toString();
        APIK=query.value(2).toString();
        SK=query.value(3).toString();
        Token=query.value(4).toString();
    }
    QString info="#"+Username+"#"+ID+"#"+APIK+"#"+SK+"#"+Token;
    return info;
}
