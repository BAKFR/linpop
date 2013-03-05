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
    if (this->ptrOutputNetworkClient != NULL)
    {
        this->ptrOutputNetworkClient->getTcpSocket()->write("PONG\r\n");
        return true;
    }
    return false;
}

ProtocolCommand *OutputCommandMessagePong::clone()
{
    return new OutputCommandMessagePong(*this);
}
