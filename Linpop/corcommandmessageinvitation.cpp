#include "corcommandmessageinvitation.h"
#include "inputcommandmessageinvitation.h"

CORCommandMessageInvitation::CORCommandMessageInvitation()
{
}

bool CORCommandMessageInvitation::predicate(QByteArray query)
{
    return false;
}

ProtocolCommand *CORCommandMessageInvitation::build(QByteArray query)
{
    return new InputCommandMessageInvitation();
}
