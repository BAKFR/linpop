#include "protocolcommandparamconv.h"
#include <QString>

ProtocolCommandParamConv::ProtocolCommandParamConv(QString string)
{
    this->convID = string;
}

void ProtocolCommandParamConv::setConvID(QString stringID)
{
    this->convID = stringID;
}

QString ProtocolCommandParamConv::getConvID() const
{
    return this->convID;
}
