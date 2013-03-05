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
    return ptrOutputNetworkClient->getTcpSocket()->write((QString("FILE") + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
                                                          + ProtocolCommand::separator + QString::number(protocolCommandParameter.getListProtocolCommandParamFile().at(0).getSize())
                                                          + ProtocolCommand::separator + protocolCommandParameter.getListProtocolCommandParamFile().at(0).getName()
                                                          + "\r\n").toUtf8()) > 0;
}

ProtocolCommand *OutputCommandMessageTransfertFile::clone()
{
    return new OutputCommandMessageTransfertFile(*this);
}

