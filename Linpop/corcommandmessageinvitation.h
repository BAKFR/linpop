#ifndef CORCOMMANDMESSAGEINVITATION_H
#define CORCOMMANDMESSAGEINVITATION_H

#include "corprotocolinputcommandbuilder.h"

class CORCommandMessageInvitation : public CORProtocolInputCommandBuilder
{
public:
    CORCommandMessageInvitation();
    bool predicate(QByteArray query);
    ProtocolCommand *build(QByteArray query);
};

#endif // CORCOMMANDMESSAGEINVITATION_H
