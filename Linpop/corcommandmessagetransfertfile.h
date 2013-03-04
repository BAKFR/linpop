#ifndef CORCOMMANDMESSAGETRANSFERTFILE_H
#define CORCOMMANDMESSAGETRANSFERTFILE_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageTransfertFile : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageTransfertFile();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGETRANSFERTFILE_H
