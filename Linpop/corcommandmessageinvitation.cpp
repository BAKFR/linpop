#include "corcommandmessageinvitation.h"
#include "inputcommandmessageinvitation.h"

CORCommandMessageInvitation::CORCommandMessageInvitation()
{
}

bool CORCommandMessageInvitation::predicate(QByteArray query)
{
    return query.startsWith("INVITE");
}

ProtocolCommand *CORCommandMessageInvitation::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandUser(ProtocolCommandParamUser(args.at(3), args.at(2)));
    int i = 4;
    while (i < args.size())
    {
        p.addParamCommandUser(ProtocolCommandParamUser(args.at(i+1), args.at(i)));
        i+=2;
    }
    InputCommandMessageInvitation *invite =  new InputCommandMessageInvitation();
    invite->setProtocolCommandParameter(p);
    return invite;
}
