#include "protocolcommandparameter.h"

ProtocolCommandParameter::ProtocolCommandParameter()
{
}

QList<ProtocolCommandParamUser>& ProtocolCommandParameter::getListProtocolCommandParamUser()
{
    return this->listProtocolCommandParamUser;
}

QList<ProtocolCommandParamFile>& ProtocolCommandParameter::getListProtocolCommandParamFile()
{
    return this->listProtocolCommandParamFile;
}

QList<ProtocolCommandParamText>& ProtocolCommandParameter::getListProtocolCommandParamText()
{
    return this->listProtocolCommandParamText;
}

QList<ProtocolCommandParamConv>& ProtocolCommandParameter::getListProtocolCommandParamConv()
{
    return this->listProtocolCommandParamConv;
}

void ProtocolCommandParameter::addParamCommandUser(ProtocolCommandParamUser p)
{
    this->listProtocolCommandParamUser.append(p);
}

void ProtocolCommandParameter::addParamCommandFile(ProtocolCommandParamFile p)
{
    this->listProtocolCommandParamFile.append(p);
}

void ProtocolCommandParameter::addParamCommandText(ProtocolCommandParamText p)
{
    this->listProtocolCommandParamText.append(p);
}

void ProtocolCommandParameter::addParamCommandConv(ProtocolCommandParamConv p)
{
    this->listProtocolCommandParamConv.append(p);
}
