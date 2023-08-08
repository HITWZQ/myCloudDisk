#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_pKernal=new TCPKernal;

    m_plogin=new login;
    m_plogin->setKernal(m_pKernal);

    if(m_pKernal->open()){
        qDebug()<<"connect server success";
    }


    m_plogin->show();

    connect((TCPKernal*)m_pKernal,&TCPKernal::sigalregister,
            m_plogin,&login::slotregister);
}

Widget::~Widget()
{
    delete m_pKernal;
    m_pKernal=0;
    delete ui;
}

