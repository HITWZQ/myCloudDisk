#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QDebug>
#include "IKernal.h"
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = nullptr);
    ~login();
    void setKernal(IKernal *pKernal){
        m_pKernal=pKernal;
    }

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

public slots:
    void slotregister(const char* szbuf);

private:
    Ui::login *ui;
    IKernal *m_pKernal;
};

#endif // LOGIN_H
