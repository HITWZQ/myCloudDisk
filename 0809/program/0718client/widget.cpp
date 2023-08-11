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
    connect((TCPKernal*)m_pKernal,&TCPKernal::signallogin,
            this,&Widget::slotlogin);
    connect((TCPKernal*)m_pKernal,&TCPKernal::signalgetfilelist,
            this,&Widget::slotgetfilelist);
    connect((TCPKernal*)m_pKernal,&TCPKernal::signaluploadfileinfo,
            this,&Widget::slotuploadfileinfo);
}

Widget::~Widget()
{
    delete m_pKernal;
    m_pKernal=0;
    delete ui;
}
std::string FileDigest(const std::string &file)
{

    std::ifstream in(file.c_str(),  std::ios::binary);
    int n = GetLastError();
    if (!in)
        return "";

    MD5 md5;
    std::streamsize length;
    char buffer[1024];
    while (!in.eof()) {
        in.read(buffer, 1024);
        length = in.gcount();
        if (length > 0)
            md5.update(buffer, length);
    }
    in.close();
    return md5.toString();
}

void Widget::slotlogin(const char *szbuf)
{
    STRU_LOGIN_RS *pslr=(STRU_LOGIN_RS*)szbuf;
    pslr->m_ntype=_deafult_protocol_login_rs;
    const char *pszResult=NULL;

    if(pslr->m_szResult==_login_usernotexist)
        pszResult="_login_usernotexist";
    else if(pslr->m_szResult==_login_passwd_err)
        pszResult="_login_passwd_err";
    else{
        pszResult="_login_success";
        m_userid=pslr->m_userid;
        m_plogin->hide();
        this->show();

        STRU_GETFILELIST_RQ psgr;
        psgr.m_ntype=_deafult_protocol_getfilelist_rq;
        psgr.m_userid=m_userid;
        m_pKernal->sendData((char*)&psgr,sizeof(psgr));

        return;
    }


    QMessageBox::information(this,"login",pszResult);
}

void Widget::slotgetfilelist(const char *szbuf)
{
    STRU_GETFILELIST_RS *psgr=(STRU_GETFILELIST_RS*)szbuf;
    psgr->m_ntype=_deafult_protocol_getfilelist_rs;
    m_nFileNum=psgr->m_nFileNum;
    int i=0;
    for(i=0;i<psgr->m_nFileNum;i++ ){

        //名字
         QTableWidgetItem *pItem=new QTableWidgetItem(psgr->m_aryFileInfo[i].m_szFilseName);
         ui->tableWidget->setItem(i,0,pItem);
         //大小
         QString pstr=QString::number(psgr->m_aryFileInfo[i].m_filesize);
         pItem=new QTableWidgetItem(pstr);
         ui->tableWidget->setItem(i,1,pItem);
         //上传时间
         pItem=new QTableWidgetItem(psgr->m_aryFileInfo[i].m_szFileUploadTime);
         ui->tableWidget->setItem(i,2,pItem);


    }
}

void Widget::slotuploadfileinfo(const char *szbuf)
{
    STRU_UPLOADFILEINFO_RS *psur=(STRU_UPLOADFILEINFO_RS*)szbuf;

    stru_uploadfileinfo* pInfo=NULL;
    auto ite=m_lstUpLoadFileInfo.begin();
    while(ite!=m_lstUpLoadFileInfo.end()){
        if(0==strcmp(psur->m_szFileMD5,(*ite)->m_szFileMD5)){
            pInfo=*ite;
            break;
        }
        ite++;
    }
    //秒传
    if(psur->m_szResult==_uploadfileinfo_success){

    }
    else{
        //正常上传
        STRU_UPLOADFILEINCONTENT_RQ sur;
        sur.m_ntype=_deafult_protocol_uploadfileblock_rq;
        sur.m_userid=m_userid;
        sur.m_szFileId=psur->m_szFileId;
        while(1){
            size_t readnum=fread(sur.m_szFileContent,
                                 sizeof(char),
                                 sizeof(sur.m_szFileContent),
                                 pInfo->m_pfile
                        );
            if(readnum>0){
                sur.m_szFileNum=readnum;
                m_pKernal->sendData((char*)&sur,sizeof (sur));
            }
            else
                break;
        }
        fclose(pInfo->m_pfile);

    }
    //名字
     QTableWidgetItem *pItem=new QTableWidgetItem(pInfo->m_szFilseName);
     ui->tableWidget->setItem(m_nFileNum,0,pItem);
     //大小
     QString pstr=QString::number(pInfo->m_filesize);
     pItem=new QTableWidgetItem(pstr);
     ui->tableWidget->setItem(m_nFileNum,1,pItem);
     //上传时间
     QDateTime date=QDateTime::currentDateTime();
     QTime t=QTime::currentTime();
     QString strDate=date.toString();
     QString strTime=t.toString();
     pItem=new QTableWidgetItem(strDate+" "+strTime);
     ui->tableWidget->setItem(m_nFileNum,2,pItem);

     m_nFileNum++;
     QMessageBox::information(this,"upload file","_uploadfileinfo_success");

     delete pInfo;
     m_lstUpLoadFileInfo.erase(ite);
}


void Widget::on_pushButton_clicked()
{
    QString pathName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                      ".",
                                                      tr("Images (*.png *.xpm *.jpg);;Text files (*.txt);;ALL files (*.*)"));
    qDebug()<<pathName;
    //获取文件名字
    QString fileName=pathName.section('/',-1);
    //获取文件大小
    QFile file(pathName);
    file.open(QIODevice::ReadOnly);
    qint64 size=file.size();
    file.close();
    //获取文件MD5值
    string strMD5=FileDigest(pathName.toStdString());
    qDebug()<<strMD5.c_str();

    STRU_UPLOADFILEINFO_RQ sur;
    sur.m_ntype=_deafult_protocol_uploadfilefo_rq;
    sur.m_userid=m_userid;
    sur.m_filesize=size;
    strcpy(sur.m_szFileMD5,strMD5.c_str());
    strcpy(sur.m_szFilseName,fileName.toStdString().c_str());
    m_pKernal->sendData((char*)&sur,sizeof(sur));

    //把文件信息保存下来到链表
    stru_uploadfileinfo* pInfo=new stru_uploadfileinfo;
    pInfo->m_pfile=fopen(pathName.toStdString().c_str(),"rb+");
    pInfo->m_fileId=0;
    pInfo->m_filesize=size;
    strcpy(pInfo->m_szFilseName,fileName.toStdString().c_str());
    strcpy(pInfo->m_szFileMD5,strMD5.c_str());

    m_lstUpLoadFileInfo.push_back(pInfo);




}
