#ifndef OUTPUTCOMMANDMESSAGEDECONNECTION_H
#define OUTPUTCOMMANDMESSAGEDECONNECTION_H
#include "protocolcommand.h"

class OutputCommandMessageDeconnection : public ProtocolCommand
{
public:
    OutputCommandMessageDeconnection();
    OutputCommandMessageDeconnection(const OutputCommandMessageDeconnection &ref);
    virtual bool execute();
    virtual ProtocolCommand *clone();
};

#endif // OUTPUTCOMMANDMESSAGEDECONNECTION_H
