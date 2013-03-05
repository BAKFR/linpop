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
    if (this->ptrOutputNetworkClient != NULL)
    {
        this->ptrOutputNetworkClient->getTcpSocket()->write("PING");
    }
    return true;
}


ProtocolCommand *OutputCommandMessagePing::clone()
{
    return new OutputCommandMessagePing(*this);
}
