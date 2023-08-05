#include <QCoreApplication>
#include <windows.h>
#define MAX 10

CRITICAL_SECTION cs;
long ticket=100;

DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter){
    while(1){
        if(ticket<=0){
            printf("current thread[%d]is gone\n",GetCurrentThreadId());
            break;
        }


        EnterCriticalSection(&cs);
        if(ticket==0){
            printf("current thread[%d]is gone\n",GetCurrentThreadId());
            LeaveCriticalSection(&cs);
            break;
        }

        ticket--;
        printf("current thread[%d] ticket = %d\n",GetCurrentThreadId(),ticket);
        LeaveCriticalSection(&cs);
         Sleep(10);
    }
    return 0;

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    InitializeCriticalSection(&cs);

    HANDLE hThread[MAX];

    for(int i=0;i < MAX ;i++){
         hThread[i]=CreateThread(0,0,&ThreadProc,0,0,0);
    }

    return a.exec();
}
