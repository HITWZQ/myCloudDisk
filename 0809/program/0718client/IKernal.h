#ifndef IKERNAL_H
#define IKERNAL_H
class IKernal
{
public:
    IKernal(){}
    virtual ~IKernal(){}
public:
   virtual bool open(const char* ip = "127.0.0.1",short sport=8899)=0;
   virtual void close(const char* err)=0;
   virtual bool sendData(const char* szbuf,int nlen)=0;
   virtual void dealData(const char* szbuf)=0;

};


#endif // IKERNAL_H
