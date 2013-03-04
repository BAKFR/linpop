/********************************************************************************
** Form generated from reading UI file 'addcontactwindow.ui'
**
** Created: Mon Mar 4 15:54:59 2013
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
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AddContactWindow
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddContactWindow)
    {
        if (AddContactWindow->objectName().isEmpty())
            AddContactWindow->setObjectName(QString::fromUtf8("AddContactWindow"));
        AddContactWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddContactWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(290, 20, 81, 241));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(AddContactWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddContactWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddContactWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddContactWindow);
    } // setupUi

    void retranslateUi(QDialog *AddContactWindow)
    {
        AddContactWindow->setWindowTitle(QApplication::translate("AddContactWindow", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddContactWindow: public Ui_AddContactWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTWINDOW_H
