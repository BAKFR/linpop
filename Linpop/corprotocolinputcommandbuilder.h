#ifndef CORPROTOCOLINPUTCOMMANDBUILDER_H
#define CORPROTOCOLINPUTCOMMANDBUILDER_H

#include "protocolcommand.h"

class CORProtocolInputCommandBuilder
{
protected:
    CORProtocolInputCommandBuilder *ptrNextCORProtocolBuilder;
public:
    CORProtocolInputCommandBuilder();
    ProtocolCommand *find(QByteArray query);
    void setNext(CORProtocolInputCommandBuilder *cor);
    virtual ProtocolCommand *build(QByteArray query) = 0;
    CORProtocolInputCommandBuilder *getNext();
    virtual bool predicate(QByteArray query) = 0;
    virtual ~CORProtocolInputCommandBuilder(){}
};

#endif // CORPROTOCOLINPUTCOMMANDBUILDER_H
