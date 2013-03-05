#ifndef CORCOMMANDMESSAGEDECONNECTION_H
#define CORCOMMANDMESSAGEDECONNECTION_H

#include <QByteArray>
#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageDeconnection : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageDeconnection();
    virtual bool predicate(QByteArray query);
    virtual ProtocolCommand* build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEDECONNECTION_H
