/********************************************************************************
** Form generated from reading UI file 'addcontactchatwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDCONTACTCHATWINDOW_H
#define UI_ADDCONTACTCHATWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_AddContactChatWindow
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddContactChatWindow)
    {
        if (AddContactChatWindow->objectName().isEmpty())
            AddContactChatWindow->setObjectName(QStringLiteral("AddContactChatWindow"));
        AddContactChatWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(AddContactChatWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(AddContactChatWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), AddContactChatWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), AddContactChatWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(AddContactChatWindow);
    } // setupUi

    void retranslateUi(QDialog *AddContactChatWindow)
    {
        AddContactChatWindow->setWindowTitle(QApplication::translate("AddContactChatWindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class AddContactChatWindow: public Ui_AddContactChatWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDCONTACTCHATWINDOW_H
