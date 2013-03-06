#include "addcontactchatwindow.h"
#include "ui_addcontactchatwindow.h"


AddContactChatWindow::AddContactChatWindow(ConversationWindow *_cw, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddContactChatWindow)
{
    ui->setupUi(this);
    this->cw = _cw;
}

AddContactChatWindow::~AddContactChatWindow()
{
    delete ui;
}

void AddContactChatWindow::on_bAddContact_clicked()
{
    this->close();
}
