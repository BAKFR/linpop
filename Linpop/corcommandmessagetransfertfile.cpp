#include "corcommandmessagetransfertfile.h"
#include "inputcommandmessagetransfertfile.h"

CORCommandMessageTransfertFile::CORCommandMessageTransfertFile()
{
}

bool CORCommandMessageTransfertFile::predicate(QByteArray query)
{
    return true;
}

ProtocolCommand *CORCommandMessageTransfertFile::build(QByteArray query)
{
    return new InputCommandMessageTransfertFile();
}
