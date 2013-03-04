#include "corcommandmessagepong.h"
#include "inputcommandmessagepong.h"

CORCommandMessagePong::CORCommandMessagePong()
{
}

bool CORCommandMessagePong::predicate(QByteArray query)
{
    return true;
}

ProtocolCommand *CORCommandMessagePong::build(QByteArray query)
{
    return new InputCommandMessagePong();
}
