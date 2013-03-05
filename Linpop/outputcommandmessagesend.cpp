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
	  QString tmp = QString("SEND") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
        + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText() + "\r\n";
	  this->ptrOutputNetworkClient->getTcpSocket()->write(tmp.toUtf8());
	  return true;
    }
    qDebug() << "We can't send SEND cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessageSend::clone()
{
    return new OutputCommandMessageSend(*this);
}
