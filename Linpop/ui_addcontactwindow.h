/********************************************************************************
** Form generated from reading UI file 'addcontactwindow.ui'
**
** Created: Tue Mar 5 03:33:30 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACTWINDOW_H
#define UI_ADDCONTACTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddContactWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *user_name;
    QLineEdit *ip;
    QPushButton *addContact;

    void setupUi(QMainWindow *AddContactWindow)
    {
        if (AddContactWindow->objectName().isEmpty())
            AddContactWindow->setObjectName(QString::fromUtf8("AddContactWindow"));
        AddContactWindow->resize(299, 157);
        centralwidget = new QWidget(AddContactWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(70, 0, 221, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 50, 66, 17));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 80, 66, 17));
        user_name = new QLineEdit(centralwidget);
        user_name->setObjectName(QString::fromUtf8("user_name"));
        user_name->setGeometry(QRect(80, 50, 201, 27));
        ip = new QLineEdit(centralwidget);
        ip->setObjectName(QString::fromUtf8("ip"));
        ip->setGeometry(QRect(80, 80, 201, 27));
        addContact = new QPushButton(centralwidget);
        addContact->setObjectName(QString::fromUtf8("addContact"));
        addContact->setGeometry(QRect(130, 120, 98, 27));
        AddContactWindow->setCentralWidget(centralwidget);

        retranslateUi(AddContactWindow);

        QMetaObject::connectSlotsByName(AddContactWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AddContactWindow)
    {
        AddContactWindow->setWindowTitle(QApplication::translate("AddContactWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddContactWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt; font-weight:600; text-decoration: underline;\">Add Contact</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("AddContactWindow", "Name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddContactWindow", "Ip:", 0, QApplication::UnicodeUTF8));
        user_name->setText(QString());
        addContact->setText(QApplication::translate("AddContactWindow", "Add Contact", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddContactWindow: public Ui_AddContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTWINDOW_H
