#ifndef TCPKERNAL_H
#define TCPKERNAL_H

#include "PACKDEF.h"
#include "IKernal.h"
#include "CMySql.h"
#include <QDebug>

struct stru_uploadfileinfo{
    long long m_fileId;
    long long m_userId;
    long long m_filesize;//文件大小
    long long m_filepos;
    FILE* m_pfile; //文件指针
};
class TCPkernal:public IKernal
{
private:
    TCPkernal();
    ~TCPkernal();
public:
    bool open();
     void close();
    void dealData(SOCKET socket,char* szbuf);
    static TCPkernal* getKernal(){
        return m_kernal;
    };
public:
    void registerrq(SOCKET socket,char* szbuf);
    void loginrq(SOCKET socket,char* szbuf);
    void getfilelistrq(SOCKET socket,char* szbuf);
    void uploadfileinforq(SOCKET socket,char* szbuf);
    void uploadfileblockforq(SOCKET socket,char* szbuf);
private:
    INet *m_pTCPnet;
    CMySql *m_sql;
    static TCPkernal* m_kernal;
    char m_szSystemPath[MAX_PATH];
    std::list<stru_uploadfileinfo*> m_lstUpLoadFileInfo;
};

#endif // TCPKERNAL_
