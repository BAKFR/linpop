#include "corcommandmessagedeconnection.h"
#include "inputcommandmessagedeconnection.h"

CORCommandMessageDeconnection::CORCommandMessageDeconnection()
{
}

bool CORCommandMessageDeconnection::predicate(QByteArray query)
{
    (void)query;
    return true;
}

ProtocolCommand* CORCommandMessageDeconnection::build(QByteArray byteArray)
{
    (void)byteArray;
    return new InputCommandMessageDeconnection();
}

