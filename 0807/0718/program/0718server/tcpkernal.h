#ifndef TCPKERNAL_H
#define TCPKERNAL_H

#include "PACKDEF.h"
#include "IKernal.h"
#include "CMySql.h"
#include <QDebug>
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
private:
    INet *m_pTCPnet;
    CMySql *m_sql;
    static TCPkernal* m_kernal;
    char m_szSystemPath[MAX_PATH];
};

#endif // TCPKERNAL_
