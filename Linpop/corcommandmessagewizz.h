#ifndef CORCOMMANDMESSAGEWIZZ_H
#define CORCOMMANDMESSAGEWIZZ_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageWizz : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageWizz();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGESWIZZ_H
