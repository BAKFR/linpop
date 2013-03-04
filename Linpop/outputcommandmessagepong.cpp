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
    if (this->ptrInputNetworkClient != NULL)
    {
        this->ptrInputNetworkClient->getTcpSocket()->write("PONG");
    }
    return true;
}

ProtocolCommand *OutputCommandMessagePong::clone()
{
    return new OutputCommandMessagePong(*this);
}
