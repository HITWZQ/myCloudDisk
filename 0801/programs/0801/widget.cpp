#include "widget.h"
#include "ui_widget.h"
#include<QLabel>
#include<QPushButton>
#include<QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //创建控件
    QLabel *pLabel = new QLabel ("helloworld",this);
    //创建按钮
    QPushButton *p=new QPushButton("Problem",this);
    //移动位置
    p->move(100,100);

    setWindowIcon(QIcon(":/Image/0.png"));
    setStyleSheet("background-image: url(:/Image/0.png);");

//    connect(ui->pushButton_2,
//            &QPushButton::clicked,
//            this,
//            [=](){
//        qDebug()<<"hi";
//    });

//    emit ui->pushButton_2->clicked();

//    connect(ui->pushButton,
//            &QPushButton::clicked,
//            this,
//            &Widget::on_pushButton_clicked);

//    connect(ui->pushButton, &QPushButton::clicked, this, [=](){
//        int value1 = ui->lineEdit1->text().toInt();
//        int value2 = ui->lineEdit2->text().toInt();
//        ui->lineEdit3->setText(QString::number(value1 + value2));
//    });








}

Widget::~Widget()
{
    delete ui;

}

void Widget::on_pushButton_clicked()
{
    //获取加数
    QString str1=ui->lineEdit1->text();
    qDebug()<<str1;
    QString str2=ui->lineEdit2->text();
    qDebug()<<str2;

    ui->lineEdit3->setText(QString::number(str1.toInt()+str2.toInt()));

}


