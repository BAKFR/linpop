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
    qDebug() << "We can't send PONG cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessagePong::clone()
{
    return new OutputCommandMessagePong(*this);
}
