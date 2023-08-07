#ifndef IKERNAL_H
#define IKERNAL_H

#include "INet.h"

class IKernal{

public:
    IKernal(){

    };
    virtual ~IKernal(){

    };

public:
    virtual bool open()=0;
    virtual void close()=0;
    virtual void dealData(SOCKET socket,char* szbuf)=0;
};

#endif // IKERNAL_H
