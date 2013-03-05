#ifndef CORCOMMANDMESSAGEACCEPTFILE_H
#define CORCOMMANDMESSAGEACCEPTFILE_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageAcceptFile : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageAcceptFile();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEACCEPTFILE_H
