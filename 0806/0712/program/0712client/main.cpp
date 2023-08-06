#include <QCoreApplication>
#include "tcpnet.h"


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    TCPNet tn;
    if(tn.connectServer())
        printf("connect server success\n");
    else
        printf("connect server err\n");
    char szbuf[1024] = {0};
    scanf("%s",szbuf);
    tn.sendData(szbuf,sizeof(szbuf));
    return a.exec();
}
