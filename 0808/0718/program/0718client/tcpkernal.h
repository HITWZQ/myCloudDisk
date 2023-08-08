#ifndef TCPKERNAL_H
#define TCPKERNAL_H

#include <QObject>
#include "IKernal.h"
#include "tcpnet.h"
#include "packdef.h"
#include <QDebug>
class TCPKernal : public QObject,public IKernal
{
    Q_OBJECT
public:
    explicit TCPKernal(QObject *parent = nullptr);
    ~TCPKernal();
public:
    bool open(const char* ip = "127.0.0.1",short sport=8899);
    void close(const char* err);
    bool sendData(const char* szbuf,int nlen);
    void dealData(const char* szbuf);

signals:
    void sigalregister(const char* szbuf);
private:
    INet *m_pNet;

};

#endif // TCPKERNAL_H
