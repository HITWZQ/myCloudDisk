#include <QCoreApplication>
#include "CMySql.h"
#include<QDebug>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CMySql mysql;
    if(mysql.ConnectMySql("localhost","hitwzq","123456","0713test")){
          qDebug()<<"connect success"    ;
    }

//    if(mysql.UpdateMySql("delete from student where sunm="08";")){
//         qDebug()<<"connect success"    ;
//    }
    if(mysql.UpdateMySql("delete from student where snum=08;")){
          qDebug()<<"delete success"    ;
    }

    list<string> lststr;
    mysql.SelectMySql("select sname,sage from student",2,lststr);
    while (lststr.size()>0) {
        string sname=lststr.front();
        lststr.pop_front();
        string sage=lststr.front();
        lststr.pop_front();
        qDebug()<<sname.c_str()<<":"<<sage.c_str();    }


     return a.exec();
}
