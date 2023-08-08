#include "tcpkernal.h"
#include "tcpnet.h"

TCPkernal* TCPkernal::m_kernal = new TCPkernal;
TCPkernal::TCPkernal()
{
    strcpy(m_szSystemPath,"D:/work/myCloudDisk/disk");
    m_pTCPnet=new TCPNet;
    m_sql=new CMySql;
}

TCPkernal::~TCPkernal()
{
    delete m_pTCPnet;
    m_pTCPnet=0;
    delete m_sql;
    m_sql=0;
}

bool TCPkernal::open()
{
    if(!m_pTCPnet->initNetWork("127.0.0.1",8899)){
        qDebug()<<"initNetWork err";
        return false;
    }

    if(!m_sql->ConnectMySql("zqwu19","hitwzq","123456","0717disk")){
        qDebug()<<"ConnectMySql err";
        return false;
    }
    else
        return true;
}

void TCPkernal::close()
{
    m_pTCPnet->uninitNetWork("success close");
    m_sql->DisConnect();
}

void TCPkernal::dealData(SOCKET socket, char *szbuf)
{
    switch(*szbuf){
    case _deafult_protocol_regisiter_rq:
        registerrq(socket,szbuf);
        break;
    case _deafult_protocol_login_rq:
        loginrq(socket,szbuf);
        break;
    case _deafult_protocol_getfilelist_rq:
        getfilelistrq(socket,szbuf);
        break;

    }

}

void TCPkernal::registerrq(SOCKET socket, char *szbuf)
{
    STRU_REGISTER_RQ *psrr=(STRU_REGISTER_RQ*)szbuf;
    STRU_REGISTER_RS srr;

    char szsql[SQLLEN];
    char szPath[MAX_PATH];

    list<string> lststr;

    srr.m_ntype=_deafult_protocol_regisiter_rs;
    srr.m_szResult=_register_err;

    //将信息写入数据库
    sprintf(szsql,"insert into user(u_tel,u_name,u_password) values(%lld,'%s','%s')"
            ,psrr->m_tel,psrr->m_szname,psrr->m_szPassword);
    //qDebug() << "Error inserting data:" << query.lastError().text();
    if(m_sql->UpdateMySql(szsql)){
        //判断结果申请成功则分配空间
        //获取当前用户的ID
        sprintf(szsql,"select u_id from user where u_tel='%lld';"
                ,psrr->m_tel);
        m_sql->SelectMySql(szsql,1,lststr);

        if(lststr.size()>0){
            srr.m_szResult=_register_success;
            string strUserId=lststr.front();
            lststr.pop_front();
            //D:/work/myCloudDisk/disk/id
            sprintf(szPath,"%s/%s",m_szSystemPath,strUserId.c_str());
            //创建目录
            CreateDirectoryA(szPath,0);
        }

        //发送回复
        m_pTCPnet->sendData(socket,(char*)&srr,sizeof (srr));

    }

}

void TCPkernal::loginrq(SOCKET socket, char *szbuf)
{
    //校验用户名和密码
    STRU_LOGIN_RQ *pslr=(STRU_LOGIN_RQ*)szbuf;
    char szsql[SQLLEN];
    list<string> lststr;

    STRU_LOGIN_RS slr;
    slr.m_ntype=_deafult_protocol_login_rs;
    slr.m_szResult=_login_usernotexist;

    sprintf(szsql,"select u_id,u_password from user where u_name='%s';"
            ,pslr->m_szname);
    m_sql->SelectMySql(szsql,2,lststr);
    if(lststr.size()>0){

        slr.m_szResult=_login_passwd_err;

        string strUserId =lststr.front();
        lststr.pop_front();
        string strPassword =lststr.front();
        lststr.pop_front();
        //校验密码
       if(0==strcmp(pslr->m_szPassword,strPassword.c_str())){
           //密码正确
           slr.m_szResult=_login_success;
           slr.m_userid=_atoi64(strUserId.c_str());
       }
    }

    //发送回复
    m_pTCPnet->sendData(socket,(char*)&slr,sizeof (slr));
}

void TCPkernal::getfilelistrq(SOCKET socket, char *szbuf)
{
    //获取当前用户的文件列表
    STRU_GETFILELIST_RQ *psgr=(STRU_GETFILELIST_RQ*)szbuf;
    char szsql[SQLLEN];
    list<string> lststr;
    STRU_GETFILELIST_RS sgr;
    sgr.m_ntype=_deafult_protocol_getfilelist_rs;

    sprintf(szsql,"select f_name,f_size,f_uploadtime from myview where u_id=%lld;"
            ,psgr->m_userid);
    m_sql->SelectMySql(szsql,3,lststr);
    int i=0;

    while(lststr.size()>0){
        string strFilename=lststr.front();
        lststr.pop_front();
        string strFileSize=lststr.front();
        lststr.pop_front();
        string strFileUpLoadTime=lststr.front();
        lststr.pop_front();

        strcpy(sgr.m_aryFileInfo[i].m_szFilseName,strFilename.c_str());
        sgr.m_aryFileInfo[i].m_filesize=_atoi64(strFileSize.c_str());
        strcpy(sgr.m_aryFileInfo[i].m_szFileUploadTime,strFileUpLoadTime.c_str());

        i++;

        if(i==FILENUM || lststr.size()==0){
            //打包发送
            sgr.m_nFileNum=i;
            m_pTCPnet->sendData(socket,(char*)&sgr,sizeof (sgr));
            i=0;
            ZeroMemory(sgr.m_aryFileInfo,sizeof (sgr.m_aryFileInfo));

        }
    }



}
