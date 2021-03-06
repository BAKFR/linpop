#include "inputcommandmessageping.h"
#include "protocolcommand.h"
#include "protocolcommandtype.h"
#include "networkobject.h"
#include "contactwindow.h"

InputCommandMessagePing::InputCommandMessagePing()
{
}

InputCommandMessagePing::InputCommandMessagePing(const InputCommandMessagePing &ref)
{
    *this = ref;
}

bool InputCommandMessagePing::execute()
{
    ProtocolCommand *commandPong = this->getContactWindow()->getNetworkObject()->getProtocolInterpretor().createOutputCommand(COMMAND_MESSAGE_PONG, this->getInputNetworkClient());
    this->getContactWindow()->getNetworkObject()->getProtocolInterpretor().executeCommand(commandPong);
    return true;
}

ProtocolCommand *InputCommandMessagePing::clone()
{
    return new InputCommandMessagePing(*this);
}
