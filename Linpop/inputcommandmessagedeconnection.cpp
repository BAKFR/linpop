#include "inputcommandmessagedeconnection.h"

InputCommandMessageDeconnection::InputCommandMessageDeconnection()
{
}

InputCommandMessageDeconnection::InputCommandMessageDeconnection(const InputCommandMessageDeconnection& ref)
{
    *this = ref;
}

bool InputCommandMessageDeconnection::execute()
{
    return true;
}

ProtocolCommand *InputCommandMessageDeconnection::clone()
{
    return new InputCommandMessageDeconnection(*this);
}
