/********************************************************************************
** Form generated from reading UI file 'historywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTORYWINDOW_H
#define UI_HISTORYWINDOW_H

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

class Ui_HistoryWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HistoryWindow)
    {
        if (HistoryWindow->objectName().isEmpty())
            HistoryWindow->setObjectName(QStringLiteral("HistoryWindow"));
        HistoryWindow->resize(800, 600);
        menubar = new QMenuBar(HistoryWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        HistoryWindow->setMenuBar(menubar);
        centralwidget = new QWidget(HistoryWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        HistoryWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HistoryWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        HistoryWindow->setStatusBar(statusbar);

        retranslateUi(HistoryWindow);

        QMetaObject::connectSlotsByName(HistoryWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HistoryWindow)
    {
        HistoryWindow->setWindowTitle(QApplication::translate("HistoryWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class HistoryWindow: public Ui_HistoryWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTORYWINDOW_H
