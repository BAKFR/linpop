#include "corcommandmessagejoin.h"
#include "inputcommandmessagejoin.h"

CORCommandMessageJoin::CORCommandMessageJoin()
{
}

bool CORCommandMessageJoin::predicate(QByteArray array)
{
    return true;
}

ProtocolCommand *CORCommandMessageJoin::build(QByteArray query)
{
    return new InputCommandMessageJoin();
}
