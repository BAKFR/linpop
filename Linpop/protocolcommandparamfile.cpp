#include "protocolcommandparamfile.h"

ProtocolCommandParamFile::ProtocolCommandParamFile(const QString &name, qulonglong size)
{
    this->name = name;
    this->size = size;
}


void ProtocolCommandParamFile::setName(QString name)
{
    this->name = name;
}

QString ProtocolCommandParamFile::getName() const
{
    return name;
}

void ProtocolCommandParamFile::setSize(qulonglong size)
{
    this->size = size;
}

qulonglong ProtocolCommandParamFile::getSize() const
{
    return this->size;
}
