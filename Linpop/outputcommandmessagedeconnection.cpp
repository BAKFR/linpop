#include "outputcommandmessagedeconnection.h"

OutputCommandMessageDeconnection::OutputCommandMessageDeconnection()
{
}

OutputCommandMessageDeconnection::OutputCommandMessageDeconnection(const OutputCommandMessageDeconnection &ref)
{
    *this = ref;
}

bool OutputCommandMessageDeconnection::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessageDeconnection::clone()
{
    return new OutputCommandMessageDeconnection(*this);
}
