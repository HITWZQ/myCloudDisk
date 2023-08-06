#ifndef TCPNET_H
#define TCPNET_H
#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
class TCPNet
{
public:
    TCPNet();
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
};

#endif // TCPNET_H
