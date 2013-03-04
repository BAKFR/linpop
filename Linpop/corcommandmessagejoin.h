#ifndef CORCOMMANDMESSAGEJOIN_H
#define CORCOMMANDMESSAGEJOIN_H

#include <QByteArray>
#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageJoin : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageJoin();
    bool predicate(QByteArray array);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEJOIN_H
