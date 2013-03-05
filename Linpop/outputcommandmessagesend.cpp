#include "ouputcommandmessagesend.h"


OutputCommandMessageSend::OutputCommandMessageSend()
{
}

OutputCommandMessageSend::OutputCommandMessageSend(const OutputCommandMessageSend &ref)
{
    *this = ref;
}

bool OutputCommandMessageSend::execute()
{
    if (this->ptrOutputNetworkClient != NULL)
    {
        this->ptrOutputNetworkClient->getTcpSocket()->write("");
        return true;
    }
    qDebug() << "We can't send SEND cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessageSend::clone()
{
    return new OutputCommandMessageSend(*this);
}
