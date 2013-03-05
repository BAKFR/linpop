#include "outputcommandmessagetransfertfile.h"

OutputCommandMessageTransfertFile::OutputCommandMessageTransfertFile()
{
}

OutputCommandMessageTransfertFile::OutputCommandMessageTransfertFile(const OutputCommandMessageTransfertFile &ref)
{
    *this = ref;
}

bool OutputCommandMessageTransfertFile::execute()
{
    return ptrOutputNetworkClient->getTcpSocket()->write((QString("FILE"+ProtocolCommand::separator_telnet) + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
                                                          + ProtocolCommand::separator_telnet + QString::number(protocolCommandParameter.getListProtocolCommandParamFile().at(0).getSize())
                                                          + ProtocolCommand::separator_telnet + protocolCommandParameter.getListProtocolCommandParamFile().at(0).getName()).toUtf8()) > 0;
}

ProtocolCommand *OutputCommandMessageTransfertFile::clone()
{
    return new OutputCommandMessageTransfertFile(*this);
}

