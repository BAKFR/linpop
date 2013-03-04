#ifndef OUTPUTCOMMANDMESSAGEJOIN_H
#define OUTPUTCOMMANDMESSAGEJOIN_H

#include "protocolcommand.h"

class OutputCommandMessageJoin : public ProtocolCommand
{
public:
    OutputCommandMessageJoin();
    OutputCommandMessageJoin(const OutputCommandMessageJoin& ref);
    virtual ProtocolCommand *clone();
    virtual bool execute();
};

#endif // OUTPUTCOMMANDMESSAGEJOIN_H
