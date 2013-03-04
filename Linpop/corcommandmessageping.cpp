#include "corcommandmessageping.h"
#include "inputcommandmessageping.h"

CORCommandMessagePing::CORCommandMessagePing()
{
}

bool CORCommandMessagePing::predicate(QByteArray query)
{
    return true;
}

ProtocolCommand *CORCommandMessagePing::build(QByteArray query)
{
    return new InputCommandMessagePing();
}
