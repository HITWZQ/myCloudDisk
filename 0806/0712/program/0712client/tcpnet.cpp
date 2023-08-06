#include "tcpnet.h"

TCPNet::TCPNet()
{
   m_sockclient = 0;
   m_hThread = 0;
   m_bFlagQuit = true;
}
TCPNet::~TCPNet()
{

}

bool TCPNet::connectServer(const char *ip, short sport)
{
       WORD wVersionRequested;
       WSADATA wsaData;
      int err;
      wVersionRequested = MAKEWORD(2, 2);

      err = WSAStartup(wVersionRequested, &wsaData);
      if (err != 0) {

          printf("WSAStartup failed with error: %d\n", err);
          return false;
      }


      if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {

          disconnectServer("WSAStartup err");
          return false;
      }
      else
          printf("The Winsock 2.2 dll was found okay\n");

    //2.创建socket();
      m_sockclient = socket(AF_INET,SOCK_STREAM,0);
      if(INVALID_SOCKET == m_sockclient){
          disconnectServer("socket err");
          return false;
      }
    //3.链接服务器 connect(); -- ip ,port
      sockaddr_in addr;
      addr.sin_family = AF_INET;
      addr.sin_addr.S_un.S_addr = inet_addr(ip);//ip地址
      addr.sin_port = htons(sport);//端口号
      if(SOCKET_ERROR == connect(m_sockclient,(const sockaddr *)&addr,sizeof(addr))){
          disconnectServer("connect err");
          return false;
      }
      //创建线程--接收数据
      m_hThread = CreateThread(0,0,&ThreadRecv,this,0,0);

      return true;
}

DWORD TCPNet::ThreadRecv(LPVOID lpvoid)
{
    TCPNet *pthis = (TCPNet*)lpvoid;
    pthis->recvData();
    return 0;
}

void TCPNet::disconnectServer(const char* err)
{
    m_bFlagQuit = false;
    if(m_hThread){
        if(WAIT_TIMEOUT == WaitForSingleObject(m_hThread,100))
                TerminateThread(m_hThread,-1);

        CloseHandle(m_hThread);
        m_hThread = 0;
    }
    printf("%s\n",err);
    if(m_sockclient){
         closesocket(m_sockclient);
         m_sockclient = 0;
    }

    WSACleanup();
}

bool TCPNet::sendData(const char *szbuf, int nlen)
{
    if(!szbuf || nlen <=0)
        return false;
    //发送包大小
    if(send(m_sockclient,(char*)&nlen,sizeof(int),0)<=0)
        return false;
     //发送包内容
    if(send(m_sockclient,szbuf,nlen,0)<=0)
        return false;
    return true;
}

void TCPNet::recvData()
{
    int nPackSize;
    while(m_bFlagQuit){

        //接收包大小
       int nRecvNum =  recv(m_sockclient,(char*)&nPackSize,sizeof(int),0);
       if(nRecvNum <=0){
           closesocket(m_sockclient);
           break;
       }
       //接收包内容

        //申请空间
        char *pszbuf  = new char[nPackSize];
        int offset = 0;
        while(nPackSize){
             int nRecvNum = recv(m_sockclient,pszbuf+offset,nPackSize,0);
             offset += nRecvNum;
             nPackSize -= nRecvNum;

        }
        //处理
        printf("server recv:%s\n",pszbuf);
        //删除
        delete[]pszbuf;
        pszbuf = NULL;
    }
}


