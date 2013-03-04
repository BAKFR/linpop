#ifndef CORCOMMANDMESSAGEPING_H
#define CORCOMMANDMESSAGEPING_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessagePing : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessagePing();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEPING_H
