#include "outputcommandmessageping.h"

OutputCommandMessagePing::OutputCommandMessagePing()
{
}

OutputCommandMessagePing::OutputCommandMessagePing(const OutputCommandMessagePing &ref)
{
    *this = ref;
}

bool OutputCommandMessagePing::execute()
{
    return true;
}


ProtocolCommand *OutputCommandMessagePing::clone()
{
    return new OutputCommandMessagePing(*this);
}
