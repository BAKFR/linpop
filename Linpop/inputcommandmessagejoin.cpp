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

    if (conv_win) {
        conv_win->addChatContact(this->ptrInputNetworkClient);
        return true;
    }
    return false;
}

ProtocolCommand* InputCommandMessageJoin::clone()
{
    return new InputCommandMessageJoin(*this);
}
