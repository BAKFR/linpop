#include "corcommandmessagepong.h"
#include "inputcommandmessagepong.h"

CORCommandMessagePong::CORCommandMessagePong()
{
}

bool CORCommandMessagePong::predicate(QByteArray query)
{
    return query.startsWith("PONG");
}

ProtocolCommand *CORCommandMessagePong::build(QByteArray)
{
    return new InputCommandMessagePong();
}
