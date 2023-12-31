#ifndef WIDGET_H
#define WIDGET_H
#include "windows.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    bool threadFlag;



private:
    Ui::Widget *ui;
    HANDLE hThread;


private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

public slots:
    void receiveI(int i);
signals:
    void sendI(int);

};
#endif // WIDGET_H
