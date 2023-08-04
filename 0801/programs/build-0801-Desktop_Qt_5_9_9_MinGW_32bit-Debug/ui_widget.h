/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLineEdit *lineEdit1;
    QLabel *label;
    QLineEdit *lineEdit2;
    QLineEdit *lineEdit3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 600);
        lineEdit1 = new QLineEdit(Widget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));
        lineEdit1->setGeometry(QRect(30, 100, 101, 21));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 100, 54, 12));
        lineEdit2 = new QLineEdit(Widget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setGeometry(QRect(220, 100, 113, 20));
        lineEdit3 = new QLineEdit(Widget);
        lineEdit3->setObjectName(QStringLiteral("lineEdit3"));
        lineEdit3->setGeometry(QRect(420, 100, 113, 20));
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(340, 100, 75, 23));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(230, 210, 112, 34));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "+", Q_NULLPTR));
        pushButton->setText(QApplication::translate("Widget", "=", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("Widget", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
