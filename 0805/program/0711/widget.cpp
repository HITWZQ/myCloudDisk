#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    hThread=0;
    ui->setupUi(this);

    connect(ui->pushButton,
            &QPushButton::clicked,
            this,
            &Widget::on_pushButton_clicked);

    connect(this,&Widget::sendI,this,&Widget::receiveI);


}

Widget::~Widget()
{
    delete ui;
}

DWORD WINAPI ThreadProc(_In_ LPVOID lpParameter)
{
    Widget *pThis=(Widget*)lpParameter;
    pThis->threadFlag=true;
    while(pThis->threadFlag){
        for(int i=0;i<=100;i++){

                emit pThis->sendI(i);
            Sleep(100);


            }
    }

}

void Widget::receiveI(int i)
{
    ui->progressBar->setValue(i);
}

void Widget::on_pushButton_clicked()
{

    if(!hThread){
       hThread= CreateThread(0,
                         0,
                         &ThreadProc,
                         this,
                         0,
                         0);
    }
    else
        ResumeThread(hThread);



}



void Widget::on_pushButton_2_clicked()
{
    SuspendThread(hThread);
}

void Widget::on_pushButton_3_clicked()
{
    threadFlag=false;
    if(WAIT_TIMEOUT==WaitForSingleObject(hThread,200))
        TerminateThread(hThread,-1);
    if(hThread){
        CloseHandle(hThread);
        hThread=0;
    }
    ui->progressBar->setValue(0);
}
