#include "login.h"
#include "ui_login.h"
#include "packdef.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    //申请账号
    QString strTel=ui->registerTel->text();
    QString strUser=ui->registerUser->text();
    QString strPasswrd=ui->registerPasswrd->text();
    qDebug()<<strTel<<strUser<<strPasswrd;


    STRU_REGISTER_RQ srr;
    srr.m_ntype=_deafult_protocol_regisiter_rq;
    srr.m_tel=strTel.toLongLong();
    strcpy(srr.m_szname,strUser.toStdString().c_str());
    strcpy(srr.m_szPassword,strPasswrd.toStdString().c_str());

    m_pKernal->sendData((char*)&srr,sizeof(srr));

}

void login::slotregister(const char* szbuf)
{
    STRU_REGISTER_RS *psrr=(STRU_REGISTER_RS*)szbuf;
    const char *pszResult="_register_er";
    if(psrr->m_szResult==_register_success)
        pszResult="_register_success";

    QMessageBox::information(this,"register",pszResult);
}

void login::on_pushButton_2_clicked()
{
    QString strUser=ui->loignUser->text();
    QString strPasswrd=ui->loginPasswrd->text();

    STRU_LOGIN_RQ slr;
    slr.m_ntype=_deafult_protocol_login_rq;
    strcpy(slr.m_szname,strUser.toStdString().c_str());
    strcpy(slr.m_szPassword,strPasswrd.toStdString().c_str());

    m_pKernal->sendData((char*)&slr,sizeof(slr));
}
