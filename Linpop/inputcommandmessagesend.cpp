#include "inputcommandmessagesend.h"

InputCommandMessageSend::InputCommandMessageSend()
{
}

InputCommandMessageSend::InputCommandMessageSend(const InputCommandMessageSend &ref)
{
    *this = ref;
}

bool InputCommandMessageSend::execute()
{
    QString message;

    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    message = (this->ptrInputNetworkClient->getUsername() + QString(" dit : ") + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText()).toUtf8();
    conv_win->AddText(message);
    return true;
}

ProtocolCommand* InputCommandMessageSend::clone()
{
    return new InputCommandMessageSend(*this);
}
