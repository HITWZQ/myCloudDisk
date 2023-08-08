#ifndef INET_H
#define INET_H

#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
class INet
{
public:
    INet(){};
    virtual ~INet(){};
public:
   virtual bool connectServer(const char* ip = "127.0.0.1",short sport=8899)=0;
   virtual void disconnectServer(const char* err)=0;
   virtual bool sendData(const char* szbuf,int nlen)=0;
   virtual void recvData()=0;

};

#endif // INET_H
