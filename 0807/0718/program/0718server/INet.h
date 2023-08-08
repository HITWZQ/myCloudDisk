#ifndef INET_H
#define INET_H

#include <winsock2.h>

class INet{

public:
    INet(){

    };
    virtual ~INet(){

    };

public:
    //1.初始化网络
         virtual bool initNetWork(const char* ip,short sport)=0;
        //2.卸载网络
        virtual void uninitNetWork(const char* error)=0;

        //3.发送数据
         virtual bool sendData(SOCKET sock,const char* szbuf,int nlen)=0;
        //4.接收数据
         virtual void recvData()=0;
};

#endif // INET_H
