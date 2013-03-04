/********************************************************************************
** Form generated from reading UI file 'conversationwindow.ui'
**
** Created: Mon Mar 4 15:55:21 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSATIONWINDOW_H
#define UI_CONVERSATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConversationWindow
{
public:
    QWidget *centralwidget;
    QPushButton *uploadButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConversationWindow)
    {
        if (ConversationWindow->objectName().isEmpty())
            ConversationWindow->setObjectName(QString::fromUtf8("ConversationWindow"));
        ConversationWindow->resize(800, 600);
        centralwidget = new QWidget(ConversationWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName(QString::fromUtf8("uploadButton"));
        uploadButton->setGeometry(QRect(250, 210, 321, 131));
        QFont font;
        font.setPointSize(36);
        uploadButton->setFont(font);
        ConversationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConversationWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ConversationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ConversationWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        ConversationWindow->setStatusBar(statusbar);

        retranslateUi(ConversationWindow);

        QMetaObject::connectSlotsByName(ConversationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConversationWindow)
    {
        ConversationWindow->setWindowTitle(QApplication::translate("ConversationWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        uploadButton->setText(QApplication::translate("ConversationWindow", "UPLOAD", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConversationWindow: public Ui_ConversationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSATIONWINDOW_H
