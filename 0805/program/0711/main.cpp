#include "widget.h"
#include <windows.h>
#include "QDebug"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();


//    STARTUPINFOA si={sizeof(STARTUPINFOA)};
//    PROCESS_INFORMATION pi;
//    char szbuf[1024]="D:\\software\\WeChat\\WeChat.exe";

//    CreateProcessA(0,
//                  szbuf,
//                  0,
//                  0,
//                  0,
//                  NORMAL_PRIORITY_CLASS,
//                  0,
//                  0,
//                  &si,
//                  &pi
//                  );

//    Sleep(2000);
//    TerminateProcess(pi.hProcess,-1);


//    qDebug()<<GetLastError();
    return a.exec();



}
