#include "inputcommandmessageping.h"
#include "protocolcommand.h"
#include "protocolcommandtype.h"
#include "networkobject.h"

InputCommandMessagePing::InputCommandMessagePing()
{
}

InputCommandMessagePing::InputCommandMessagePing(const InputCommandMessagePing &ref)
{
    *this = ref;
}

bool InputCommandMessagePing::execute()
{
    qDebug()<<"Une commande ping vient d'etre recue !!";
    ProtocolCommand *commandPong = this->getContactWindow()->getNetworkObject()->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_PONG, this->getInputNetworkClient());
    this->getContactWindow()->getNetworkObject()->getProtocolInterpretor().executeCommand(commandPong);
    return true;
}

ProtocolCommand *InputCommandMessagePing::clone()
{
    return new InputCommandMessagePing(*this);
}
