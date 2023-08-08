#ifndef TCPNET_H
#define TCPNET_H

#include "INet.h"
#include <stdio.h>
#include <list>
#include <map>
using namespace  std;
class TCPNet:public INet
{
public:
    TCPNet();
    ~TCPNet();
public:
    //1.初始化网络
     bool initNetWork(const char* ip = "127.0.0.1",short sport=8899);
    //2.卸载网络
     void uninitNetWork(const char* error);

    //3.发送数据
     bool sendData(SOCKET sock,const char* szbuf,int nlen);
    //4.接收数据
     void recvData();
     //线程函数
     static DWORD WINAPI ThreadAccept(LPVOID lpvoid);
     static DWORD WINAPI ThreadRecv(LPVOID lpvoid);
private:
     SOCKET m_socklisten;
     bool   m_bFlagQuit;
     list<HANDLE> m_lstThread;
     map<DWORD,SOCKET> m_mapThreadIdToSocket;
};

#endif // TCPNET_H
