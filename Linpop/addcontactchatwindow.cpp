#include "addcontactchatwindow.h"
#include "ui_addcontactchatwindow.h"
#include "contactwindow.h"

#include <QMessageBox>


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
    NetworkClient *newclient = this->cw->getContactWindow()->createAndConnectNetworkClientOnIP(ui->ip->text());
    if (newclient != NULL)
    {
        newclient->setUsername(ui->user_name->text());
        this->cw->addChatContact(newclient);
    }
    else
        QMessageBox::warning(this, "Contact unreachable", "Unable to reach contact. Check the ip adress before trying connecting again.");
    this->close();
}
