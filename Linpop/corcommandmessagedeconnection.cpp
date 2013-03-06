#include "corcommandmessagedeconnection.h"
#include "inputcommandmessagedeconnection.h"

CORCommandMessageDeconnection::CORCommandMessageDeconnection()
{
}

bool CORCommandMessageDeconnection::predicate(QByteArray query)
{
    return query.startsWith("DISCONNECT");
}

ProtocolCommand* CORCommandMessageDeconnection::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));

    InputCommandMessageDeconnection *icmd =  new InputCommandMessageDeconnection();
    icmd->setProtocolCommandParameter(p);
    return icmd;
}

