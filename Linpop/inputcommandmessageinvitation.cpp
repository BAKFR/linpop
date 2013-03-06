#include "inputcommandmessageinvitation.h"
#include "protocolcommand.h"
#include "networkobject.h"
#include "protocolcommandtype.h"
#include "protocolcommandparameter.h"
#include "conversationwindow.h"
#include "protocolinterpretor.h"
#include "contactwindow.h"

InputCommandMessageInvitation::InputCommandMessageInvitation()
{
}

InputCommandMessageInvitation::InputCommandMessageInvitation(const InputCommandMessageInvitation &ref)
{
    *this = ref;
}

void InputCommandMessageInvitation::findAndAssociateTheUserNameOfTheInputClient(QList<ProtocolCommandParamUser> &list, NetworkClient *networkClient)
{
    /*int i = 0;
    while (i < list.size())
    {
        if (list.at(i).getIP() == networkClient->getIP())
        {
            networkClient->setUsername(list.at(i).getUsername());
        }
        i++;
    }*/
    networkClient->setUsername(list.at(0).getUsername());
}

//A verifier...
void InputCommandMessageInvitation::broadcastCommandJoin(QList<ProtocolCommandParamUser> &list, ProtocolCommand* command_join)
{
    ProtocolCommand *command_join_clone = command_join->clone();
    ProtocolCommand *temp = NULL;
    QString ip_client_to_notify_join;
    NetworkClient *remote_client_to_notify_join = NULL;
    if (this->ptrContactWindow->getNetworkObject()->getProtocolInterpretor().executeCommand(command_join))
    {
        int i = 1;
        while (i < list.size())
        {
            ip_client_to_notify_join = list.at(i).getIP();
            remote_client_to_notify_join = this->getContactWindow()->createAndConnectNetworkClientOnIP(ip_client_to_notify_join);
            if (remote_client_to_notify_join != NULL)
            {
                temp = command_join_clone->clone();
                remote_client_to_notify_join->setUsername(list.at(i).getUsername());
                command_join_clone->setOutputNetworkClient(remote_client_to_notify_join);
                this->ptrContactWindow->getNetworkObject()->getProtocolInterpretor().executeCommand(command_join_clone);
                command_join_clone = temp;
            }
            i++;
        }
    }
}

bool InputCommandMessageInvitation::execute()
{
    ProtocolInterpretor &protocolInterpretor = this->ptrContactWindow->getNetworkObject()->getProtocolInterpretor();
    ProtocolCommandParameter p;
    QString id_conv = this->getProtocolCommandParameter().getListProtocolCommandParamConv().at(0).getConvID();
    ProtocolCommand* command = protocolInterpretor.createOutputCommand(COMMAND_MESSAGE_JOIN, this->ptrInputNetworkClient);

    findAndAssociateTheUserNameOfTheInputClient(this->getProtocolCommandParameter().getListProtocolCommandParamUser() ,this->ptrInputNetworkClient);
    p.addParamCommandConv(ProtocolCommandParamConv(id_conv));
    p.addParamCommandUser(ProtocolCommandParamUser(this->getContactWindow()->getLogin(), QString("NO-NEED")));
    command->setProtocolCommandParameter(p);
    broadcastCommandJoin(this->getProtocolCommandParameter().getListProtocolCommandParamUser(), command);
    ConversationWindow *conversationWindow = this->ptrContactWindow->createEmptyConversationWindow();
    conversationWindow->setIDConv(id_conv);
    conversationWindow->addChatContact(this->ptrInputNetworkClient);
    conversationWindow->show();
    return true;
}

ProtocolCommand *InputCommandMessageInvitation::clone()
{
    return new InputCommandMessageInvitation(*this);
}
