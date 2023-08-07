#include <QCoreApplication>
#include "tcpkernal.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    IKernal *p=TCPkernal::getKernal();
    if(p->open())
        qDebug()<<"Server is running";


    //测试STRU_REGISTER_RQ是否成功
    STRU_REGISTER_RQ srr;
    srr.m_tel=12345678906;
    srr.m_ntype=_deafult_protocol_regisiter_rq;
    strcpy(srr.m_szname,"rachel");
    strcpy(srr.m_szPassword,"123456");

    p->dealData(0,(char*)&srr);

    return a.exec();
}
