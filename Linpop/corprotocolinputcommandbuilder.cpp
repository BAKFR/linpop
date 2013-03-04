#include "corprotocolinputcommandbuilder.h"


CORProtocolInputCommandBuilder::CORProtocolInputCommandBuilder()
{
  this->ptrNextCORProtocolBuilder = NULL;
}

void CORProtocolInputCommandBuilder::setNext(CORProtocolInputCommandBuilder *cor)
{
   this->ptrNextCORProtocolBuilder = cor;
}

CORProtocolInputCommandBuilder *CORProtocolInputCommandBuilder::getNext()
{
    return this->ptrNextCORProtocolBuilder;
}

ProtocolCommand *CORProtocolInputCommandBuilder::find(QByteArray query)
{
    if (predicate(query) == true)
    {
        return build(query);
    }
    else
    {
        if (this->ptrNextCORProtocolBuilder == NULL)
        {
            return NULL;
        }
        else
        {
            return this->ptrNextCORProtocolBuilder->find(query);
        }
    }
}

