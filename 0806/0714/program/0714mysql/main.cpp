#include <QCoreApplication>
#include "CMySql.h"
#include<QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CMySql mysql;
    if(mysql.ConnectMySql("zqwu19","hitwzq","123456","0717disk")){
          qDebug()<<"connect success"    ;
    }

//    if(mysql.UpdateMySql("delete from student where sunm="08";")){
//         qDebug()<<"connect success"    ;
//    }
    if(mysql.UpdateMySql("insert into user(u_tel,u_name,u_password) values(12345678904,'lily','123456');")){
          qDebug()<<"insert success"    ;
    };
    if(mysql.UpdateMySql("delete from user where u_name='lily'")){
          qDebug()<<"delete success"    ;
    }

//    list<string> lststr;
//    mysql.SelectMySql("select  from student",1,lststr);
//    while (lststr.size()>0) {
//        string sname=lststr.front();
//        lststr.pop_front();
//        string sage=lststr.front();
//        lststr.pop_front();
//        qDebug()<<sname.c_str()<<":"<<sage.c_str();    }


     return a.exec();
}
