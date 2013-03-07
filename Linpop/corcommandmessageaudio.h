#ifndef CORCOMMANDMESSAGEAUDIO_H
#define CORCOMMANDMESSAGEAUDIO_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageAudio : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageAudio();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEAUDIO_H
