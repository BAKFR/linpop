#include "ouputcommandmessagesend.h"


OutputCommandMessageSend::OutputCommandMessageSend()
{
}

OutputCommandMessageSend::OutputCommandMessageSend(const OutputCommandMessageSend &ref)
{
    *this = ref;
}

bool OutputCommandMessageSend::execute()
{
    if (this->ptrOutputNetworkClient != NULL)
    {
        std::string tmp = "SEND\01" + protocolCommandParameter.getListProtocolCommandParamConv().at(0).getConvID().toStdString() + "\01" + protocolCommandParameter.getListProtocolCommandParamText().at(0).getText().toStdString();
        this->ptrOutputNetworkClient->getTcpSocket()->write(tmp.c_str());
        return true;
    }
    qDebug() << "We can't send SEND cmd: no output client to send !";
    return false;
}

ProtocolCommand *OutputCommandMessageSend::clone()
{
    return new OutputCommandMessageSend(*this);
}
