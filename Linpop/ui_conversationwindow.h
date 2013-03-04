/********************************************************************************
** Form generated from reading UI file 'conversationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERSATIONWINDOW_H
#define UI_CONVERSATIONWINDOW_H

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

class Ui_ConversationWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *ConversationWindow)
    {
        if (ConversationWindow->objectName().isEmpty())
            ConversationWindow->setObjectName(QStringLiteral("ConversationWindow"));
        ConversationWindow->resize(800, 600);
        menubar = new QMenuBar(ConversationWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        ConversationWindow->setMenuBar(menubar);
        centralwidget = new QWidget(ConversationWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ConversationWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(ConversationWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ConversationWindow->setStatusBar(statusbar);

        retranslateUi(ConversationWindow);

        QMetaObject::connectSlotsByName(ConversationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConversationWindow)
    {
        ConversationWindow->setWindowTitle(QApplication::translate("ConversationWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class ConversationWindow: public Ui_ConversationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSATIONWINDOW_H
