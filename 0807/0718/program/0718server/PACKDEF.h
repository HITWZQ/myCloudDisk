#ifndef PACKDEF_H
#define PACKDEF_H

//协议
#define _default_protocol_base  10
//申请账号
#define _deafult_protocol_regisiter_rq  _default_protocol_base+1
#define _deafult_protocol_regisiter_rs  _default_protocol_base+2
//登录
#define _deafult_protocol_login_rq  _default_protocol_base+3
#define _deafult_protocol_login_rs  _default_protocol_base+4
//获取文件列表
#define _deafult_protocol_getfilelist_rq  _default_protocol_base+5
#define _deafult_protocol_getfilelist_rs  _default_protocol_base+6
//上传文件
#define _deafult_protocol_uploadfilefo_rq  _default_protocol_base+7
#define _deafult_protocol_uploadfilefo_rs  _default_protocol_base+8
//上传文件块
#define _deafult_protocol_uploadfileblock_rq  _default_protocol_base+9
#define _deafult_protocol_uploadfileblock_rs  _default_protocol_base+10

//协议包
#define MAXNUM 45
#define FILENUM 15
#define SQLLEN 300

#define _register_success 1
#define _register_err 0

#define _login_usernotexist 0
#define _login_passwd_err 1
#define _login_success 2

struct STRU_REGISTER_RQ{
    char m_ntype;
    long long m_tel;
    char m_szname[MAXNUM];
    char m_szPassword[MAXNUM];
};
struct STRU_REGISTER_RS{
    char m_ntype;
    char m_szResult;
};
struct STRU_LOGIN_RQ{
    char m_ntype;
    char m_szname[MAXNUM];
    char m_szPassword[MAXNUM];
};
struct STRU_LOGIN_RS{
    char m_ntype;
    char m_szResult;
    long long m_userid;
};
//获取文件列表
struct STRU_GETFILELIST_RQ{
    char m_ntype;
    long long m_userid;
};
struct FileInfo{
    char m_szFilseName[MAXNUM];
    long long m_filesize;
    char m_szFileUploadTime[MAXNUM];
};
struct STRU_GETFILELIST_RS{
    char m_ntype;
    int m_nFileNum;
    FileInfo m_aryFileInfo[FILENUM];

};




#endif // PACKDEF_H
