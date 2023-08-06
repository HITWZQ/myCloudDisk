#include <QCoreApplication>
#include "tcpnet.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    TCPNet tn;
    if(tn.initNetWork())
        printf("server is running\n");
    else
        printf("server err\n");
    return a.exec();
}
