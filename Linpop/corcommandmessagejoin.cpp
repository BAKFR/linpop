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

    QList<QByteArray> args = query.split('\01');

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));

    InputCommandMessageJoin *join =  new InputCommandMessageJoin();
    join->setProtocolCommandParameter(p);
    return join;
}
