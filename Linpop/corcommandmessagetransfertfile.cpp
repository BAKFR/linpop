#include "corcommandmessagetransfertfile.h"
#include "inputcommandmessagetransfertfile.h"

CORCommandMessageTransfertFile::CORCommandMessageTransfertFile()
{
}

bool CORCommandMessageTransfertFile::predicate(QByteArray query)
{
    return query.startsWith("FILE");
}

ProtocolCommand *CORCommandMessageTransfertFile::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandFile(ProtocolCommandParamFile(args.at(3), args.at(2).toULongLong()));

    InputCommandMessageTransfertFile *icmtf =  new InputCommandMessageTransfertFile();
    icmtf->setProtocolCommandParameter(p);
    return icmtf;
}
