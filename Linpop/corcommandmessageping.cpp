#include "corcommandmessageping.h"
#include "inputcommandmessageping.h"

CORCommandMessagePing::CORCommandMessagePing()
{
}

bool CORCommandMessagePing::predicate(QByteArray query)
{
    return query.startsWith("PING");
}

ProtocolCommand *CORCommandMessagePing::build(QByteArray)
{
    return new InputCommandMessagePing();
}
