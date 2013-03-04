#include "inputcommandmessageinvitation.h"

InputCommandMessageInvitation::InputCommandMessageInvitation()
{
}

InputCommandMessageInvitation::InputCommandMessageInvitation(const InputCommandMessageInvitation &ref)
{
    *this = ref;
}

bool InputCommandMessageInvitation::execute()
{
    return true;
}

ProtocolCommand *InputCommandMessageInvitation::clone()
{
    return new InputCommandMessageInvitation(*this);
}
