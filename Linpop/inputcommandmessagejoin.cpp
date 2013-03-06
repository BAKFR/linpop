#include "inputcommandmessagejoin.h"

InputCommandMessageJoin::InputCommandMessageJoin()
{
}

InputCommandMessageJoin::InputCommandMessageJoin(const InputCommandMessageJoin& ref)
{
    *this = ref;
}

bool InputCommandMessageJoin::execute()
{
    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    QString input_client_username = this->getProtocolCommandParameter().getListProtocolCommandParamUser().at(0).getUsername();

    if (conv_win) {
        this->ptrInputNetworkClient->setUsername(input_client_username);
        conv_win->addChatContact(this->ptrInputNetworkClient);
        return true;
    }
    return false;
}

ProtocolCommand* InputCommandMessageJoin::clone()
{
    return new InputCommandMessageJoin(*this);
}
