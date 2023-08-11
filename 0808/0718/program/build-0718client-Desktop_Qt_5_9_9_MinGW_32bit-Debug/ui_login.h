/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label;
    QLineEdit *registerTel;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *registerUser;
    QLineEdit *registerPasswrd;
    QWidget *tab_2;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *loginPasswrd;
    QLineEdit *loignUser;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(452, 374);
        tabWidget = new QTabWidget(login);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(40, 60, 371, 221));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 40, 81, 18));
        registerTel = new QLineEdit(tab);
        registerTel->setObjectName(QStringLiteral("registerTel"));
        registerTel->setGeometry(QRect(130, 40, 141, 25));
        registerTel->setEchoMode(QLineEdit::Normal);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 81, 18));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 120, 81, 20));
        registerUser = new QLineEdit(tab);
        registerUser->setObjectName(QStringLiteral("registerUser"));
        registerUser->setGeometry(QRect(130, 80, 141, 25));
        registerPasswrd = new QLineEdit(tab);
        registerPasswrd->setObjectName(QStringLiteral("registerPasswrd"));
        registerPasswrd->setGeometry(QRect(130, 120, 141, 25));
        registerPasswrd->setEchoMode(QLineEdit::Password);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 90, 81, 20));
        label_7 = new QLabel(tab_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 50, 81, 18));
        loginPasswrd = new QLineEdit(tab_2);
        loginPasswrd->setObjectName(QStringLiteral("loginPasswrd"));
        loginPasswrd->setGeometry(QRect(130, 90, 141, 25));
        loginPasswrd->setEchoMode(QLineEdit::Password);
        loignUser = new QLineEdit(tab_2);
        loignUser->setObjectName(QStringLiteral("loignUser"));
        loignUser->setGeometry(QRect(130, 50, 141, 25));
        tabWidget->addTab(tab_2, QString());
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 310, 112, 34));
        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(250, 310, 112, 34));

        retranslateUi(login);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QWidget *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Form", Q_NULLPTR));
        label->setText(QApplication::translate("login", "tel:", Q_NULLPTR));
        registerTel->setPlaceholderText(QApplication::translate("login", "\350\257\267\350\276\223\345\205\245\347\224\265\350\257\235\345\217\267\347\240\201", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "user:", Q_NULLPTR));
        label_5->setText(QApplication::translate("login", "password:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("login", "\346\263\250\345\206\214", Q_NULLPTR));
        label_6->setText(QApplication::translate("login", "password:", Q_NULLPTR));
        label_7->setText(QApplication::translate("login", "user:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "register", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("login", "login", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
