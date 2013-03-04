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
    return ptrOutputNetworkClient->getTcpSocket()->write((QString("ACCEPTFILE\01") + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID()
                                                          + "\01" + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText())
                                                         .toUtf8()) > 0;

    return true;
}

ProtocolCommand *OutputCommandMessageAcceptFile::clone()
{
    return new OutputCommandMessageAcceptFile(*this);
}
