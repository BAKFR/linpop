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
    int i = 0;
    while (i < list.size())
    {
        if (list.at(i).getIP() == networkClient->getIP())
        {
            networkClient->setUsername(list.at(i).getUsername());
        }
        i++;
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
    command->setProtocolCommandParameter(p);
    if (protocolInterpretor.executeCommand(command))
    {
        ConversationWindow *conversationWindow = this->ptrContactWindow->createEmptyConversationWindow();
        conversationWindow->setIDConv(id_conv);
        conversationWindow->addChatContact(this->ptrInputNetworkClient);
        conversationWindow->show();
    }
    return true;
}

ProtocolCommand *InputCommandMessageInvitation::clone()
{
    return new InputCommandMessageInvitation(*this);
}
