#ifndef OUTPUTCOMMANDMESSAGEDECONNECTION_H
#define OUTPUTCOMMANDMESSAGEDECONNECTION_H
#include "protocolcommand.h"

class OutputCommandMessageDeconnection : public ProtocolCommand
{
public:
    OutputCommandMessageDeconnection();
    virtual bool execute();
};

#endif // OUTPUTCOMMANDMESSAGEDECONNECTION_H
