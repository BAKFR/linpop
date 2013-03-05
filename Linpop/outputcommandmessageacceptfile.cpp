#include "outputcommandmessageacceptfile.h"

OutputCommandMessageAcceptFile::OutputCommandMessageAcceptFile()
{
}

OutputCommandMessageAcceptFile::OutputCommandMessageAcceptFile(const OutputCommandMessageAcceptFile &ref)
{
    *this = ref;
}

bool OutputCommandMessageAcceptFile::execute()
{
    return ptrOutputNetworkClient->getTcpSocket()->write((QString("ACCEPTFILE"+ProtocolCommand::separator_telnet) + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
                                                          + ProtocolCommand::separator_telnet + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText())
                                                         .toUtf8()) > 0;

    return true;
}

ProtocolCommand *OutputCommandMessageAcceptFile::clone()
{
    return new OutputCommandMessageAcceptFile(*this);
}
