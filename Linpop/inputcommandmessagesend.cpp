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
    return true;
}

ProtocolCommand* InputCommandMessageSend::clone()
{
    return new InputCommandMessageSend(*this);
}
