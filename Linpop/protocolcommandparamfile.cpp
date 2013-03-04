#include "protocolcommandparamfile.h"

ProtocolCommandParamFile::ProtocolCommandParamFile(QString string, int size, int port)
{
    this->name = name;
    this->port = port;
    this->size = size;
}


void ProtocolCommandParamFile::setName(QString name)
{
    this->name = name;
}

QString ProtocolCommandParamFile::getName()
{
    return name;
}

void ProtocolCommandParamFile::setSize(int size)
{
    this->size = size;
}

int ProtocolCommandParamFile::getSize()
{
    return this->size;
}

void ProtocolCommandParamFile::setPort(int port)
{
    this->port = port;
}

int ProtocolCommandParamFile::getPort()
{
    return this->port;
}
