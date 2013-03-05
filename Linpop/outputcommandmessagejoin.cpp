#include "outputcommandmessagejoin.h"

OutputCommandMessageJoin::OutputCommandMessageJoin()
{
}

OutputCommandMessageJoin::OutputCommandMessageJoin(const OutputCommandMessageJoin&ref)
{
    *this = ref;
}

bool OutputCommandMessageJoin::execute()
{
    QString command = QString("JOIN") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()+"\r\n";
    return ptrOutputNetworkClient->getTcpSocket()->write(command.toUtf8()) > 0;
}

ProtocolCommand *OutputCommandMessageJoin::clone()
{
    return new OutputCommandMessageJoin(*this);
}
