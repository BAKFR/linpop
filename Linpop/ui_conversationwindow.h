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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

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
            ConversationWindow->setObjectName(QStringLiteral("ConversationWindow"));
        ConversationWindow->resize(800, 600);
        centralwidget = new QWidget(ConversationWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        uploadButton = new QPushButton(centralwidget);
        uploadButton->setObjectName(QStringLiteral("uploadButton"));
        uploadButton->setGeometry(QRect(250, 210, 321, 131));
        QFont font;
        font.setPointSize(36);
        uploadButton->setFont(font);
        ConversationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(ConversationWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        ConversationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(ConversationWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        ConversationWindow->setStatusBar(statusbar);

        retranslateUi(ConversationWindow);

        QMetaObject::connectSlotsByName(ConversationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ConversationWindow)
    {
        ConversationWindow->setWindowTitle(QApplication::translate("ConversationWindow", "MainWindow", 0));
        uploadButton->setText(QApplication::translate("ConversationWindow", "UPLOAD", 0));
    } // retranslateUi

};

namespace Ui {
    class ConversationWindow: public Ui_ConversationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERSATIONWINDOW_H
