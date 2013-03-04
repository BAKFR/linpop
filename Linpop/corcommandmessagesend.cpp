#include "corcommandmessagesend.h"
#include "inputcommandmessagesend.h"

CORCommandMessageSend::CORCommandMessageSend()
{
}

bool CORCommandMessageSend::predicate(QByteArray query)
{
    return true;
}

ProtocolCommand *CORCommandMessageSend::build(QByteArray query)
{
    return new InputCommandMessageSend();
}
