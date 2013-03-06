#include "corcommandmessagejoin.h"
#include "inputcommandmessagejoin.h"

CORCommandMessageJoin::CORCommandMessageJoin()
{
}

bool CORCommandMessageJoin::predicate(QByteArray query)
{
    return query.startsWith("JOIN");
}

ProtocolCommand *CORCommandMessageJoin::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandUser(ProtocolCommandParamUser(args.at(3), args.at(2)));

    InputCommandMessageJoin *join =  new InputCommandMessageJoin();
    join->setProtocolCommandParameter(p);
    return join;
}
