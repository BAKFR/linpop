#include "protocolcommandparamfile.h"

ProtocolCommandParamFile::ProtocolCommandParamFile(const QString &string, int size)
{
    this->name = name;
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
