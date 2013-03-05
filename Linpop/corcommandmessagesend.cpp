#include "corcommandmessagesend.h"
#include "inputcommandmessagesend.h"

CORCommandMessageSend::CORCommandMessageSend()
{
}

bool CORCommandMessageSend::predicate(QByteArray query)
{
    return query.startsWith("SEND");;
}

ProtocolCommand *CORCommandMessageSend::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandText(ProtocolCommandParamText(args.at(2)));

    InputCommandMessageSend *icms =  new InputCommandMessageSend();
    icms->setProtocolCommandParameter(p);
    return icms;
}
