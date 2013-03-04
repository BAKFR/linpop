#include "outputcommandmessageinvitation.h"

OutputCommandMessageInvitation::OutputCommandMessageInvitation()
{
}

OutputCommandMessageInvitation::OutputCommandMessageInvitation(const OutputCommandMessageInvitation& ref)
{
    *this = ref;
}

bool OutputCommandMessageInvitation::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageInvitation::clone()
{
    return new OutputCommandMessageInvitation(*this);
}
