#include "inputcommandmessagedeconnection.h"
#include "networkobject.h"

InputCommandMessageDeconnection::InputCommandMessageDeconnection()
{
}

InputCommandMessageDeconnection::InputCommandMessageDeconnection(const InputCommandMessageDeconnection& ref)
{
    *this = ref;
}

bool InputCommandMessageDeconnection::execute()
{
    ConversationWindow *conv_win = ptrContactWindow
            ->getConvById(protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID());
    if (conv_win) {

        conv_win->rmChatContact(ptrInputNetworkClient);

        if (!ptrContactWindow->hasConvByClient(ptrInputNetworkClient)) {
            ptrContactWindow->getNetworkObject()->rmNetworkClient(ptrInputNetworkClient);
            ptrInputNetworkClient = NULL;
        }

        return true;
    } else {
        qDebug() << "ERROR: we receive msg from a unknown ";
        return false;
    }
}

ProtocolCommand *InputCommandMessageDeconnection::clone()
{
    return new InputCommandMessageDeconnection(*this);
}
