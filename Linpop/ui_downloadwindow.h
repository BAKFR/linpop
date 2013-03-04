/********************************************************************************
** Form generated from reading UI file 'downloadwindow.ui'
**
** Created: Mon Mar 4 15:55:28 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DOWNLOADWINDOW_H
#define UI_DOWNLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_DownloadWindow
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DownloadWindow)
    {
        if (DownloadWindow->objectName().isEmpty())
            DownloadWindow->setObjectName(QString::fromUtf8("DownloadWindow"));
        DownloadWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(DownloadWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DownloadWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), DownloadWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DownloadWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(DownloadWindow);
    } // setupUi

    void retranslateUi(QDialog *DownloadWindow)
    {
        DownloadWindow->setWindowTitle(QApplication::translate("DownloadWindow", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DownloadWindow: public Ui_DownloadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DOWNLOADWINDOW_H
