#include "corcommandmessagewizz.h"
#include "inputcommandmessagewizz.h"

CORCommandMessageWizz::CORCommandMessageWizz()
{
}

bool CORCommandMessageWizz::predicate(QByteArray query)
{
    return query.startsWith("WIZZ");
}

ProtocolCommand *CORCommandMessageWizz::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));

    InputCommandMessageWizz *icmw =  new InputCommandMessageWizz();
    icmw->setProtocolCommandParameter(p);
    return icmw;
}
