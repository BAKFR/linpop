#include "corcommandmessagejoin.h"
#include "inputcommandmessagejoin.h"

CORCommandMessageJoin::CORCommandMessageJoin()
{
}

bool CORCommandMessageJoin::predicate(QByteArray array)
{
    return false;
}

ProtocolCommand *CORCommandMessageJoin::build(QByteArray query)
{
    return new InputCommandMessageJoin();
}
