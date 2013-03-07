#include "outputcommandmessageaudio.h"
#include "networkclient.h"
#include <QDebug>

OutputCommandMessageAudio::OutputCommandMessageAudio()
{
}

OutputCommandMessageAudio::OutputCommandMessageAudio(const OutputCommandMessageAudio &ref)
{
    *this = ref;
}

bool OutputCommandMessageAudio::execute()
{
    if (this->ptrOutputNetworkClient != NULL)
    {
      QString tmp = QString("AUDIO") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
        + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText() + "\r\n";
	  this->ptrOutputNetworkClient->getTcpSocket()->write(tmp.toUtf8());
	  return true;
    }
    qDebug() << "We can't send Audio cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessageAudio::clone()
{
    return new OutputCommandMessageAudio(*this);
}
