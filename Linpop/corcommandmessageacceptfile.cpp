#include "corcommandmessageacceptfile.h"
#include "inputcommandmessageacceptfile.h"

CORCommandMessageAcceptFile::CORCommandMessageAcceptFile()
{
}

bool CORCommandMessageAcceptFile::predicate(QByteArray query)
{
    return query.startsWith("ACCEPTFILE");
}

//  ACCEPTFILE:ID_CONV:ID_PORT (0 == NO)
ProtocolCommand* CORCommandMessageAcceptFile::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandText(ProtocolCommandParamText(args.at(2)));

    InputCommandMessageAcceptFile *icmaf =  new InputCommandMessageAcceptFile();
    icmaf->setProtocolCommandParameter(p);
    return icmaf;
}
