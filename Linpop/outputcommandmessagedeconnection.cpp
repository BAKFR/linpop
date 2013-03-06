#include "outputcommandmessagedeconnection.h"
#include "networkclient.h"

#include <QDebug>

OutputCommandMessageDeconnection::OutputCommandMessageDeconnection()
{
}

OutputCommandMessageDeconnection::OutputCommandMessageDeconnection(const OutputCommandMessageDeconnection &ref)
{
    *this = ref;
}

bool OutputCommandMessageDeconnection::execute()
{
    if (this->ptrOutputNetworkClient != NULL)
    {
      QString tmp = QString("DISCONNECT") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
        + "\r\n";
      this->ptrOutputNetworkClient->getTcpSocket()->write(tmp.toUtf8());
      return true;
    }
    qDebug() << "We can't send DISCONNECT cmd: no output client to send !";
    return false;}

ProtocolCommand *OutputCommandMessageDeconnection::clone()
{
    return new OutputCommandMessageDeconnection(*this);
}
