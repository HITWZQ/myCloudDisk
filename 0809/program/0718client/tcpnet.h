#ifndef TCPNET_H
#define TCPNET_H

#include "INet.h"
#include "IKernal.h"
class TCPNet:public INet
{
public:
    TCPNet(IKernal *pKernal);
    ~TCPNet();
public:
    bool connectServer(const char* ip = "127.0.0.1",short sport=8899);
    void disconnectServer(const char* err);
    bool sendData(const char* szbuf,int nlen);
    void recvData();
public:
    static DWORD WINAPI ThreadRecv(LPVOID lpvoid);
private:
    SOCKET m_sockclient;
    HANDLE m_hThread;
    bool   m_bFlagQuit;
    IKernal* m_pKernal;
};

#endif // TCPNET_H
