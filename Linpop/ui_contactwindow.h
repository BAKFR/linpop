/********************************************************************************
** Form generated from reading UI file 'contactwindow.ui'
**
** Created: Mon Mar 4 15:55:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWINDOW_H
#define UI_CONTACTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContactWindow)
    {
        if (ContactWindow->objectName().isEmpty())
            ContactWindow->setObjectName(QString::fromUtf8("ContactWindow"));
        ContactWindow->resize(800, 600);
        menubar = new QMenuBar(ContactWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        ContactWindow->setMenuBar(menubar);
        centralwidget = new QWidget(ContactWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        ContactWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ContactWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ContactWindow->setStatusBar(statusbar);

        retranslateUi(ContactWindow);

        QMetaObject::connectSlotsByName(ContactWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ContactWindow)
    {
        ContactWindow->setWindowTitle(QApplication::translate("ContactWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactWindow: public Ui_ContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWINDOW_H
