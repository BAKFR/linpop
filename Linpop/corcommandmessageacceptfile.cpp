#include "corcommandmessageacceptfile.h"
#include "inputcommandmessageacceptfile.h"

CORCommandMessageAcceptFile::CORCommandMessageAcceptFile()
{
}

bool CORCommandMessageAcceptFile::predicate(QByteArray query)
{
    return false;
}

ProtocolCommand* CORCommandMessageAcceptFile::build(QByteArray query)
{
    return new InputCommandMessageAcceptFile();
}
