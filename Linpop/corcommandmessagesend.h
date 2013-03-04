#ifndef CORCOMMANDMESSAGESEND_H
#define CORCOMMANDMESSAGESEND_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageSend : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageSend();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGESEND_H
