/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created: Mon Mar 4 00:48:13 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralWidget;
    QLabel *luser_name;
    QLineEdit *user_name;
    QLabel *lpassword;
    QLineEdit *password;
    QPushButton *bConnexion;
    QPushButton *bCreateAccount;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(301, 345);
        centralWidget = new QWidget(LoginWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        luser_name = new QLabel(centralWidget);
        luser_name->setObjectName(QString::fromUtf8("luser_name"));
        luser_name->setGeometry(QRect(120, 0, 141, 41));
        user_name = new QLineEdit(centralWidget);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(50, 30, 201, 27));
        lpassword = new QLabel(centralWidget);
        lpassword->setObjectName(QString::fromUtf8("lpassword"));
        lpassword->setGeometry(QRect(110, 70, 66, 17));
        password = new QLineEdit(centralWidget);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(50, 90, 201, 31));
        bConnexion = new QPushButton(centralWidget);
        bConnexion->setObjectName(QString::fromUtf8("bConnexion"));
        bConnexion->setGeometry(QRect(90, 140, 121, 27));
        bCreateAccount = new QPushButton(centralWidget);
        bCreateAccount->setObjectName(QString::fromUtf8("bCreateAccount"));
        bCreateAccount->setGeometry(QRect(90, 230, 121, 27));
        LoginWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LoginWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 301, 25));
        LoginWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LoginWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        LoginWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LoginWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        LoginWindow->setStatusBar(statusBar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "LoginWindow", 0, QApplication::UnicodeUTF8));
        luser_name->setText(QApplication::translate("LoginWindow", "Name :", 0, QApplication::UnicodeUTF8));
        lpassword->setText(QApplication::translate("LoginWindow", "Password:", 0, QApplication::UnicodeUTF8));
        bConnexion->setText(QApplication::translate("LoginWindow", "Connexion", 0, QApplication::UnicodeUTF8));
        bCreateAccount->setText(QApplication::translate("LoginWindow", "New Account", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
