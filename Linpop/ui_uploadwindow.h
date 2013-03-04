/********************************************************************************
** Form generated from reading UI file 'uploadwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWINDOW_H
#define UI_UPLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_UploadWindow
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *UploadWindow)
    {
        if (UploadWindow->objectName().isEmpty())
            UploadWindow->setObjectName(QStringLiteral("UploadWindow"));
        UploadWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(UploadWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(UploadWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), UploadWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UploadWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(UploadWindow);
    } // setupUi

    void retranslateUi(QDialog *UploadWindow)
    {
        UploadWindow->setWindowTitle(QApplication::translate("UploadWindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class UploadWindow: public Ui_UploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWINDOW_H
