#include "addcontactchatwindow.h"
#include "ui_addcontactchatwindow.h"

AddContactChatWindow::AddContactChatWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContactChatWindow)
{
    ui->setupUi(this);
}

AddContactChatWindow::~AddContactChatWindow()
{
    delete ui;
}
