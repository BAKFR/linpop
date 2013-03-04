/********************************************************************************
** Form generated from reading UI file 'uploadwindow.ui'
**
** Created: Mon Mar 4 15:56:09 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPLOADWINDOW_H
#define UI_UPLOADWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UploadWindow
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLabel *label_fileName;

    void setupUi(QDialog *UploadWindow)
    {
        if (UploadWindow->objectName().isEmpty())
            UploadWindow->setObjectName(QString::fromUtf8("UploadWindow"));
        UploadWindow->resize(400, 300);
        buttonBox = new QDialogButtonBox(UploadWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);
        pushButton = new QPushButton(UploadWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 140, 83, 25));
        horizontalLayoutWidget = new QWidget(UploadWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 10, 361, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        label_fileName = new QLabel(horizontalLayoutWidget);
        label_fileName->setObjectName(QString::fromUtf8("label_fileName"));
        QFont font1;
        font1.setBold(false);
        font1.setWeight(50);
        label_fileName->setFont(font1);

        horizontalLayout_2->addWidget(label_fileName);


        retranslateUi(UploadWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), UploadWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), UploadWindow, SLOT(reject()));

        QMetaObject::connectSlotsByName(UploadWindow);
    } // setupUi

    void retranslateUi(QDialog *UploadWindow)
    {
        UploadWindow->setWindowTitle(QApplication::translate("UploadWindow", "Upload", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("UploadWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("UploadWindow", "File:", 0, QApplication::UnicodeUTF8));
        label_fileName->setText(QApplication::translate("UploadWindow", "????", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UploadWindow: public Ui_UploadWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPLOADWINDOW_H
