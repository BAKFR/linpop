/********************************************************************************
** Form generated from reading UI file 'contactwindow.ui'
**
** Created: Tue Mar 5 03:33:30 2013
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
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ContactWindow
{
public:
    QAction *actionDisconnect;
    QAction *actionExit;
    QAction *actionAdd_Contact;
    QAction *actionSettings;
    QAction *actionHistory;
    QWidget *centralwidget;
    QListWidget *listContact;
    QPushButton *boutonAddContact;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuOptions;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ContactWindow)
    {
        if (ContactWindow->objectName().isEmpty())
            ContactWindow->setObjectName(QString::fromUtf8("ContactWindow"));
        ContactWindow->resize(236, 331);
        actionDisconnect = new QAction(ContactWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        actionDisconnect->setEnabled(true);
        actionExit = new QAction(ContactWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd_Contact = new QAction(ContactWindow);
        actionAdd_Contact->setObjectName(QString::fromUtf8("actionAdd_Contact"));
        actionSettings = new QAction(ContactWindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionHistory = new QAction(ContactWindow);
        actionHistory->setObjectName(QString::fromUtf8("actionHistory"));
        centralwidget = new QWidget(ContactWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listContact = new QListWidget(centralwidget);
        QIcon icon;
        icon.addFile(QString::fromUtf8("../loginWindow.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listContact);
        __qlistwidgetitem->setIcon(icon);
        listContact->setObjectName(QString::fromUtf8("listContact"));
        listContact->setGeometry(QRect(40, 10, 181, 271));
        boutonAddContact = new QPushButton(centralwidget);
        boutonAddContact->setObjectName(QString::fromUtf8("boutonAddContact"));
        boutonAddContact->setGeometry(QRect(0, 250, 31, 27));
        ContactWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ContactWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 236, 25));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menubar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        ContactWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ContactWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ContactWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionDisconnect);
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionAdd_Contact);
        menuOptions->addAction(actionSettings);
        menuOptions->addAction(actionHistory);

        retranslateUi(ContactWindow);

        QMetaObject::connectSlotsByName(ContactWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ContactWindow)
    {
        ContactWindow->setWindowTitle(QApplication::translate("ContactWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionDisconnect->setText(QApplication::translate("ContactWindow", "Disconnect", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("ContactWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAdd_Contact->setText(QApplication::translate("ContactWindow", "Add Contact", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("ContactWindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionHistory->setText(QApplication::translate("ContactWindow", "History", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listContact->isSortingEnabled();
        listContact->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listContact->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ContactWindow", "test 127.0.0.1", 0, QApplication::UnicodeUTF8));
        listContact->setSortingEnabled(__sortingEnabled);

        boutonAddContact->setText(QApplication::translate("ContactWindow", "+", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("ContactWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("ContactWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ContactWindow: public Ui_ContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTACTWINDOW_H
