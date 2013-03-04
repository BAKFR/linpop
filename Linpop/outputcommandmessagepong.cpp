#include "outputcommandmessagepong.h"

OutputCommandMessagePong::OutputCommandMessagePong()
{
}

OutputCommandMessagePong::OutputCommandMessagePong(const OutputCommandMessagePong &ref)
{
    *this = ref;
}

bool OutputCommandMessagePong::execute()
{
    return true;
}

ProtocolCommand *OutputCommandMessagePong::clone()
{
    return new OutputCommandMessagePong(*this);
}
