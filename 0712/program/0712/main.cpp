#include <QCoreApplication>
#include<winsock2.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    WORD wVersionRequested;
        WSADATA wsaData;
        int err;

    /* Use the MAKEWORD(lowbyte, highbyte) macro declared in Windef.h */
        wVersionRequested = MAKEWORD(2, 2);

        err = WSAStartup(wVersionRequested, &wsaData);
        if (err != 0) {
            /* Tell the user that we could not find a usable */
            /* Winsock DLL.                                  */
            printf("WSAStartup failed with error: %d\n", err);
            return 1;
        }

    /* Confirm that the WinSock DLL supports 2.2.*/
    /* Note that if the DLL supports versions greater    */
    /* than 2.2 in addition to 2.2, it will still return */
    /* 2.2 in wVersion since that is the version we      */
    /* requested.                                        */

        if (LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2) {
            /* Tell the user that we could not find a usable */
            /* WinSock DLL.                                  */
            printf("Could not find a usable version of Winsock.dll\n");
            WSACleanup();
            return 1;
        }
        else
            printf("Server""\nThe Winsock 2.2 dll was found okay\n");


    /* The Winsock DLL is acceptable. Proceed to use it. */

    /* Add network programming using Winsock here */

    /* then call WSACleanup when done using the Winsock dll */



    //创建套接字
      SOCKET socketlisten = socket(AF_INET,SOCK_STREAM,0);
      if(INVALID_SOCKET==socketlisten){
           printf("socket err\n");
           WSACleanup();
           return 1;
      }

     //绑定地址信息
      sockaddr_in addr;
      addr.sin_family=AF_INET;
      addr.sin_addr.S_un.S_addr=0;
      addr.sin_port=htons(8899);

      if(SOCKET_ERROR==bind(socketlisten,(const sockaddr*)&addr,sizeof (addr)))
      {
          printf("bind err");
          closesocket(socketlisten);
          WSACleanup();
          return 1;
      }
    //监听
     if(SOCKET_ERROR== listen(socketlisten,128)){
         printf("listen err");
         closesocket(socketlisten);
         WSACleanup();
         return 1;
     }
     //接受链接
      sockaddr_in addrclient;
      int nSize=sizeof(addrclient);
      printf("begin accept");
      SOCKET sockWaiter=accept(socketlisten,
                               (sockaddr *)&addrclient,
                               &nSize
                               );
      printf("accept success");
      printf("client ip:%s,client port:%d\n",
             inet_ntoa(addrclient.sin_addr),
             addrclient.sin_port);

      char szbuf[1024]={0};
      while(1){
          //说话
          printf("please inpunt content:\n");
          scanf("%s",szbuf);
          send(sockWaiter,szbuf,sizeof (szbuf),0);

          //接受
          int nRecvNum=recv(sockWaiter,szbuf,sizeof (szbuf),0);
          if(nRecvNum>0)
              printf("recv buffers:%s\n",szbuf);
          else
               break;
      }

      closesocket(sockWaiter);
      closesocket(socketlisten);
      WSACleanup();

    return a.exec();
}
