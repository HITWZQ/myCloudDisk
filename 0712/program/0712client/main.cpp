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
            printf("Client\nThe Winsock 2.2 dll was found okay\n");


    /* The Winsock DLL is acceptable. Proceed to use it. */

    /* Add network programming using Winsock here */

    /* then call WSACleanup when done using the Winsock dll */



        //创建套接字
          SOCKET socketClient=socket(AF_INET,SOCK_STREAM,0);
          if(INVALID_SOCKET==socketClient){
               printf("socket err");
               WSACleanup();
               return 1;
          }

        //连接服务器
          sockaddr_in addr;
          addr.sin_family=AF_INET;
          addr.sin_addr.S_un.S_addr=inet_addr("172.20.247.119");
          addr.sin_port=htons(8899);
          if(SOCKET_ERROR==connect(socketClient,(const sockaddr*)&addr,sizeof(addr))){
              printf("connect err");
              WSACleanup();
              return 1;
          }
          else
              printf("connect succes");

          char szbuf[1024]={0};
          while (1) {
              int nRecvNum=recv(socketClient,szbuf,sizeof (szbuf),0);
              if(nRecvNum>0)
                  printf("server say:%s\n",szbuf);
              else
                   break;

              scanf("%s",szbuf);
              send(socketClient,szbuf,sizeof (szbuf),0);
          }
          closesocket(socketClient);
          WSACleanup();
    return a.exec();
}
