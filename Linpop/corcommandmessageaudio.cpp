#include "corcommandmessageaudio.h"
#include "inputcommandmessageaudio.h"

CORCommandMessageAudio::CORCommandMessageAudio()
{
}

bool CORCommandMessageAudio::predicate(QByteArray query)
{
    return query.startsWith("AUDIO");
}

ProtocolCommand *CORCommandMessageAudio::build(QByteArray query)
{
    ProtocolCommandParameter    p;

    QList<QByteArray> args = query.split(ProtocolCommand::separator);

    p.addParamCommandConv(ProtocolCommandParamConv(args.at(1)));
    p.addParamCommandText(ProtocolCommandParamText(args.at(2)));

    InputCommandMessageAudio *icms =  new InputCommandMessageAudio();
    icms->setProtocolCommandParameter(p);
    return icms;
}
