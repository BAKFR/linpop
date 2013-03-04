/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created: Mon Mar 4 15:55:35 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

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

class Ui_HistoryWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName(QString::fromUtf8("HistoryWindow"));
        HistoryWindow->resize(800, 600);
        menubar = new QMenuBar(HistoryWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        HistoryWindow->setMenuBar(menubar);
        centralwidget = new QWidget(HistoryWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        HistoryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HistoryWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HistoryWindow->setStatusBar(statusbar);

        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QApplication::translate("HistoryWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
