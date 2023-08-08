#include "tcpkernal.h"

TCPKernal::TCPKernal(QObject *parent) : QObject(parent)
{
    m_pNet=new TCPNet(this);
}

TCPKernal::~TCPKernal(){
    delete m_pNet;
    m_pNet=0;
}

bool TCPKernal::open(const char *ip, short sport)
{
    if(!m_pNet->connectServer(ip,sport))
        return false;
    return true;
}

void TCPKernal::close(const char *err)
{
    m_pNet->disconnectServer("close success");

}

bool TCPKernal::sendData(const char *szbuf, int nlen)
{
    if(!m_pNet->sendData(szbuf,nlen))
        return false;
    return true;

}

void TCPKernal::dealData(const char* szbuf)
{
   // const char* newszbuf=szbuf;

    switch (*szbuf) {
    case _deafult_protocol_regisiter_rs:
        emit sigalregister(szbuf);
        break;
    }

}
