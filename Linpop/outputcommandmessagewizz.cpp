#include "outputcommandmessagewizz.h"
#include "networkclient.h"
#include <QDebug>


OutputCommandMessageWizz::OutputCommandMessageWizz()
{
}

OutputCommandMessageWizz::OutputCommandMessageWizz(const OutputCommandMessageWizz &ref)
{
    *this = ref;
}

bool OutputCommandMessageWizz::execute()
{
    if (this->ptrOutputNetworkClient != NULL)
    {
      QString tmp = QString("WIZZ") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
        + "\r\n";
	  this->ptrOutputNetworkClient->getTcpSocket()->write(tmp.toUtf8());
	  return true;
    }
    qDebug() << "We can't send WIZZ cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessageWizz::clone()
{
    return new OutputCommandMessageWizz(*this);
}
