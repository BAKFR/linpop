/********************************************************************************
** Form generated from reading UI file 'contactwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTACTWINDOW_H
#define UI_CONTACTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
            ContactWindow->setObjectName(QStringLiteral("ContactWindow"));
        ContactWindow->resize(800, 600);
        menubar = new QMenuBar(ContactWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        ContactWindow->setMenuBar(menubar);
        centralwidget = new QWidget(ContactWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ContactWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ContactWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ContactWindow->setStatusBar(statusbar);

        retranslateUi(ContactWindow);

        QMetaObject::connectSlotsByName(ContactWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ContactWindow)
    {
        ContactWindow->setWindowTitle(QApplication::translate("ContactWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ContactWindow: public Ui_ContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWINDOW_H
