#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tcpkernal.h"
#include "login.h"
#include <QTableWidgetItem>
#include<QFileDialog>
#include<QFile>
#include"md5.h"
#include <QDateTime>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

struct stru_uploadfileinfo{
    long long m_fileId;
    long long m_filesize;
    char m_szFileMD5[MAXNUM];
    char m_szFilseName[MAXNUM];
    FILE* m_pfile;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
public slots:
    void slotlogin(const char* szbuf);
    void slotgetfilelist(const char* szbuf);
    void slotuploadfileinfo(const char* szbuf);
private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
    IKernal *m_pKernal;
    login *m_plogin;
    long long m_userid;
    int m_nFileNum;
    std::list<stru_uploadfileinfo*> m_lstUpLoadFileInfo;
};
#endif // WIDGET_H
