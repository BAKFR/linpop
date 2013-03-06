#include "addcontactchatwindow.h"
#include "ui_addcontactchatwindow.h"
#include "contactwindow.h"
#include "networkobject.h"
#include <QMessageBox>
#include <QList>

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

void AddContactChatWindow::addAllConversationMemberInCommandParameter(ProtocolCommandParameter &p)
{
    int i = 0;
    QList<NetworkClient *> listClientInConversation = this->cw->getListClient();
    NetworkClient *cur;

    while (i < listClientInConversation.size())
    {
        cur = listClientInConversation.at(i);
        //username puis ip
        p.addParamCommandUser(ProtocolCommandParamUser(cur->getUsername(), cur->getIP()));
        i++;
    }
}

void AddContactChatWindow::on_bAddContact_clicked()
{
    NetworkClient *newclient = this->cw->getContactWindow()->createAndConnectNetworkClientOnIP(ui->ip->text());
    if (newclient != NULL)
    {
        newclient->setUsername(ui->user_name->text());
        ProtocolCommand *command_invite = this->cw->getContactWindow()->getNetworkObject()->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_INVITATION, newclient);
        ProtocolCommandParameter p;
        p.addParamCommandConv(ProtocolCommandParamConv(this->cw->getIDConv()));
        p.addParamCommandUser(ProtocolCommandParamUser(this->cw->getContactWindow()->getLogin(), "NO-NEED"));
        addAllConversationMemberInCommandParameter(p);
        command_invite->setProtocolCommandParameter(p);
        if (this->cw->getContactWindow()->getNetworkObject()->getProtocolInterpretor().executeCommand(command_invite))
        {
            return;
        }
    }
    QMessageBox::warning(this, "Contact unreachable", "Unable to reach contact. Check the ip adress before trying connecting again.");
    this->close();
}
