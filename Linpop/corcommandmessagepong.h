#ifndef CORCOMMANDMESSAGEPONG_H
#define CORCOMMANDMESSAGEPONG_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessagePong : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessagePong();
    bool predicate(QByteArray query);
    ProtocolCommand* build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEPONG_H
