#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
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

    for(int i=0;i<=100;i++){

            emit pThis->sendI(i);
        Sleep(100);


        }
}

void Widget::receiveI(int i)
{
    ui->progressBar->setValue(i);
}

void Widget::on_pushButton_clicked()
{
    CreateThread(0,
                 0,
                 &ThreadProc,
                 this,
                 0,
                 0);
}

