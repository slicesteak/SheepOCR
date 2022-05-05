#include "mysql.h"
MySql::MySql()
{

}

void MySql::initsql(QString ip,QString password)
{
//    if(ip==""){
//        QMessageBox::information(0,"信息提示","请输入数据库ip地址",QMessageBox::Ok);
//    }else{
        QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(ip);
        db.setUserName("root");
        db.setPassword(password);
        db.setDatabaseName("user");
        if(db.open())
        {
            qDebug()<<"Database connected successfully!";
            QMessageBox::information(0,"信息提示","数据库连接成功!",QMessageBox::Ok);
            //createtable();
            return;
        }
        else
        {
            qDebug()<<"Database connected failed!";
            QMessageBox::information(0,"信息提示","数据库连接失败!",QMessageBox::Ok);
            return;
        }
    }
//}

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
    QString str=QString("select username,app_id,api_key,sk,token from user where username='%1' and password='%2'").arg(name).arg(password);
    info=ExecuteSqlEx(str);
    return info;
}


bool MySql::signup(QString name,QString password)
{  
    QString i=QString("insert into user(username,password) values ('%1','%2'); ").arg(name).arg(password);
    return ExecuteSql(i);
}


QString MySql::getinfo(QString name)
{
    QString s=QString("select username,app_id,api_key,sk,token from user where username='%1' ").arg(name);
    QString info=ExecuteSqlEx(s);
    return info;
}

bool MySql::ExecuteSql(QString strSQL){
    QSqlQuery query;
    if(query.exec(strSQL)){
        return true;
    }
    else{
        return false;
    }
}

QString MySql::ExecuteSqlEx(QString strSQL){
    QSqlQuery query;
    QString info;
    if(query.exec(strSQL)){
        query.last();
        int record=query.at()+1;
        if(record==0)
            info="#false";
        else{
            info="#true";
            query.exec(strSQL);
//            int i=0;
            while(query.next()){
//                info+="#"+query.value(i).toString();
//                i=i+1;
                info+="#"+query.value(0).toString();
                info+="#"+query.value(1).toString();
                info+="#"+query.value(2).toString();
                info+="#"+query.value(3).toString();
                info+="#"+query.value(4).toString();
                qDebug()<<info;
            }
        }
    }
    else{
        info="#false";
    }
    return info;
}
