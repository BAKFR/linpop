#include "inputcommandmessageping.h"

InputCommandMessagePing::InputCommandMessagePing()
{
}

InputCommandMessagePing::InputCommandMessagePing(const InputCommandMessagePing &ref)
{
    *this = ref;
}

bool InputCommandMessagePing::execute()
{
    return true;
}

ProtocolCommand *InputCommandMessagePing::clone()
{
    return new InputCommandMessagePing(*this);
}
