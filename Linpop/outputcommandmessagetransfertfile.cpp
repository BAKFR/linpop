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
    return ptrOutputNetworkClient->getTcpSocket()->write((QString("FILE\01") + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
                                                          + "\01" + QString::number(protocolCommandParameter.getListProtocolCommandParamFile().at(0).getSize())
                                                          + "\01" + protocolCommandParameter.getListProtocolCommandParamFile().at(0).getName()).toUtf8()) > 0;
}

ProtocolCommand *OutputCommandMessageTransfertFile::clone()
{
    return new OutputCommandMessageTransfertFile(*this);
}

