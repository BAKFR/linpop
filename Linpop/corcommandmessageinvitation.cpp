#include "corcommandmessageinvitation.h"
#include "inputcommandmessageinvitation.h"

CORCommandMessageInvitation::CORCommandMessageInvitation()
{
}

bool CORCommandMessageInvitation::predicate(QByteArray query)
{
    return true;
}

ProtocolCommand *CORCommandMessageInvitation::build(QByteArray query)
{
    return new InputCommandMessageInvitation();
}
