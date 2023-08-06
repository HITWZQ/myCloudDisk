#include "tcpnet.h"

TCPNet::TCPNet()
{
    m_socklisten = 0;
    m_bFlagQuit = true;
}

TCPNet::~TCPNet()
{

}


bool TCPNet::initNetWork(const char *ip, short sport)
{
    //1.选择种类 面馆 火锅店  烤肉店---加载库
    WORD wVersionRequested;
    WSADATA wsaData;
      int err;

  /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
      wVersionRequested = MAKEWORD(2, 2);

      err = WSAStartup(wVersionRequested, &wsaData);
      if (err != 0) {

          printf("WSAStartup failed with error: %d\n", err);
          return false;
      }

      if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {

         // printf("Could not find a usable version of Winsock.dll\n");
          uninitNetWork("wsastartup err");
          return false;
      }
      else
          printf("The Winsock 2.2 dll was found okay\n");


    //2.雇个店长--创建套接字
     m_socklisten = socket(AF_INET,SOCK_STREAM,0);
     if(INVALID_SOCKET == m_socklisten){
         uninitNetWork("socket err");
         return false;
     }
    //3.找个地方--绑定地址信息
     sockaddr_in addr;
     addr.sin_family = AF_INET;
     addr.sin_addr.S_un.S_addr = 0;//ip地址
     addr.sin_port = htons(sport);//端口号   0---1024
     if(SOCKET_ERROR == bind(m_socklisten,
                             (const sockaddr *)&addr,
                             sizeof(addr))){
         uninitNetWork("bind err");
         return false;
     }

    //4.宣传--监听
     if(SOCKET_ERROR  == listen(m_socklisten,128)){
         uninitNetWork("listen err");
         return false;
     }
     //5.接收客户端链接---创建线程
    HANDLE hThread=  CreateThread(0,0,&TCPNet::ThreadAccept,this,0,0);
    if(hThread)//将线程的句柄加入链表中
        m_lstThread.push_back(hThread);
     return true;
}

DWORD WINAPI TCPNet::ThreadAccept(LPVOID lpvoid){

    TCPNet *pthis = (TCPNet*)lpvoid;
    sockaddr_in addrclient;
    int nSize = sizeof(addrclient);
    DWORD dwThreadId;
    while(pthis->m_bFlagQuit){

        //接收链接
        SOCKET sockWaiter = accept(pthis->m_socklisten,(sockaddr*)&addrclient, &nSize);
        printf("client ip:%s,client port:%d\n",inet_ntoa(addrclient.sin_addr),addrclient.sin_port);
        //为每一个客人创建一个线程
        HANDLE hThread=  CreateThread(0,0,&TCPNet::ThreadRecv,
                                      pthis,0,&dwThreadId);
        if(hThread)//将线程的句柄加入链表中
        {
            pthis->m_lstThread.push_back(hThread);
            pthis->m_mapThreadIdToSocket[dwThreadId] = sockWaiter;
        }


    }
    return 0;
}

DWORD TCPNet::ThreadRecv(LPVOID lpvoid)
{
    TCPNet *pthis = (TCPNet*)lpvoid;
    pthis->recvData();

    return 0;
}

void TCPNet::recvData()
{
    DWORD dwThreadId = GetCurrentThreadId();
    SOCKET sockWaiter = m_mapThreadIdToSocket[dwThreadId];

    int nPackSize;
    while(m_bFlagQuit){

        //接收包大小
       int nRecvNum =  recv(sockWaiter,(char*)&nPackSize,sizeof(int),0);
       if(nRecvNum <=0){
           closesocket(sockWaiter);
           break;
       }
       //接收包内容

        //申请空间
        char *pszbuf  = new char[nPackSize];
        int offset = 0;
        while(nPackSize){
             int nRecvNum = recv(sockWaiter,pszbuf+offset,nPackSize,0);
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


void TCPNet::uninitNetWork(const char* error)
{
    m_bFlagQuit = false;
    //如果线程退不出去，则强制杀死
    //线程   无信号  如果线程退出，则变成有信号
    //遍历 链表
    //获取链表的头
    auto ite  = m_lstThread.begin();
    while(ite  != m_lstThread.end()){
         //判断线程是否有信号
        if(WAIT_TIMEOUT == WaitForSingleObject(*ite,100))
            TerminateThread(*ite,-1);
        //关闭句柄
        CloseHandle(*ite);
        *ite = NULL;
        ite++;
    }

    printf("%s\n",error);
    if(m_socklisten){
      closesocket(m_socklisten);
      m_socklisten = 0;
    }
    WSACleanup();
}

bool TCPNet::sendData(SOCKET sock, const char *szbuf, int nlen)
{
    if(!sock || !szbuf || nlen <=0)
        return false;
    //发送包大小

    if(send(sock,(char*)&nlen,sizeof(int),0)<=0)
        return false;
     //发送包内容
    if(send(sock,szbuf,nlen,0)<=0)
        return false;


    return true;
}

