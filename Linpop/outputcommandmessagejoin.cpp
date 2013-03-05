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
    QString command = "JOIN" + ProtocolCommand::separator_telnet + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()+"\r\n";
    return ptrOutputNetworkClient->getTcpSocket()->write(command.toAscii()) > 0;
}

ProtocolCommand *OutputCommandMessageJoin::clone()
{
    return new OutputCommandMessageJoin(*this);
}
